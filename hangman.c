					
/*	
	Authors: 
		Francis Saylon
		Ross Marabe
	Date and Time Created: 3:00 PM, May 10, 2018
	Section: CMSC 125 T-7L
	Program Description: Hangman Game for ICS-OS	
*/

// Libraries
#include "../../sdk/dexsdk.h"
#include "../../sdk/time.h"

// Function Prototypes
void erase(int x, int y, int w, int h);
void print_board(int x, int y, int error_count);

// Constants
#define START '1'
#define QUIT_GAME '2'
#define QUIT '0'
#define YES 'y'
#define RESET 'R'
#define X_coord 85
#define Y_coord 35

// Global Variables
int level;
int choices[2][13];
char *words[5];

// Main Function
int main(){
	char keypress = START; 
	int champion = 0;
	int error_count = 0;

	set_graphics(VGA_320X200X256);
	
	do{
		erase(1,1,400,220);
		header(10, 8);

		level = 1; // initialize level		
		champion = 0; // falsify championhood
		error_count = 0;

		keypress=(char)getch();
		erase(1,1,400,220); 

		if(keypress==START){
			do{

				if(keypress==START){
					setup_level();

					//update level display
					erase(25,125,40,30);
					print_board(X_coord, Y_coord,error_count);

				}else
					print_board(X_coord, Y_coord, error_count);

				do{
					if(keypress=(char)getch()){

					}
				}while(keypress != QUIT && champion !=1);
				
				if(champion==1){keypress = YES;}
				else if(keypress == QUIT){
					//prompt confirmation then erase message
					write_text("Do you want to exit? y/n ",60,160,WHITE,0);
					keypress=(char)getch();
					erase(60,160,220,40);
				}					
				else if(keypress == RESET){
					//prompt confirmation then erase message
					write_text("Do you want to restart? y/n ",50,160,WHITE,0);
					keypress=(char)getch();
					if(keypress == YES) keypress = START;
					erase(50,160,260,40);
				}
								
			}while(keypress != YES);
		}
	}while(keypress != QUIT_GAME);
	
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

noose(int error_count){

	if(error_count == 0){
		write_text("===============",100, 0, WHITE, 1);
		write_text("||",100, 10, WHITE, 1);
		write_text("||",100, 20, WHITE, 1);
		write_text("||",100, 30, WHITE, 1);
		write_text("||",100, 40, WHITE, 1);
		write_text("||",100, 50, WHITE, 1);
		write_text("||",100, 60, WHITE, 1);
		write_text("============",100, 70, WHITE, 1);
	}else if(error_count == 1){
		write_text("===============",100, 0, WHITE, 1);
		write_text("||         +",100, 10, WHITE, 1);
		write_text("||         +",100, 20, WHITE, 1);
		write_text("||",100, 30, WHITE, 1);
		write_text("||",100, 40, WHITE, 1);
		write_text("||",100, 50, WHITE, 1);
		write_text("||",100, 60, WHITE, 1);
		write_text("============",100, 70, WHITE, 1);
	}else if(error_count == 2){
		write_text("===============",100, 0, WHITE, 1);
		write_text("||         +",100, 10, WHITE, 1);
		write_text("||         +",100, 20, WHITE, 1);
		write_text("||        ( )",100, 30, WHITE, 1);
		write_text("||",100, 40, WHITE, 1);
		write_text("||",100, 50, WHITE, 1);
		write_text("||",100, 60, WHITE, 1);
		write_text("============",100, 70, WHITE, 1);
	}else if(error_count == 3){
		write_text("===============",100, 0, WHITE, 1);
		write_text("||         +",100, 10, WHITE, 1);
		write_text("||         +",100, 20, WHITE, 1);
		write_text("||        ( )",100, 30, WHITE, 1);
		write_text("||       / | /",100, 40, WHITE, 1);
		write_text("||",100, 50, WHITE, 1);
		write_text("||",100, 60, WHITE, 1);
		write_text("============",100, 70, WHITE, 1);
	}else if(error_count == 4){
		write_text("===============",100, 0, WHITE, 1);
		write_text("||         +",100, 10, WHITE, 1);
		write_text("||         +",100, 20, WHITE, 1);
		write_text("||        ( )",100, 30, WHITE, 1);
		write_text("||       / | /",100, 40, WHITE, 1);
		write_text("||        | |",100, 50, WHITE, 1);
		write_text("||",100, 60, WHITE, 1);
		write_text("============",100, 70, WHITE, 1);
	}else if(error_count == 5){
		write_text("===============",100, 0, WHITE, 1);
		write_text("||         +",100, 10, WHITE, 1);
		write_text("||         +",100, 20, WHITE, 1);
		write_text("||        (X)",100, 30, WHITE, 1);
		write_text("||       / | /",100, 40, WHITE, 1);
		write_text("||        | |",100, 50, WHITE, 1);
		write_text("||",100, 60, WHITE, 1);
		write_text("============",100, 70, WHITE, 1);
	}
}

void print_board(int x, int y, int error_count){
	int i, j, a, b;
	a=x;
	b=y;

	noose(error_count);
	
	// Display Legend
	write_text("Exit-0",5,40,WHITE,0);
	write_text("Reset-R",5,50,WHITE,0);
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