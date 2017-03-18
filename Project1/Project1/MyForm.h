#pragma once
#include<stdlib.h>
#include <fstream>
#include <msclr\marshal_cppstd.h>
#include <string>
#include <cstdio>
#include <memory>
#include <stdexcept>
#include <array>
#include "arbolb.h"
#include "nodo.h"
#include "pagina.h"
#include <time.h>

using std::endl;
using std::ifstream;
using std::string;

namespace Project1 {
	pagina root(nodo("", 0));
	arbolb principal(root);
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


	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  directory;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::RichTextBox^  richTextBox2;
	private: System::Windows::Forms::Label^  filename;

	private: System::Windows::Forms::Label^  label5;




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
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->directory = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->filename = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// richTextBox1
			// 
			this->richTextBox1->BackColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->richTextBox1->ForeColor = System::Drawing::SystemColors::Info;
			this->richTextBox1->Location = System::Drawing::Point(2, 31);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(645, 217);
			this->richTextBox1->TabIndex = 2;
			this->richTextBox1->Text = L"";
			this->richTextBox1->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::richTextBox1_KeyDown);
			// 
			// label1
			// 
			this->label1->ForeColor = System::Drawing::SystemColors::Control;
			this->label1->Location = System::Drawing::Point(12, 262);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(122, 33);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Supr: Clear Screen Enter:Input command";
			// 
			// directory
			// 
			this->directory->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->directory->Location = System::Drawing::Point(1, 8);
			this->directory->Name = L"directory";
			this->directory->Size = System::Drawing::Size(636, 20);
			this->directory->TabIndex = 4;
			// 
			// label2
			// 
			this->label2->ForeColor = System::Drawing::SystemColors::Control;
			this->label2->Location = System::Drawing::Point(165, 262);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(88, 62);
			this->label2->TabIndex = 5;
			this->label2->Text = L"F2: Display Tree  Up: ls              Down: ls-a      F1: la";
			// 
			// label3
			// 
			this->label3->ForeColor = System::Drawing::SystemColors::Control;
			this->label3->Location = System::Drawing::Point(286, 262);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(88, 62);
			this->label3->TabIndex = 6;
			this->label3->Text = L"F3: grep <term>  F4: touch <file.txt>";
			// 
			// richTextBox2
			// 
			this->richTextBox2->Location = System::Drawing::Point(12, 327);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->Size = System::Drawing::Size(625, 203);
			this->richTextBox2->TabIndex = 7;
			this->richTextBox2->Text = L"";
			this->richTextBox2->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::richTextBox2_KeyDown);
			// 
			// filename
			// 
			this->filename->ForeColor = System::Drawing::SystemColors::Control;
			this->filename->Location = System::Drawing::Point(12, 533);
			this->filename->Name = L"filename";
			this->filename->Size = System::Drawing::Size(88, 23);
			this->filename->TabIndex = 8;
			// 
			// label5
			// 
			this->label5->ForeColor = System::Drawing::SystemColors::Control;
			this->label5->Location = System::Drawing::Point(106, 533);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(88, 23);
			this->label5->TabIndex = 9;
			this->label5->Text = L"F5: Save";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->ClientSize = System::Drawing::Size(649, 578);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->filename);
			this->Controls->Add(this->richTextBox2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->directory);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->richTextBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);

		}
		string exec(const char* cmd) {
			std::array<char, 128> buffer;
			string result;
			std::shared_ptr<FILE> pipe(_popen(cmd, "r"), _pclose);
			if (!pipe) throw std::runtime_error("popen() failed!");
			while (!feof(pipe.get())) {
				if (fgets(buffer.data(), 128, pipe.get()) != NULL)
				{
					result += buffer.data();
				}
			}
			return result;
		}
#pragma endregion
	private: System::Void richTextBox1_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		if (e->KeyCode == Keys::Enter)
		{
			//cd C:\Users\Juan O'Hara\Documents\Visual Studio 2017\Projects\Project1\ & ls
			System::String^ managedString = richTextBox1->Text;
			msclr::interop::marshal_context context;
			std::string standardString = context.marshal_as<std::string>(managedString);
			const char *command = standardString.c_str();
			string com;
			if (standardString.find("rm") != std::string::npos) {
				string temp1 = "DEL /F " + standardString.erase(0, 3);
				command = temp1.c_str();
				com = exec(command);
			}else {
				com = exec(command);
			}
			string direc = exec("cd");
			System::String^ v1str = gcnew String(direc.c_str());
			directory->Text = v1str;
			System::String^ v1str1 = gcnew String(com.c_str());;
			richTextBox1->Text = v1str1;
		}
		if (e->KeyCode == Keys::Delete)//suprimir
		{
			richTextBox1->Text = "";
		}
		if (e->KeyCode == Keys::F2){
			/*System::String^ v1str = gcnew String(btree.print().c_str());;
			richTextBox1->Text = v1str;*/
			System::String^ v1str1 = gcnew String(principal.tostring().c_str());;
			richTextBox1->Text = v1str1;
		}if (e->KeyCode == Keys::Up)
		{
			string com = exec("dir /b /a-h");
			System::String^ v1str1 = gcnew String(com.c_str());;
			richTextBox1->Text = v1str1;
		}
		if (e->KeyCode == Keys::Down)
		{
			string com = exec("dir /b /a");
			System::String^ v1str1 = gcnew String(com.c_str());;
			richTextBox1->Text = v1str1;
		}
		if (e->KeyCode == Keys::F1)
		{
			string 	com = exec("dir /a /q /T:C");
			System::String^ v1str1 = gcnew String(com.c_str());;
			richTextBox1->Text = v1str1;
		}
		if (e->KeyCode == Keys::F3)
		{
			System::String^ managedString = richTextBox1->Text;
			msclr::interop::marshal_context context;
			string standardString = context.marshal_as<string>(managedString);
			string com = "findstr /s /i ";
			com.append(standardString.c_str());
			com.append(" *.txt*");
			string res = exec(com.c_str());
			System::String^ v1str1 = gcnew String(res.c_str());;
			richTextBox1->Text = v1str1;
		}
		if (e->KeyCode == Keys::F4){
			//echo.   nuevo texto>> hola.txt
			//echo.   > hola.txt 
			System::String^ managedString = richTextBox1->Text;
			msclr::interop::marshal_context context;
			string standardString = context.marshal_as<string>(managedString);
			ifstream infile;
			infile.open(standardString);
			System::String^ name = gcnew String(standardString.c_str());
			filename->Text = name;
			if (infile.is_open()) {
				string content((std::istreambuf_iterator<char>(infile)),
					(std::istreambuf_iterator<char>()));
				System::String^ v1str1 = gcnew String(content.c_str());
				richTextBox2->Text = v1str1;
				infile.close();
			}
			else {
				string comm = "echo.> ";
				comm.append(standardString);
				exec(comm.c_str());
			}
			time_t seconds;
			seconds = time(NULL);
			string currPat = exec("cd");
			pagina nueva(nodo(currPat, seconds));
			principal.agregar(nueva,true);
		}
	}
	private: System::Void richTextBox2_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		if (e->KeyCode == Keys::F5) {
			//echo.   nuevo texto>> hola.txt
			//echo.   > hola.txt 
			System::String^ managedString = richTextBox2->Text;
			msclr::interop::marshal_context context;
			string standardString = context.marshal_as<string>(managedString);
			string output = "echo.";
			output.append(standardString.c_str());
			output.append("> ");
			System::String^ namefi = filename->Text;
			msclr::interop::marshal_context context2;
			string names = context2.marshal_as<string>(namefi);
			output.append(names);
			exec(output.c_str());
			richTextBox2->Text = "";
		}
	}
};
}
