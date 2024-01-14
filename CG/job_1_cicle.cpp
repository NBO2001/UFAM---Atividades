#include <iostream>
#include <ctime>
#include <GL/gl.h>
#include <GL/glut.h>
#include <cmath>
#include <utility>
#include <thread>

#define NUM_POINTS 90

std::pair<double, double> points[NUM_POINTS+1];

void pointsGenerate(void){

    double angle = 0.0;
    double radians = 0.0;
    int divs = 90/NUM_POINTS;

    double x,y;

    for(int i=0; i <= NUM_POINTS; i++){
        x = 0.5 * cos(radians);
        y = 0.5 * sin(radians);

        points[i].first = x;
        points[i].second = y;

        angle += divs;
        radians = (angle * M_PI) / 180.0;
    }
}

void circ_1(int j){

    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_LINE_STRIP);

        for(int i=0; i < NUM_POINTS; i++) glVertex2f(points[i].first, points[i].second);
        if(j >= 1)    
            for(int i=NUM_POINTS; i >= 0; i--) glVertex2f(-points[i].first, points[i].second);
        
        if(j >= 2)
            for(int i=0; i < NUM_POINTS; i++)  glVertex2f(-points[i].first, -points[i].second);
        
        if(j >= 3)
            for(int i=NUM_POINTS; i >= 0; i--) glVertex2f(points[i].first, -points[i].second);

    glEnd();

    glFlush();

    std::this_thread::sleep_for( std::chrono::milliseconds(120));

}

void circ_2(int j){

    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_LINE_STRIP);

        for(int i=NUM_POINTS; i >= 0; i--) glVertex2f(-points[i].first, points[i].second);
        
        if(j >= 1)
            for(int i=0; i < NUM_POINTS; i++)  glVertex2f(-points[i].first, -points[i].second);
        
        if(j >= 2)
            for(int i=NUM_POINTS; i >= 0; i--) glVertex2f(points[i].first, -points[i].second);
        
        if(j >= 3)
            for(int i=0; i < NUM_POINTS; i++) glVertex2f(points[i].first, points[i].second);

    glEnd();

    glFlush();

    std::this_thread::sleep_for( std::chrono::milliseconds(120));

}

void circ_3(int j){

    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_LINE_STRIP);

        
        for(int i=0; i < NUM_POINTS; i++)  glVertex2f(-points[i].first, -points[i].second);

        if(j >= 1)    
            for(int i=NUM_POINTS; i >= 0; i--) glVertex2f(points[i].first, -points[i].second);
        
        if(j >= 2)
            for(int i=0; i < NUM_POINTS; i++) glVertex2f(points[i].first, points[i].second);
        
        if(j >= 3)
            for(int i=NUM_POINTS; i >= 0; i--) glVertex2f(-points[i].first, points[i].second);

    glEnd();

    glFlush();

    std::this_thread::sleep_for( std::chrono::milliseconds(120));

}

void circ_4(int j){

    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_LINE_STRIP);

        for(int i=NUM_POINTS; i >= 0; i--) glVertex2f(points[i].first, -points[i].second);
        if(j >= 1)    
            
            for(int i=0; i < NUM_POINTS; i++) glVertex2f(points[i].first, points[i].second);
        
        if(j >= 2)
            for(int i=NUM_POINTS; i >= 0; i--) glVertex2f(-points[i].first, points[i].second);
        
        if(j >= 3)
            for(int i=0; i < NUM_POINTS; i++)  glVertex2f(-points[i].first, -points[i].second);

    glEnd();

    glFlush();

    std::this_thread::sleep_for( std::chrono::milliseconds(120));

}



void display(void){
    

    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0,0.0,0.0);
    
    int start = 0;
    for(int t=0; t < 1500; t++){

        for(int j = 0; j < 4; j++)
            
            if(start==0) circ_1(j);
            else if(start==2) circ_2(j);
            else if(start==3) circ_3(j);
            else circ_3(j);

            start = start > 3 ? 0 : start + 1; 

        glBegin(GL_POLYGON);
            for(int i=0; i < NUM_POINTS; i++) glVertex2f(points[i].first, points[i].second);
            for(int i=NUM_POINTS; i >= 0; i--) glVertex2f(-points[i].first, points[i].second);
            for(int i=0; i < NUM_POINTS; i++)  glVertex2f(-points[i].first, -points[i].second);
            for(int i=NUM_POINTS; i >= 0; i--) glVertex2f(points[i].first, -points[i].second);
        glEnd();

        glFlush();
        std::this_thread::sleep_for( std::chrono::milliseconds(500));
    }

    


}

int main(int argc, char** argv){

    pointsGenerate();

    glutInit(&argc, argv);
    glutInitWindowSize(1000,1000);
    glutCreateWindow("Circ create");
    glutDisplayFunc(display);

    glMatrixMode(GL_PROJECTION_MATRIX);
    glLoadIdentity();
    glOrtho(0.0, 1000,0.0,1000, 1.0,1.0);

    glutMainLoop();
 
    return 0;


}