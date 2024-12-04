cmake_minimum_required(VERSION 3.16)

project(WxChillGuy)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(wxWidgets REQUIRED)

add_executable(${PROJECT_NAME} WIN32 src/main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${wxWidgets_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})