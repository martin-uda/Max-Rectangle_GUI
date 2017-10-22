#pragma once

#include <exception>
class Excp_Invalid_Matrix : public std::exception 
{
    public:
    //Excp_Invalid_Matrix(char const* const message) throw();
    const char * what() const throw();
};

#include <vector>

typedef std::vector<bool> T_BoolVector;
typedef std::vector<T_BoolVector> T_BoolMatrix;

ref class C_Matrix
{
    public:
    T_BoolMatrix *a;

    C_Matrix();
    void init(int height, int width);
    void destroy();
    virtual ~C_Matrix();
    int get_h();
    int get_w();
    bool is_valid();
    void set_invalid();

    bool set_full_true();
    bool set_full_false();
    bool generate_random(float perct);
    bool set_1(int y, int x, bool value);
    bool get_1(int y, int x);
    bool negate_1(int y, int x);
    //std::tuple<bool, bool> get_1(int x, int y);

    private:
    int w;
    int h;
    bool valid;
    bool set_full_value(bool value);

};

