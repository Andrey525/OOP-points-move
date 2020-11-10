#ifndef POINT_H
#define POINT_H

#include <GL/freeglut.h>
#include <GL/glut.h>
#include <cstdlib>
#include <ctime>

class tPoint {
private:
    /* Координаты */
    float x;
    float y;

    /* Размер */
    float size;

    /* Цвет */
    float r;
    float g;
    float b;

    /* Направление движения */
    float vector_x;
    float vector_y;

    /* Коэффициент скорости*/
    float koef;

public:
    tPoint();

    void setX(float rx);
    void setY(float ry);
    void setSize(float rsize);
    void setR(float mr);
    void setG(float mg);
    void setB(float mb);
    void setVX(float v_x);
    void setVY(float v_y);
    void setKoef(float koef);

    float getX();
    float getY();
    float getSize();
    float getR();
    float getG();
    float getB();
    float getVX();
    float getVY();
    float getKoef();

    /* Движение */
    void move();
    void set_chaos_vector();
};

#endif