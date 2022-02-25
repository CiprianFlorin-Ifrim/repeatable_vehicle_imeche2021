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
#define S1 A5                                     // Left Sharp IR GP2Y0A60SZLF (10-150cm, analog)
#define S2 A6                                     // Right Sharp IR GP2Y0A60SZLF (10-150cm, analog)

//sensor_colour
#define SC A7                                     // QTR-1A Reflectance Sensor (analog) 

//variables
int user_speed_left;
int user_speed_right;

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

void loop()                                       
{
  int left_sensor = analogRead(S1);
  int right_sensor = analogRead(S2);
  double difference = left_sensor - right_sensor;
  Serial.println("Left Sensor: ");
  Serial.println(left_sensor);
  Serial.println("Right Sensor: ");
  Serial.println(right_sensor);
//  Serial.println(difference/5);
  delay(10);
  
}
