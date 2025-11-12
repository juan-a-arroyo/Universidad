void setup(){
  size(620,389);
  fill(#FA5025);
}

int x = 0, y = 0, inc_x = 1, inc_y = 1;

void draw(){
  float ancho = 100, alto = 50;
  if(x>width||x<0)
    inc_x*=-1;
  if(y>height||y<0)
    inc_y*=-1;
  point(x+=inc_x,y+=inc_y);
  dibujaBoton(ancho, alto);
}

void mousePressed(){
   if(mouseX>=width/2-50 && mouseX<=width/2+50 && mouseY>=height-50 && mouseY<=height)
      fill(#FFFFFF);
   println(mouseX,mouseY); 
    
}

void mouseClicked(){
    if(mouseX>=width/2-50 && mouseX<=width/2+50 && mouseY>=height-50 && mouseY<=height)
      noLoop();
}

void mouseReleased(){
  fill(#FA5025);
}

void dibujaBoton(float ancho, float alto){
  fill(#000000);
  rect(width/2-ancho/2+4,height-alto+4-10,ancho,alto);
  fill(#FA5025);
  rect(width/2-ancho/2,height-alto-10,ancho,alto);
}
