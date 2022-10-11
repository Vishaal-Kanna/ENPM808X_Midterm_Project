/**
 * @file Detection_module.hpp
 * @authors Sahruday, Vishaal Kanna Sivakumar
 * @brief This file contains a stub class to represent the Tracking module
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
 * @brief Class to localize the locations of humans in a given image
 * @param class_data
 *
 */

class Tracking_module {
 public:
  /**
   * @brief Default constructor for class Detection_module
   *
   * @param None
   * @return None
   */
  Tracking_module() {
  
  }

  /**
   * @brief Method to associate Ids based on IOU
   *
   * @param cv::Mat image
   * @return std::vector<cv::rect>
   */
  std::vector<cv::rect> hungarian_algorithm(std::vector<cv::rect> bboxes_frame1, std::vector<cv::rect> bboxes_frame2);

    /**
   * @brief Method to associate Ids based on IOU
   *
   * @param cv::Mat image
   * @return std::vector<cv::rect>
   */
  void track_human(cv::Mat image1, cv::Mat image2);

 private:
  unordered_map<int, cv::rect> track_ids; ///< Tracking Ids
};
