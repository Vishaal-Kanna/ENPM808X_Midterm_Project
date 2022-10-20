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
 * @file Tracking_module.cpp
 * @authors Sahruday Patti, Vishaal Kanna Sivakumar
 * @brief Stub class for the Tracking module class
 * @version 0.1
 * @date 2022-10-10
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../include/Tracking_module.hpp"

#include <iostream>
#include <vector>

void Tracking_module::set_track_ids(std::unordered_map<int, cv::Rect> tracks) {
  _track_ids = tracks;
}

std::vector<cv::Rect> Tracking_module::hungarian_algorithm(
    std::vector<cv::Rect> bboxes_frame1, std::vector<cv::Rect> bboxes_frame2) {
  cv::Rect bbox(0, 0, 256, 256);
  std::vector<cv::Rect> bboxes;
  bboxes.push_back(bbox);
  bboxes.push_back(bbox);
  return bboxes;
}

void Tracking_module::track_human(cv::Mat image1, cv::Mat image2) {}
