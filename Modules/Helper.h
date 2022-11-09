//
// Created by hugo on 09/11/22.
//

#ifndef BATTERY_ESTIMATOR_HELPER_H
#define BATTERY_ESTIMATOR_HELPER_H


class Helper {

public:

    struct Coordinates {
        float x;
        float y;
    };

    struct WindInfo {
        float speed;
        float direction;
    };

    static constexpr int                    initialBatteryLevel = 22;


    int getEnergyConsumption(const float speed) const { return energyConsumption; }

private:

    static constexpr int                    energyConsumption = 22;
};


#endif //BATTERY_ESTIMATOR_HELPER_H
