#include <Servo.h>

Servo myservo;
Servo sokkaServo;


int pos = 0;    // variable to store the servo position
int sekunnit = 0;

void setup() {
  myservo.attach(8);  // attaches the servo on pin 9 to the servo object
  sokkaServo.attach(10);


  myservo.write(90);
  Serial.begin(115200);
  Serial.println("ALOITETAAN ODOTTELU");
  myservo.write(90);
  sokkaServo.write(100);

  delay(3000);
  pinMode(5, INPUT);
  digitalWrite(5, INPUT_PULLUP); //activate arduino internal pull up
  delay(20000);
}


void vedaSokkaKiinni() {
  Serial.println("VEDETAAN SOKKA KIINNI");
  sokkaServo.write(180);
  delay(2000);
  sokkaServo.write(90);
}

void vedaSokkaAuki() {
  Serial.println("VEDETAAN SOKKA AUKI");
  sokkaServo.write(0);
  delay(2000);
  sokkaServo.write(90);
}

void pysaytaVinssi() {
  Serial.println("VINSSI PYSAYTETTY " + sekunnit);
  myservo.write(90);
  delay(2000);
}



void loop() {
  while (1 == 1) {
    int i = 0;
    for (i = 0; i < 30; i++) {
      myservo.write(90);
      delay(400);
      myservo.write(60);
      delay(400);
      Serial.println("KOHTA 60 ASTETTA YLOS");
    }
    myservo.write(90);

    Servo varaServo;
    Servo palauttajaServo;
    varaServo.attach(7);
    

    for (pos = 0; pos <= 180; pos += 1) { // goes from 180 degrees to 0 degrees
      myservo.write(90);
      varaServo.write(pos);              // tell servo to go to position in variable 'pos'
      Serial.println("VARASERVO LIIKKUU");
      delay(15);                       // waits 15ms for the servo to reach the position
    }
    myservo.write(90);
    varaServo.detach();
    myservo.write(90);
    palauttajaServo.attach(A0);
    myservo.write(90);
    for (pos = 0; pos <= 180; pos += 1) { // goes from 180 degrees to 0 degrees
      myservo.write(90);
      palauttajaServo.write(pos);              // tell servo to go to position in variable 'pos'
      Serial.println("VARASERVO LIIKKUU");
      myservo.write(90);
      delay(15);                       // waits 15ms for the servo to reach the position
    }
    palauttajaServo.detach();

    for (i = 0; i < 35; i++) {
      myservo.write(140);
      delay(400);
      myservo.write(90);
      delay(400);
      Serial.println("KOHTA 140 ASTETTA ALAS");
    }


    Serial.println("VEDETAAN SOKKA AUKI");
    delay(2000);
    sokkaServo.write(0);
    delay(2000);
    sokkaServo.write(90);
    delay(2000);
    Serial.println("ANNETAAN LOYSAT");
    sokkaServo.write(180);
    delay(2000);
    sokkaServo.write(90);
  }
  Serial.println("Aletaan kelata sisaan.");

  vedaSokkaAuki();
}
