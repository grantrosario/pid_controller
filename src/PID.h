#ifndef PID_H
#define PID_H
#include <random>

class PID {

public:
  /*
  * Errors
  */
  double p_error;
  double i_error;
  double d_error;
  
  int cte_length;
  
  std::vector<double> cte_lst ;

  
  
  /*
  * Coefficients
  */ 
  double Kp_;
  double Ki_;
  double Kd_;

  
  double steering; 

  /*
  * Constructor
  */
  PID();

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Initialize PID.
  */
  void Init(double Kp, double Ki, double Kd);
  

  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(double cte);
  
  
  /*
   * Calculate the steering value. 
   */
  double GetErrorSquare();
  

  /*
  * Calculate the total PID error.
  */
  double TotalError();
  
};

#endif /* PID_H */
