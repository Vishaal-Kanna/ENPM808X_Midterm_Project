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
 * @file Detection_module.cpp
 * @authors Sahruday Patti, Vishaal Kanna Sivakumar
 * @brief Stub class for the Detection module class
 * @version 0.1
 * @date 2022-10-10
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../include/Detection_module.hpp"

using namespace std;
using namespace cv;
using namespace dnn;

void Detection_module::set_img_width(int val) { _img_width = val; }

void Detection_module::set_img_height(int val) { _img_height = val; }

void Detection_module::set_conf_threshold(float val) { _conf_threshold = val; }

void Detection_module::set_nms_threshold(float val) { _nms_threshold = val; }

std::vector<cv::Rect> Detection_module::bbox_detector(cv::Mat frame) {

  Net net = readNetFromDarknet(
      "/home/vishaal/Downloads/yolov3.cfg",
      "/home/vishaal/Vishaal/UMD_Sem_3/ENPM808X/yolov3.weights");
  Mat blob = blobFromImage(frame, 1 / 255, Size(_img_width, _img_height),
                           Scalar(0, 0, 0), true, false);
  net.setInput(blob);

  vector<Mat> outs;

  vector<std::string> out_names = net.getUnconnectedOutLayersNames();
  net.forward(outs, out_names);

    vector<int> classIds;
    vector<float> confs;
    vector<cv::Rect> bboxes;
    
    for (int i = 0; i < outs.size(); ++i)
    {
        float* data = (float*)outs[i].data;
        std::cout<< outs[i].row(j).colRange(5, outs[i].cols) << std::endl;
        for (int j = 0; j<outs[i].rows; j++)
            { Mat scores = outs[i].row(j).colRange(5, outs[i].cols);
            Point classId;
            double conf;
            /// perform minMaxLoc to get global min n max in scores
            minMaxLoc(scores, 0, &conf, 0, &classId);
            std::cout<<confidence<< std::endl;
            if (confidence > conf_threshold && classId == 0)
            {
              int centerX = (int)(data[0] * _img_width);
              int centerY = (int)(data[1] * _img_height);
              int width = (int)(data[2] * _img_width);
              int height = (int)(data[3] * _img_height);
              int left = centerX - width / 2;
              int top = centerY - height / 2;
              
              classIds.push_back(classId.x);
              confs.push_back((float)conf);
              bboxes.push_back(cv::Rect(left, top, width, height));
            }
            }
    }

    vector<int> indices;
    NMSBoxes(bboxes, confidences, conf_threshold, nms, indices); 

  return indices, bboxes;
}

float Detection_module::calc_IOU(cv::Rect bbox1, cv::Rect bbox2) {
  return 0.166;
}

std::vector<cv::Rect> Detection_module::nms(std::vector<cv::Rect>, vector<float> confs, float _conf_threshold, float _nms_threshold, vector<int> indices) {
  std::vector<cv::Rect> bboxes_after_nms;
  return bboxes_after_nms;
}
