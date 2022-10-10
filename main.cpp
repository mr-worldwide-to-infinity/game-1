#include <Arduino.h>
#include <Display.h>
const int led1 = 7;
const int led2 = 6;
const int knopb = 8;
const int knopa = 9;
const int buzzer=3;

int x = 200;
int headcounter = 1;
int buttonstatea = 0;
int buttonstateb = 0;
int laststate;
int count;
int scount;
int a;
int b;
int c = 0;
int simonsaysia[6]{1, 1, 2, 1, 2, 2};
int simonsaysib[6]{2, 2, 2, 1, 1, 2};
int knoppen[]{knopa, knopb};
int laststateb;
int level = 1;
int arrayOutcome[6]{};
int statemonitor = 1;
int conditioncounter = 0;
int klopt;
int simonsaysic[6]{2, 1, 2, 1, 2, 2};
int randomnummer;
unsigned long tijd;
int maareen = 0;

void vreugde(){
  for (int yui = 0; yui <= 5; yui++)
  {
    tone(buzzer, 5000);
  delay(100);
  noTone(buzzer);
  delay(100);
  }
}

void fa()
{
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW);
  tone(buzzer, 1000);
  delay(x);
  digitalWrite(led1, LOW);
  noTone(buzzer);
  delay(x);
}
// lampje links aan
void fb()
{
  digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);
  tone(buzzer, 2500);
  delay(x);
  digitalWrite(led2, LOW);
  noTone(buzzer);
  delay(x);
}
// lampje rechts aan
void simonsaysoa()
{
  fa();
  fa();
  fb();
  fa();
  fb();
  fb();
}

void simonsaysob()
{
  fb();
  fb();
  fb();
  fa();
  fa();
  fb();
}

void simonsaysoc()
{
  fb();
  fa();
  fb();
  fa();
  fb();
  fb();
}

int controlea()
{

  for (int k = 0; k <= 5; k++)
  {
    if (arrayOutcome[k] == simonsaysia[k])
    {
      conditioncounter++;
    }
  }
  if (conditioncounter == 6)
  {
    {
      Serial.println("great succes");
      vreugde();
      klopt = 1;
      level = 2;
      statemonitor = 1;
      for (int o = 0; o <= 5; o++)
      {
        arrayOutcome[o] = 0;
      }
      c = 0;
      Serial.println("clear");
    }
    conditioncounter = 0;
    return level;
  }
  if (arrayOutcome[5] == 1 || arrayOutcome[5] == 2)
  {
    for (int o = 0; o <= 5; o++)
    {
      arrayOutcome[o] = 0;
    }
    c = 0;
    Serial.println("clear");
    statemonitor = 1;
  }
}

int reader()
{
  int a = digitalRead(knopa);
  if (a != laststate && a == LOW)
  {
    delay(75);
    a = digitalRead(knopa);
    if (a == LOW)
    {
      tone(buzzer,1000);
      delay(x);
      noTone(buzzer);
      count = 1;
      arrayOutcome[c] = count;
      c++;
    }
  }
  laststate = a;

  int b = digitalRead(knopb);
  if (b != laststateb && b == LOW)
  {
    delay(75);
    b = digitalRead(knopb);
    if (b == LOW)
    {
      tone(buzzer,2500);
      delay(x);
      noTone(buzzer);
      count = 2;
      arrayOutcome[c] = count;
      c++;
    }
  }
  laststateb = b;

  for (int h = 0; h <= 5; h++)
  {
    Serial.print(arrayOutcome[h]);
  }
  Serial.println("");
}

int controleb()
{
  for (int k = 0; k <= 5; k++)
  {
    if (arrayOutcome[k] == simonsaysib[k])
    {
      conditioncounter++;
    }
  }
  if (conditioncounter == 6)
  {
    {
      Serial.println("great succes2");
      vreugde();
      klopt = 1;
      level = 3;
      statemonitor = 1;
      for (int o = 0; o <= 5; o++)
      {
        arrayOutcome[o] = 0;
      }
      c = 0;
      Serial.println("clear");
    }
    conditioncounter = 0;
    return level;
  }
  if (arrayOutcome[5] == 1 || arrayOutcome[5] == 2)
  {
    for (int o = 0; o <= 5; o++)
    {
      arrayOutcome[o] = 0;
    }
    c = 0;
    Serial.println("clear");
    statemonitor = 1;
  }
}

int controlec()
{
  for (int k = 0; k <= 5; k++)
  {
    if (arrayOutcome[k] == simonsaysic[k])
    {
      conditioncounter++;
    }
  }
  if (conditioncounter == 6)
  {
    {
      Serial.println("great succes3");
      vreugde();
      klopt = 1;
      level = 4;
      statemonitor = 1;
      for (int o = 0; o <= 5; o++)
      {
        arrayOutcome[o] = 0;
      }
      c = 0;
      Serial.println("clear");
    }
    conditioncounter = 0;
    {
      /* code */
    }

    return level;
  }
  if (arrayOutcome[5] == 1 || arrayOutcome[5] == 2)
  {
    for (int o = 0; o <= 5; o++)
    {
      arrayOutcome[o] = 0;
    }
    c = 0;
    Serial.println("clear");
    statemonitor = 1;
  }
}

void setup()
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(knopa, INPUT_PULLUP);
  pinMode(knopb, INPUT_PULLUP);
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
}

void loop()
{
  if (level == 1 && statemonitor == 1)
  {
    Display.show("1");
    simonsaysoa();
    statemonitor = 0;
  }
  if (level == 2 && statemonitor == 1)
  {
    Display.show("2");
    simonsaysob();
    statemonitor = 0;
  }
  if (level == 3 && statemonitor == 1)
  {
    Display.show("3");
    simonsaysoc();
    statemonitor = 0;
  }
  if (level == 1)
  {
    controlea();
  }
  if (level == 2)
  {
    controleb();
  }
  if (level == 3)
  {
    controlec();
  }
  if (level == 1 || level == 2 || level == 3)
  {
    reader();
  }
  if (level == 4)
  {
    if (maareen == 0)
    {
      tijd = millis();
      tijd = (tijd * tijd);
      while (tijd > 10000)
      {
        tijd = tijd / 10;
      }
      randomnummer = tijd;
      maareen = 2;
    }
    Display.show(randomnummer);
    delay(1000);
    Serial.print("vul hier het getal op het beeldscherm in gedeeld door 2.\nRond af naar beneden en op gehele getallen: ");
    while (Serial.available() == 0)
    {
    }
    long jo = Serial.readString().toInt();
    
    
    if (jo == (randomnummer/2))
    {
      level = 5;
      Serial.println("great succes");
      vreugde();
    }
    else{
      Serial.println("probeer opnieuw");
    }
  }

  conditioncounter = 0;
  count = 0;
}