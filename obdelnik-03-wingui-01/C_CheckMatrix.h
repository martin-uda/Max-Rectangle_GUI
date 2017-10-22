#pragma once

#include <vector>

class C_CheckMatrix
{
    public:
    C_CheckMatrix();
    virtual ~C_CheckMatrix();

    private:
    int mainMax;
    typedef std::vector<T_Graph*> T_GraphVector;
    typedef std::vector<T_GraphVector> T_GraphMatrix;

    std::vector<T_MaxRec> mainMax_arr;
    T_GraphMatrix G;               // matrix of pointers to graph
    int w;   // size for G
    int h;

};

