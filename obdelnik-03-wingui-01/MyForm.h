#pragma once

#include "C_Matrix.h"

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
            this->lab_Size_height->Size = System::Drawing::Size(42, 13);
            this->lab_Size_height->TabIndex = 0;
            this->lab_Size_height->Text = L"height";
            // 
            // lab_Size_width
            // 
            this->lab_Size_width->AutoSize = true;
            this->lab_Size_width->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                                                                      static_cast<System::Byte>(238)));
            this->lab_Size_width->Location = System::Drawing::Point(111, 21);
            this->lab_Size_width->Name = L"lab_Size_width";
            this->lab_Size_width->Size = System::Drawing::Size(37, 13);
            this->lab_Size_width->TabIndex = 1;
            this->lab_Size_width->Text = L"width";
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
            this->num_Size_width->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 28, 0, 0, 0 });
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
            this->num_Size_height->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 15, 0, 0, 0 });
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
            this->pictureBox1->Size = System::Drawing::Size(285, 155);
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

        Int32 SMALL_RECT_SIZE = 10;


        // TODO:********** M.init(4, 5);

        int rows, cols;        //  # of rows and cols from "height" and "width"
        int pic1h, pic1w;		//	Height and width of pictureBox1
        Graphics^ g;			//		A Graphics handle

        //C_Matrix^ M = gcnew C_Matrix;
        C_Matrix* M = new C_Matrix;

        private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e)
        {

            rows = Int32(this->num_Size_height->Value);
            cols = Int32(this->num_Size_width->Value);
            pic1w = pictureBox1->Width;
            pic1h = pictureBox1->Height;
            //	Prepare an image component and a Graphics handle.
            pictureBox1->Image = gcnew Bitmap(pic1w, pic1h);
            g = Graphics::FromImage(pictureBox1->Image);

            //Color color = panel->BackColor;
            Color color = pictureBox1->BackColor;
            //Color color = Color::White;
            clear_pic();
            rect_draw();
        }

        private: System::Void draw_w_line(Pen^ pen, Point loc, Int32 length)
        {
            Int32 x, y;
            x = loc.X;
            y = loc.Y;
            g->DrawLine(pen, loc, Point(x + length - 1, y));
        }

        private: System::Void draw_h_line(Pen^ pen, Point loc, Int32 length)
        {
            Int32 x, y;
            x = loc.X;
            y = loc.Y;
            g->DrawLine(pen, loc, Point(x, y + length));
        }

                 // draw small rectangle on position [row,col] in matrix
        private: System::Void draw_small_rect(int row, int col, Color color)
        {
            pictureBox1->Image = pictureBox1->Image;  // needed per tutor

            int x = row*SMALL_RECT_SIZE + 1;
            int y = col*SMALL_RECT_SIZE + 1;
            int size = SMALL_RECT_SIZE - 1;
            SolidBrush^ myBrush = gcnew SolidBrush(color);

            g->FillRectangle(myBrush, x, y, size, size);
            //g->FillRectangle(myBrush, rect);
            delete myBrush;
        }


        private: System::Void rect_draw()
        {
            Int32 rows, cols;

            //drawRect2(e, Pens::White, Point(0, 0), Int32(SMALL_RECT_SIZE - 1));
            //drawRect(panel, Pens::White, Point(0, 0), Int32(SMALL_RECT_SIZE - 1));

            rows = Int32(this->num_Size_height->Value);  // height
            cols = Int32(this->num_Size_width->Value);  // width

            Int32 h = rows*SMALL_RECT_SIZE;
            Int32 w = cols*SMALL_RECT_SIZE;

            for (Int32 i = 0; i <= cols; i++) {
                draw_h_line(Pens::Black, Point(i*SMALL_RECT_SIZE, 0), Int32(h));
            }
            for (Int32 i = 0; i <= rows; i++) {
                draw_w_line(Pens::Black, Point(0, i*SMALL_RECT_SIZE), Int32(w));
            }

        }

        private: System::Void rect_redraw()
        {
            clear_pic();
            rect_draw();
        }

        private: void clear_pic()
        {
            pictureBox1->Image = pictureBox1->Image;  // needed per tutor

            Color color = pictureBox1->BackColor;
            Rectangle rect = pictureBox1->Bounds;
            rect.Location = Point(0, 0);
            SolidBrush^ myBrush = gcnew SolidBrush(color);

            //g->FillRectangle(myBrush, 0, 0, pic1w, pic1h);
            g->FillRectangle(myBrush, rect);

            delete myBrush;
        }

        private: void init_pic(Color color)
        {
            //pictureBox1->Image = pictureBox1->Image;  // needed per tutor

            rows = Int32(this->num_Size_height->Value);
            cols = Int32(this->num_Size_width->Value);


            Rectangle rect = pictureBox1->Bounds;
            rect.Location = Point(0, 0);
            SolidBrush^ myBrush = gcnew SolidBrush(color);

            //g->FillRectangle(myBrush, 0, 0, pic1w, pic1h);
            g->FillRectangle(myBrush, rect);

            delete myBrush;
        }



        private: System::Void height_Click(System::Object^  sender, System::EventArgs^  e)
        {
            rect_redraw();
        }
        private: System::Void width_Click(System::Object^  sender, System::EventArgs^  e)
        {
            rect_redraw();

        }
                 //private: System::Void TextBox1_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)
                 //{
                 //    // Accept only digits and the Backspace character
                 //    if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08)
                 //        e->Handled = true;
                 //}

        private: System::Void minus10_Click(System::Object^  sender, System::EventArgs^  e)
        {
            Int32 val = Int32(this->num_Edit_percent->Value);
            if (val <= 10) {
                val = 0;
            } else {
                val = val - 10;
            }
            this->num_Edit_percent->Value = Decimal(val);
        }

        private: System::Void plus10_Click(System::Object^  sender, System::EventArgs^  e)
        {
            Int32 val = Int32(this->num_Edit_percent->Value);
            if (val >= 90) {
                val = 100;
            } else {
                val = val + 10;
            }
            this->num_Edit_percent->Value = Decimal(val);
        }

        private: System::Void but_FullEmpty_Click(System::Object^  sender, System::EventArgs^  e)
        {
            Int32 rows, cols;

            rows = Int32(this->num_Size_height->Value);  // height
            cols = Int32(this->num_Size_width->Value);   // width

            draw_small_rect(2, 1, Color::White);


            //drawRect2(e, Pens::White, Point(0, 0), Int32(SMALL_RECT_SIZE - 1));
            //drawRect(panel, Pens::White, Point(0, 0), Int32(SMALL_RECT_SIZE - 1));

        }

        private: System::Void but_FullBlack_Click(System::Object^  sender, System::EventArgs^  e)
        {
            draw_small_rect(2, 1, Color::White);

        }

    };



}
