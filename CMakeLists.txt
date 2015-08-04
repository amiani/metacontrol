cmake_minimum_required(VERSION 3.2)
project(MetaControl)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(SOURCE_FILES main.cpp)

#find_package(Boost COMPONENTS system python-py34 REQUIRED)
#find_package(PythonLibs 3.4 REQUIRED)
#if (PYTHONLIBS_FOUND)
#    include_directories(${PYTHON_INCLUDE_DIRS})
#endif()
#if (Boost_PYTHON_FOUND)
#    include_directories(${Boost_INCLUDE_DIRS})
#endif()

add_executable(MetaControl ${SOURCE_FILES} LevelSwitch.cpp LevelSwitch.h Pump.cpp Pump.h Flowmeter.cpp Flowmeter.h Routine.cpp Routine.h Controller.cpp Controller.h Sensor.h LevelSwitch.cpp LevelSwitch.h Profile.cpp Profile.h fscs/Profiles/DefaultProfile.cpp fscs/Profiles/DefaultProfile.h fscs/Sensors/TempSensor.cpp fscs/Sensors/TempSensor.h fscs/Sensors/PHSensor.cpp fscs/Sensors/PHSensor.h fscs/Sensors/WetTraySensor.cpp fscs/Sensors/WetTraySensor.h fscs/Sensors/ECSensor.cpp fscs/Sensors/ECSensor.h Switch.h fscs/FSCS.h State.cpp State.h fscs/FSState.cpp fscs/FSState.h Machine.h Machine.cpp fscs/FSCS.cpp)
#target_link_libraries(MetaControl ${Boost_LIBRARIES} ${PYTHON_LIBRARIES})
