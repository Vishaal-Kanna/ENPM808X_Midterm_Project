/** MIT License
 * Copyright (c) 2022 Vishaal Kanna Sivakumar, Sahruday Patti
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

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

std::array<float, 4> Transformation_module::transform_2dto3D(
    cv::Rect r) {

  

  float _focalLength = _intrinsics[1][1];
  double _calib_factor = 0.0;
  std::array<float, 4> coord = {0, 0, 0, 1};
 
  double factor = _avg_human_height / r.height;

  _calib_factor = _focalLength * _avg_human_height;

  float calib_distance = _calib_factor / r.height;

  float x_center = (r.width / 2.0) + r.x;
  float y_center = (r.height / 2.0) + r.y;

  float camera_x_center = x_center * calib_distance/_focalLength;
  float camera_y_center = y_center * calib_distance/_focalLength;

    std::array<float, 4> cam_coord = {camera_x_center, camera_y_center,
                                      calib_distance + _cam_to_rob[3][2], 1};
    // for (int i = 0; i < 3; i++) {
    //   for (int j = 2; j < 3; j++) {
    //     coord[i] = (_cam_to_rob[i][j + 1] * cam_coord[i]);
    //   }
    // }



  return cam_coord;
}
