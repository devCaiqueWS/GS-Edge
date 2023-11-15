# Projeto de Bioimpedância com ESP32

## Objetivo
O objetivo deste projeto é utilizar um ESP32 para realizar medições de bioimpedância, fornecendo informações como peso corporal por meio de células de carga (HX711) e estimativas de composição corporal utilizando sensores bioeletricos(representados por sensores ultrassônicos HC-SR04), podendo assim gerar um programa de alimentação ideal para cada individuo.

## Desenvolvimento do Projeto
Este projeto foi desenvolvido utilizando um ESP32 para aquisição de dados de bioimpedância. Utiliza um sensor de célula de carga (HX711) para medir o peso corporal e três sensores ultrassônicos (HC-SR04) para estimar a composição corporal. O código foi escrito em linguagem C++ e foi utilizado o ambiente de desenvolvimento Arduino e o browser de simulação Wokwi.

## Como Executar
1. Conecte os componentes conforme o esquema elétrico abaixo.
2. Carregue o código no ESP32 utilizando o ambiente de desenvolvimento Arduino.
3. Abra o Monitor Serial para visualizar os dados lidos pelos sensores.
4. Os valores exibidos incluem: peso corporal, peso em massa muscular, peso em massa óssea e peso em gordura.

## Pré-requisitos
- ESP32
- Módulo HX711 (sensor de célula de carga)
- Sensores Ultrassônicos HC-SR04 (três unidades)
- Fonte de alimentação para o ESP32
- Fonte de alimentação para os sensores de peso (HX711)
- Fonte de alimentação para os sensores ultrassônicos

## Esquema Elétrico
Link para simulação no Wokwi: <a href="https://wokwi.com/projects/381390178121396225">https://wokwi.com/projects/</a>
- **Sensor de Peso (HX711):**
  - DOUT do HX711 -> Pino 32 (D32) do ESP32
  - CLK do HX711 -> Pino 33 (D33) do ESP32
  - VCC do HX711 -> 3.3V do ESP32
  - GND do HX711 -> GND do ESP32

- **Sensores Ultrassônicos (HC-SR04):**
  - Sensor 1:
    - Trig -> GPIO2 (D2) do ESP32
    - Echo -> GPIO4 (D4) do ESP32
    - VCC -> 5V do ESP32
    - GND -> GND do ESP32

  - Sensor 2:
    - Trig -> GPIO5 (D5) do ESP32
    - Echo -> GPIO15 (D15) do ESP32
    - VCC -> 5V do ESP32
    - GND -> GND do ESP32

  - Sensor 3:
    - Trig -> GPIO18 (D18) do ESP32
    - Echo -> GPIO19 (D19) do ESP32
    - VCC -> 5V do ESP32
    - GND -> GND do ESP32

## Funcionamento
Os sensores de célula de carga (HX711) são utilizados para medir o peso corporal, enquanto os sensores ultrassônicos (HC-SR04) são utilizados como estimativas para a composição corporal. O código lê os valores dos sensores e exibe os resultados no Monitor Serial.

## Dificuldades
Durante o desenvolvimento, algumas dificuldades foram encontradas, principalmente no funcionamento programação dos sensores de célula de carga para garantir medições precisas e confiáveis.

## Código fonte
O código fonte está no arquivo<a href="https://github.com/devCaiqueWS/GS-Edge/blob/main/main.ino"> main.ino</a> do projeto.

## Link para vídeo explicativo

## Conclusão
Este projeto de bioimpedância utilizando ESP32, sensores de célula de carga e ultrassônicos oferece uma forma inicial de medir e estimar parâmetros corporais. As medições podem ser aprimoradas com calibrações mais precisas e análises adicionais para uma avaliação mais detalhada da composição corporal.
