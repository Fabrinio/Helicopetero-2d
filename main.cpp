
#include <GL/glut.h>
#include <Gl/gl.h>
#include<math.h>



GLfloat tranx, trany = 0;
void init(void)
{
    glClearColor(0,0,0,1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,500,0,500);
    glMatrixMode(GL_MODELVIEW);
}
void janela(int x, int y)
{
    float th;
    glBegin(GL_LINE_LOOP);
     for(int i=0;i<360;i++)
     {
        th=i*3.142/180;
        glVertex2f(x+15*cos(th), y+15*sin(th));
     }
    glEnd();
}
void heli (void)
{
    glPushMatrix();
    glTranslated(tranx, trany, 0);
   // base helicopetero
   glBegin(GL_LINE_LOOP);
    glVertex2f(340,220);
    glVertex2f(220, 220);
   glEnd();
   // parte que vai para cima
   glBegin(GL_LINE_LOOP);
    glVertex2f(400,230);
    glVertex2f(340,220);
   glEnd();
   // parte1 que coneceta com o corpo
   glBegin(GL_LINE_LOOP);
    glVertex2f(330,220);
    glVertex2f(330,240);
   glEnd();
   // parte2 que coneceta com o corpo
   glBegin(GL_LINE_LOOP);
    glVertex2f(240,220);
    glVertex2f(240,240);
   glEnd();

  //corpo helicoptero
  glBegin(GL_LINE_LOOP);
    glVertex2f(400,240);
    glVertex2f(225,240);
    glVertex2f(205,310);
    glVertex2f(120,310);
    glVertex2f(115,300);
    glVertex2f(100,300);
    glVertex2f(110,315);
    glVertex2f(100,345);
    glVertex2f(115,345);
    glVertex2f(120,325);
    glVertex2f(200,325);
    glVertex2f(220,340);
    glVertex2f(325,340);
    glVertex2f(340,300);
   glEnd();
   //helice esquerda
   glBegin(GL_LINE_LOOP);
    glVertex2f(270,340);
    glVertex2f(270,370);
    glVertex2f(160,390);
   glEnd();
//helice direita
   glBegin(GL_LINE_LOOP);
    glVertex2f(270,340);
    glVertex2f(270,370);
    glVertex2f(380,390);
   glEnd();
// janela piloto parte cima
   glBegin(GL_LINE_LOOP);
    glVertex2f(335,310);
    glVertex2f(315,310);
   glEnd();
// janela piloto parte baixo
   glBegin(GL_LINE_LOOP);
    glVertex2f(315,310);
    glVertex2f(315,285);
   glEnd();
   janela(240,300);
   janela(280,300);
   glPopMatrix();
}


static void display(void)
{

    glColor3f(1,0,1);
    glClear(GL_COLOR_BUFFER_BIT);
    heli();
    glFlush();
}

void teclado(unsigned char teclas, GLint x, GLint Y){
switch(teclas){
case 'w':
    trany+=3;
    break;
case 's':
    trany-=3;
    break;
case 'a':
    tranx-=3;
    break;
case 'd':
    tranx+=3;
    break;
}
glutPostRedisplay();
}





int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB| GLUT_SINGLE);
    glutCreateWindow("Helicopetero");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(teclado);
    display();
    glutIdleFunc(heli);
    glutMainLoop();
    return 0;
}
