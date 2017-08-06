#include "PID.h"

#include <random>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <math.h>
#include <iostream>
#include <sstream>
#include <string>
#include <iterator>
#include <numeric>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {

    Kp_ = Kp;
    Ki_ = Ki;
    Kd_ = Kd;

    Kp_ =  0.22;
    Kd_ = 2.55;
    Ki_ = 0.000195;

    p_error =0;
    d_error = 0;
    i_error = 0;
    cte_length = 0 ;
}



void PID::UpdateError(double cte) {
    //Update Error
    d_error = cte - p_error;
    p_error = cte;
    i_error += cte;
    
    //Add Update Weight Steps
    cte_lst.push_back(cte);
    cte_length += 1;
    
    //This steps are required when we want to calcualte the initial parameters for the first time. You can check by comment out
    /*
    if(cte_length > 30 ){
        vector<double> y(cte_lst.end()-30,cte_lst.end());
        cte_lst = y;
        double total_error = PID::GetErrorSquare();
       

        if(total_error >= 0.3){
            Kp_ += 0.001;
        }

        if(total_error >= 0.1 && total_error < 0.3 ){
            Kd_ += 0.01;
        }
        
        if(total_error >= 0.01 && total_error< 0.1){
            Ki_ += 0.000001;
        }
        
        
        if(cte_length % 100 ==0 ){
            cout<<"CTE LENGTH "<<cte_length <<endl;;
            cout<<"It's total error:"<<total_error<<endl;
            cout<<"It's p error    :"<<p_error<<endl;
            cout<<"It's d error    :"<<d_error<<endl;
            cout<<"It's i error    :"<<i_error<<endl;
            cout<<"Im Kp_          :"<<Kp_<<endl;
            cout<<"Im Kd_          :"<<Kd_<<endl;
            cout<<"Im Ki_          :"<<Ki_<<endl;
            cout<<"\n"<<endl;
        }
     
      }
     **/
    
    
    

    }


// Code to calculate the mean CTE Squared. 
double PID::GetErrorSquare() {
    double err =0;
    for(int i = 0 ; i< cte_lst.size() ;i++){
        err += pow(cte_lst[i],2.0);
    }
    err = err / cte_lst.size();
    return err;
}

double PID::TotalError(){
    double steer = (-1) * p_error * Kp_ - d_error * Kd_ - i_error * Ki_;
    return steer;
}

