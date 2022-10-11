/**
 * @file pid.cpp
 * @authors Rishabh Singh, Vishaal Kanna Sivakumar
 * @authors Part 2: Sanchit Kedia, Adarsh Malapaka
 * @brief Stub class for the PID controller
 * @version 0.1
 * @date 2022-10-02
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../include/Transformation_module.hpp"

#include <iostream>
#include <vector>

void Transformation_module::set_intrinsics(float (*intrinsic)[3][3])
{ _intrinsics = *intrinsics; }

void Transformation_module::set_cam_to_rob(float (*cam_to_rob)[3][4])
{ _cam_to_rob = *cam_to_rob; }

std::vector<std::array<float, 4>> Transformation_module::2dto3D_transform(std::vector<cv::rect> rect)
{ return -1; }