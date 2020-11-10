#include "point.h"

#define COL_POINTS 25

tPoint* point = new tPoint[COL_POINTS];

void renderScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPointSize(point[1].getSize());
    // glEnable(GL_POINT_SMOOTH);
    glBegin(GL_POINTS);
    for (int i = 0; i < COL_POINTS; i++) {
        glVertex2f(point[i].getX(), point[i].getY());
        glColor3f(point[i].getR(), point[i].getG(), point[i].getB());
    }
    glEnd();

    glutSwapBuffers();
}

void move(int j = 0)
{
    renderScene();
    for (int i = 0; i < COL_POINTS; i++) {
        if ((i % 5 == 0) || (i % 6 != 0 && i % 3 == 0)) {
            point[i].set_chaos_vector();
        }
        point[i].move();
    }

    glutTimerFunc(5, move, 0);
}

int main(int argc, char** argv)
{

    // инициализация
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(600, 500);
    glutCreateWindow("Lab-2");
    glClearColor(0, 0, 0, 0);

    // регистрация обратных вызовов
    glutDisplayFunc(renderScene);

    move();

    // Основной цикл GLUT
    glutMainLoop();

    return 1;
}
