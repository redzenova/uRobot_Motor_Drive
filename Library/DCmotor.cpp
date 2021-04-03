/*======================================================
  |   Multi-Function Motor Driver and Control Board    |
  |    4 CH x (DC Motor Control)                       |
  |                                                    |
  |    Design by Raweeroj Thongdee                     |   
  ======================================================*/


    #include "Arduino.h"
    #include "DCmotor.h"

DCmotor::DCmotor()
{

}   

void DCmotor::motor(int numMotor, int command, int speed)
{
  int motorA, motorB;

  if (numMotor >= 1 && numMotor <= 4)
  {  
    switch (numMotor)
    {
    case 1:
      motorA   = MOTOR1_INA_PIN;
      motorB   = MOTOR1_INB_PIN;
      break;
    case 2:
      motorA   = MOTOR2_INA_PIN;
      motorB   = MOTOR2_INB_PIN;
      break;
    case 3:
      motorA   = MOTOR3_INA_PIN;
      motorB   = MOTOR3_INB_PIN;
      break;
    case 4:
      motorA   = MOTOR4_INA_PIN;
      motorB   = MOTOR4_INB_PIN;
      break;
    default:
      break;
    }

    switch (command)
    {
    case FORWARD:
      motor_output (motorA, HIGH, speed);
      motor_output (motorB, LOW, -1);     // -1: no PWM set
      break;
    case BACKWARD:
      motor_output (motorA, LOW, speed);
      motor_output (motorB, HIGH, -1);    // -1: no PWM set
      break;
    case BRAKE:
      motor_output (motorA, LOW, 255); // 255: fully on.
      motor_output (motorB, LOW, -1);  // -1: no PWM set
      break;
    case RELEASE:
      motor_output (motorA, LOW, 0);  // 0: output floating.
      motor_output (motorB, LOW, -1); // -1: no PWM set
      break;
    default:
      break;
    }
  }      
}

void DCmotor::motor_output(int out, int high_low, int speed)
{
  int motorPWM;

  switch (out)
  {
  case MOTOR1_INA_PIN:
  case MOTOR1_INB_PIN:
    motorPWM = MOTOR1_SPEED_PIN;
    break;
  case MOTOR2_INA_PIN:
  case MOTOR2_INB_PIN:
    motorPWM = MOTOR2_SPEED_PIN;
    break;
  case MOTOR3_INA_PIN:
  case MOTOR3_INB_PIN:
    motorPWM = MOTOR3_SPEED_PIN;
    break;
  case MOTOR4_INA_PIN:
  case MOTOR4_INB_PIN:
    motorPWM = MOTOR4_SPEED_PIN;
    break;
  default:
    // Use speed as error flag, -1000 = invalid output.
    speed = -1000;
    break;
  }

  if (speed != -1000)
  {
    pinMode(out, OUTPUT);
    digitalWrite(out, high_low);

    if (speed >= 0 && speed <= 255)    
    {
      analogWrite(motorPWM, speed);
    }
  }
}
