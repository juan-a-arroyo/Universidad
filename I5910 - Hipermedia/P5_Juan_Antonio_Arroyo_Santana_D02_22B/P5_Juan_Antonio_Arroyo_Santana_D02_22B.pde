PImage fondo, pelota;

void setup(){
  size(800,600);
  fondo = loadImage("cancha.jpg");
  pelota = loadImage("balon.png");
}

int x = 25, inc_x = 5, inc_y = 1, aux_x, aux_y;
float y = 0.0, z;
boolean pausa = false;

void draw(){
  imageMode(CORNER);
  image(fondo, 0,0,width,height); 
  imageMode(CENTER);
  z = 300-sin(y)*200;
  image(pelota,x,z,50,50);
  if(x >= width-25 || x < 25){
    inc_x*=-1;
    inc_y*=-1;
  }
  x+=inc_x;
  y += 0.021*inc_y;
}

void mouseClicked(){
  if(dist(mouseX, mouseY, x, z) <= 25 && pausa == true){
    inc_x = aux_x;
    inc_y = aux_y;
    pausa = false;
    return;
  }
  if(dist(mouseX, mouseY, x, z) <= 25 && pausa == false){
    aux_x = inc_x;
    inc_x = 0;
    aux_y = inc_y;
    inc_y = 0;
    pausa = true;
  }
}
