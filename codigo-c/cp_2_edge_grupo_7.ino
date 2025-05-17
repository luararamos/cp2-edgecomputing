#include <LiquidCrystal_I2C.h>

#define sensor_ldr  A2
#define sensor_tmp  A0
#define sensor_umidade A1

#define led_verde 5
#define led_amarelo 6
#define led_vermelho 7
#define buzzer 8

LiquidCrystal_I2C lcd(0x20, 16, 2);

// 🥂 Caracteres personalizados
byte wineGlass[8] = {
  B00000,
  B01110,
  B01110,
  B01110,
  B00100,
  B00100,
  B01110,
  B00000
};

byte wineBottle[8] = {
  B00100,
  B00100,
  B01110,
  B01110,
  B01110,
  B01110,
  B01110,
  B00000
};

unsigned long tempo_buzina_alerta = 0;
unsigned long tempo_buzina_problema = 0;
unsigned long tempo_lcd = 0;
unsigned long tempo_tela = 0;

bool mostrarInfos = true;  // controle para alternar mensagens

void setup() {
  Serial.begin(9600);
  pinMode(led_verde, OUTPUT);
  pinMode(led_amarelo, OUTPUT);
  pinMode(led_vermelho, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(sensor_ldr, INPUT);
  pinMode(sensor_tmp, INPUT);
  pinMode(sensor_umidade, INPUT);

  lcd.init();
  lcd.backlight();
  lcd.clear();

  // Cria os ícones no LCD
  lcd.createChar(0, wineGlass);   // char 0 = taça
  lcd.createChar(1, wineBottle);  // char 1 = garrafa
}

void loop() {
  unsigned long agora = millis();

  // Alterna a mensagem a cada 3 segundos
  if (agora - tempo_tela >= 3000) {
    tempo_tela = agora;
    mostrarInfos = !mostrarInfos;
  }
  

  if (agora - tempo_lcd >= 1000) {
    tempo_lcd = agora;

    int leitura_sensor_ldr = analogRead(sensor_ldr);
    int variacao_luz = map(leitura_sensor_ldr, 54, 974, 0, 100);

    int leitura_sensor_tmp = analogRead(sensor_tmp);
    float temperatura_celsius = (leitura_sensor_tmp * 5.0 / 1023.0 - 0.5) * 100.0;

    int leitura_sensor_umidade = analogRead(sensor_umidade);
    int umidade_percentual = map(leitura_sensor_umidade, 0, 1023, 0, 100);

    lcd.clear();

    if (mostrarInfos) {
      Serial.print(variacao_luz);
      Serial.print("% | Temp: ");
      Serial.print(temperatura_celsius);
      Serial.print("°C | Umidade: ");
      Serial.println(umidade_percentual);

      lcd.setCursor(0, 0);
      lcd.print("Luz:");
      lcd.print(variacao_luz);
      lcd.print("% T:");
      lcd.print((int)temperatura_celsius);
      lcd.print("C");

      lcd.setCursor(0, 1);
      lcd.print("Umid:");
      lcd.print(umidade_percentual);
      lcd.print("% ");
      lcd.write(byte(0)); // taça
      lcd.write(byte(1)); // garrafa
    } else {
  		static unsigned long tempo_mensagem = 0;
  		static bool mostrar_umidade = false;

  		// Alterna a cada 2 segundos (2000 ms)
 		 if (millis() - tempo_mensagem >= 2000) {
 		   mostrar_umidade = !mostrar_umidade;
  		  tempo_mensagem = millis();
  		}

  		lcd.clear();

 		 if (!mostrar_umidade) {
  		  // Primeiros 2s: iluminação e temperatura
  		  lcd.setCursor(0, 0);
  		  if (variacao_luz <= 30) {
   		   lcd.print("Amb escuro");
   		 } 
   		 else if (variacao_luz <= 70) {
   		   lcd.print("Meia luz");
   		 } 
   		 else {
    		  lcd.print("Amb claro");
   		 }

   		 lcd.setCursor(0, 1);
   		 if (temperatura_celsius >= 10 && temperatura_celsius <= 15) {
   		   lcd.print("Temp OK ");
  		  } 
   		 else if (temperatura_celsius > 15) {
   		   lcd.print("Temp Alta ");
  		  } 
  		  else {
   		   lcd.print("Temp Baixa ");
   		 }

 		 } else {
 		   // Depois dos 2s: só umidade
  		  lcd.setCursor(0, 0);
  		  lcd.print("Umidade:");

   		 lcd.setCursor(0, 1);
  		  if (umidade_percentual >= 50 && umidade_percentual <= 70) {
   		   lcd.print("Umid OK ");
  		  } 
   		 else if (umidade_percentual > 70) {
   		   lcd.print("Umid Alta ");
  		  } 
  		  else {
  		    lcd.print("Umid Baixa ");
  		  }
 		 }
      
    		}

    		if (variacao_luz <= 70) {
   		   status_ok();
   		 } else if (variacao_luz <= 85) {
   		   status_alerta();
 		   } else {
   		   status_problema();
   		 }
  }

  atualiza_buzinas();
}

void status_ok() {
  digitalWrite(led_verde, HIGH);
  digitalWrite(buzzer, LOW);
  digitalWrite(led_amarelo, LOW);
  digitalWrite(led_vermelho, LOW);
}

void status_alerta() {
  digitalWrite(led_amarelo, HIGH);
  digitalWrite(led_verde, LOW);
  digitalWrite(led_vermelho, LOW);
}

void status_problema() {
  digitalWrite(led_vermelho, HIGH);
  digitalWrite(led_verde, LOW);
  digitalWrite(led_amarelo, LOW);
}

void atualiza_buzinas() {
  unsigned long agora = millis();

  if (digitalRead(led_amarelo) == HIGH) {
    if (agora - tempo_buzina_alerta >= 500 && agora - tempo_buzina_alerta < 3000) {
      digitalWrite(buzzer, HIGH);
    }
    if (agora - tempo_buzina_alerta >= 3000) {
      digitalWrite(buzzer, LOW);
      tempo_buzina_alerta = agora;
    }
  }

  if (digitalRead(led_vermelho) == HIGH) {
    if (agora - tempo_buzina_problema >= 500 && agora - tempo_buzina_problema < 3000) {
      digitalWrite(buzzer, HIGH);
    }
    if (agora - tempo_buzina_problema >= 3000) {
      digitalWrite(buzzer, LOW);
      tempo_buzina_problema = agora;
    }
  }
}
