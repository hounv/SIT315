//Task M1.T2P
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
  //Set up Interrupt for the motion
  attachInterrupt(digitalPinToInterrupt(MOT_PIN), buttonHandler, CHANGE);
  //Set the LED & BUZ as output
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZ_PIN, OUTPUT);
  //opens serial port, set data rate to 9600 bps
  Serial.begin(9600);
}

void loop()
{
  
}
//If the button state has been changed update the LED
void buttonHandler()
{
  uint8_t mot1State = digitalRead(MOT_PIN);
  digitalWrite(LED_PIN, digitalRead(MOT_PIN));
  digitalWrite(BUZ_PIN, digitalRead(MOT_PIN));
  
  Serial.println(mot1State);//Print to serial
}