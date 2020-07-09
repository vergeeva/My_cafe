#include "food.h"

dish::dish()
{
	name = gcnew String("Названия блюда");
	calorific = 0;
	price = 0;
}

bool dish::operator==(dish^ other)
{
	return this->name == other->name && this->calorific == other->calorific && this->price == other->price;
}

bool dish::operator > (dish^ other)
{
	return this->calorific > other->calorific;
}

bool dish::operator<(dish^ other)
{
	return this->price < other->price;
}

dish^ dish::operator=(dish^ other)
{
	this->name = other->name;
	this->calorific = other->calorific;
	this->price = other->price;
	return this;
}

food::food()
{
	len = 0;
	for each (dish ^ i in food_list)
	{
		i = gcnew dish();
	}
}

bool food::empty()
{
	return len == 0;
}

bool food::full()
{
	return len == 100;
}

bool food::Add(dish^ object)
{
	if (!full())
	{
		this->food_list[this->len]->operator=(object);
		this->len++;
		return 1;
	}
	else return 0;
}

bool food::Del(dish^ value)
{
	if (!empty())
	{
		for (int i = 0; i < len; i++)
		{
			if (food_list[i] == value)
			{
				for (int k = i; k < len; k++)
				{
					food_list[k] = food_list[k + 1];
				}
				len--;
				return 1;
			}
		}
	}
	return 0;
}

void food::View(System::Windows::Forms::DataGridView^ DGV)
{
	if (len == 0)
	{
		DGV->Rows[0]->Cells[0]->Value = "";
		DGV->Rows[0]->Cells[1]->Value = "";
		DGV->Rows[0]->Cells[2]->Value = "";
	}
	else
	{
		DGV->RowCount = len;
		for (int i = 0; i < len; i++)
		{
			DGV->Rows[i]->Cells[0]->Value = this->food_list[i]->Name;
			DGV->Rows[i]->Cells[1]->Value = this->food_list[i]->Cal;
			DGV->Rows[i]->Cells[2]->Value = this->food_list[i]->Price;
		}
	}
}

food^ food::fattest()
{
	dish ^temp = gcnew dish(); // временная переменная для обмена элементов местами
// Сортировка массива пузырьком
	for (int i = 0; i < len - 1; i++) {
		for (int j = 0; j < len - i - 1; j++) {
			if (food_list[j] > food_list[j + 1]) {
				// меняем элементы местами
				temp = food_list[j];
				food_list[j] = food_list[j + 1];
				food_list[j + 1] = temp;
			}
		}
	}
	return this;
}

food^ food::most_expensive()
{
	dish^ temp = gcnew dish(); // временная переменная для обмена элементов местами
// Сортировка массива пузырьком
	for (int i = 0; i < len - 1; i++) {
		for (int j = 0; j < len - i - 1; j++) {
			if (food_list[j+1] < food_list[j]) {
				// меняем элементы местами
				temp = food_list[j];
				food_list[j] = food_list[j + 1];
				food_list[j + 1] = temp;
			}
		}
	}
	return this;
}

double food::sort_cal(int cal)
{
	double price_sum = 0;
	for (int i = 0; i < len; i++)
	{
		if (food_list[i]->Cal < cal)
		{
			price_sum += food_list[i]->Cal;
		}
	}

	return price_sum;
}
