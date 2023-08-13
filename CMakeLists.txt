cmake_minimum_required(VERSION 3.25)
project(site_survey)

set(CMAKE_CXX_STANDARD 14)

add_executable(site_survey
        process.cpp datalogger.cpp datalogger.h linkedlist.cpp linkedlist.h sensordata.cpp sensordata.h)
