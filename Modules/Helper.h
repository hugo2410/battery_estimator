//
// Created by hugo on 09/11/22.
//

#define SECONDSPERHOUR 3600

typedef std::pair<int, int>     Coordinates;

struct WindInfo {
    float speed;
    float direction;
};

static constexpr int                    initialBatteryLevel = 20;
static constexpr double                 energyConsumption = 36.0;
static constexpr int                    airSpeed = 30;
static constexpr int                    batteryMargin = 2;