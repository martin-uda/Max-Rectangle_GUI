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


        private: System::Windows::Forms::Button^  button1;
        private: System::Windows::Forms::PictureBox^  pictureBox1;


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
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
            this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
            this->groupBox1->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
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
            this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
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
            // button1
            // 
            this->button1->BackColor = System::Drawing::SystemColors::Window;
            this->button1->Location = System::Drawing::Point(36, 304);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(75, 23);
            this->button1->TabIndex = 1;
            this->button1->Text = L"button1";
            this->button1->UseVisualStyleBackColor = false;
            // 
            // pictureBox1
            // 
            this->pictureBox1->Location = System::Drawing::Point(12, 97);
            this->pictureBox1->Name = L"pictureBox1";
            this->pictureBox1->Size = System::Drawing::Size(281, 151);
            this->pictureBox1->TabIndex = 4;
            this->pictureBox1->TabStop = false;
            // 
            // MyForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(306, 420);
            this->Controls->Add(this->pictureBox1);
            this->Controls->Add(this->button1);
            this->Controls->Add(this->groupBox1);
            this->Name = L"MyForm";
            this->Text = L"My App";
            this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
            this->groupBox1->ResumeLayout(false);
            this->groupBox1->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
            this->ResumeLayout(false);

        }
#pragma endregion
        private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e)
        {
            //clearPic();
        }
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
    };
}
