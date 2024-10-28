cmake_minimum_required(VERSION 3.0)

project(helloworld)

# Set the C++ standard to moderncpp
set(CMAKE_CXX_STANDARD 20)


include_directories(includes/ utils/)


# Add the source files
set(SOURCE src/main.cpp  )



add_executable(${PROJECT_NAME} ${SOURCE})

