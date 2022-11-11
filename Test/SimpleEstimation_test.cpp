//
// Created by hugo on 07/12/2020.
//

#include "gtest/gtest.h"
#include "SimpleBatteryEstimation.h"
#include <cmath>


class SimpleEstimation : public ::testing::Test
{
protected:
    virtual void TearDown() {
    }

    virtual void SetUp() {

            windData = {
                {{1000.0, 0}, {100, 0}},
                {{1000, 1000}, {100, 0}},
        };
        windData1 = {
                {{1000.1, 0.1}, {50.1, 3}},
                {{1000.1, 1000.1}, {70.1, 3}},
        };
        waypoints = {{1000.0, 0}, {1000, 1000}, {2000, 1000}};

    }
public:
    SimpleEstimation() : Test() {
        pBatteryEstimation = new SimpleBatteryEstimation;

        }
        virtual ~SimpleEstimation() {
            delete pBatteryEstimation;
        }

    AbstractBatteryEstimation* pBatteryEstimation;
    std::vector<Coordinates> waypoints;
    std::unordered_map<Coordinates, WindInfo, boost::hash<Coordinates>> windData;
    std::unordered_map<Coordinates, WindInfo, boost::hash<Coordinates>> windData1;
    double batteryEstimate1 = initialBatteryLevel - (3000.0/ (static_cast<float>(airSpeed) + 100)) *
                                                    (energyConsumption / SECONDSPERHOUR);
    };


TEST_F(SimpleEstimation, tailWind) {
EXPECT_NEAR(batteryEstimate1, pBatteryEstimation->computeRemainingBattery(initialBatteryLevel, waypoints, windData,
                                                                          energyConsumption), 1e-1);
}
TEST_F(SimpleEstimation, WindError) {
ASSERT_THROW(pBatteryEstimation->computeRemainingBattery(initialBatteryLevel, waypoints, windData1,
                                                                        energyConsumption), WindError);
}
