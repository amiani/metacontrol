cmake_minimum_required(VERSION 3.2)
project(MetaControlSim)

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

add_executable(MetaControlSim ${SOURCE_FILES} LevelSensor.cpp LevelSensor.h Pump.cpp Pump.h Flowmeter.cpp Flowmeter.h Routine.cpp Routine.h Controller.cpp Controller.h Sensor.h fscs/Routines/FreshBatchRoutine.cpp fscs/Routines/FreshBatchRoutine.h LevelSensor.cpp LevelSensor.h Profile.cpp Profile.h fscs/Profiles/DefaultProfile.cpp fscs/Profiles/DefaultProfile.h fscs/Sensors/TempSensor.cpp fscs/Sensors/TempSensor.h fscs/Sensors/PHSensor.cpp fscs/Sensors/PHSensor.h fscs/Sensors/WetTraySensor.cpp fscs/Sensors/WetTraySensor.h fscs/Sensors/ECSensor.cpp fscs/Sensors/ECSensor.h Sensor.cpp TestSensor.h TestPump.cpp TestPump.h TestFlowmeter.h)
#target_link_libraries(MetaControlSim ${Boost_LIBRARIES} ${PYTHON_LIBRARIES})
