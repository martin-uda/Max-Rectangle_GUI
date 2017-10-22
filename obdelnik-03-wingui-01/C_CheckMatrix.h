#pragma once

#include <vector>
#include "C_Matrix.h"

class C_CheckMatrix
{
    public:
    C_CheckMatrix();
    void init();
    virtual ~C_CheckMatrix();

    typedef struct {
        int i, j, Ls, Us, size;
    } T_MaxRec;
    typedef std::vector<T_MaxRec> T_MaxRecVec;

    T_MaxRecVec find_max_rectangle(C_Matrix ^M);

    //int get_max_size();

    private:
    int mainMax;

    struct T_Graph {
        T_Graph* next;
        int Ls, Us, size;
    };
    typedef struct T_Graph T_Graph;

    typedef std::vector<T_Graph*> T_GraphVector;
    typedef std::vector<T_GraphVector> T_GraphMatrix;

    T_MaxRecVec mainMax_arr;
    T_GraphMatrix G;               // matrix of pointers to graph
    int w;   // size for G
    int h;

    void initialize_G(int w1, int h1);
    void new_max(int i, int j, T_Graph *g);
    //void show_max();
    T_Graph* new_graph_node(int value);
    T_Graph* check_unit_IJ(T_BoolMatrix M, int i, int j);
    void add_graphs(T_Graph *gU, T_Graph *g, T_Graph *gL, int i, int j);

};

