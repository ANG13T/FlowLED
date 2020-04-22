const int whiteLED = 8;
const int yellowLED = 9;
const int greenLED = 10;
const int blueLED = 11;
const int potReciever = 0;
const int addButton = 4;
const int subButton = 3;
const int resetButton = 2;


void setup() {
  // put your setup code here, to run once:
  pinMode(whiteLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(potReciever, INPUT);
  pinMode(addButton, INPUT);
  pinMode(subButton, INPUT);
  pinMode(resetButton, INPUT);
  Serial.begin(9600);
}

int addButtonVal;
int subButtonVal;
int resetButtonVal;
int potVal;

void loop() {
  // put your main code here, to run repeatedly:
  addButtonVal = digitalRead(addButton);
  subButtonVal = digitalRead(subButton);
  resetButtonVal = digitalRead(resetButton);
  potVal = analogRead(potReciever);
  potVal = map(potVal, 0, 1023, 0, 180);
  Serial.println(potVal);

  if(addButtonVal == HIGH){
    Serial.println("Add Button Pushed");
    delay(100);
  }
  if(subButtonVal == HIGH){
    Serial.println("Subtract Button Pushed");
    delay(100);
  }
  if(resetButtonVal == HIGH){
    Serial.println("Reset Button Pushed");
    delay(100);
  }

  if(potVal >= 0){
    digitalWrite(whiteLED, HIGH);
  }else{
    digitalWrite(whiteLED, LOW);
  }

  if(potVal >= 45){
     digitalWrite(yellowLED, HIGH);
  }else{
    digitalWrite(yellowLED, LOW);
  }

  if(potVal >= 90){
     digitalWrite(greenLED, HIGH);
  }else{
    digitalWrite(greenLED, LOW);
  }

  if(potVal >= 135){
     digitalWrite(blueLED, HIGH);
  }else{
    digitalWrite(blueLED, LOW);
  }
  
}
