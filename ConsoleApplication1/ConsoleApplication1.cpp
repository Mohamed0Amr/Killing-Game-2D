#include <windows.h>
#include <gl/GL.h>
#include <gl/glut.h>
#include <ctime>
#include <cstdio>
#include "RGBpixmap.h"

using namespace std;
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")
#pragma comment(lib, "glut32.lib")

//Idetinfie the variable
RGBpixmap image[2];
int x_axis = -20;
float x_axis_square = 0;
bool buttonPressed = false;
bool direction = false;
int Enemy1 = -80, Enemy2 = -60, Enemy3 = -40, Enemy4 = -20, Enemy5=0 , Enemy6= 20 , Enemy7 = 40 , Enemy8 = 60;
int EnemyHeight = 70;
int ammo_x = 0, ammo_y = 0;
int currentAmmoPos = 0;
int sum = 0;


//Creates the main window, registers event handlers, and
//initializes OpenGL stuff.
void InitGraphics(int argc, char* argv[]);

//Sets the logical coordinate system we will use to specify
//our drawings.
void SetTransformations() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100, 100, -100, 100);
}
//Keys to right and left and up
void keys(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_RIGHT:
        x_axis += 5;
        glutPostRedisplay();
        break;
    case GLUT_KEY_LEFT:
        x_axis -= 5;
        glutPostRedisplay();
        break;
    case GLUT_KEY_UP:
        buttonPressed = true;
        ammo_x = x_axis;
    }
}

void drawText(void* font, const char s[], float x, float y) {
    glRasterPos2f(x, y);
    for (int i = 0; i < strlen(s); i++)
        glutBitmapCharacter(font, s[i]);
}

void OnDisplay() {
    //set the background color to Black
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    SetTransformations();
    glutSpecialFunc(keys);

    
    //ammo
    if (buttonPressed) {
        ammo_y += 2;
        glPixelZoom(0.04, 0.04);
        glEnable(GL_TEXTURE_2D);
        glRasterPos2i(ammo_x + 13, -90 + ammo_y);
        image[2].draw();
        glEnd();
    }
    if (ammo_y > 200) {
        buttonPressed = false;
        ammo_y = 0;
    }
    
    //SPACE
    glPixelZoom(0.7, 0.7);
    glEnable(GL_TEXTURE_2D);
    glRasterPos2i(0 + x_axis, -90);
    image[1].draw();

    if (x_axis >= 60) x_axis = 60;
    else if (x_axis <= -95) x_axis = -95;
    glEnd();

    //ENIMIES

    //enemy draw
 

    glPixelZoom(0.1, 0.1);
    glEnable(GL_TEXTURE_2D);
   
    glRasterPos2i(Enemy1, EnemyHeight);
    image[0].draw();
    glRasterPos2i(Enemy2, EnemyHeight);
    image[0].draw();
    glRasterPos2i(Enemy3, EnemyHeight);
    image[0].draw();
    glRasterPos2i(Enemy4, EnemyHeight);
    image[0].draw();
    glRasterPos2i(Enemy5, EnemyHeight);
    image[0].draw();
    glRasterPos2i(Enemy6, EnemyHeight);
    image[0].draw();
    glRasterPos2i(Enemy7, EnemyHeight);
    image[0].draw();
    glRasterPos2i(Enemy8, EnemyHeight);
    image[0].draw();
    glEnd();
    //final message
    
    if (sum == 8) {
        x_axis = -800;
        x_axis_square = 5;
        glTranslatef(0, 0, 0);
        drawText(GLUT_BITMAP_HELVETICA_18, "WINNER WINNER CHICKEN DINER", -40, 20);
        drawText(GLUT_BITMAP_HELVETICA_10, "YOU HAVE KILLED 9 ENEMIES", -20, 10);
    }
    

    currentAmmoPos = ammo_x ;
    
    currentAmmoPos = ammo_x;
    if (ammo_y == EnemyHeight + 80 && currentAmmoPos >= Enemy1 - 15 + x_axis_square &&//el 3la ymin
        currentAmmoPos <= Enemy1 + 5 + x_axis_square) {//el 3la shmal
        Enemy1 = -800;
        sum++;
    }
    if (ammo_y == EnemyHeight + 80 && currentAmmoPos >= Enemy2 - 15 + x_axis_square &&
        currentAmmoPos <= Enemy2 + 5 + x_axis_square) {
        Enemy2 = -800;
        sum++;
    }
    if (ammo_y == EnemyHeight + 80 && currentAmmoPos >= Enemy3 - 15 + x_axis_square &&
        currentAmmoPos <= Enemy3 + 5 + x_axis_square) {
        Enemy3 = -800;
        sum++;
    }
    if (ammo_y == EnemyHeight + 80 && currentAmmoPos >= Enemy4 - 15 + x_axis_square &&
        currentAmmoPos <= Enemy4 + 5 + x_axis_square) {
        Enemy4 = -800;
        sum++;
    }
    if (ammo_y == EnemyHeight + 80 && currentAmmoPos >= Enemy5 - 15 + x_axis_square &&
        currentAmmoPos <= Enemy5 + 5 + x_axis_square) {
        Enemy5 = -800;
        sum++;
    }
    if (ammo_y == EnemyHeight + 80 && currentAmmoPos >= Enemy6 - 15 + x_axis_square &&
        currentAmmoPos <= Enemy6 + 5 + x_axis_square) {
        Enemy6 = -800;
        sum++;
    }
    if (ammo_y == EnemyHeight + 80 && currentAmmoPos >= Enemy7 - 15 + x_axis_square &&
        currentAmmoPos <= Enemy7 + 5 + x_axis_square) {
        Enemy7 = -800;
        sum++;
    }
    if (ammo_y == EnemyHeight + 80 && currentAmmoPos >= Enemy8 - 15 + x_axis_square &&
        currentAmmoPos <= Enemy8 + 5 + x_axis_square) {
        Enemy8 = -800;
        sum++;
    }

    
    glutSwapBuffers();
    glutPostRedisplay();
}

int main(int argc, char* argv[]) {
    InitGraphics(argc, argv);
    return 0;
}

//Creates the main window, registers event handlers, and
//initializes OpenGL stuff.
void InitGraphics(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutInitWindowPosition(100, 100); //pass (-1, -1) for Window-Manager defaults
    glutInitWindowSize(800, 600);
    glutCreateWindow("KILLING-GAME");
    glutDisplayFunc(OnDisplay);
    image[0].readBMPFile("enemy.bmp");
    image[1].readBMPFile("space1.bmp");
    image[2].readBMPFile("ammo.bmp");
    glutMainLoop();
}