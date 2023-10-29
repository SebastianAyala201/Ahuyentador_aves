int led		= 3;
int pir		= 2;
int buzzer 	= 4;
int potenc 	= A0;
int valor 	= 0;
int tempo;

unsigned long tempoInicial;
bool temMovimento = false;

void setup()
{
  Serial.begin(9600);
  pinMode(led, 		OUTPUT); 
  pinMode(buzzer, 	OUTPUT);
  pinMode(potenc, 	INPUT);
  pinMode(pir, 		INPUT);
  tempoInicial = millis();
}

void loop()
{
  valor = analogRead(potenc);
  valor = map(valor,0, 1023, 20, 2000);
 
  temMovimento = digitalRead(pir);

  if(temMovimento)
  {
	  encenderluzesBuzzer(valor);
    Serial.println("¡Hay aves!");
  }
  else{
    Serial.println("Modo Vigilancia");
  }
}

void encenderluzesBuzzer(int frequency)
{
    //leds
    digitalWrite(led, HIGH);
    delay(100);
    digitalWrite(led, LOW);
    //buzzer
    tone(buzzer,frequency); 
    delay(100);
    noTone(buzzer);
}

