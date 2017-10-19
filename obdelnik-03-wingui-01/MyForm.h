#pragma once

#include "C_Matrix.h"

#define DEFAULT_FLOOR_OFFSET 10
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
            Graphics^ g;             // A Graphics handle; = Graphics::FromImage(pictureBox1->Image);
            PictureBox^ picBox;      // 
            int pic_box_h, pic_box_w;  // size of picBox

            C_Matrix^ M = gcnew C_Matrix();

            public:
            Floor(PictureBox^ picBox_, int rows_, int cols_, int off_x, int off_y,
                  Color stone_color_, Color free_color_)
            {
                picBox = picBox_;
                cols = cols_;
                rows = rows_;
                size_sq = SMALL_RECT_SIZE;
                h = calc_line_length(rows);
                w = calc_line_length(cols);
                offset_x = off_x;
                offset_y = off_y;
                pic_box_w = picBox->Width;
                pic_box_h = picBox->Height;
                stone_color = stone_color_;
                free_color = free_color_;
                //	Prepare an image component and a Graphics handle.
                picBox->Image = gcnew Bitmap(pic_box_w, pic_box_h);
                g = Graphics::FromImage(picBox->Image);
            }

            ~Floor()
            {
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
                                if (M->get_1(i, j)) { // free
                                    draw_small_rect(i, j, free_color);
                                } else {            // stone
                                    draw_small_rect(i, j, stone_color);
                                }
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

        private: System::Windows::Forms::PictureBox^  pictureBox1;

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
            this->lab_Size_height = (gcnew System::Windows::Forms::Label());
            this->lab_Size_width = (gcnew System::Windows::Forms::Label());
            this->grp_Size = (gcnew System::Windows::Forms::GroupBox());
            this->ckbox_Size_lockRatio = (gcnew System::Windows::Forms::CheckBox());
            this->lab_Size_x = (gcnew System::Windows::Forms::Label());
            this->num_Size_width = (gcnew System::Windows::Forms::NumericUpDown());
            this->num_Size_height = (gcnew System::Windows::Forms::NumericUpDown());
            this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
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
            this->grp_Size->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->num_Size_width))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->num_Size_height))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
            this->grp_Edit->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->num_Edit_percent))->BeginInit();
            this->SuspendLayout();
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
            // grp_Size
            // 
            this->grp_Size->Controls->Add(this->ckbox_Size_lockRatio);
            this->grp_Size->Controls->Add(this->lab_Size_x);
            this->grp_Size->Controls->Add(this->num_Size_width);
            this->grp_Size->Controls->Add(this->num_Size_height);
            this->grp_Size->Controls->Add(this->lab_Size_height);
            this->grp_Size->Controls->Add(this->lab_Size_width);
            this->grp_Size->Location = System::Drawing::Point(12, 12);
            this->grp_Size->Name = L"grp_Size";
            this->grp_Size->Size = System::Drawing::Size(282, 70);
            this->grp_Size->TabIndex = 2;
            this->grp_Size->TabStop = false;
            this->grp_Size->Text = L"Size";
            // 
            // ckbox_Size_lockRatio
            // 
            this->ckbox_Size_lockRatio->AutoSize = true;
            this->ckbox_Size_lockRatio->Location = System::Drawing::Point(189, 40);
            this->ckbox_Size_lockRatio->Name = L"ckbox_Size_lockRatio";
            this->ckbox_Size_lockRatio->Size = System::Drawing::Size(69, 17);
            this->ckbox_Size_lockRatio->TabIndex = 6;
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
            this->num_Size_width->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 26, 0, 0, 0 });
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
            this->num_Size_height->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 14, 0, 0, 0 });
            this->num_Size_height->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
            this->num_Size_height->Name = L"num_Size_height";
            this->num_Size_height->Size = System::Drawing::Size(68, 20);
            this->num_Size_height->TabIndex = 2;
            this->num_Size_height->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            this->num_Size_height->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
            this->num_Size_height->ValueChanged += gcnew System::EventHandler(this, &MyForm::height_Click);
            // 
            // pictureBox1
            // 
            this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
            this->pictureBox1->Location = System::Drawing::Point(12, 97);
            this->pictureBox1->Name = L"pictureBox1";
            this->pictureBox1->Size = System::Drawing::Size(285, 165);
            this->pictureBox1->TabIndex = 4;
            this->pictureBox1->TabStop = false;
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
            this->grp_Edit->Location = System::Drawing::Point(12, 274);
            this->grp_Edit->Name = L"grp_Edit";
            this->grp_Edit->Size = System::Drawing::Size(285, 134);
            this->grp_Edit->TabIndex = 5;
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
            this->but_Edit_generate->TabIndex = 9;
            this->but_Edit_generate->Text = L"Generate";
            this->but_Edit_generate->UseVisualStyleBackColor = true;
            this->but_Edit_generate->Click += gcnew System::EventHandler(this, &MyForm::but_Generate_Click);
            // 
            // but_Edit_minus10
            // 
            this->but_Edit_minus10->Location = System::Drawing::Point(63, 49);
            this->but_Edit_minus10->Name = L"but_Edit_minus10";
            this->but_Edit_minus10->Size = System::Drawing::Size(33, 23);
            this->but_Edit_minus10->TabIndex = 8;
            this->but_Edit_minus10->Text = L"-10";
            this->but_Edit_minus10->UseVisualStyleBackColor = true;
            this->but_Edit_minus10->Click += gcnew System::EventHandler(this, &MyForm::minus10_Click);
            // 
            // num_Edit_percent
            // 
            this->num_Edit_percent->Location = System::Drawing::Point(102, 52);
            this->num_Edit_percent->Name = L"num_Edit_percent";
            this->num_Edit_percent->Size = System::Drawing::Size(42, 20);
            this->num_Edit_percent->TabIndex = 7;
            this->num_Edit_percent->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            this->num_Edit_percent->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
            // 
            // but_Edit_plus10
            // 
            this->but_Edit_plus10->Location = System::Drawing::Point(166, 49);
            this->but_Edit_plus10->Name = L"but_Edit_plus10";
            this->but_Edit_plus10->Size = System::Drawing::Size(33, 23);
            this->but_Edit_plus10->TabIndex = 6;
            this->but_Edit_plus10->Text = L"+10";
            this->but_Edit_plus10->UseVisualStyleBackColor = true;
            this->but_Edit_plus10->Click += gcnew System::EventHandler(this, &MyForm::plus10_Click);
            // 
            // but_Edit_fullFill
            // 
            this->but_Edit_fullFill->Location = System::Drawing::Point(147, 19);
            this->but_Edit_fullFill->Name = L"but_Edit_fullFill";
            this->but_Edit_fullFill->Size = System::Drawing::Size(82, 23);
            this->but_Edit_fullFill->TabIndex = 4;
            this->but_Edit_fullFill->Text = L"Full Occupied";
            this->but_Edit_fullFill->UseVisualStyleBackColor = true;
            this->but_Edit_fullFill->Click += gcnew System::EventHandler(this, &MyForm::but_FullBlack_Click);
            // 
            // but_Edit_fullFree
            // 
            this->but_Edit_fullFree->Location = System::Drawing::Point(63, 20);
            this->but_Edit_fullFree->Name = L"but_Edit_fullFree";
            this->but_Edit_fullFree->Size = System::Drawing::Size(75, 23);
            this->but_Edit_fullFree->TabIndex = 3;
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
            this->lab_Edit_random->TabIndex = 2;
            this->lab_Edit_random->Text = L"Random:";
            // 
            // lab_Edit_manually
            // 
            this->lab_Edit_manually->AutoSize = true;
            this->lab_Edit_manually->Location = System::Drawing::Point(6, 25);
            this->lab_Edit_manually->Name = L"lab_Edit_manually";
            this->lab_Edit_manually->Size = System::Drawing::Size(52, 13);
            this->lab_Edit_manually->TabIndex = 1;
            this->lab_Edit_manually->Text = L"Manually:";
            // 
            // MyForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(306, 521);
            this->Controls->Add(this->grp_Edit);
            this->Controls->Add(this->pictureBox1);
            this->Controls->Add(this->grp_Size);
            this->Name = L"MyForm";
            this->Text = L"My App";
            this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
            this->grp_Size->ResumeLayout(false);
            this->grp_Size->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->num_Size_width))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->num_Size_height))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
            this->grp_Edit->ResumeLayout(false);
            this->grp_Edit->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->num_Edit_percent))->EndInit();
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
            floor = gcnew Floor(pictureBox1, rows, cols, offset, offset,
                                STONE_COLOR, FREE_COLOR);

            floor->clear_pic_box();
            floor->draw_floor();
        }

        private: System::Void height_Click(System::Object^  sender, System::EventArgs^  e)
        {
            floor->set_matrix_invalid();
            floor->clear_floor();
            floor->set_rows(Int32(this->num_Size_height->Value));
            floor->draw_floor();
        }
        private: System::Void width_Click(System::Object^  sender, System::EventArgs^  e)
        {
            floor->set_matrix_invalid();
            floor->clear_floor();
            floor->set_cols(Int32(this->num_Size_width->Value));
            floor->draw_floor();
        }
                 //private: System::Void TextBox1_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)
                 //{
                 //    // Accept only digits and the Backspace character
                 //    if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08)
                 //        e->Handled = true;
                 //}

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
            floor->redraw_floor();
        }

        private: System::Void but_FullBlack_Click(System::Object^ sender, System::EventArgs^  e)
        {
            floor->set_full_matrix_occupied();
            floor->redraw_floor();
        }

        private: System::Void but_Generate_Click(System::Object^  sender, System::EventArgs^  e)
        {
            Int32 val = Int32(this->num_Edit_percent->Value); 
            floor->set_matrix_random(val/100.0);
            floor->redraw_floor();
        }
};  // of public ref class MyForm  ===============================


}  // of namespace obdelnik03wingui01
