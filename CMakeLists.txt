cmake_minimum_required(VERSION 3.5)
project(BlueRobotics_KellerLD)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()


include_directories(include)

file(GLOB SOURCE_FILES
 include/KellerLD.h
 include/KellerLD.cpp
)

add_executable(${PROJECT_NAME} src/main.cpp ${SOURCE_FILES})
