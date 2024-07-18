#include <iostream>
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>

void myinit() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,700,0,700);
    glMatrixMode(GL_MODELVIEW);
}
void writeString(int x,int y,char *string)
{
    glColor3f(0,0,0);
    int len,i;
    glRasterPos2f(x,y);
    len=(int) strlen(string);
    for(i=0;i<len;i++){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,string[i]);
    }
    glFlush();
}

void computer()
{
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
        glVertex2f(80,350);
        glVertex2f(140,350);
        glVertex2f(140,400);
        glVertex2f(80,400);
    glEnd();

    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(75,345);
        glVertex2f(75,405);
        glVertex2f(145,405);
        glVertex2f(145,345);
    glEnd();

    glColor3f(0,0,0);
    glBegin(GL_QUADS);
        glVertex2f(85,340);
        glVertex2f(135,340);
        glVertex2f(140,335);
        glVertex2f(80,335);
    glEnd();
    writeString(85,420,"ALICE");
    
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
        glVertex2f(570,350);
        glVertex2f(630,350);
        glVertex2f(630,400);
        glVertex2f(570,400);
    glEnd();

    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(565,345);
        glVertex2f(635,345);
        glVertex2f(635,405);
        glVertex2f(565,405);
    glEnd();

    glColor3f(0,0,0);
    glBegin(GL_QUADS);
        glVertex2f(575,340);
        glVertex2f(625,340);
        glVertex2f(630,335);
        glVertex2f(570,335);
    glEnd();
    writeString(580,420,"BOB");
    
    
    glColor3f(1,0.0,0.0);
    glBegin(GL_QUADS);
        glVertex2f(320,600);
        glVertex2f(380,600);
        glVertex2f(380,650);
        glVertex2f(320,650);
    glEnd();

    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(315,595);
        glVertex2f(385,595);
        glVertex2f(385,655);
        glVertex2f(315,655);
    glEnd();

    glColor3f(0,0,0);
    glBegin(GL_QUADS);
        glVertex2f(325,590);
        glVertex2f(375,590);
        glVertex2f(380,585);
        glVertex2f(320,585);
    glEnd();
    writeString(305,670,"INTRUDER");
}

void home()
{
     glClearColor(0.8, 1.0, 1.0, 1.0);
     glClear(GL_COLOR_BUFFER_BIT);
     computer();
     glFlush();
}

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

void clearArea(int u,int v,int w,int x)
{
    glColor3f(0.8, 1.0, 1.0);
    glBegin(GL_QUADS);
        glVertex2f(u,w);
        glVertex2f(v,w);
        glVertex2f(v,x);
        glVertex2f(u,x);
    glEnd();
}

void publicColor()
{
    glColor3f(1,1,0.0);
    glBegin(GL_QUADS);
        glVertex2f(80,325);
        glVertex2f(140,325);
        glVertex2f(140,300);
        glVertex2f(80,300);
    glEnd();

    glColor3f(1,1,0.0);
    glBegin(GL_QUADS);
        glVertex2f(570,325);
        glVertex2f(630,325);
        glVertex2f(630,300);
        glVertex2f(570,300);
    glEnd();

    glColor3f(1,1,0.0);
    glBegin(GL_QUADS);
        glVertex2f(320,575);
        glVertex2f(380,575);
        glVertex2f(380,555);
        glVertex2f(320,555);
    glEnd();
    glFlush();
}

void privateColor(){
    glColor3f(1,0,0);
    glBegin(GL_QUADS);
        glVertex2f(80,290);
        glVertex2f(140,290);
        glVertex2f(140,265);
        glVertex2f(80,265);
    glEnd();
    
    glColor3f(0,0,1.0);
    glBegin(GL_QUADS);
        glVertex2f(570,290);
        glVertex2f(630,290);
        glVertex2f(630,265);
        glVertex2f(570,265);
    glEnd();
    glFlush();

}

void mixPublicPrivate()
{
    glColor3f(1,0.49,0);  // Alice orange
    glBegin(GL_QUADS);
        glVertex2f(80,325);
        glVertex2f(140,325);
        glVertex2f(140,300);
        glVertex2f(80,300);
    glEnd();
    
    glColor3f(0,0.6,0.0);  //  Bob green
    glBegin(GL_QUADS);
        glVertex2f(570,325);
        glVertex2f(630,325);
        glVertex2f(630,300);
        glVertex2f(570,300);
    glEnd();
    glFlush();
}

float pos1 = 80;
float pos2 = 140;
float pos3 = 570;
float pos4 = 630;
float ipos1=240;
float ipos2=300;
float ipos3=400;
float ipos4=460;

void moveHorizontal(){
    int i=0;
    int j=630;
    while (i<490 && j>80)
    {
        glColor3f(1,0.49,0);  // Alice orange
        glBegin(GL_QUADS);
            glVertex2f(pos1,325);
            glVertex2f(pos2,325);
            glVertex2f(pos2,300);
            glVertex2f(pos1,300);
        glEnd();

        delay(1);
        clearArea(pos1-70,pos2-65,325,300);

        pos1+=1;
        pos2+=1;
        i+=1;

        glColor3f(0,0.6,0.0);  //  Bob green
        glBegin(GL_QUADS);
            glVertex2f(pos3,325);
            glVertex2f(pos4,325);
            glVertex2f(pos4,300);
            glVertex2f(pos3,300);
        glEnd();

        delay(1);
        clearArea(pos3+60,pos4+65,325,300);
        pos3-=1;
        pos4-=1;
        j-=1;
            
        glFlush();
    }

}

void moveVertical(){
    int m=0;

    float ipos1=325;
    float ipos2=300;

    while (m<250)
    {
        glColor3f(1,0.49,0);  // Alice orange
        glBegin(GL_QUADS);
            glVertex2f(240,ipos1);
            glVertex2f(300,ipos1);
            glVertex2f(300,ipos2);
            glVertex2f(240,ipos2);
        glEnd();
        
        glColor3f(0,0.6,0.0);  //  Bob green
        glBegin(GL_QUADS);
            glVertex2f(400,ipos1);
            glVertex2f(460,ipos1);
            glVertex2f(460,ipos2);
            glVertex2f(400,ipos2);
        glEnd();
        glFlush();

        delay(2);
        clearArea(240,300,ipos1-20,ipos2-20);
        clearArea(400,460,ipos1-20,ipos2-20);
        ipos1+=1;
        ipos2+=1;
        m+=1;
        glFlush();
    }
    
}
void mixPrivateShared()
{
    delay(500);
    clearArea(80,140,265,290);
    glColor3f(0.6,0.29,0.0);  // Alice brown
    glBegin(GL_QUADS);
        glVertex2f(80,325);
        glVertex2f(141,325);
        glVertex2f(141,300);
        glVertex2f(80,300);
    glEnd();
    
    clearArea(570,630,265,290);
    glColor3f(0.6,0.29,0.0);  // Bob brown
    glBegin(GL_QUADS);
        glVertex2f(564,325);
        glVertex2f(630,325);
        glVertex2f(630,300);
        glVertex2f(564,300);
    glEnd();
    glFlush();
}

void establishCon(){
  glColor3f(0, 1, 0);

  for (int i = 180; i < 530; i++) {
    glBegin(GL_POLYGON);
      glVertex2i(i, 380);
      glVertex2i(i + 1, 380);
      glVertex2i(i + 1, 390);
      glVertex2i(i, 390);
    glEnd();
    glFlush();
    delay(1);
  }
    writeString(240,280,"CONNECTION ESTABLISHED");
}

void display() {
    glClearColor(0.8, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    
    writeString(240,550,"Diffie-Hellman Key Exchange");
    writeString(250,350,"Prajwal S R - 1RN22CS413");
    writeString(250,320,"Revanth H S - 1RN22CS414");
    writeString(320,020,"'S' to start >>");
    glFlush();
}

void keyfunc (unsigned char key, int x, int y)
{
   switch(key) {
      case 'S' :
      case 's' :home();break;
    }
}

void menu(int id){
    switch (id) {
        case 1:clearArea(215,500,340,390); publicColor();
            break;
        case 2:privateColor();
            break;
        case 3:mixPublicPrivate();
            break;
        case 4:moveHorizontal();moveVertical();
            break;
        case 5:mixPrivateShared();
            break;
        case 6:establishCon();
            break;
        default:
            exit(0);
    }

}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(1000,700);
    glutCreateWindow("Diffie-Hellman Key Exchange");
    myinit();

    glutKeyboardFunc(keyfunc);
    glutCreateMenu(menu);
    glutAddMenuEntry("1.Select public keys",1);
    glutAddMenuEntry("2.Choose private keys",2);
    glutAddMenuEntry("3.Mix public & private keys",3);
    glutAddMenuEntry("4.Exchange mix keys",4);
    glutAddMenuEntry("5.Mix private & shared keys",5);
    glutAddMenuEntry("6.Establish connection",6);
    glutAddMenuEntry("7.Quit",7);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutDisplayFunc(display);
    glutMainLoop();
    
    return 0;
}


