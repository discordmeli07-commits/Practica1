String comando = "";
int led = 25;  // GPIO 2

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(115200);
  Serial.println("Escribe 'on' para encender o 'off' para apagar el LED");
}

void loop() {
  if (Serial.available() > 0) {
    comando = Serial.readStringUntil('\n');
    comando.trim();

    if (comando == "on") {
      digitalWrite(led, HIGH);
      Serial.println("LED ENCENDIDO");
    } 
    else if (comando == "off") {
      digitalWrite(led, LOW);
      Serial.println("LED APAGADO");
    } 
    else {
      Serial.println("Comando no reconocido");
    }
  }
}
