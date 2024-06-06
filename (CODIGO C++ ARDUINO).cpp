#include <LiquidCrystal.h>

// Inicializa o display com os pinos correspondentes
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Pinos do sensor ultrassônico
const int trigPin = 9;
const int echoPin = 8;

void setup() {
  // Configura os pinos do sensor ultrassônico
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Configura o display LCD
  lcd.begin(16, 2);
  lcd.print("Preserve o Oceano");
  delay(2000); // Espera 2 segundos para mostrar a mensagem inicial
}

void loop() {
  // Gera um pulso de 10 microsegundos no TRIG
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Calcula o tempo que o pulso ECHO levou para retornar
  long duration = pulseIn(echoPin, HIGH);

  // Calcula a distância em centímetros
  int distance = duration * 0.034 / 2;

  // Se a distância for menor que 50 cm, exibe a mensagem no LCD
  if (distance < 50) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Nao jogue lixo");
    lcd.setCursor(0, 1);
    lcd.print("no mar!");
  } else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Preserve o Oceano");
  }

  // Espera 500ms antes de medir novamente
  delay(500);
}
