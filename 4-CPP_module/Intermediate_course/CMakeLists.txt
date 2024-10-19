cmake_minimum_required(VERSION 3.0)

project(helloworld)

# Set the C++ standard to moderncpp
set(CMAKE_CXX_STANDARD 17)


include_directories(includes/ utils/)


# Add the source files
set(SOURCE src/main.cpp  utils/math.cpp)



add_executable(${PROJECT_NAME} ${SOURCE})

