  #include <LiquidCrystal.h>
  
  #define PIR_In 2
  #define buzzer_Out 3
  
  LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
  
  void setup() {
  
    pinMode(buzzer_Out, OUTPUT);
    pinMode(PIR_In, INPUT);
    Serial.begin(9600);
    lcd.begin(16, 2);
  
  }
  
  void loop() {
    lcd.setCursor(3,0);
    lcd.print("ALL CLEAR");    
    check_For_Intruder();
  }

  void check_For_Intruder()
  {
    boolean sensorvalue= digitalRead(PIR_In);
    if(sensorvalue==1)
     {
      digitalWrite(buzzer_Out,HIGH);
      lcd.setCursor(0,0);
      lcd.print("Intruder in the ");
      lcd.setCursor(0,1);
      lcd.print("House :( ");
      delay(3000);
      lcd.clear();
     }
else{     
      digitalWrite(buzzer_Out,LOW);        
         }
     delay(10);    
    }
