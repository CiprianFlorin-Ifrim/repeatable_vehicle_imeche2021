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
int white_times = 0;
int user_speed_left;
int user_speed_right;

//------------------------------------------ SETUP CODE -------------------------------------------
void setup()                                      
{                                                 // pinMode for all input/output devices
//  Serial.begin(9600);
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
  white_times_counted();
  int left_sensor = analogRead(S1);
  int right_sensor = analogRead(S2);
  int difference = (left_sensor - right_sensor);
  delay(10);
 //Serial.println(difference);
  
      if (difference > 0)
      { 
      forward(255,232 - difference); 
      }
      else if (difference < 0)
      {
      forward(255 + difference,232);
      }
      else if (difference == 0)
      {
      forward(255,233);
      }
    
  while (analogRead(S2) > 150 && analogRead(S2) < 680)
  {
  forward(65,68);
  }
  
  while(left_sensor >= 680 && right_sensor >= 680)
   {
     delay(60);
     stop_robot();
     int i = 1;
     while(i == 1)
     {
     white_times_counted();
     backwards(60, 70);
     float colour_sensor = analogRead(SC);
     while(white_times >= 30 && colour_sensor < 450)
     {
     stop_robot();
     delay(5500);
     int x = 1;
     while(x == 1)
     {
//         float colour_sensor = analogRead(SC);
//         while(colour_sensor < 450 || colour_sensor > 850)
//         {
         forward(65,67);
         delay(1000);
         int z = 1;
         while(z == 1)
         {
            int colour_sensor = analogRead(SC);
            while(colour_sensor < 100)
            {
             delay(380);
             stop_robot();
            }
         }   
     } 
     
     
   }
  }  
  }
}


//------------------------------------- WHITE TIMES COUNTED ----------------------------------------
int white_times_counted()
{ 
  float colour_sensor = analogRead(SC);
  delay(10); 
  if (colour_sensor >= 250 && colour_sensor <= 450)
  {
    white_times = white_times + 1;
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


/* 
NOTES:

65,59  = SLOW FORWARD

60, 68 = SLOW BACKWARDS




*/
