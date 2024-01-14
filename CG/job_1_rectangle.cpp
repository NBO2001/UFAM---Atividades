#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <thread>
#include <chrono>
#include <GL/gl.h>
#include <GL/glut.h>


void display(void) {

    double r[4] = {0.85, 0.17, 0.85,0.0};
    double g[4] = {0.14,0.0, 0.17, 0.67};
    double b[4] = {0.81, 0.85, 0.0, 0.39};

    double move = 0.0;
    double move_top = 0.0;
    int chosen;
    glClear(GL_COLOR_BUFFER_BIT);
    
    for(int i=0; i < 100; i++){
        chosen = rand() % 4;
        glColor3f(r[chosen],g[chosen],b[chosen]);

        glBegin(GL_POLYGON);
            glVertex2f(-1.0 + move, -0.2 - move_top);
            glVertex2f(-1.0 + move, 1.0  - move_top);
            glVertex2f(-0.7 + move, 1.0 - move_top);
            glVertex2f(-0.7 + move, -0.2 - move_top);
        glEnd();

        glFlush();

        if (move < 2.0 ){
            move += 0.1;
        }else{
            move = 0.0;
            move_top += 0.1;
        }
        
        std::this_thread::sleep_for( std::chrono::milliseconds(150) );
        glClear(GL_COLOR_BUFFER_BIT);
    }
    
}

int main(int argc, char *argv[]) {

    time_t t;
    srand((unsigned) time(&t));

    glutInit(&argc,argv);
    glutInitWindowSize(1000, 1000);
    glutCreateWindow("simple");
    glutDisplayFunc(display);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1000,0.0,1000, 1.0,1.0);


    glutMainLoop();

    return 0;
}
