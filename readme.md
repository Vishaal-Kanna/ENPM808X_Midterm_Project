[![Build Status](https://github.com/Vishaal-Kanna/ENPM808X_Midterm_Project/actions/workflows/build_and_coveralls.yml/badge.svg)](https://github.com/Vishaal-Kanna/ENPM808X_Midterm_Project/actions/workflows/build_and_coveralls.yml)

[![Coverage Status](https://coveralls.io/repos/github/Vishaal-Kanna/ENPM808X_Midterm_Project/badge.svg?branch=master)](https://coveralls.io/github/Vishaal-Kanna/ENPM808X_Midterm_Project?branch=master)

[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](https://opensource.org/licenses/MIT)

# Human Detection and Tracking

Perception is an integral part of any autonomous system. Knowing the surrounding environment enables the system to take suitable actions and navigate to the desired goal location and also augments the control system of the robot to perform a variety of tasks. We want to design one important part of the control system, within the perception stack of acme robotics which is Human detection, and tracking and providing coordinates of humans present in the scene with respect to the Robot’s Reference frame. This Repository is used for development of this module.

# Team
[Vishaal Sivakumar](vishaal@umd.edu) UID: 117764314

[Sahruday Patti](sahruday@umd.edu) UID: 118218366

## Presentation

[Phase0 Presentation](https://drive.google.com/file/d/1ub64094s9hPrDXhbEKSXYC8esveSZAHf/view?usp=sharing) 

[Phase1 Presentation](https://drive.google.com/file/d/153FP7lnLD9CjYQmFsAVQo6xBl6MGawtI/view?usp=sharing)

[Phase2 Presentation](https://drive.google.com/file/d/18FPWkRjVS88V6VPK5J5V68W88ig2g-zX/view?usp=sharing)

## Development process

Agile iterative process with Test driven development Approach. We switch Driver and navigator roles depending on the task.

[AIP sheet](https://docs.google.com/spreadsheets/d/1pYYn6fuLaZafYxjfUbE6aWcIrWNkj-Lk/edit?usp=sharing&ouid=117244734534887324936&rtpof=true&sd=true)

[Sprint Meeting](https://docs.google.com/document/d/1XypCPp2geL_ffwExqyoCF2SI7ATvjYEgtfYST-q0xqE/edit?usp=sharing)


UML Diagram:

![Alt text](https://github.com/Vishaal-Kanna/ENPM808X_Midterm_Project/blob/Dev/UML/revised/uml_class_diagram.PNG?raw=true "Title")

![Activity Diagram](https://github.com/Vishaal-Kanna/ENPM808X_Midterm_Project/blob/Dev/UML/revised/uml_activity_diagram.pdf)

![QuadChart](https://github.com/Vishaal-Kanna/ENPM808X_Midterm_Project/blob/Dev/Proposal_docs/quad_chart.pdf)

## Results

![Result_Frame](https://github.com/Vishaal-Kanna/ENPM808X_Midterm_Project/blob/Dev/outputs/output1.png)


## Running

Download the video and Yolov3 tiny weights from ![here](https://drive.google.com/drive/folders/1_tvLAOI7ZmhKPQpJbTqEpOvd83U_eqoD)

Change the file path respectively in the detection module.cpp

## Dependencies
Install Dependencies listed in requirements.sh
```
sh requirements.sh
```

## Standard install via command-line
```
git clone --recursive https://github.com/Vishaal-Kanna/ENPM808X_Midterm_Project
cd <path to repository>
mkdir build
cd build
cmake ..
make
```
To Run the module 
```
./app ACME
```

To Run Tests
```
./test/cpp-test
```



## Building for code coverage
```
sudo apt-get install lcov
cmake -D COVERAGE=ON -D CMAKE_BUILD_TYPE=Debug ../
make
make code_coverage
```
This generates a index.html page in the build/coverage sub-directory that can be viewed locally in a web browser.

## Running Cpplint and CppCheck
```
cppcheck --enable=all --std=c++11 -I include/ --suppress=missingIncludeSystem $( find . -name *.cpp | grep -vE -e "^./build/" -e "^./vendor/") > results/cppcheck.txt &&

cpplint $( find . -name *.cpp | grep -vE -e "^./build/" -e "^./vendor/") $( find . -name *.hpp | grep -vE -e "^./build/" -e "^./vendor/") > results/cpplint.txt
```

## Generate Doxygen Documentation
```
cd <path to repository>/Docs

doxygen Doxyfile

firefox index.html
```

## Known issues and bugs

1. Travis and Coveralls Not working due to subscription problems.
2. Tracker module would not work in crowded scenarios.
3. Due to the lack of calibration factors, the camera parameters have been chosen approximately.
4. Doxygen doucmentation is truncated to 1000 files in github.
