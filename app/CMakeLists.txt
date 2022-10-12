add_executable(ACME main.cpp ACME_robot.cpp Detection_module.cpp Tracking_module.cpp Transformation_module.cpp)
include_directories(
    ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(ACME PUBLIC gtest ${OpenCV_LIBS})
