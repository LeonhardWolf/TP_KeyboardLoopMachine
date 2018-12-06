
/* sketch in out
Digitale Eingänge werden mit dem Schieberegister CD4021 parallel gelesen und seriell zum Arduino geleitet.
Dieser gibt die Daten seriell an das Schieberegister 74HC595, der die Daten dann parallel an Leuchtdioden anzeigt.
Technisches Projekt WiSe2017
 */
// globale Variablen deklarieren
int Wert_1;
int Wert_2;
int CLK = 12;
int LATCH = 11;
int DATA = 9;
int DOUT = 10;


void setup() {
  Serial.begin(9600);
  
  pinMode(DATA, INPUT);
  pinMode(CLK, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(DOUT, OUTPUT);
  Serial.println("Begin...");
}

void loop() {
  digitalWrite(LATCH, HIGH);
  delay(1);
  digitalWrite(LATCH, LOW);
  delay(1);
  Wert_1 = shiftIn(DATA, CLK, MSBFIRST);
  delay(1);
  Wert_2 = shiftIn(DATA, CLK, MSBFIRST);
  delay(1);

  Serial.print(Wert_1, BIN);
  Serial.print("  ");
  Serial.println(Wert_2, BIN);
  shiftOut(DOUT, CLK, MSBFIRST, Wert_1 + Wert_2);
  

  delay(10);
}
