#pragma once
#include <string>
#include <iostream>
#include <fstream> 
#include <vector>
#include <string>
#include <filesystem>
#include <list>
#include <msclr\marshal.h>
#include <msclr\marshal_cppstd.h>
#include <sstream>
#include <queue>
#include <bitset>




namespace Thread {
	using std::cout; using std::cin;
	using std::endl; using std::string;
	using std::filesystem::recursive_directory_iterator;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	using namespace System::IO;
	using namespace System::Threading;
	using namespace msclr::interop;
	using namespace System::Collections::Generic;


	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{

			InitializeComponent();
			Control::CheckForIllegalCrossThreadCalls = false;
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
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label2;


	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label4;


	protected:


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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(38, 41);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(502, 37);
			this->textBox1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(130, 29);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Đường dẫn";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(582, 41);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(97, 37);
			this->button1->TabIndex = 8;
			this->button1->Text = L"Chọn...";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(544, 500);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(135, 49);
			this->button2->TabIndex = 9;
			this->button2->Text = L"Quét";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(17, 189);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBox2->Size = System::Drawing::Size(502, 142);
			this->textBox2->TabIndex = 10;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(38, 121);
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(502, 37);
			this->textBox3->TabIndex = 11;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox3_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label2->Location = System::Drawing::Point(12, 89);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(222, 29);
			this->label2->TabIndex = 12;
			this->label2->Text = L"Tham số truyền vào";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label3->Location = System::Drawing::Point(22, 348);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(107, 29);
			this->label3->TabIndex = 14;
			this->label3->Text = L"Kết quả: ";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(17, 398);
			this->textBox4->Multiline = true;
			this->textBox4->Name = L"textBox4";
			this->textBox4->ReadOnly = true;
			this->textBox4->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBox4->Size = System::Drawing::Size(502, 155);
			this->textBox4->TabIndex = 15;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label4->Location = System::Drawing::Point(116, 348);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(26, 29);
			this->label4->TabIndex = 16;
			this->label4->Text = L"0";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(691, 561);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		FolderBrowserDialog^ dlg = gcnew FolderBrowserDialog();
		dlg->ShowDialog();
		msclr::interop::marshal_context context;
		std::string path = context.marshal_as<std::string>(dlg->SelectedPath);
		for (int i = 0; i < size(path); i++) {
			if (int(path[i]) == 92) path[i] = '/';
		}
		textBox1->Text = dlg->SelectedPath;
	}

	//-------------------------Hex_to_binary-------------------
	String^ flag_text;
	auto hex_to_binary(char data) {
		switch (toupper(data))
		{
		case ' ': return "";
		case '0': return "0000";
		case '1': return "0001";
		case '2': return "0010";
		case '3': return "0011";
		case '4': return "0100";
		case '5': return "0101";
		case '6': return "0110";
		case '7': return "0111";
		case '8': return "1000";
		case '9': return "1001";
		case 'A': return "1010";
		case 'B': return "1011";
		case 'C': return "1100";
		case 'D': return "1101";
		case 'E': return "1110";
		case 'F': return "1111";
		}

	}
	void convert(Object^ data) {
		System::String^ convert_data = cli::safe_cast<System::String^>(data);
		string flag = "";
		for each (auto it in convert_data)
		{
			flag += hex_to_binary(it);
		}
		flag_text = gcnew String(flag.c_str());
	}


	
	//-------------------------Thread--------------------------
	int n = 0;
	void scan_thread(Object^ data) {
		msclr::interop::marshal_context context3;
		System::String^ con = cli::safe_cast<System::String^>(data);
		string path = context3.marshal_as<std::string>(con);

		//--------------------Vì có thể quét file trên 50MB nên em sẽ comment đoạn đó------
		
		/*std::ifstream in_file(path, std::ifstream::ate | std::ifstream::binary);
		if (in_file.is_open()) {
			if (in_file.tellg() > 1000000) {
				System::String^ namee = gcnew String(path.c_str());
				textBox2->Text += namee + "----- File lon hon 50MB" + "\r\n";
			}
			else {*/
				msclr::interop::marshal_context context;
				textBox2->Text += con + "\r\n";
				std::string flag = context.marshal_as<std::string>(flag_text);
				ifstream in(path, ios::in | ios::binary);
				string line;
				std::string binary;
				while (getline(in, line)) {
						for (int i = 0; i < line.length(); i++) {
							bitset<8> bs4(line[i]);
							binary += bs4.to_string();
						}
						if (binary.find(flag) != string::npos) {
							System::String^ namee = gcnew String(path.c_str());
							textBox4->Text += namee + "\r\n";
							n++;
							label4->Text = "";
							label4->Text += n;
							break;
					}
				}
				in.close();
			/* }
			in_file.close();
		}
		in_file.close();*/
	}
	//------------------------------End_Thread------------------------------------

	 void Thread_click(Object^ data) {

		 auto files = System::IO::Directory::GetFiles(textBox1->Text, "*.*", SearchOption::AllDirectories);
		 try
		 {
			 for each (auto file in files)
			 {
				 System::Threading::Thread^ T = gcnew System::Threading::Thread(gcnew System::Threading::ParameterizedThreadStart(this, &MyForm::scan_thread));
				 T->IsBackground = FALSE;
				 T->Start(file);
				 T->Join();
			 }
		 }
		 catch (const std::exception&)
		 {

		 }
			
		 MessageBox::Show("Da quet xong co : " + n + " ket qua");
		 button1->Enabled = TRUE;
		 button2->Enabled = TRUE;
		 textBox1->Enabled = TRUE;
		 textBox3->Enabled = TRUE;

	 }
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		if (textBox3->Text != "") {
			flag_text = textBox3->Text;
			convert(flag_text);
			
			System::Threading::Thread^ T = gcnew System::Threading::Thread(gcnew System::Threading::ParameterizedThreadStart(this, &MyForm::Thread_click));
			T->IsBackground = true;
			T->Start();
			button1->Enabled = FALSE;
			button2->Enabled = FALSE;
			textBox1->Enabled = FALSE;
			textBox3->Enabled = FALSE;
		}
		else {
			MessageBox::Show("Can truyen tham so");
		}
		
	}

private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}

	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	
	}
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}	  	  
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	
}

};
}
