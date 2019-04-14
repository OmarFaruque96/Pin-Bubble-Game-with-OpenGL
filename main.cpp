#include<windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <ctime>
#include<iostream>

#define PI 3.1416

using namespace std;

static float	tx	=  0.0;
static float	ty	=  0.0;

//   $$$$$ Pin Area   $$$$$$
// head circle
float circle_xP=1.6,circle_yP=2.2;
//position
float circle_XP=11.7,circle_YP=19.0,circle_ZP=0.0;

//##########  circle size   ##########
float circle_x1=4.0,circle_y1=5.5;
float circle_x2=4.0,circle_y2=5.7;
float circle_x3=3.0,circle_y3=4.8;
float circle_x4=6.0,circle_y4=7.5;
float circle_x5=6.0,circle_y5=7.5;
float circle_x6=6.2,circle_y6=7.5;
float circle_x7=6.5,circle_y7=7.8;
float circle_x8=6.0,circle_y8=7.5;
float circle_x9=5.5,circle_y9=6.5;
float circle_x10=5.0,circle_y10=6.5;
float circle_x11=6.0,circle_y11=7.5;
float circle_x12=6.0,circle_y12=7.2;

//########   circle color code    #######
float circle_color_r1=0.1,circle_color_g1=0.08,circle_color_b1=0.99;
float circle_color_r2=0.2,circle_color_g2=0.9,circle_color_b2=0.2;
float circle_color_r3=1.0,circle_color_g3=0.0,circle_color_b3=0.49;
float circle_color_r4=0.50,circle_color_g4=1.0,circle_color_b4=0.0;
float circle_color_r5=0.5,circle_color_g5=0.08,circle_color_b5=0.29;
float circle_color_r6=0.6,circle_color_g6=0.7,circle_color_b6=0.99;

float circle_00_x=00.0,circle_00_y=0.0,circle_01_z=0.0;

//right side bubble position
float circle_01_x=10.0,circle_01_y=0.0;
float circle_02_x=20.0,circle_02_y=0.0;
float circle_03_x=30.0,circle_03_y=0.0;
float circle_04_x=40.0,circle_04_y=0.0;
//left side bubble position
float circle_01_x_=-10.0,circle_01_y_=0.0;
float circle_02_x_=-20.0,circle_02_y_=0.0;
float circle_03_x_=-30.0,circle_03_y_=0.0;
float circle_04_x_=-40.0,circle_04_y_=0.0;
//2nd row right
float circle_011_x=05.0,circle_011_y=-15.0;
float circle_012_x=15.0,circle_012_y=-15.0;
float circle_013_x=25.0,circle_013_y=-15.0;
float circle_014_x=35.0,circle_014_y=-15.0;
float circle_015_x=45.0,circle_015_y=-15.0;
//2nd row left
float circle_011_x_=-05.0,circle_011_y_=-15.0;
float circle_012_x_=-15.0,circle_012_y_=-15.0;
float circle_013_x_=-25.0,circle_013_y_=-15.0;
float circle_014_x_=-35.0,circle_014_y_=-15.0;
float circle_015_x_=-45.0,circle_015_y_=-15.0;



bool Game_State=true;


void init(void)
{
	glClearColor (0.3, 1.0, 1.0, 0.0);
	glOrtho(-50.0, 50.0, -50.0, 50.0, -50.0, 50.0);
}

//Circle Creation Code
void circle(float radius_x, float radius_y)
{
	int i = 0;
	float angle = 0.0;

	glBegin(GL_POLYGON);

		for(i = 0; i < 100; i++)
		{
			angle = 2 * PI * i / 100;
			glVertex3f (cos(angle) * radius_x, sin(angle) * radius_y, 0);
		}
	glEnd();
}

void Pin(){

    glPushMatrix();
        //pin head
        glPushMatrix();
            glColor3f(circle_color_r2,circle_color_g2,circle_color_b2);
            glTranslated(circle_XP,circle_YP,0);
            circle(circle_xP,circle_yP);
        glPopMatrix();
        //pin body
        glColor3f(circle_color_r2,circle_color_g2,circle_color_b2);
        glBegin(GL_POLYGON);
                    glVertex2f(5.0,10.0);
                    glVertex2f(12.0,17.0);
                    glVertex2f(10.0,19.0);
                    glVertex2f(5.0,10.0);
        glEnd();
    glPopMatrix();
}
void bubble_Animate(){

        circle_00_y+=0.06;

        circle_01_y+=0.04;
        circle_02_y+=0.01;
        circle_03_y+=0.02;
        circle_04_y+=0.04;
        circle_011_y+=0.02;
        circle_012_y+=0.03;
        circle_013_y+=0.03;
        circle_014_y+=0.02;
        circle_015_y+=0.02;

        circle_01_y_+=0.01;
        circle_02_y_+=0.01;
        circle_03_y_+=0.02;
        circle_04_y_+=0.02;
        circle_011_y_+=0.01;
        circle_012_y_+=0.02;
        circle_013_y_+=0.01;
        circle_014_y_+=0.03;
        circle_015_y_+=0.01;

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
            circle(circle_x1,circle_y1);
        glPopMatrix();
        //2nd bubble
        glPushMatrix();
            glColor3f(circle_color_r3,circle_color_g3,circle_color_b3);
            glTranslated(circle_02_x,circle_02_y,0);
            circle(circle_x1,circle_y1);
        glPopMatrix();
        //3rd bubble
        glPushMatrix();
            glColor3f(circle_color_r4,circle_color_g4,circle_color_b4);
            glTranslated(circle_03_x,circle_03_y,0);
            circle(circle_x1,circle_y1);
        glPopMatrix();
        //4th bubble
        glPushMatrix();
            glColor3f(circle_color_r3,circle_color_g3,circle_color_b3);
            glTranslated(circle_04_x,circle_04_y,0);
            circle(circle_x1,circle_y1);
        glPopMatrix();

        //2nd row right ########################
        //1st bubble
        glPushMatrix();
            glColor3f(circle_color_r2,circle_color_g2,circle_color_b2);
            glTranslated(circle_011_x,circle_011_y,0);
            circle(circle_x1,circle_y1);
        glPopMatrix();
        //2nd bubble
        glPushMatrix();
            glColor3f(circle_color_r3,circle_color_g3,circle_color_b3);
            glTranslated(circle_012_x,circle_012_y,0);
            circle(circle_x1,circle_y1);
        glPopMatrix();
        //3rd bubble
        glPushMatrix();
            glColor3f(circle_color_r4,circle_color_g4,circle_color_b4);
            glTranslated(circle_013_x,circle_013_y,0);
            circle(circle_x1,circle_y1);
        glPopMatrix();
        //4th bubble
        glPushMatrix();
            glColor3f(circle_color_r3,circle_color_g3,circle_color_b3);
            glTranslated(circle_014_x,circle_014_y,0);
            circle(circle_x1,circle_y1);
        glPopMatrix();
        //5th bubble
        glPushMatrix();
            glColor3f(circle_color_r4,circle_color_g4,circle_color_b4);
            glTranslated(circle_015_x,circle_015_y,0);
            circle(circle_x1,circle_y1);
        glPopMatrix();

        //Left Side bubble #############

        //1st bubble
        glPushMatrix();
            glColor3f(circle_color_r4,circle_color_g4,circle_color_b4);
            glTranslated(circle_01_x_,circle_01_y_,0);
            circle(circle_x1,circle_y1);
        glPopMatrix();
        //2nd bubble
        glPushMatrix();
            glColor3f(circle_color_r3,circle_color_g3,circle_color_b3);
            glTranslated(circle_02_x_,circle_02_y_,0);
            circle(circle_x1,circle_y1);
        glPopMatrix();
        //3rd bubble
        glPushMatrix();
            glColor3f(circle_color_r2,circle_color_g2,circle_color_b2);
            glTranslated(circle_03_x_,circle_03_y_,0);
            circle(circle_x1,circle_y1);
        glPopMatrix();
        //4th bubble
        glPushMatrix();
            glColor3f(circle_color_r1,circle_color_g1,circle_color_b1);
            glTranslated(circle_04_x_,circle_04_y_,0);
            circle(circle_x1,circle_y1);
        glPopMatrix();

        // 2nd Row #################################
        //1st bubble
        glPushMatrix();
            glColor3f(circle_color_r4,circle_color_g4,circle_color_b4);
            glTranslated(circle_011_x_,circle_011_y_,0);
            circle(circle_x1,circle_y1);
        glPopMatrix();
        //2nd bubble
        glPushMatrix();
            glColor3f(circle_color_r3,circle_color_g3,circle_color_b3);
            glTranslated(circle_012_x_,circle_012_y_,0);
            circle(circle_x1,circle_y1);
        glPopMatrix();
        //3rd bubble
        glPushMatrix();
            glColor3f(circle_color_r2,circle_color_g2,circle_color_b2);
            glTranslated(circle_013_x_,circle_013_y_,0);
            circle(circle_x1,circle_y1);
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
            circle(circle_x1,circle_y1);
        glPopMatrix();

}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

	if(Game_State==true){

        bubble_Animate();
        glPushMatrix();
        bubble_Position();
        Pin();
        glPopMatrix();
	}
	glFlush();
}


void spe_key(int key, int x, int y)
{

	switch (key) {

		case GLUT_KEY_LEFT:

				//glutPostRedisplay();
				break;

		case GLUT_KEY_RIGHT:

				//glutPostRedisplay();
				break;

        case GLUT_KEY_DOWN:

				//glutPostRedisplay();
				break;

		case GLUT_KEY_UP:

				//glutPostRedisplay();
				break;
	  default:
			break;
	}
}
int main()
{
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (800, 600);
	glutInitWindowPosition (10, 10);
	glutCreateWindow ("Pin Bubble");
	init();
	glutDisplayFunc(display);
	glutSpecialFunc(spe_key);
	glutMainLoop();
	return 0;
}

