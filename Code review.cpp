#include <iostream>

using namespace std;

template <class T>
class A
{
	T a; //элемент
	A<T>* b; //указатель на следующий элемент
public:
	A(T a)
	{
		this->a = a;
		b = NULL;
	}
	T getA() //возвращает значение элемента
	{
		return a;
	}
	void setA(T a) //добавить значение элемента
	{
		this->a = a;
	}
	void setB(A<T>* d) //добавляем ссылку на след. элемент
	{
		b = d;
	}
	A<T>* getB() //возвращает след. элемент
	{
		return this->b;
	}
};

template <class T>
class B
{
	A<T>* c; //первый элемент списка, в котором будут содержаться элементы класса А
	int d; //количество элементов списка
public:
	B()
	{
		c = NULL;
		d = 0;
	}
	void func1 (T a);
	int func2 (T a, T b);
	template <class F>
	friend ostream & operator<< (ostream &out, const B<F> &point);
	~B()
	{
		if	(!d)
		{
			A<T>* e = c;
			A<T>* temp;
			for (int i = 0 ; i < d; i++)
			{
				temp = e->getB();
				delete e;
				e = temp;
			}
			c = NULL;
			d = 0;
		}
	}
};

template <class T>
void B<T>::func1 (T a) //добавление элемента в конец списка
{
	A<T>* temp = new A<T> (a);
	if (!d)
	{
		c = temp;
		d++;
	}
	else
	{
		A<T>* e = c;
		for (int i = 0; i < d-1; i++)
		{
			e = e->getB();
		}

		e->setB(temp);
		d++;
	}
}

template <class T>
int B<T> :: func2 (T a, T b) //замена элементов со значением а на b
{
	if (!d)
	{
		cout << "Empty!" << endl;
		return 2; // Возвращает 2, если пусто
	}
	else
	{
		int flag = 1;
		A<T>* e = c;
		for(int i=0 ; i < d; i++)
		{
			if (e->getA() == a)
			{
				e->setA(b);
				flag = 0;
			}
			e = e->getB();
		}
		return flag; // Возвращает 1 - если нет элемента, 0 - если есть
	}
}

template <class T>
ostream& operator<< (ostream &out, const B<T> &a) //в переменную, находящуюся слева от <<, сохраняются значения всех элементов списка, находящегося справа от <<
{

	if (!a.d)
	{
		out << "Empty" << endl;
	}
	else
	{
		A<T>* e = a.c;
		for (int i = 0; i < a.d; i++)
		{
			out << e->getA() << " ";
			e = e->getB();
		}
		out<<endl;
	}
	return out;
}

int main() //Возможный функционал: добавление в список элемента и возможность заменить его другим элементом
{
	B<int> test;

	cout << test << endl;
	cout << test.func2(3, 10) << endl;

	test.func1(1);
	test.func1(3);
	test.func1(5);
	test.func1(3);
	test.func1(7);

	cout << test << endl;
	cout << test.func2(3, 10) << endl;
	cout << test << endl;
	cout << test.func2(4, 11) << endl;
	cout << test << endl;

	return 0;
}
