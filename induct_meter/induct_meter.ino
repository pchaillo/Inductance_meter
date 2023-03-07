

/*Thanks. Remember to visit my Youtube channel
  If you don't whant to Serial print the valeus just delete the serial. print lines
  and leave just the LCD print ones.
  I've used a i2c LCD screen module. 
*/
//LCD config
#include <Wire.h>
// #include <LiquidCrystal_I2C.h>
// LiquidCrystal_I2C lcd(0x3f,20,4);  //sometimes the adress is not 0x3f. Change to 0x27 if it dosn't work.

//13 is the input to the circuit (connects to 150ohm resistor), 11 is the comparator/op-amp output.
double pulse, frequency, capacitance, inductance;
void setup(){ 
 // lcd.init();
 // lcd.backlight();
  Serial.begin(115200);
  pinMode(11, INPUT);
  pinMode(13, OUTPUT);
  Serial.println("Why hello!");
  delay(200);
}

void loop(){
  digitalWrite(13, HIGH);
  delay(20);//give some time to charge inductor.
  digitalWrite(13,LOW);
  delayMicroseconds(100); //make sure resination is measured
  pulse = pulseIn(11,HIGH,5000);//returns 0 if timeout

  // Serial.println( pulse );
  if(pulse > 0.1){ //if a timeout did not occur and it took a reading:
    
    
//  #error insert your used capacitance value here. Currently using 2uF. Delete this line after that
  capacitance = 2.E-6; // - insert value here
  
  
  frequency = 1.E6/(2*pulse);
  inductance = 1./(capacitance*frequency*frequency*4.*3.14159*3.14159);//one of my profs told me just do squares like this
  inductance *= 1E6; //note that this is the same as saying inductance = inductance*1E6

  //Serial print
  Serial.print("High for uS:");
  Serial.print( pulse );
  Serial.print("\tfrequency Hz:");
  Serial.print( frequency );
  Serial.print("\tinductance uH:");
  Serial.println( inductance );
  delay(10);

/*
  //LCD print
  lcd.clear();
  lcd.setCursor(0,0); 
  lcd.print("Inductance:");
  lcd.setCursor(0,1); 
  lcd.print(inductance);
  lcd.setCursor(14,1); 
  lcd.print("uH");          
  delay(10); */
  }
}


 
