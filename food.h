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
	~dish();
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
	~food();
	bool empty();
	bool full();
	bool Add(dish^);
	bool Del(dish^);
	void View(System::Windows::Forms::DataGridView^);
	food^ fattest();
	food^ most_expensive();
	double sum_price();
	int sum_cal();
	food^ sort_cal(int cal);
	void Load(String^);
	void Infile(String^);
	food^ operator =(food^ other);
	bool operator ==(food^ other);

	property array <dish^>^ Food_list
	{
		array <dish^>^ get() {
			return food_list;
		}
	}

	property int Len
	{
		int get() 
		{
			return len;
		}
	}

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

public ref class food_arr //—писок бизнес-ланчей
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
	void Infile(String^);

	//4.	¬ыбрать все ланчи, калорийность которых ниже, чем указанное значение.ѕодсчитать стоимость.
	property array <food^>^ Lunch_list
	{
		array <food^>^ get() {
			return lunch_list;
		}
	}
	food_arr^ food_arr::sort_cal(int cal);
	//5.	¬ыбрать все ланчи, стоимость которых ниже, чем указанное значение.ѕодсчитать калорийность.
	food_arr^ sort_price(double price);
	int sum_cal();
	double sum_price();


};
