//
// Created by mehdi on 28/11/20.
//

#ifndef BATTERY_ESTIMATOR_ABSTRACTBATTERYESTIMATION_H
#define BATTERY_ESTIMATOR_ABSTRACTBATTERYESTIMATION_H

#include <vector>
#include <unordered_map>
#include <boost/functional/hash.hpp>
#include "Helper.h"

/**
 * \brief Abstract class for battery estimation
 */
class AbstractBatteryEstimation {
public:

    /**
     * \brief Abstract function to compute the amount of battery left
     * @param pRandom : pRandom : Pointer to a random variables.
     * @return Vector containing the battery estimates at each waypoint.
     */
    virtual bool computeRemainingBattery(double initBattery,
                                                        const std::vector<Coordinates> &WayPoints,
                                                        const  std::unordered_map<Coordinates, WindInfo,
                                                                                    boost::hash<Coordinates>> &WindData,
                                                        double energyConsumption) = 0 ;
};


#endif //BATTERY_ESTIMATOR_ABSTRACTBATTERYESTIMATION_H
