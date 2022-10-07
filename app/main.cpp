/**
 * @file main.cpp
 * @authors Rishabh Singh, Vishaal Kanna Sivakumar
 * @brief main function for PID controller
 * @version 0.1
 * @date 2022-10-02
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <cmath>
#include <iostream>

#include "../include/pid.hpp"

int main() {
  pid::PID controller;
  double target_velocity;
  double current_velocity;
  double total_error = 0;

  controller.setKp(0.4);
  controller.setKd(0.3);
  controller.setKi(0.1);
  controller.setTstep(0.1);

  std::cout << "Input the Target velocity " << std::endl;
  std::cin >> target_velocity;
  std::cout << "Input the Current velocity " << std::endl;
  std::cin >> current_velocity;

  while (std::abs(current_velocity - target_velocity) > 0.1) {
    total_error += target_velocity - current_velocity;
    current_velocity += controller.computeCommand(
                            target_velocity, current_velocity, total_error) *
                        controller.getTstep();
  }

  std::cout << "The final error is " << target_velocity - current_velocity
            << std::endl;
  std::cout << "The final velocity is " << current_velocity << std::endl;
}
