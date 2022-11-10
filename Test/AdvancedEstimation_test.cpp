//
// Created by hugo on 08/12/2020.
//


#include "gtest/gtest.h"
#include "AdvancedBatteryEstimation.h"
#include <cmath>


class AdvancedEstimation : public ::testing::Test
{
protected:
    virtual void TearDown() {

    }

    virtual void SetUp() {

        windData = {
                  {{999.0, 0}, {50, 0}},
                  {{1001.0, 0}, {50, 3.14}},
          };
        windData2 = {
                {{999.0, 0}, {10, 0}},
                {{1001.0, 0}, {10, 0}},
                {{1000.0, 999}, {10, 0}},
                {{1001.0, 1000}, {10, 0}},
                {{1999.0, 1000}, {10, 0}},
                {{2001.0, 1000}, {10, 0}},
        };

        waypoints = {{1000.0, 0}, {1000, 1000}, {2000, 1000}};

    }
public:
    AdvancedEstimation() : Test() {
        pBatteryEstimation = new AdvancedBatteryEstimation;

    }

    virtual ~AdvancedEstimation() {
        delete pBatteryEstimation;
    }
    AbstractBatteryEstimation* pBatteryEstimation;
    std::vector<Coordinates> waypoints;
    std::unordered_map<Coordinates, WindInfo, boost::hash<Coordinates>> windData;
    std::unordered_map<Coordinates, WindInfo, boost::hash<Coordinates>> windData2;
    double batteryEstimate1 = initialBatteryLevel - (3000.0/ static_cast<float>(airSpeed)) *
                              (static_cast<float>(energyConsumption)  / SECONDSPERHOUR);
    double batteryEstimate2 = initialBatteryLevel - (3000.0/ (static_cast<float>(airSpeed) + 20)) *
                                                    (static_cast<float>(energyConsumption)  / SECONDSPERHOUR);

};

TEST_F(AdvancedEstimation, oppositeWinds) {
    EXPECT_NEAR(batteryEstimate1, pBatteryEstimation->computeRemainingBattery(initialBatteryLevel, waypoints, windData,
                                                                              energyConsumption), 1e-1);
}
TEST_F(AdvancedEstimation, sameWinds) {
EXPECT_NEAR(batteryEstimate2, pBatteryEstimation->computeRemainingBattery(initialBatteryLevel, waypoints, windData2,
        energyConsumption), 1e-1);
}

