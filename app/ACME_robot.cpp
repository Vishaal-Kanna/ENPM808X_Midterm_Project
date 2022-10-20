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
 * @file ACME_robot.cpp
 * @authors Sahruday Patti, Vishaal Kanna Sivakumar
 * @brief Stub class for the ACME Robot
 * @version 0.1
 * @date 2022-10-10
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../include/ACME_robot.hpp"

#include <iostream>
#include <vector>

void ACME_robot::set_detector_parameters(int img_width, int img_height,
                                         float conf_threshold,
                                         float nms_threshold) {
  detector.set_img_width(img_width);
  detector.set_img_height(img_height);
  detector.set_conf_threshold(conf_threshold);
  detector.set_nms_threshold(nms_threshold);
}

void ACME_robot::set_tracker_parameters(
    std::unordered_map<int, cv::Rect> tracks) {
  tracker.set_track_ids(tracks);
}

void ACME_robot::set_transformation_parameters(float intrinsic[3][3],
                                               float cam_to_rob[3][4]) {
  transforms.set_intrinsics(intrinsic);
  transforms.set_cam_to_rob(cam_to_rob);
}

void ACME_robot::perception_stack(std::string img_folder_path) {
  cv::Mat img = cv::imread(img_folder_path);
}
