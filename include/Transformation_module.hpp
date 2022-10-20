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
 * @file Detection_module.hpp
 * @authors Sahruday, Vishaal Kanna Sivakumar
 * @brief This file contains a stub class to represent the Transformation module
 * @version 1.0
 * @date 10/07/2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once
#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>

/**
 * @brief Class to transform the 2D image detections to 3D locations with
 * respect to the robot frame
 * @param class_data
 *
 */

class Transformation_module {
 public:
  /**
   * @brief Default constructor for class Transformation_module
   *
   * @param None
   * @return None
   */
  Transformation_module() {}

  /**
   * @brief Set the value of intrinsic parameters
   *
   * @param intrinsic
   * @return void
   */
  void set_intrinsics(float intrinsics[3][3]);

  /**
   * @brief Set the value of camera to robot coordinate transformation matrix
   *
   * @param cam_to_rob
   * @return void
   */
  void set_cam_to_rob(float cam_to_rob[3][4]);

  /**
   * @brief Get the 3D coordinates of the bounding box from 2D detections using
   * average height of human
   *
   * @param val
   * @return void
   */
  std::vector<std::array<float, 4>> transform_2dto3D(
      std::vector<cv::Rect> rect);

 private:
  float _intrinsics[3][3] = {
      {0, 1, 2}, {3, 4, 5}, {6, 7, 8}};  ///< Camera's intrinsic parameters
  float _cam_to_rob[3][4] = {
      {0, 1, 2, 3},
      {4, 5, 6, 7},
      {8, 9, 10,
      11}};  ///< Tranformation from camera's coordinates to robot coordinates_
  double _avg_human_height;
};
