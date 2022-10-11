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

void Transformation_module::set_intrinsics(float intrinsics[3][3])
{  }

void Transformation_module::set_cam_to_rob(float cam_to_rob[3][4])
{  }

std::vector<std::array<float, 4>> Transformation_module::transform_2dto3D(std::vector<cv::Rect> rect)
{   std::array<float,4> coord= {0,0,0,1};
    std::vector<std::array<float, 4>> coords;
    coords.push_back(coord);
    return coords; }