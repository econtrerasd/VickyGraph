// ----------------------------------------------------
// Source Code for Resolution Independent Graphics Primitives & Vicky II Wrapper Functions
// Theoretically It Should Work on Foenix c256 U, Foenix C256 u+, FMX
// By Ernesto Contreras
// June 2022
// ----------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dma.h>
#include <time.h>
#include <math.h>
#include "support.h"
#include "vickyGraph.h"

// Demo Helper functions
int setupScreen(int mode);
void delay(int delay);
void shake(int repetitions);

// Global Variables that hold screen resolution / current bitmap page / maxVickyMemory 
long extern vickyResX;
long extern vickyResY;

// ----------------------
// Main demo 
// ----------------------

int main ()
{
  int xRndInit;
  int xRndMid;
  int xRndMid2;
  int xRndEnd;
  int yRndInit;
  int yRndMid;
  int yRndMid2;
  int yRndEnd;
  int colRnd;
  int c,d,e;
  char option;
  ANSIClrScr();

	if (setupScreen(1)==0)
	{
		ANSIClrScr();
		clrBitmap();
	   /*
		c=time(NULL);
		srand(c); */
		for (c=1;c<=90;c++)
		{
			printf ("sin (%d)=%f\r",c,sin(c));
		}
		
		//plot_arc(100,100,20, 90,180,128);
		
		/*
		printf("Palette Test...\r");
		 for (e=1;e<=5;e++)
		 {
			if (e!=5)
			// randomize palette
			{
				for (c=0;c<=255;c++)
				{
					vickyPaletteCol (0, c, rand() % 255, rand() % 255, rand() % 255, 255);
				}
			}
			else 
				vickyDefPalette();		
			// paint pixel color bar
			for (c=0;c<=255;c++)
			{
				for (d=0;d<20;d++)
					plot (c+50, d+(e*50), c);
			} 
		 }
		  clrBitmap();
		  ANSIClrScr();           // Clear Text screen after switching resolution (for sanity!)
		  ANSILocate(1,1);
		printf("200 Lines...\n\r");
		 for (c=0;c<=200;c++)
		  {
			xRndInit=rand() % (int)vickyResX;
			xRndEnd=rand() % (int)vickyResX;
			yRndInit=rand() % (int)vickyResY;
			yRndEnd=rand() % (int)vickyResY;
			colRnd=rand() % 255;
			plot_line (xRndInit, yRndInit, xRndEnd, yRndEnd, colRnd);
		  } 
		  clrBitmap();
		  ANSIClrScr();           // Clear Text screen after switching resolution (for sanity!)
		  ANSILocate(1,1);
		 printf("100 Bezier Lines...\n\r");
		 for (c=0;c<=100;c++)
		  {
			xRndInit=rand() % (int)vickyResX;
			xRndEnd=rand() % (int)vickyResX;
			xRndMid=rand() % (int)vickyResX;
			xRndMid2=rand() % (int)vickyResX;
			yRndInit=rand() % (int)vickyResY;
			yRndMid=rand() % (int)vickyResY;
			yRndMid2=rand() % (int)vickyResY;
			yRndEnd=rand() % (int)vickyResY;
			colRnd=rand() % 255;
			plot_bezier (xRndInit, yRndInit, xRndMid, yRndMid,  xRndMid2, yRndMid2, xRndEnd, yRndEnd, colRnd);
		  } 
		  clrBitmap();
		  ANSIClrScr();           // Clear Text screen after switching resolution (for sanity!)
		  ANSILocate(1,1);
		  printf("50 Rectangles...\n\r");
		  for (c=0;c<=50;c++)
		  {
			xRndInit=rand() % (int)vickyResX;
			xRndEnd=rand() % (int)vickyResX;
			xRndMid=rand() % (int)vickyResX;
			yRndMid=rand() % (int)vickyResY;
			yRndInit=(rand() % (int)vickyResY);
			yRndEnd=(rand() % (int)vickyResY);
			colRnd=rand() % 255;
			plot_rectangle (xRndInit, yRndInit, xRndEnd, yRndEnd, colRnd);
		  } 
		  clrBitmap();
		  ANSIClrScr();           // Clear Text screen after switching resolution (for sanity!)
		  ANSILocate(1,1);
		  printf("50 Circles...\n\r");
		 for (c=0;c<=50;c++)
		  {
			xRndInit=rand() % (int)vickyResX;
			yRndInit=rand() % (int)vickyResY;
			yRndMid=(rand() % (int)vickyResY);
			colRnd=rand() % 255;
			plot_circle (xRndInit, yRndInit, (yRndMid / 2),colRnd);
		  } 
		  clrBitmap();
		  ANSIClrScr();           // Clear Text screen after switching resolution (for sanity!)
		  ANSILocate(1,1);
 		  printf("50 Ellipses...\n\r");
		  for (c=0;c<=50;c++)
		  {
			xRndInit=rand() % (int)vickyResX;
			xRndEnd=rand() % (int)vickyResX;
			xRndMid=rand() % (int)vickyResX;
			yRndMid=rand() % (int)vickyResY;
			yRndInit=rand() % (int)vickyResY;
			yRndEnd=rand() % (int)vickyResY;
			colRnd=rand() % 255;
			plot_ellipse (xRndInit, yRndInit, xRndEnd/2, yRndEnd/2, colRnd);
		  }
		  clrBitmap();
		  ANSIClrScr();           // Clear Text screen after switching resolution (for sanity!)
		  ANSILocate(1,1);
 		  printf("30 Solid Ellipses... \n\r");
		  for (c=0;c<=30;c++)
		  {
			xRndInit=rand() % (int)vickyResX;
			xRndEnd=rand() % (int)vickyResX;
			xRndMid=rand() % (int)vickyResX;
			yRndMid=rand() % (int)vickyResY;
			yRndInit=rand() % (int)vickyResY;
			yRndEnd=rand() % (int)vickyResY;
			colRnd=rand() % 255;
			plot_solid_ellipse (xRndInit, yRndInit, xRndEnd / 2, yRndEnd / 2, colRnd);
		  }
		  clrBitmap();
		  ANSIClrScr();           // Clear Text screen after switching resolution (for sanity!)
		  ANSILocate(1,1);
		 printf("30 Solid circles... \n\r");
		 srand(time(NULL)); 
		 for (c=0;c<=30;c++)
		  {
			xRndInit=rand() % (int)vickyResX;
			yRndInit=rand() % (int)vickyResY;
			yRndMid=rand() % (int)vickyResY;
			colRnd=rand() % 255;
			plot_solid_circle (xRndInit, yRndInit, yRndMid / 2,colRnd);
		  } 
		  clrBitmap();
		  ANSIClrScr();           // Clear Text screen after switching resolution (for sanity!)
		  ANSILocate(1,1);
		  printf("300 Solid Rectangles...\n\r");
		  	  for (c=0;c<=300;c++)
		  {
			xRndInit=rand() % (int)vickyResX;
			xRndEnd=rand() % (int)vickyResX;
			xRndMid=rand() % (int)vickyResX;
			yRndMid=rand() % (int)vickyResY;
			yRndInit=rand() % (int)vickyResY;
			yRndEnd=rand() % (int)vickyResY;
			colRnd=rand() % 255;
			plot_solid_rectangle (xRndInit, yRndInit, xRndEnd, yRndEnd, colRnd);
		  } 
		  
		  clrBitmap();
		  ANSIClrScr();           // Clear Text screen after switching resolution (for sanity!)
		  ANSILocate(1,1);
		  printf("10 Flood Filled Circles...\n\r");
		  for (c=0;c<=10;c++)
		  {
			xRndInit=rand() % (int)vickyResX;
			yRndInit=rand() % (int)vickyResY;
			yRndMid=rand() % (int)vickyResY;
			colRnd=rand() % 255;
			plot_circle (xRndInit, yRndInit, (yRndMid / 2),colRnd);
			colRnd=rand() % 255;
			floodFill (xRndInit, yRndInit,colRnd);
		  } 
		  clrBitmap();
		  c=vickyVideomode (true,false,false,false,false,false,false,0);
		  ANSIClrScr();           // Clear Text screen after switching resolution (for sanity!)
		  ANSILocate(1,1);
		  */
		  printf("Thx for watching this demo\n\r");
		  return 0;
  } // screen
  else {return -1;}
}

// ----------------------------------------
// Helper functions 
// ----------------------------------------

// ----------------------------------------
// Setup Graphic Screen
// ----------------------------------------
int setupScreen(int mode)
{
	int status;
	// VickyVideoMode (bool text,bool txtOverlay,bool bitmap,bool tiles,bool sprites,bool gammaFix,bool blank,int resolution {0-640x480|1-800x600|2-320x240|3-400x300})
	status=vickyVideomode (true,true,true,false,true,true,false,mode);
	// VickyBitmap (int page {0-1}, bool enable, long address {0-0x1fffff (2 Mb)| 0-0x3fffff (4 Mb)}, int lut {0-7}, bool collision)
	if (status!=-1)
	{
		status=vickyBitmap (0,true,0,0,false);
		if (status==0)
		{
			ANSIClrScr();           // Clear Text screen after switching resolution (for sanity!)
			ANSILocate(1,1);		// Locate cursor at 1,1
			// Set Border size to 0 
			BORDER_CTRL_REG = 0;
			return 0;
		}
		else 
		{
			printf ("Error %d while setting bitmap",status);
			return status;
		} //Error setting Bitmap
	}
	else 
	{
		printf ("Error %d while setting VideoMode",status);
		return status;
	} //Error setting videomode
}

// ----------------------------------------
// Delay Function
// credits https://www.quora.com/How-do-you-use-the-time-delay-in-C-programming
// ----------------------------------------

void delay(int delay) 
{ 
 int now=time(NULL); 
 int later=now+delay; 
	while(now<=later)
	    now=time(NULL); 
} 