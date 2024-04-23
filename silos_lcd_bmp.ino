#include <Wire.h>
#include <Adafruit_BMP085.h>
#include <LiquidCrystal_I2C.h>

//I2C pins declaration
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); 
#define seaLevelPressure_hPa 1013.25

Adafruit_BMP085 bmp;

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);//Defining 16 columns and 2 rows of lcd display
  lcd.backlight();//To Power ON the back light
  if (!bmp.begin()) {
  Serial.println("Could not find a valid BMP085 sensor, check wiring!"); 
  }
}

void loop() {
    lcd.setCursor(0,0); //Defining positon to write from first row,first column .
    String temp = String(bmp.readTemperature());
    lcd.print(" Temp: " + temp + char(223) +"C"); //You can write 16 Characters per line .
    Serial.println(" Temp: " + temp + char(223) +"C");
    delay(1000);//Delay used to give a dynamic effect
    lcd.setCursor(0,1);  //Defining positon to write from second row,first column .
    lcd.print("Press: " + String(bmp.readPressure() / 100) + " hPa");
    Serial.println("Pression: " + String(bmp.readPressure() / 100) + "hPa");
    delay(5000);
    lcd.clear();
    lcd.setCursor(0,0); //Defining positon to write from first row,first column .
    char buffer[17];
    sprintf(buffer, "Temp Opt: 13%cC", char(223));
    lcd.print(buffer);
    delay(1000);//Delay used to give a dynamic effect
    lcd.setCursor(0,1);  //Defining positon to write from second row,first column .
    char pressureBuffer[17];
    sprintf(pressureBuffer, "Pres Opt: 1013.25 hPa");
    lcd.print(pressureBuffer);
    Serial.println("Pression: " + String(bmp.readPressure() / 100) + "hPa");
    delay(5000);
}
