# Battery Estimator

### Author :
Birch Hugo 

### Description
This project aims to deliver a battery estimator module taking the following inputs:

* Initial battery (Wh)
* Ordered list of waypoints (the black dots, simplified to be 2D (m) for this problem)
* Unordered list of wind samples (2D location (m), wind speed (m/s), wind direction (rad))
* The airspeed at which we fly (m/s); 30m/s, which is constant throughout the mission
  * Note: we fly at a constant speed in the wind frame, which means wind affects our
    ground speed, not our airspeed 
* The power needed to fly at the provided constant airspeed (Watts)

The module outputs a list with the battery estimate at each waypoint

I decided to implement 3 different logics, which would all use the same framework. The first being the "naive" one 
which would mimic the current implementation which would be the baseline needing improvement. Then I created two 
branches building up onto this skeleton and offers more realistic approaches. The aim was to show how I 
would develop new features.

For all logic the program creates an abstract battery estimation object and then creates the desired 
object before calling the computeBatteryEstimation function. However, each implementation solves the problem
in a different manner.
The 3 different implementations are explained below:

* The "naive" implementation ignores the wind and assumes a constant depletion of the battery across the journey.

* The "[simple](https://github.com/hugo2410/battery_estimator/pull/2)" implementation used the assumption  
that the wind along the journey will correspond to the wind at the closest measured point.

* The "[Advanced](https://github.com/hugo2410/battery_estimator/pull/1)" implementation computes the 
decay of each measurement using the distance to the waypoint and the exponential function. The 
weighted measurement is then compared to the head wind component to ensure that two measurements don't 
end up creating a stronger wind then the measurements themselves.

## Installation

The following dependencies are required to build the code. The executable can be obtained either via 
command line by cloning this repository via git or the executable can be found online at each release tags.

### Dependencies

The following dependencies are required to build and contribute to this repository:

* CMake 3.2 or higher
* git
* gcc 5.4 or higher

### Building the code

To compile and run the executable, the following commands must be written in the terminal :
```
git clone git@github.com:hugo2410/battery_estimator.git
cd battery_estimator
git submodule update --init --recursive
cmake .
make 
./Battery_Estimator
``` 

### Unit tests
I implemented some unit tests for each of the implementations. These use the
[google test](https://github.com/google/googletest) framework. I added 1 Test file for each implementation,
these can either be executed indivually or all together by running the RunAllTest binary.

To compile and run the executable, the following commands must be written in the terminal :
```
cmake .
make 
cd Test
./RunAllTest
``` 

### Doxygen
The documentation was designed for doxygen 1.8.16 or higher.
To generate the documentation, run the command : 'doxygen Doxyfile' in the terminal.