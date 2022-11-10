//
// Created by hugo on 07/12/2020.
//

#include "gtest/gtest.h"
#include "SimpleBatteryEstimation.h"
#include "AbstractBatteryEstimation.h"
#include <cmath>



#define TEST_SIZE 100
#define TEST_MEAN 4.
#define TEST_VARIANCE 2.



class SimpleEstimation : public ::testing::Test
{
protected:
    virtual void TearDown() {

        windData = {
                {{12.1, 1.1}, {5.1, 2}},
                {{4.1, 15.1}, {7.1, 3.1}},
                {{5.1, -1.1}, {-5.1, -1.2}},
                {{11.1, 11.1}, {-15.1, 2}},
        };
        windData = {
                {{12.1, 1.1}, {50.1, 2}},
                {{4.1, 15.1}, {70.1, 3.1}},
                {{5.1, -1.1}, {-50.1, -1.2}},
                {{11.1, 11.1}, {-150.1, 2}},
        };
        waypoints = {{1.0, 0}, {1, 1}};
        waypoints1 = {{10.0, 0}, {10, 1}};

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
    std::vector<Coordinates> waypoints1;
    std::unordered_map<Coordinates, WindInfo, boost::hash<Coordinates>> windData;
    std::unordered_map<Coordinates, WindInfo, boost::hash<Coordinates>> windData1;
    std::vector<double> batteryEstimate1 = {initialBatteryLevel - 1.0*energyConsumption, initialBatteryLevel - 2.0*energyConsumption};
    std::vector<double> batteryEstimate2 = {initialBatteryLevel - 1.0*energyConsumption, initialBatteryLevel - 2.0*energyConsumption};

    };


TEST_F(SimpleEstimation, baseline) {
EXPECT_EQ(true, pBatteryEstimation->computeRemainingBattery(initialBatteryLevel, waypoints, windData, energyConsumption));
}
TEST_F(SimpleEstimation, increasedWind) {
EXPECT_EQ(false, pBatteryEstimation->computeRemainingBattery(initialBatteryLevel, waypoints, windData1, energyConsumption));
}




