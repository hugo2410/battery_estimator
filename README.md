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

It was decided to implement 3 different logics, the first being the "naive" one which would mimic the current
implementation which needs to be improved. Then I created two branches building up onto this skeleton and offers
more realistic approaches. The aim was to show how I would develop new features. 

The "naive" implementation ignores the wind and assumes a constant depletion of the battery across the journey.

The "simple" implementation which is developed on the branch "feature/simple_implementation", the assumption used is 
that the wind along the journey will correspond to the wind at the closest measured point.

### How It Works

To run the executable, the following information must be written to the terminal :

'./battery_estimator  name_of_waypoint_file name_of_winddata_file' .