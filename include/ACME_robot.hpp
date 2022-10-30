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
 * @brief This file contains a stub class to represent the ACME robot module
 * @version 1.0
 * @date 10/07/2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <opencv2/opencv.hpp>

#include "../include/Detection_module.hpp"
#include "../include/Tracking_module.hpp"
#include "../include/Transformation_module.hpp"

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
  ACME_robot() { _no_of_bboxes = 0; }

  /**
   * @brief Set the parameters of the detection module
   *
   * @param val
   * @return void
   */
  void set_detector_parameters(int img_width, int img_height,
                               float conf_threshold, float nms_threshold);

  /**
   * @brief Set the parameters of the Transformation module
   *
   * @param val
   * @return void
   */
  void set_transformation_parameters(float intrinsic[3][3],
                                     float cam_to_rob[3][4]);

  /**
   * @brief Set the parameters of the Transformation module
   *
   * @param frame, frame_no
   * @return void
   */
  int perception_stack(cv::Mat frame, int frame_no);

  /**
   * @brief Draw box function
   *
   * @param frame, bboxes, track_ids
   * @return void
   */
  void draw_bboxes(cv::Mat frame,
                   std::unordered_map<int, cv::Rect> bboxes_with_ids, int width,
                   int height);

  /**
   * @brief read
   * @param
   *
   */

  void read_video(std::string filename);

 private:
  size_t _no_of_bboxes;
  Detection_module detector;
  Tracking_module tracker;
  Transformation_module transforms;
};
