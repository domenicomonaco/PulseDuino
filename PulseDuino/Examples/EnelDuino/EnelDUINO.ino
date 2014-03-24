//  EnelDUINO 
//  
//  Simple implementation of PulseDUINO
//
//  Created by Domenico Monaco on 24/03/2014
//  Copyright 2014 Domenico Monaco - domenico.monaco@kiuz.it
//
//  License: GNU v2
//

#include <PulseDuino.h>

int photoRPin = A2;
int led = 13;
LightPulse pulseDetect((int)photoRPin, (int)90);

void setup() {
    Serial.begin(9600);

    pulseDetect.checkLight();
    
    Serial.println("Config...");
    delay(1500);
}

void loop(){
    pulseDetect.checkLight();
    if(pulseDetect.isPulse()){

        Serial.println(pulseDetect.getCurrentCount());

        Serial.print("pulse");

        Serial.println(pulseDetect.getFrequency(3600,1)
        );
    }
    delay(10);
}


