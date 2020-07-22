#include "food.h"

dish::dish()
{
	name = gcnew String("Названия блюда");
	calorific = 1;
	price = 1;
}

dish::~dish()
{
	delete name;
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
	this->Name = other->name;
	this->Cal = other->calorific;
	this->Price = other->price;
	return this;
}


food::food()
{
	len = 0;
	for (int i = 0; i < 100;i++)
	{
		food_list[i] = gcnew dish();
	}
}

food::~food()
{
	len = 0;
	for (int i = 0; i < 100; i++)
	{
		delete food_list[i];
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
	for (int i = 0; i < len - 1; i++) 
	{
		for (int j = 0; j < len - i - 1; j++) 
		{
			if (food_list[j] > food_list[j + 1]) 
			{
				// меняем элементы местами
				temp->operator=(food_list[j]);
				food_list[j]->operator=(food_list[j + 1]);
				food_list[j + 1]->operator=(temp);
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
	int sum_cal = 0;
	for (int i = 0; i < len; i++)
	{
		sum_cal += food_list[i]->Cal;
	}
	return sum_cal;
}

food^ food::sort_cal(int cal)
{
	food^ g = gcnew food();
	for (int i = 0; i < len; i++)
	{
		if (food_list[i]->Cal < cal)
		{
			g->Add(food_list[i]);
		}
	}
	return g;
}

void food::Load(String^ fileName)
{
	StreamReader^ SR = gcnew StreamReader(fileName);
	String^ str = gcnew String("");
	while (str = SR->ReadLine()) {
		dish^ p = gcnew dish();
		p->Name = str->Substring(0, str->IndexOf("$"));
		p->Cal = Convert::ToInt32(str->Substring(str->IndexOf("$") + 1, 3));
		p->Price = Convert::ToDouble(str->Substring(str->LastIndexOf("$")+1));
		this->Add(p);
	}
	SR->Close();
}

void food::Infile(String^ fileName)
{
	StreamWriter^ My_SW = gcnew StreamWriter(fileName);
	for (int i = 0; i < len; i++)
	{
		String^ Line = gcnew String("");
		if (food_list[i]->Cal >= 0 && food_list[i]->Cal < 10)
		{
			Line = food_list[i]->Name + "$" + "00" + food_list[i]->Cal + "$" + food_list[i]->Price + "\n";
		}
		else
		{
			if (food_list[i]->Cal < 100)
			{
				Line = food_list[i]->Name + "$" + "0" + food_list[i]->Cal + "$" + food_list[i]->Price + "\n";

			}
			else
			{
				Line = food_list[i]->Name + "$" + food_list[i]->Cal + "$" + food_list[i]->Price + "\n";

			}
		}

		
		My_SW->Write(Line);
	}
	My_SW->Close();
}


food^ food::operator=(food^ other)
{
	for (int i = 0; i < len; i++)
	{
		this->food_list[i]->operator= (other->food_list[i]);
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
	for (int i = 0; i < 100; i++)
	{
		lunch_list[i] = gcnew food();
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
		this->lunch_list[Count] = object;
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

void food_arr::Load(String^ fileName)
{
	food^ f = gcnew food();
	dish^ p = gcnew dish();

	StreamReader^ SR = gcnew StreamReader(fileName);
	String^ str = gcnew String("");
	f->Name = SR->ReadLine();
	while (str = SR->ReadLine())
	{
		if (str == "") 
		{ 
		this->Add(f); 
		f = gcnew food();
		f->Name = SR->ReadLine(); 
		}
		else
		{
			p->Name = str->Substring(0, str->IndexOf("$"));
			p->Cal = Convert::ToInt32(str->Substring(str->IndexOf("$") + 1, 3));
			p->Price = Convert::ToDouble(str->Substring(str->LastIndexOf("$") + 1));
			f->Add(p);
		}
	}
	this->Add(f);
	SR->Close();
}

void food_arr::Infile(String^ fileName)
{
	StreamWriter^ My_SW = gcnew StreamWriter(fileName);
	String^ space = gcnew String("\n"); ;
	for (int i = 0; i < Count; i++)
	{
		String^ Line = gcnew String("");
		Line = lunch_list[i]->Name + "\n";
		My_SW->Write(Line);
		for (int j = 0; j < lunch_list[i]->Len; j++)
		{
			String^ Line_1 = gcnew String("");


			if (lunch_list[i]->Food_list[j]->Cal >= 0 && lunch_list[i]->Food_list[j]->Cal < 10)
			{
				Line_1 = lunch_list[i]->Food_list[j]->Name + "$" + "00" + lunch_list[i]->Food_list[j]->Cal + "$" + lunch_list[i]->Food_list[j]->Price + "\n";
			}
			else
			{
				if (lunch_list[i]->Food_list[j]->Cal < 100)
				{
					Line_1 = lunch_list[i]->Food_list[j]->Name + "$" + "0" + lunch_list[i]->Food_list[j]->Cal + "$" + lunch_list[i]->Food_list[j]->Price + "\n";

				}
				else
				{
					Line_1 = lunch_list[i]->Food_list[j]->Name + "$" + lunch_list[i]->Food_list[j]->Cal + "$" + lunch_list[i]->Food_list[j]->Price + "\n";

				}
			}




			My_SW->Write(Line_1);
		}
		if (Count > 1 && i != Count - 1) My_SW->Write(space);
	}
	My_SW->Close();
}

food_arr^ food_arr::sort_cal(int cal)
{
	food_arr^ g = gcnew food_arr();
	for (int i = 0; i < Count; i++)
	{
		if (lunch_list[i]->sum_cal() < cal)
		{
			g->Add(lunch_list[i]);
		}
	}
	return g;
}

food_arr^ food_arr::sort_price(double price)
{
	food_arr^ g = gcnew food_arr();
	for (int i = 0; i < Count; i++)
	{
		if (lunch_list[i]->sum_price()*0.8 < price)
		{
			g->Add(lunch_list[i]);
		}
	}
	return g;
}

int food_arr::sum_cal()
{
	int sum_cal = 0;
	for (int i = 0; i < Count; i++)
	{
		sum_cal += lunch_list[i]->sum_cal();
	}
	return sum_cal;
}

double food_arr::sum_price()
{
	double sum_price = 0;
	for (int i = 0; i < Count; i++)
	{
		sum_price += lunch_list[i]->sum_price()*0.8;
	}
	return sum_price;
}

