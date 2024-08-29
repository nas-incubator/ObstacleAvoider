// Define motor pins
int motorLeftBackward = 1;
int motorLeftForward = 2;

int motorRightBackward = 3;
int motorRightForward = 4;

// Define sensor pins
#define RIGHT_SENSOR 8
#define LEFT_SENSOR 9 //it moves opposite

void setup() {
  // Set motor pins as output
  pinMode(motorLeftBackward, OUTPUT);
  pinMode(motorLeftForward, OUTPUT);
  pinMode(motorRightBackward, OUTPUT);
  pinMode(motorRightForward, OUTPUT);
//Speed Control
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  
  // Set sensor pins as input
  pinMode(LEFT_SENSOR, INPUT);
  pinMode(RIGHT_SENSOR, INPUT);
}

void loop() {

  analogWrite(6,110); //right motor rpm
  analogWrite(5,100); //left motor rpm
  
  // Read sensor values
  int leftSensorValue = digitalRead(LEFT_SENSOR);
  int rightSensorValue = digitalRead(RIGHT_SENSOR);
  
  // Determine motor actions based on sensor values
  if (leftSensorValue == LOW && rightSensorValue == LOW) {
    
    moveForward(); // Move forward
  } else {
    
    turn(); // turns
  }
}

void moveForward() {
  delay(300);
  digitalWrite(motorLeftBackward, LOW);
  digitalWrite(motorLeftForward, HIGH);
  digitalWrite(motorRightBackward, LOW);
  digitalWrite(motorRightForward, HIGH);
  
}

void moveBackward()
{
  digitalWrite(motorLeftBackward, HIGH); //move Backward
  digitalWrite(motorLeftForward, LOW);
  digitalWrite(motorRightBackward, HIGH);
  digitalWrite(motorRightForward, LOW);
}

void turn() {
  moveBackward();
  //int randomNumber = random(2);
  delay(1000);
  digitalWrite(motorLeftBackward, LOW);  //Turn Left 
  digitalWrite(motorLeftForward, HIGH);
  digitalWrite(motorRightBackward, LOW);
  digitalWrite(motorRightForward, LOW); 
  delay(500);
  moveForward();
}





