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
 * @file Transformation_module.cpp
 * @authors Sahruday Patti, Vishaal Kanna Sivakumar
 * @brief Stub class for the Transformation module class
 * @version 0.1
 * @date 2022-10-10
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../include/Transformation_module.hpp"

#include <iostream>
#include <vector>

void Transformation_module::set_intrinsics(float intrinsics[3][3]) {}

void Transformation_module::set_cam_to_rob(float cam_to_rob[3][4]) {}

std::vector<std::array<float, 4>> Transformation_module::transform_2dto3D(
    std::vector<cv::Rect> rect) {
  std::array<float, 4> coord = {0, 0, 0, 1};
  std::vector<std::array<float, 4>> coords;
  coords.push_back(coord);
  return coords;
}
