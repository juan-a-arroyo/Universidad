void setup(){
  size(620,389);
}

int x = 0, y = 0, inc_x = 1, inc_y = 1;

void draw(){
  if(x>width||x<0)
    inc_x*=-1;
  if(y>height||y<0)
    inc_y*=-1;
  point(x+=inc_x,y+=inc_y);
  //println(x, y);
}

void mousePressed(){
  noLoop();
  println(mouseX,mouseY);
}

void mouseClicked(){
  
}

void mouseReleased(){
  loop();
}
