#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#define PI 3.14159265358979323846

void circle(float a, float b, float r)
{
    int i;
    int triangleAmount = 100;
    GLfloat twicePi = 2.0f * PI;
    GLfloat x = a;
    GLfloat y = b;
    GLfloat radius = r;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
}

void quad(float a, float b, float c, float d, float e, float f, float g,
          float h)
{
    glBegin(GL_QUADS);
    glVertex2f(a, b);
    glVertex2f(c, d);
    glVertex2f(e, f);
    glVertex2f(g, h);
    glEnd();
}

void triangle(float a, float b, float c, float d, float e, float f)
{
    glBegin(GL_TRIANGLES);
    glVertex2f(a, b);
    glVertex2f(c, d);
    glVertex2f(e, f);
    glEnd();
}

void line(float a, float b, float c, float d)
{
    glBegin(GL_LINES);
    glVertex2f(a, b);
    glVertex2f(c, d);
    glEnd();
}

GLfloat cloudP = 2.0f;
GLfloat cloudS = 0.02f;
void cloudUp(int value)
{
    if (cloudP < -2.0) cloudP = 2.0f;
    cloudP -= cloudS;
    glutPostRedisplay();
    glutTimerFunc(100, cloudUp, 0);
}

GLfloat sunP = 0.0f;
GLfloat sunS = 0.005f;

void sunUp(int value)
{
    if (sunP > 1.2) sunP = -1.2f;
    sunP += sunS;
    glutPostRedisplay();
    glutTimerFunc(50, sunUp, 0);
}

GLfloat RcloudP = 3.5f;
GLfloat RcloudS = 0.02f;
void RcloudUp(int value)
{
    if (RcloudP < -0.0) RcloudP = 1.0f;
    RcloudP -= RcloudS;
    glutPostRedisplay();
    glutTimerFunc(100, RcloudUp, 0);
}

GLfloat wSpeed = 0.0f;

GLfloat boatP = 1.2f;
GLfloat boatS = 0.02f;
void boatUp(int value)
{
    if (boatP < -1.5) boatP = 1.0f;
    boatP -= boatS;
    glutPostRedisplay();
    glutTimerFunc(200, boatUp, 0);
}

void sky()
{
    glBegin(GL_QUADS);

    glVertex2f(-1, 0);
    glVertex2f(1, 0);
    glVertex2f(1, 1);
    glVertex2f(-1, 1);

    glEnd();
}

void mountain()
{
    glColor3ub(61, 119, 135);
    triangle(.55, 0, 1.1, 0, .8, .22);
    glColor3ub(29, 78, 92);
    triangle(.55, 0, .65, 0, .8, .22);

    glBegin(GL_QUADS);

    glColor3ub(75, 152, 173);
    glVertex2f(-.35, 0);
    glVertex2f(.75, 0);
    glVertex2f(.25, .45);
    glVertex2f(.1, .43);
    glEnd();

    glBegin(GL_TRIANGLES);

    glColor3ub(61, 119, 135);
    glVertex2f(-.8, 0);
    glVertex2f(-.3, 0);
    glVertex2f(-.55, .15);
    glColor3ub(29, 78, 92);
    glVertex2f(-.8, 0);
    glVertex2f(-.7, 0);
    glVertex2f(-.55, .15);

    glColor3ub(61, 119, 135);
    glVertex2f(-.45, 0);
    glVertex2f(.1, 0);
    glVertex2f(-.2, .23);
    glColor3ub(29, 78, 92);
    glVertex2f(-.45, 0);
    glVertex2f(-.35, 0);
    glVertex2f(-.2, .23);

    glEnd();
}
void house()
{
    glScalef(1.2, 1.2, 0);
    glTranslated(.05, 0.0, 0);
    glBegin(GL_QUADS);
    glColor3ub(212, 205, 205);
    glVertex2f(.4, -.1);
    glVertex2f(.4, -.3);
    glVertex2f(.7, -.3);
    glVertex2f(.7, -.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(242, 133, 31);
    glVertex2f(.52, -.2);
    glVertex2f(.52, -.3);
    glVertex2f(.58, -.3);
    glVertex2f(.58, -.2);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(245, 43, 32);
    glVertex2f(.39, -.05);
    glVertex2f(.37, -.18);
    glVertex2f(.73, -.18);
    glVertex2f(.71, -.05);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(204, 51, 0);
    glVertex2f(.39, -.29);
    glVertex2f(.39, -.31);
    glVertex2f(.71, -.31);
    glVertex2f(.71, -.29);
    glEnd();

    glLoadIdentity();
}

void tree()
{
    glBegin(GL_POLYGON);
    glColor3ub(69, 30, 14);
    glVertex2f(-.67, -.2);
    glVertex2f(-.84, -.85);
    glVertex2f(-.73, -.85);
    glVertex2f(-.6, -.2);
    glEnd();
    quad(-.6, -.22, -.4, -.29, -.39, -.28, -.55, -.2);

    quad(-.63, -.18, -.65, -.28, -.4, -.1, -.33, -.09);

    quad(-.6, -.18, -.55, -.18, -.55, -.01, -.56, -.02);
    quad(-.75, -.16, -.68, -.18, -.78, .02, -.8, .03);

    quad(-.63, -.18, -.62, -.28, -.9, -.14, -.89, -.12);

    glBegin(GL_QUADS);
    glVertex2f(-.83, -.82);
    glVertex2f(-.95, -.88);
    glVertex2f(-.81, -.85);
    glVertex2f(-.81, -.82);
    glVertex2f(-.81, -.82);
    glVertex2f(-.83, -.84);
    glVertex2f(-.63, -.89);
    glVertex2f(-.73, -.82);

    glEnd();
}

void river()
{
    glScalef(0.25, .2, 0);
    glTranslated(2., .86, 0);

    glLoadIdentity();

    glBegin(GL_QUADS);
    glColor3ub(150, 201, 38);
    glVertex2f(-1, -.00);
    glVertex2f(1, -.00);
    glVertex2f(1, -.01);
    glVertex2f(-1, -.01);
    glColor3ub(43, 155, 207);
    glVertex2f(-1, -.01);
    glVertex2f(1, -.01);
    glVertex2f(1, -.1);
    glVertex2f(-1, -.1);
    glEnd();

    glColor3ub(109, 170, 199);
    glLineWidth(.05);
    line(-0.85, -.06, -0.95, -.06);
    line(-0.5, -.035, -.56, -.035);
    line(0.0, -.06, -0.1, -.06);
    line(0.8, -.03, 0.9, -.03);
}


void riverNight()
{
    glScalef(0.25, .2, 0);
    glTranslated(2., .86, 0);

    glLoadIdentity();

    glBegin(GL_QUADS);
    glColor3ub(150, 101, 38);
    glVertex2f(-1, -.00);
    glVertex2f(1, -.00);
    glVertex2f(1, -.01);
    glVertex2f(-1, -.01);
    glColor3ub(43, 55, 27);
    glVertex2f(-1, -.01);
    glVertex2f(1, -.01);
    glVertex2f(1, -.1);
    glVertex2f(-1, -.1);
    glEnd();

    glColor3ub(109, 100, 199);
    glLineWidth(.05);
    line(-0.85, -.06, -0.95, -.06);
    line(-0.5, -.035, -.56, -.035);
    line(0.0, -.06, -0.1, -.06);
    line(0.8, -.03, 0.9, -.03);
}

void boat()
{
    glLineWidth(3);
    glBegin(GL_LINES);

    glColor3ub(145, 89, 58);
    glVertex2f(-.01, -.04);
    glVertex2f(-.01, .3);
    glVertex2f(-.1, -.04);
    glVertex2f(-.01, .28);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(252, 25, 0);
    glVertex2f(-.01, .28);
    glVertex2f(-.01, -.0);
    glVertex2f(.14, -.0);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(252, 185, 0);
    glVertex2f(-.12, -.03);
    glVertex2f(-.1, -.06);
    glVertex2f(.1, -.06);
    glVertex2f(.12, -.03);
    glEnd();
}
void cloud()
{
    circle(.625, .58, .05);
    circle(.7, .6, .08);
    circle(.79, .582, .06);
    circle(.85, .58, .04);

    circle(-.425, .585, .04);
    circle(-.5, .6, .07);
    circle(-.59, .592, .05);
    circle(-.64, .58, .03);
}

void cloudNight()
{
    circle(.625, .58, .05);
    circle(.7, .6, .08);
    circle(.79, .582, .06);
    circle(.85, .58, .04);

    circle(-.425, .585, .04);
    circle(-.5, .6, .07);
    circle(-.59, .592, .05);
    circle(-.64, .58, .03);
}
void ground()
{
    glBegin(GL_QUADS);
    glVertex2f(-1, -1);
    glVertex2f(1, -1);
    glVertex2f(1, 0);
    glVertex2f(-1, 0);
    glEnd();
}

void treeLeaf()
{
    glColor3ub(41, 140, 42);
    circle(-0.36, -0.02, .22);

    glColor3ub(95, 168, 47);
    circle(-0.4, -0.3f, .13);

    glColor3ub(30, 74, 34);
    circle(-0.895, -0.13, .15);

    glColor3ub(41, 140, 42);
    circle(-0.77, 0.07, .2);

    glColor3ub(105, 184, 53);
    circle(-0.54, 0.1, .22);
}

void Idle()
{
    glutPostRedisplay();
}

void summer()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3ub(148, 208, 242);
    sky();
    mountain();

    glColor3ub(242, 245, 243);
    glPushMatrix();
    glTranslatef(cloudP, 0.0f, 0.0f);
    cloud();
    glPopMatrix();
    glLoadIdentity();

    glPushMatrix();
    glTranslatef(sunP, 0.0f, 0.0f);

    glColor3ub(247, 232, 99);
    circle(0.0, .75, .09);
    glPopMatrix();
    glLoadIdentity();

    glColor3ub(150, 201, 38);
    ground();

    glColor3ub(47, 158, 68);

    river();
    glPushMatrix();
    glTranslatef(boatP, 0.0f, 0.0f);

    boat();
    glPopMatrix();
    glLoadIdentity();

    glLoadIdentity();

    glColor3ub(41, 140, 42);
    house();
    treeLeaf();
    tree();

    Idle();
    glFlush();
}


void summerNight()
{
    glClearColor(0.1f, 0.1f, 0.1f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3ub(148, 208, 242);

    mountain();

    glColor3ub(100, 100, 100);
    glPushMatrix();
    glTranslatef(cloudP, 0.0f, 0.0f);
    cloudNight();
    glPopMatrix();
    glLoadIdentity();

    glPushMatrix();
    glTranslatef(sunP, 0.0f, 0.0f);

    glColor3ub(200, 200, 200);
    circle(0.0, .75, .09);
    glPopMatrix();
    glLoadIdentity();

    glColor3ub(70, 71, 20);
    ground();

    glColor3ub(47, 158, 68);

    riverNight();

    glLoadIdentity();

    glColor3ub(41, 140, 42);
    house();
    treeLeaf();
    tree();

    Idle();
    glFlush();
}


void handleKeypress(unsigned char key, int x, int y)
{
    switch (key)
    {
    case  'd':
        glutDestroyWindow(1);
        glutInitWindowSize(800, 700);

        glutCreateWindow("village scenario");
        glutKeyboardFunc(handleKeypress);
        glutDisplayFunc(summer);

        glutPostRedisplay();
        break;

    case 'n':
        glutDestroyWindow(1);
        glutInitWindowSize(800, 700);

        glutCreateWindow("village scenario");
        glutKeyboardFunc(handleKeypress);
        glutDisplayFunc(summerNight);

        glutPostRedisplay();
        break;
    case 27: // Escape key
        exit(1);

    }
}


void StartingText()
{
    char text[120];

    sprintf(text, "UNIVERSITY OF INFORMATION TECHNOLOGY AND SCIENCES",5.00,8.00);
    glColor3f(0, 1, 0);
    glRasterPos2f( -35, 55 );
    for(int i = 0; text[i] != '\0'; i++)
    {
        if(text[i]==' '  && text[i+1]==' ')
        {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
            glRasterPos2f( -32, 02 );
        }
        else glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
    }

    sprintf(text, "VILLAGE SCENARIO",5.00,8.00);
    glColor3f(1, 1, 0);
    glRasterPos2f( -20, 45 );
    for(int i = 0; text[i] != '\0'; i++)
    {
        if(text[i]==' '  && text[i+1]==' ')
        {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
            glRasterPos2f( -32, 02 );
        }
        else glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
    }

    sprintf(text, "NAME: AKASH SHEIKH",5.00,8.00);
    glColor3f(1, 0, 0);
    glRasterPos2f( -20, 35 );
    for(int i = 0; text[i] != '\0'; i++)
    {
        if(text[i]==' '  && text[i+1]==' ')
        {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
            glRasterPos2f( -32, 02 );
        }
        else glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
    }
    sprintf(text, "ID: 1914551118",5.00,8.00);
    glColor3f(1, 0, 0);
    glRasterPos2f( -20, 30 );
    for(int i = 0; text[i] != '\0'; i++)
    {
        if(text[i]==' '  && text[i+1]==' ')
        {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
            glRasterPos2f( -32, 02 );
        }
        else glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
    }
    sprintf(text, "DEPARTMENT OF CSE",5.00,8.00);
    glColor3f(1, 0, 0);
    glRasterPos2f( -20, 25 );
    for(int i = 0; text[i] != '\0'; i++)
    {
        if(text[i]==' '  && text[i+1]==' ')
        {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
            glRasterPos2f( -32, 02 );
        }
        else glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
    }
    sprintf(text, "SUBMITTED TO-",5.00,8.00);
    glColor3f(0, 0, 1);
    glRasterPos2f( -20, 17 );
    for(int i = 0; text[i] != '\0'; i++)
    {
        if(text[i]==' '  && text[i+1]==' ')
        {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
            glRasterPos2f( -32, 02 );
        }
        else glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
    }
    sprintf(text, "SALIM SHADMAN ANKUR & PROPA PUNAM",5.00,8.00);
    glColor3f(0, 0, 1);
    glRasterPos2f( -10, 12 );
    for(int i = 0; text[i] != '\0'; i++)
    {
        if(text[i]==' '  && text[i+1]==' ')
        {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
            glRasterPos2f( -32, 02 );
        }
        else glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
    }
    sprintf(text, "PRESS 'd' FOR DAY MOOD",5.00,8.00);
    glColor3f(1, 0, 1);
    glRasterPos2f( -20, 0 );
    for(int i = 0; text[i] != '\0'; i++)
    {
        if(text[i]==' '  && text[i+1]==' ')
        {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
            glRasterPos2f( -32, 02 );
        }
        else glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
    }
    sprintf(text, " PRESS 'n' FOR NIGHT MOOD",5.00,8.00);
    glColor3f(1, 1, 1);
    glRasterPos2f( -21, -5 );
    for(int i = 0; text[i] != '\0'; i++)
    {
        if(text[i]==' '  && text[i+1]==' ')
        {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
            glRasterPos2f( -32, 02 );
        }
        else glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
    }
}


void Display1()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glClearColor(0,0,0,0);
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluOrtho2D(-60,60,-40,60);
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    glPushMatrix();
    StartingText();
    glEnd();
    glPopMatrix();
    glFlush();
    glutSwapBuffers();

}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutCreateWindow("Akash");
    glutReshapeWindow(800, 700);
    glutKeyboardFunc(handleKeypress);
    glShadeModel( GL_SMOOTH );
    glutDisplayFunc(Display1);
    glutTimerFunc(100, cloudUp, 0);
    glutTimerFunc(10, boatUp, 0);
    glutTimerFunc(10, sunUp, 0);

    glutMainLoop();
    return 0;
}
