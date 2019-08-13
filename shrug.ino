
#define joyX A0
#define joyY A1
int animationSpeed = 400;
//joystick values
int SWpin = 10;
int Xpin = 0;
int Ypin = 1;
int xValue = 0;
int yValue = 0;

void setup() {
  Serial.begin(115200);
  pinMode(SWpin, INPUT);
  digitalWrite(SWpin, HIGH);
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  xValue = analogRead(Xpin);
  yValue = analogRead(Ypin);
  Serial.print(xValue);
  Serial.print("\t");
  Serial.println(yValue);
  Tomato(xValue, yValue);
}

int Tomato(int xValue, int yValue) {

  // X negative
  if (xValue <= 480) {
    animationSpeed = 100;
    digitalWrite(2, HIGH);
    delay(animationSpeed); // Wait for animationSpeed millisecond(s)
    digitalWrite(2, LOW);
    delay(animationSpeed);

    digitalWrite(3, HIGH);
    delay(animationSpeed); // Wait for animationSpeed millisecond(s)
    digitalWrite(3, LOW);
    delay(animationSpeed);

    digitalWrite(5, HIGH);
    delay(animationSpeed); // Wait for animationSpeed millisecond(s)
    digitalWrite(5, LOW);
    delay(animationSpeed);
  }

  // X positive
  else if (xValue >= 530) {
    animationSpeed = 100;
    digitalWrite(4, HIGH);
    delay(animationSpeed); // Wait for animationSpeed millisecond(s)
    digitalWrite(4, LOW);
    delay(animationSpeed);

    digitalWrite(5, HIGH);
    delay(animationSpeed); // Wait for animationSpeed millisecond(s)
    digitalWrite(5, LOW);
    delay(animationSpeed);

    digitalWrite(2, HIGH);
    delay(animationSpeed); // Wait for animationSpeed millisecond(s)
    digitalWrite(2, LOW);
    delay(animationSpeed);
  }

  //Y negative
  else if (yValue <= 480) {
    animationSpeed = 100;
    digitalWrite(1, HIGH);
    delay(animationSpeed); // Wait for animationSpeed millisecond(s)
    digitalWrite(1, LOW);
    delay(animationSpeed);

    digitalWrite(6, HIGH);
    delay(animationSpeed); // Wait for animationSpeed millisecond(s)
    digitalWrite(6, LOW);
    delay(animationSpeed);

    digitalWrite(3, HIGH);
    delay(animationSpeed); // Wait for animationSpeed millisecond(s)
    digitalWrite(3, LOW);
    delay(animationSpeed);
  }

  else if (yValue >= 530) {
    animationSpeed = 100;
    digitalWrite(3, HIGH);
    delay(animationSpeed); // Wait for animationSpeed millisecond(s)
    digitalWrite(3, LOW);
    delay(animationSpeed);

    digitalWrite(5, HIGH);
    delay(animationSpeed); // Wait for animationSpeed millisecond(s)
    digitalWrite(5, LOW);
    delay(animationSpeed);

    digitalWrite(4, HIGH);
    delay(animationSpeed); // Wait for animationSpeed millisecond(s)
    digitalWrite(4, LOW);
    delay(animationSpeed);
  }
  else if (xValue <= -530 && xValue >= 530 && yValue <= -530 && yValue >= 530) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    
  }
  //
  //  else if(xValue <=-10 && xValue >= 10 && yValue <=-10 && yValue >= 10){
  //  digitalWrite(2, HIGH);
  //  delay(animationSpeed); // Wait for animationSpeed millisecond(s)
  //  digitalWrite(2, LOW);
  //  delay(animationSpeed);
  //
  //  digitalWrite(3, HIGH);
  //  delay(animationSpeed); // Wait for animationSpeed millisecond(s)
  //  digitalWrite(3, LOW);
  //  delay(animationSpeed);
  //
  //  digitalWrite(4, HIGH);
  //  delay(animationSpeed); // Wait for animationSpeed millisecond(s)
  //  digitalWrite(4, LOW);
  //  delay(animationSpeed);
  //
  //  digitalWrite(5, HIGH);
  //  delay(animationSpeed); // Wait for animationSpeed millisecond(s)
  //  digitalWrite(5, LOW);
  //  delay(animationSpeed);
  //
  //  digitalWrite(6, HIGH);
  //  delay(animationSpeed); // Wait for animationSpeed millisecond(s)
  //  digitalWrite(6, LOW);
  //  delay(animationSpeed);
  //  }
}
