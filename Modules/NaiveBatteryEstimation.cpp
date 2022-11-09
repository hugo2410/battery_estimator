//
// Created by hugo on 09/11/22.
//

#include "NaiveBatteryEstimation.h"

NaiveBatteryEstimation::NaiveBatteryEstimation(){};

std::vector<double>  NaiveBatteryEstimation::computeRemainingBattery(double initBattery,
                                                                       const std::vector<Coordinates> &WayPoints,
                                                                       const  std::unordered_map<Coordinates,
                                                                       WindInfo, boost::hash<Coordinates>> &WindData,
                                                                       double energyConsumption){
    double sum = 0.;
    for(int i=0;i<pRandom->get_size();++i){
        sum += pRandom->get_vector()[i];
    }
    return sum/pRandom->get_size();
}