#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <GL/gl.h>
#include <GL/glut.h>

#define MAX_SEGMENTS 1000

typedef struct {
    float x, y;
} Point;

typedef struct {
    Point start, end;
} Segment;

int numSegments;
Segment segments[MAX_SEGMENTS];
int windowWidth, windowHeight;

int ccw(Point A, Point B, Point C){
    if( (C.y-A.y)*(B.x-A.x) > (B.y-A.y)*(C.x-A.x)) return 1;
    else 0;
}

int intersect(Point A,Point B,Point C,Point D){
    if((ccw(A,C,D)==1) != (ccw(B,C,D)==1) && (ccw(A,B,C)==1) != (ccw(A,B,D)==1)) return 1;
    else 0;
}

int isValid(Segment segment, Segment segments[], int n){

    for(int i=0; i < n; i++){
        if(intersect(segment.start,segment.end, segments[i].start, segments[i].end)){
            return 0;
        }
    }

    return 1;
}

void generateRandomSegments() {
    srand(time(NULL));

    Segment segment;
    
    
    for (int i = 0; i < numSegments; i++) {
        
        do{
            segments[i].start.x = rand() % windowWidth;
            segments[i].start.y = rand() % windowHeight;
            segments[i].end.x = rand() % windowWidth;
            segments[i].end.y = rand() % windowHeight;
        }while(isValid(segments[i], segments, i) != 1);
        
    }
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);

    for (int i = 0; i < numSegments; i++) {
        glBegin(GL_LINES);
        glVertex2f(segments[i].start.x, segments[i].start.y);
        glVertex2f(segments[i].end.x, segments[i].end.y);
        glEnd();
    }

    glFlush();
}

int main(int argc, char *argv[]) {

    windowWidth = atoi(argv[1]);
    windowHeight = atoi(argv[2]);
    numSegments = atoi(argv[3]);

    if (numSegments > MAX_SEGMENTS) {
        printf("Number of segments exceeds the maximum allowed.\n");
        return 1;
    }

    generateRandomSegments();

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("Segmentos Aleatorios");
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, windowWidth, 0.0, windowHeight, -1.0, 1.0);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
