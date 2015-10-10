//  MLAB LABduino LCD module example
//  www.mlab.cz
//---------------------------------------------------------------------

#include <LiquidCrystal.h>

#define  S1  9  // PB1
#define  S2  10 // PB2
#define  S3  6  // PD6
#define  S4  7  // PD7

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 

// Create a set of new characters
byte smiley[8] = {
  0b00000,
  0b00000,
  0b01010,
  0b00000,
  0b00000,
  0b10001,
  0b01110,
  0b00000
};

byte frownie[8] = {
  0b00000,
  0b00000,
  0b01010,
  0b00000,
  0b00000,
  0b00000,
  0b01110,
  0b10001
};



void play()
{
  // notes in the melody:
  int melody[] = {
    262, 196, 196, 220, 196,0, 247, 262};
  
  // note durations: 4 = quarter note, 8 = eighth note, etc.:
  int noteDurations[] = {
    4, 8, 8, 4,4,4,4,4 };
    
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 8; thisNote++) 
  {
    // to calculate the note duration, take one second 
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000/noteDurations[thisNote];
    tone(8, melody[thisNote],noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }
}

int button;
  
void setup()
{
  lcd.begin(16,2);               // initialize the lcd 

  lcd.createChar (0, smiley);    // load character to the LCD
  lcd.createChar (1, frownie);   // load character to the LCD

  lcd.home ();                   // go home
  lcd.print("www.mlab.cz  www.mlab.cz  www.mlab.cz");
  lcd.setCursor ( 0, 1 );
  lcd.print("wiki.mlab.cz/doku.php?id=cs:labduino");  
  
  
  pinMode(S1, INPUT);   // initialize buttons
  pinMode(S2, INPUT); 
  pinMode(S3, INPUT); 
  pinMode(S4, INPUT); 

  button = 6;
  lcd.setCursor ( 0, 1 );
}

unsigned int n=0;

void loop()
{
  
  if (!digitalRead(S1))   // read buttons
  {
    button=1;    
  }
  if (!digitalRead(S2))
  {
    button=2;    
  }
  if (!digitalRead(S3))
  {
    button=3;    
  }
  if (!digitalRead(S4))
  {
    button=4;    
  }
  
  if ((button<=4)&&(button>=1))
  {
    lcd.clear();                   // clear display
    lcd.home ();                   // go home
    lcd.print("www.mlab.cz");
    lcd.setCursor ( 0, 1 );
    lcd.print("Cvak...S"); 
  }
  
  switch (button)        // do some specific action 
  {
    case 1:
      lcd.print("1"); 
      button=0;
      break;
    case 2:
      lcd.print("2");  
      button=0;
      break;
    case 3:
      lcd.print("3");  
      button=0;
      break;
    case 4:
      lcd.print("4");  
      button=0;
      break;      
  }
  
  if (0==button)                  // do rest of action
  {
      lcd.setCursor ( 10, 1 );
      lcd.print ( char(0));
      play();
      lcd.setCursor ( 0, 1 );
      lcd.print("Hmmm...   ");  
      lcd.print ( char(1));
      button=5;
      lcd.setCursor ( 0, 1 );
  }


  if ((n++ > 25000) && (button==6))  // time delay
  {
    lcd.scrollDisplayLeft();
    n=0;
  }
}
