# **Lumisound: Controle de LED RGB e Buzzer com Raspberry Pi Pico W, Placa BitDogLab**

## **Introdução**
O **Lumisound** é um projeto interativo que combina efeitos visuais e sonoros utilizando a Raspberry Pi Pico W integrado à placa BitDogLab. O sistema permite alternar cores em um LED RGB e emitir sons correspondentes através de um buzzer, tudo controlado por dois botões físicos. Este projeto pode ser utilizado em aplicações como jogos, interfaces sonoras educativas e feedbacks visuais e auditivos.

## **Materiais Necessários**
- Placa BitDogLab
- Fonte de alimentação (cabo USB ou bateria integrada)

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

*Bibliotecas utilizadas: stdio.h, pico/stdlib.h e hardware/gpio.h*

## **Etapas de Construção e Elaboração**
### **1. Planejamento e Escolha das Funcionalidades**
A escolha das funcionalidades foi baseada na ideia de criar um sistema interativo simples, porém eficiente, utilizando somente os recursos disponíveis da placa BitDogLab. A combinação entre o LED RGB e o buzzer permite não apenas um feedback visual, mas também auditivo, tornando o projeto versátil para aplicações educativas e lúdicas.

### **2. Desenvolvimento do Código**
O código foi escrito em linguagem C utilizando o SDK da Raspberry Pi Pico W. A implementação inclui:
- **Configuração dos GPIOs**: Definição dos pinos de entrada e saída.
- **Controle dos LEDs**: Alternância e combinação de cores conforme a interação com os botões.
- **Geração de Som**: O buzzer é ativado com frequências específicas para cada cor, respondendo a escala diatônica.
- **Leitura dos Botões**: Uso de interrupções ou polling para detectar pressionamentos.

## **Funcionamento do Projeto**
1. Inicialização do sistema e configuração dos pinos GPIO.
2. O botão A altera a cor do LED RGB para a próxima cor no ciclo predefinido e emite o som correspondente.
3. As seguintes notações representam as respectivas cores associadas a cada nota musical:

- **Frequência do som para o LED Vermelho (Dó)**
- **Frequência do som para o LED Verde (Ré)**
- **Frequência do som para o LED Azul (Mi)**
- **Frequência do som para o LED Amarelo (Fá)**
- **Frequência do som para o LED Ciano (Sol)**
- **Frequência do som para o LED Magenta (Lá)**
- **Frequência do som para o LED Branco (Si)**

4. O botão B retorna para a cor anterior, emitindo o respectivo som.
5. As cores seguem a sequência: Vermelho, Verde, Azul, Amarelo, Ciano, Magenta e Branco, cada uma associada a uma frequência sonora.

## **Processos de Execução**
1. Conecte a placa BitDogLab ao computador via USB.
2. Compile o código utilizando o SDK do Raspberry Pi Pico W.
3. Carregue o arquivo binário na placa.
4. O sistema iniciará automaticamente, permitindo a mudança de cores e a reprodução dos sons ao pressionar os botões.

## **Justificativas das Escolhas**
- **LED RGB**: Proporciona um impacto visual interativo ao projeto.
- **Buzzer Passivo**: Permite o controle da frequência sonora, associando sons específicos a cada cor.
- **Botões de Pressão**: Garantem uma interação simples e eficiente com o sistema.

## **Conclusão**
O **Lumisound** demonstra como a combinação de um LED RGB e um buzzer pode criar uma experiência interativa envolvente. O projeto pode ser expandido com novos padrões de cores, reproduções personalizados e até mesmo integração com sensores adicionais para tornar a experiência ainda mais dinâmica.

Este sistema pode ser aplicado em contextos educativos, de acessibilidade e entretenimento, servindo como base para futuras melhorias e personalizações. 🚀

