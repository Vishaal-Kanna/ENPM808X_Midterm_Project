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

#include "../include/pid.hpp"

#include <cmath>
#include <iostream>

void pid::PID::setKp(double val) { _Kp = val; }

double pid::PID::getKp() { return _Kp; }

void pid::PID::setKd(double val) { _Kd = val; }

double pid::PID::getKd() { return _Kd; }

void pid::PID::setKi(double val) { _Ki = val; }

double pid::PID::getKi() { return _Ki; }

void pid::PID::setTstep(float val) {
  if (val > 0) {
    _tstep = val;
  } else {
    _tstep = 0.1;
  }
}

float pid::PID::getTstep() { return _tstep; }

double pid::PID::computeCommand(double V_target, double V_current,
                                double total_error) {
  double error = V_target - V_current;

  double p = _Kp * error;
  double i = _Ki * total_error * _tstep;
  double d = _Kd * (error - _prev_error) / _tstep;

  return p + i + d;
}
