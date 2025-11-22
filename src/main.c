/*
 *--------------------------------------
 * Program Name: WordScapes CE
 * Author: sumde2
 * License: MIT
 * Description: WordScapes port to the TI-84 Plus CE
 *--------------------------------------
*/

#include <graphx.h>
#include <keypadc.h>
#include <math.h>
#include <sys/timers.h>
#include <ti/getkey.h>
#include <ti/vars.h>
#include <stdlib.h>
#include <tice.h>
#include "levels.h"

//definitions
#define PI 3.14159
#define BGcolor 0xBF
//end of definitions

bool check_win();
void search_word(int x, int y, int direction_x, int direction_y); // x and y vars are inverted
void find_word();
void fill_word(int x, int y, int direction);
void draw();
int main(void);

//save file stuff
int archived = 0;
int16_t *save_file;

//global variables
uint8_t MAX_letters = 7;
bool is_holding_key = false;

uint16_t coins;

int nlila = 0; // number of letters in the letter answers array
int cx_word_circle[6];
int cy_word_circle[6];

char letters[7];
int selected_letter = 1;

char current_word[6] = "";
int current_selected_letters = 0;

int current_level;
bool new_level = true;
//end of global variables

bool check_win() {
    for (int i = 0; i<10; i++) {
        for (int j = 0; j<10; j++) {
            if (solved_answers[i][j]!=level_answers[current_level][i][j]) return false;
        }
    }

    return true;
}

void search_word(int x, int y, int direction_x, int direction_y) {
    int matched_letters = 0;
    for (int k = 0; k<current_selected_letters; k++) {
        int marginx = k*direction_x;
        int marginy = k*direction_y;

        if (level_answers[current_level][x+marginx][y+marginy]==current_word[k]) {
            matched_letters++;
        }
    }

    int last_x = x+((current_selected_letters-1)*direction_x);
    int last_y = y+((current_selected_letters-1)*direction_y);
    int axis = -1;

    if (matched_letters==current_selected_letters && matched_letters!=1) {
        if (direction_y && level_answers[current_level][x][last_y+1]==' ' &&
            level_answers[current_level][x][y-1]==' ') {
            axis = 1; //good in x axis
        } else if (direction_x && level_answers[current_level][last_x+1][y]==' ' &&
            level_answers[current_level][x-1][y]==' ') {
            axis = 0; //good in y axis
        }
        
        if (axis!=-1) fill_word(y,x,axis);
    }
}

void find_word() {
    for (int i = 0; i<10; i++) {
        for (int j = 0; j<10; j++) {
            if (level_answers[current_level][j][i]!=current_word[0]) continue;
        
            search_word(j,i,0,1);
            search_word(j,i,1,0);
        }
    }

    for (int i = 0; i<current_selected_letters; i++) {
        current_word[i]='\0';
    }
    current_selected_letters = 0;
}

void fill_word(int x, int y, int direction) {
    int matched_letters = 0;
    for (int i = 0; i<current_selected_letters; i++) {
        if (direction==1 && 
            solved_answers[y][x+i]==level_answers[current_level][y][x+i]) matched_letters++;
        if (direction==0 && 
            solved_answers[y+i][x]==level_answers[current_level][y+i][x]) matched_letters++;
    } for (int i = 0; i<current_selected_letters; i++) {
        if (direction==1) solved_answers[y][x+i] = current_word[i];
        else if (direction==0) solved_answers[y+i][x] = current_word[i];
    }
    if (matched_letters!=current_selected_letters) coins+=current_selected_letters;
}

void draw() {
    gfx_FillScreen(BGcolor);

    //UI stuff
    gfx_SetTextTransparentColor(0);

    if (check_win()) {
        gfx_SetTextBGColor(BGcolor);
        gfx_SetTextFGColor(0xE0);

        gfx_SetTextScale(3,3);
        gfx_SetTextXY(84,90);
        gfx_PrintString("You Won!");

        gfx_SetTextScale(1,1);
        gfx_SetTextXY(84,120);
        gfx_PrintString("Next Level:");
        gfx_SetTextXY(172,120);
        gfx_PrintInt(current_level+1,1);

        gfx_SwapDraw();

        delay(2000);
        new_level = true;
    }

    for (int i = 0; i<10; i++) {
        for (int j = 0; j<10; j++) {
            gfx_SetColor(BGcolor*(level_answers[current_level][j][i]==' '||
                                level_answers[current_level][j][i]=='\0'));
            gfx_Rectangle(110+(19*i),30+(19*j),18,18);

            gfx_SetTextBGColor(BGcolor);
            gfx_SetTextFGColor((BGcolor-1)*(solved_answers[j][i]==' '||
                                solved_answers[j][i]=='\0')+1);
            gfx_SetTextScale(1,1);
            gfx_SetTextXY(115+(19*i),35+(19*j));
            gfx_PrintChar(solved_answers[j][i]);
        }
    }

    gfx_SetColor(0xDF);
    gfx_FillCircle(50, 115, 45);

    gfx_SetTextBGColor(BGcolor);
    gfx_SetTextFGColor(0x17);

    gfx_SetTextScale(3,2);
    gfx_SetTextXY(20,20);
    gfx_PrintString("WordScapes!");

    gfx_SetTextScale(1,1);
    gfx_SetTextXY(10,220);
    gfx_PrintString("Current word: ");
    gfx_SetTextXY(110,220);
    gfx_PrintString(current_word);

    gfx_SetTextScale(1,1);
    gfx_SetTextXY(10,210);
    gfx_PrintString("Current level: ");
    gfx_SetTextXY(111,210);
    if(current_level!=0) {
        gfx_PrintInt(current_level,1);
    } else gfx_PrintString("Tutorial");

    gfx_SetColor(0xE5);
    gfx_FillCircle(248, 222, 12);

    gfx_SetTextScale(2,2);
    gfx_SetTextBGColor(0xE5);
    gfx_SetTextFGColor(0xE4);
    gfx_SetTextXY(241,215);
    gfx_PrintChar('$');

    gfx_SetTextScale(1,1);
    gfx_SetTextBGColor(BGcolor);
    gfx_SetTextFGColor(0xE3);
    gfx_SetTextXY(264,220);
    gfx_PrintInt(coins,4);

    for (int i = 0; i<nlila; i++) {
        gfx_SetColor(0xE3);
        gfx_FillCircle(cx_word_circle[i], cy_word_circle[i], 10);

        gfx_SetTextBGColor(0xE3);
        gfx_SetTextFGColor(0xFF);
        gfx_SetTextScale(2,2);
        gfx_SetTextXY(cx_word_circle[i]-7,cy_word_circle[i]-7);
        gfx_PrintChar(letters[i]);

        if (selected_letter==i) {
            gfx_SetColor(0xE0);
            gfx_Circle(cx_word_circle[i],cy_word_circle[i],12);
        }
    }

    gfx_SwapDraw();
}

int main(void) {
    gfx_Begin();
	gfx_SetDrawBuffer();

    srand(rtc_Time());

    save_file = (int16_t *)os_GetAppVarData("WDSCSAVE", &archived);
    if (save_file==NULL) {
        save_file = (int16_t *)os_CreateAppVar("WDSCSAVE", 32);

        save_file[0] = 0; // coins
        save_file[1] = 0; // current level
    }

    coins = save_file[0];
    current_level = save_file[1]-1;

    //code
    while(true) {
        kb_Scan();

        if (!is_holding_key) {
            if(kb_Data[6] & kb_Clear) break;
            if(kb_Data[7] & kb_Left) selected_letter++; is_holding_key = true;
            if(kb_Data[7] & kb_Right) selected_letter--; is_holding_key = true;
            if(kb_Data[1] & kb_2nd && current_selected_letters<MAX_letters) {
                current_word[current_selected_letters] = letters[selected_letter];
                current_selected_letters++;
                is_holding_key = true;
            }
            if(kb_Data[6] & kb_Enter) find_word();
        }

        if(!(kb_Data[7] & (kb_Right | kb_Left)) &&
            !(kb_Data[1] & kb_2nd) && 
            !(kb_Data[6] & kb_Enter)) {
            is_holding_key = false;
        }

        selected_letter = ((selected_letter%nlila)+nlila)%nlila;

        if (new_level) {
            new_level = false;

            current_level++;
            current_level%=num_of_levels;

            nlila = 0;
            while (1) {
                letters[nlila] = level_letters[current_level][nlila];

                if(letters[nlila]=='\0') {
                    break;
                }

                nlila++;
            }

            for (int i = 0; i<nlila; i++) {
                int radius = 30;
                float angle = (PI*2*i)/(float)nlila;
                cx_word_circle[i] = 50+(int)(cosf(angle)*radius);
                cy_word_circle[i] = 115+(int)(sinf(angle)*radius);
            }
            for (int i = 0; i<10; i++) {
                for (int j = 0; j<10; j++) {
                    solved_answers[i][j]=' ';
                }
            }

            save_file[0] = coins;
            save_file[1] = current_level;
        }

        draw();
    }

    gfx_End();

    return 0;
}