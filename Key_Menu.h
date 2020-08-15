#pragma once
#include "food.h"

namespace Mycafe {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Key_Menu
	/// </summary>
	public ref class Key_Menu : public System::Windows::Forms::Form
	{
	public:
		Key_Menu(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			list = gcnew food();
			p = gcnew dish();
			list_order = gcnew food();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Key_Menu()
		{
			if (components)
			{
				delete components;
			}
		}
		food^ list;
		dish^ p;
		food^ list_order;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;

	private: System::Windows::Forms::Button^ button2;


	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;




	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button6;



	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Key_Menu::typeid));
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button6 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->Column1,
					this->Column2, this->Column3
			});
			this->dataGridView1->Location = System::Drawing::Point(22, 41);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(454, 271);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellContentDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Key_Menu::dataGridView1_CellContentDoubleClick);
			// 
			// Column1
			// 
			this->Column1->Frozen = true;
			this->Column1->HeaderText = L"Название";
			this->Column1->MinimumWidth = 6;
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			this->Column1->Width = 125;
			// 
			// Column2
			// 
			this->Column2->Frozen = true;
			this->Column2->HeaderText = L"Каллорийность(ккал)";
			this->Column2->MinimumWidth = 6;
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			this->Column2->Width = 150;
			// 
			// Column3
			// 
			this->Column3->Frozen = true;
			this->Column3->HeaderText = L"Стоимость(руб)";
			this->Column3->MinimumWidth = 6;
			this->Column3->Name = L"Column3";
			this->Column3->ReadOnly = true;
			this->Column3->Width = 125;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(578, 290);
			this->button2->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(106, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Закрыть";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Key_Menu::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(480, 41);
			this->button3->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(204, 28);
			this->button3->TabIndex = 4;
			this->button3->Text = L"Сортировать по каллорийности";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Key_Menu::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(480, 74);
			this->button4->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(204, 28);
			this->button4->TabIndex = 5;
			this->button4->Text = L"Сортировать по цене";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Key_Menu::button4_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(480, 290);
			this->button1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(92, 22);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Помощь";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Key_Menu::button1_Click_1);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(480, 118);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(135, 13);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Введите каллорийность";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(482, 149);
			this->textBox1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(196, 22);
			this->textBox1->TabIndex = 9;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(482, 181);
			this->button5->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(195, 27);
			this->button5->TabIndex = 10;
			this->button5->Text = L"Показать подходящие блюда";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Key_Menu::button5_Click);
			// 
			// textBox2
			// 
			this->textBox2->Enabled = false;
			this->textBox2->Location = System::Drawing::Point(480, 234);
			this->textBox2->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(196, 22);
			this->textBox2->TabIndex = 11;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(480, 218);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(104, 13);
			this->label2->TabIndex = 12;
			this->label2->Text = L"Общая стоимость:";
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(481, 257);
			this->button6->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(203, 29);
			this->button6->TabIndex = 13;
			this->button6->Text = L"Отменить сортировку";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Key_Menu::button6_Click);
			// 
			// Key_Menu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(696, 343);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->dataGridView1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"Key_Menu";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Основное меню";
			this->Load += gcnew System::EventHandler(this, &Key_Menu::Key_Menu_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Key_Menu_Load(System::Object^ sender, System::EventArgs^ e) {
		list->Load("Основное меню.txt");
		list->View(dataGridView1);
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

private: System::Void Button1_Click(System::Object^ sender, System::EventArgs^ e) {
	food^ list_order = gcnew food();

}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	list->fattest();
	list->View(dataGridView1);
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	list->most_expensive();
	list->View(dataGridView1);
}
private: System::Void dataGridView1_CellContentDoubleClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	int i = e->RowIndex;
	auto result = MessageBox::Show(
		"Вы действительно хотите добавить блюдо в список?",
		"Подтвердите добавление",
		MessageBoxButtons::YesNo,
		MessageBoxIcon::Question);

	if (result == System::Windows::Forms::DialogResult::Yes)
	{
		list_order->Add(list->Food_list[i]);
		list_order->Infile("Заказ_блюда.txt");
		MessageBox::Show("Блюдо успешно добавлено в заказ", "Сообщение о добавлении");
	}
}
private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show("Чтобы добавить блюдо в заказ, нажмите дважды на название блюда", "Помощь");
}

private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	if (textBox1->Text != "")
	{
		food^ g = gcnew food();
		g = list->sort_cal(Convert::ToInt32(textBox1->Text));
		g->View(dataGridView1);
		textBox2->Text = Convert::ToString(g->sum_price());
	}
}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	list->View(dataGridView1);
	textBox2->Text = "";
}
};
}
