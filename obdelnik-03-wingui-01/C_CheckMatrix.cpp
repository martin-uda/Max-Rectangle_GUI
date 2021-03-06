// =============================================================================
// things for checking Matrix
// =============================================================================

#include "C_CheckMatrix.h"

// begin of class C_BaseCheckMatrix  vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv


C_BaseCheckMatrix::C_BaseCheckMatrix()
{
}

C_BaseCheckMatrix::~C_BaseCheckMatrix()
{
}

int C_BaseCheckMatrix::get_max_size()
{
	return mainMax;
}

T_MaxRecVec C_BaseCheckMatrix::get_max_rect_vec()
{
	return mainMax_arr;
}

// end of class C_BaseCheckMatrix  ============================================



// begin of class C_CheckMatrix  vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv

C_CheckMatrix::C_CheckMatrix()
{
	init();
} // end of construltor C_CheckMatrix

void C_CheckMatrix::init()
{
	mainMax = 0;
	mainMax_arr.clear();
	mainMax_arr.push_back({ -1, -1, 0, 0, 0 });  // int i, j, Ls, Us, size;
	G.clear();
	w = h = 0;
} // end of construltor C_CheckMatrix

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
	mainMax_arr.push_back({ j - u.Ls + 1, i - u.Us + 1, u.Ls, u.Us, u.size });
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
	}
	else {
		gL = G[i][j - 1];
	}
	// check Up now
	if (i <= 0) {
		gU = nullptr;
	}
	else {
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
		}
		else {             // no more Left, just copy rest of Up
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


T_MaxRecVec C_CheckMatrix::find_max_rectangle(C_Matrix ^M)
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



// begin of class C_CheckWithHist  vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv

#include <string>

std::string C_CheckWithHist::str_hist(T_Histogram h)
{
	std::string s = "";
	for (int i = 0; i < h.size(); i++) {
		s += ' ';
		s += std::to_string(h[i]);
	}
	s += '\n';
	return s;
}

C_CheckWithHist::C_CheckWithHist()
{
	init();
}

void C_CheckWithHist::init()
{
	mainMax = 0;
	mainMax_arr.clear();
	mainMax_arr.push_back({ -1, -1, 0, 0, 0 });  // int i, j, Ls, Us, size;
} // end of construltor C_CheckWithHist

C_CheckWithHist::~C_CheckWithHist()
{
}

T_MaxRecVec C_CheckWithHist::find_max_rectangle_in_hist(T_Histogram x)
{
	max_rect_in_histogram(x, 2, x.size());
	return get_max_rect_vec();
}

void C_CheckWithHist::new_max(int size, int col, int row, int col_w, int row_h)
{
	if (size > mainMax) {          // create new max
		mainMax = size;
		mainMax_arr.clear();
	}
	mainMax_arr.push_back({ col, row - row_h + 1, col_w, row_h, size });
}

void C_CheckWithHist::max_rect_in_histogram(T_Histogram x, int y, int N)
{
	int i = 0;
	T_Last last = { i, x[i] };
	stack_last.push({ -1, -1 });
	i++;
	int xi, w, size;

	while (i < N) {
		xi = x[i];
		while (xi >= last.h) {
			if (xi > last.h) {
				stack_last.push(last);
				last = { i, xi };
			}
			i++;
			if (i >= N) {
				xi = 0; break;
			}
			else {
				xi = x[i];
			}
		}

		do {
			w = i - last.i;
			size = w * last.h;
			if (size >= mainMax) {
				new_max(size, last.i, y, w, last.h);
			}
			if (xi > 0 && stack_last.top().h < xi) {
				last.h = xi;
			}
			else {
				last = stack_last.top();
				stack_last.pop();
			}
		} while (last.h > xi);

		if (i >= N) { return; }

		while ((i < N) && (x[i] == 0)) {  // skip all 0s
			i++;
		}
	}
}  // max_rect_in_histogram()


T_MaxRecVec C_CheckWithHist::find_max_rectangle(C_Matrix ^M)
{
	init();
	const int rows = M->get_h();
	const int cols = M->get_w();
	const int N = cols;

	T_Histogram h0(cols, 0);
	//T_Histogram h0 = { 0,0,0,0 };

	//std::string s1 = str_hist(h0);

	for (int row = 0; row < rows; row++) {
		//s1 = str_hist(h0);
		//build_histogram(M, N, row, h0);
		for (int j = 0; j < N; j++) {
			if ((*(M->a))[row][j]) {
				h0[j] += 1;
			}
			else {
				h0[j] = 0;
			}
		}
		//s1 = str_hist(h0);
		max_rect_in_histogram(h0, row, N);
	}
	return mainMax_arr;
}

// end of class C_CheckWithHist  ============================================



// begin of class C_CheckWithHist_FromWeb  vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv

// This code is based on http://www.geeksforgeeks.org/largest-rectangle-under-histogram/
// I made couple of changes: 
// 1) to use boolean matrix instead of 1/0.
// 2) to use vector for array
// 3) to have {row,col, row-size,col-size} for max rectangle to be able to draw the result(s)


C_CheckWithHist_FromWeb::C_CheckWithHist_FromWeb()
{
	init();
}

void C_CheckWithHist_FromWeb::init()
{
	mainMax = 0;
	mainMax_arr.clear();
	mainMax_arr.push_back({ -1, -1, 0, 0, 0 });  // int i, j, Ls, Us, size;
} // end of construltor C_CheckWithHist_FromWeb

C_CheckWithHist_FromWeb::~C_CheckWithHist_FromWeb()
{
}

void C_CheckWithHist_FromWeb::new_max(int size, int col, int row, int col_w, int row_h)
{
	if (size > mainMax) {          // create new max
		mainMax = size;
		mainMax_arr.clear();
	}
	mainMax_arr.push_back({ col, row - row_h + 1, col_w, row_h, size });
}


void C_CheckWithHist_FromWeb::max_rect_in_histogram(T_Histogram hist, int y, int N) {
	// Create an empty stack. The stack holds indexes of hist[] array
	// The bars stored in stack are always in increasing order of their
	// heights.
	std::stack<int> s;

	// it's this.mainMax in my code
	//int max_area = 0; // Initalize max area
	int tp;   // To store top of stack
	int area; // To store area with top bar as the smallest bar
	int w;    // width of rectangle            // my var. due to new_max()

	// Run through all bars of given histogram
	int i = 0;
	while (i < N)
	{
		// If this bar is higher than the bar on top stack, push it to stack
		if (s.empty() || hist[s.top()] <= hist[i])
			s.push(i++);

		// If this bar is lower than top of stack, then calculate area of rectangle 
		// with stack top as the smallest (or minimum height) bar. 'i' is 
		// 'right index' for the top and element before top in stack is 'left index'
		else
		{
			tp = s.top();  // store the top index
			s.pop();  // pop the top

			// Calculate the area with hist[tp] stack as smallest bar
			w = (s.empty() ? i : i - s.top() - 1);
			area = hist[tp] * w;

			// update max area, if needed
			if (area >= mainMax) {
				new_max(area, i - w, y, w, hist[tp]);
			}
		}
	}

	// Now pop the remaining bars from stack and calculate area with every
	// popped bar as the smallest bar
	while (s.empty() == false)
	{
		tp = s.top();
		s.pop();
		w = (s.empty() ? i : i - s.top() - 1);
		area = hist[tp] * w;

		if (area >= mainMax) {
			new_max(area, i - w, y, w, hist[tp]);
		}
	}
}  // of max_rect_in_histogram()


T_MaxRecVec C_CheckWithHist_FromWeb::find_max_rectangle(C_Matrix ^M) {
	// Returns area of the largest rectangle with all 1s in A[][]
	// Calculate area for first row and initialize it as result

	init();
	const int rows = M->get_h();
	const int cols = M->get_w();
	const int N = cols;

	T_Histogram h0(cols, 0);

	// iterate over row to find maximum rectangular area
	// considering each row as histogram
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < N; j++) {
			if ((*(M->a))[i][j]) {
				h0[j] += 1;
			}
			else {
				h0[j] = 0;
			}
		}
		max_rect_in_histogram(h0, i, N);
	}
	return mainMax_arr;
} // of find_max_rectangle()

// end of class C_CheckWithHist_FromWeb  ========================================
