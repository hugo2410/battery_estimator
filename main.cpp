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

#include "main.h"


using namespace std;

int main(int argc, char *argv[]) {


    unordered_map<Coordinates, WindInfo, boost::hash<Coordinates>> WindData;
    vector<Coordinates> WayPoints;

    computeRemainingBattery(WayPoints, WindData);


    return 0;
}