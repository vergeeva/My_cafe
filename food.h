#pragma once
using namespace System;
using namespace std;
public ref class dish
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

	property double^ Price
	{
		double^ get() {
			return price;
		}
		void set(double^ price) {
			price = price;
		}
	}
};

public ref class food
{
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
	//Выбрать все блюда, калорийность которых ниже, чем указанное значение, и подсчитать их стоимость.
	double sort_cal(int);

};

////Выбрать все ланчи, калорийность которых ниже, чем указанное значение.Подсчитать стоимость.
//double sort_cal_in_mas(array <food^>^ l, int cal)
//{
//	for (int i = 0; i < l->Length; i++)
//	{
//		if ()
//	}
//}