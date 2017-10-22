// =============================================================================
// things for checking Matrix
// =============================================================================

#include "C_CheckMatrix.h"


C_CheckMatrix::C_CheckMatrix()
{
    init();
} // end of construltor CheckingRec

void C_CheckMatrix::init()
{
    mainMax = 0;
    mainMax_arr.clear();
    mainMax_arr.push_back({ -1, -1, 0, 0, 0 });  // int i, j, Ls, Us, size;
    G.clear();
    w = h = 0;
} // end of construltor CheckingRec

C_CheckMatrix::~C_CheckMatrix()
{
    // new_graph_node() creates new T_Graph
}


void C_CheckMatrix::initialize_G(int w1, int h1)  // set G to nullptrs
{
    w = w1;
    h = h1;
    //T_Graph *pu;

    G.clear();
    for (size_t i = 0; i < h; i++) {
        T_GraphVector myvec;
        for (size_t j = 0; j < w; j++) {
            //pu = new T_Graph;
            //myvec.push_back(pu);
            T_Graph *p = nullptr;
            myvec.push_back(p);
            //myvec.push_back(nullptr);
        }
        G.push_back(myvec);
    }
} // initialize_G()

void C_CheckMatrix::new_max(int i, int j, T_Graph *g)
{
    T_Graph u = *g;
    if (u.size > mainMax) {          // create new max
        mainMax = u.size;
        mainMax_arr.clear();
    }
    mainMax_arr.push_back({ i, j, u.Ls, u.Us, u.size });
    //} else if (u.size = mainMax) {   // add another size
    //    mainMax_arr.push_back({ i, j, u.Ls, u.Us, u.size });
    //    printf("add size: (%d) @ %d,%d; size: %d*%d \n", u.size, i, j, u.Ls, u.Us);
    //}
} // new_max()


C_CheckMatrix::T_Graph* C_CheckMatrix::new_graph_node(int value)   // value=1 for new node in add_graphs()
{
    T_Graph* g = new T_Graph;
    g->next = nullptr;
    g->size = value;
    g->Ls = value;
    g->Us = value;
    return g;
}  // new_graph_node()


C_CheckMatrix::T_Graph* C_CheckMatrix::check_unit_IJ(T_BoolMatrix M, int i, int j)  // [i,j] : i=> h, j=> w
{
    T_Graph *g;   // graph for current unit : [i][j]
    T_Graph *gL;  // graph for Left unit    : [i-1][j]
    T_Graph *gU;  // graph for Up unit      : [i][j-1]

    if (M[i][j] == false) {       // we are on False
        return nullptr;
    }
    g = new_graph_node(1);
    if (g->size >= mainMax) { new_max(i, j, g); }

    // we are on True, set Left first
    if (j <= 0) {
        gL = nullptr;
    } else {
        gL = G[i][j - 1];
    }
    // check Up now
    if (i <= 0) {
        gU = nullptr;
    } else {
        gU = G[i - 1][j];
    }
    add_graphs(gU, g, gL, i, j);
    return g;
} // check_unit_IJ()


void C_CheckMatrix::add_graphs(T_Graph *gU, T_Graph *g, T_Graph *gL, int i, int j)
{
    if (gL != nullptr) {
        g->Ls = gL->Ls + 1;
        g->Us = 1;
        g->size = gL->size + 1;
        if (g->size >= mainMax) { new_max(i, j, g); }
        gL = gL->next;
        //g->next = new_graph_node(1);
        //g = g->next;
    }
    // and now try to add gU graph
    int cnt = 1;
    while (gU != nullptr) {
        g->next = new_graph_node(1);  // add new node if gU exists
        g = g->next;
        cnt++;
        if (gL != nullptr) {          // add gL info
            g->Ls = gL->Ls + 1;
            g->Us = cnt;
            g->size = gL->size + cnt;
            if (g->size >= mainMax) { new_max(i, j, g); }
            gL = gL->next;
            gU = gU->next;
        } else {             // no more Left, just copy rest of Up
            while (gU != nullptr) {
                g->Ls = 1;
                g->Us = cnt;
                g->size = cnt;  //gU->size + 1;  //## mozna jen cnt neboli Us
                if (g->size >= mainMax) { new_max(i, j, g); }
                gU = gU->next;
                if (gU != nullptr) {     // prepare new node if gU exists
                    g->next = new_graph_node(1);
                    g = g->next;
                }
                cnt++;
            }
            break;
        }
    }
} // add_graphs()


C_CheckMatrix::T_MaxRecVec C_CheckMatrix::find_max_rectangle(C_Matrix ^M)
{
    T_BoolMatrix* pM;

    init();
    pM = M->a;
    initialize_G(M->get_w(), M->get_h());

    for (size_t j = 0; j < M->get_w(); j++) {
        for (size_t i = 0; i < M->get_h(); i++) {
            G[i][j] = check_unit_IJ(*pM, i, j);
        }
    }
    return mainMax_arr;
}  // find_max_rectangle()


// end of class C_CheckMatrix  ============================================
