/*
 --- Social Distancing Device ---
        
 This source code is 
 created in: March 2022
 written by: Htut Myat Oo 
*/

//For leds
int red_led    = 3;
int blue_led   = 2;
int green_led  = A1; //only one analog pin

//For Buzzer
int buzzer = 13;

//For PIR sensor
int PIR     = 12;
int PIRvalue= 0;

//For Front Ultrasonic (1)
int trigger = 5; 
int echo    = 4;
float distance, duration;

//For Right Ultrasonic (2)
int trigger2 = 11;
int echo2    = 10;
float distance2, duration2;

//For Back Ultrasonic (3)
int trigger3 = 7;
int echo3    = 6;
float distance3, duration3;

//For Left Ultrasonic (4)
int trigger4 = 9;
int echo4    = 8;
float distance4, duration4;

void setup() {
  
  //for leds
  pinMode(red_led, OUTPUT);
  pinMode(blue_led, OUTPUT);
  pinMode(green_led, OUTPUT);
  
  //for buzzer
  pinMode(buzzer, OUTPUT);
  
  //for PIR sensor
  pinMode(PIR, INPUT);
  
  //for ultrasonic sensors
  pinMode(trigger, OUTPUT);                     //front ultrasonic sensor
  pinMode(echo, INPUT);                         //front ultrasonic sensor
  pinMode(trigger2, OUTPUT);                    //right ultrasonic sensor
  pinMode(echo2, INPUT);                        //right ultrasonic sensor 
  pinMode(trigger3, OUTPUT);                    //back ultrasonic sensor
  pinMode(echo3, INPUT);                        //back ultrasonic sensor
  pinMode(trigger4, OUTPUT);                    //left ultrasonic sensor
  pinMode(echo4, INPUT);                        //left ultrasonic sensor
  
  Serial.begin(115200);
}

void loop() {
  
  PIRvalue = digitalRead(PIR);                  //Get PIR data value
  //Serial.println((String)"PIR Value: "+PIRvalue);
  delay(2000);

  // initialize the conditions of PIR sensor:
  if(PIRvalue == 1){
    
    //blink blue led as a sign for front ultrasonic sensor 1
    digitalWrite(blue_led, HIGH);
    delay(2000);                        //wait 2 second(s)
    digitalWrite(blue_led, LOW);
    
    //trigger the front ultrasonic sensor
    digitalWrite(trigger, LOW);                 //low because to set clear trigger pin
    delayMicroseconds(2);                       //wait 2 micro second(s)
    digitalWrite(trigger, HIGH);                //make output signal wave
    delayMicroseconds(10);                      //Wait for 10 micro second(s)
    digitalWrite(trigger, LOW);                 //off output signal wave
    duration = pulseIn(echo, HIGH);             //catch back output signal wave as input
    distance = duration * 0.034 / 2;            //calculate distance value
    //Serial.println((String)"Front distance: "+distance);

      //conditions for front ultrasonic sensor
      if (distance < 182.88){
        tone(buzzer, 200, 800);                 //Turn-on buzzer sound as a alert sign
        digitalWrite(red_led, HIGH);            //Turn-on red led as a danger sign
        delay(3000);                            //wait 3 second(s)
        digitalWrite(red_led, LOW);             //Turn-off red led to be a blink
        //Serial.println("You are in danger distance");
      }//front ultrasonic sensor's condition 1
      else{
        noTone(buzzer);                       //off buzzer sound
        delay(1000);                          //wait 1 second(s)
        //blink blue led as a sign for right ultrasonic sensor 2
        digitalWrite(blue_led, HIGH);
        delay(2000);                        //wait 2 second(s)
        digitalWrite(blue_led, LOW);
        
        //trigger the right ultrasonic sensor
        digitalWrite(trigger2, LOW);             //low because making clear trigger pin
        delayMicroseconds(2);                    //wait 2 micro second(s)
        digitalWrite(trigger2, HIGH);            //make output signal wave
        delayMicroseconds(10);                   //Wait for 10 micro second(s)
        digitalWrite(trigger2, LOW);             //off output signal wave
        duration2 = pulseIn(echo2, HIGH);        //catch back output signal wave as input
        distance2 = duration2 * 0.034 / 2;       //calculate distance value
        //Serial.println((String)"Right distance: "+distance2);

        //conditions for right ultrasonic sensor
        if (distance2 < 182.88){
          tone(buzzer, 200, 800);                 //Turn-on buzzer sound as a alert sign
          digitalWrite(red_led, HIGH);          //Turn-on red led as a danger sign
          delay(3000);                          //wait 3 second(s)
          digitalWrite(red_led, LOW);           //Turn-off red led to be a blink
          //Serial.println("You are in danger distance");
        }//right ultrasonic sensor's condition 1
        else{
          noTone(buzzer);                       //off buzzer sound
          delay(1000);                          //wait 1 second(s)
          //blink blue led as a sign for back ultrasonic sensor 2
          digitalWrite(blue_led, HIGH);
          delay(2000);                        //wait 2 second(s)
          digitalWrite(blue_led, LOW);
        
          //trigger the back ultrasonic sensor
          digitalWrite(trigger3, LOW);          //low because making clear trigger pin
          delayMicroseconds(2);                 //wait 2 micro second(s)
          digitalWrite(trigger3, HIGH);         //make output signal wave
          delayMicroseconds(10);                //Wait for 10 micro second(s)
          digitalWrite(trigger3, LOW);          //off output signal wave
          duration3 = pulseIn(echo3, HIGH);     //catch back output signal wave as input
          distance3 = duration3 * 0.034 / 2;    //calculate distance value
          //Serial.println((String)"Back distance: "+distance3);

            //conditions for back ultrasonic sensor
            if (distance3 < 182.88){
              tone(buzzer, 200, 800);                 //Turn-on buzzer sound as a alert sign
              digitalWrite(red_led, HIGH);       //Turn-on red led as a danger sign
              delay(3000);                       //wait 3 second(s)
              digitalWrite(red_led, LOW);        //Turn-off red led to be a blink
              //Serial.println("You are in danger distance");
            }//back ultrasonic sensor's condition 1
            else{
              noTone(buzzer);                     //off buzzer sound
              delay(1000);                        //wait 1 second(s)
              //blink blue led as a sign for left ultrasonic sensor 2
              digitalWrite(blue_led, HIGH);
              delay(2000);                        //wait 2 second(s)
              digitalWrite(blue_led, LOW);
        
              //trigger the left ultrasonic sensor
              digitalWrite(trigger4, LOW);        //low because making clear trigger pin
              delayMicroseconds(2);               //wait 2 micro second(s)
              digitalWrite(trigger4, HIGH);       //make output signal wave
              delayMicroseconds(10);              //Wait for 10 micro second(s)
              digitalWrite(trigger4, LOW);        //off output signal wave
              duration4 = pulseIn(echo4, HIGH);   //catch back output signal wave as input
              distance4 = duration4 * 0.034 / 2;  //calculate distance value
              //Serial.println((String)"Left distance: "+distance4);

              //conditions for left ultrasonic sensor
              if (distance4 < 182.88){
                tone(buzzer, 200, 800);                 //Turn-on buzzer sound as a alert sign
                digitalWrite(red_led, HIGH); //Turn-on red led as a danger sign
                delay(3000);                 //wait 3 second(s)
                digitalWrite(red_led, LOW);  //Turn-off red led to be a blink
                //Serial.println("You are in danger distance");
              }//left ultrasonic sensor's condition 1
              else{
                //Serial.println("You are in safe distance");
                noTone(buzzer);                 //Turn-off buzzer sound as a good sign 
                digitalWrite(red_led, LOW);     //Turn-off red led to turn-on only green led
                digitalWrite(blue_led, LOW);    //Turn-off blue led to turn-on only green led
                digitalWrite(green_led, HIGH);  //Turn-on green led as a safe sign
                delay(1000);                    //wait 1 second(s)
                digitalWrite(green_led, LOW);   //Turn-off green led to be a blink
              }//left ultrasonic sensor's condition 2
              
            }//back ultrasonic sensor's condition 2
            
        }//right ultrasonic sensor's condition 2
        
      }//front ultrasonic sensor's condition 2
      
  }//PIR sensor's condition 1
  else{
    //Serial.println("You are in safe distance");
    digitalWrite(red_led, LOW);      //Turn-off red led to turn-on only green led
    digitalWrite(blue_led, LOW);     //Turn-off blue led to turn-on only green led
    digitalWrite(green_led, HIGH);   //Turn-on green led as a safe sign
    delay(1000);                     //wait 1 second(s)
    digitalWrite(green_led, LOW);    //Turn-off green led to be a blink
  }//PIR sensor's condition 2
}

/* -------------------------------------------------------------- END SOURCE CODE -------------------------------------------------------------- */
