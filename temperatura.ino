#include <LiquidCrystal.h>

LiquidCrystal lcd(16,17,23,25,27,29);

#define a -9.5787e-07
#define b 0.0016
#define c -0.8656
#define d 267.2047
double x;
double y;
int temp1;
int i_temp=0;



void setup() {
  lcd.begin(20,4);   // rozmiar wyswietlacza 20x4

  pinMode(10,OUTPUT);
}


void loop() {
  
  temp1=analogRead(13);
  x = (double)temp1;
  y=a*x*x*x + b*x*x + c*x + d;
  lcd.setCursor(0,0);
  lcd.print("siema siema");
  lcd.setCursor(0,1);  //pozycja na ktorą ma sie ustawic do cholery
  lcd.print("temperatura: ");
  lcd.print(y);


 
 if(y<80)
  {
    digitalWrite(10,1); //grzała ON
  }
  else if(y>100)
    {
      digitalWrite(10,0); //grzała OFF
    }
  
  delay(100);
  

  
}
