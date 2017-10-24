#pragma once

#include "C_Matrix.h"
#include "C_CheckMatrix.h"
#include <iostream>
#include <msclr/marshal.h>  // for String^ -> char*

#define DEFAULT_FLOOR_OFFSET 20
#define DEFAULT_FLOOR_OFFSET_X DEFAULT_FLOOR_OFFSET
#define DEFAULT_FLOOR_OFFSET_Y DEFAULT_FLOOR_OFFSET
#define STONE_COLOR Color::DimGray
#define FREE_COLOR  Color::White

namespace obdelnik03wingui01 {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;



    /// <summary>
    /// Summary for MyForm
    /// </summary>
    public ref class MyForm : public System::Windows::Forms::Form
    {
        Int32 SMALL_RECT_SIZE = 10;

        ref class Floor   // --- Floor --- Floor --- Floor --- Floor --- Floor 
        {
            Int32 SMALL_RECT_SIZE = 10;

            int h, w;		// Height and width of floor in px
            int rows, cols;   // height and width of floor in tile
            int size_sq;
            int perct;      // 
            Color stone_color;
            Color free_color;
            int offset_x, offset_y;  // offset from origin of pixBox
            Graphics^ g;             // A Graphics handle; = Graphics::FromImage(pic_Pic1->Image);
            PictureBox^ picBox;      // 
            int pic_box_h, pic_box_w;  // size of picBox

            C_Matrix^ M = gcnew C_Matrix();
            C_CheckMatrix *pCM = new C_CheckMatrix();

            public:
            Floor(PictureBox^ picBox_, int rows_, int cols_, int off_x, int off_y,
                  Color stone_color_, Color free_color_)
            {
                init_picBox(picBox_);    // Prepare an image component and a Graphics handle.
                cols = cols_;
                rows = rows_;
                size_sq = SMALL_RECT_SIZE;
                h = calc_line_length(rows);
                w = calc_line_length(cols);
                offset_x = off_x;
                offset_y = off_y;
                stone_color = stone_color_;
                free_color = free_color_;
            }

            ~Floor()
            {
            }

            void init_picBox(PictureBox^ picBox_)
            {
                picBox = picBox_;
                pic_box_w = picBox->Width;
                pic_box_h = picBox->Height;
                //	Prepare an image component and a Graphics handle.
                picBox->Image = gcnew Bitmap(pic_box_w, pic_box_h);
                g = Graphics::FromImage(picBox->Image);
            }

            int calc_line_length(int tiles_num)
            {
                return tiles_num * size_sq;
            }

            void set_rows(int rows_)
            {
                rows = rows_;
                h = calc_line_length(rows);
            }

            void set_cols(int cols_)
            {
                cols = cols_;
                w = calc_line_length(cols);
            }

            void clear_rect(int x_, int y_, int w_, int h_)
            {
                picBox->Image = picBox->Image;  // needed per tutor
                Color color = picBox->BackColor;
                SolidBrush^ myBrush = gcnew SolidBrush(color);
                g->FillRectangle(myBrush, x_, y_, w_, h_);
                //g->FillRectangle(myBrush, rect);
                delete myBrush;
            }

            void clear_pic_box()
            {
                clear_rect(0, 0, pic_box_w, pic_box_h);
            }

            void clear_floor()
            {
                clear_rect(offset_x, offset_y, w + 1, h + 1);
            }

            bool is_in_floor(int X, int Y)
            {
                if (offset_x < X && offset_y < Y && (X - offset_x) < w && (Y - offset_y) < h) {
                    return true;
                } else {
                    return false;
                }
            }

            int calc_col_from_x(int x)
            {
                return (x - offset_x) / size_sq;
            }

            int calc_row_from_y(int y)
            {
                return (y - offset_y) / size_sq;
            }

            void find_and_invert(int X, int Y)
            {
                int row = calc_row_from_y(Y);
                int col = calc_col_from_x(X);
                invert_small_rect(row, col);
            }

            void draw_x_line(Pen^ pen, Point loc, Int32 length)
            {
                Int32 x, y;
                x = loc.X;
                y = loc.Y;
                g->DrawLine(pen, loc, Point(x + length, y));
            }

            void draw_y_line(Pen^ pen, Point loc, Int32 length)
            {
                Int32 x, y;
                x = loc.X;
                y = loc.Y;
                g->DrawLine(pen, loc, Point(x, y + length));
            }

            // draw small rectangle on position [row,col] in matrix
            void draw_small_rect(const int row, const int col, const Color color)
            {
                picBox->Image = picBox->Image;  // needed per tutor
                int y = row*size_sq + 1;
                int x = col*size_sq + 1;
                int size = size_sq - 1;
                SolidBrush^ myBrush = gcnew SolidBrush(color);
                g->FillRectangle(myBrush, x + offset_x, y + offset_y, size, size);
                //g->FillRectangle(myBrush, rect);
                delete myBrush;
            }

            void draw_small_rect(const int row, const int col)
            {
                if (M->get_1(row, col)) { // free
                    draw_small_rect(row, col, free_color);
                } else {            // stone
                    draw_small_rect(row, col, stone_color);
                }
            }

            void invert_small_rect(int row, int col)
            {
                if (M->is_valid()) {
                    M->negate_1(row, col);
                    draw_small_rect(row, col);
                }
            }

            void draw_result_rect(const int row, const int col,
                                  int size_row, int size_col, const Color color)
            {
                picBox->Image = picBox->Image;  // needed per tutor
                int y = row*size_sq + 2;
                int x = col*size_sq + 2;
                int size_y = size_row * size_sq - 4;
                int size_x = size_col * size_sq - 4;
                float width = 3.0;
                //SolidBrush^ myBrush = gcnew SolidBrush(color);
                Pen^ myPen = gcnew Pen(color, width);
                g->DrawRectangle(myPen, x + offset_x, y + offset_y, size_x, size_y);
                //g->FillRectangle(myBrush, rect);
                //delete myBrush;
                delete myPen;
            }

            void draw_floor()
            {
                for (Int32 i = 0; i <= cols; i++) {
                    draw_y_line(Pens::Black,
                                Point(i*size_sq + offset_x, 0 + offset_y), Int32(h));
                }
                for (Int32 i = 0; i <= rows; i++) {
                    draw_x_line(Pens::Black,
                                Point(0 + offset_x, i*size_sq + offset_y), Int32(w));
                }
                draw_matrix();
            }

            void draw_matrix()
            {
                try {
                    if (M->is_valid()) {
                        for (size_t i = 0; i < rows; i++) {
                            for (size_t j = 0; j < cols; j++) {
                                draw_small_rect(i, j);
                            }
                        }
                    }
                }
                catch (const std::exception& e) {
                    // M->get_1() can throw excp. => don't draw matrix
                }
            }

            void redraw_floor()
            {
                clear_floor();
                draw_floor();
            }

            void draw_border()
            {
                const int FONT_SIZE = 8;
                int x, y;    // for drawinng text
                String^ str = "";
                msclr::interop::marshal_context ctx;
                const char* converted = ctx.marshal_as<const char*>(str);
                std::cout << "h: " << h << " str: " << converted << std::endl;

                System::Drawing::Font^ drawFont = gcnew System::Drawing::Font("Consolas", FONT_SIZE);
                SolidBrush^ myBrush = gcnew SolidBrush(Color::Red);

                // left border : DirectionRightToLeft
                StringFormat^ format = gcnew StringFormat(StringFormatFlags::DirectionRightToLeft);
                str = (rows > 1) ? Int32(rows - 1).ToString() : "";
                x = offset_x;
                y = offset_y;
                g->DrawString("0", drawFont, myBrush, x, y, format);
                g->DrawString(str, drawFont, myBrush, x, y + h - (FONT_SIZE + 4), format);

                // top border, no format
                str = (cols > 1) ? Int32(cols - 1).ToString() : "";
                x = offset_x;
                y = offset_y - (FONT_SIZE + 4);
                g->DrawString("0", drawFont, myBrush, x, y);
                g->DrawString(str, drawFont, myBrush, x + w - (FONT_SIZE + 4), y);

                delete drawFont;
                delete myBrush;
            }

            void draw_pic_box()
            {
                draw_floor();
                draw_border();
            }

            void redraw_pic_box()
            {
                clear_pic_box();
                draw_pic_box();
            }


            void set_full_matrix_free()      // free => true
            {
                M->init(rows, cols);
                M->set_full_true();
            }

            void set_full_matrix_occupied()  // stone => false
            {
                M->init(rows, cols);
                M->set_full_false();
            }

            void set_matrix_invalid()
            {
                M->set_invalid();
            }

            void set_matrix_random(float perct)
            {
                M->init(rows, cols);
                M->generate_random(perct);
            }

            // === C_CheckMatrix part

            void draw_max_rec(C_CheckMatrix::T_MaxRec r, Color color)  //i, j, Ls, Us
            {
                int row, col;
                col = r.j - r.Ls + 1;
                row = r.i - r.Us + 1;
                draw_result_rect(row, col, r.Us, r.Ls, color);
            }

            String^ str_max_rec(C_CheckMatrix::T_MaxRec r)  //i, j, Ls, Us
            {
                String^ str_rect = "";
                //str_rect += "pos: " + r.i + "," + r.j + "  size: " + r.Ls + " x " + r.Us + "\n";
                str_rect = str_rect->Format("pos: {0,3:D},{1,3:D}  size: {2,3:D} x{3,3:D}",
                                            r.j - r.Ls + 1, r.i - r.Us + 1, r.Ls, r.Us);
                return str_rect;
            }

            String^ get_str_max_rec()
            {
                String^ str = "";
                if (pCM->get_max_size() <= 0) {
                    return "no rectangle found";
                }

                C_CheckMatrix::T_MaxRecVec max_rec_vec = pCM->get_max_rect_vec();
                C_CheckMatrix::T_MaxRecVec::const_iterator r;  // pointer

                for (r = max_rec_vec.begin(); r != max_rec_vec.end(); ++r) {
                    str += str_max_rec(*r) + "\n";
                }
                return str;
            }

            C_CheckMatrix::T_MaxRecVec find_max_rectangle(Color color)
            {
                //String^ rectangles_text;
                C_CheckMatrix::T_MaxRecVec max_rec_vec = pCM->find_max_rectangle(M);

                C_CheckMatrix::T_MaxRecVec::const_iterator max_rec;  // pointer

                for (max_rec = max_rec_vec.begin(); max_rec != max_rec_vec.end(); ++max_rec) {
                    draw_max_rec(*max_rec, color);
                }

                //rectangles_text = "a\na\na\na\na\na\na\na\na\na\na\na\nbbbb";
                //return rectangles_text;
                return max_rec_vec;
            }

        };  // of class Floor  === Floor === Floor === Floor === Floor === Floor 




        public:
        MyForm(void)
        {
            InitializeComponent();
            //
            //TODO: Add the constructor code here
            //
        }

        protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~MyForm()
        {
            if (components) {
                delete components;
            }
        }
        private: System::Windows::Forms::Label^  lab_Size_height;
        private: System::Windows::Forms::Label^  lab_Size_width;
        protected:

        protected:

        private: System::Windows::Forms::GroupBox^  grp_Size;
        private: System::Windows::Forms::NumericUpDown^  num_Size_width;
        private: System::Windows::Forms::NumericUpDown^  num_Size_height;
        private: System::Windows::Forms::CheckBox^  ckbox_Size_lockRatio;
        private: System::Windows::Forms::Label^  lab_Size_x;
        private: System::Windows::Forms::PictureBox^  pic_Pic1;



        private: System::Windows::Forms::GroupBox^  grp_Edit;
        private: System::Windows::Forms::Label^  lab_Edit_manually;
        private: System::Windows::Forms::NumericUpDown^  num_Edit_percent;
        private: System::Windows::Forms::Button^  but_Edit_plus10;
        private: System::Windows::Forms::Button^  but_Edit_fullFill;
        private: System::Windows::Forms::Button^  but_Edit_fullFree;

        private: System::Windows::Forms::Label^  lab_Edit_random;
        private: System::Windows::Forms::Label^  lab_Edit_percent;
        private: System::Windows::Forms::Button^  but_Edit_generate;
        private: System::Windows::Forms::Button^  but_Edit_minus10;
        private: System::Windows::Forms::GroupBox^  grp_Find;
        private: System::Windows::Forms::Button^  but_Find_start;
        private: System::Windows::Forms::Label^  lab_Find_max_rect;
        private: System::Windows::Forms::GroupBox^  grp_Result;
        private: System::Windows::Forms::Label^  lab_Result_size;

        private: System::Windows::Forms::Label^  lab_Result_maxRect;
        private: System::Windows::Forms::Label^  lab_Result_rects;
        private: System::Windows::Forms::Panel^  panel_Result_out;
        private: System::Windows::Forms::Panel^  panel_Result_in;
        private: System::Windows::Forms::Button^  but_Size_max_size;
        private: System::Windows::Forms::Button^  but_Find_clear;



        private: System::Windows::Forms::GroupBox^  grp_Pic1;







        private:
        /// <summary>
        /// Required designer variable.
        /// </summary>
        System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        void InitializeComponent(void)
        {
            this->grp_Size = (gcnew System::Windows::Forms::GroupBox());
            this->but_Size_max_size = (gcnew System::Windows::Forms::Button());
            this->ckbox_Size_lockRatio = (gcnew System::Windows::Forms::CheckBox());
            this->lab_Size_x = (gcnew System::Windows::Forms::Label());
            this->num_Size_width = (gcnew System::Windows::Forms::NumericUpDown());
            this->num_Size_height = (gcnew System::Windows::Forms::NumericUpDown());
            this->lab_Size_height = (gcnew System::Windows::Forms::Label());
            this->lab_Size_width = (gcnew System::Windows::Forms::Label());
            this->grp_Pic1 = (gcnew System::Windows::Forms::GroupBox());
            this->pic_Pic1 = (gcnew System::Windows::Forms::PictureBox());
            this->grp_Edit = (gcnew System::Windows::Forms::GroupBox());
            this->lab_Edit_percent = (gcnew System::Windows::Forms::Label());
            this->but_Edit_generate = (gcnew System::Windows::Forms::Button());
            this->but_Edit_minus10 = (gcnew System::Windows::Forms::Button());
            this->num_Edit_percent = (gcnew System::Windows::Forms::NumericUpDown());
            this->but_Edit_plus10 = (gcnew System::Windows::Forms::Button());
            this->but_Edit_fullFill = (gcnew System::Windows::Forms::Button());
            this->but_Edit_fullFree = (gcnew System::Windows::Forms::Button());
            this->lab_Edit_random = (gcnew System::Windows::Forms::Label());
            this->lab_Edit_manually = (gcnew System::Windows::Forms::Label());
            this->grp_Find = (gcnew System::Windows::Forms::GroupBox());
            this->but_Find_clear = (gcnew System::Windows::Forms::Button());
            this->but_Find_start = (gcnew System::Windows::Forms::Button());
            this->lab_Find_max_rect = (gcnew System::Windows::Forms::Label());
            this->grp_Result = (gcnew System::Windows::Forms::GroupBox());
            this->panel_Result_out = (gcnew System::Windows::Forms::Panel());
            this->panel_Result_in = (gcnew System::Windows::Forms::Panel());
            this->lab_Result_rects = (gcnew System::Windows::Forms::Label());
            this->lab_Result_size = (gcnew System::Windows::Forms::Label());
            this->lab_Result_maxRect = (gcnew System::Windows::Forms::Label());
            this->grp_Size->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->num_Size_width))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->num_Size_height))->BeginInit();
            this->grp_Pic1->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pic_Pic1))->BeginInit();
            this->grp_Edit->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->num_Edit_percent))->BeginInit();
            this->grp_Find->SuspendLayout();
            this->grp_Result->SuspendLayout();
            this->panel_Result_out->SuspendLayout();
            this->panel_Result_in->SuspendLayout();
            this->SuspendLayout();
            // 
            // grp_Size
            // 
            this->grp_Size->Controls->Add(this->but_Size_max_size);
            this->grp_Size->Controls->Add(this->ckbox_Size_lockRatio);
            this->grp_Size->Controls->Add(this->lab_Size_x);
            this->grp_Size->Controls->Add(this->num_Size_width);
            this->grp_Size->Controls->Add(this->num_Size_height);
            this->grp_Size->Controls->Add(this->lab_Size_height);
            this->grp_Size->Controls->Add(this->lab_Size_width);
            this->grp_Size->Dock = System::Windows::Forms::DockStyle::Top;
            this->grp_Size->Location = System::Drawing::Point(5, 5);
            this->grp_Size->MaximumSize = System::Drawing::Size(300, 70);
            this->grp_Size->MinimumSize = System::Drawing::Size(300, 70);
            this->grp_Size->Name = L"grp_Size";
            this->grp_Size->Size = System::Drawing::Size(300, 70);
            this->grp_Size->TabIndex = 2;
            this->grp_Size->TabStop = false;
            this->grp_Size->Text = L"Size";
            // 
            // but_Size_max_size
            // 
            this->but_Size_max_size->Location = System::Drawing::Point(189, 11);
            this->but_Size_max_size->Name = L"but_Size_max_size";
            this->but_Size_max_size->Size = System::Drawing::Size(75, 23);
            this->but_Size_max_size->TabIndex = 5;
            this->but_Size_max_size->Text = L"Max Size";
            this->but_Size_max_size->UseVisualStyleBackColor = true;
            this->but_Size_max_size->Click += gcnew System::EventHandler(this, &MyForm::but_MaxSize_Click);
            // 
            // ckbox_Size_lockRatio
            // 
            this->ckbox_Size_lockRatio->AutoSize = true;
            this->ckbox_Size_lockRatio->Enabled = false;
            this->ckbox_Size_lockRatio->Location = System::Drawing::Point(189, 40);
            this->ckbox_Size_lockRatio->Name = L"ckbox_Size_lockRatio";
            this->ckbox_Size_lockRatio->Size = System::Drawing::Size(69, 17);
            this->ckbox_Size_lockRatio->TabIndex = 4;
            this->ckbox_Size_lockRatio->Text = L"lock ratio";
            this->ckbox_Size_lockRatio->UseVisualStyleBackColor = true;
            // 
            // lab_Size_x
            // 
            this->lab_Size_x->AutoSize = true;
            this->lab_Size_x->Location = System::Drawing::Point(84, 39);
            this->lab_Size_x->Name = L"lab_Size_x";
            this->lab_Size_x->Size = System::Drawing::Size(12, 13);
            this->lab_Size_x->TabIndex = 5;
            this->lab_Size_x->Text = L"x";
            // 
            // num_Size_width
            // 
            this->num_Size_width->Location = System::Drawing::Point(102, 37);
            this->num_Size_width->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 30, 0, 0, 0 });
            this->num_Size_width->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
            this->num_Size_width->Name = L"num_Size_width";
            this->num_Size_width->Size = System::Drawing::Size(71, 20);
            this->num_Size_width->TabIndex = 3;
            this->num_Size_width->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            this->num_Size_width->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 15, 0, 0, 0 });
            this->num_Size_width->ValueChanged += gcnew System::EventHandler(this, &MyForm::width_Click);
            // 
            // num_Size_height
            // 
            this->num_Size_height->Location = System::Drawing::Point(10, 37);
            this->num_Size_height->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 20, 0, 0, 0 });
            this->num_Size_height->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
            this->num_Size_height->Name = L"num_Size_height";
            this->num_Size_height->Size = System::Drawing::Size(68, 20);
            this->num_Size_height->TabIndex = 2;
            this->num_Size_height->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            this->num_Size_height->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
            this->num_Size_height->ValueChanged += gcnew System::EventHandler(this, &MyForm::height_Click);
            // 
            // lab_Size_height
            // 
            this->lab_Size_height->AutoSize = true;
            this->lab_Size_height->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                                                                       static_cast<System::Byte>(238)));
            this->lab_Size_height->Location = System::Drawing::Point(21, 21);
            this->lab_Size_height->Name = L"lab_Size_height";
            this->lab_Size_height->Size = System::Drawing::Size(33, 13);
            this->lab_Size_height->TabIndex = 0;
            this->lab_Size_height->Text = L"rows";
            // 
            // lab_Size_width
            // 
            this->lab_Size_width->AutoSize = true;
            this->lab_Size_width->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                                                                      static_cast<System::Byte>(238)));
            this->lab_Size_width->Location = System::Drawing::Point(99, 21);
            this->lab_Size_width->Name = L"lab_Size_width";
            this->lab_Size_width->Size = System::Drawing::Size(53, 13);
            this->lab_Size_width->TabIndex = 1;
            this->lab_Size_width->Text = L"columns";
            // 
            // grp_Pic1
            // 
            this->grp_Pic1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                                                                                         | System::Windows::Forms::AnchorStyles::Left)
                                                                                        | System::Windows::Forms::AnchorStyles::Right));
            this->grp_Pic1->Controls->Add(this->pic_Pic1);
            this->grp_Pic1->Location = System::Drawing::Point(5, 76);
            this->grp_Pic1->MinimumSize = System::Drawing::Size(300, 0);
            this->grp_Pic1->Name = L"grp_Pic1";
            this->grp_Pic1->Size = System::Drawing::Size(300, 193);
            this->grp_Pic1->TabIndex = 3;
            this->grp_Pic1->TabStop = false;
            this->grp_Pic1->Text = L"Matrix";
            // 
            // pic_Pic1
            // 
            this->pic_Pic1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                                                                                         | System::Windows::Forms::AnchorStyles::Left)
                                                                                        | System::Windows::Forms::AnchorStyles::Right));
            this->pic_Pic1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
            this->pic_Pic1->Location = System::Drawing::Point(3, 16);
            this->pic_Pic1->Name = L"pic_Pic1";
            this->pic_Pic1->Size = System::Drawing::Size(294, 174);
            this->pic_Pic1->TabIndex = 4;
            this->pic_Pic1->TabStop = false;
            this->pic_Pic1->SizeChanged += gcnew System::EventHandler(this, &MyForm::pic_box_Resize);
            this->pic_Pic1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pic1_MouseClick);
            // 
            // grp_Edit
            // 
            this->grp_Edit->Controls->Add(this->lab_Edit_percent);
            this->grp_Edit->Controls->Add(this->but_Edit_generate);
            this->grp_Edit->Controls->Add(this->but_Edit_minus10);
            this->grp_Edit->Controls->Add(this->num_Edit_percent);
            this->grp_Edit->Controls->Add(this->but_Edit_plus10);
            this->grp_Edit->Controls->Add(this->but_Edit_fullFill);
            this->grp_Edit->Controls->Add(this->but_Edit_fullFree);
            this->grp_Edit->Controls->Add(this->lab_Edit_random);
            this->grp_Edit->Controls->Add(this->lab_Edit_manually);
            this->grp_Edit->Dock = System::Windows::Forms::DockStyle::Bottom;
            this->grp_Edit->Location = System::Drawing::Point(5, 272);
            this->grp_Edit->MaximumSize = System::Drawing::Size(300, 90);
            this->grp_Edit->MinimumSize = System::Drawing::Size(300, 90);
            this->grp_Edit->Name = L"grp_Edit";
            this->grp_Edit->Size = System::Drawing::Size(300, 90);
            this->grp_Edit->TabIndex = 10;
            this->grp_Edit->TabStop = false;
            this->grp_Edit->Text = L"Edit";
            // 
            // lab_Edit_percent
            // 
            this->lab_Edit_percent->AutoSize = true;
            this->lab_Edit_percent->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                                                                        static_cast<System::Byte>(238)));
            this->lab_Edit_percent->Location = System::Drawing::Point(144, 54);
            this->lab_Edit_percent->Name = L"lab_Edit_percent";
            this->lab_Edit_percent->Size = System::Drawing::Size(16, 13);
            this->lab_Edit_percent->TabIndex = 10;
            this->lab_Edit_percent->Text = L"%";
            // 
            // but_Edit_generate
            // 
            this->but_Edit_generate->Location = System::Drawing::Point(215, 49);
            this->but_Edit_generate->Name = L"but_Edit_generate";
            this->but_Edit_generate->Size = System::Drawing::Size(61, 23);
            this->but_Edit_generate->TabIndex = 16;
            this->but_Edit_generate->Text = L"Generate";
            this->but_Edit_generate->UseVisualStyleBackColor = true;
            this->but_Edit_generate->Click += gcnew System::EventHandler(this, &MyForm::but_Generate_Click);
            // 
            // but_Edit_minus10
            // 
            this->but_Edit_minus10->Location = System::Drawing::Point(63, 49);
            this->but_Edit_minus10->Name = L"but_Edit_minus10";
            this->but_Edit_minus10->Size = System::Drawing::Size(33, 23);
            this->but_Edit_minus10->TabIndex = 13;
            this->but_Edit_minus10->Text = L"-10";
            this->but_Edit_minus10->UseVisualStyleBackColor = true;
            this->but_Edit_minus10->Click += gcnew System::EventHandler(this, &MyForm::minus10_Click);
            // 
            // num_Edit_percent
            // 
            this->num_Edit_percent->Location = System::Drawing::Point(102, 52);
            this->num_Edit_percent->Name = L"num_Edit_percent";
            this->num_Edit_percent->Size = System::Drawing::Size(42, 20);
            this->num_Edit_percent->TabIndex = 14;
            this->num_Edit_percent->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            this->num_Edit_percent->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
            // 
            // but_Edit_plus10
            // 
            this->but_Edit_plus10->Location = System::Drawing::Point(166, 49);
            this->but_Edit_plus10->Name = L"but_Edit_plus10";
            this->but_Edit_plus10->Size = System::Drawing::Size(33, 23);
            this->but_Edit_plus10->TabIndex = 15;
            this->but_Edit_plus10->Text = L"+10";
            this->but_Edit_plus10->UseVisualStyleBackColor = true;
            this->but_Edit_plus10->Click += gcnew System::EventHandler(this, &MyForm::plus10_Click);
            // 
            // but_Edit_fullFill
            // 
            this->but_Edit_fullFill->Location = System::Drawing::Point(147, 19);
            this->but_Edit_fullFill->Name = L"but_Edit_fullFill";
            this->but_Edit_fullFill->Size = System::Drawing::Size(82, 23);
            this->but_Edit_fullFill->TabIndex = 12;
            this->but_Edit_fullFill->Text = L"Full Occupied";
            this->but_Edit_fullFill->UseVisualStyleBackColor = true;
            this->but_Edit_fullFill->Click += gcnew System::EventHandler(this, &MyForm::but_FullBlack_Click);
            // 
            // but_Edit_fullFree
            // 
            this->but_Edit_fullFree->Location = System::Drawing::Point(63, 20);
            this->but_Edit_fullFree->Name = L"but_Edit_fullFree";
            this->but_Edit_fullFree->Size = System::Drawing::Size(75, 23);
            this->but_Edit_fullFree->TabIndex = 11;
            this->but_Edit_fullFree->Text = L"Full Free";
            this->but_Edit_fullFree->UseVisualStyleBackColor = true;
            this->but_Edit_fullFree->Click += gcnew System::EventHandler(this, &MyForm::but_FullEmpty_Click);
            // 
            // lab_Edit_random
            // 
            this->lab_Edit_random->AutoSize = true;
            this->lab_Edit_random->Location = System::Drawing::Point(9, 54);
            this->lab_Edit_random->Name = L"lab_Edit_random";
            this->lab_Edit_random->Size = System::Drawing::Size(50, 13);
            this->lab_Edit_random->TabIndex = 10;
            this->lab_Edit_random->Text = L"Random:";
            // 
            // lab_Edit_manually
            // 
            this->lab_Edit_manually->AutoSize = true;
            this->lab_Edit_manually->Location = System::Drawing::Point(6, 25);
            this->lab_Edit_manually->Name = L"lab_Edit_manually";
            this->lab_Edit_manually->Size = System::Drawing::Size(52, 13);
            this->lab_Edit_manually->TabIndex = 10;
            this->lab_Edit_manually->Text = L"Manually:";
            // 
            // grp_Find
            // 
            this->grp_Find->Controls->Add(this->but_Find_clear);
            this->grp_Find->Controls->Add(this->but_Find_start);
            this->grp_Find->Controls->Add(this->lab_Find_max_rect);
            this->grp_Find->Dock = System::Windows::Forms::DockStyle::Bottom;
            this->grp_Find->Location = System::Drawing::Point(5, 362);
            this->grp_Find->MaximumSize = System::Drawing::Size(300, 40);
            this->grp_Find->MinimumSize = System::Drawing::Size(300, 40);
            this->grp_Find->Name = L"grp_Find";
            this->grp_Find->Size = System::Drawing::Size(300, 40);
            this->grp_Find->TabIndex = 20;
            this->grp_Find->TabStop = false;
            this->grp_Find->Text = L"Find";
            // 
            // but_Find_clear
            // 
            this->but_Find_clear->Location = System::Drawing::Point(189, 11);
            this->but_Find_clear->Name = L"but_Find_clear";
            this->but_Find_clear->Size = System::Drawing::Size(65, 23);
            this->but_Find_clear->TabIndex = 22;
            this->but_Find_clear->Text = L"Clear";
            this->but_Find_clear->UseVisualStyleBackColor = true;
            this->but_Find_clear->Click += gcnew System::EventHandler(this, &MyForm::but_Clear_Click);
            // 
            // but_Find_start
            // 
            this->but_Find_start->Enabled = false;
            this->but_Find_start->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                                                                      static_cast<System::Byte>(238)));
            this->but_Find_start->ForeColor = System::Drawing::Color::Green;
            this->but_Find_start->Location = System::Drawing::Point(108, 11);
            this->but_Find_start->Name = L"but_Find_start";
            this->but_Find_start->Size = System::Drawing::Size(65, 23);
            this->but_Find_start->TabIndex = 21;
            this->but_Find_start->Text = L"Start";
            this->but_Find_start->UseVisualStyleBackColor = true;
            this->but_Find_start->EnabledChanged += gcnew System::EventHandler(this, &MyForm::but_Find_start_change);
            this->but_Find_start->Click += gcnew System::EventHandler(this, &MyForm::but_Start_Click);
            // 
            // lab_Find_max_rect
            // 
            this->lab_Find_max_rect->AutoSize = true;
            this->lab_Find_max_rect->Location = System::Drawing::Point(6, 16);
            this->lab_Find_max_rect->Name = L"lab_Find_max_rect";
            this->lab_Find_max_rect->Size = System::Drawing::Size(96, 13);
            this->lab_Find_max_rect->TabIndex = 20;
            this->lab_Find_max_rect->Text = L"Find max. rectanle:";
            // 
            // grp_Result
            // 
            this->grp_Result->Controls->Add(this->panel_Result_out);
            this->grp_Result->Controls->Add(this->lab_Result_size);
            this->grp_Result->Controls->Add(this->lab_Result_maxRect);
            this->grp_Result->Dock = System::Windows::Forms::DockStyle::Bottom;
            this->grp_Result->Location = System::Drawing::Point(5, 402);
            this->grp_Result->MinimumSize = System::Drawing::Size(300, 180);
            this->grp_Result->Name = L"grp_Result";
            this->grp_Result->Size = System::Drawing::Size(300, 180);
            this->grp_Result->TabIndex = 7;
            this->grp_Result->TabStop = false;
            this->grp_Result->Text = L"Result";
            // 
            // panel_Result_out
            // 
            this->panel_Result_out->Controls->Add(this->panel_Result_in);
            this->panel_Result_out->Location = System::Drawing::Point(6, 32);
            this->panel_Result_out->Name = L"panel_Result_out";
            this->panel_Result_out->Size = System::Drawing::Size(273, 139);
            this->panel_Result_out->TabIndex = 3;
            // 
            // panel_Result_in
            // 
            this->panel_Result_in->AutoScroll = true;
            this->panel_Result_in->Controls->Add(this->lab_Result_rects);
            this->panel_Result_in->Location = System::Drawing::Point(5, 3);
            this->panel_Result_in->Name = L"panel_Result_in";
            this->panel_Result_in->Size = System::Drawing::Size(263, 131);
            this->panel_Result_in->TabIndex = 3;
            // 
            // lab_Result_rects
            // 
            this->lab_Result_rects->AutoSize = true;
            this->lab_Result_rects->Font = (gcnew System::Drawing::Font(L"Consolas", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                                                                        static_cast<System::Byte>(238)));
            this->lab_Result_rects->Location = System::Drawing::Point(3, 3);
            this->lab_Result_rects->Name = L"lab_Result_rects";
            this->lab_Result_rects->Size = System::Drawing::Size(103, 13);
            this->lab_Result_rects->TabIndex = 2;
            this->lab_Result_rects->Text = L"results: not yet";
            // 
            // lab_Result_size
            // 
            this->lab_Result_size->AutoSize = true;
            this->lab_Result_size->Location = System::Drawing::Point(125, 16);
            this->lab_Result_size->Name = L"lab_Result_size";
            this->lab_Result_size->Size = System::Drawing::Size(13, 13);
            this->lab_Result_size->TabIndex = 1;
            this->lab_Result_size->Text = L"0";
            // 
            // lab_Result_maxRect
            // 
            this->lab_Result_maxRect->AutoSize = true;
            this->lab_Result_maxRect->Location = System::Drawing::Point(6, 16);
            this->lab_Result_maxRect->Name = L"lab_Result_maxRect";
            this->lab_Result_maxRect->Size = System::Drawing::Size(107, 13);
            this->lab_Result_maxRect->TabIndex = 0;
            this->lab_Result_maxRect->Text = L"Max. rectangle - size:";
            // 
            // MyForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(310, 587);
            this->Controls->Add(this->grp_Pic1);
            this->Controls->Add(this->grp_Edit);
            this->Controls->Add(this->grp_Find);
            this->Controls->Add(this->grp_Size);
            this->Controls->Add(this->grp_Result);
            this->Name = L"MyForm";
            this->Padding = System::Windows::Forms::Padding(5);
            this->Text = L"My App";
            this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
            this->grp_Size->ResumeLayout(false);
            this->grp_Size->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->num_Size_width))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->num_Size_height))->EndInit();
            this->grp_Pic1->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pic_Pic1))->EndInit();
            this->grp_Edit->ResumeLayout(false);
            this->grp_Edit->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->num_Edit_percent))->EndInit();
            this->grp_Find->ResumeLayout(false);
            this->grp_Find->PerformLayout();
            this->grp_Result->ResumeLayout(false);
            this->grp_Result->PerformLayout();
            this->panel_Result_out->ResumeLayout(false);
            this->panel_Result_in->ResumeLayout(false);
            this->panel_Result_in->PerformLayout();
            this->ResumeLayout(false);

        }
#pragma endregion


        // TODO:********** M.init(4, 5);

        Floor^ floor;
        //Graphics^ g;

        private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e)
        {
            int rows = Int32(this->num_Size_height->Value);
            int cols = Int32(this->num_Size_width->Value);
            int offset = DEFAULT_FLOOR_OFFSET;
            floor = gcnew Floor(pic_Pic1, rows, cols, offset, offset,
                                STONE_COLOR, FREE_COLOR);

            floor->clear_pic_box();
            floor->draw_pic_box();
        }

        private: System::Void height_Click(System::Object^  sender, System::EventArgs^  e)
        {
            floor->set_matrix_invalid();
            this->but_Find_start->Enabled = false;
            floor->clear_pic_box();
            floor->set_rows(Int32(this->num_Size_height->Value));
            floor->draw_pic_box();
        }
        private: System::Void width_Click(System::Object^  sender, System::EventArgs^  e)
        {
            floor->set_matrix_invalid();
            this->but_Find_start->Enabled = false;
            floor->clear_pic_box();
            floor->set_cols(Int32(this->num_Size_width->Value));
            floor->draw_pic_box();
        }
                 //private: System::Void TextBox1_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)
                 //{
                 //    // Accept only digits and the Backspace character
                 //    if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08)
                 //        e->Handled = true;
                 //}

        private: System::Void but_MaxSize_Click(System::Object^  sender, System::EventArgs^  e)
        {
            this->num_Size_height->Value = this->num_Size_height->Maximum;
            this->num_Size_width->Value = this->num_Size_width->Maximum;
            floor->set_matrix_invalid();
            this->but_Find_start->Enabled = false;
            floor->clear_pic_box();
            floor->set_rows(Int32(this->num_Size_height->Value));
            floor->set_cols(Int32(this->num_Size_width->Value));
            floor->draw_pic_box();
        }

        private: System::Void minus10_Click(System::Object^ sender, System::EventArgs^  e)
        {
            Int32 val = Int32(this->num_Edit_percent->Value);
            if (val <= 10) {
                val = 0;
            } else {
                val = val - 10;
            }
            this->num_Edit_percent->Value = Decimal(val);
        }

        private: System::Void plus10_Click(System::Object^ sender, System::EventArgs^  e)
        {
            Int32 val = Int32(this->num_Edit_percent->Value);
            if (val >= 90) {
                val = 100;
            } else {
                val = val + 10;
            }
            this->num_Edit_percent->Value = Decimal(val);
        }

        private: System::Void but_FullEmpty_Click(System::Object^ sender, System::EventArgs^  e)
        {
            floor->set_full_matrix_free();
            this->but_Find_start->Enabled = true;
            floor->redraw_floor();
        }

        private: System::Void but_FullBlack_Click(System::Object^ sender, System::EventArgs^  e)
        {
            floor->set_full_matrix_occupied();
            this->but_Find_start->Enabled = true;
            floor->redraw_floor();
        }

        private: System::Void but_Generate_Click(System::Object^  sender, System::EventArgs^  e)
        {
            Int32 val = Int32(this->num_Edit_percent->Value);
            floor->set_matrix_random(val / 100.0);
            this->but_Find_start->Enabled = true;
            floor->redraw_floor();
        }
        private: System::Void pic1_MouseClick(System::Object^  sender,
                                              System::Windows::Forms::MouseEventArgs^  ms)
        {
            int X = ms->X;
            int Y = ms->Y;
            if (floor->is_in_floor(X, Y)) {
                floor->find_and_invert(X, Y);
            }
        }

        private: System::Void but_Find_start_change(System::Object^  sender, System::EventArgs^  e)
        {
            Button^ but_start = this->but_Find_start;
            if (but_start->Enabled) {
                but_start->Font = gcnew System::Drawing::Font(but_start->Font->Name,
                                                              but_start->Font->Size, FontStyle::Bold);
            } else {
                but_start->Font = gcnew System::Drawing::Font(but_start->Font->Name,
                                                              but_start->Font->Size, FontStyle::Regular);
            }
        }

        private: System::Void but_Start_Click(System::Object^  sender, System::EventArgs^  e)
        {
            //floor->draw_result_rect(1, 0, 2, 4, Color::ForestGreen);
            String^ rectangles_text = "";
            C_CheckMatrix::T_MaxRecVec max_rec_vec;

            max_rec_vec = floor->find_max_rectangle(Color::SkyBlue);
            rectangles_text = floor->get_str_max_rec();
            this->lab_Result_size->Text = Int32(max_rec_vec[0].size).ToString();
            this->lab_Result_rects->Text = rectangles_text;
        }

        private: System::Void but_Clear_Click(System::Object^  sender, System::EventArgs^  e)
        {
            floor->redraw_floor();
        }

        private: System::Void pic_box_Resize(System::Object^  sender, System::EventArgs^  e)
        {
            floor->init_picBox(pic_Pic1);
            floor->redraw_pic_box();
        }
    };  // of public ref class MyForm  ===============================


}  // of namespace obdelnik03wingui01
