/*======================================================
  |   Multi-Function Motor Driver and Control Board    |
  |    4 CH x (DC Motor Control)                       |
  |    2 CH x (NXT/EV3 Motor Drive and Control)        |
  |    6 CH x (Servo Motor Control)                    |
  |                                                    |
  |    Design by Raweeroj Thongdee                     |   
  ======================================================*/

/*==================| Define-PIN |======================*/
  #define MC1_SPEED_PIN   9   
  #define MC1_INA_PIN     7
  #define MC1_INB_PIN     8


/*==================| Define-Value |====================*/
  /*Motor encoder output pulse per rotation (change as required)*/
  #define ENC1_COUNT_REV 374
  /* Encoder output to Arduino Interrupt pin */
  #define ENC1_IN 3
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
  
  pinMode(MC1_SPEED_PIN, OUTPUT);
  pinMode(MC1_INA_PIN, OUTPUT);
  pinMode(MC1_INB_PIN, OUTPUT);

   // Set encoder as input with internal pullup  
  pinMode(ENC1_IN, INPUT_PULLUP);

  // Attach interrupt 
  attachInterrupt(digitalPinToInterrupt(ENC1_IN), updateEncoder, RISING);
  
  // Setup initial values for timer
  previousMillis = millis();
}

void loop() {
  analogWrite(MC1_SPEED_PIN, 20);   // 100% 
  digitalWrite(MC1_INA_PIN, HIGH);
  digitalWrite(MC1_INB_PIN, LOW);
  delay(2000);
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

  // Update RPM value every second
  currentMillis = millis();
  if (currentMillis - previousMillis > interval) {
    previousMillis = currentMillis;
 
 
    // Calculate RPM
    rpm = (float)(encoderValue * 60 / ENC1_COUNT_REV);
 
    // Only update display when there is a reading
    if (rpm > 0) {
      Serial.print('\t');
      Serial.print(" PULSES: ");
      Serial.print(encoderValue);
      Serial.print('\t');
      Serial.print(" SPEED: ");
      Serial.print(rpm);
      Serial.println(" RPM");
    }
    
    encoderValue = 0;
}
}

void updateEncoder()
{
  // Increment value for each pulse from encoder
  encoderValue++;
}
