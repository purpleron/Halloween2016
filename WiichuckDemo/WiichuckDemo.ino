/*
 * WiiChuckDemo -- 
 *
 * 2008 Tod E. Kurt, http://thingm.com/
 *
 */

#include <Wire.h>
#include "nunchuck_funcs.h"
#include <Servo.h>


int loop_cnt=0;

byte accx,accy,accz,zbut,cbut,joyx,joyy;
int ledPin = 13;

Servo eyepan;
Servo eyetilt;
void setup()
{
    Serial.begin(19200);


    nunchuck_setpowerpins();
    nunchuck_init(); // send the initilization handshake
    eyepan.attach(D3);
    eyetilt.attach(D6);
    
    Serial.print("WiiChuckDemo ready\n");
}
// 130 50

void loop()
{
char i=50;

   
    if( loop_cnt > 20 ) { // every 100 msecs get new data
        loop_cnt = 0;

        nunchuck_get_data();

        accx  = nunchuck_accelx(); // ranges from approx 70 - 182
        accy  = nunchuck_accely(); // ranges from approx 65 - 173
        accz  = nunchuck_accelz(); // ranges from approx 65 - 173
        zbut = nunchuck_zbutton();
        cbut = nunchuck_cbutton(); 
        joyx = nunchuck_joyx();
        joyy = nunchuck_joyy();
        
                  eyetilt.write(joyx);
          eyepan.write(joyy);    
        //Serial.print("accx: "); Serial.print((byte)accx,DEC);
        //Serial.print("\taccy: "); Serial.print((byte)accy,DEC);
        //Serial.print("\taccy: "); Serial.print((byte)accz,DEC);
        //Serial.print("\tzbut: "); Serial.print((byte)zbut,DEC);
        //Serial.print("\tcbut: "); Serial.println((byte)cbut,DEC);
    }
    loop_cnt++;
    delay(1);
}
