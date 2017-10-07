#pragma once

#include <vector>

typedef std::vector<bool> T_BoolVector;
typedef std::vector<T_BoolVector> T_BoolMatrix;

ref class C_Matrix
{
    public:
    T_BoolMatrix *a;

    C_Matrix();
    void init(int width, int height);
    virtual ~C_Matrix();

    bool set_full_true();
    bool set_full_false();
    bool generate_random(int perct);
    bool set_1(int x, int y, bool value);
    
    private:
    int w;
    int h;
    bool valid;
    bool set_full_value(bool value);

};

