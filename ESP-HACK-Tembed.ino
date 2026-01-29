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

// Твой старый код ниже...
; PlatformIO Project Configuration File
;
;   Build options: build flags, source filter
;   Upload options: custom upload port, speed and extra flags
;   Library options: dependencies, extra library storages
;   Advanced options: extra scripting
;
; Please visit documentation for the other options and examples
; https://docs.platformio.org/page/projectconf.html

[env:esp32dev]
platform = espressif32
board = esp32dev
framework = arduino
monitor_speed = 115200
board_build.partitions = huge_app.csv

lib_deps =
    adafruit/Adafruit SH110X@^2.1.13
    gyverlibs/GyverButton@^3.8
    crankyoldgit/IRremoteESP8266@^2.8.6
    lsatan/SmartRC-CC1101-Driver-Lib@^2.5.7
    sui77/rc-switch@^2.6.4
    h2zero/NimBLE-Arduino@^2.3.2
    nrf24/RF24@^1.5.0
    

# 3 to 1 build
extra_scripts = 
    post:build.py