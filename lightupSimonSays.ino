
#define joyX A0
#define joyY A1
int rand();
//everything online said dont use arraylist due to memory limitations
//premade arraylist
int myArray[100] = {};

//player array
int playerArray[100] {};

//delay speed
int animationSpeed = 300;

//booleans dont seem to work
String pause = "false";

//check if the pattern has been shown
String patternDone="n";

//iterate the player array
int it = 1;

//cycle = number of time play loop has been done
//+1 when compare is run
int cycle=1;

//joystick valuese
int SWpin = 10;
int Xpin = 0;
int Ypin = 1;
int xValue = 0;
int yValue = 0;


//generate random #s between 1-4
int rando() {
  int result = ((rand() % 4) + 1);
  return result;
}

//uses the rando function to populate the array with random #'s up to 100 values
void arrayFill() {

  for (int i = 0; i < 100; i++) {
    myArray[i] = rando();
  }
}

//print player array TESTING PURPOSES
void playerPrint() {

  for (int i = 0; i < 100; i++) {
    Serial.print(playerArray[i]);
  }
  Serial.print(pause);
  // put your main code here, to run repeatedly:
  xValue = analogRead(Xpin);
  yValue = analogRead(Ypin);
  Serial.print(xValue);
  Serial.print("\t");
  Serial.println(yValue);
}
//shorten use of colors in rest of program
void red() {
  digitalWrite(6, HIGH);
  pause = "true";
}
void white() {
  digitalWrite(5, HIGH);
  pause = "true";
}
void green() {
  digitalWrite(4, HIGH);
  pause = "true";
}
void gold() {
  digitalWrite(2, HIGH);
  pause = "true";
}
void blue() {
  digitalWrite(3, HIGH);
  pause = "true";
}

//turns all lights off
void off() {
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
}
//////////
//intro//
//////////
void intro() {

  white();
  delay(animationSpeed);
  gold();
  delay(animationSpeed);
  blue();
  delay(animationSpeed);
  green();
  delay(animationSpeed);
  red();
  delay(animationSpeed);
  off();
  delay(animationSpeed);
  white();
  gold();
  blue();
  green();
  red();
  delay(animationSpeed);
  off();
  delay(animationSpeed);
  white();
  gold();
  blue();
  green();
  red();
  delay(animationSpeed);
  off();
}

//////////
//wrong//
//////////
void wrong() {
  red();
  delay(100);
  off();
  delay(100);
  red();
  delay(100);
  off();
  delay(100);
  red();
  delay(100);
  off();
  delay(100);

  //RESET ARRAYS
  //premade arraylist
  myArray[100] = {};
  //player array
  playerArray[100]= {};
  it=0;
  cycle=1;
  arrayFill();

  intro();
  simon();
}
///////////
//compare//
////////////
//compare generated array to player input
void compare() {
  for ( int i = 0; i < cycle; i++) {
    if (playerArray[i] != myArray[i] && playerArray[i] != 0) {
      wrong();
      Serial.println("wrong");
      break;
    }
  }
  //if the # of player inputs == the # of simon cycles then cycle++ and it resets
  if (cycle==it){
    cycle++;
    it=0;
    simon();
    Serial.println("stuck at it/cycle");
    }
}

//makes simon start the pattern
void simon() {
  //it=player's # of entries into the array
  for (int i = 0; i <= it; i++) {
    int beep = myArray[i];

    if (beep == 1) {
      white();
      delay(400);
      off();
    }
    else if (beep == 2) {
      green();
      delay(400);
      off();
    }
    else if (beep == 3) {
      gold();
      delay(400);
      off();
    }
    else if (beep == 4) {
      blue();
      delay(400);
      off();
    }
  }
  pause="true";
}

//tomato TOMATO!
int Tomato(int xValue, int yValue) {
Serial.println("stuck at tomato");
  //neutral position
  playerPrint();
  while (xValue <= 600 && xValue >= 500 && yValue <= 600 && yValue >= 500) {
    off();
    Serial.println("stuck at neutral");

  }

  // X negative
  if (xValue <= 480 && pause == "false") {
    white();
    playerArray[it] = 1;
    it++;
    compare();
    
    playerPrint();
  }

  // X positive
  else if (xValue >= 530 && pause == "false") {
    green();
    playerArray[it] = 2;
    it++;
    compare();
    
    playerPrint();
  }

  //Y negative
  else if (yValue <= 480 && pause == "false") {
    gold();
    playerArray[it] = 3;
    it++;
    compare();
    
    playerPrint();
  }

  //y positive
  else if (yValue >= 530 && pause == "false") {
    blue();
    playerArray[it] = 4;
    it++;
    compare();
    
    playerPrint();
  }
  

}
///////
//setup
///////
void setup() {
  Serial.begin(115200);
  pinMode(SWpin, INPUT);
  digitalWrite(SWpin, HIGH);
  // put your setup code here, to run once:
  //red
  pinMode(6, OUTPUT);
  //white
  pinMode(5, OUTPUT);
  //green
  pinMode(4, OUTPUT);
  //gold
  pinMode(3, OUTPUT);
  //blue
  pinMode(2, OUTPUT);
  arrayFill();
  intro();
}
//////////
//loop///
//////////
void loop() {
  Tomato(xValue, yValue);
  Serial.println("stuck at loop");
}
