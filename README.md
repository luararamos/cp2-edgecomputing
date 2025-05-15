# Checkpoint 2 - Monitoramento de Condições Ambientais

Projeto de circuito para uma vinícola que busca automatizar o monitoramento das condições ambientais da adega, incluindo **luminosidade, temperatura e umidade**. A ideia é garantir a conservação ideal dos vinhos armazenados, usando sensores e um display para informar a situação em tempo real. O projeto utiliza conceitos aprendidos em aula e complementa com pesquisas adicionais.

📺 **Veja o vídeo explicativo do projeto 👉 _Clique aqui!_**

---

## 👥 Equipe do Projeto

| Nome   | RM       | E-mail                     |
|--------|----------|----------------------------|
| Luara  | 565573   | rm565573@fiap.com.br       |
| Kaio   | 566536   | rm566536@fiap.com.br       |
| Jean   | 566534   | rm566534@fiap.com.br       |

---

## 💻 Desenvolvimento

### 🛠️ Componentes utilizados
- Arduino Uno  
- Protoboard  
- Jumpers  
- Resistores de 10 kΩ  
- LEDs: Verde, Amarelo e Vermelho  
- Fotorresistor (LDR)  
- Buzzer  
- Sensor de Temperatura (TMP36)  
- Sensor de Umidade (analógico)  
- Display LCD 16x2 com módulo I2C (PCF8574)

---

## ⚙️ Explicação dos Componentes

### Fotorresistor (LDR)
O LDR, conectado ao pino A5, capta a luminosidade do ambiente. Com base na variação da luz, o sistema ativa LEDs e exibe mensagens no LCD:
- **LED Verde**: iluminação ideal (ambiente escuro)
- **LED Amarelo**: meia luz (exibe "Ambiente a meia luz" no display)
- **LED Vermelho**: ambiente muito claro (exibe "Ambiente muito claro" e aciona o buzzer)

### Sensor de Temperatura (TMP36)
Lê a temperatura ambiente via pino A0. A lógica do sistema:
- Entre **10°C e 15°C**: mostra "Temperatura OK" no display com o valor médio.
- Abaixo de 10°C: exibe "Temp. Baixa", acende o LED Amarelo e ativa o buzzer.
- Acima de 15°C: exibe "Temp. Alta", acende o LED Amarelo e ativa o buzzer.

### Sensor de Umidade
Conectado ao pino A1, faz a leitura da umidade relativa do ar:
- Entre **50% e 70%**: mostra "Umidade OK" no display com o valor médio.
- Abaixo de 50%: exibe "Umidade Baixa", acende o LED Vermelho e ativa o buzzer.
- Acima de 70%: exibe "Umidade Alta", acende o LED Vermelho e ativa o buzzer.

### Display LCD 16x2 com I2C
Conectado aos pinos **A2 (SDA)** e **A3 (SCL)**, o LCD exibe os valores médios da temperatura e umidade a cada **5 segundos**, com base em **5 leituras consecutivas**.

---

## 🧠 Lógica de Funcionamento

### Intervalos de Luminosidade
| Nível de Luz        | LED Ativado | Buzzer | Mensagem no LCD         |
|---------------------|-------------|--------|--------------------------|
| ≤ 70 (escuro)       | Verde       | Não    | -                        |
| > 70 e ≤ 85 (meia)  | Amarelo     | Não    | "Ambiente a meia luz"    |
| > 85 (claro)        | Vermelho    | Sim    | "Ambiente muito claro"   |

### Intervalos de Temperatura
| Temperatura (°C)  | LED         | Buzzer | Mensagem no LCD      |
|------------------|-------------|--------|------------------------|
| 10°C a 15°C       | Nenhum      | Não    | "Temperatura OK"       |
| < 10°C            | Amarelo     | Sim    | "Temp. Baixa"          |
| > 15°C            | Amarelo     | Sim    | "Temp. Alta"           |

### Intervalos de Umidade
| Umidade (%)       | LED         | Buzzer | Mensagem no LCD      |
|------------------|-------------|--------|------------------------|
| 50% a 70%         | Nenhum      | Não    | "Umidade OK"           |
| < 50%             | Vermelho    | Sim    | "Umidade Baixa"        |
| > 70%             | Vermelho    | Sim    | "Umidade Alta"         |

---

## 🔁 Exibição de Informações

- As **leituras dos sensores** são feitas continuamente.
- A **média de 5 leituras** é calculada a cada **5 segundos**.
- O LCD exibe:
  - Temperatura média com status
  - Umidade média com status
  - Mensagens relacionadas à luminosidade conforme necessário

---

## 👩‍💻 Código do Circuito

O código completo está na pasta `codigo_cp2/` com o arquivo `codigo_cp2.ino`.

Você também pode acessá-lo diretamente 👉 **_Clique aqui_**

---

## 🧪 Montagem do Circuito

Ambiente simulado para testes do circuito 👉 **_Clique aqui_**

> **Importante:** o projeto foi testado no Tinkercad com as bibliotecas disponíveis, utilizando o LCD com I2C do tipo **PCF8574**.
