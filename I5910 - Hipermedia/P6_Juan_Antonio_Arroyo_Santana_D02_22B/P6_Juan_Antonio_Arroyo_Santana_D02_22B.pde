import processing.sound.*;
PImage fondo, pelota;
SoundFile rebote;

void setup(){
  size(800,600);
  fondo = loadImage("cancha.jpg");
  pelota = loadImage("balon.png");
  rebote = new SoundFile(this, "rebote.mp3");
}

float inc = 15, y, x = 1;
int lado = 1;
boolean acelerar = false, izq = true, pausa = false;

void draw(){
  y = -sin(x/240)*200;
  imageMode(CORNER);
  image(fondo, 0,0,width,height);
  imageMode(CENTER);
  image(pelota,x+25,275+y,50,50);
  if(x >= width-50 || x <= 0){
    inc*=-1;
    lado*=-1;
    rebote.play();
  }
  if(x <= width/2)
    izq = true;
  else
    izq = false;
  if(x >= width/2-7.5 && x <=width/2+7.5 || x >= width-50 && x <= width || x >= -50 && x <= 0){
     acelerar = !acelerar;
  }
  if(acelerar)
     inc+=0.03*lado;
  else
     inc-=0.03*lado;
  x+=inc;
  println(inc);
}

void mouseClicked(){
  if(dist(mouseX, mouseY, x+25, 275+y) <= 25 && pausa == false){
     noLoop();
     pausa = true;
     return;
  }
  if(dist(mouseX, mouseY, x+25, 275+y) <= 25 && pausa == true){
     loop();
     pausa = false;
  }
}
