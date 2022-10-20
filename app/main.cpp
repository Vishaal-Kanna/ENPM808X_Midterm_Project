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
 * @file main.cpp
 * @authors Sahruday Patti, Vishaal Kanna Sivakumar
 * @brief main function for Human Tracking
 * @version 0.1
 * @date 2022-10-12
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <opencv2/dnn.hpp>
#include <opencv2/opencv.hpp>

#include "../include/Detection_module.hpp"

using namespace std;
using namespace cv;
using namespace dnn;

int main() {
  Detection_module detector;
  Mat frame1 = imread(
      "/home/vishaal/Vishaal/UMD_Sem_3/ENPM808X/ENPM808X_Midterm_Project/"
      "test_img.jpg");

  detector.bbox_detector(frame1);
  return 0;
}
