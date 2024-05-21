#include <GL/glut.h>
#include <cmath>

float angle = 0.0;

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
}

void drawOctahedron() {
    glBegin(GL_TRIANGLES);

    // Top pyramid
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(0.0, 1.0, 0.0);
    glVertex3f(-1.0, 0.0, -1.0);
    glVertex3f(1.0, 0.0, -1.0);

    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(0.0, 1.0, 0.0);
    glVertex3f(1.0, 0.0, -1.0);
    glVertex3f(1.0, 0.0, 1.0);

    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0.0, 1.0, 0.0);
    glVertex3f(1.0, 0.0, 1.0);
    glVertex3f(-1.0, 0.0, 1.0);

    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(0.0, 1.0, 0.0);
    glVertex3f(-1.0, 0.0, 1.0);
    glVertex3f(-1.0, 0.0, -1.0);

    // Bottom pyramid
    glColor3f(1.0, 0.0, 1.0);
    glVertex3f(0.0, -1.0, 0.0);
    glVertex3f(-1.0, 0.0, -1.0);
    glVertex3f(1.0, 0.0, -1.0);

    glColor3f(0.0, 1.0, 1.0);
    glVertex3f(0.0, -1.0, 0.0);
    glVertex3f(1.0, 0.0, -1.0);
    glVertex3f(1.0, 0.0, 1.0);

    glColor3f(1.0, 0.5, 0.0);
    glVertex3f(0.0, -1.0, 0.0);
    glVertex3f(1.0, 0.0, 1.0);
    glVertex3f(-1.0, 0.0, 1.0);

    glColor3f(0.5, 0.0, 1.0);
    glVertex3f(0.0, -1.0, 0.0);
    glVertex3f(-1.0, 0.0, 1.0);
    glVertex3f(-1.0, 0.0, -1.0);

    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(0.0, 0.0, -5.0);
    glRotatef(angle, 1.0, 1.0, 0.0);

    drawOctahedron();

    glutSwapBuffers();
}

void timer(int value) {
    angle += 0.5;
    if (angle > 360) angle -= 360;

    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Rotating Octahedron");

    init();

    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);

    glutMainLoop();
    return 0;
}
