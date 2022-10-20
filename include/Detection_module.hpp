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
 * @brief This file contains a stub class to represent the Detection module
 * @version 1.0
 * @date 10/07/2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once
#include <iostream>
#include <opencv2/dnn.hpp>
#include <opencv2/opencv.hpp>
/**
 * @brief Class to localize the locations of humans in a given image
 * @param class_data
 *
 */

class Detection_module {
 public:
  /**
   * @brief Default constructor for class Detection_module
   *
   * @param None
   * @return None
   */
  Detection_module() {
    _img_width = 256;
    _img_height = 256;
    _conf_threshold = 0.6;
    _nms_threshold = 0.4;
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
   * @brief Method to predict locations of humans in the image
   *
   * @param cv::Mat image
   * @return std::vector<cv::rect>
   */
  std::vector<cv::Rect> bbox_detector(cv::Mat frame);

  /**
   * @brief Method to calculate Intersection over Union for two bounding boxes
   *
   * @param std::vector<cv::rect> bbox1
   * @param std::vector<cv::rect> bbox2
   * @return std::vector<cv::rect>
   */
  float calc_IOU(cv::Rect bbox1, cv::Rect bbox2);

  /**
   * @brief Method to perform non-maximum supression and remove overlapping
   * boxes
   *
   * @param std::vector<cv::rect>
   * @return std::vector<cv::rect>
   */
  std::vector<cv::Rect> nms(std::vector<cv::Rect> bboxes);

 private:
  int _img_width;         ///< Image width
  int _img_height;        ///< Image height
  float _conf_threshold;  ///< Confidence threshold
  float _nms_threshold;   ///< Non maximum suppression threshold
};
