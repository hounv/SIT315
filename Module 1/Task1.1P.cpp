//Task M1.T1P
//connect and assign pins
const uint8_t MOT_PIN = 2;
const uint8_t BUZ_PIN = 4;
const uint8_t LED_PIN = 13;

//Initialize the states for default is off
uint8_t mot0State = LOW;
uint8_t ledState = LOW;
uint8_t buzState = LOW;

//Set up the board
void setup()
{
  //Set the motion as input
  pinMode(MOT_PIN, INPUT);
  //Set the LED & BUZ as output
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZ_PIN, OUTPUT);
  //opens serial port, set data rate to 9600 bps
  Serial.begin(9600);
}

void loop()
{
  //Read state of the button
  uint8_t mot1State = digitalRead(MOT_PIN);
  
  //Print to serial
  Serial.print(mot1State);
  Serial.print(mot0State);
  Serial.print(ledState);
  Serial.print(buzState);
  Serial.println("1");
  
  
  //If button state has been changed then output LED & BUZ
  if(mot1State != mot0State)
  {
    ledState = !ledState;
    digitalWrite(LED_PIN, ledState);
    buzState = !buzState;
    digitalWrite(BUZ_PIN, buzState);
  }  
  mot0State = mot1State;
    
  //Wait half second
  delay(500);
}