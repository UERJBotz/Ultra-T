#include <esp_now.h>
#include <WiFi.h>
#include "DRV8833.h"

DRV8833 motor(19, 18, 23, 4);

typedef struct rc {
  int gatilho;
  int roda;
} rc;

rc pack_rc;

// Variáveis normalizadas
int gatilhoNorm = 0; // -255 até 255
int rodaNorm = 0;    // -127 até 127

void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
  memcpy(&pack_rc, incomingData, sizeof(pack_rc));

  // ---------------------------
  // Normalização do gatilho
  if (pack_rc.gatilho < 1800) {
    // Frente (puxado até ~820)
    gatilhoNorm = map(pack_rc.gatilho, 820, 1800, 255, 0);
  } else if (pack_rc.gatilho > 2300) {
    // Ré (empurrado até ~2970)
    gatilhoNorm = map(pack_rc.gatilho, 2300, 2970, 0, -255);
  } else {
    gatilhoNorm = 0;
  }
  //gatilhoNorm = constrain(gatilhoNorm, -255, 255);

  // ---------------------------
  // Normalização da roda
  if (pack_rc.roda < 1800) {
    // Giro horário (até ~150) → positivo
    rodaNorm = map(pack_rc.roda, 150, 1800, 127, 0);
  } else if (pack_rc.roda > 2300) {
    // Giro anti-horário (até ~4050) → negativo
    rodaNorm = map(pack_rc.roda, 2300, 4050, 0, -127);
  } else {
    rodaNorm = 0;
  }
  //rodaNorm = constrain(rodaNorm, -127, 127);

  // ---------------------------
  // Impressão no Serial
  Serial.print("Bruto -> G: ");
  Serial.print(pack_rc.gatilho);
  Serial.print(" R: ");
  Serial.print(pack_rc.roda);

  Serial.print(" | Normalizado -> G: ");
  Serial.print(gatilhoNorm);
  Serial.print(" R: ");
  Serial.println(rodaNorm);

  int y = map(gatilhoNorm, -280, 180, -1023, 1023);
  int z = map(rodaNorm, -130, 120, -1023, 1023);

  int motorEsq = constrain(z - y, -1023, 1023);
  int motorDir = constrain(-z - y, -1023, 1023);
  // fazer aquilo de zerar o motor
  motor.move(motorEsq, motorDir);

  // Serial.print(" | Motores -> Esquerdo: ");
  // Serial.print(motorEsq);
  // Serial.print(" Direito: ");
  // Serial.println(motorDir);
}

void setup() {
  Serial.begin(115200);
  motor.begin();
  motor.bip(5, 250, 2500);

  WiFi.mode(WIFI_STA);

  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  esp_now_register_recv_cb(esp_now_recv_cb_t(OnDataRecv));
}

void loop() {}
