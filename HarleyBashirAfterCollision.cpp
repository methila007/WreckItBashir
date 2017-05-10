/* This is WreckItBashir. My project for Computer Graphics course. */


#include <GL/glut.h>
#include <iostream>

using namespace std;

class window
{
public:
    int x;
    int y;
    bool isBroken = false;
    void drawWindow(int p, int q)
    {
        if(!isBroken)
            glColor3ub(180, 255, 255);
        else
            glColor3ub(0, 0, 0);

        glBegin(GL_QUADS);
            glVertex2i(p, q);
            glVertex2i(p+40, q);
            glVertex2i(p+40, q+50);
            glVertex2i(p, q+50);
        glEnd();

        x = p+350-70;
        y = q-100;


    }

    void checkStatus(int a, int b)
    {
        if(a+5>x && a-5<x+40)
        {
            if(b+5>y && b-5<y+50)
                isBroken = true;
        }

        cout << a << " " << b << "      " << x << " " << y << endl;
    }
};

float counter = 0.0;

void initRendering()
{
    glEnable(GL_DEPTH_TEST);
    glEnable (GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

}

void handleResize(int w, int h)
{

    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 1.1, 5001.1);
}
float _angle = 0.0;
int _camera_angle = 0;
int bashX = 0;
int bashY = 0;
int quinX = 0;
int quinY = 0;
float hit = 0;
float fix = 0;
bool breakWindow = false;
window w[25];

void update(int value)
{
    _angle += .50f;
	if (_angle > 360) {
		_angle -= 360;
	}

    counter += 6;

   if ( counter > 2000)
    counter = -2000;

    glutPostRedisplay();
    glutTimerFunc(800, update, 0);//21022before it was 500, but made it 50 to make the clouds movement smooth

    hit = 0;
    breakWindow = false;
}

GLUquadricObj *cyl = gluNewQuadric();

void bashir()
{
    //body
    glColor3ub(245,136,85);
    glPushMatrix();
    //glRotatef(5, 1.0, 01.0, 0.0);
    glScalef(1.1, 1.9, .7);
    glutSolidCube(100);
    glPopMatrix();

//left hand
//sphre

    glPushMatrix();
    glColor3ub(100, 100, 120);
    glTranslatef(-40, 50, 0);
    //glScalef(.35, 1, .3);
    glutSolidSphere(20, 50, 50);
    glPopMatrix();

//hand upper part

    glPushMatrix();
    glColor3ub(255,129,68);
    glTranslatef(-50, 50, 0);
    glRotatef(45, 0.0, -1.0, 0.0);
    //glScalef(.35, 1, .3);
    gluCylinder(cyl, 25, 20, 100, 50, 50);
    glPopMatrix();

//sphere
    glPushMatrix();
    glColor3ub(255,129,68);
    glTranslatef(-120, 50, 70);
    //glScalef(.35, 1, .3);
    glutSolidSphere(20, 50, 50);
    glPopMatrix();

//lower part

    glPushMatrix();
    glColor3ub(247, 172, 128);
    glTranslatef(-125, 50, 70);
    glRotatef(45, 0.0, -1.0, 0.0);
    //glScalef(.35, 1, .3);
    gluCylinder(cyl, 20, 30, 100, 50, 50);
    glPopMatrix();

//fist

    glPushMatrix();
    glColor3ub(247, 172, 128);
    glTranslatef(-200, 50, 160);
    glRotatef(45, 0.0, -1.0, 0.0);
    //glScalef(.35, 1, .3);
    glutSolidCube(60);
    glPopMatrix();

//right hand
//sphre

    glPushMatrix();
   glColor3ub(255,129,68);
    glTranslatef(40, 50, 0);
    //glScalef(.35, 1, .3);
    glutSolidSphere(20, 50, 50);
    glPopMatrix();

//hand upper part

    glPushMatrix();
   glColor3ub(255,129,68);
    glTranslatef(50, 50, 0);
    glRotatef(-45, 0.0, -1.0, 0.0);
    //glScalef(.35, 1, .3);
    gluCylinder(cyl, 20, 16, 100, 50, 50);
    glPopMatrix();

//sphere
    glPushMatrix();
    glColor3ub(255,129,68);
    glTranslatef(120, 50, 70);
    //glScalef(.35, 1, .3);
    glutSolidSphere(20, 50, 50);
    glPopMatrix();

//lower part

    glPushMatrix();
    glColor3ub(247, 172, 128);
    glTranslatef(125, 50, 70);
    glRotatef(-45, 0.0, -1.0, 0.0);
    //glScalef(.35, 1, .3);
    gluCylinder(cyl, 20, 30, 100, 50, 50);
    glPopMatrix();

//fist

    glPushMatrix();
     glColor3ub(247, 172, 128);
    glTranslatef(200, 50, 160);
    glRotatef(-45, 0.0, -1.0, 0.0);
    //glScalef(.35, 1, .3);
    glutSolidCube(60);
    glPopMatrix();


//l leg
    glPushMatrix();
    //glRotatef(5, 1.0, 01.0, 0.0);
    glColor3ub(99,18, 31);
    glTranslatef(-37, -100, 0);
    glScalef(.35, 1.3, .3);
    glutSolidCube(100);
    glPopMatrix();

//sphre

    glPushMatrix();
    glColor3ub(61, 15,21);
    glTranslatef(37, -165, 0);
    //glScalef(.35, 1, .3);
    glutSolidSphere(20, 50, 50);
    glPopMatrix();

//lower part

 glPushMatrix();
     glColor3ub(99,18, 31);
    glTranslatef(37, -200, 0);
    glScalef(.35, 1.1, .3);
    glutSolidCube(100);
    glPopMatrix();


    glPushMatrix();
     glColor3ub(0,0,0);
    glTranslatef(37, -250, 0);
    glRotatef(90, -1.0, 0.0, 0.0);
    //glScalef(.35, 1.1, .3);
    glutSolidSphere(30,20,20);
    glPopMatrix();



//r leg

    glPushMatrix();
     glColor3ub(99,18, 31);
    glTranslatef(37, -100, 0);
    glScalef(.35, 1.3, .3);
    glutSolidCube(100);
    glPopMatrix();


//sphre

    glPushMatrix();
    glColor3ub(61, 15,21);
    glTranslatef(-37, -165, 0);
    //glScalef(.35, 1, .3);
    glutSolidSphere(20, 50, 50);
    glPopMatrix();

//lower part

 glPushMatrix();
     glColor3ub(99,18, 31);
    glTranslatef(-37, -200, 0);
    glScalef(.35, 1.1, .3);
    glutSolidCube(100);
    glPopMatrix();



    glPushMatrix();
     glColor3ub(0,0,0);
    glTranslatef(-40, -250, 0);
    glRotatef(90, -1.0, 0.0, 0.0);
    //glScalef(.35, 1.1, .3);
    glutSolidSphere(30,50,50);
    glPopMatrix();

//neck

    glPushMatrix();
    glColor3ub(247, 172, 128);
    glTranslatef(0, 100, 0);
    glRotatef(-90, 1.0, 0.0, 0.0);
    gluCylinder(cyl, 20, 16, 20, 50, 50);
    glPopMatrix();

//head

    glPushMatrix();
    glColor3ub(247, 172, 128);
    glTranslatef(0, 165, 0);
    glScalef(.9, 1.1, .7);
    glutSolidSphere(50, 50, 50);
    glPopMatrix();

glPushMatrix();
    glColor3ub(0,0,0);
    glTranslatef(0, 165, -5);
    glScalef(.9, 1.1, .7);
    glutSolidSphere(50, 50, 50);
    glPopMatrix();


    //eyes

    glPushMatrix();
    glColor3ub(255,255,255);
    glTranslatef(5, 165, 30);
    glScalef(.9, 1.1, .7);
    glutSolidSphere(12, 50, 50);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(0,0,0);
    glTranslatef(5, 165, 40);
    glScalef(.9, 1.1, .7);
    glutSolidSphere(8, 50, 50);
    glPopMatrix();




   glPushMatrix();
    glColor3ub(255,255,255);
    glTranslatef(-30, 165, 30);
    glScalef(.9, 1.1, .7);
    glutSolidSphere(12, 50, 50);
    glPopMatrix();

glPushMatrix();
    glColor3ub(0,0,0);
    glTranslatef(-30, 165, 40);
    glScalef(.9, 1.1, .7);
    glutSolidSphere(8, 50, 50);
    glPopMatrix();




   glBegin(GL_LINE);
   glColor3ub(0,0,0);
   glVertex3d(-30,150,40);
   glVertex3d(30,150,40);

glEnd();


//hair





glPushMatrix();
    glColor3ub(0,0,0);
    glTranslatef(0, 200, 0);
    glRotatef(90, -1.0, 0.0, 1.0);
    glScalef(.9, 1.1, .7);
    glutSolidCone(20, 100, 50,20);
    glPopMatrix();
glPushMatrix();
    glColor3ub(0,0,0);
    glTranslatef(5, 200, 0);
    glRotatef(110, -1.0, 0.0, 1.0);
    glScalef(.9, 1.1, .7);
    glutSolidCone(20, 100, 50,20);
    glPopMatrix();

glPushMatrix();
    glColor3ub(0,0,0);
    glTranslatef(-10, 200, 0);
    glRotatef(90, -1.0, 0.0, 1.0);
    glScalef(.9, 1.1, .7);
    glutSolidCone(20, 100, 50,20);
    glPopMatrix();

glPushMatrix();
    glColor3ub(0,0,0);
    glTranslatef(30, 190, 0);
    glRotatef(-180, 1.0, 0.0, 1.0);
    glScalef(.9, 1.1, .7);
    glutSolidCone(20, 100, 50,20);
    glPopMatrix();





glPushMatrix();
    glColor3ub(0,0,0);
    glTranslatef(4, 195, 0);
    glRotatef(90, -1.0, 0.0, 1.0);
    glScalef(.9, 1.1, .7);
    glutSolidCone(20, 100, 50,20);
    glPopMatrix();

glPushMatrix();
    glColor3ub(0,0,0);
    glTranslatef(30, 200, 0);
    glRotatef(80, -1.0, 0.0, 1.0);
    glScalef(.9, 1.1, .7);
    glutSolidCone(20, 100, 50,20);
    glPopMatrix();

glPushMatrix();
    glColor3ub(0,0,0);
    glTranslatef(20, 200, 0);
    glRotatef(65, -1.0, 0.0, 1.0);
    glScalef(.9, 1.1, .7);
    glutSolidCone(20, 100, 50,20);
    glPopMatrix();



glPushMatrix();
    glColor3ub(0,0,0);
    glTranslatef(10, 200, 0);
    glRotatef(90, -1.0, 0.0, 1.0);
    glScalef(.9, 1.1, .7);
    glutSolidCone(20, 100, 50,20);
    glPopMatrix();



glPushMatrix();
    glColor3ub(0,0,0);
    glTranslatef(0, 210, 0);
    glRotatef(90, -1.0, 0.0, 1.0);
    glScalef(.9, 1.1, .7);
    glutSolidCone(20, 100, 50,20);
    glPopMatrix();


glPushMatrix();
    glColor3ub(0,0,0);
    glTranslatef(-20, 210, 0);
    glRotatef(-180, -1.0, 0.0, 1.0);
    glScalef(.9, 1.1, .7);
    glutSolidCone(20, 100, 50,20);
    glPopMatrix();


}

void quinn()
{
    //hat

 glPushMatrix();
    glColor3ub(255,19,70);
    glTranslatef(-40, 170, 1);
    glRotatef(-60, -1.0, 1.0, 0.0);
    //glScalef(1, 1.5, 1);
    glutSolidCone(20,82,50,20);
    glPopMatrix();


//hat


 glPushMatrix();
    glColor3ub(0,0,0);
    glTranslatef(40, 170, 1);
    glRotatef(60, 1.0, 1.0, 0.0);
    //glScalef(1, 1.5, 1);
    glutSolidCone(20,82,50,20);
    glPopMatrix();


   //hat
    glPushMatrix();
    glColor3ub(0,0,0);
    glTranslatef(0, 130, 1);
    glRotatef(360, -1.0, 0.0, 0.0);
    //glScalef(1, 1.5, 1);
    glutSolidTorus(30,30,50,20);
    glPopMatrix();

    //glRotatef(_angle, 0.0, 1.0, 0.0);


   //head

    glPushMatrix();
    glColor3ub(255,207,185);
    glTranslatef(0, 125, 1);
    glRotatef(260, -1.0, 0.0, 0.0);
    //glScalef(1, 1.5, 1);
    glutSolidSphere(50,50,20);
    glPopMatrix();

glPushMatrix();
    glColor3ub(0,0,0);
    glTranslatef(0, 125, -10);
    glRotatef(260, -1.0, 0.0, 0.0);
    //glScalef(1, 1.5, 1);
    glutSolidSphere(50,50,20);
    glPopMatrix();




    //glRotatef(_angle, 0.0, 1.0, 0.0);


    //eyes
glPushMatrix();
    glColor3ub(0,0,0);
    glTranslatef(-50, 125, 60);
    glRotatef(90, 0.0, 1.50, 0.0);
    //glScalef(1, 1.5, 1);
    glutSolidCone(20,60,20,20);
    glPopMatrix();

glPushMatrix();
    glColor3ub(0,0,0);
    glTranslatef(50, 125, 60);
    glRotatef(-90, 0.0, 1.50, 0.0);
    //glScalef(1, 1.5, 1);
    glutSolidCone(20,60,20,20);
    glPopMatrix();


glPushMatrix();
    glColor3ub(153,217,235);
    glTranslatef(20, 119, 70);
    glRotatef(-90, 0.0, 1.50, 0.0);
    //glScalef(1, 1.5, 1);
    glutSolidSphere(8,20,20);
    glPopMatrix();

glPushMatrix();
    glColor3ub(153,217,235);
    glTranslatef(-20, 119, 70);
    glRotatef(-90, 0.0, 1.50, 0.0);
    //glScalef(1, 1.5, 1);
    glutSolidSphere(8,20,20);
    glPopMatrix();


//head
    glPushMatrix();
    glColor3ub(255,19,70);
    glTranslatef(0, 75, 1);
    glRotatef(90, -1.0, 0.0, 0.0);
    //glScalef(1, 1.5, 1);
    gluCylinder(cyl, 15, 15, 20, 50, 50);
    glPopMatrix();


//neck
    glPushMatrix();
    glColor3ub(255,207,185);
    glTranslatef(0, 75, 1);
    glRotatef(90, -1.0, 0.0, 0.0);
    //glScalef(1, 1.5, 1);
    gluCylinder(cyl, 15, 15, 20, 50, 50);
    glPopMatrix();



//body upper cone
    glPushMatrix();
    glColor3ub(255,207,185);
    glTranslatef(0, 62, 1);
    glRotatef(90, -1.0, 0.0, 0.0);
    //glScalef(1, 1.5, 1);
    glutSolidCone(55, 20, 30, 30);
    glPopMatrix();


//body cube
    glPushMatrix();
    glColor3ub(0,0,0);
    //glRotatef(90, 1.0, 0.0, 0.0);
    glScalef(1, 1.2, 1);
    glutSolidCube(100);
    glPopMatrix();




//body cone
    glPushMatrix();
    glColor3ub(0,0,0);
    glTranslatef(1, -90, 1);
    glRotatef(90, -1.0, 0.0, 0.0);
    //glScalef(1, 1.5, 1);
    glutWireCone(100, 160, 30, 50);
    glPopMatrix();

//body cone
    glPushMatrix();
    glColor3ub(255,19,70);
    glTranslatef(1, -90, 1);
    glRotatef(90, -1.0, 0.0, 0.0);
    //glScalef(1, 1.5, 1);
    glutSolidCone(100, 140, 30, 30);
    glPopMatrix();




//left leg
    glPushMatrix();
    glColor3ub(255,207,185);
    glTranslatef(-30, -200, 1);
    glRotatef(90, -1.0, 0.0, 0.0);
    //glScalef(1, 1.5, 1);
    //glutSolidCone(110, 150, 30, 30);
    gluCylinder(cyl, 15, 15, 150, 50, 50);
    glPopMatrix();


    glPushMatrix();
    glColor3ub(255,19,70);
    glTranslatef(-30, -200, 1);
    glRotatef(90, -1.0, 0.0, 0.0);
    //glScalef(1, 1.5, 1);
    //glutSolidCone(110, 150, 30, 30);
    glutSolidSphere(20,20,20);
    glPopMatrix();



//left leg
    glPushMatrix();
    glColor3ub(255,207,185);
    glTranslatef(30, -200, 1);
    glRotatef(90, -1.0, 0.0, 0.0);
    //glScalef(1, 1.5, 1);
    //glutSolidCone(110, 150, 30, 30);
    gluCylinder(cyl, 15, 15, 150, 50, 50);
    glPopMatrix();


glPushMatrix();
    glColor3ub(0,0,0);
    glTranslatef(30, -200, 1);
    glRotatef(90, -1.0, 0.0, 0.0);
    //glScalef(1, 1.5, 1);
    //glutSolidCone(110, 150, 30, 30);
    glutSolidSphere(20,20,20);
    glPopMatrix();






//hand

glPushMatrix();
    glColor3ub(255,19,70);
    glTranslatef(-40,40, 1);
    glRotatef(850, -1.0, 0.0, 1.0);
    //glScalef(-1, 1.5, 1);
    //glutSolidCone(110, 150, 30, 30);
    gluCylinder(cyl, 15, 15, 110, 50, 50);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(255,19,70);
    glTranslatef(-130,100, 5);
    glRotatef(850, -1.0, 0.0, 1.0);
    //glScalef(-1, 1.5, 1);
    //glutSolidCone(110, 150, 30, 30);
    glutSolidSphere(20,20,20);
    glPopMatrix();




//hand
glPushMatrix();
    glColor3ub(0,0,0);
    glTranslatef(130,-10, 1);
    glRotatef(850, -1.0, 0.0, 1.0);
    //glScalef(-1, 1.5, 1);
    //glutSolidCone(110, 150, 30, 30);
    gluCylinder(cyl, 15, 15, 110, 50, 50);
    glPopMatrix();

glPushMatrix();
glColor3ub(0,0,0);
    glTranslatef(130,-5, 1);
    glRotatef(850, -1.0, 0.0, 1.0);
    //glScalef(-1, 1.5, 1);
    //glutSolidCone(110, 150, 30, 30);
    glutSolidSphere(20,20,20);
    glPopMatrix();





//hammer


glPushMatrix();
glColor3ub(0,0,0);
    glTranslatef(300,-5, 1);
    glRotatef(-180, -1.0, 0.0, 1.0);
    //glScalef(-1, 1.5, 1);
    //glutSolidCone(110, 150, 30, 30);
    gluCylinder(cyl, 15, 5, 210, 50, 50);
    glPopMatrix();



glPushMatrix();
glColor3ub(255,19,70);
    glTranslatef(300,-5, 1);
    glRotatef(-180, -1.0, 0.0, 1.0);
    //glScalef(-1, 1.5, 1);
    //glutSolidCone(110, 150, 30, 30);
    glutSolidCube(70);
    glPopMatrix();
}

void bird()
{

//bird
glTranslatef ( -counter*5 , 0.0 , 0.0 );
    //beck
    glPushMatrix();
    glColor3ub(0, 0, 0);
    glTranslatef(-27, 0, 0);
    glRotatef(45, 0, -1, 0);
    glutSolidCone(13, 30, 30, 30);
    glPopMatrix();

    //tail
    glPushMatrix();
    glColor3ub(155, 255, 1);
    glTranslatef(40, 20, 0);
    glRotatef(30, 0, 0, 1);
    glScalef(1, .4, 1);
    gluCylinder(cyl, 30, 10, 5, 50, 50);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(40, 0, 0);
    //glRotatef(30, 0, 0, 1);
    glScalef(1, .4, 1);
    gluCylinder(cyl, 30, 10, 5, 50, 50);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(40, -20, 0);
    glRotatef(30, 0, 0, -1);
    glScalef(1, .4, 1);
    gluCylinder(cyl, 30, 10, 5, 50, 50);
    glPopMatrix();

    //head
    glPushMatrix();
    glColor3ub(255, 242, 0);
    //glScalef(1, .8, 1);
    glutSolidSphere(35, 60, 60);
    glPopMatrix();



    //wings
    glPushMatrix();
    glColor3ub(155, 255, 1);
    glTranslatef(4, -4, 30);
    glRotatef(-90, -1, 0, 0);
    glScalef(1, .3, 1);
    gluCylinder(cyl, 17, 7, 40, 50, 50);
    //glutSolidCone(15, 30, 20, 20);
    glPopMatrix();

    //wing 2
    glPushMatrix();
    glColor3ub(1, 255, 1);
    glTranslatef(0, 60, 0);
    glRotatef(90, 1, 0, 0);
    glScalef(1, .3, 1);
    gluCylinder(cyl, 7, 15, 35, 50, 50);
    //glutSolidCone(15, 30, 20, 20);
    glPopMatrix();

    //eye
    glPushMatrix();
    glColor3ub(1,1,1);
    glTranslatef(-7, 10, 32);
    glRotatef(-90, -1, 0, 0);
    glScalef(1, .3, 1);
    glutSolidSphere(5, 60, 60);
    //glutSolidCone(15, 30, 20, 20);
    glPopMatrix();


}

void tree()
{
    //body cone
    glPushMatrix();
    glColor3ub(0,79,0);
    glTranslatef(1, -90, 1);
    glRotatef(90, -1.0, 0.0, 0.0);
    //glScalef(1, 1.5, 1);
    glutSolidCone(90, 140, 30, 30);
    glPopMatrix();

glPushMatrix();
    glColor3ub(0,117,0);
    glTranslatef(1, -40, 1);
    glRotatef(90, -1.0, 0.0, 0.0);
    //glScalef(1, 1.5, 1);
    glutSolidCone(80, 140, 30, 30);
    glPopMatrix();

glPushMatrix();
    glColor3ub(0,169,0);
    glTranslatef(1, 0, 1);
    glRotatef(90, -1.0, 0.0, 0.0);
    //glScalef(1, 1.5, 1);
    glutSolidCone(70, 140, 30, 30);
    glPopMatrix();

glPushMatrix();
    glColor3ub(0,210,0);
    glTranslatef(1, 40, 1);
    glRotatef(90, -1.0, 0.0, 0.0);
    //glScalef(1, 1.5, 1);
    glutSolidCone(60, 110, 30, 30);
    glPopMatrix();

 glPushMatrix();

    glColor3ub(106,48,0);
    glTranslatef(5, -200, 1);
    glRotatef(90, -1.0, 0.0, 0.0);
    //glScalef(1, 1.5, 1);
    //glutSolidCone(110, 150, 30, 30);
    gluCylinder(cyl, 15, 15, 150, 50, 50);
    glPopMatrix();
}
void cloud()
{


    glPushMatrix();
    glTranslatef ( counter/2 , 0.0 , 0.0 );
    glColor3ub(199, 240, 249);
    glTranslatef(-650, 1050, -500);
    glScalef(1.1, .5, .7);
    glutSolidSphere(70, 50, 50);
    glPopMatrix();

        glPushMatrix();
        glTranslatef ( counter/2 , 0.0 , 0.0 );
    glColor3ub(199, 240, 249);
    glTranslatef(-650, 990, -500);
    glScalef(1.1, .5, .7);
    glutSolidSphere(100, 50, 50);
    glPopMatrix();

        glPushMatrix();
        glTranslatef ( counter/2 , 0.0 , 0.0 );
    glColor3ub(199, 240, 249);
    glTranslatef(-790, 1040, -500);
    glScalef(1.1, .7, .7);
    glutSolidSphere(70, 50, 50);
    glPopMatrix();


//set 2

    glPushMatrix();
    glTranslatef ( counter*0.5 , 0.0 , 0.0 );
    glColor3ub(199, 240, 249);
    glTranslatef(440, 1040, -500);
    glScalef(1.1, .7, .7);
    glutSolidSphere(70, 50, 50);
    glPopMatrix();

    glPushMatrix();
    glTranslatef ( counter*0.5 , 0.0 , 0.0 );
    glColor3ub(199, 240, 249);
    glTranslatef(290, 1050, -500);
    glScalef(1.1, .5, .7);
    glutSolidSphere(70, 50, 50);
    glPopMatrix();

    glPushMatrix();
    glTranslatef ( counter*0.5 , 0.0 , 0.0 );
    glColor3ub(199, 240, 249);
    glTranslatef(350, 990, -500);
    glScalef(1.1, .5, .7);
    glutSolidSphere(100, 50, 50);
    glPopMatrix();


//set 3

    glPushMatrix();
    glTranslatef ( counter*1.5 , 0.0 , 0.0 );
    glColor3ub(199, 240, 249);
    glTranslatef(350, 800+500, -3500);
    glScalef(1.1*2, .5*2, .7*2);
    glutSolidSphere(100, 50, 50);
    glPopMatrix();

    glPushMatrix();
    glTranslatef ( counter*1.5 , 0.0 , 0.0 );
    glColor3ub(199, 240, 249);
    glTranslatef(450, 850+500, -3500);
    glScalef(1.1*2, .5*2, .7*2);
    glutSolidSphere(100, 50, 50);
    glPopMatrix();


    glPushMatrix();
    glTranslatef ( counter*1.5 , 0.0 , 0.0 );
    glColor3ub(199, 240, 249);
    glTranslatef(470, 750+500, -3500);
    glScalef(1.1*2, .5*2, .7*2);
    glutSolidSphere(100, 50, 50);
    glPopMatrix();

    glPushMatrix();
    glTranslatef ( counter*1.5 , 0.0 , 0.0 );
    glColor3ub(199, 240, 249);
    glTranslatef(570, 800+500, -3500);
    glScalef(1.1*2, .5*2, .7*2);
    glutSolidSphere(100, 50, 50);
    glPopMatrix();


//set 4

    glPushMatrix();
    glTranslatef ( counter*2 , 0.0 , 0.0 );
    glColor3ub(199, 240, 249);
    glTranslatef(-850-500-400, 800+600, -3500);
    //glScalef(1.1*3, .5, .7);
    glutSolidSphere(200, 50, 50);
    glPopMatrix();


   /* glPushMatrix();
    glTranslatef ( counter*2 , 0.0 , 0.0 );
    glColor3ub(199, 240, 249);
    glTranslatef(-850-500, 800+600, -3500);
   // glScalef(1.1*3, .5, .7);
    glutSolidSphere(100, 50, 50);
    glPopMatrix();

    glPushMatrix();
    glTranslatef ( counter*2 , 0.0 , 0.0 );
    glColor3ub(199, 240, 249);
    glTranslatef(-950-500, 850+600, -3500);
    //glScalef(1.1*3, .5, .7);
    glutSolidSphere(100, 50, 50);
    glPopMatrix();


    glPushMatrix();
    glTranslatef ( counter*2 , 0.0 , 0.0 );
    glColor3ub(199, 240, 249);
    glTranslatef(-870-500, 750+600, -3500);
    //glScalef(1.1*3, .5, .7);
    glutSolidSphere(299, 50, 50);
    glPopMatrix();*/

    glPushMatrix();
    glTranslatef ( counter*2 , 0.0 , 0.0 );
    glColor3ub(199, 240, 249);
    glTranslatef(-920-500, 800+600, -3500);
    //glScalef(1.1*3, .5, .7);
    glutSolidSphere(200, 50, 50);
    glPopMatrix();

}
void hills_building()
{
//hills
    glPushMatrix();
    glColor3ub(70, 100, 120);
    glTranslatef(-2800, 200, -3000);
    glScalef(1.9, 1, 1);
    glutSolidSphere(350, 50, 50);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(70, 100, 120);
    glTranslatef(-1700, 200, -3000);
    glScalef(1.9, 1.4, 1);
    glutSolidSphere(400, 50, 50);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(70, 100, 120);
    glTranslatef(-500, 150, -3000);
    glScalef(1.9, 1.4, 1);
    glutSolidSphere(370, 50, 50);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(70, 100, 120);
    glTranslatef(500, 250, -3000);
    glScalef(2, .8, 1);
    glutSolidSphere(400, 50, 50);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(70, 100, 120);
    glTranslatef(2000, 200, -3000);
    glScalef(2, 1.5, 1);
    glutSolidSphere(450, 50, 50);
    glPopMatrix();

//building

    glPushMatrix();
    glColor3ub(1, 1, 1);
    glTranslatef(2000, 200, -2000);
    glRotatef(180, 0, 1, 0);
    glScalef(2, 8, 2);
    glutSolidCube(200);
    glPopMatrix();

        glPushMatrix();
    glColor3ub(140, 100, 120);
    glTranslatef(1550, 250, -2000);
    glRotatef(180, 0, 1, 0);
    glScalef(2, 8, 2);
    glutSolidCube(100);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(55, 55, 55);
    glTranslatef(-2000, 200, -2000);
    glRotatef(180, 0, 1, 0);
    glScalef(2, 7, 2);
    glutSolidCube(200);
    glPopMatrix();


    glPushMatrix();
    glColor3ub(155, 55, 76);
    glTranslatef(-1600, 200, -2000);
    glRotatef(180, 0, 1, 0);
    glScalef(2, 9, 2);
    glutSolidCube(100);
    glPopMatrix();




}

void drawScene() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.12313, 0.76572, 0.8997987, 0.0);


    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0.0, 0.0, -1000.0);
    //glRotatef(_angle, 0.0, 0.0, 1.0);
    glRotatef(_camera_angle, 01.0, 0.0, 0.0);

    //Building Skeleton
    glColor3ub(100, 50, 40);
    glPushMatrix();
    //glRotatef(5, 1.0, 01.0, 0.0);
    glScalef(1.2, 1.75, 1);
    glutSolidCube (300);
    glPopMatrix();

    //Stairs
    glPushMatrix();
    glTranslatef(0.0, -245, 155);
    //glRotatef(5, 1.0, 01.0, 0.0);
    glScalef(.5, .1, .1);
    glutSolidCube (300);
    glPopMatrix();

    //Building Base
    glPushMatrix();
    glColor3ub(120, 100, 70);
    glScalef(1.2, 1, 1);
    glTranslatef(-150.0, -260.0, 150.1);
    glBegin(GL_QUADS);
        glVertex2i(0, 0);
        glVertex2i(300, 0);
        glVertex2i(300, 100);
        glVertex2i(0, 100);
    glEnd();
    glPopMatrix();

    //Bricks
    glPushMatrix();
    glColor3ub(128, 128, 128);
    glScalef(1.2, 1, 1);
    glTranslatef(-150.0, -260.0, 150.2);
    glBegin(GL_LINES);
        for(int i = 0; i < 500; i+=5)
        {
            glVertex2i(0, i);
            glVertex2i(300, i);
        }
        for(int j = 0; j < 300; j+=15)
            for(int i = 0; i < 500; i+=5)
            {
                if(i%2 == 1 )
                    continue;
                glVertex2i(j, i);
                glVertex2i(j, i+5);
            }

        for(int j = 7; j < 300; j+=15)
            for(int i = 0; i < 495; i+=5)
            {
                if(i%2 == 0 )
                    continue;
                glVertex2i(j, i);
                glVertex2i(j, i+5);
            }
    glEnd();
    glPopMatrix();

    //
    glColor3ub(70, 60, 50);
    glPushMatrix();
    glTranslatef(0.0, -145, 165);
    glScalef(1.2, .1, .1);
    glutSolidCube(300);

    glTranslatef(0.0, 1000, 0);
    glutSolidCube(300);

    glTranslatef(0.0, 1000, 0);
    glutSolidCube(300);

    glTranslatef(0.0, 1000, 0);
    glutSolidCube(300);

    glTranslatef(0.0, 1000, 0);
    glutSolidCube(300);
    glPopMatrix();

    glTranslatef(0, -525, 150.5);


    glPushMatrix();

    glTranslatef(120, 200, 0);
    int p=0;
    int q=0;
    for(int i = 0; i < 25; i++)
    {
        if(i%5 == 0)
        {
            //glTranslatef(-350, 100, 0);
            p-=350;
            q+=100;
        }

        //glTranslatef(70, 0, 0);
        p+=70;

        w[i].drawWindow(p, q);


    }

    glPopMatrix();


//lodind bird
    glPushMatrix();
    glTranslatef(1000, 900, -400);
    glScalef(.7, .7, .7);
    bird();
    glPopMatrix();


    glPushMatrix();
    glTranslatef ( -counter*5 , 0.0 , 0.0 );
    glTranslatef(-1000, 1000, -400);
    glScalef(.7, .6, .7);
    bird();
    glPopMatrix();



// ground
	glPushMatrix();
	glColor3ub(85, 120, 54);
	glTranslatef(0, 200, 0);
	glScalef(7, 0.1, 7);
	glutSolidCube(1000);
	glPopMatrix();


//loading quinn
    glTranslatef(-400, 325, 0);
	glPushMatrix();
	glTranslatef(quinX, quinY, 30);
	glRotatef(fix, 0, 1, 0); // to move using keyboard
	glScalef(.25, .25, .35);
	quinn();
	glPopMatrix();


// loading bashir
	glTranslatef(800, -5, 0);
	glPushMatrix();
	glTranslatef(bashX, bashY, 30); // to move using keyboard
	glRotatef(hit, 0, 1, 0);
	glScalef(.25, .25, .35);
	bashir();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-400, -345, 0);
	cloud();
	glPopMatrix();


//loading the hills_building
    //glPushMatrix();
	glTranslatef(-400, -345, 0);
    hills_building();
    //glPopMatrix();


//loading tree
	glPushMatrix();
	glTranslatef(-1400, 490, -2090);//1
	//glScalef(2, 2, 2);
	tree();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-1200, 450, -2000);//2
	glScalef(.8, .8,.8);
	tree();
	glPopMatrix();


	glPushMatrix();//3
	glTranslatef(-1050, 490, -2000);
	//glScalef(2, 2, 2);
	tree();
	glPopMatrix();


    glPushMatrix();//4
	glTranslatef(-930, 450, -2000);
	glScalef(.8, .8,.8);
	tree();
	glPopMatrix();

    glPushMatrix();//5
	glTranslatef(-800, 490, -2000);
	//glScalef(.8, .9,.8);
	tree();
	glPopMatrix();


    glPushMatrix();//6
	glTranslatef(-660, 450, -2000);
	glScalef(.8, .9,.8);
	tree();
	glPopMatrix();


////////////////right side
    glPushMatrix();
	glTranslatef(1350, 490, -2090);//1
	//glScalef(2, 2, 2);
	tree();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(1200, 450, -2000);//2
	glScalef(.8, .8,.8);
	tree();
	glPopMatrix();


	glPushMatrix();//3
	glTranslatef(1050, 490, -2000);
	//glScalef(2, 2, 2);
	tree();
	glPopMatrix();


    glPushMatrix();//4
	glTranslatef(930, 450, -2000);
	glScalef(.8, .8,.8);
	tree();
	glPopMatrix();

    glPushMatrix();//5
	glTranslatef(800, 490, -2000);
	//glScalef(.8, .9,.8);
	tree();
	glPopMatrix();


    glPushMatrix();//6
	glTranslatef(660, 450, -2000);
	glScalef(.8, .9,.8);
	tree();
	glPopMatrix();

    glutSwapBuffers();
}

void collisionCheck()
{
    for(int i = 0; i < 25; i++)
    {
        w[i].checkStatus(bashX+540, bashY);
    }
}

void myKeyboard(unsigned char key, int x, int y)
{
    switch(key)
    {
    case 'i':
        if(bashY<400)
            bashY+=5;
        break;

    case 'k':
        if(bashY>0)
            bashY-=5;
        break;

    case 'j':
        if(bashX>-600)
            bashX-=5;
        break;

    case 'l':
        if(bashX<200)
            bashX+=5;
        break;

    case 'w':
        if(quinY<400)
            quinY+=5;
        break;

    case 's':
        if(quinY>0)
            quinY-=5;
        break;

    case 'a':
        if(quinX>-200)
            quinX-=5;
        break;

    case 'd':
        if(quinX<600)
            quinX+=5;
        break;

    case 'm':
        hit = 120;
        breakWindow = true;
        collisionCheck();
        break;
    case 'b':
        hit = -120;
        breakWindow = true;
        collisionCheck();
        break;


    case 'x':
        fix = 120;
        breakWindow = true;
        collisionCheck();
        break;

    case 'z':
        fix = -120;
        breakWindow = true;
        collisionCheck();
        break;

    case '-':
        _camera_angle++;
        break;
    case '+':
        _camera_angle--;
        break;

    }

    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1280, 720);

    glutCreateWindow("OpenGL 3D");
    initRendering();

    glutDisplayFunc(drawScene);
    glutReshapeFunc(handleResize);
    glutKeyboardFunc(myKeyboard);

    glutTimerFunc(25, update, 0);

    glutMainLoop();
    return 0;
}

