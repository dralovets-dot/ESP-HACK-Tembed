// НАСТРОЙКИ ДЛЯ LILYGO T-EMBED CC1101
#define CC1101_GDO0  21  // GDO0 на CC1101
#define CC1101_GDO2  10  // GDO2 на CC1101  
#define CC1101_SS    12  // CS на CC1101 (обычно SS)
#define CC1101_MOSI  11  // MOSI
#define CC1101_MISO  13  // MISO  
#define CC1101_SCK   14  // SCK

// Пины дисплея ST7789 (T-Embed)
#define TFT_MOSI  6
#define TFT_SCLK  5
#define TFT_CS    7
#define TFT_DC    4
#define TFT_RST   8
#define TFT_BL    9   // Подсветка

// Пины энкодера и кнопок
#define BUTTON_ENCODER 0  // Центральная кнопка (BOOT)
#define PIN_ENCODER_A  2  // Энкодер A
#define PIN_ENCODER_B  1  // Энкодер B

// Подключаем библиотеки
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>
#include <GyverButton.h>
#include <IRremoteESP8266.h>
#include <ELECHOUSE_CC1101_SRC_DRV.h>
#include <RCSwitch.h>
#include <NimBLEDevice.h>
#include <RF24.h>

// Объекты для работы с периферией
// Дисплей (укажи правильный адрес если нужно)
Adafruit_SH1106G display(128, 64, &Wire, -1);

// CC1101 через SPI
SPIClass spiCC1101(HSPI);

// Кнопка энкодера
GButton encoderBtn(BUTTON_ENCODER, LOW_PULL);

// ==================== ТВОЙ КОД НИЖЕ ====================

void setup() {
  Serial.begin(115200);
  
  // Инициализация SPI для CC1101
  spiCC1101.begin(CC1101_SCK, CC1101_MISO, CC1101_MOSI, CC1101_SS);
  pinMode(CC1101_SS, OUTPUT);
  
  // Инициализация дисплея (пример)
  if(!display.begin(0x3C, OLED_RESET)) {
    Serial.println(F("SH110x allocation failed"));
    for(;;);
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SH110X_WHITE);
  display.setCursor(0,0);
  display.println(F("ESP-HACK T-Embed"));
  display.display();
  
  // Инициализация CC1101 (пример)
  ELECHOUSE_cc1101.Init();
  ELECHOUSE_cc1101.setMHZ(433.92);
  
  Serial.println("Setup complete");
}

void loop() {
  // Твой основной код здесь
  
  encoderBtn.tick();  // Обработка кнопки
  
  delay(10);
}
