// sensor pin
int sensorPin = A0;
// buzzer pin
int buzzer = 12;
// var for sensor value
int sensorVal = 0;
// laser pin
int laser = 7;
// var for alarm code
int code = 0;

// button pin (in this example, only one is used)
#define Button1 A5

void setup() {
  Serial.begin(9600);
  pinMode(laser,OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(Button1, INPUT);
  // on start, laser will be turned on
  digitalWrite(laser,HIGH);
}

// vars for alarm and button state
bool alarm = false, button1_state;

void loop() {
  // read button state
  button1_state = digitalRead(Button1);
  // read light sensor value
  sensorVal = analogRead(sensorPin);
  int valLight = analogRead(A2);
  Serial.println(valLight,DEC);
  Serial.println(sensorVal);
  delay(100);
  // if valLight is lower than 300, it means the laser is interruped
  if(valLight < 300 ) {
    alarm = true;
    digitalWrite(laser,LOW);
  }
  // if alarm is true, buzzer starts making sounds
  if (alarm) {
    tone(buzzer,100);
    delay(100);
    noTone(buzzer);
    Serial.println("ALARM ON");
  }
  // at every button press, we add 10 to the code var
  if(button1_state && alarm) {
    code += 10;
  }
  // if the button is pressed 3 times, the alarm resets
  if(code == 30) {
    noTone(buzzer);
    alarm = false;
    code = 0;
    digitalWrite(laser,HIGH);
    Serial.println("ALARM OFF");
  }
  Serial.println(String(button1_state));
  delay(100);
}
