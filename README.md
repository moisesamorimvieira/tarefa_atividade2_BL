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

## Funcionalidades do Código

1. Controlo de LEDs via GPIO:
Configura pinos GPIO para controlar LEDs nos pinos 11, 12 e 13.
Utiliza gpio_put() para ligar e desligar os LEDs.

2. Botão de Entrada e Interrupções:
Usa o pino GPIO 5 para leitura do botão.
Configura interrupção para detecção do botão pressionado com gpio_set_irq_enabled_with_callback().

3. Alarms e Callbacks:
Utiliza add_alarm_in_ms() para configurar callbacks que controlam a sequência de desligamento dos LEDs.

4. Controlo de Fluxo e Estado:
Loop while(1) para execução contínua do programa.
Usa sleep_ms(100) para pausas no loop principal.

5. Debounce do Botão:
Função debounce_button() para lidar com o efeito de debounce do botão.

6. Comunicação Serial:
Inicialização da comunicação serial com stdio_init_all() para exibir mensagens no terminal.


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
 
 
