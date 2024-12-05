cmake_minimum_required(VERSION 3.8)
project(safety_stopper)

# if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
#   add_compile_options(-Wall -Wextra -Wpedantic)
# endif()

# find dependencies
# find_package(ament_cmake REQUIRED)
# find_package(rclcpp REQUIRED)
# find_package(sensor_msgs REQUIRED)
# find_package(std_msgs REQUIRED)
find_package(ament_cmake_auto REQUIRED)
ament_auto_find_build_dependencies()

ament_auto_add_executable(${PROJECT_NAME}_node
    src/safety_stopper.cpp
)
ament_auto_package()

install(DIRECTORY
    launch
    DESTINATION share/${PROJECT_NAME}
)
