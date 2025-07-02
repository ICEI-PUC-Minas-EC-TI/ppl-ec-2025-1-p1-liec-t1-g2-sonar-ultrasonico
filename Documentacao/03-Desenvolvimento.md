
# Materiais
Os materiais utilizados no projeto foram:

1 placa Arduino UNO (simulado via Tinkercad);
1 sensor ultrassônico HC-SR04;
1 LED vermelho (indica obstáculo detectado);
1 LED verde (indica caminho livre);
2 resistores de 220Ω;
1 buzzer (ativo);
Jumpers (fios de conexão);
Garrafa PET (estrutura do submarino);
Cola quente e fita adesiva;
Software Arduino IDE;
Plataforma Tinkercad (simulação do circuito);
MIT App Inventor (desenvolvimento do aplicativo);
Cabo USB (para alimentação e testes físicos).

# Desenvolvimento



## Desenvolvimento do Aplicativo

### Interface
Interface
A interface foi criada no MIT App Inventor, com o objetivo de permitir a visualização dos dados captados pelo sensor ultrassônico de forma simples e intuitiva. A tela principal contém:

Um botão para conectar ao módulo Bluetooth (simulado);
Um campo de texto que exibe a distância detectada pelo sensor em tempo real;
Um indicador visual (imagem ou mudança de cor) que informa se há ou não um obstáculo próximo;
Mensagens de alerta que mudam dinamicamente com base na distância recebida.
O layout foi pensado para ser funcional em dispositivos Android, com foco em acessibilidade e usabilidade.

### Código
A programação foi realizada com os blocos lógicos do App Inventor. As principais funções implementadas foram:

Estabelecimento da conexão Bluetooth entre o aplicativo e o Arduino;
Recebimento contínuo dos dados enviados pelo Arduino via comunicação serial;
Processamento e exibição desses dados na interface gráfica;
Troca de mensagens ou alertas visuais conforme o valor da distância (ex: "Caminho livre" ou "Obstáculo próximo").

## Desenvolvimento do Hardware

### Montagem

A estrutura foi construída reutilizando uma garrafa PET, representando o casco do submarino. O sensor ultrassônico foi fixado na parte frontal da garrafa, simulando o sonar de um submarino real. Os LEDs (vermelho e verde) foram posicionados na parte superior da garrafa, de forma visível, para indicar visualmente a presença ou ausência de obstáculos.

O LED verde acende quando não há obstáculo próximo (distância segura);
O LED vermelho acende quando há um obstáculo detectado (distância abaixo do limite);
O buzzer emite som para reforçar a presença de obstáculo quando o LED vermelho estiver ativo.
Essa montagem foi primeiro testada no Tinkercad, garantindo que os componentes funcionassem corretamente antes da montagem física.

### Desenvolvimento do Código

O código do Arduino foi responsável por:

Ler a distância com o sensor HC-SR04;
Ativar o LED verde quando a distância estiver segura (por exemplo, acima de 15 cm);
Ativar o LED vermelho e o buzzer quando a distância estiver abaixo do limite (por exemplo, menor que 15 cm);
Enviar os dados via Serial/Bluetooth para o aplicativo desenvolvido no App Inventor, utilizando comandos Serial.print().
if (distancia < 15) {
  digitalWrite(ledVermelho, HIGH);
  digitalWrite(ledVerde, LOW);
  digitalWrite(buzzer, HIGH);
} else {
  digitalWrite(ledVermelho, LOW);
  digitalWrite(ledVerde, HIGH);
  digitalWrite(buzzer, LOW);
}

## Comunicação entre App e Hardware

A comunicação entre o aplicativo e o Arduino foi simulada utilizando um módulo Bluetooth (como o HC-05) em conjunto com a interface do App Inventor. Essa integração permite que o app leia os dados transmitidos pelo Arduino e atualize a tela em tempo real.

O processo de comunicação envolveu as seguintes etapas:

Configuração do Arduino para enviar os dados de distância continuamente via Serial;
Pareamento do módulo Bluetooth com o celular Android;
Leitura dos dados no App Inventor, utilizando blocos de leitura serial Bluetooth;
Atualização da interface com base nos dados recebidos, exibindo mensagens como “Caminho livre” ou “Obstáculo próximo” de acordo com a distância.
Essa etapa foi fundamental para integrar o hardware com o aplicativo, proporcionando uma solução funcional, educativa e interativa.


