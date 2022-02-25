//-------------------------------------- IMACHE 2021 ROBOT ----------------------------------------
//motors_left                                     // 2x Micro Metal Gearmotor 50:1 (L298N)
#define IN1 2
#define IN2 4
#define ENL 3                                     // PWM control pin for right motors

//motors_right                                    // 2x Micro Metal Gearmotor 50:1 (L298N)
#define IN3 7
#define IN4 8
#define ENR 9                                     // PWM control pin for right motors

//sensors_distance
const int S1 = A5;                                     // Left Sharp IR GP2Y0A60SZLF (10-150cm, analog)
const int S2 = A6;                                     // Right Sharp IR GP2Y0A60SZLF (10-150cm, analog)

//sensor_colour
#define SC A7                                     // QTR-1A Reflectance Sensor (analog) 

// Create variable to store the distance:


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
  pinMode (SC, INPUT);
  delay(3000);                                    // Delay before starting the main code for end-user ease of use
}

//------------------------------------------- MAIN CODE -------------------------------------------
void loop()                                       
{
  double sensorLeft = 187754 * pow(analogRead(S1), -1.49);
  double sensorRight = 187754 * pow(analogRead(S2), -1.51);
  double difference = sensorLeft - sensorRight;
  delay(15);
  
  if (difference > 0)
  { 
  forward(150,125 - difference*2); 
  }
  else if (difference < 0)
  {
   forward(150 - difference*2,125);
  }
  else if (difference == 0)
  {
   forward(150,125);
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
