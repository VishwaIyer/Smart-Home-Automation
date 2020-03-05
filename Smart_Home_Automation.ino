#include <Servo.h>
#define ServoPin 8
#define relay0 A0
#define relay2 A2
#define interval 1000
int red_light_pin= 11;
int green_light_pin= 10;
int blue_light_pin = 9;
Servo myservo;
int c = 0;
int m=0;
int n=0;
void setup()
{
// put your setup code here, to run once:
10
myservo.attach(ServoPin);
Serial.begin(9600);
pinMode(relay0, OUTPUT);
pinMode(relay2, OUTPUT);
pinMode(red_light_pin, OUTPUT);
pinMode(green_light_pin, OUTPUT);
pinMode(blue_light_pin, OUTPUT);
}
char val;
int flag=0;
void loop()
{
// put your main code here, to run repeatedly:
if(Serial.available())
{
val=Serial.read();
myservo.write(val);
11
if(val=='a')
{
if(flag==0)
{
myservo.write(90);
flag=1;
}
else if(flag==1)
{
myservo.write(0);
flag=0;
}
}
else if(val=='b')
{
c++;
12
if (c == 0)
{
digitalWrite(red_light_pin,LOW);
digitalWrite(green_light_pin,LOW);
digitalWrite(blue_light_pin,LOW);
}
else if (c == 1)
{
digitalWrite(red_light_pin,HIGH);
digitalWrite(green_light_pin,LOW);
digitalWrite(blue_light_pin,LOW);
}
else if (c == 2)
{
digitalWrite(red_light_pin,LOW);
digitalWrite(green_light_pin,HIGH);
digitalWrite(blue_light_pin,LOW);
}
13
else if (c == 3)
{
digitalWrite(red_light_pin,LOW);
digitalWrite(green_light_pin,LOW);
digitalWrite(blue_light_pin,HIGH);
}
else if (c == 4)
{
digitalWrite(red_light_pin,HIGH);
digitalWrite(green_light_pin,LOW);
digitalWrite(blue_light_pin,HIGH);
}
else if (c == 5)
{
digitalWrite(red_light_pin,LOW);
digitalWrite(green_light_pin,HIGH);
digitalWrite(blue_light_pin,HIGH);
}
14
else if (c == 6)
{
digitalWrite(red_light_pin,HIGH);
digitalWrite(green_light_pin,HIGH);
digitalWrite(blue_light_pin,LOW);
}
else if(c==7)
{
digitalWrite(red_light_pin,HIGH);
digitalWrite(green_light_pin,HIGH);
digitalWrite(blue_light_pin,HIGH);
}
else
c=0;
}
else if(val=='c')
15
{
if(m==0)
{
digitalWrite(relay0, HIGH);
m=1;
}
else
{
digitalWrite(relay0, LOW);
m=0;
}
}
else if(val=='d')
{
if(n==0)
{
digitalWrite(relay2, HIGH);
n=1;
16
}
else
{
digitalWrite(relay2, LOW);
n=0;
}
}
else if(val=='e')
{
myservo.write(0);
digitalWrite(red_light_pin,LOW);
digitalWrite(green_light_pin,LOW);
digitalWrite(blue_light_pin,LOW);
digitalWrite(relay0,LOW);
digitalWrite(relay2,LOW);
}
else if(val=='f')
{
17
myservo.write(90);
digitalWrite(red_light_pin,HIGH);
digitalWrite(green_light_pin,HIGH);
digitalWrite(blue_light_pin,HIGH);
digitalWrite(relay0,HIGH);
digitalWrite(relay2,HIGH);
}
}
}
