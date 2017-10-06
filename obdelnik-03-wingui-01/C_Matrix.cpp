#include "C_Matrix.h"

C_Matrix::C_Matrix()
{
    w = 0;
    h = 0;
    valid = false;
}

C_Matrix::C_Matrix(int width, int height)
{
    w = width;
    h = height;
    valid = false;
    for (int i = 0; i < h; i++) {
        T_BoolVector myvec;
        for (size_t j = 0; j < w; j++) {
            myvec.push_back(false);
        }
        a.push_back(myvec);
    }

} // of ctor C_Matrix(w,h)

C_Matrix::~C_Matrix()
{
} // of dtor C_Matrix()


bool C_Matrix::set_full_value(bool value)
{
    if (h == 0 || w == 0) {
        return false;
    }
    for (size_t i = 0; i < h; i++) {
        for (size_t j = 0; j < w; j++) {
            a[i][j] = value;
        }
    }
    valid = true;
    return true;

} // of set_full_value()

bool C_Matrix::set_full_true()
{
    return set_full_value(true);
}

bool C_Matrix::set_full_false()
{
    return set_full_value(false);
}

bool C_Matrix::generate_random(int perct)
{
    float f;
    if (h == 0 || w == 0) {
        return false;
    }
    for (size_t i = 0; i < h; i++) {
        for (size_t j = 0; j < w; j++) {
            f = rand() / (RAND_MAX + 1.);
            a[i][j] = (f < perct);
        }
    }
    valid = true;
    return true;
} // of generate_random()


bool C_Matrix::set_1(int x, int y, bool value)
{
    if (!valid || h == 0 || w == 0) {
        return false;
    }
    a[x][y] = value;
    return true;
} // of set_1()

//}; // of class C_Martix  ============================================
