/**
 * @file pid.cpp
 * @authors Rishabh Singh, Vishaal Kanna Sivakumar
 * @authors Part 2: Sanchit Kedia, Adarsh Malapaka
 * @brief Stub class for the PID controller
 * @version 0.1
 * @date 2022-10-02
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../include/ACME_robot.hpp"

#include <iostream>
#include <vector>

void ACME_robot::set_detector_parameters(int img_width, int img_height, float conf_threshold, float nms_threshold)
{ detector.set_img_width(img_width);
  detector.set_img_height(img_height);
  detector.set_conf_threshold(conf_threshold);
  detector.set_nms_threshold(nms_threshold); }

void ACME_robot::set_tracker_parameters(std::unordered_map<int, cv::Rect>tracks)
{ tracker.set_track_ids(tracks); }

void ACME_robot::set_transformation_parameters(float intrinsic[3][3], float cam_to_rob[3][4])
{ transforms.set_intrinsics(intrinsic);
  transforms.set_cam_to_rob(cam_to_rob); }

void ACME_robot::perception_stack(int img_folder_path)
{   
}
