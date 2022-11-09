//
// Created by hugo on 08/12/2020.
//


#include "gtest/gtest.h"
#include "AbstractBatteryEstimation.h"
#include "NaiveBatteryEstimation.h"
#include <cmath>


class NaiveEstimation : public ::testing::Test
{
protected:
    virtual void TearDown() {

    }

    virtual void SetUp() {

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
    NaiveEstimation() : Test() {
        pBatteryEstimation = new NaiveBatteryEstimation;

    }

    virtual ~NaiveEstimation() {
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

TEST_F(NaiveEstimation, baseline) {
    ASSERT_THAT(batteryEstimate1, pBatteryEstimation->computeRemainingBattery(initialBatteryLevel, waypoints, windData, energyConsumption));
}
TEST_F(NaiveEstimation, increasedWind) {
    ASSERT_THAT(batteryEstimate1, pBatteryEstimation->computeRemainingBattery(initialBatteryLevel, waypoints, windData1, energyConsumption));
}
TEST_F(NaiveEstimation, increasedDistance) {
    ASSERT_THAT(batteryEstimate2, pBatteryEstimation->computeRemainingBattery(initialBatteryLevel, waypoints1, windData, energyConsumption));
}

