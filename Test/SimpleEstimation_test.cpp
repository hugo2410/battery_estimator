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
    double batteryEstimate1 = initialBatteryLevel - (2.0/ airSpeed) * (energyConsumption / SECONDSPERHOUR);
    double batteryEstimate2 = initialBatteryLevel - (20.0/ airSpeed) * (energyConsumption / SECONDSPERHOUR);

    };


TEST_F(SimpleEstimation, baseline) {
EXPECT_EQ(batteryEstimate1, pBatteryEstimation->computeRemainingBattery(initialBatteryLevel, waypoints, windData, energyConsumption));
}
TEST_F(SimpleEstimation, increasedWind) {
EXPECT_EQ(batteryEstimate2, pBatteryEstimation->computeRemainingBattery(initialBatteryLevel, waypoints, windData1, energyConsumption));
}




