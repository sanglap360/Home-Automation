#include<Servo.h>
Servo x;
int pos = 0;// intialized position as 0;
const int y=5;//echo pin of sonar;
const int z=7;//trigger pin of sonar;


void setup() 
{ pinMode(6,OUTPUT);//LED LIGHT;
x.attach(8);//SERVO MOTOR ;
pinMode(z,OUTPUT);// trigger is for output signal;
pinMode(y,INPUT);//echo for input signal;
}

void loop()
{
long d;//duration
int s;//distance
  digitalWrite(z,LOW);// At initial trigger is 0;
  delayMicroseconds(2);// after the first stage timer need a delay of 2 microseconds;
  digitalWrite(z,HIGH);// now the trigger is switched on;
  delayMicroseconds(5);// delay of 5 microseconds ;
   d=pulseIn(y,HIGH);// Sonar sensor Take pulses(Signal) from the object;
  s=d*0.034/2;//Mesure the distance by using Dopller effect of sound;
  if(s<=40)//when distance is less then 4 cm;
  {
  for(pos=0; pos<=130;pos+=5)// gate is opened ;
  { 
    x.write(pos);
  digitalWrite(6,HIGH);//gate opened and the led turned on;
  delay(5);
  }delay(10000);}
   else
  {
  for(pos=130;pos>=0;pos-=5);//gate is closed;
  {
    x.write(pos);
  digitalWrite(6,LOW);
delay(20);
  }
  }delay(100);}
