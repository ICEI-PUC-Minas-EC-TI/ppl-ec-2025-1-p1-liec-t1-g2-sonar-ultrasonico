import processing.serial.*;

Serial porta;

float angulo = 0;
float distancia = 0;
PFont fonte;

void setup() {
  size(800, 400);
  porta = new Serial(this, Serial.list()[0], 9600); // Ajuste a porta se necessário
  porta.bufferUntil('\n');
  fonte = createFont("Arial", 12, true);
}

void draw() {
  background(0);
  translate(width/2, height); // Origem embaixo no centro

  stroke(0, 255, 0);
  noFill();
  arc(0, 0, 600, 600, PI, TWO_PI);  // Semicírculo de fundo
  arc(0, 0, 400, 400, PI, TWO_PI);  // Distância intermediária
  arc(0, 0, 200, 200, PI, TWO_PI);  // Distância próxima

  // Linhas de varredura e marcadores de ângulo
  for (int a = 0; a <= 180; a += 30) {
    float rad = radians(a);
    float x = cos(rad - PI) * 300;
    float y = sin(rad - PI) * 300;
    stroke(50, 255, 50, 100);
    line(0, 0, x, y);
    fill(255);
    textFont(fonte);
    textAlign(CENTER);
    text(a + "°", x, y + 15);
  }

  // Linha de varredura atual
  float angRad = radians(angulo);
  float linhaX = cos(angRad - PI) * 300;
  float linhaY = sin(angRad - PI) * 300;
  stroke(0, 255, 0);
  line(0, 0, linhaX, linhaY);

  // Ponto do obstáculo
  if (distancia > 0 && distancia <= 400) {
    float r = map(distancia, 0, 100, 0, 300); // distância convertida
    float x = cos(angRad - PI) * r;
    float y = sin(angRad - PI) * r;
    fill(255, 0, 0);
    noStroke();
    ellipse(x, y, 8, 8);
  }
}

void serialEvent(Serial p) {
  String entrada = p.readStringUntil('\n');
  if (entrada != null) {
    entrada = trim(entrada);
    String[] partes = split(entrada, ":");
    if (partes.length == 2) {
      angulo = float(partes[0]);
      distancia = float(partes[1]);
    }
  }
}
