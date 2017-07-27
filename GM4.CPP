#include<iostream.h>
#include<stdlib.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
void addSound(int x);
 void hold();
 void clr();
 void  resetAll();
  void write(int,int,char *,int);
  void writeName();
  void drawStart();
  void drawFinish();
  void moveCar();
 int Movobs(int,int,int,int);
     int movOb1(int,int,int,int);
     int movOb2(int,int,int,int);
     int movOb3(int,int,int,int);
     int movOb4(int,int,int,int);
     int movOb5(int,int,int,int);
     int movOb6(int,int,int,int);
     int callOb(int,int,int,int);
     int restart=0;
void main(){
    clr();
    write(50,70,"WELCOME TO",0);
    write(50,70,"TURBO TRAFFIC RACING GAME",0);
    moveCar();
    int xm=250,x1=245,x2=255,y1=345,y2=365,over=0;
    char ch;

  for(;(y1>=25&& over!=1);)
     {  //for road
	clr(); addSound(50);
	setcolor(RED);
				   settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);

	line(200,50,200,340);     outtextxy(250,20,"FINISH"); outtextxy(250,350,"START");
	line(300,50,300,340);
	line(203,50,203,340);
	line(303,50,303,340);

	line(200,50,302,50);  line(200,60,302,60);
	line(200,340,302,340); line(200,330,302,330);

	// for flags1
	setcolor(RED);
	line(200,50,200,30);
	line(202,50,202,30);
	setcolor(GREEN);
	line(200,30,215,35);
	line(215,35,200,40);

	// for flags2
	setcolor(BLACK);
	line(300,50,300,30);
	line(302,50,302,30);
	setcolor(GREEN);
	line(300,30,285,35);
	line(285,35,300,40);

	 //for car
	   over=callOb(x1,x2,y1,y2);
	    setcolor(BLACK);
	    line(x1,y1,x2,y1);
	    line(x2,y1,x2,y2);
	    line(x2,y2,x1,y2);
	    line(x1,y2,x1,y1);

	    line(x1,y1-2,x2,y1-2);
	    setcolor(RED);

	    for(int j=x1+2;j<=x2-2;j++){
	     line(j,y1+2,j,y2-2);
	      }

	    if(over!=1)
	    cin>>ch;

		//for forward movemant
		  if(ch=='w')
		   { y1=y1-5;
		     y2=y2-5;
		    }

	       //for left movemant
		else if(ch=='a'&&x1>205){
		  x1=x1-5; x2=x2-5;
		  }

		//for right movemant
		else if(ch=='d'&&x2<295){
		  x1=x1+5; x2=x2+5;
		  }
		//for down movemant
		else if(ch=='s')
		{
		  y1=y1+10;
		  y2=y2+10;

		}

		     y1=y1-5;
		     y2=y2-5;
		     xm=xm-5;

     }//loop
      clr();

     if(over!=1)
       {
	 write(50,50,"YOU WIN",0);
	}

      if(ch=='y')
      { restart=0;
	main();
	}
      else{
	write(50,50," EXIT ",0);
	}

 }//main


 void addSound(int x)
 {
   sound(100*random(10));
   delay(x);
   nosound();
  }


 void clr()
 {
  clrscr();
  }


 void hold()
  { getch();
   }


 int k=0;
   //write
 void write(int xm,int ym,char *str,int g)
  {
    if(restart==0)
    {
      int gd=DETECT,gm;
      initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
      restart++;
      }
       highvideo();
       clr();

      settextjustify(CENTER_TEXT,CENTER_TEXT); xm=getmaxx()/2;
      settextstyle(SANS_SERIF_FONT,HORIZ_DIR,3);

      ym=getmaxy()/2-50; int x=1000;

      if(g==1)
	x=300; int j=1;

      if(k==0)
      {
       setcolor(RED);
	 outtextxy(getmaxx()/2,50,"COMPUTER GRAPHICS PROJECT BY:");
	 outtextxy(getmaxx()/2,100,"LUCKY BARKANE ");
	 outtextxy(getmaxx()/2,150,"ALAY JAIN (13C4120)");
	 outtextxy(getmaxx()/2,200,"AYUSH KUMAR (13C41)");
	 outtextxy(getmaxx()/2,250,"ASHISH SINGH (13C41)");
	 getch();
	 clr();
	 k++;
     }

   for(int i=0;i<10;i++)
   {
       if(j==1)
       {
	setcolor(RED); j=2;
	}
       else if(j==2) {
	 setcolor(BLUE); j=1;}

       outtextxy(xm,ym,str);
	     addSound(250);
       }//loop

   if(g==1)
    getch();
}


int x1=500,x2=580,y1=120,y2=130;
void moveCar(){
	   clr();
      int x1,y1,x2,y2; x1=500;
		     x2=580;  y1=120; y2=130;

	     for(int i=0;i<=46;i++){
	     clr();
	     setcolor(RED);
	   //road
	     line(30,70,getmaxx()-10,70); line(30,150,getmaxx()-10,150);
	     line(27,67,getmaxx()-13,67); line(27,153,getmaxx()-13,153);
	    //car
	     if(i%2!=0)
	      setcolor(BLUE);
	      else
	      setcolor(RED);

	      //road
	     line(30,70,getmaxx()-10,70); line(30,150,getmaxx()-10,150);
	     line(27,67,getmaxx()-13,67); line(27,153,getmaxx()-13,153);

	    line(x1,y1+5,x2,y1-20);        line(x2,y1-16,x2+15,y1-16);
	    line(x1,y1+5,x1,y2);           line(x2+15,y1-16,x2+15,y1-6);       line(x2+15,y1-6,x2,y1-6);
	    line(x2,y2,x2,y1-20);
	    line(x1,y2,x2,y2);

	    setcolor(BLACK);  circle(x1+20,y2,5); circle(x2-10,y2,5);
	      /*smoke*/line(x2+16,y1-14,x2+19,y1-14); line(x2+16,y1-12,x2+19,y1-12);
		 x1=x1-10; x2=x2-10;
		 if(x1==30){
		   x1=500, x2=580;
		  }
		     sleep(.8);
		  addSound(80);

		  }//for1

		   settextstyle(SANS_SERIF_FONT,HORIZ_DIR,10);
		   setcolor(RED);

		    outtextxy(290,230,"Start.....");
			addSound(250);
			getch();
	}
   // call the obstacles
  int callOb(int x1,int x2,int y1,int y2)
  {
    int  over;
    over =  movOb1(x1,x2,y1,y2);

     if(over!=1)
      { over =  movOb2(x1,x2,y1,y2); }

    if(over!=1)
     { over= movOb3(x1,x2,y1,y2);  }

    if(over!=1)
     { over= movOb4(x1,x2,y1,y2);  }

    if(over!=1)
     { over = movOb5(x1,x2,y1,y2); }

     if(over!=1)
      { over =  movOb6(x1,x2,y1,y2);  }

      if(over==1){
       write(50,50,"GAME OVER",0) ;
      }
      return over;
  }

 int x01=250,x02=260,y01=140,y02=160;
 int movOb1(int x1,int x2,int y1,int y2)
 {
	if( (x2>x01 && y1<y02 && y2>y01 && x1<x01) || (x1<x02 && y1<y02 && y2>y01 && x2>x01) )
	{
	 return 1;
	}
	   setcolor(BLUE);
       if(y02<=322)
	 {

	    line(x01,y01,x02,y01);
	    line(x02,y01,x02,y02);
	    line(x02,y02,x01,y02);
	    line(x01,y02,x01,y01);

	    line(x01,y02+2,x02,y02+2);

	      for (int j=x01+2;j<=x02-2;j++)
		 { setcolor(RED);
		   line(j,y01+2,j,y02-2);}
	    }
	     y02=y02+5; y01=y01+5;
      return 0;
  }


int x11=270,x12=280,y11=220,y12=240;
int movOb2(int x1,int x2,int y1,int y2)
{

	if( (x2>x11 && y1<y12 && y2>y11 && x1<x11) || (x1<x12 && y1<y12 && y2>y11 && x2>x11) )
	{  return 1;
	}

	  setcolor(BLUE);
	if(y12>=322)
	 {  line(x11,y11,x12,y11);
	    line(x12,y11,x12,y12);
	    line(x12,y12,x11,y12);
	    line(x11,y12,x11,y11);

	    line(x11,y12+2,x12,y12+2);

	    y12=y12+5; y11=y11+5;

	      for (int j=x11+2;j<=x12-2;j++)
		 { setcolor(RED);
		   line(j,y11+2,j,y12-2);}
	    }


	    return 0;
}

int x31=270,x32=280,y31=5,y32=25;
int movOb3(int x1,int x2,int y1,int y2){


	if( (x2>x31 && y1<y32 && y2>y31 && x1<x31) || (x1<x32 && y1<y32 && y2>y31 && x2>x31) )
	{  return 1;
	 }
	setcolor(BLUE);
	if(y32<=322&&y31>=50)
	 {  line(x31,y31,x32,y31);
	    line(x32,y31,x32,y32);
	    line(x32,y32,x31,y32);
	    line(x31,y32,x31,y31);

	    line(x31,y32+2,x32,y32+2);

	      for (int j=x31+2;j<=x32-2;j++)
		 { setcolor(RED);
		   line(j,y31+2,j,y32-2);}
	    }



	     y32=y32+5; y31=y31+5;
	       return 0;
}

int x41=215,x42=225,y41=70,y42=90;
int movOb4(int x1,int x2,int y1,int y2){


	if( (x2>x41 && y1<y42 && y2>y41 && x1<x41) || (x1<x42 && y1<y42 && y2>y41 && x2>x41) )
	{   return 1;
	}

   setcolor(BLUE);
	if(y42<=322)
	 {  line(x41,y41,x42,y41);
	    line(x42,y41,x42,y42);
	    line(x42,y42,x41,y42);
	    line(x41,y42,x41,y41);

	    line(x41,y42+2,x42,y42+2);


	      for (int j=x41+2;j<=x42-2;j++)
		 { setcolor(RED);
		   line(j,y41+2,j,y42-2);}


	    }
	    y42=y42+5; y41=y41+5;

	    return 0;
}



int x51=215,x52=225,y51=-10,y52=10;
int movOb5(int x1,int x2,int y1,int y2){


	if( (x2>x51 && y1<y52 && y2>y51 && x1<x51) || (x1<x52 && y1<y52 && y2>y51 && x2>x51) )
	{   return 1;
	}

	setcolor(BLUE);
	if(y52!=322&&y51>=50)
	 {  line(x51,y51,x52,y51);
	    line(x52,y51,x52,y52);
	    line(x52,y52,x51,y52);
	    line(x51,y52,x51,y51);

	    line(x51,y52+2,x52,y52+2);


	      for (int j=x51+2;j<=x52-2;j++)
		 { setcolor(RED);
		   line(j,y51+2,j,y52-2);}
	    }


	    y52=y52+5; y51=y51+5;

	    return 0;
}


int x61=275,x62=285,y61=280,y62=300;
int movOb6(int x1,int x2,int y1,int y2){

	if( (x2>x61 && y1<y62 && y2>y61 && x1<x61) || (x1<x62 && y1<y62 && y2>y61 && x2>x61) )
	{   return 1;
	}

	  setcolor(BLUE);
	 if(y62<=400)
	 {  line(x61,y61,x62,y61);
	    line(x62,y61,x62,y62);
	    line(x62,y62,x61,y62);
	    line(x61,y62,x61,y61);

	    line(x61,y62+2,x62,y62+2);


	      for (int j=x61+2;j<=x62-2;j++)
		 { setcolor(RED);
		   line(j,y61+2,j,y62-2);}
	    }


	 y62=y62+5; y61=y61+5;

       return 0;
}

void resetAll(){
int x01=250,x02=260,y01=140,y02=160;
int x11=270,x12=280,y11=220,y12=240;
int x31=270,x32=280,y31=5,y32=25;
int x41=215,x42=225,y41=70,y42=90;
int x51=215,x52=225,y51=-10,y52=10;
int x61=275,x62=285,y61=280,y62=300;

}                     getch();
