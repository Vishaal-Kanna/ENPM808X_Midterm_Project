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

void Transformation_module::set_intrinsics(float intrinsics[3][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      _intrinsics[i][j] = intrinsics[i][j];
      }
  }
}

void Transformation_module::set_cam_to_rob(float cam_to_rob[3][4]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      _cam_to_rob[i][j] = cam_to_rob[i][j];
      }
  }
}

std::vector<std::array<float, 4>> Transformation_module::transform_2dto3D(
    std::vector<cv::Rect> rect) {
  int bbox_id = 0;
  float _focalLength = _intrinsics[1][1];
  double _calib_factor = 0.0;
  std::array<float, 4> coord = {0, 0, 0, 1};
  std::vector<std::array <float, 4> > coords;
  for (cv::Rect r : rect) {
    bbox_id++;
    double factor = _avg_human_height / r.height;

    _calib_factor = _focalLength * _avg_human_height;

    float calib_distance = _calib_factor/ r.height;

    float x_center = r.width / 2.0 + r.x;
    float y_center = r.height / 2.0 + r.y;

    float camera_x_center = x_center * factor;
    float camera_y_center = y_center * factor;

    std::array<float, 4> cam_coord = {camera_x_center,
    camera_y_center, calib_distance, 1};
    for (int i =0; i < 3; i++) {
      for (int j = 2 ; j < 3; j++) {
        coord[i] = _cam_to_rob[i][j+1] * cam_coord[i];
      }
    }
    coords.push_back(coord);
  }
  return coords;
}
