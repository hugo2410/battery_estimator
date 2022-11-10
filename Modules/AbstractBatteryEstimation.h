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
     * \brief Abstract function of the battery estimation fucntion
    * @param initBattery: value of the battery at the beginning of the flight (Wh)
    * @param WayPoints: vector containing the list of coordinates of each waypoint
    * @param WindData: unordered map containing the coordinates of the wind measurements and the speed and direction
    * of the measurements
    * @param energyConsumption: value of the power needed to fly at 30m/s
    * @return Estimation of the remaining battery (Wh)
     */
    virtual double computeRemainingBattery(double initBattery,
                                                        const std::vector<Coordinates> &WayPoints,
                                                        const  std::unordered_map<Coordinates, WindInfo,
                                                                                    boost::hash<Coordinates>> &WindData,
                                                        double energyConsumption) = 0 ;
};


#endif //BATTERY_ESTIMATOR_ABSTRACTBATTERYESTIMATION_H
