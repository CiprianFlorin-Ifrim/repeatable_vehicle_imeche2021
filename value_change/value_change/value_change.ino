//sensor_colour
#define SC A7                                     // QTR-1A Reflectance Sensor (analog) 

int white_times = 0;
  
void setup() 
{
  // put your setup code here, to run once:
  pinMode (SC, INPUT);
  Serial.begin(9600);
  delay(5000);
}

void loop() 
{
  
  // put your main code here, to run repeatedly:
  float colour_sensor = analogRead(SC);
  delay(10);   
  Serial.println("Value:");
  Serial.println(colour_sensor);
  if (colour_sensor >= 250 && colour_sensor <= 450)
  {
    white_times = white_times + 1;
    Serial.println("Times seen white:");
    Serial.println(white_times);
  }

  
}
  


// COLOUR BANDS (DEBUGGING)
// White = 360-400
// Black = 930-1023
// Blue = 60-90
// Yellow = 45-59
// Red = 35-44 
