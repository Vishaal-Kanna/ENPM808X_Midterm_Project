# Human Detection and Tracking

Perception is an integral part of any autonomous system. Knowing the surrounding environment enables the system to take suitable actions and navigate to the desired goal location and also augments the control system of the robot to perform a variety of tasks. This project aims to solve the human detection and tracking problem for the ACME robot.

## Overview


## Standard install via command-line
```
git clone --recursive https://github.com/dpiet/cpp-boilerplate
cd <path to repository>
mkdir build
cd build
cmake ..
make
Run tests: ./test/cpp-test
Run program: ./app/shell-app
```

## Building for code coverage (for assignments beginning in Week 4)
```
sudo apt-get install lcov
cmake -D COVERAGE=ON -D CMAKE_BUILD_TYPE=Debug ../
make
make code_coverage
```
This generates a index.html page in the build/coverage sub-directory that can be viewed locally in a web browser.

Phase 0 presentation link: https://drive.google.com/file/d/1ub64094s9hPrDXhbEKSXYC8esveSZAHf/view?usp=sharing 
