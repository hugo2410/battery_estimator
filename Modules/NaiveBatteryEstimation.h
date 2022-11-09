//
// Created by hugo on 09/11/22.
//

#ifndef BATTERY_ESTIMATOR_NAIVEBATTERYESTIMATION_H
#define BATTERY_ESTIMATOR_NAIVEBATTERYESTIMATION_H

#include "AbstractBatteryEstimation.h"


/*
 * Naive implementation for the battery estimation with constant depletion of the battery, only considering the time
 * it would take to reach the home.
 */
class NaiveBatteryEstimation : public AbstractBatteryEstimation
{
    /*
	 * Standard constructor
	 */
    NaiveBatteryEstimation();


    std::vector<double> computeRemainingBattery(double initBattery,
                                                const std::vector<Coordinates> &WayPoints,
                                                const  std::unordered_map<Coordinates, WindInfo,
                                                        boost::hash<Coordinates>> &WindData,
                                                double energyConsumption);
};


#endif //BATTERY_ESTIMATOR_NAIVEBATTERYESTIMATION_H
