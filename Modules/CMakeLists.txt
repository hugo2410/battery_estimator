project(Modules)

set(HEADER_FILES
        AbstractBatteryEstimation.h
        NaiveBatteryEstimation.h)

set(SOURCE_FILES
        Helper.h NaiveBatteryEstimation.cpp)

add_library(Modules STATIC ${SOURCE_FILES} ${HEADER_FILES})
