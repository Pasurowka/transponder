#include "Multiplexer.h"

#define Sig 13
#define Numouts 4

int linePins[] = {2, 3, 4, 5};
int numone;
int numtwo;
int numthree;
int numfour;
int num;

Multiplexer m(Sig, Numouts, linePins);

void setup(){
  pinMode(12, OUTPUT);
  Serial.begin(9600);
}

void loop(){
    numone = scan(0, 3, 0);
    numtwo = scan(3, 6, 1);
    numthree = scan(6, 9, 2);
    numfour = scan(9, 12, 3);
    Serial.print(numone);
    Serial.print(numtwo);
    Serial.print(numthree);
    Serial.print(numfour);
    if (m.digitalRead(13) == LOW) {
      Serial.print("  ON");
      digitalWrite(12, HIGH);
    }
    else {
      digitalWrite(12, LOW);
    }
    if (m.digitalRead(14) == LOW) {
      Serial.print("  ALT");
    }   
    if (m.digitalRead(15) == LOW) {
      Serial.print("  IDENT");
    }
    delay(100);
    Serial.println();
}

int scan (int low, int high, int place) {
  num = 0;
  for(int address = low; address < high; address++) {
      bitWrite(num, address-3*place, m.digitalRead(address)); 
  }
  return 7-num;       

}

