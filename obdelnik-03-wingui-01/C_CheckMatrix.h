#pragma once

#include <vector>
#include <stack>
#include "C_Matrix.h"

typedef struct {
	int i, j, Ls, Us, size;
} T_MaxRec;
typedef std::vector<T_MaxRec> T_MaxRecVec;

typedef std::vector<int> T_Histogram;


class C_BaseCheckMatrix
{
public:
	C_BaseCheckMatrix();
	virtual ~C_BaseCheckMatrix();

	int get_max_size();
	T_MaxRecVec get_max_rect_vec();
	virtual T_MaxRecVec find_max_rectangle(C_Matrix ^M) = 0;

protected:  // v v v v v v v v v v v v v 
	int mainMax;
	T_MaxRecVec mainMax_arr;

};

class C_CheckMatrix : public C_BaseCheckMatrix
{
public:
	C_CheckMatrix();
	void init();
	virtual ~C_CheckMatrix();

	virtual T_MaxRecVec find_max_rectangle(C_Matrix ^M);

protected:  // v v v v v v v v v v v v v 
	struct T_Graph {
		T_Graph* next;
		int Ls, Us, size;
	};
	typedef struct T_Graph T_Graph;

	typedef std::vector<T_Graph*> T_GraphVector;
	typedef std::vector<T_GraphVector> T_GraphMatrix;

	T_GraphMatrix G;         // matrix of pointers to graph
	int w;   // size for G
	int h;

	void initialize_G(int w1, int h1);
	void new_max(int i, int j, T_Graph *g);
	T_Graph* new_graph_node(int value);
	T_Graph* check_unit_IJ(T_BoolMatrix M, int i, int j);
	void add_graphs(T_Graph *gU, T_Graph *g, T_Graph *gL, int i, int j);
};


class C_CheckWithHist : public C_BaseCheckMatrix
{
public:
	C_CheckWithHist();
	void init();
	virtual ~C_CheckWithHist();

	virtual T_MaxRecVec find_max_rectangle(C_Matrix ^M);
	T_MaxRecVec find_max_rectangle_in_hist(T_Histogram x);

	std::string str_hist(T_Histogram h);

protected:  // v v v v v v v v v v v v v 
	typedef struct {
		int i, h;
	} T_Last;

	std::stack<T_Last> stack_last;

	void new_max(int size, int col, int row, int col_w, int row_h);
	//void build_histogram(C_Matrix ^M, int N, int row, T_Histogram &h0);
	void max_rect_in_histogram(T_Histogram x, int y, int N);
};

class C_CheckWithHist_FromWeb : public C_BaseCheckMatrix
{
public:
	C_CheckWithHist_FromWeb();
	void init();
	virtual ~C_CheckWithHist_FromWeb();

	virtual T_MaxRecVec find_max_rectangle(C_Matrix ^M);
	//T_MaxRecVec find_max_rectangle_in_hist(T_Histogram x);

protected:  // v v v v v v v v v v v v v 

	void new_max(int size, int col, int row, int col_w, int row_h);
	void max_rect_in_histogram(T_Histogram x, int y, int N);

};
