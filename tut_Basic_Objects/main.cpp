#include "GL/freeglut.h"
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif


// Определяем функцию для графика Астроиды
double astroid_x(double t) {
    return 2 * pow(sin(t), 3);
}

double astroid_y(double t) {
    return 2 * pow(cos(t), 3);
}

// Функция отрисовки
void draw() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 1.0f);  // Устанавливаем цвет графика (белый)

    glBegin(GL_LINE_STRIP);
    for (double t = 0; t <= 2 * M_PI; t += 0.01) {
        double x = astroid_x(t);
        double y = astroid_y(t);
        glVertex2f(x, y);
    }
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Graph");

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);  // Устанавливаем цвет фона (черный)
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-3.0, 3.0, -3.0, 3.0, -1.0, 1.0);

    glutDisplayFunc(draw);
    glutMainLoop();

    return 0;
}
