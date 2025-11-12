void setup(){
  size(800,200);
  background(0,0,0);
}

void draw(){
  stroke(255,255,255);
  float relacion = 0.0;
  if(height>width){
    relacion = (float)width/height;
    for(int i=0;i<=height;i++){
      point(i*relacion,i);
      point((height-i)*relacion,i);}}
  else{
    relacion = (float)height/width;
    for(int i=0;i<=width;i++){
      point(i,i*relacion);
      point(i,(width-i)*relacion);}}
}
