/**
 * @file Detection_module.hpp
 * @authors Sahruday, Vishaal Kanna Sivakumar
 * @brief This file contains a stub class to represent the Detection module
 * @version 1.0
 * @date 10/07/2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once
#include "Detection_module.hpp"
#include "Tracking_module.hpp"
#include "Transformation_module.hpp"
#include <iostream>
#include <opencv2/opencv.hpp>
/**
 * @brief Class for the robot's human detection and tracking functions
 * @param class_data
 *
 */

class ACME_robot {
 public:
  /**
   * @brief Default constructor for class Detection_module
   *
   * @param None
   * @return None
   */
  ACME_robot() {
   _img_width = 256;
   _img_height = 256;
   _conf_threshold =0.6;
   _nms_threshold = 0.4;
  }

  /**
   * @brief Set the parameters of the detection module
   *
   * @param val
   * @return void
   */
  void set_detector_parameters(int img_width, int img_height, float conf_threshold, float nms_threshold);

  /**
   * @brief Set the parameters of the Tracking module
   *
   * @param val
   * @return void
   */
  void set_tracker_parameters(int val);

  /**
   * @brief Set the parameters of the Transformation module
   *
   * @param val
   * @return void
   */
  void set_transformation_parameters(int val);

  /**
   * @brief Set the parameters of the Transformation module
   *
   * @param val
   * @return void
   */
  void perception_stack();

 private:
  int _img_width; ///< Image width
  int _img_height; ///< Image height
  float _conf_threshold; ///< Confidence threshold
  float _nms_threshold; ///< Non maximum suppression threshold
  Detection_module detector;
  Tracking_module tracker;
  Transformation_module transforms;
};
