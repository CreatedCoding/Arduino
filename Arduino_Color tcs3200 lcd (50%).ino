#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);
 
const int s0 = 2;  
const int s1 = 3;  
const int s2 = 4;  
const int s3 = 5;  
const int out = 6;    
int red = 0;  
int green = 0;  
int blue = 0;  
    
void setup()   
{  
  lcd.begin(20, 4);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print(">> Penelitian S2");
  lcd.setCursor(0, 1);
  lcd.print(">> Alat Pendeteksi");
  lcd.setCursor(0, 2);
  lcd.print(">> Bryan.Ruhulessin");
  lcd.setCursor(0, 3);
  lcd.print(">> Stimik Handayani");
  delay(4000);
  lcd.clear();
  Serial.begin(9600); 
  pinMode(s0, OUTPUT);  
  pinMode(s1, OUTPUT);  
  pinMode(s2, OUTPUT);  
  pinMode(s3, OUTPUT);  
  pinMode(out, INPUT);   
  digitalWrite(s0, HIGH);  
  digitalWrite(s1, LOW); 
  lcd.setCursor(0, 2);
  lcd.print("Terdeteksi");
  lcd.setCursor(0,0);
  lcd.print("   Pembacaan Warna  ");  
}  
    
void loop() 
{  
  color();    
  lcd.setCursor(0, 2);
  lcd.print("Terdeteksi");
  lcd.setCursor(0,0);
  lcd.print("   Pembacaan Warna  ");
  lcd.setCursor(0,1);
  lcd.print("R: ");  
  lcd.print(red,DEC);
  lcd.print("     "); 
  lcd.setCursor(7,1); 
  lcd.print("G: ");  
  lcd.print(green,DEC); 
  lcd.print("     "); 
  lcd.setCursor(14,1); 
  lcd.print("B: ");  
  lcd.print(blue,DEC);
  lcd.print("     ");   
  
      
  if (red > 25 && red < 50 && green >95 && green < 135 && blue > 64 && blue < 90)
  {  
    lcd.setCursor(0, 3);
    lcd.print("  >> Warna Merah <<  ");
    lcd.print("                     ");    
  }  
  else if (blue > 38 && blue < 69 && red > 120 && red < 180 && green > 89 && green < 141 )   
  { 
    lcd.setCursor(0, 3);
    lcd.print("  >> Warna Biru <<  "); 
    lcd.print("                    ");    
  }  
  else if (red > 42 && red < 71 && green >39 && green < 130 && blue > 48 && blue < 91)  
  { 
    lcd.setCursor(0, 3);
    lcd.print("  >> Warna Hijau << "); 
    lcd.print("                    ");     
  }  
  else if (red>9 && red<29 && green >14 && green <45 && blue >14 && blue <46 ) 
  {
    lcd.setCursor(0, 3);
    lcd.print(" >> Warna Kuning << "); 
    lcd.print("                    "); 
  } 
  else{
    delay(100);
    lcd.clear();  
  }  
  lcd.setCursor(0, 2);
  lcd.print("Terdeteksi : ");
  lcd.setCursor(0,0);
  lcd.print("   Pembacaan Warna  ");  
  lcd.setCursor(0,1);
  lcd.print("R: ");  
  lcd.print(red, DEC); 
  lcd.setCursor(7,1); 
  lcd.print("G: ");  
  lcd.print(green, DEC); 
  lcd.setCursor(14,1); 
  lcd.print("B: ");  
  lcd.print(blue, DEC);   
  delay(800);   
 }  
    
void color()  
{    
  digitalWrite(s2, LOW);  
  digitalWrite(s3, LOW);  
  //count OUT, pRed, RED  
  red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s3, HIGH);  
  //count OUT, pBLUE, BLUE  
  blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s2, HIGH);  
  //count OUT, pGreen, GREEN  
  green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);   
}
