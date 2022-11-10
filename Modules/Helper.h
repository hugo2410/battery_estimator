//
// Created by hugo on 09/11/22.
//

#define SECONDSPERHOUR 3600

typedef std::pair<uint8_t, uint8_t>     Coordinates;

struct WindInfo {
    float speed;
    float direction;
};

static constexpr int                    initialBatteryLevel = 22;
static constexpr int                    energyConsumption = 2;
static constexpr int                    airSpeed = 30;
static constexpr int                    batteryMargin = 2;
static constexpr int                    maxRangeWindMeasurement = 10;