				
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
void print_board(int x, int y);

// Constants
#define START '1'
#define QUIT_GAME '2'
#define GAMEOVER '3'
#define QUIT '0'
#define YES '5'
#define RESET '8'
#define X_coord 85
#define Y_coord 35

// Global Variables
int level;
int choices[26];
char *words[5];
int error_count;
int correct;
int level;

// Main Function
int main(){
	char keypress = START; 
	int champion = 0;
	error_count = correct = 0;
	int word_index=0;

	set_graphics(VGA_320X200X256);
	
	do{
		erase(1,1,400,220);
		header(10, 8);

		level = 1; // initialize level		
		champion = 0; // falsify championhood

		keypress=(char)getch();
		erase(1,1,400,220); 

		if(keypress==START){
			do{
				if(keypress==START){
					setup_level(level);

					//update level display
					erase(25,125,40,30);
					// write_text("O",25,125,WHITE,0);
					print_blanks(word_index);
					print_board(X_coord, Y_coord);
				}else{
					print_blanks(word_index);
					print_board(X_coord, Y_coord);
				}

				word_index=0;
				do{
					if(keypress=(char)getch()){
						correct=0; //reset counting of blanks

						check_if_exist(words[0][1], keypress);
						erase(30, 120, 270, 250);
						print_blanks(word_index);

						if(strchr(words[word_index], keypress) == NULL){
							error_count++;
						}

						print_board(X_coord, Y_coord);
					}
					if(error_count == 5) break;
					
					// Will enter this if-statement if word is spelled correctly
					if(correct == 0 && error_count < 5) {
						reset();
						erase(1,1,400,220);
						word_index++;	
						
						if(word_index == 4){
							word_index = 0;
							level++;
						}
						
						if(level > 5){
							reset();
							champion = 1;
							break;
						}

						print_blanks(word_index);
						print_board(X_coord, Y_coord);

						
					}

				}while(keypress != QUIT && champion !=1);
				
				if(error_count==5){keypress = GAMEOVER;}
				
				if(keypress == GAMEOVER){
					write_text("Game Over",50,160,WHITE,0);
					reset();
					keypress=RESET;
				}
				
				if(champion==1){keypress = YES;}
				else if(keypress == QUIT){
					//prompt confirmation then erase message
					write_text("Do you want to exit? y/n",50,160,WHITE,0);
					keypress=(char)getch();
					erase(50,160,220,40);
				}					
				else if(keypress == RESET){
					//prompt confirmation then erase message
					write_text("Do you want to restart? y/n",50,180,WHITE,0);
					keypress=(char)getch();
					if(keypress == YES) {
						reset();
						keypress = START;
					}else{
						keypress=QUIT;
						break;
					}	
					erase(50,160,260,40);
				}
								
			}while(keypress != YES && error_count < 5);
		}
	}while(keypress != QUIT_GAME);
	
	set_graphics(VGA_TEXT80X25X16);
	clrscr();
}

void reset(){
	int i;
	for(i=0; i<26; i++) choices[i] = 0;
	error_count = 0;
}

//displays header
header(int x, int y){
	
	write_text("Hangman",120,40,WHITE,1); //title
	
	//menu options
	write_text("1 - Start",40,160,WHITE,0); 
	write_text("2 - Quit",200,160,WHITE,0);
}

void check_if_exist(char * word, char keypress){
	int i;
	// if(strchar(word, keypress)){
		
	// }
	//mark 
	choices[keypress-97] = 1;
}

void print_board_alphabet(){
	int i, x, y, counter =0;
	char color = WHITE;
	// char 
	x = 20;
	y = 120;
	for(i=0; i<26; i++, x+= 20){
		if(choices[counter] == 0){
			color = WHITE;
		}else{
			color = RED;
		}
		switch(counter){
			case 0: 
				write_text("A", 30, y, color, 0);
				break;
			case 1: 
				write_text("B", 50, y, color, 0);
				break;
			case 2: 
				write_text("C", 70, y, color, 0);
				break;
			case 3: 
				write_text("D", 90, y, color, 0);
				break;
			case 4: 
				write_text("E", 110, y, color, 0);
				break;
			case 5: 
				write_text("F", 130, y, color, 0);
				break;
			case 6: 
				write_text("G", 150, y, color, 0);
				break;
			case 7: 
				write_text("H", 170, y, color, 0);
				break;
			case 8: 
				write_text("I", 190, y, color, 0);
				break;
			case 9: 
				write_text("J", 210, y, color, 0);
				break;
			case 10: 
				write_text("K", 230, y, color, 0);
				break;
			case 11: 
				write_text("L", 250, y, color, 0);
				break;
			case 12: 
				write_text("M", 270, y, color, 0);
				break;
			case 13: 
				write_text("N", 30,150, color, 0);
				break;
			case 14: 
				write_text("O", 50,150, color, 0);
				break;
			case 15: 
				write_text("P", 70,150, color, 0);
				break;
			case 16: 
				write_text("Q", 90,150, color, 0);
				break;
			case 17: 
				write_text("R", 110,150, color, 0);
				break;
			case 18: 
				write_text("S", 130,150, color, 0);
				break;
			case 19: 
				write_text("T", 150,150, color, 0);
				break;
			case 20: 
				write_text("U", 170,150, color, 0);
				break;
			case 21: 
				write_text("V", 190,150, color, 0);
				break;
			case 22: 
				write_text("W", 210,150, color, 0);
				break;
			case 23: 
				write_text("X", 230,150, color, 0);
				break;
			case 24: 
				write_text("Y", 250,150, color, 0);
				break;
			case 25: 
				write_text("Z", 270,150, color, 0);
				break;
			default:
				break;
			}

			counter  += 1;
			if(counter == 13){
				x = 20;
				y = 150;
			}	
		}
}

noose(){

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

void print_blanks(int word_selected){
	int i;
	int word_size = strlen(words[word_selected]);
	char letter;

	erase(120, 100, (word_size+1)*10, 110);

	for(i=0; i<word_size; i++){
		int letter_index = words[word_selected][i]-97;

		if(choices[letter_index] == 1){
			switch(letter_index){
				case 0: 
					write_text(" A ", 120+(i*10), 100, WHITE, 0);
					break;
				case 1: 
					write_text(" B ", 120+(i*10), 100, WHITE, 0);
					break;
				case 2: 
					write_text(" C ", 120+(i*10), 100, WHITE, 0);
					break;
				case 3: 
					write_text(" D ", 120+(i*10), 100, WHITE, 0);
					break;
				case 4: 
					write_text(" E ", 120+(i*10), 100, WHITE, 0);
					break;
				case 5: 
					write_text(" F ", 120+(i*10), 100, WHITE, 0);
					break;
				case 6: 
					write_text(" G ", 120+(i*10), 100, WHITE, 0);
					break;
				case 7: 
					write_text(" H ", 120+(i*10), 100, WHITE, 0);
					break;
				case 8: 
					write_text(" I ", 120+(i*10), 100, WHITE, 0);
					break;
				case 9: 
					write_text(" J ", 120+(i*10), 100, WHITE, 0);
					break;
				case 10: 
					write_text(" K ", 120+(i*10), 100, WHITE, 0);
					break;
				case 11: 
					write_text(" L ", 120+(i*10), 100, WHITE, 0);
					break;
				case 12: 
					write_text(" M ", 120+(i*10), 100, WHITE, 0);
					break;
				case 13: 
					write_text(" N ", 120+(i*10), 100, WHITE, 0);
					break;
				case 14: 
					write_text(" O ", 120+(i*10), 100, WHITE, 0);
					break;
				case 15: 
					write_text(" P ", 120+(i*10), 100, WHITE, 0);
					break;
				case 16: 
					write_text(" Q ", 120+(i*10), 100, WHITE, 0);
					break;
				case 17: 
					write_text(" R ", 120+(i*10), 100, WHITE, 0);
					break;
				case 18: 
					write_text(" S ", 120+(i*10), 100, WHITE, 0);
					break;
				case 19: 
					write_text(" T ", 120+(i*10), 100, WHITE, 0);
					break;
				case 20: 
					write_text(" U ", 120+(i*10), 100, WHITE, 0);
					break;
				case 21: 
					write_text(" V ", 120+(i*10), 100, WHITE, 0);
					break;
				case 22: 
					write_text(" W ", 120+(i*10), 100, WHITE, 0);
					break;
				case 23: 
					write_text(" X ", 120+(i*10), 100, WHITE, 0);
					break;
				case 24: 
					write_text(" Y ", 120+(i*10), 100, WHITE, 0);
					break;
				case 25: 
					write_text(" Z ", 120+(i*10), 100, WHITE, 0);
					break;
				default:
					break;
				}

			
		}else{
			correct++;
			write_text(" _ ", 120+(i*10), 100, WHITE, 0);
		}
	}
}

void print_board(int x, int y){
	int i, j, a, b;
	
	a=x;
	b=y;
	
	noose();

	print_board_alphabet();
	// Display Legend
	write_text("Exit-0",5,40,WHITE,0);
	write_text("Reset-8",5,50,WHITE,0);
}

void erase(int x, int y, int w, int h){ //basically covers an area with a black rectangle
   int i,j;
   for (i=y;i<=(y+h);i++)
      for (j=x;j<=(x+w);j++)
         write_pixel(j,i,100);
}

void setup_level(int level){
	int i, j;

	switch(level){
		case 1:
			words[0] = "her";
			words[1] = "doe";
			words[2] = "rat";
			words[3] = "cat";
			words[4] = "dog";
			break;
		case 2:
			words[0] = "drunken";
			words[1] = "drawn";
			words[2] = "round";
			words[3] = "wound";
			words[4] = "down";
			break;
		case 3:
			words[0] = "around";
			words[1] = "circle";
			words[2] = "early";
			words[3] = "crawled";
			words[4] = "drilled";
			break;
		case 4:
			words[0] = "nutrition";
			words[1] = "computer";
			words[2] = "engineer";
			words[3] = "geodetic";
			words[4] = "drainage";
			break;
		case 5:
			words[0] = "COMMUNICATION";
			words[1] = "INFORMATION";
			words[2] = "PROGRAMMER";
			words[3] = "MATHEMATICIAN";
			words[4] = "MODIFIED";
			break;
	}

	print_board(X_coord, Y_coord);	
}
