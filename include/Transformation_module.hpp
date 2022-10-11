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
#include <opencv2/opencv.hpp>
/**
 * @brief Class to transform the 2D image detections to 3D locations with respect to the robot frame
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
  Transformation_module() {
  }

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
   * @brief Get the 3D coordinates of the bounding box from 2D detections using average height of human
   *
   * @param val
   * @return void
   */
  std::vector<std::array<float, 4>> transform_2dto3D(std::vector<cv::Rect> rect);

 private:
  float _intrinsics[3][3] = {{0,0,0}, {0,0,0}, {0,0,0}}; ///< Camera's intrinsic parameters
  float _cam_to_rob[3][4] = {{0,0,0,0}, {0,0,0,0}, {0,0,0,0}}; ///< Tranformation from camera's coordinates to robot coordinates_
};
