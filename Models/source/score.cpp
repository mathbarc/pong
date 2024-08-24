#include "score.hpp"
#include <GL/gl.h>

Score::Score()
    : score(0)
{

}

void Score::draw()
{
    if(score!=6&&score!=5)
    {
        glTranslatef(450,500,0);
        glBegin(GL_POLYGON);
            glVertex2f(2.5,10);
            glVertex2f(2.5,-10);
            glVertex2f(1.5,-11.5);
            glVertex2f(-1.5,-11.5);
            glVertex2f(-2.5,-10);
            glVertex2f(-2.5,10);
            glVertex2f(-1.5,11.5);
            glVertex2f(1.5,11.5);
        glEnd();
        glLoadIdentity();
    }
    if(score!=2)
    {
        glTranslatef(450,475,0);
        glBegin(GL_POLYGON);
            glVertex2f(2.5,10);
            glVertex2f(2.5,-10);
            glVertex2f(1.5,-11.5);
            glVertex2f(-1.5,-11.5);
            glVertex2f(-2.5,-10);
            glVertex2f(-2.5,10);
            glVertex2f(-1.5,11.5);
            glVertex2f(1.5,11.5);
        glEnd();
        glLoadIdentity();
    }
    if(score==0||score==4||score==5||score==6||score==8||score==9)
    {
        glTranslatef(425,500,0);
        glBegin(GL_POLYGON);
            glVertex2f(2.5,10);
            glVertex2f(2.5,-10);
            glVertex2f(1.5,-11.5);
            glVertex2f(-1.5,-11.5);
            glVertex2f(-2.5,-10);
            glVertex2f(-2.5,10);
            glVertex2f(-1.5,11.5);
            glVertex2f(1.5,11.5);
        glEnd();
        glLoadIdentity();
    }
    if(score==0||score==2||score==6||score==8)
    {
        glTranslatef(425,475,0);
        glBegin(GL_POLYGON);
            glVertex2f(2.5,10);
            glVertex2f(2.5,-10);
            glVertex2f(1.5,-11.5);
            glVertex2f(-1.5,-11.5);
            glVertex2f(-2.5,-10);
            glVertex2f(-2.5,10);
            glVertex2f(-1.5,11.5);
            glVertex2f(1.5,11.5);
        glEnd();
        glLoadIdentity();
    }
    if(score==0||score==2||score==3||score==5||score==6||score==7||score==8||score==9)
    {
        glTranslatef(437.5,515,0);
        glRotatef(90,0,0,1);
        glBegin(GL_POLYGON);
            glVertex2f(2.5,10);
            glVertex2f(2.5,-10);
            glVertex2f(1.5,-11.5);
            glVertex2f(-1.5,-11.5);
            glVertex2f(-2.5,-10);
            glVertex2f(-2.5,10);
            glVertex2f(-1.5,11.5);
            glVertex2f(1.5,11.5);
        glEnd();
        glLoadIdentity();
    }
    if(score==0||score==2||score==3||score==5||score==6||score==8||score==9)
    {
        glTranslatef(437.5,460,0);
        glRotatef(90,0,0,1);
        glBegin(GL_POLYGON);
            glVertex2f(2.5,10);
            glVertex2f(2.5,-10);
            glVertex2f(1.5,-11.5);
            glVertex2f(-1.5,-11.5);
            glVertex2f(-2.5,-10);
            glVertex2f(-2.5,10);
            glVertex2f(-1.5,11.5);
            glVertex2f(1.5,11.5);
        glEnd();
        glLoadIdentity();
    }
    if((score>=2&&score<=6)||score==8||score==9)
    {
        glTranslatef(437.5,486.5,0);
        glRotatef(90,0,0,1);
        glBegin(GL_POLYGON);
            glVertex2f(2.5,10);
            glVertex2f(2.5,-10);
            glVertex2f(1.5,-11.5);
            glVertex2f(-1.5,-11.5);
            glVertex2f(-2.5,-10);
            glVertex2f(-2.5,10);
            glVertex2f(-1.5,11.5);
            glVertex2f(1.5,11.5);
        glEnd();
        glLoadIdentity();
    }

}

void Score::increase()
{
    this->score++;
}

void Score::reset()
{
    this->score = 0;
}
