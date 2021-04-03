/*======================================================
  |   Multi-Function Motor Driver and Control Board    |
  |    4 CH x (DC Motor Control)                       |
  |                                                    |
  |    Design by Raweeroj Thongdee                     |   
  ======================================================*/


  #include "Arduino.h"
  
  #ifndef DCmotor_h
  #define DCmotor_h

// Arduino pins for the PWM signals to control motor speed
  #define MOTOR1_SPEED_PIN   4  
  #define MOTOR2_SPEED_PIN   7 
  #define MOTOR3_SPEED_PIN   8 
  #define MOTOR4_SPEED_PIN   9

// These are used to set the direction of motor 
  #define MOTOR1_INA_PIN     22
  #define MOTOR1_INB_PIN     23
  #define MOTOR2_INA_PIN     24
  #define MOTOR2_INB_PIN     25
  #define MOTOR3_INA_PIN     26
  #define MOTOR3_INB_PIN     27
  #define MOTOR4_INA_PIN     28
  #define MOTOR4_INB_PIN     29

// Motor function codes
  #define FORWARD   1
  #define BACKWARD  2
  #define BRAKE     3
  #define RELEASE   4

class DCmotor
{
  public:
      DCmotor();
      void motor(int numMotor, int command, int speed);
  
  private:
      void motor_output(int output, int high_low, int speed);

};

#endif