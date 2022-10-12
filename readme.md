# Human Detection and Tracking

Perception is an integral part of any autonomous system. Knowing the surrounding environment enables the system to take suitable actions and navigate to the desired goal location and also augments the control system of the robot to perform a variety of tasks. We want to design one important part of the control system, within the perception stack of acme robotics which is Human detection, and tracking and providing coordinates of humans present in the scene with respect to the Robot’s Reference frame. This Repository is used for development of this module.

# Team
Vishaal Sivakumar (vishaal@umd.edu)
Sahruday Patti (sahruday@umd.edu) (UID: 118218366)

[Phase 0 presentation] (https://drive.google.com/file/d/1ub64094s9hPrDXhbEKSXYC8esveSZAHf/view?usp=sharing) 

## Standard install via command-line
```
git clone --recursive https://github.com/Vishaal-Kanna/ENPM808X_Midterm_Project
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


