/*!
 *
 * main.cpp
 *
 *  Created on: Nov 9, 2022
 * 	   Author: Birch Hugo <hugo@birchs.net>
 */

#include <iostream>
#include <cstring>
#include <boost/functional/hash.hpp>
#include <unordered_map>

#include "AbstractBatteryEstimation.h"
#include "NaiveBatteryEstimation.h"
#include "SimpleBatteryEstimation.h"


using namespace std;

int main(int argc, char *argv[]) {


    const unordered_map<Coordinates, WindInfo, boost::hash<Coordinates>> windData({
                                                              {{12.1, 1.1}, {5.1, 2}},
                                                              {{4.1, 15.1}, {7.1, 3.1}},
                                                              {{5.1, -1.1}, {-5.1, -1.2}},
                                                              {{11.1, 11.1}, {-15.1, 2}}, });
    const vector<Coordinates> waypoints = {{3.1, 7.1}, {2.6, 1.1}, {-1.1, 21}, {12.1, 1.1}};

    AbstractBatteryEstimation *pBatteryEstimation{nullptr};

    pBatteryEstimation = new SimpleBatteryEstimation;
    std::vector<double> batteryEstimation;
    try {
        batteryEstimation = pBatteryEstimation->computeRemainingBattery(initialBatteryLevel,
                                                                        waypoints,
                                                                        windData,
                                                                        energyConsumption);
        cout << "Battery estimatation at each waypoint is :";
        for (auto estimate: batteryEstimation) {
            cout << estimate << " ";
        }
    } catch(AbstractError& e) {
        cerr << "Exception thrown: " << e.what() << endl;
        return -1;
    pBatteryEstimation = new NaiveBatteryEstimation;

    if (pBatteryEstimation->computeRemainingBattery(initialBatteryLevel,
                                                                    waypoints,
                                                                    windData,
                                                                    energyConsumption)){
        cout<< " Flight plan is safe, there is enough battery for the drone to complete the mission"<<endl;
    } else {
        err<< " Caution: there is not enough battery to complete the flight plan"<<endl;
    }
    return 0;
}