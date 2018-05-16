#include"library.h"
#include"vector.h"
Vector::Vector()
{
	cur_size = 0;
	buf_size = 0;
	els = nullptr;
	count = 0;
}
int Vector::push_back(int el)
{
	if (buf_size == 0)
	{
		buf_size = 2;
		els = new int[buf_size];
	}
	else if (buf_size <= cur_size)
	{
		buf_size *= 2;
		int *tmp = new int[buf_size];
		for (int i = 0;i < cur_size;i++)
		{
			tmp[i] = els[i];
		}
		delete[]els;
		els = tmp;
	}
	els[cur_size] = el;
	cur_size++;
	return els[cur_size - 1];
}
Vector & Vector::operator+(const Vector & obj)
{
	for (int i = 0;i < cur_size ; i++)
	{
		this->els[i] += obj.els[i];
	}
	return *this;
}
Vector & Vector::operator-(const Vector & obj)
{
	Vector SaveIndex;
	for (int i = 0;i < cur_size;i++)
	{
		for (int j = 0;j < cur_size;j++)
		{
			if (this->els[i] == obj.els[j])
			{
				SaveIndex.push_back(i);
			}
		}
	}
	for (int i = 0;i < SaveIndex.cur_size;i++)
	{
		int index = SaveIndex[i]; //перегрузкa оператора индексирования
		deleteEl(index);
	}
	return *this;
}
void Vector::print()
{
	for (int i = 0;i < cur_size;i++)
		cout << els[i] << " ";
}
Vector Vector::deleteEl(int index)
{
	if (index == cur_size - 1)
		cur_size-=2;
	else
	{

		int*tmp = new int[cur_size];
		int i = 0;
		for (;i < index;i++)
		{
			tmp[i] = els[i];
		}
		for (int j = i;j < cur_size;j++)
		{
			tmp[j] = els[j + 1];
		}
		delete[] els;
		els = tmp;
	}
	return *this;
}

int Vector::operator[](int index)
{
	return this->els[index];
}