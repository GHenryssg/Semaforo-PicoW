# Semaforo-PicoW

# Semáforo com Raspberry Pi Pico e Pico SDK

## Descrição
Este projeto implementa um sistema de semáforo utilizando a biblioteca **Pico SDK**. O controle do semáforo é realizado através da função `add_repeating_timer_ms()`, garantindo a troca de sinais a cada **3 segundos** de forma automática.

## Funcionamento
1. O sistema inicia com o **LED vermelho** aceso.
2. Após **3 segundos**, o semáforo muda para **amarelo**.
3. Após mais **3 segundos**, muda para **verde**.
4. Após mais **3 segundos**, retorna para **vermelho**, reiniciando o ciclo.

A temporização é gerenciada pela função `add_repeating_timer_ms()`, que chama uma função de callback periodicamente para alternar os estados do semáforo.

## Componentes Utilizados
- **Microcontrolador:** Raspberry Pi Pico
- **LEDs:** Vermelho, Amarelo e Verde
- **Resistores:** Resistores adequados para os LEDs

## Pinos Utilizados
| Componente  | Pino do Pico |
|-------------|-------------|
| LED Vermelho | GPIO 11     |
| LED Amarelo  | GPIO 12     |
| LED Verde    | GPIO 13     |


## Simulação
Para testar este projeto em um simulador, pode-se utilizar ferramentas como:
- **Proteus**
- **Fritzing**
- **Wokwi**

