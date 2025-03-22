# **Lumisound: Sinfonia Interativa - Controle de LED RGB e Buzzer com Raspeberry Pi Pico W, Placa BitDogLab**

## **Introdução**
O **Lumisound: Sinfonia Interativa** é um projeto interativo que combina efeitos visuais e sonoros utilizando a Raspberry Pi Pico W integrada à Placa BitDogLab. Este sistema permite:

- **Modo Básico:** Alternar cores em um LED RGB e reproduzir tons diatônicos correspondentes através de um buzzer, acionado por botões de pressão.
- **Modo Melódico:** Detectar pressionamento prolongado (>1 segundo) dos botões para reproduzir melodias predefinidas:
  - **Botão A:** Reproduz a melodia de *Super Mario Bros* com LED fixo na cor vermelha.
  - **Botão B:** Reproduz a melodia tema de *Game of Thrones* com LED fixo na cor amarela.

Essas funcionalidades ampliam as possibilidades de uso do sistema em aplicações educacionais, interativas e assistivas

## **Materiais Necessários**
- Placa BitDogLab
- Fonte de alimentação (cabo USB ou bateria integrada)

*Todos os componentes necessários para a execução do seguinte projeto já são nativos da própria placa BitDogLab.*

## **Conexão do Circuito**
A tabela a seguir descreve as conexões entre os componentes e os pinos da Raspberry Pi Pico W:

| Componente  | Pino da Raspberry Pi Pico W |
|------------|---------------------------|
| LED Vermelho | GP13 |
| LED Verde | GP11 |
| LED Azul | GP12 |
| Botão A | GP5 |
| Botão B | GP6 |
| Buzzer | GP21 |

*Bibliotecas utilizadas: stdio.h, pico/stdlib.h, hardware/gpio.h e stdbool.h*

## **Etapas de Construção e Elaboração**
### **1. Planejamento e Escolha das Funcionalidades**
A escolha das funcionalidades foi baseada na ideia de criar um sistema interativo simples, porém eficiente, utilizando somente os recursos disponíveis da placa BitDogLab. A combinação entre o LED RGB e o buzzer permite não apenas um feedback visual, mas também auditivo, tornando o projeto versátil para aplicações educativas e lúdicas.

### **2. Desenvolvimento do Código**
O código foi escrito em linguagem C utilizando o SDK da Raspberry Pi Pico W. A implementação inclui:
- **Configuração dos GPIOs**: Definição dos pinos de entrada e saída.
- **Controle dos LEDs**: Alternância e combinação de cores conforme a interação com os botões.
- **Geração de Som**: O buzzer é ativado com frequências específicas para cada cor, respondendo a escala diatônica, além da emissão das melodias correspondentes associadas.
- **Leitura dos Botões**: Uso de interrupções ou polling para detectar pressionamentos, a partir disso, identificar e distinguir entre pressionameto curto (reprodução da nota individualmente) ou pressionamento longo (reprodução melódica).

## **Funcionamento do Projeto**
Inicialização do sistema e configuração dos pinos GPIO.

### Modo Básico (Curto Pressionamento)
- **Botão A:** Avança para a próxima cor na sequência (Vermelho, Verde, Azul, Amarelo, Ciano, Magenta, Branco) e reproduz o tom correspondente.
- **Botão B:** Retorna para a cor anterior, emitindo o som associado.

As seguintes notações representam as respectivas cores associadas a cada nota musical:

- **Frequência do som para o LED Vermelho (Dó)**
- **Frequência do som para o LED Verde (Ré)**
- **Frequência do som para o LED Azul (Mi)**
- **Frequência do som para o LED Amarelo (Fá)**
- **Frequência do som para o LED Ciano (Sol)**
- **Frequência do som para o LED Magenta (Lá)**
- **Frequência do som para o LED Branco (Si)**

As cores seguem a sequência: Vermelho, Verde, Azul, Amarelo, Ciano, Magenta e Branco, cada uma associada a uma frequência sonora.

### Modo Melódico (Pressionamento Prolongado, >1s)
- **Botão A:** Ao manter pressionado, aciona a reprodução da melodia de *Super Mario Bros* e fixa o LED na cor vermelha.
- **Botão B:** Ao manter pressionado, aciona a reprodução da melodia tema de *Game of Thrones* e fixa o LED na cor amarela.

*Nota:* As melodias foram simplificadas para melhor gerenciamento do código, focando nas partes principais para reconhecimento auditivo.

---

## **Processos de Execução**
1. Conecte a placa BitDogLab ao computador via USB.
2. Compile o código utilizando o SDK do Raspberry Pi Pico W.
3. Carregue o arquivo binário na placa.
4. O sistema iniciará automaticamente, permitindo a mudança de cores e a reprodução dos sons ao pressionar os botões, identificando os dois modos, individual e melódico.

## **Justificativas das Escolhas**
- **LED RGB**: Proporciona um impacto visual interativo ao projeto.
- **Buzzer Passivo**: Permite o controle da frequência sonora, associando sons específicos a cada cor.
- **Botões de Pressão**: Garantem uma interação simples e eficiente com o sistema.

## **Conclusão**
**Lumisound: Sinfonia Interativa** demonstra a eficácia de integrar feedbacks visuais e sonoros em sistemas embarcados. Seu design modular e a utilização de arrays em estrutura para definição das melodias facilitam futuras expansões e personalizações, tornando-o uma excelente ferramenta para aplicações educacionais, de acessibilidade e entretenimento.

Este sistema pode ser aplicado em contextos educativos, de acessibilidade e entretenimento, servindo como base para futuras melhorias e personalizações. 🚀

Link para o vídeo demonstrativo: https://drive.google.com/file/d/1NvY6pknxNDp3-oRLGSkHFGcGUOPrfZs2/view?usp=sharing

