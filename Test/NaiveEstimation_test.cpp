//
// Created by hugo on 08/12/2020.
//


#include "gtest/gtest.h"
#include "../Modules/AbstractBatteryEstimation.h"
#include "../Modules/NaiveBatteryEstimation.h"
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
        windData1 = {
                {{12.1, 1.1}, {50.1, 2}},
                {{4.1, 15.1}, {70.1, 3.1}},
                {{5.1, -1.1}, {-50.1, -1.2}},
                {{11.1, 11.1}, {-150.1, 2}},
        };
        waypoints = {{100.0, 0}, {100, 100}, {200, 100}};
        waypoints1 = {{1000.0, 0}, {1000, 1000}, {2000, 1000}};
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
    double batteryEstimate1 = initialBatteryLevel - (300.0/ static_cast<float>(airSpeed)) *
                              (static_cast<float>(energyConsumption) / SECONDSPERHOUR);
    double batteryEstimate2 = initialBatteryLevel - (3000.0/ static_cast<float>(airSpeed)) *
                              (static_cast<float>(energyConsumption)  / SECONDSPERHOUR);

};

TEST_F(NaiveEstimation, baseline) {
    EXPECT_NEAR(batteryEstimate1, pBatteryEstimation->computeRemainingBattery(initialBatteryLevel, waypoints, windData,
                                                                              energyConsumption), 1e-1);
}
TEST_F(NaiveEstimation, increasedWind) {
    EXPECT_NEAR(batteryEstimate1, pBatteryEstimation->computeRemainingBattery(initialBatteryLevel, waypoints, windData1,
                                                                              energyConsumption), 1e-1);
}
TEST_F(NaiveEstimation, increasedDistance) {
    EXPECT_NEAR(batteryEstimate2, pBatteryEstimation->computeRemainingBattery(initialBatteryLevel, waypoints1, windData,
                                                                              energyConsumption), 1e-1);
}

