# ⚙️ Projeto: PWM

## Descrição
Este projeto implementa um **controle de servomotor** utilizando um **Raspberry Pi Pico W**. O código ajusta o ângulo do servomotor utilizando PWM e realiza uma movimentação periódica suave entre diferentes posições.

## Desenvolvido por
- Vinicius Lemos de Carvalho

## 📌 Funcionalidades
- Controle preciso do ângulo do servomotor através de PWM.
- Movimentação automática entre 0°, 90° e 180°.
- Incremento suave do ângulo para transições mais realistas.
- Compatível com o **simulador Wokwi** e placas físicas.

## 🛠 Componentes utilizados
- 1 × Raspberry Pi Pico W
- 1 × Servomotor micro servo (ex: SG90)
- Fios de conexão

## 📌 Requisitos
- Pico SDK instalado
- Compilador C configurado no VS Code
- Simulador Wokwi

## 📌 Esquema de ligação (GPIOs)

| Componente | Pino GPIO |
|------------|----------|
| Servomotor | 22       |

## Como Compilar e Executar
1. Clone o repositório:
   ```sh
   git clone https://github.com/ViniciusLemosDev/Embacatech_PWM.git
   cd Embacatech_PWM
   ```
2. Compile e Execute o código pelo simulador do Wokwi no VSCode.

## 🏁 Conclusão
Este projeto demonstra um controle eficiente de servomotor utilizando PWM no Raspberry Pi Pico W. Pode ser usado para aplicações como robótica, automação e aprendizado de eletrônica. 🤖⚙️

## Link do Vídeo
https://youtu.be/pQ2Wtm5FJxo
