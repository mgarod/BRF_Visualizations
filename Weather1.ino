
#include <Wire.h>
#include "RTClib.h"
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <SD.h>

// set up variables using the SD utility library functions:
Sd2Card card;
SdVolume volume;
SdFile root;

//Adafruit SD shield is pin 10:
const int chipSelect = 10;

//other globals
const int ledPin = 3;
int ledState = 1;
String fname = "fileName";


#define BME_SCK 13   //these four needed for i2c too
#define BME_MISO 12
#define BME_MOSI 11
#define BME_CS 10


#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BME280 bme; // I2C
RTC_DS1307 rtc;

void setup() {
  pinMode(ledPin, OUTPUT);
  delay(1000); //just in case
  Serial.begin(9600);

  if (!bme.begin()) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1); //don't start on error
  }
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1); //don't start on error here either
  }
  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    Serial.println("RTC clock set");
  }
  Serial.print("Initializing SD card...");

  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    while (1); //don't start with a failed card
  }
  Serial.println("card initialized.");
  //flash LED if pass all above
  for (int i = 1; i < 7; i++) {
    analogWrite(ledPin, 64 * (i % 2));
    delay(500);
  }

  Serial.println("Exiting setup()");
}


void loop() {

  for (int i = 0; i < 48; i++) {
    DateTime now = rtc.now();
    String fileName = String(now.unixtime() / 100) + ".txt";
    //File dataFile = SD.open(fileName, FILE_WRITE);

    for (int j = 0; j < 6; j++) {

      String data = " ";
      data = data + bme.readTemperature() + " deg C" + ", ";
      data = data + (bme.readPressure() / 100.0F ) + " mBar" + ", ";
      data = data + bme.readHumidity() + "%" + ", ";
      DateTime now = rtc.now();
      data = data + now.unixtime();

      File dataFile = SD.open(fileName, FILE_WRITE);

      //LED on for 2 sec to protect card write
      analogWrite(ledPin, 64);
      delay(2000);

      if (dataFile) {
        dataFile.println(data);
      }
      dataFile.close();
      delay(100);

      //turn off led
      analogWrite(ledPin, 0);
      delay(297900); // SHOULD BE 5 minutes total, 5*1000*60 - (2000+100)
    }
  }
  while (1); // HALT after 24 hours
}


