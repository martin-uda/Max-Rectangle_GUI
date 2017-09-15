#pragma once

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
        private: System::Windows::Forms::Label^  label1;
        protected:
        private: System::Windows::Forms::Label^  label2;
        private: System::Windows::Forms::GroupBox^  groupBox1;
        private: System::Windows::Forms::NumericUpDown^  numericUpDown2;
        private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
        private: System::Windows::Forms::CheckBox^  checkBox1;
        private: System::Windows::Forms::Label^  label4;



        private: System::Windows::Forms::PictureBox^  pictureBox1;
        private: System::Windows::Forms::Label^  label3;
        private: System::Windows::Forms::GroupBox^  groupBox2;
        private: System::Windows::Forms::Label^  label5;

        private: System::Windows::Forms::NumericUpDown^  numericUpDown3;
        private: System::Windows::Forms::Button^  button4;

        private: System::Windows::Forms::Button^  button2;
        private: System::Windows::Forms::Button^  button1;
        private: System::Windows::Forms::Label^  label6;
        private: System::Windows::Forms::Label^  label7;
        private: System::Windows::Forms::Button^  button5;
        private: System::Windows::Forms::Button^  button3;


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
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
            this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
            this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
            this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
            this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
            this->label7 = (gcnew System::Windows::Forms::Label());
            this->button5 = (gcnew System::Windows::Forms::Button());
            this->button3 = (gcnew System::Windows::Forms::Button());
            this->numericUpDown3 = (gcnew System::Windows::Forms::NumericUpDown());
            this->button4 = (gcnew System::Windows::Forms::Button());
            this->button2 = (gcnew System::Windows::Forms::Button());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->label6 = (gcnew System::Windows::Forms::Label());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->groupBox1->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
            this->groupBox2->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->BeginInit();
            this->SuspendLayout();
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                                                              static_cast<System::Byte>(238)));
            this->label1->Location = System::Drawing::Point(21, 21);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(42, 13);
            this->label1->TabIndex = 0;
            this->label1->Text = L"height";
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                                                              static_cast<System::Byte>(238)));
            this->label2->Location = System::Drawing::Point(111, 21);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(37, 13);
            this->label2->TabIndex = 1;
            this->label2->Text = L"width";
            // 
            // groupBox1
            // 
            this->groupBox1->Controls->Add(this->checkBox1);
            this->groupBox1->Controls->Add(this->label3);
            this->groupBox1->Controls->Add(this->label4);
            this->groupBox1->Controls->Add(this->numericUpDown2);
            this->groupBox1->Controls->Add(this->numericUpDown1);
            this->groupBox1->Controls->Add(this->label1);
            this->groupBox1->Controls->Add(this->label2);
            this->groupBox1->Location = System::Drawing::Point(12, 12);
            this->groupBox1->Name = L"groupBox1";
            this->groupBox1->Size = System::Drawing::Size(282, 70);
            this->groupBox1->TabIndex = 2;
            this->groupBox1->TabStop = false;
            this->groupBox1->Text = L"Size";
            // 
            // checkBox1
            // 
            this->checkBox1->AutoSize = true;
            this->checkBox1->Location = System::Drawing::Point(189, 40);
            this->checkBox1->Name = L"checkBox1";
            this->checkBox1->Size = System::Drawing::Size(69, 17);
            this->checkBox1->TabIndex = 6;
            this->checkBox1->Text = L"lock ratio";
            this->checkBox1->UseVisualStyleBackColor = true;
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Location = System::Drawing::Point(186, 21);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(35, 13);
            this->label3->TabIndex = 0;
            this->label3->Text = L"label3";
            this->label3->Visible = false;
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->Location = System::Drawing::Point(84, 39);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(12, 13);
            this->label4->TabIndex = 5;
            this->label4->Text = L"x";
            // 
            // numericUpDown2
            // 
            this->numericUpDown2->Location = System::Drawing::Point(102, 37);
            this->numericUpDown2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 28, 0, 0, 0 });
            this->numericUpDown2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
            this->numericUpDown2->Name = L"numericUpDown2";
            this->numericUpDown2->Size = System::Drawing::Size(71, 20);
            this->numericUpDown2->TabIndex = 3;
            this->numericUpDown2->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            this->numericUpDown2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 15, 0, 0, 0 });
            this->numericUpDown2->ValueChanged += gcnew System::EventHandler(this, &MyForm::width_Click);
            // 
            // numericUpDown1
            // 
            this->numericUpDown1->Location = System::Drawing::Point(10, 37);
            this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 15, 0, 0, 0 });
            this->numericUpDown1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
            this->numericUpDown1->Name = L"numericUpDown1";
            this->numericUpDown1->Size = System::Drawing::Size(68, 20);
            this->numericUpDown1->TabIndex = 2;
            this->numericUpDown1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
            this->numericUpDown1->ValueChanged += gcnew System::EventHandler(this, &MyForm::height_Click);
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
            // groupBox2
            // 
            this->groupBox2->Controls->Add(this->label7);
            this->groupBox2->Controls->Add(this->button5);
            this->groupBox2->Controls->Add(this->button3);
            this->groupBox2->Controls->Add(this->numericUpDown3);
            this->groupBox2->Controls->Add(this->button4);
            this->groupBox2->Controls->Add(this->button2);
            this->groupBox2->Controls->Add(this->button1);
            this->groupBox2->Controls->Add(this->label6);
            this->groupBox2->Controls->Add(this->label5);
            this->groupBox2->Location = System::Drawing::Point(12, 274);
            this->groupBox2->Name = L"groupBox2";
            this->groupBox2->Size = System::Drawing::Size(285, 134);
            this->groupBox2->TabIndex = 5;
            this->groupBox2->TabStop = false;
            this->groupBox2->Text = L"Edit";
            // 
            // label7
            // 
            this->label7->AutoSize = true;
            this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                                                              static_cast<System::Byte>(238)));
            this->label7->Location = System::Drawing::Point(144, 54);
            this->label7->Name = L"label7";
            this->label7->Size = System::Drawing::Size(16, 13);
            this->label7->TabIndex = 10;
            this->label7->Text = L"%";
            // 
            // button5
            // 
            this->button5->Location = System::Drawing::Point(215, 49);
            this->button5->Name = L"button5";
            this->button5->Size = System::Drawing::Size(61, 23);
            this->button5->TabIndex = 9;
            this->button5->Text = L"Generate";
            this->button5->UseVisualStyleBackColor = true;
            // 
            // button3
            // 
            this->button3->Location = System::Drawing::Point(63, 49);
            this->button3->Name = L"button3";
            this->button3->Size = System::Drawing::Size(33, 23);
            this->button3->TabIndex = 8;
            this->button3->Text = L"-10";
            this->button3->UseVisualStyleBackColor = true;
            this->button3->Click += gcnew System::EventHandler(this, &MyForm::minus10_Click);
            // 
            // numericUpDown3
            // 
            this->numericUpDown3->Location = System::Drawing::Point(102, 52);
            this->numericUpDown3->Name = L"numericUpDown3";
            this->numericUpDown3->Size = System::Drawing::Size(42, 20);
            this->numericUpDown3->TabIndex = 7;
            this->numericUpDown3->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            this->numericUpDown3->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
            // 
            // button4
            // 
            this->button4->Location = System::Drawing::Point(166, 49);
            this->button4->Name = L"button4";
            this->button4->Size = System::Drawing::Size(33, 23);
            this->button4->TabIndex = 6;
            this->button4->Text = L"+10";
            this->button4->UseVisualStyleBackColor = true;
            this->button4->Click += gcnew System::EventHandler(this, &MyForm::plus10_Click);
            // 
            // button2
            // 
            this->button2->Location = System::Drawing::Point(147, 19);
            this->button2->Name = L"button2";
            this->button2->Size = System::Drawing::Size(75, 23);
            this->button2->TabIndex = 4;
            this->button2->Text = L"Black";
            this->button2->UseVisualStyleBackColor = true;
            this->button2->Click += gcnew System::EventHandler(this, &MyForm::but_FullBlack_Click);
            // 
            // button1
            // 
            this->button1->Location = System::Drawing::Point(63, 20);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(75, 23);
            this->button1->TabIndex = 3;
            this->button1->Text = L"White";
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this, &MyForm::but_FullWhite_Click);
            // 
            // label6
            // 
            this->label6->AutoSize = true;
            this->label6->Location = System::Drawing::Point(9, 54);
            this->label6->Name = L"label6";
            this->label6->Size = System::Drawing::Size(50, 13);
            this->label6->TabIndex = 2;
            this->label6->Text = L"Random:";
            // 
            // label5
            // 
            this->label5->AutoSize = true;
            this->label5->Location = System::Drawing::Point(6, 25);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(52, 13);
            this->label5->TabIndex = 1;
            this->label5->Text = L"Manually:";
            // 
            // MyForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(306, 521);
            this->Controls->Add(this->groupBox2);
            this->Controls->Add(this->pictureBox1);
            this->Controls->Add(this->groupBox1);
            this->Name = L"MyForm";
            this->Text = L"My App";
            this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
            this->groupBox1->ResumeLayout(false);
            this->groupBox1->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
            this->groupBox2->ResumeLayout(false);
            this->groupBox2->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->EndInit();
            this->ResumeLayout(false);

        }
#pragma endregion

        Int32 MYSIZE = 10;

        int rows, cols;        //  # of rows and cols from "height" and "width"
        int pic1h, pic1w;		//	Height and width of pictureBox1
        Graphics^ g;			//		A Graphics handle

        private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e)
        {

            rows = Int32(this->numericUpDown1->Value);
            cols = Int32(this->numericUpDown2->Value);
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

        private: System::Void draw_line_W(Pen^ pen, Point loc, Int32 length)
        {
            Int32 x, y;
            x = loc.X;
            y = loc.Y;
            g->DrawLine(pen, loc, Point(x + length - 1, y));
        }

        private: System::Void draw_line_H(Pen^ pen, Point loc, Int32 length)
        {
            Int32 x, y;
            x = loc.X;
            y = loc.Y;
            g->DrawLine(pen, loc, Point(x, y + length));
        }

        private: System::Void rect_draw()
        {
            Int32 rows, cols;

            //drawRect2(e, Pens::White, Point(0, 0), Int32(MYSIZE - 1));
            //drawRect(panel, Pens::White, Point(0, 0), Int32(MYSIZE - 1));

            rows = Int32(this->numericUpDown1->Value);  // height
            cols = Int32(this->numericUpDown2->Value);  // width

            Int32 h = rows*MYSIZE;
            Int32 w = cols*MYSIZE;

            for (Int32 i = 0; i <= cols; i++) {
                draw_line_H(Pens::Black, Point(i*MYSIZE, 0), Int32(h));
            }
            for (Int32 i = 0; i <= rows; i++) {
                draw_line_W(Pens::Black, Point(0, i*MYSIZE), Int32(w));
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

            rows = Int32(this->numericUpDown1->Value);
            cols = Int32(this->numericUpDown2->Value);


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
            Int32 val = Int32(this->numericUpDown3->Value);
            if (val <= 10) {
                val = 0;
            } else {
                val = val - 10;
            }
            this->numericUpDown3->Value = Decimal(val);
        }

        private: System::Void plus10_Click(System::Object^  sender, System::EventArgs^  e)
        {
            Int32 val = Int32(this->numericUpDown3->Value);
            if (val >= 90) {
                val = 100;
            } else {
                val = val + 10;
            }
            this->numericUpDown3->Value = Decimal(val);
        }

        private: System::Void but_FullWhite_Click(System::Object^  sender, System::EventArgs^  e)
        {
            Int32 rows, cols;

            rows = Int32(this->numericUpDown1->Value);  // height
            cols = Int32(this->numericUpDown2->Value);  // width


            ;

            //drawRect2(e, Pens::White, Point(0, 0), Int32(MYSIZE - 1));
            //drawRect(panel, Pens::White, Point(0, 0), Int32(MYSIZE - 1));

        }

        private: System::Void but_FullBlack_Click(System::Object^  sender, System::EventArgs^  e)
        {
        }
    };
}
