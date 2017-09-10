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
			if (components)
			{
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

        private: System::Windows::Forms::Panel^  panel1;
        private: System::Windows::Forms::Button^  button1;


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
            this->panel1 = (gcnew System::Windows::Forms::Panel());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->groupBox1->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
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
            // 
            // panel1
            // 
            this->panel1->Location = System::Drawing::Point(12, 97);
            this->panel1->Name = L"panel1";
            this->panel1->Size = System::Drawing::Size(281, 151);
            this->panel1->TabIndex = 3;
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
            // MyForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(306, 420);
            this->Controls->Add(this->button1);
            this->Controls->Add(this->panel1);
            this->Controls->Add(this->groupBox1);
            this->Name = L"MyForm";
            this->Text = L"My App";
            this->groupBox1->ResumeLayout(false);
            this->groupBox1->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
            this->ResumeLayout(false);

        }
#pragma endregion
        private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e)
        {
        }
};
}
