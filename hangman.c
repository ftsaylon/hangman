/*					*/
/*	 john paul ibay 07-67611	*/
/*      angelo de la vina 07-67724	*/
/*					*/
/*	LIGHTSOUT! Game for ICS-OS	*/


#include "../../sdk/dexsdk.h"
#include "../../sdk/time.h"

void erase(int x, int y, int w, int h);
void print_board(int x, int y);

#define START '1'
#define QUIT_GAME '2'

#define X_coord 85
#define Y_coord 35

// GLOBAL VARIABLES
int level;
int choices[2][13];
char *words[5];

int main(){
	char keypress = START; 
	
	set_graphics(VGA_320X200X256);
	
	do{
		erase(1,1,400,220);
		header(8, 5);

		keypress=(char)getch();
		erase(1,1,400,220); 

		if(keypress==START){
			setup_level();

			//update level display
			erase(25,125,40,30);
			write_text("0",25,125,WHITE,0);
		}else{
			print_board(X_coord, Y_coord);
		}

	}while(keypress!=QUIT_GAME);
	
	set_graphics(VGA_TEXT80X25X16);
	clrscr();
}

//displays header
header(int x, int y){
	
	write_text("Hangman",120,40,WHITE,1); //title

	//menu options
	write_text("1 - Start",40,160,WHITE,0); 
	write_text("2 - Quit",200,160,WHITE,0);
}

void print_board(int x, int y){
	int i, j, a, b;

	for(i=0; i<2; i++, b+=24){
		for(j=0; j<13; j++, a+=31)
			write_text('A');
	}
}

void erase(int x, int y, int w, int h){ //basically covers an area with a black rectangle
   int i,j;
   for (i=y;i<=(y+h);i++)
      for (j=x;j<=(x+w);j++)
         write_pixel(j,i,100);
}

void setup_level(){
	int i, j;

	switch(level){
		case 1:
			words[0] = 'ABELARD';
			words[1] = 'AVERT';
			words[2] = 'BOW';
			words[3] = 'CAR';
			words[4] = 'DOG';
			break;
	}	
}