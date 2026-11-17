#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16x2 LCD (sometimes it's 0x3F)
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();              // Initialize the LCD
  lcd.backlight();         // Turn on the backlight
  lcd.setCursor(0, 0);     // Set cursor to column 0, row 0
  lcd.print("Atharv Rajpoot"); // Print your message
}

void loop() {
  // Nothing needed here, text stays on display
}
