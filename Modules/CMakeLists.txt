project(Modules)

set(HEADER_FILES
        AbstractBatteryEstimation.h
        AbstractError.h
        NaiveBatteryEstimation.h
        SimpleBatteryEstimation.h)

set(SOURCE_FILES
        Helper.h NaiveBatteryEstimation.cpp SimpleBatteryEstimation.cpp)

add_library(Modules STATIC ${SOURCE_FILES} ${HEADER_FILES})
