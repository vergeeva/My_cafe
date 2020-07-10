#include "food.h"

dish::dish()
{
	name = gcnew String("�������� �����");
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
	name = gcnew String("�������� �����");
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
	dish ^temp = gcnew dish(); // ��������� ���������� ��� ������ ��������� �������
// ���������� ������� ���������
	for (int i = 0; i < len - 1; i++) {
		for (int j = 0; j < len - i - 1; j++) {
			if (food_list[j] > food_list[j + 1]) {
				// ������ �������� �������
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
	dish^ temp = gcnew dish(); // ��������� ���������� ��� ������ ��������� �������
// ���������� ������� ���������
	for (int i = 0; i < len - 1; i++) {
		for (int j = 0; j < len - i - 1; j++) {
			if (food_list[j+1] < food_list[j]) {
				// ������ �������� �������
				temp = food_list[j];
				food_list[j] = food_list[j + 1];
				food_list[j + 1] = temp;
			}
		}
	}
	return this;
}

double food::sum_price()
{
	double sum_price = 0;
	for (int i = 0; i < len; i++)
	{
		sum_price+=food_list[i]->Price;
	}
	return sum_price;
}

int food::sum_cal()
{
	double sum_cal = 0;
	for (int i = 0; i < len; i++)
	{
		sum_cal += food_list[i]->Cal;
	}
	return sum_cal;
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

//������� ��� �����, ������������ ������� ����, ��� ��������� ��������.���������� ���������
double food::sort_luhch(array <food^> ^ lunch, int len)
{
	for (int i = 0; i < len; i++)
	{

	}
	return 0.0;
}

food^ food::operator=(food^ other)
{
	for (int i = 0; i > len; i++)
	{
		this->food_list[i] = other->food_list[i];
	}
	return this;
}

bool food::operator==(food^ other)
{
	for (int i = 0; i < len; i++)
	{
		if (!(this->food_list[i] == other->food_list[i]))
			return 0;

	}
	return 1;
}

food_arr::food_arr()
{
	Count = 0;
	for each (food^ i in lunch_list)
	{
		i = gcnew food();
	}
}

bool food_arr::empty()
{
	return Count == 0;
}

bool food_arr::full()
{
	return Count == 100;
}

bool food_arr::Add(food^ object)
{
	if (!full())
	{
		this->lunch_list[this->Count]->operator=(object);
		this->Count++;
		return 1;
	}
	else return 0;
}

bool food_arr::Del(food^ value)
{
	if (!empty())
	{
		for (int i = 0; i < Count; i++)
		{
			if (lunch_list[i] == value)
			{
				for (int k = i; k < Count; k++)
				{
					lunch_list[k] = lunch_list[k + 1];
				}
				Count--;
				return 1;
			}
		}
	}
	return 0;
}

void food_arr::View(System::Windows::Forms::DataGridView^ DGV)
{
	if (Count == 0)
	{
		DGV->Rows[0]->Cells[0]->Value = "";
		DGV->Rows[0]->Cells[1]->Value = "";
		DGV->Rows[0]->Cells[2]->Value = "";
	}
	else
	{
		DGV->RowCount = Count;
		for (int i = 0; i < Count; i++)
		{
			DGV->Rows[i]->Cells[0]->Value = this->lunch_list[i]->Name;
			DGV->Rows[i]->Cells[1]->Value = this->lunch_list[i]->sum_cal();
			DGV->Rows[i]->Cells[2]->Value = this->lunch_list[i]->sum_price()*0.8;
		}
	}
}

