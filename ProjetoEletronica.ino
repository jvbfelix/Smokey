const int botao = 5;
const int temperatura1 = 6;
const int temperatura2 = 7;
const int temperatura3 = 8;
const int gas1 = 9;
const int gas2 = 10;
const int gas3 = 11;

const int alarme1 = 2;
const int alarme2 = 3;
const int alarme3 = 4;
const int ledVermelho = 0;
const int ledAmarelo = 1;
const int ledVerde = 12;
const int ledAzul = 13;

void stopAlarm(){
  digitalWrite(alarme1, LOW);
  digitalWrite(alarme2, LOW);
  digitalWrite(alarme3, LOW);

  digitalWrite(ledVermelho, LOW);
  digitalWrite(ledAmarelo, LOW);
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledAzul, LOW);
}

void changeAlarm(int temp, int gas){
  if(temp == 1 || gas == 1){
    // NIVEL 1
    digitalWrite(alarme1, LOW);
    digitalWrite(alarme2, LOW);
    digitalWrite(alarme3, LOW);

    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledAzul, LOW);
  } else if((temp > 1  && temp < 4) || (gas > 1  && gas < 4)){
    // NIVEL 2
    digitalWrite(alarme1, LOW);
    digitalWrite(alarme2, LOW);
    digitalWrite(alarme3, LOW);

    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledAzul, LOW);
  } else if((temp > 3  && temp < 6) || (gas > 3  && gas < 6)){
    // NIVEL 3
    digitalWrite(alarme1, HIGH);
    digitalWrite(alarme2, LOW);
    digitalWrite(alarme3, HIGH);

    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAzul, LOW);
  } else if((temp > 5  && temp < 8) || (gas > 5  && gas < 8)){
    // NIVEK 4
    digitalWrite(alarme1, HIGH);
    digitalWrite(alarme2, HIGH);
    digitalWrite(alarme3, HIGH);

    digitalWrite(ledVermelho, HIGH);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAzul, LOW);
  } else {
    stopAlarm();
  }
}

int bitConversor(int bit0, int bit1, int bit2){
  return (bit2 * 4) + (bit1 *2) + bit0;
}

void setup() {
  pinMode(alarme1, OUTPUT);
  pinMode(alarme2, OUTPUT);
  pinMode(alarme3, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAzul, OUTPUT);
  pinMode(botao, INPUT);
  pinMode(temperatura1, INPUT);
  pinMode(temperatura2, INPUT);
  pinMode(temperatura3, INPUT);
  pinMode(gas1, INPUT);
  pinMode(gas2, INPUT);
  pinMode(gas3, INPUT);

  stopAlarm();
}

void loop() {
  const int bntPress = digitalRead(botao);
  if (bntPress) {
    stopAlarm();
    delay(1000);
  }

  const int tempBit1 = digitalRead(temperatura1);
  const int tempBit2 = digitalRead(temperatura2);
  const int tempBit3 = digitalRead(temperatura3);

  const int temperatura = bitConversor(tempBit1, tempBit2, tempBit3);

  const int gasBit1 = digitalRead(gas1);
  const int gasBit2 = digitalRead(gas2);
  const int gasBit3 = digitalRead(gas3);

  const int fumaca = bitConversor(gasBit3, gasBit2, gasBit1);

  changeAlarm(temperatura, fumaca);
}
