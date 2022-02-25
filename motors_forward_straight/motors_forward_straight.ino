//-------------------------------------- IMACHE 2021 ROBOT ----------------------------------------

//motors_left                                     // 2x Micro Metal Gearmotor 50:1 (L298N)
#define IN1 2
#define IN2 4
#define ENL 3                                     // PWM control pin for right motors

//motors_right                                    // 2x Micro Metal Gearmotor 50:1 (L298N)
#define IN3 7
#define IN4 8
#define ENR 9                                     // PWM control pin for right motors
#define S1 A5                                     // Left Sharp IR GP2Y0A60SZLF (10-150cm, analog)
#define S2 A6                                     // Right Sharp IR GP2Y0A60SZLF (10-150cm, analog)

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
  pinMode (S1, INPUT);
  pinMode (S2, INPUT);
  delay(3000);                                    // Delay before starting the main code for end-user ease of use
}

void loop()
{
  
  int left_sensor = analogRead(S1);
  int right_sensor = analogRead(S2);
  float difference = left_sensor - right_sensor;
  delay(10);
 //Serial.println(difference);
  
  if (difference > 0)
  { 
  forward(255,230 - difference); 
  }
  else if (difference < 0)
  {
  forward(255 + difference,230);
  }
  else if (difference == 0)
  {
  forward(255,237);
  }
  while(left_sensor >= 500 && right_sensor >= 500)
  { 
     stop_robot();
     delay(10000);
  }
}

//--------------------------------------- FORWARD FUCNTION -----------------------------------------
void forward(int user_speed_left, int user_speed_right)                       
{
  //Forward motors_left
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENL, user_speed_left);
  
  //Forward motors_right
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
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
