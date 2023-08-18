

#include <Servo.h>

Servo myservo;
Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
int sekunnit = 0;

void setup() {
  myservo1.attach(0);
  myservo2.attach(2);
  myservo3.attach(7);
  myservo4.attach(10);
  myservo1.write(0);
  myservo2.write(0);
  myservo3.write(0);
  myservo4.write(0);
   
  delay(3000);
  pinMode(5, INPUT);
  digitalWrite(5, INPUT_PULLUP); //activate arduino internal pull up

  myservo.attach(8);  // attaches the servo on pin 9 to the servo object
  // ajetaan vinssin kytkenta off asentoon
  myservo.write(90);
  Serial.begin(115200);
  Serial.println("ALOITETAAN ODOTTELU");

  delay(20000);
}

void kelaaSisaan() {
  while (digitalRead(5) != LOW) {

    Serial.println("KELATAAN SISAAN JA SEKUNNIT ON " + sekunnit);
    delay(500);
    myservo.write(60);
    delay(500);
    myservo.write(90);
    delay(500);
  }

  Serial.println("Button is pressed");
  int alasLaskuLaskuri = 0;

  delay(1000);
  Serial.println("TURVAKYTKIN LAUKAISTU! 1");
  while (alasLaskuLaskuri < 5) {
    kelaaAlas();
    kelaaAlas();
    kelaaAlas();
    kelaaAlas();
    delay(1000);
    alasLaskuLaskuri++;
  }


  while (1 == 1) {
    Serial.println("JUKAN OHJELMA LOPETETTU!!");
    pysaytaVinssi();
  }

}

void kelaaAlas() {
  int laskuri = 0;
  while (laskuri < 5) {
    Serial.println("KELATAAN ULOS JA SEKUNNIT ON " + sekunnit);
    delay(3500);
    myservo.write(140);
    delay(3500);
    myservo.write(90);
    delay(3500);

    laskuri++;
  }
  if (laskuri >= 3) {
    exit(0);
    while (1 == 1) {
      pysaytaVinssi();
      Serial.println("OLLAAN LOPETTU OHJELMA");
    }
  }

}

void pysaytaVinssi() {
  Serial.println("VINSSI PYSAYTETTY " + sekunnit);
  myservo.write(90);
  delay(2000);
}

void loop() {
  if (digitalRead(5) == LOW) {
    Serial.println("Button is pressed");
    int alasLaskuLaskuri = 0;
    delay(1000);
    Serial.println("TURVAKYTKIN LAUKAISTU 77!");
    kelaaAlas();

    delay(1000);

    pysaytaVinssi();
    Serial.println("OLLAAN LOPETTU OHJELMA");
    exit(0);
    while (1 == 1) {
      Serial.println("OLLAAN LOPETTU OHJELMA");
      pysaytaVinssi();
    }


  }

  //kelaaUlos();
  //kelaaUlos();
  //pysaytaVinssi();
  pysaytaVinssi();
  if (sekunnit < 13) {
    if (digitalRead(5) == LOW) { // nappain painettu vai ei
      Serial.println("Button is pressed");
      int alasLaskuLaskuri = 0;
      while (1 == 1) {
        delay(1000);
        Serial.println("TURVAKYTKIN LAUKAISTU! 2");
        while (alasLaskuLaskuri < 5) {
          kelaaAlas();
          kelaaAlas();
          kelaaAlas();
          delay(1000);
          alasLaskuLaskuri++;
        }
      }
    }

    kelaaSisaan();
  } else {
    kelaaAlas();
  }
  sekunnit++;
  pysaytaVinssi();
  if (sekunnit > 13) {
    if (sekunnit < 15) {
      kelaaAlas();
      sekunnit++;
    }
    pysaytaVinssi();
    Serial.println("OLLAAN LOPETTU OHJELMA");
    exit(0);
    while (1 == 1) {
      Serial.println("OLLAAN LOPETTU OHJELMA");
      pysaytaVinssi();
    }
  }

  //kelaaUlos();

  /*
    for (pos = 60; pos <= 140; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
    }
    for (pos = 140; pos >= 60; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
    }
  */
}
