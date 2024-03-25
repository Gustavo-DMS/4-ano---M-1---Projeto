#define LAzul 13
#define LVermelho 12
#define LVerde 11
#define LAmarelo 10

#define BAzul 7
#define BVermelho 6
#define BVerde 5
#define BAmarelo 4

#include <Adafruit_Sensor.h>
#include <Adafruit_MPU6050.h>
#include <Wire.h>

int estadoAzul = 0;
int estadoVermelho = 0;
int estadoVerde = 0;
int estadoAmarelo = 0;

int filtro = 0;

// Adafruit_MPU6050 mpu;

// void acelorometro(){
//   sensors_event_t a, g, temp;
//   mpu.getEvent(&a, &g, &temp);
//
//   /* Print out the values */
//   Serial.print("Acceleration X: ");
//   Serial.print(a.acceleration.x);
//   Serial.print(", Y: ");
//   Serial.print(a.acceleration.y);
//   Serial.print(", Z: ");
//   Serial.print(a.acceleration.z);
//   Serial.println(" m/s^2");
//
//   Serial.print("Rotation X: ");
//   Serial.print(g.gyro.x);
//   Serial.print(", Y: ");
//   Serial.print(g.gyro.y);
//   Serial.print(", Z: ");
//   Serial.print(g.gyro.z);
//   Serial.println(" rad/s");
//
//   Serial.print("Temperature: ");
//   Serial.print(temp.temperature);
//   Serial.println(" degC");
// }

void verificaBotao(int botao) {
  char nomeBotao[10];
  switch (botao) {
    case BAzul:
      strcpy(nomeBotao, "BAzul");
      break;
    case BVermelho:
      strcpy(nomeBotao, "BVermelho");
      break;
    case BVerde:
      strcpy(nomeBotao, "BVerde");
      break;
    case BAmarelo:
      strcpy(nomeBotao, "BAmarelo");
      break;
  }
  if (digitalRead(botao) == HIGH) {
    filtro++;
    if (filtro > 10) {
      Serial1.write(nomeBotao);
    }
  } else {
    filtro = 0;
  }
}

void setup() {
  Serial.begin(9600);
  Serial1.begin(38400);

  pinMode(BAzul, INPUT);
  pinMode(BVermelho, INPUT);
  pinMode(BVerde, INPUT);
  pinMode(BAmarelo, INPUT);

  pinMode(LAzul, OUTPUT);
  pinMode(LVermelho, OUTPUT);
  pinMode(LVerde, OUTPUT);
  pinMode(LAmarelo, OUTPUT);

  // if (!mpu.begin()) {
  //   Serial.println("Failed to find MPU6050 chip");
  //   while (1) {
  //     delay(10);
  //   }
  // }
  // Serial.println("MPU6050 Found!");
}

void loop() {
  //inicializacao do bluetooth
  if (Serial1.available() > 0) {
    String receber = Serial1.readString();
    Serial.println(receber);
    if (receber == "LAzul") {
      estadoAzul = !estadoAzul;
      digitalWrite(LAzul, estadoAzul);
    }
    if (receber == "LVermelho") {
      estadoVermelho = !estadoVermelho;
      digitalWrite(LVermelho, estadoVermelho);
    }
    if (receber == "LVerde") {
      estadoVerde = !estadoVerde;
      digitalWrite(LVerde, estadoVerde);
    }
    if (receber == "LAmarelo") {
      estadoAmarelo = !estadoAmarelo;
      digitalWrite(LVerde, estadoAmarelo);
    }

    //Verifica se os botoes foram pressionados
    verificaBotao(BAzul);
    verificaBotao(BVermelho);
    verificaBotao(BVerde);
    verificaBotao(BAmarelo);
  }

  if (Serial.available() > 0) {
    Serial1.write(Serial.read());
  }
}
