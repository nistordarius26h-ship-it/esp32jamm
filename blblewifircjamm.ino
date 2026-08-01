#include "RF24.h"
#include <SPI.h>
#include "esp_bt.h"
#include "esp_wifi.h"

// full spectrum channels
byte full_channels[] = {
  1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21,
  22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42,
  43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63,
  64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84,
  85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100
};

const int num_full = sizeof(full_channels) / sizeof(full_channels[0]);

// radios
// hspi: ce = 16, csn = 15
// vspi: ce = 22, csn = 21
RF24 radio1(16, 15);
RF24 radio2(22, 21);

byte ch[2] = {45, 45};

void setup() {
  Serial.begin(115200);
  delay(500);

  Serial.println("starting full spectrum jammer");

  // disable bluetooth and wifi
  esp_bt_controller_deinit();
  esp_wifi_stop();
  esp_wifi_deinit();
  esp_wifi_disconnect();

  // hspi bus
  SPIClass *hspi = new SPIClass(HSPI);
  hspi->begin(14, 12, 13, -1);

  if (radio1.begin(hspi)) {
    Serial.println("radio1 ready");
    configure(radio1, ch[0]);
  } else {
    Serial.println("radio1 failed");
  }

  // vspi bus
  SPIClass *vspi = new SPIClass(VSPI);
  vspi->begin(18, 19, 23, -1);

  if (radio2.begin(vspi)) {
    Serial.println("radio2 ready");
    configure(radio2, ch[1]);
  } else {
    Serial.println("radio2 failed");
  }

  Serial.println("running");
}

void loop() {
  byte new0 = full_channels[random(num_full)];
  byte new1 = full_channels[random(num_full)];

  if (new0 != ch[0]) {
    radio1.setChannel(new0);
    ch[0] = new0;
  }

  if (new1 != ch[1]) {
    radio2.setChannel(new1);
    ch[1] = new1;
  }

  delayMicroseconds(random(60));
}

void configure(RF24& radio, byte channel) {
  radio.setAutoAck(false);
  radio.stopListening();
  radio.setRetries(0, 0);
  radio.setPALevel(RF24_PA_MAX, true);
  radio.setDataRate(RF24_2MBPS);
  radio.setCRCLength(RF24_CRC_DISABLED);
  radio.startConstCarrier(RF24_PA_MAX, channel);
}