project(Modules)

set(HEADER_FILES
        AbstractBatteryEstimation.h
        )

set(SOURCE_FILES
        Helper.h NaiveBatteryEstimation.cpp NaiveBatteryEstimation.h SimpleBatteryEstimation.cpp SimpleBatteryEstimation.h)

add_library(Modules STATIC ${SOURCE_FILES} ${HEADER_FILES})