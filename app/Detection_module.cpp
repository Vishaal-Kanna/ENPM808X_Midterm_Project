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

void Detection_module::set_img_width(int val)
{ _img_width = val; }

void Detection_module::set_img_height(int val)
{ _img_height = val; }

void Detection_module::set_conf_threshold(float val)
{ _conf_threshold = val; }

void Detection_module::set_nms_threshold(float val)
{ _nms_threshold = val; }

std::vector<cv::Rect> Detection_module::bbox_detector(cv::Mat frame)
{ 
  std::vector<cv::Rect>bboxes;
  Net net = readNetFromDarknet("/home/vishaal/Downloads/yolov3.cfg", "/home/vishaal/Vishaal/UMD_Sem_3/ENPM808X/yolov3.weights");
  Mat blob = blobFromImage(frame, 1/255, Size(_img_width,_img_height), Scalar(0,0,0), true, false);
  net.setInput(blob);

  vector<Mat> outs;

  std::vector<std::string> out_names = net.getUnconnectedOutLayersNames();
  net.forward(outs, out_names);

  //remove_box(frame, outs);
  // imshow("Frame", frame);
  // waitKey(0);

  return bboxes;

}

float Detection_module::calc_IOU(cv::Rect bbox1, cv::Rect bbox2){
  return 0.166;
}

std::vector<cv::Rect> Detection_module::nms(std::vector<cv::Rect>)
{ 
  std::vector<cv::Rect>bboxes_after_nms;
  return bboxes_after_nms;
}
