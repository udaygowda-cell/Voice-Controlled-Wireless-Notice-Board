#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>
#include <SPI.h>
#include <DMD.h>
#include <TimerOne.h>
#include "Arial_black_16.h"
#include "SystemFont5x7.h"

#define ROW 2
#define COLUMN 1
#define FONT Arial_Black_16

DMD dmd(ROW, COLUMN);
LiquidCrystal_I2C lcd(0x27, 20, 4);
SoftwareSerial mySerial(2, 3); // RX, TX (Arduino RX=3, TX=2)

String val = "NOTICE BOARD";
String oldval = "";
String newval = "NOTICE BOARD";
int i = 0;

void ScanDMD() {
  dmd.scanDisplayBySPI();
}

void scrollText(String dispString) {
  dmd.clearScreen(true);
  dmd.selectFont(FONT);

  char newString[256];
  int sLength = dispString.length();
  dispString.toCharArray(newString, sLength + 1);

  dmd.drawMarquee(newString, sLength, (32 * ROW) - 1, 0);

  long start = millis();
  long timer = start;
  boolean ret = false;

  while (!ret) {
    if ((timer + 20) < millis()) {
      ret = dmd.stepMarquee(-1, 0);
      timer = millis();
      delay(30);
    }
  }
}

void setup() {
  Timer1.initialize(1000);
  Timer1.attachInterrupt(ScanDMD);
  dmd.clearScreen(true);

  lcd.init();
  lcd.backlight();

  mySerial.begin(9600);
  Serial.begin(9600);

  lcd.setCursor(0, 0);
  lcd.print("WIRELESS NOTICE");
  lcd.setCursor(0, 1);
  lcd.print("     BOARD     ");
  delay(3000);
  lcd.clear();
  lcd.print("Welcome!");

  dmd.selectFont(FONT);
  scrollText("WIRELESS NOTICE BOARD");
  scrollText("WELCOME!");
}

void loop() {
  val = mySerial.readString();
  val.trim();

  if (val.length() > 0 && val != oldval) {
    newval = val;
  }

  lcd.clear();
  lcd.setCursor(i, 0);
  lcd.print(newval);

  scrollText(newval);

  i++;
  if (i >= 15) i = 0;

  oldval = newval;
}
