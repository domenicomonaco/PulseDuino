## PulseDuino =  Light Pulse + Arduino ##
* Author: Domenico Monaco, domenico.monaco[@]kiuz.it
* Site: http://monaco.kiuz.it
* LICENSE: GNU v2 
* Date: 24 / 03 / 2014

## Derivaiton ##
This is entirly derived by mine Arduino sketch for photoresistor and some inspiration that you found "Special Thanks, ispiration and forks" part of this document.

## Goals ##
* Identify Light pulse by Photoresistor
* Reading frequency of pulse
* Personalize value of reading

##Feature ##
* Set analog pin of LDR sensor
* Set digital pin of led used to "mirror" light pulse
* Set "Pulse duration", is minimiun time to ignore consecutve "hight" level of light
* Set time windows to count pulse, example each 30s 
* Calucate frequency with your personalized time Unit example  3455 pulse per hours or 364 pulse per minuts
* Mapping raw light level from sensoro to "predefined value range"
* Personalize "predefined value range"
* Set mapped level of light that you consider "pulse"

## Requirements ##

#### Hardware ####
	* Photoresistor
	* Arduino
	* 10K ohm Resistor or a sum of some

**[IMPORTANT]** Photoresistor directly oriented to source of "light pulse", where there aren't disturb by external light. So the goal is: there are nothing light disturb between sensor and source, and there are evidence between "light UP" and "light DOWN" of source

## Example of use ##
### EnelDUINO ##

** http://www.enel.com/ **

Enel is Italy’s largest power company, each house have an electronic system that allows reading consumption or produced energy by house. To allow this have one screen lcd with some menu, plus two led to allow immediate reading of energy consumation, where each light puls corresponds to 1w/h. 

With this preamble I've created simple "Light pulse reader" by LDR sensor to read this information by Enel electronic system. Obviously I've generalized the "light pulse reader" library to use in some other case. 

You can found this implemenation of "Light Pulse Reader" into Examples folder, named as EnelDuino;


## Special Thanks, ispiration and forks ##
* <http://enerduino.blogspot.it/2009/12/enerduino-italiano.html>
* <http://bildr.org/2012/11/photoresistor-arduino/>
* <http://blog.elettronicain.it/2011/07/22/tidigino-contest-monitor-real-time-consumi-energia-di-michele-mancini/>
* <http://arduinobasics.blogspot.it/2011/06/arduino-uno-photocell-sensing-light.html>
