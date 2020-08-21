//Open Source

#include <Wire.h> 
#include <LiquidCrystal_I2C.h> //INCLUSÃO DE BIBLIOTECA
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE);

int pin = A0;

void setup(){
  lcd.begin (16,2); //SETA A QUANTIDADE DE COLUNAS(16) E O NÚMERO DE LINHAS(2) DO DISPLAY
  lcd.setBacklight(HIGH); //LIGA O BACKLIGHT (LUZ DE FUNDO)
  pinMode(pin,INPUT);
}

void loop()
{
  int val = analogRead(pin);
  lcd.setCursor(0,0);
  lcd.print("VALOR= " + (String)val + "  ");

  if(val >= 525 && val <= 528)
  {
    lcd.setCursor(0,1);
    lcd.print("Nao detectado     ");  // valor de 525 a 528  
  }
  else if (val < 525)
  {
    lcd.setCursor(0,1);
    lcd.print("Orientacao: Norte");    
  }
  else if (val > 528)
  { 
    lcd.setCursor(0,1);
    lcd.print("Orientacao: Sul");       
  }
  delay(200);
}
