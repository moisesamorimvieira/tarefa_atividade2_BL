<img width=100% src="https://capsule-render.vercel.app/api?type=waving&color=02A6F4&height=120&section=header"/>
<h1 align="center">Embarcatec | Clock e Temporizadores /  Atividade 2: Temporizador de um disparo (One Shot). </h1>

<div align="center">  
  <img width=40% src="http://img.shields.io/static/v1?label=STATUS&message=EM%20DESENVOLVIMENTO&color=02A6F4&style=for-the-badge"/>
</div>

## Objetivo do Projeto

Com o emprego da função add_alarm_in_ms(), presente na ferramenta Pico SDK, projete um sistema de temporização para o acionamento de LEDs, que atua a partir do clique em um botão (pushbutton). Nesta prática, será necessário simular os seguintes componentes (simulação sugerida presente na Figura 2):

1) Microcontrolador Raspberry Pi Pico W.
2) 03 LEDs (azul, vermelho e verde).
3) 03 Resistores de 330 Ω.
4) Botão (Pushbutton).

## 🗒️ Lista de requisitos

1) Caso o usuário clique no botão (pushbutton), os três LEDs serão ligados (todos em nível alto). A partir da primeira rotina de atraso, ocorrerá uma mudança de estado
para dois LEDs ligados e, em seguida, apenas um. Obs.: veja o vídeo associado a esta prática no link presente na Figura 3.

3) O temporizador do alarme deve ser ajustado para um atraso de 3 segundos (3.000ms), entre os estados de acionamento dos LEDs.
4) A mudança de estado dos LEDs deve ser implementa em funções de call-back do temporizador, a exemplo da rotina trabalhada na aula síncrona - turn_off_callback().
5) O botão só pode alterar o estado dos LEDs quando o último LED for desligado. Deste modo, durante a execução das rotinas de temporização, o botão não pode iniciar uma nova chamada da função call-back.
6) Com o emprego da Ferramenta Educacional BitDogLab, faça um experimento com o código deste exercício utilizando o LED RGB – GPIOs 11, 12 e 13 e o Botão A, GPIO 05.
7) Opcional: Implementar uma rotina em software para atenuação do efeito bouncing no botão (software debounce). Destacamos aqui alguns passos necessários para este projeto.
   
• Deve-se utilizar o ambiente de desenvolvimento VS Code em todas as duas atividades;
• Os códigos devem ser escritos na linguagem C, juntamente com os recursos do Kit de Desenvolvimento de Software Pico SDK;
• O simulador Wokwi deve estar integrado ao ambiente de desenvolvimento VS Code;
• Deve-se criar um repositório no github para o versionamento, registro e submissão dessa atividade.

## 🛠 Tecnologias

1. **Git e Github**;
2. **VScode**;
3. **Linguagem C**;
4. **Software de emulação PuTTy. (Opcional para testes)**
5. **Extensões no VScode do Raspberry Pi Pico Project e CMake**
6. **Wokwi**;

## 🔧 Funcionalidades Implementadas:

O código implementa diversas funcionalidades utilizando os recursos do RP2040, incluindo controlo de LEDs, gestão de tempo com alarms, deteção de botões com interrupções, e comunicação serial. O SDK do Pico oferece uma variedade de bibliotecas que facilitam a interação com o hardware, incluindo GPIOs, timers, e periféricos. As funcionalidades principais implementadas incluem:

•Controlo de LEDs via GPIO: O código inicializa e configura pinos GPIO como saídas para controlar LEDs. Especificamente, pinos GPIO 11, 12, e 13 são usados para controlar LEDs azul, vermelho e verde, respetivamente. A função gpio_put() é utilizada para ligar ou desligar os LEDs. O RP2040 permite conectar periféricos internos aos pinos GPIO ou controlá-los diretamente via software. Cada pino GPIO pode ser configurado para diversas funções, incluindo SPI, I2C, UART, PWM, ou como GPIO genérico. A função gpio_set_function() no SDK garante que o pad esteja configurado para a função desejada.

A função gpio_init() inicializa os GPIOs e a função gpio_set_dir(gpio, GPIO_OUT) define-os como saídas.

A função gpio_put(gpio, value) é utilizada para ligar (1) ou desligar (0) os LEDs.

•Botão de Entrada e Interrupções: O código configura um pino GPIO como entrada para detetar o acionamento de um botão. Especificamente, o pino GPIO 5 é usado para ler o estado do botão. A função gpio_pull_up(BUTTON) ativa o pull-up interno para evitar leituras flutuantes quando o botão não está pressionado. Uma interrupção é configurada para ser acionada quando o botão é pressionado (queda na borda) usando gpio_set_irq_enabled_with_callback(). Quando a interrupção ocorre, a função button_callback() é chamada. Os pinos GPIO podem ser usados para acionar interrupções, permitindo uma resposta assíncrona a eventos.
◦
A função gpio_init() inicializa o GPIO e a função gpio_set_dir(BUTTON, GPIO_IN) define-o como entrada.
◦
A função gpio_pull_up(BUTTON) ativa o pull-up interno para evitar leituras flutuantes quando o botão não está pressionado.
•
Alarms e Callbacks: O código utiliza alarms e callbacks para controlar a sequência de desligamento dos LEDs. A função add_alarm_in_ms() configura um alarm para chamar uma função de callback após um certo número de milissegundos. As funções turn_off_blue_callback(), turn_off_red_callback(), e turn_off_green_callback() são callbacks que são executados após um tempo específico definido pelo alarm. A biblioteca pico_time oferece funções para criar timestamps, colocar o microcontrolador em sleep, usar alarms, e usar temporizadores repetitivos.
◦
A função add_alarm_in_ms() configura um alarm para chamar uma função de callback após um certo número de milissegundos.

turn_off_blue_callback() desliga o LED azul e configura um alarm para desligar o LED vermelho após 3000 ms, chamando turn_off_red_callback().

turn_off_red_callback() desliga o LED vermelho e configura um alarm para desligar o LED verde após 3000 ms, chamando turn_off_green_callback().

turn_off_green_callback() desliga o LED verde e redefine a flag led_sequence_active para false, permitindo que a sequência seja iniciada novamente.
•
Controlo de Fluxo e Estado: O programa utiliza um loop while(1) para executar indefinidamente. A função sleep_ms(100) pausa o loop principal por 100 milissegundos. Uma flag volátil led_sequence_active é usada para controlar se a sequência de LEDs está ativa, impedindo múltiplas ativações da sequência durante a execução da mesma.

O loop while(1) garante que o código continue a executar indefinidamente.
◦
A função sleep_ms(100) pausa o loop principal por 100 milissegundos.
•
Debounce do Botão: O código inclui uma função debounce_button() para tratar o efeito de debounce do botão, embora não seja utilizada no callback. A função utiliza sleep_ms(50) para aguardar um curto período de tempo e verificar o estado do botão, retornando true apenas se o botão permanecer pressionado após o atraso.
•
Comunicação Serial: Embora não haja código de comunicação serial diretamente neste código, a função stdio_init_all() é incluída, que inicializa a comunicação serial, permitindo que o programa exiba mensagens através do terminal. A biblioteca pico_stdio oferece suporte para entrada e saída através de UART, USB ou semi-hosting.
Em resumo, o código demonstra o uso de GPIOs para controlo de LEDs e deteção de botões, alarms e callbacks para temporização e sequências de LEDs, interrupções para resposta a eventos, e o uso de funções de sleep para pausa na execução. O SDK do Pico oferece diversas bibliotecas para facilitar a interação com o hardware e criar aplicações complexas.
## 💻 Desenvolvedores
 
<table>
  <tr>
    
<td align="center"><img style="" src="https://avatars.githubusercontent.com/u/96251377?v=4" width="100px;" alt=""/><br /><sub><b> Moises Amorim </b></sub></a><br />👨‍💻</a></td>

  </tr>
</table>


## 🎥 Demonstração: 

<div align="center">
  <figure>  
    
    
<figcaption>

**Figura 1** - Demo do Projeto no Wokwi.com - Acessível em: https://wokwi.com/projects/421471551935887361
    </figcaption>
  </figure>
</div>
 
 
