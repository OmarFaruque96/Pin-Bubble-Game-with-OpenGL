#include<windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <ctime>
#include<iostream>
#include<stdio.h>

#define PI 3.1416

using namespace std;

static int width=800,height=600;

static int point = 0;

static float TimeCount=0;
//Hill part circle position

float h1=-45,k1=-43;

//   $$$$$ Pin Area   $$$$$$
// head circle
float circle_xP=1.6,circle_yP=2.2;
//position
float circle_XP=11.7,circle_YP=19.0,circle_ZP=0.0;

// ###
static float a1=0.0, b1=0.0;

float x10,y10;  //mouse area co ordinate
//##########  circle size   ##########
float circle_x1=4.0,circle_y1=5.5;
float circle_x2=4.0,circle_y2=5.7;
float circle_x3=3.0,circle_y3=4.8;
float circle_x4=6.0,circle_y4=7.5;
float circle_x5=6.0,circle_y5=7.5;

//########   circle color code    #######
//#######################################//

float circle_color_r1=0.10,circle_color_g1=0.08,circle_color_b1=0.99;    //blue
float circle_color_r2=0.20,circle_color_g2=0.90,circle_color_b2=0.20;
float circle_color_r3=1.00,circle_color_g3=0.00,circle_color_b3=0.49;  //pink
float circle_color_r4=0.50,circle_color_g4=1.00,circle_color_b4=0.00;  // yellow green
float circle_color_r5=0.50,circle_color_g5=0.08,circle_color_b5=0.29;
//&& game over bubble
float circle_color_r6=1.0,circle_color_g6=0.0,circle_color_b6=0.0;
float circle_color_r7=0.0,circle_color_g7=0.0,circle_color_b7=0.0;


float circle_00_x=00.0,circle_00_y=0.0,circle_01_z=0.0;

//right side bubble position
float circle_01_x=10.0,circle_01_y=-80.0;
float circle_02_x=20.0,circle_02_y=-70.0;
float circle_03_x=30.0,circle_03_y=-100.0;
float circle_04_x=40.0,circle_04_y=-80.0;
//left side bubble position
float circle_01_x_=-10.0,circle_01_y_=-60.0;
float circle_02_x_=-20.0,circle_02_y_=-65.0;
float circle_03_x_=-30.0,circle_03_y_=-90.0;
float circle_04_x_=-40.0,circle_04_y_=-120.0;
//2nd row right
float circle_011_x=05.0,circle_011_y=-130.0;
float circle_012_x=15.0,circle_012_y=-110.0;
float circle_013_x=25.0,circle_013_y=-70.0;
float circle_014_x=35.0,circle_014_y=-90.0;
float circle_015_x=45.0,circle_015_y=-100.0;
//2nd row left
float circle_011_x_=-05.0,circle_011_y_=-130.0;
float circle_012_x_=-15.0,circle_012_y_=-120.0;
float circle_013_x_=-25.0,circle_013_y_=-85.0;
float circle_014_x_=-35.0,circle_014_y_=-105.0;
float circle_015_x_=-45.0,circle_015_y_=-70.0;
//game over stage

FILE *scoreStore;

bool Game_State=true;
float angle = 0.0;

void init(void)
{
	glClearColor (0.28, 0.815, 0.80, 0.0);
	//glClearColor (0.686, 0.93, 0.93, 0.0);
	glOrtho(-50.0, 50.0, -50.0, 50.0, -50.0, 50.0);
}

//Circle Creation Code
void circle(float radius_x, float radius_y)
{
	int i = 0;

	glBegin(GL_POLYGON);

		for(i = 0; i < 100; i++)
		{
			angle = 2 * PI * i / 100;
			glVertex3f (cos(angle) * radius_x, sin(angle) * radius_y, 0);
		}
	glEnd();
}

void Pin(float a1,float b1){


        //pin head
        glPushMatrix();

            glColor3f(circle_color_r1,circle_color_g1,circle_color_b1);
            glTranslated(a1+6.7,b1+9.0,0);
            circle(circle_xP,circle_yP);
        glPopMatrix();
        //pin body
        glPushMatrix();
        glColor3f(circle_color_r1,circle_color_g1,circle_color_b1);
            glTranslated(a1,b1,0);
            glBegin(GL_POLYGON);
                        glVertex2f(0,0);
                        glVertex2f(7,7);
                        glVertex2f(5,9);
                        glVertex2f(0,0);
            glEnd();
        glPopMatrix();


}
void Tree_View(float tx1,float tx2,float tx3){
    //tree
    //body
    glPushMatrix();
        glColor3f(0.13,0.52,0.13);
        glTranslated(tx1,tx2,tx3);
        glBegin(GL_POLYGON);
            glVertex2f(-40.0,-42.0);
            glVertex2f(-38.5,-19.0);
            glVertex2f(-37.0,-42.0);
            glVertex2f(-40.0,-42.0);
        glEnd();
    glPopMatrix();
    // leaf
    glPushMatrix();
        glColor3f(0.13,0.52,0.13);
        glTranslated(tx1,tx2,tx3);
        //glScalef(2,1,0);
        glBegin(GL_POLYGON);
            glVertex2f(-38.5,-22.0);
            glVertex2f(-40.5,-23.0);  //1
            glVertex2f(-40.8,-24.0);  //2
            glVertex2f(-41.2,-25.0);   //3
            glVertex2f(-41.5,-26.0);  //4

            glVertex2f(-41.7,-24.0);
            glVertex2f(-41.5,-23.0);
            glVertex2f(-41.3,-22.8);

            glVertex2f(-41.8,-23.0);
            glVertex2f(-42.1,-23.5);

            glVertex2f(-42.1,-22.7);
            glVertex2f(-41.9,-22.1);
            glVertex2f(-41.4,-21.8);

            glVertex2f(-41.6,-21.75);
            glVertex2f(-41.9,-21.9);
            glVertex2f(-42.3,-21.95);

            glVertex2f(-42.0,-21.2);
            glVertex2f(-41.8,-21.0);
            glVertex2f(-41.5,-20.0);
            glVertex2f(-41.0,-20.8);
            glVertex2f(-40.5,-20.5);
            glVertex2f(-40.0,-20.8);
            glVertex2f(-39.8,-20.0);
            glVertex2f(-39.72,-20.5);

            glVertex2f(-38.5,-21.0);

             glVertex2f(-38.5,-22.0);
            glVertex2f(-36.5,-23.0);  //1
            glVertex2f(-36.8,-24.0);  //2
            glVertex2f(-35.2,-25.0);   //3
            glVertex2f(-35.5,-26.0);  //4

            glVertex2f(-35.7,-24.0);
            glVertex2f(-35.5,-23.0);
            glVertex2f(-35.3,-22.8);

            glVertex2f(-35.8,-23.0);
            glVertex2f(-34.1,-23.5);

            glVertex2f(-34.1,-22.7);
            glVertex2f(-35.9,-22.1);
            glVertex2f(-35.4,-21.8);

            glVertex2f(-35.6,-21.75);
            glVertex2f(-35.9,-21.9);
            glVertex2f(-34.3,-21.95);

            glVertex2f(-34.0,-21.2);
            glVertex2f(-35.8,-21.0);
            glVertex2f(-35.5,-20.0);
            glVertex2f(-35.0,-20.8);
            glVertex2f(-36.5,-20.5);
            glVertex2f(-36.0,-20.8);
            glVertex2f(-37.8,-20.0);
            glVertex2f(-37.72,-20.5);

            glVertex2f(-38.5,-21.0);
        glEnd();
    glPopMatrix();
}
void background_view(){
    glPushMatrix();
        glColor3f(0.13,0.52,0.13);
        glBegin(GL_POLYGON);
            glVertex2f(-50,-45);
            glVertex2f(50,-45);
            glVertex2f(50,-50);
            glVertex2f(-50,-50);
        glEnd();
    glPopMatrix();
    //1st bubble
    glPushMatrix();
        glColor3f(0.13,0.52,0.13);
        glTranslated(h1,k1,0);
        circle(8,8);
    glPopMatrix();
    //2nd bubble
    glPushMatrix();
        glColor3f(0.13,0.52,0.13);
        glTranslated(h1+13,k1,0);
        circle(8,8);
    glPopMatrix();
    //3
    //3rd bubble
    glPushMatrix();
        glColor3f(0.13,0.52,0.13);
        glTranslated(h1+26,k1,0);
        circle(8,8);
    glPopMatrix();
    //4th bubble
    glPushMatrix();
        glColor3f(0.13,0.52,0.13);
        glTranslated(h1+39,k1,0);
        circle(8,8);
    glPopMatrix();
    //5th bubble
    glPushMatrix();
        glColor3f(0.13,0.52,0.13);
        glTranslated(h1+52,k1,0);
        circle(8,8);
    glPopMatrix();
    //6th bubble
    glPushMatrix();
        glColor3f(0.13,0.52,0.13);
        glTranslated(h1+66,k1,0);
        circle(8,8);
    glPopMatrix();
    //6th bubble
    glPushMatrix();
        glColor3f(0.13,0.52,0.13);
        glTranslated(h1+80,k1,0);
        circle(8,8);
    glPopMatrix();
    //7th bubble
    glPushMatrix();
        glColor3f(0.13,0.52,0.13);
        glTranslated(h1+93,k1,0);
        circle(8,8);
    glPopMatrix();
    //8th bubble
    glPushMatrix();
        glColor3f(0.13,0.52,0.13);
        glTranslated(h1+106,k1,0);
        circle(8,8);
    glPopMatrix();

    Tree_View(0.0,0.0,0.0);
    Tree_View(20.0,0.0,0.0);
    Tree_View(30.0,-8.0,0.0);
    Tree_View(45.0,0.0,0.0);
    Tree_View(53.0,-10.0,0.0);
    Tree_View(65.0,0.0,0.0);
    Tree_View(80.0,-2.0,0.0);
    //

}
void bubble_Animate(){

        circle_00_y+=0.06;

        circle_01_y+=0.20;
        circle_02_y+=0.09;
        circle_03_y+=0.10;
        circle_04_y+=0.09;
        circle_011_y+=0.15;
        circle_012_y+=0.20;
        circle_013_y+=0.16;
        circle_014_y+=0.15;
        circle_015_y+=0.19;

        circle_01_y_+=0.19;
        circle_02_y_+=0.12;
        circle_03_y_+=0.16;
        circle_04_y_+=0.20;
        circle_011_y_+=0.25;
        circle_012_y_+=0.19;
        circle_013_y_+=0.16;
        circle_014_y_+=0.13;
        circle_015_y_+=0.15;

        if(circle_00_y>55){
            circle_00_y=-70;
        }
        //#### upper row
        if(circle_01_y>55){
            circle_01_y=-65;
        }
        if(circle_02_y>58){
            circle_02_y=-60;
        }
        if(circle_03_y>70){
            circle_03_y=-70;
        }
        if(circle_04_y>65){
            circle_04_y=-70;
        }

        if(circle_011_y>55){
            circle_011_y=-65;
        }
        if(circle_012_y>58){
            circle_012_y=-60;
        }
        if(circle_013_y>70){
            circle_013_y=-60;
        }
        if(circle_014_y>65){
            circle_014_y=-60;
        }
        if(circle_015_y>65){
            circle_015_y=-60;
        }
        //###lower row
        if(circle_01_y_>55){
            circle_01_y_=-65;
        }
        if(circle_02_y_>58){
            circle_02_y_=-60;
        }
        if(circle_03_y_>70){
            circle_03_y_=-60;
        }
        if(circle_04_y_>65){
            circle_04_y_=-60;
        }

        if(circle_011_y_>55){
            circle_011_y_=-65;
        }
        if(circle_012_y_>58){
            circle_012_y_=-60;
        }
        if(circle_013_y_>70){
            circle_013_y_=-60;
        }
        if(circle_014_y_>65){
            circle_014_y_=-60;
        }
        if(circle_015_y_>65){
            circle_015_y_=-60;
        }
        glutPostRedisplay();
}

void bubble_Position(){

        //middle bubble
        glPushMatrix();
            glColor3f(circle_color_r1,circle_color_g1,circle_color_b1);
            glTranslated(circle_00_x,circle_00_y,0);
            circle(circle_x1,circle_y1);
        glPopMatrix();

        //Right Side bubble #############

        //1st bubble
        glPushMatrix();
            glColor3f(circle_color_r2,circle_color_g2,circle_color_b2);
            glTranslated(circle_01_x,circle_01_y,0);
            circle(circle_x2,circle_y2);
        glPopMatrix();
        //2nd bubble
        glPushMatrix();
            glColor3f(circle_color_r3,circle_color_g3,circle_color_b3);
            glTranslated(circle_02_x,circle_02_y,0);
            circle(circle_x1,circle_y1);
        glPopMatrix();
        //3rd bubble
        glPushMatrix();
            glColor3f(circle_color_r7,circle_color_g7,circle_color_b7);
            glTranslated(circle_03_x,circle_03_y,0);
            circle(circle_x3,circle_y3);
        glPopMatrix();
        //4th bubble
        glPushMatrix();
            glColor3f(circle_color_r3,circle_color_g3,circle_color_b3);
            glTranslated(circle_04_x,circle_04_y,0);
            circle(circle_x4,circle_y4);
        glPopMatrix();

        //2nd row right ########################
        //1st bubble
        glPushMatrix();
            glColor3f(circle_color_r6,circle_color_g6,circle_color_b6);
            glTranslated(circle_011_x,circle_011_y,0);
            circle(circle_x2,circle_y2);
        glPopMatrix();
        //2nd bubble
        glPushMatrix();
            glColor3f(circle_color_r3,circle_color_g3,circle_color_b3);
            glTranslated(circle_012_x,circle_012_y,0);
            circle(circle_x3,circle_y3);
        glPopMatrix();
        //3rd bubble
        glPushMatrix();
            glColor3f(circle_color_r6,circle_color_g6,circle_color_b6);
            glTranslated(circle_013_x,circle_013_y,0);
            circle(circle_x5,circle_y5);
        glPopMatrix();
        //4th bubble
        glPushMatrix();
            glColor3f(circle_color_r3,circle_color_g3,circle_color_b3);
            glTranslated(circle_014_x,circle_014_y,0);
            circle(circle_x1,circle_y1);
        glPopMatrix();
        //5th bubble
        glPushMatrix();
            glColor3f(circle_color_r6,circle_color_g6,circle_color_b6);
            glTranslated(circle_015_x,circle_015_y,0);
            circle(circle_x2,circle_y2);
        glPopMatrix();

        //Left Side bubble #############

        //1st bubble
        glPushMatrix();
            glColor3f(circle_color_r6,circle_color_g6,circle_color_b6);
            glTranslated(circle_01_x_,circle_01_y_,0);
            circle(circle_x1,circle_y1);
        glPopMatrix();
        //2nd bubble
        glPushMatrix();
            glColor3f(circle_color_r3,circle_color_g3,circle_color_b3);
            glTranslated(circle_02_x_,circle_02_y_,0);
            circle(circle_x3,circle_y3);
        glPopMatrix();
        //3rd bubble
        glPushMatrix();
            glColor3f(circle_color_r7,circle_color_g7,circle_color_b7);
            glTranslated(circle_03_x_,circle_03_y_,0);
            circle(circle_x4,circle_y4);
        glPopMatrix();
        //4th bubble
        glPushMatrix();
            glColor3f(circle_color_r6,circle_color_g6,circle_color_b6);
            glTranslated(circle_04_x_,circle_04_y_,0);
            circle(circle_x1,circle_y1);
        glPopMatrix();

        // 2nd Row #################################
        //1st bubble
        glPushMatrix();
            glColor3f(circle_color_r4,circle_color_g4,circle_color_b4);
            glTranslated(circle_011_x_,circle_011_y_,0);
            circle(circle_x2,circle_y2);
        glPopMatrix();
        //2nd bubble
        glPushMatrix();
            glColor3f(circle_color_r3,circle_color_g3,circle_color_b3);
            glTranslated(circle_012_x_,circle_012_y_,0);
            circle(circle_x5,circle_y5);
        glPopMatrix();
        //3rd bubble
        glPushMatrix();
            glColor3f(circle_color_r6,circle_color_g6,circle_color_b6);
            glTranslated(circle_013_x_,circle_013_y_,0);
            circle(circle_x2,circle_y2);
        glPopMatrix();
        //4th bubble
        glPushMatrix();
            glColor3f(circle_color_r1,circle_color_g1,circle_color_b1);
            glTranslated(circle_014_x_,circle_014_y_,0);
            circle(circle_x1,circle_y1);
        glPopMatrix();
        //5th bubble
        glPushMatrix();
            glColor3f(circle_color_r4,circle_color_g4,circle_color_b4);
            glTranslated(circle_015_x_,circle_015_y_,0);
            circle(circle_x3,circle_y3);
        glPopMatrix();


}

void Timer(){
    clock_t start;
    start = clock();
    TimeCount = (float)start/CLOCKS_PER_SEC;
    if(TimeCount >= 120){
        Game_State=false;
    }
}

void PointFunction(){

        //middle
        if((circle_00_x+circle_x1 > a1) && (circle_00_y+circle_y1>b1) && (circle_00_y-circle_y1<b1) && (circle_00_x-circle_x1<a1)){
                        ++point;
                        circle_00_y=-80;
                }

    //1st row 1st right
        else if((circle_01_x+circle_x2 > a1) && (circle_01_y+circle_y2>b1) && (circle_01_y-circle_y2<b1) && (circle_01_x-circle_x2<a1)){
                        point+=5;
                        circle_01_y=-90;
                }
//2nd
       else if((circle_02_x+circle_x1 > a1) && (circle_02_y+circle_y1>b1) && (circle_02_y-circle_y1<b1) && (circle_02_x-circle_x1<a1)){
                        ++point;
                        circle_02_y=-60;
                }
//3rd
        else if((circle_03_x+circle_x3 > a1) && (circle_03_y+circle_y3>b1) && (circle_03_y-circle_y3<b1) && (circle_03_x-circle_x3<a1)){

                        point-=2;
                        circle_03_y=-160;
                }
//4th
        else if((circle_04_x+circle_x4 > a1) && (circle_04_y+circle_y4>b1) && (circle_04_y-circle_y4<b1) && (circle_04_x-circle_x4<a1)){
                        ++point;
                        circle_04_y=-140;
                }

//left part
//1st
        else if((circle_011_x+circle_x2 > a1) && (circle_011_y+circle_y2>b1) && (circle_011_y-circle_y2<b1) && (circle_011_x-circle_x2<a1)){
                        //game over bubble
                        Game_State=false;
                }
//2nd
        else if((circle_012_x+circle_x3 > a1) && (circle_012_y+circle_y3>b1) && (circle_012_y-circle_y3<b1) && (circle_012_x-circle_x3<a1)){
                        ++point;
                        circle_012_y=-100;
                }
//3rd
        else if((circle_013_x+circle_x5 > a1) && (circle_013_y+circle_y5>b1) && (circle_013_y-circle_y5<b1) && (circle_013_x-circle_x5<a1)){
                        //game over bubble
                        Game_State=false;
                }
//4th
        else if((circle_014_x+circle_x1 > a1) && (circle_014_y+circle_y1>b1) && (circle_014_y-circle_y1<b1) && (circle_014_x-circle_x1<a1)){
                        ++point;
                        circle_014_y=-90;
            }
    //5th
        else if((circle_015_x+circle_x2 > a1) && (circle_015_y+circle_y2>b1) && (circle_015_y-circle_y2<b1) && (circle_015_x-circle_x2<a1)){
                        //game over bubble
                        Game_State=false;
                }
//2nd Row
//1st right

        else if((circle_01_x_+circle_x1 > a1) && (circle_01_y_+circle_y1>b1) && (circle_01_y_-circle_y1<b1) && (circle_01_x_-circle_x1<a1)){
                        //game over bubble
                        Game_State=false;
                }
//2nd
        else if((circle_02_x_+circle_x3 > a1) && (circle_02_y_+circle_y3>b1) && (circle_02_y_-circle_y3<b1) && (circle_02_x_-circle_x3<a1)){
                        ++point;
                        circle_02_y_=-75;
                }
//3rd
        else if((circle_03_x_+circle_x4 > a1) && (circle_03_y_+circle_y4>b1) && (circle_03_y_-circle_y4<b1) && (circle_03_x_-circle_x4<a1)){
                        point-=2;
                        circle_03_y_=-130;
                }
//4th
        else if((circle_04_x_+circle_x1 > a1) && (circle_04_y_+circle_y1>b1) && (circle_04_y_-circle_y1<b1) && (circle_04_x_-circle_x1<a1)){
                        //game over bubble
                        Game_State=false;
                }
//left
//1st
        else if((circle_011_x_+circle_x2 > a1) && (circle_011_y_+circle_y2>b1) && (circle_011_y_-circle_y2<b1) && (circle_011_x_-circle_x2<a1)){
                        point+=2;
                        circle_011_y_=-110;
                }
//2nd
        else if((circle_012_x_+circle_x5 > a1) && (circle_012_y_+circle_y5>b1) && (circle_012_y_-circle_y5<b1) && (circle_012_x_-circle_x5<a1)){
                        ++point;
                        circle_012_y_=-120;
                }
//3rd
        else if((circle_013_x_+circle_x2 > a1) && (circle_013_y_+circle_y2>b1) && (circle_013_y_-circle_y2<b1) && (circle_013_x_-circle_x2<a1)){
                        //game over bubble
                        Game_State=false;
                }
//4th
        else if((circle_014_x_+circle_x1 > a1) && (circle_014_y_+circle_y1>b1) && (circle_014_y_-circle_y1<b1) && (circle_014_x_-circle_x1<a1)){
                        ++point;
                        circle_014_y_=-85;
                }
//5th
        else if((circle_015_x_+circle_x3 > a1) && (circle_015_y_+circle_y3>b1) && (circle_015_y_-circle_y3<b1) && (circle_015_x_-circle_x3<a1)){
                        point+=2;
                        circle_015_y_=-90;
                }

        else if(point == 120){
            Game_State=false;
        }
        Timer();
}
void TextSmall(char text[], float r, float g, float b, int x, int y, int z)
{
    glColor3f(r, g, b);
    glRasterPos3f( x , y , z);
    for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
}

void TextLarge(char text[], int r, int g, int b, int x, int y, int z)
{
    glColor3f(r,g,b);
    glRasterPos3f( x,y ,z);
    for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
}

void FileWork(){
    //file write from here
            scoreStore=fopen("F:\\Education\\191\\Computer Graphics Lab\\Pin Bubble Game Project\\Score.text","a"); //append
            //check for null
            if(scoreStore == NULL){
                printf("Error");
            }else{
                fprintf(scoreStore,"%d \n",point);
            }
            //close the file
            fclose(scoreStore);
}
void End_Level(){
        FileWork();
        glClear(GL_COLOR_BUFFER_BIT);
            glColor3f(0.1,0.9,0.9);
            TextLarge("Game Over", 1.0, 0.1, 0.5, -8, 20, 0);
            TextLarge("Score is storing in the file", 0, 0, 1, -14, 5, 0);

            TextLarge("Time :        SEC", 0, 0, 1, -14, -5 , 0);
            char timeC[100];
            itoa(TimeCount, timeC, 10);
            TextLarge(timeC, 0, 0, 1, -4, -5 , 0);

            char SCORE[100];
            itoa(point, SCORE, 10);
            TextLarge(SCORE, 0, 0, 1, -3, -20, 0);
            TextLarge("Score : ", 0, 0, 1, -12, -20, 0);

        glFlush();

}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

	if(Game_State == true){

            glPushMatrix();
            Timer();
            PointFunction();

            bubble_Animate();
            bubble_Position();
            Pin(a1,b1);
            background_view();
        glPopMatrix();

        //printf("%d \n",point);
	}
	if(Game_State==false){

        End_Level();
	}
	glFlush();
}
void my_keyboard(unsigned char key, int x, int y)
{
	switch (key) {

        case 's':
           // PlaySound("file_example_WAV_2MG.wav", NULL, SND_FILENAME| SND_ASYNC);
            if(Game_State == true) {
               // point=0;
            }
            break;

	  default:
			break;
	}
}

void my_mouse(int button, int state, int x, int y)
{
   switch (button) {
      case GLUT_LEFT_BUTTON:
         if (state == GLUT_DOWN)
//          //position of the mouse on the screen
                 x10 = x /(float) width;
                 y10 = y /(float) height;
                // convert in X and Y co ordinate based on our screen
                a1=(x10*100)-50;
                b1=50-(y10*100);
                //ReSize();
                glutPostRedisplay();
                break;
      case GLUT_MIDDLE_BUTTON:

      case GLUT_RIGHT_BUTTON:
         if (state == GLUT_DOWN)
//
         break;

      default:
         break;
   }

}

int main()
{
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (width, height);
	glutInitWindowPosition (10, 10);
	glutCreateWindow ("Pin Bubble");
	init();
	glutDisplayFunc(display);
	glutMouseFunc(my_mouse);
    glutKeyboardFunc(my_keyboard);

	glutMainLoop();
	return 0;
}

