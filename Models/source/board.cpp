#include "board.hpp"
#include <GL/gl.h>
#include <GL/glut.h>


Board::Board()
{

}

void Board::draw()
{
    glColor3f(Superficie[0], Superficie[1], Superficie[2]);

    glBegin(GL_QUADS);
        glVertex3f(100,0,200);
        glVertex3f(-100,0,200);
        glVertex3f(-100,0,-200);
        glVertex3f(100,0,-200);
    glEnd();

    glColor3f(1,1,1);


    glBegin(GL_QUADS);
        glVertex3f(100,0.1,10);
        glVertex3f(100,0.1,-10);
        glVertex3f(-100,0.1,-10);
        glVertex3f(-100,0.1,10);
    glEnd();

    glColor3f(1,1,1);

    glPushMatrix();
    glTranslatef(105,15,0);
    glScalef(0.025,0.075,1.0);
    glutSolidCube(400);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-105,15,0);
    glScalef(0.025,0.075,1.0);
    glutSolidCube(400);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,25,-195);
    glScalef(1.0,0.05,0.05);
    glutSolidCube(200);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,25,195);
    glScalef(1.0,0.05,0.05);
    glutSolidCube(200);
    glPopMatrix();
}
