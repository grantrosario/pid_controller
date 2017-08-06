# CarND-Controls-PID
[![Udacity - Self-Driving Car NanoDegree](https://s3.amazonaws.com/udacity-sdc/github/shield-carnd.svg)](http://www.udacity.com/drive)

[image1]: ./pic/car_pic.png
[image1]: ./pic/plot.png

This is part of udacity self-driving car nanodegree project part4. In this project I have runed the car in the simulator by adjusting steering angle of the car using PID control. To implement PID controller we have to tune three parameters. **Kp_**(proportional control) to handle overal Cross-Track-Error(difference between model's steering angle and required steering angle), **Kd_**(Differntial control) to handle differential of CTE and **Ki_**(Integeral control) to handle integeral of CTE.

The source code of this project consists with followings.
* main.cpp: Recieve data and process data from simulator.
* PID.h/PID.cpp: code to proceed the PID Control. 
* visualization.ipynb jupyter notebook file to visualize the relation ship between Mean Squared CTE and parameters. 

 

The Simulator can be downloaded [here](https://github.com/udacity/self-driving-car-sim/releases).

---

## Basic Build Instructions

I used xcode as main IDE. You can execute project with ide_profiles/xcode/PARTICLE_FILTER.xcodeproj file. 

Also you can execute project with following steps.
0. Install [uWebSocketIO](https://github.com/uWebSockets/uWebSockets) for either Linux or Mac systems and [Windows 10 Bash on Ubuntu](https://www.howtogeek.com/249966/how-to-install-and-use-the-linux-bash-shell-on-windows-10/) for windows.
1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make` 
4. Run it: `./particle_filter`  
5. Run the simulator and watch the results.

---
## Model Construction Steps.

### Update parameters. 
* To implement the PID control I have used following logic.
    * Increase Kp_ parameter by 0.001 if the recent 30th Mean Square Error value of the controller is greater than 0.3 
    * Increase Kd_ parameter by 0.01 if the recent 30th Mean Square Error value of the controller is with in 0.3 and 0.1
    * Increase Ki_ parameter by 0.000001 if the recent 30th Mean Squar Error value of the controller is with in 0.1 and 0.01
    
### Select tuned parameters.

* Rather than let the parameters to keep update themselves we have to select parameters for follwing reasons. 
    * (1) Cannot control steering angle of initial steps of driving. 
    * (2) Excessively increased parameter could lead to further oscillation. 
* By tracking Kp_, Kd_, and Ki_ value find the parameter bring us the best result. 

![alt text][image2]


---

## Results
* The Car run with this PID-Control

[![alt text][image1]](https://www.youtube.com/watch?v=Iz-l3CekfO8)

