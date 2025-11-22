#include <esp_now.h>
#include <WiFi.h>

uint8_t broadcastAddress1[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
//A0:B7:65:4A:4D:60
//F4:65:0B:48:03:8C
//60:55:f9:9f:a5:7c

typedef struct tx {
  int gatilho;
  int roda;
} tx;

tx pack_tx;

esp_now_peer_info_t peerInfo;

// callback when data is sent
void OnDataSent(const wifi_tx_info_t* info, esp_now_send_status_t status) {
  char macStr[18];
  Serial.print("Packet to: ");
  // Copies the sender mac address to a string
  snprintf(macStr, sizeof(macStr), "%02x:%02x:%02x:%02x:%02x:%02x",
           info->src_addr[0], info->src_addr[1], info->src_addr[2],
           info->src_addr[3], info->src_addr[4], info->src_addr[5]);
  Serial.print(macStr);
  Serial.print(" send status:\t");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}
 
void setup() {
  Serial.begin(115200);
  pinMode(3, INPUT);
  pinMode(1, INPUT);
  WiFi.mode(WIFI_STA);
 
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  
  esp_now_register_send_cb(OnDataSent);
   
  // register peer
  peerInfo.channel = 0;  
  peerInfo.encrypt = false;
  // register first peer  
  memcpy(peerInfo.peer_addr, broadcastAddress1, 6);
  if (esp_now_add_peer(&peerInfo) != ESP_OK){
    Serial.println("Failed to add peer");
    return;
  }
  // // register second peer  
  // memcpy(peerInfo.peer_addr, broadcastAddress2, 6);
  // if (esp_now_add_peer(&peerInfo) != ESP_OK){
  //   Serial.println("Failed to add peer");
  //   return;
  // }
  // /// register third peer
  // memcpy(peerInfo.peer_addr, broadcastAddress3, 6);
  // if (esp_now_add_peer(&peerInfo) != ESP_OK){
  //   Serial.println("Failed to add peer");
  //   return;
  // }
}
 
void loop() {
  pack_tx.gatilho = analogRead(3);
  pack_tx.roda    = analogRead(1);
  
  esp_err_t result = esp_now_send(broadcastAddress1, (uint8_t *) &pack_tx, sizeof(tx));
   
  if (result == ESP_OK) {
    Serial.println("Sent with success");
  }
  else {
    Serial.println("Error sending the data");
  }
  delay(1);
}