#pragma once

#include <cliext/vector>

namespace BD {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace cliext;

	using namespace System::Data::SQLite;
	using namespace System::Text;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	public: 

	SQLiteConnection ^db;

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
			db->Close();
		}

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	protected: 

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;


	//Заполнение таблицы из БД
	private: DataTable^ fillDataTable() {
	DataTable ^table;
	try
	{
		SQLiteCommand ^cmdSelect = db->CreateCommand();
		cmdSelect->CommandText = "SELECT * FROM emp;";
		SQLiteDataReader ^reader = cmdSelect->ExecuteReader();
		
		//Переменные таблицы
		DataColumn ^column; //Столбец
		DataRow ^row; //Строка
 
		//Создаем таблицу данных
		table = gcnew DataTable();
		
 
		//Вектор названий столбцов
		vector<String^>^ nameColumns = gcnew vector<String^>();
		//Заполним данные о столбцах
		for (int i = 0; i < reader->FieldCount; i++) {
			nameColumns->push_back(reader->GetName(i));
			column = gcnew DataColumn(nameColumns->at(i), String::typeid);
			table->Columns->Add(column);
		}
 
		//Пробегаем по каждой записи
		while (reader->Read()) {
			row = table->NewRow();
			for (int i = 0; i < reader->FieldCount; i++) {
				row[nameColumns->at(i)] = reader->GetValue(i)->ToString();
				reader->GetValue(i)->ToString();
			}
			table->Rows->Add(row);
		}
	}
	catch (Exception ^e)
	{
		MessageBox::Show("Error Executing SQL: " + e->ToString(), "Exception While Displaying MyTable ...");
	}
	return table;
}

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Roboto", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(35, 37);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(257, 23);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Стирание БД (Цапаев Егор)";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(365, 192);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(106, 31);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Стереть";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(365, 254);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(109, 81);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Стереть всю таблицу";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->Filter = L"Файлы БД (^.db)|*.db";
			this->openFileDialog1->Title = L"test.db";
			this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &MyForm::openFileDialog1_FileOk);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(382, 101);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 4;
			this->button3->Text = L"Открыть";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(39, 101);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(303, 234);
			this->dataGridView1->TabIndex = 5;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(36, 69);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(0, 13);
			this->label2->TabIndex = 6;
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(7, 69);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(477, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Кнопкой \"Открыть\" можно подключить файл с бд \"table.db\", которая прилагается к пр" 
				L"оекту";
			this->label3->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(496, 414);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void openFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
			 }
	

	//Кнопка открытия БД
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			String^ fileName = openFileDialog1->FileName;
	

			//Установка соединения с БД
			db = gcnew SQLiteConnection();
			try
			{
				db->ConnectionString = "Data Source=\"" + fileName + "\"";
				db->Open();
 
				DataTable ^table = fillDataTable();
 
				dataGridView1->DataSource = table;
			}
			catch (Exception ^e)
			{
				MessageBox::Show("Error Working SQL: " + e->ToString(), "Exception ...");
			}
		}
    
	}
	


	// Кнопка удаления выделенной записи таблицы
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		//Номер выделенной строки
		int index = dataGridView1->CurrentCell->RowIndex; 
		//Определим _id в выделенной строке
		String^ id = dataGridView1->Rows[index]->Cells[0]->Value->ToString();
 
		try
		{
			SQLiteCommand ^cmdInsertValue = db->CreateCommand();
			cmdInsertValue->CommandText = "DELETE FROM emp WHERE "+ dataGridView1->Columns[0]->HeaderText+ " = " + id+ ";";
			cmdInsertValue->ExecuteNonQuery();
 
			DataTable ^table = fillDataTable();
 
			dataGridView1->DataSource = table;
		}
		catch (Exception ^e)
		{
			MessageBox::Show("Error Executing SQL: " + e->ToString(), "Exception ...");
		}
			 
	}



	// Кнопка удаления всех записей таблицы
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		try
		{
			SQLiteCommand ^cmdInsertValue = db->CreateCommand();
			cmdInsertValue->CommandText = "DELETE FROM emp;";
			cmdInsertValue->ExecuteNonQuery();

			//Метод переотображения таблицы в форме
			DataTable ^table = fillDataTable();
 
			dataGridView1->DataSource = table;
		}
		catch (Exception ^e)
		{
			MessageBox::Show("Error Executing SQL: " + e->ToString(), "Exception ...");
		}

	}
private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}