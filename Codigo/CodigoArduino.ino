# Código do Arduino

```ruby
#include <Servo.h>

//Lembrar de atualizar e mudar os valores das portas de entrada conforme necessário na montagem

//LED RGB
const int red = 10;
const int green = 9;
const int blue = 8;

//Piezo
const int piezo = 2;

//Sensor Ultrassônico
const int sensorTrig = 12;
const int sensorEcho = 11;

//Servo
Servo servo_9;
int pos = 0; //Posição inicial
bool grausAumentando = true; //Direção do movimento do servo

long duracao;
float dist;

unsigned long ultimoMovimento = 0;
const int intervaloMovimento = 15; // milissegundos

void setup() {
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);

  pinMode(piezo, OUTPUT);

  pinMode(sensorTrig, OUTPUT);
  pinMode(sensorEcho, INPUT);

  servo_9.attach(6, 500, 2500); // Pino do servo

  Serial.begin(9600);
}

void loop() {
  //MOVIMENTO DO SERVO
  if (millis() - ultimoMovimento >= intervaloMovimento) {
    if (grausAumentando) {
      pos+=5;
      if (pos >= 180) {
        pos = 180;
        grausAumentando = false;
      }
    } else {
      pos-=5;
      if (pos <= 0) {
        pos = 0;
        grausAumentando = true;
      }
    }
    servo_9.write(pos);
    ultimoMovimento = millis();
  }

  //SENSOR ULTRASSÔNICO
  digitalWrite(sensorTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(sensorTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(sensorTrig, LOW);

  duracao = pulseIn(sensorEcho, HIGH);
  dist = duracao * 0.0343 / 2;

  Serial.print("Distância: ");
  Serial.print(dist);
  Serial.println(" cm");

  //LED + PIEZO
  if (dist > 0 && dist <= 30.0) {
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH);
    digitalWrite(blue, HIGH);
    digitalWrite(piezo, HIGH);
  } else {
    digitalWrite(red, HIGH);
    digitalWrite(green, LOW);
    digitalWrite(blue, HIGH);
    digitalWrite(piezo, LOW);
  }

  delay(100); //Pequeno atraso para estabilizar leituras
}
```
