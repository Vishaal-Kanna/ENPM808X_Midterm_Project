/**
 * @file Transformation_module.cpp
 * @authors Sahruday Patti, Vishaal Kanna Sivakumar
 * @brief Stub class for the Transformation module class
 * @version 0.1
 * @date 2022-10-10
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../include/Transformation_module.hpp"

#include <iostream>
#include <vector>



void Transformation_module::set_intrinsics(float intrinsics[3][3]) {
    _intrinsics[3][3] = intrinsics[3][3];
  }

void Transformation_module::set_cam_to_rob(float cam_to_rob[3][4]) {
    _cam_to_rob[3][4] = cam_to_rob[3][4];
  }

std::vector<std::array<float, 4>> Transformation_module::transform_2dto3D(std::vector<cv::Rect> rect) {
    std::array<float,4> coord= {0,0,0,1};
    std::vector<std::array<float, 4>> coords;
    coords.push_back(coord);
    return coords;
    }
