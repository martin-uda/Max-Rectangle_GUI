#include "C_Matrix.h"

// -- Exception def
//Excp_Invalid_Matrix::Excp_Invalid_Matrix() {}

const char * Excp_Invalid_Matrix::what() const throw()
{
    return "Matrix is not valid yet.";
}
// end of -- Exception def

C_Matrix::C_Matrix()
{
    w = 0;
    h = 0;
    valid = false;
} // of ctor C_Matrix(h,w)


void C_Matrix::init(int height, int width)
{
    w = width;
    h = height;
    valid = false;
    a = new T_BoolMatrix;

    for (size_t i = 0; i < h; i++) {
        T_BoolVector myvec;
        for (size_t j = 0; j < w; j++) {
            myvec.push_back(false);
        }
        (*a).push_back(myvec);
    }

} // of init()

void C_Matrix::destroy()
{
    valid = false;
    delete a;
} // of destroy()


int C_Matrix::get_h()
{
    return h;
}

int C_Matrix::get_w()
{
    return w;
}

bool C_Matrix::is_valid()
{
    return valid;
}

void C_Matrix::set_invalid()
{
    valid = false;
}


C_Matrix::~C_Matrix()
{
    delete a;
} // of dtor C_Matrix()


bool C_Matrix::set_full_value(bool value)
{
    if (h == 0 || w == 0) {
        return false;
    }
    for (size_t i = 0; i < h; i++) {
        for (size_t j = 0; j < w; j++) {
            (*a)[i][j] = value;
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

bool C_Matrix::generate_random(float perct)
{
    float f;
    if (h == 0 || w == 0) {
        return false;
    }
    for (size_t i = 0; i < h; i++) {
        for (size_t j = 0; j < w; j++) {
            f = std::rand() / (RAND_MAX + 1.F);
            (*a)[i][j] = (f < perct);
        }
    }
    valid = true;
    return true;
} // of generate_random()


bool C_Matrix::set_1(int y, int x, bool value)
{
    if (!valid || h == 0 || w == 0) {
        return false;
    }
    (*a)[y][x] = value;
    return value;
} // of set_1()

bool C_Matrix::get_1(int y, int x)
{
    if (!valid || h == 0 || w == 0) {
        Excp_Invalid_Matrix ex_invalid_matrix;
        throw ex_invalid_matrix;
    }
    return (*a)[y][x];
} // of get_1()

bool C_Matrix::negate_1(int y, int x)
{
    return set_1(y, x, !get_1(y, x));
}

// of class C_Martix  ============================================
