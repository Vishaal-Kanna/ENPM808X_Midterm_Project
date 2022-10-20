[![Build Status](https://github.com/Vishaal-Kanna/ENPM808X_Midterm_Project/actions/workflows/build_and_coveralls.yml/badge.svg)](https://github.com/Vishaal-Kanna/ENPM808X_Midterm_Project/actions/workflows/build_and_coveralls.yml)

[![Coverage Status](https://coveralls.io/repos/github/Vishaal-Kanna/ENPM808X_Midterm_Project/badge.svg?branch=master)](https://coveralls.io/github/Vishaal-Kanna/ENPM808X_Midterm_Project?branch=master)

# Human Detection and Tracking

Perception is an integral part of any autonomous system. Knowing the surrounding environment enables the system to take suitable actions and navigate to the desired goal location and also augments the control system of the robot to perform a variety of tasks. We want to design one important part of the control system, within the perception stack of acme robotics which is Human detection, and tracking and providing coordinates of humans present in the scene with respect to the Robot’s Reference frame. This Repository is used for development of this module.

# Team
[Vishaal Sivakumar](vishaal@umd.edu) UID: 117764314

[Sahruday Patti](sahruday@umd.edu) UID: 118218366

[Phase0 Presentation](https://drive.google.com/file/d/1ub64094s9hPrDXhbEKSXYC8esveSZAHf/view?usp=sharing) 

[AIP sheet](https://docs.google.com/spreadsheets/d/1pYYn6fuLaZafYxjfUbE6aWcIrWNkj-Lk/edit?usp=sharing&ouid=117244734534887324936&rtpof=true&sd=true)

[Sprint Meeting](https://docs.google.com/document/d/1XypCPp2geL_ffwExqyoCF2SI7ATvjYEgtfYST-q0xqE/edit?usp=sharing)

## Standard install via command-line
```
git clone --recursive https://github.com/Vishaal-Kanna/ENPM808X_Midterm_Project
cd <path to repository>
mkdir build
cd build
cmake ..
make
```

## Building for code coverage
```
sudo apt-get install lcov
cmake -D COVERAGE=ON -D CMAKE_BUILD_TYPE=Debug ../
make
make code_coverage
```
This generates a index.html page in the build/coverage sub-directory that can be viewed locally in a web browser.

## Modules

### Detection Module
Code stubs for different class methods have been written and a rough code has been made for bounding box detection.

### Tracking Module
Code stubs for class methods have been written. The methods should be updated in the coming week.

### Tranformation Module
The class for transformation is complete. Changes will be done if required in th coming week.

### ACME Robot
Code stubs for class methods have been written. The code will be completed based on rest of the module outputs.

## Known Issues/Bugs
Since the development is in progress and most of the class methods have not yet been completed, we do not have any known issues or bugs.


