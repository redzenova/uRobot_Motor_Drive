/*======================================================
  |   Multi-Function Motor Driver and Control Board    |
  |    4 CH x (DC Motor Control)                       |
  |    2 CH x (NXT/EV3 Motor Drive and Control)        |
  |    6 CH x (Servo Motor Control)                    |
  |                                                    |
  |    Design by Raweeroj Thongdee                     |   
  ======================================================*/
  
  #include <DCmotor.h>
  #include <ServoMotor.h>
  
  DCmotor M;
  Servo s1;


  /* Encoder output to Arduino Interrupt pin */
  #define ENC1_IN_PIN 2
  #define ENC2_IN_PIN 3
  #define ENC3_IN_PIN 18
  #define ENC4_IN_PIN 19
  
/*==================| Define-Value |====================*/
  /*Motor encoder output pulse per rotation (pps) (change as required)*/
  #define ENC1_COUNT_REV 1440
  #define ENC2_COUNT_REV 1440
  #define ENC3_COUNT_REV 1440
  #define ENC4_COUNT_REV 1440
  
  /* Pulse count from encoder */
  volatile long encoderValue = 0;
 
  /* One-second interval for measurements */
  int interval = 1000;
 
  /* Counters for milliseconds during interval */
  long previousMillis = 0;
  long currentMillis = 0;
 
  /* Variable for RPM measuerment */
  int rpm = 0;
 
  /* Variable for PWM motor speed output */
  int motorPwm = 0;

  //void updateEncoder();
  

void setup() {
  // Setup Serial Monitor
  Serial.begin(9600);
  
//  pinMode(MC1_SPEED_PIN, OUTPUT);
//  pinMode(MC1_INA_PIN, OUTPUT);
//  pinMode(MC1_INB_PIN, OUTPUT);
//
//   // Set encoder as input with internal pullup   
//  pinMode(ENC1_IN, INPUT_PULLUP);

//  // Attach interrupt 
//  attachInterrupt(digitalPinToInterrupt(ENC1_IN), updateEncoder, RISING);
//  
//  // Setup initial values for timer
//  previousMillis = millis();

    s1.attach(SERVO4);
}

void loop() {
  M.motor(4,FORWARD,32);
  delay(2000);
  M.motor(4,RELEASE,32);
  delay(2000);
  M.motor(4,BACKWARD,32);
  delay(2000);
  M.motor(4,RELEASE,32);
  delay(2000);

  s1.write(0);
  delay(1000);
  s1.write(45);
  delay(1000);
  s1.write(90);
  delay(1000);
  s1.write(135);
  delay(1000);  
  s1.write(180);
  delay(1000);
  s1.write(135);
  delay(1000);
  s1.write(90);
  delay(1000);
  s1.write(45);
  delay(1000);


//  analogWrite(MC1_SPEED_PIN, 20);   // 100% 
//  digitalWrite(MC1_INA_PIN, HIGH);
//  digitalWrite(MC1_INB_PIN, LOW);
//  delay(2000);
//  analogWrite(MC1_SPEED_PIN, 127);   // 50% 
////  digitalWrite(MC1_INA_PIN, LOW);
////  digitalWrite(MC1_INB_PIN, HIGH);
//  analogWrite(MC1_SPEED_PIN, 63);   // 25%
//  delay(2000);
//  analogWrite(MC1_SPEED_PIN, 0);   // 0% 
//  delay(2000);
//  analogWrite(MC1_SPEED_PIN, 63);   // 25%
//  delay(2000);
//  analogWrite(MC1_SPEED_PIN, 127);   // 50% 
//  delay(2000);

//  // Update RPM value every second
//  currentMillis = millis();
//  if (currentMillis - previousMillis > interval) {
//    previousMillis = currentMillis;
// 
// 
//    // Calculate RPM
//    rpm = (float)(encoderValue * 60 / ENC1_COUNT_REV);
// 
//    // Only update display when there is a reading
//    if (rpm > 0) {
//      Serial.print('\t');
//      Serial.print(" PULSES: ");
//      Serial.print(encoderValue);
//      Serial.print('\t');
//      Serial.print(" SPEED: ");
//      Serial.print(rpm);
//      Serial.println(" RPM");
//    }
//    
//    encoderValue = 0;
//}
}

//void updateEncoder()
//{
//  // Increment value for each pulse from encoder
//  encoderValue++;
//}
//
//void MOTOR(){
//  
//}
