#define LEDWIFI 27  
#define LEDRF 33 
#define LED1 34 
#define LED2 35

void setup() {
  // put your setup code here, to run once:
  pinMode(LEDWIFI, OUTPUT);
  pinMode(LEDRF, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}

void Blink(int pin)
{
  digitalWrite(pin, LOW);
  delay(500);
  digitalWrite(pin, HIGH);
  delay(500);
}

void loop() {
  Blink(LEDWIFI);
  Blink(LEDRF);
  Blink(LED1);
  Blink(LED2);
}
