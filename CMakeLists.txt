cmake_minimum_required(VERSION 3.2)
project(MetaControlSim)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(Boost COMPONENTS python REQUIRED)
if (Boost_PYTHON_FOUND)
    include_directories(${Boost_INCLUDE_DIR})
    set(SOURCE_FILES main.cpp)
endif()
add_executable(MetaControlSim ${SOURCE_FILES} LevelSensor.cpp LevelSensor.h Pump.cpp Pump.h FlowMeter.cpp FlowMeter.h Routine.cpp Routine.h Controller.cpp Controller.h Sensor.h fscs/Routines/FreshBatchRoutine.cpp fscs/Routines/FreshBatchRoutine.h LevelSensor.cpp LevelSensor.h Profile.cpp Profile.h fscs/Profiles/DefaultProfile.cpp fscs/Profiles/DefaultProfile.h fscs/Sensors/TempSensor.cpp fscs/Sensors/TempSensor.h fscs/Sensors/PHSensor.cpp fscs/Sensors/PHSensor.h fscs/Sensors/WetTraySensor.cpp fscs/Sensors/WetTraySensor.h)