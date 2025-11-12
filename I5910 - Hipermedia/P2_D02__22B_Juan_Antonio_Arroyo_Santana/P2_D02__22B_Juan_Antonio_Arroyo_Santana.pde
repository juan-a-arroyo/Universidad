void setup(){
  size(620,389);
}

int x = 0, y = 0, inc_x = 1, inc_y = 1;
boolean pausa;
float ancho = 100, alto = 50;

void draw(){
  pausa = false;
  if(x>width||x<0)
    inc_x*=-1;
  if(y>height||y<0)
    inc_y*=-1;
  point(x+=inc_x,y+=inc_y);
  dibujaBoton(false);
}

void mousePressed(){
   if(mouseX>=width/2-50 && mouseX<=width/2+50 && mouseY>=height-60 && mouseY<=height-10){
     dibujaBoton(true);
     noLoop();
   }
}

void mouseClicked(){
}

void mouseReleased(){
  dibujaBoton(false);
  loop();

}

void dibujaBoton(boolean pressed){
  if(pressed){
    fill(#000000);
    rect(width/2-ancho/2,height-alto-10,ancho,alto);
    fill(#011196);
    rect(width/2-ancho/2+2,height-alto+2-10,ancho,alto);
    fill(#FFFFFF);
    rect(width/2-32+2,height-alto+5+2,7,20);
    rect(width/2-18+2,height-alto+5+2,7,20);
    triangle(width/2+10,height-alto+6,width/2+10,height-alto+25+3,width/2+32,height-alto-10+25+2);
    stroke(#FFFFFF);
    line(width/2-5,height-alto+30,width/2+5,height-alto+2);
    stroke(#000000);
  }
  else{
    fill(#000000);
    rect(width/2-ancho/2+2,height-alto+2-10,ancho,alto);
    fill(#FFFFFF);
    rect(width/2-ancho/2,height-alto-10,ancho,alto);
    fill(#000000);
    rect(width/2-32,height-alto+5,7,20);
    rect(width/2-18,height-alto+5,7,20);
    triangle(width/2+10,height-alto+4,width/2+10,height-alto+25+1,width/2+32,height-alto-10+25);
    line(width/2-5,height-alto+28,width/2+5,height-alto);
  }
}
