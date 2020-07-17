#pragma once
using namespace System;
using namespace std;
using namespace System::IO;
public ref class dish //блюдо
{
private:
	String^ name;
	int calorific;
	double price;

public:
	dish();
	bool operator ==(dish ^ other);
	dish^ operator =(dish^ other);
	bool operator >(dish^ other);
	bool operator <(dish^ other);
	property String^ Name
	{
		String^ get() {
			return name;
		}
		void set(String^ Name) {
			name = gcnew String(Name);
		}
	}

	property int Cal
	{
		int get() {
			return calorific;
		}
		void set(int Cal) {
			calorific = Cal;
		}
	}

	property double Price
	{
		double get() {
			return price;
		}
		void set(double price) {
			this->price = price;
		}
	}
};

public ref class food //список блюд
{
	String^ name;
	array <dish^>^ food_list = gcnew array <dish^>(100);
	int len;
public:
	food();
	bool empty();
	bool full();
	bool Add(dish^);
	bool Del(dish^);
	void View(System::Windows::Forms::DataGridView^);
	food^ fattest();
	food^ most_expensive();
	double sum_price();
	int sum_cal();
	//Выбрать все блюда, калорийность которых ниже, чем указанное значение, и подсчитать их стоимость.
	double sort_cal(int);
	void Load(String^);
	food^ operator =(food^ other);
	bool operator ==(food^ other);

	property String^ Name
	{
		String^ get() {
			return name;
		}
		void set(String^ Name) {
			name = Name;
		}
	}

};

public ref class food_arr //Список бизнес-ланчей
{
	int Count;
	array <food^>^ lunch_list = gcnew array <food^>(100);
public:
	food_arr();
	bool empty();
	bool full();
	bool Add(food^);
	bool Del(food^);
	void View(System::Windows::Forms::DataGridView^);
	void Load(String^);
	//Выбрать все ланчи, калорийность которых ниже, чем указанное значение.Подсчитать стоимость
	
	//Выбрать все ланчи, стоимость которых ниже, чем указанное значение.Подсчитать калорийность.



};
