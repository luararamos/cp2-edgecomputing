# Checkpoint 2 - Monitoramento de Vinheria 🍷

Projeto de circuito para uma vinheria que busca automatizar o monitoramento das condições ambientais da adega, incluindo **luminosidade, temperatura e umidade**. A ideia é garantir a conservação ideal dos vinhos armazenados, usando sensores e um display para informar a situação em tempo real. O projeto utiliza conceitos aprendidos em aula e complementa com pesquisas adicionais.

📺 **Veja o vídeo explicativo do projeto 👉 [**Clique aqui**](https://www.youtube.com/watch?v=vkRdPV0pZD8&t=1s)

---

## 👥 Equipe do Projeto

| Nome   | RM       | E-mail                     |
|--------|----------|----------------------------|
| Luara Martins de Oliveira Ramos  | 565573   | rm565573@fiap.com.br       |
| Kaio Victtor Santos Andrade Galvão   | 566536   | rm566536@fiap.com.br       |
| Jean Pierre Andrade Feltran   | 566534   | rm566534@fiap.com.br       |

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

## 🚀 MVP do Produto

<img src="https://github.com/user-attachments/assets/e67419fa-3088-42b7-8628-9e8ae6f03414" alt="Dispositivo Arduino com Sensor DHT11" width="400" />


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

O código completo está na pasta `codigo-c/` com o arquivo `cp_2_edge_grupo_7.ino`.

Você também pode acessá-lo diretamente 👉 *[**Clique aqui**](https://github.com/luararamos/cp2-edgecomputing/blob/main/codigo-c/cp_2_edge_grupo_7.ino)


---

## 🧪 Montagem do Circuito

Ambiente simulado do circuito 👉 [**Clique aqui**](https://www.tinkercad.com/things/8FnMSzi0G7J-cp-2-edge-grupo-7/editel?returnTo=https%3A%2F%2Fwww.tinkercad.com%2Fdashboard&sharecode=HaBvEHHctf9PeKeA9z_7yYxlNdv7NT31blenweq09PE)

<img src="https://github.com/user-attachments/assets/3d08ddfe-437e-47f8-b3ff-68684d1bf81a" alt="Foto do circuito" width="500" />



