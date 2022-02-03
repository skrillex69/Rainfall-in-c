/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.
a
*******************************************************************************/

#include <stdio.h>
#include<graphics.h>
#include <stdlib.h>

struct raindrop{int x1,y1,x2,y2,yspeed;}rain[10000];
int makerain(int numberofdrops){
	int i=0;
	for(i=0;i<=numberofdrops;i++){
		rain[i].yspeed=(rand() %(10 - 1 + 1)) + 1;
        rain[i].x1=(rand() %(700 - 10 + 1)) + 10;
        rain[i].y1=(rand() %(250- 1 + 1)) + 1;
        line(rain[i].x1,rain[i].y1 , rain[i].x1, rain[i].y1+20);
  	}
  	return numberofdrops;
}

void fallrain(int num){
    int i=0;
    int k=0;int j=0;
    int res1=0;
    int res2=0;
    
     while(k<500){
  for(i=0;i<=1000;i++){
      //delay(1);
      //int j=0;
      k=1;
      for(j=0;j<=num;j++){
      	res1=i+rain[j].y1;
      	  //rain[j].yspeed=(rand() %(200 - 1 + 1)) + 1;
          //line(rain[j].x1, (i+rain[j].y1 * rain[j].yspeed), rain[j].x1, (rain[j].y1+i * rain[j].yspeed));
          line(rain[j].x1, ((res1) * rain[j].yspeed), rain[j].x1, ((res1 )* rain[j].yspeed +20));
      }
      cleardevice();
      k++;
      if(i==700){
    	makerain(num);
    	fallrain(num);

      }
    
	}
      
  }
  
}
int main()
{
    //printf("Hello World");
    int gd = DETECT, gm;
    int i=0;
    int k=0;int j=0;
    int num;
    // initgraph initializes the graphics system
    // by loading a graphics driver from disk
    initgraph(&gd, &gm, "C:/tc/bgi");
    num=makerain(300);
    fallrain(num);
  
    getch();

    return 0;
}
