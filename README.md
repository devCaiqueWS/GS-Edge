# Projeto de Bioimpedância com ESP32

Este projeto utiliza um ESP32 para medir informações de bioimpedância, como peso por célula de carga (HX711) e estimativa de composição corporal por sensores bioeletricos (representados por sensores ultrassônicos HC-SR04).

## Hardware necessário

- ESP32
- Módulo HX711 (sensor de célula de carga)
- Sensores Ultrassônicos HC-SR04 (três unidades)
- Jumpers
- Fonte de alimentação para o ESP32
- Fonte de alimentação para os sensores de peso (HX711)
- Fonte de alimentação para os sensores ultrassônicos

## Conexões

### ESP32:

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

## Instruções de Uso

1. Conecte os sensores de peso (HX711) e os sensores ultrassônicos (HC-SR04) conforme as conexões descritas acima.
2. Carregue o código no ESP32 usando a plataforma de desenvolvimento Arduino.
3. Abra o Monitor Serial para visualizar os dados lidos pelos sensores.
4. Os valores exibidos incluem: peso corporal, peso em massa muscular, peso em massa óssea e peso em gordura.

## Observações

- Certifique-se de fornecer a alimentação correta para cada sensor.
- Calibre os sensores de peso (HX711) conforme necessário para garantir medições precisas.
- Os sensores ultrassônicos (HC-SR04) medem distâncias e são utilizados como uma estimativa para compor a análise de bioimpedância.
