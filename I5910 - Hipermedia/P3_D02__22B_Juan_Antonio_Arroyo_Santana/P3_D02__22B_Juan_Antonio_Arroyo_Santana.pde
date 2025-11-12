void setup(){
   size(800,400);
   dibujaBotonMasMenos(false);
}

float x = 0, y = 0, inc = 0.1, ancho = 100, alto = 50;;
int z, incrx = 1, amplitud = 10, r, g, b;

void draw(){
   z = int(height/2+sin(y)*amplitud);
   point(x, z);
   for(int i = z; i<=int(height/2+sin(y+inc)*amplitud); i++)
     point(x,i);
   for(int i = int(height/2+sin(y+inc)*amplitud); i<=z; i++)
     point(x,i);
   y+=inc;
   x+=incrx;
   if(x >= width || x <= 0){
     incrx*=-1;
     r = int(random(255));
     g = int(random(255));
     b = int(random(255));
     stroke(r, g, b);
   }
   dibujaBotonPausa(false);
}

void mousePressed(){
   if(mouseX>=width/2+10 && mouseX<=width/2+110 && mouseY>=height-60 && mouseY<=height-10){
     dibujaBotonPausa(true);
     noLoop();
   }
   if(mouseX>=width/2-110 && mouseX<=width/2-10 && mouseY>=height-60 && mouseY<=height-10){
     dibujaBotonMasMenos(true);
   }
}

void mouseClicked(){
  if(mouseX>=width/2-110 && mouseX<=width/2-10 && mouseY>=height-60 && mouseY<=height-10 && mouseButton == RIGHT){
     if(amplitud <= 0)
       amplitud = 0;
     else
       amplitud -= 10;
   }
  if(mouseX>=width/2-110 && mouseX<=width/2-10 && mouseY>=height-60 && mouseY<=height-10 && mouseButton == LEFT){
     if(amplitud >= 150)
       amplitud = 150;
     else
       amplitud += 10;
   }
}

void mouseReleased(){
  loop();
  dibujaBotonPausa(false);
  dibujaBotonMasMenos(false);

}

void dibujaBotonPausa(boolean pressed){
  if(pressed){
    stroke(#000000);
    fill(#000000);
    rect(width/2+10,height-alto-10,ancho,alto);
    fill(#011196);
    rect(width/2+12,height-alto+2-10,ancho,alto);
    fill(#FFFFFF);
    rect(width/2-32+2+60,height-alto+5+2,7,20);
    rect(width/2-18+2+60,height-alto+5+2,7,20);
    triangle(width/2+10+60,height-alto+6,width/2+10+60,height-alto+25+3,width/2+32+60,height-alto-10+25+2);
    stroke(#FFFFFF);
    line(width/2-5+60,height-alto+30,width/2+5+60,height-alto+2);
    stroke(r,g,b);
  }
  else{
    stroke(#000000);
    fill(#000000);
    rect(width/2+12,height-alto+2-10,ancho,alto);
    fill(#FFFFFF);
    rect(width/2+10,height-alto-10,ancho,alto);
    fill(#000000);
    rect(width/2-32+60,height-alto+5,7,20);
    rect(width/2-18+60,height-alto+5,7,20);
    triangle(width/2+10+60,height-alto+4,width/2+10+60,height-alto+25+1,width/2+32+60,height-alto-10+25);
    line(width/2-5+60,height-alto+28,width/2+5+60,height-alto);
    stroke(r,g,b);
  }
}

void dibujaBotonMasMenos(boolean pressed){
  if(pressed){
    stroke(#000000);
    fill(#000000);
    rect(width/2-110,height-alto-10,ancho,alto);
    fill(#011196);
    rect(width/2-108,height-alto+2-10,ancho,alto);
    fill(#FFFFFF);
    stroke(#FFFFFF);
    strokeWeight(5);
    line(width/2-80-10,height-alto+15,width/2-80+10,height-alto+15);
    line(width/2-40-10,height-alto+15,width/2-40+10,height-alto+15);
    line(width/2-40,height-alto+15+10,width/2-40,height-alto+15-10);
    strokeWeight(1);
    line(width/2-5-60,height-alto+30,width/2+5-60,height-alto+2);
    stroke(r,g,b);
  }
  else{
    stroke(#000000);
    fill(#000000);
    rect(width/2-108,height-alto+2-10,ancho,alto);
    fill(#FFFFFF);
    rect(width/2-110,height-alto-10,ancho,alto);
    fill(#000000);
    strokeWeight(5);
    line(width/2-80-10,height-alto+15,width/2-80+10,height-alto+15);
    line(width/2-40-10,height-alto+15,width/2-40+10,height-alto+15);
    line(width/2-40,height-alto+15+10,width/2-40,height-alto+15-10);
    strokeWeight(1);
    line(width/2-5-60,height-alto+28,width/2+5-60,height-alto);
    stroke(r,g,b);
  }
}
