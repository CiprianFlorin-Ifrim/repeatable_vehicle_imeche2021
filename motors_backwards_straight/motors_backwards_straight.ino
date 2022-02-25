//-------------------------------------- IMACHE 2021 ROBOT ----------------------------------------

//motors_left                                     // 2x Micro Metal Gearmotor 50:1 (L298N)
#define IN1 2
#define IN2 4
#define ENL 3                                     // PWM control pin for right motors

//motors_right                                    // 2x Micro Metal Gearmotor 50:1 (L298N)
#define IN3 7
#define IN4 8
#define ENR 9                                     // PWM control pin for right motors


//------------------------------------------ SETUP CODE -------------------------------------------
void setup()                                      
{                                                 // pinMode for all input/output devices
  Serial.begin(9600);
  pinMode (IN1, OUTPUT);                          
  pinMode (IN2, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);
  pinMode (ENL, OUTPUT);
  pinMode (ENR, OUTPUT);
  delay(3000);                                    // Delay before starting the main code for end-user ease of use
}

void loop() {
  backwards(60, 68);
  delay(2000);
  stop_robot();
  
}

//-------------------------------------- BACKWARDS FUNCTION ---------------------------------------
void backwards(int user_speed_left, int user_speed_right)
{
  //Bacxkwards motors_left
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENL, user_speed_left);
  
  //Backwards motors_right
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENR, user_speed_right);
}

//----------------------------------------- STOP FUNCTION ---------------------------------------
void stop_robot()
{
  //Bacxkwards motors_left
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENL, 0);
  
  //Backwards motors_right
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENR, 0);
}
