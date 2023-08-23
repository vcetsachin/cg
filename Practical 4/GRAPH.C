#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void bfill(int x,int y,int f_c,int b_c)
{
int current;
current= getpixel(x,y);
if(current !=b_c && current !=f_c)
{
putpixel(x,y,f_c);
bfill(x,y+1,f_c,b_c);
bfill(x,y-1,f_c,b_c);
bfill(x+1,y,f_c,b_c);
bfill(x-1,y,f_c,b_c);
}
}
void ffill(int x1,int y1,int o_c,int n_c)
{
int current;
current=getpixel(x1,y1);
if(current == o_c)
{
putpixel(x1,y1,n_c);
ffill(x1,y1+1,o_c,n_c);
ffill(x1,y1-1,o_c,n_c);
ffill(x1+1,y1,o_c,n_c);
ffill(x1-1,y1,o_c,n_c);
}
}
void main()
{
int gd=DETECT,gm,x,y,x1,y1,r;
printf("enter origin point for circle 1&2:");
scanf("%d%d%d%d", &x,&y,&x1,&y1);
printf("\n enter radius");
scanf("\n%d",&r);
initgraph(&gd,&gm,"..//bgi");
circle(x,y,r);
circle(x1,y1,r);
bfill(x,y,7,15);
ffill(x1,y1,0,2);
getch();
closegraph();
}