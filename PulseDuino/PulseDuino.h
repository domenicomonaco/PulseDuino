//  PulseDuino 
//  
//  Simple reader of Light Pulse by using LDR sensor
//
//  Created by Domenico Monaco on 24/03/2014
//  Copyright 2014 Domenico Monaco - domenico.monaco@kiuz.it
//
//  License: GNU v2
//

#ifndef LightPulseReader_h
#define LightPulseReader_h

#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
  #else
  #include "WProgram.h"
#endif

class LightPulse{
private:

// pint of LDR sensor
    int pldr;

// Pin of LED mirror
    int pledmirr;

// Light level in RAW formats
    int LightLevelRAW;

// mapped value in the particular range
    int mappedLightLevel;

// Default time duration Light Pulse, 
// light pulse in this elapsed time will
// be considered part of same pulse
// format: milliseconds
    int pulseDuration;

    int pulseDetectLevel;

    // Default map range to normalize RAW data
    // default is [0-100]
    int MAPMAX;
    int MAPMIN;

    int minLight;
    int maxLight;

    //count of pulse in the particular "timeCount"
    int lastCountPulse;
    int currentcountPulse;

    // time windows to count pulse
    int timeCount ;

    // time values used into interation
    long int currentTime;
    long int lastPartitionTime;

    // time of last windows of count 
    long int lastTimeCount;

    bool PULSE;

public:
    LightPulse(int PIN_LDR, int LEVELPULSE){

    setPulseDuration();
    setMapRange();
    setTimeCountPulse();
    setPinLedMirror();
    
    pldr=PIN_LDR;
    setLevelPulse(LEVELPULSE);

    LightLevelRAW = analogRead(pldr);
    minLight= LightLevelRAW-20;
    maxLight= LightLevelRAW;

    currentTime = millis();
    lastTimeCount = currentTime;

    pinMode(pledmirr, OUTPUT);
    digitalWrite(pledmirr, LOW);

    }

    void setTimeCountPulse(unsigned long int time = 30000){
        timeCount = time;
    }
    void setPinLedMirror(int pin = 13){
        pledmirr=pin;
    }
    
    void setMapRange(int min=0, int max=100){
        MAPMAX = max;
        MAPMIN = min;
    }
    void setPulseDuration(int time = 50){
      pulseDuration=time;
    }

    void setLevelPulse(int level = 90){
      pulseDetectLevel=level;
    }

    int checkLight(){
        currentTime=millis();
        LightLevelRAW = analogRead(pldr);

        if(minLight> LightLevelRAW){
           minLight= LightLevelRAW;
        }

        if(maxLight<LightLevelRAW){
           maxLight= LightLevelRAW;
        }
        
        mappedLightLevel = map(LightLevelRAW, minLight, maxLight, MAPMIN, MAPMAX);

        if(mappedLightLevel >=  pulseDetectLevel){

            if((currentTime-lastTimeCount) >= pulseDuration){
                
                lastTimeCount = currentTime;

                currentcountPulse=currentcountPulse+1;
                PULSE=true;

                digitalWrite(pledmirr, HIGH);
                delay(30);
            }else{
                digitalWrite(pledmirr, LOW);
                PULSE=false;
            }
        }else{
            digitalWrite(pledmirr, LOW);
            PULSE=false;
        }

        long int elapsed = currentTime-lastPartitionTime;
        if(elapsed >= timeCount){
            lastCountPulse = currentcountPulse;
            currentcountPulse = 0;
            lastPartitionTime = currentTime;
        }
        return mappedLightLevel;
    }

    boolean isPulse(){
        return PULSE;
    }

    int getLastCount(){
        return lastCountPulse;
    }
    int getCurrentCount(){
        return currentcountPulse;
    }

    long int getLastTimeCount(){
        return lastTimeCount;

    }
    unsigned long int getFrequency(int TimeUnit, int PulseUnit){
        float A = (TimeUnit/(timeCount/1000));
        float B = (lastCountPulse/PulseUnit);
        unsigned long int C = A*B;
        return C;
    }
};


#endif
