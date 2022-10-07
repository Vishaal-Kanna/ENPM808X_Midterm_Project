/**
 * @file Detection_module.hpp
 * @authors Sahruday, Vishaal Kanna Sivakumar
 * @brief This file contains a stub class to represent a PID controller
 * @version 1.0
 * @date 10/07/2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once
#include <iostream>
#include <opencv2/core.hpp>
/**
 * @brief Class to localize the locations of humans in a given image
 * @param class_data
 *
 */

class Detection_module {
 public:
  /**
   * @brief Default constructor for class PID
   *
   * @param None
   * @return None
   */
  Detection_module() {

  }

  /**
   * @brief Set the value of img_width constant
   *
   * @param val
   * @return void
   */
  void set_img_width(int val);

  /**
   * @brief Set the value of img_height constant
   *
   * @param val
   * @return void
   */
  void set_img_height(int val);

  /**
   * @brief Set the value of confidence threshold of detections constant
   *
   * @param val
   * @return void
   */
  void set_conf_threshold(float val);

  /**
   * @brief Set the value of Time step
   *
   * @param val
   * @return void
   */
  void set_nms_threshold(float val);

  /**
   * @brief Method to compute the new acceleration
   *
   * @param V_target
   * @param V_current
   * @return double
   */
  vector<cv::rect> bbox_detector(cv::Mat image);

 private:
  int _img_width; ///< Proportional constant
  int _img_height; ///< Derivative constant
  float _conf_threshold; ///< Integral constant
  float _nms_threshold; ///< Time step
};
