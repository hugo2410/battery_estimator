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
    std::vector<double> batteryEstimate1 = {initialBatteryLevel - 1.0*energyConsumption, initialBatteryLevel - 2.0*energyConsumption};
    std::vector<double> batteryEstimate2 = {initialBatteryLevel - 1.0*energyConsumption, initialBatteryLevel - 2.0*energyConsumption};

    };


TEST_F(SimpleEstimation, mean_check) {
    EXPECT_EQ(pRandomNormal->get_mean(),TEST_MEAN);
}

TEST_F(SimpleEstimation, variance_check) {
    EXPECT_EQ(pRandomNormal->get_var(),TEST_VARIANCE);
}

TEST_F(SimpleEstimation, size_check) {
    EXPECT_EQ(pRandomNormal->get_vector().size(),TEST_SIZE);
}




