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
#include <unordered_map>
/**
 * @brief Class to track the humans detected in a given image
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
  Tracking_module() {}

  /**
   * @brief Set the value of track_ids
   *
   * @param val
   * @return void
   */
  void set_track_ids(std::unordered_map<int, cv::Rect> tracks);

  /**
   * @brief Method to associate Ids based on IOU
   *
   * @param cv::Mat image
   * @return std::vector<cv::rect>
   */
  std::vector<cv::Rect> hungarian_algorithm(
      std::vector<cv::Rect> bboxes_frame1, std::vector<cv::Rect> bboxes_frame2);

  /**
   * @brief Method to associate Ids based on IOU
   *
   * @param cv::Mat image
   * @return std::vector<cv::rect>
   */
  void track_human(cv::Mat image1, cv::Mat image2);

 private:
  std::unordered_map<int, cv::Rect> _track_ids;  ///< Tracking Ids
};
