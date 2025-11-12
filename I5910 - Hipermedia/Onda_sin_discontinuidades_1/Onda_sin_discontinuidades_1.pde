void setup(){
   size(800,400);
   stroke(#011196);
}

float x = 0, y = 0, inc = 0.0001;
int z;

void draw(){
   z = int(height/2+sin(y)*100);
   point(x, z);
   for(int i = z; i<=int(height/2+sin(y+inc)*100); i++)
     point(x,i);
   for(int i = int(height/2+sin(y+inc)*100); i<=z; i++)
     point(x,i);
   y+=inc;
   x+=1;
}
