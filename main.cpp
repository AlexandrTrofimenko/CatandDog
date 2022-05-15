// ConsoleApplication5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
struct T_List
{
	T_List* right_next;//правый элемент
	T_List* left_next;//левый элемент
	//std::string surname;
	int age;
};

void ADD(T_List* cat, int age)//добавление сначала кота
{
	T_List* p = new T_List;
	p->age = age;
	p->right_next = cat->right_next;
	cat->right_next = p;
	p->left_next = cat; 
	T_List* n = p->right_next;
	n->left_next = p;
}
void ADD(int age,T_List* dog)//добавление сначала собаки
{
	T_List* p = new T_List;
	p->age = age;
	p->left_next = dog->left_next;
	dog->left_next = p;
	p->right_next=dog;
	T_List* n = p->left_next;
	n->right_next = p;
}

void PRINT_CAT(T_List* cat,T_List* dog)//вывод с кота
{
	T_List* p = cat->right_next;
	while (p != dog)
	{
		std::cout << p->age << std::endl;
		p = p->right_next;
	}
}
void PRINT_DOG(T_List* dog, T_List* cat)//вывод с собаки
{
	T_List* p = dog->left_next;
	while (p != cat)
	{
		std::cout << p->age << std::endl;
		p = p->left_next;
	}
}
void SEARCH(T_List* cat, int k)//поиск элемента по ключу с кота
{
	T_List* p = cat;
	while (p->right_next != nullptr)
	{
		if (p->right_next->age == k)
		{
			std::cout << "found " << p->right_next->age << std::endl;
			return;
		}
		else
			p = p->right_next;
	}
	std::cout<<"not found "<< k << std::endl;
}
void SEARCH(int k, T_List* dog)// поиск элемента по ключу с собаки
{
	T_List* p = dog;
	while (p->left_next != nullptr)
	{
		if (p->left_next->age == k)
		{
			std::cout << "found " << p->left_next->age << std::endl;
			return;
		}
		else
			p = p->left_next;
	}
	std::cout << "not found " << k << std::endl;
}
void DELETE(T_List* cat,int k)//удаление элемента по ключу с кота
{
	T_List* tmp;
	T_List* p = cat;
	while (p->right_next != nullptr)
	{
		if (p->right_next->age  == k)
		{
			tmp = p->right_next;
			p->right_next = p->right_next->right_next;
			delete tmp;
			T_List* n = p->right_next;
			n->left_next = p;
		}
		else
			p = p->right_next;
	}
}
void DELETE(int k, T_List* dog)// удаление элемента по ключу с собаки
{
	T_List* tmp;
	T_List* p = dog;
	while (p->left_next != nullptr)
	{
		if (p->left_next->age == k)
		{
			tmp = p->left_next;
			p->left_next = p->left_next->left_next;
			delete tmp;
			T_List* n = p->left_next;
			n->right_next = p;
		}
		else
			p = p->left_next;
	}
}

void CLEAR(T_List* cat,T_List* dog)//очистка
{
	T_List* tmp;
	T_List* p = cat->right_next;
	while (p != dog)
	{
		tmp = p;
		p = p->right_next;
		delete tmp;
	}
}

void DUPLICATE(T_List* cat)
{
	T_List* p = cat->right_next;
	while (p != nullptr)
	{
		if (p->age % 2 == 1)
		{
			T_List* q = new T_List;
			q->right_next = p->right_next;
			p->right_next = q;
			q->age = p->age;
			p = p->right_next;
		}
		p = p->right_next;
	}
}

void SWAPSORT(T_List* cat)
{
	//for(int i=0;i<n-1;i++)
	//	for(int j=i+1;j<n;j++)

	T_List* p = cat->right_next;
	while (p->right_next->right_next != nullptr)
	{
		T_List* q = p->right_next;
		while (q->right_next != nullptr)
		{
			if (p->age > q->age)
				std::swap(p->age, q->age);
			q = q->right_next;
		}
		p = p->right_next;
	}
}

int main()
{
	T_List* cat = new T_List;
	T_List* dog = new T_List;
	cat->right_next = dog;
	dog->right_next = nullptr;
	cat->left_next = nullptr;
	dog->left_next = cat;

	//  
	ADD(cat, 10);
	ADD(cat, 11);
	ADD(3,dog);
	ADD(2,dog);
	
	SEARCH(10, dog);
	PRINT_DOG(dog,cat);
	DELETE(10, dog);
	SEARCH(10, dog);
	std::cout << "=======" << std::endl;
	PRINT_DOG(dog,cat);
	std::cout << "====="<<std::endl;
	PRINT_CAT(cat, dog);
	
	CLEAR(cat,dog);

	delete cat;
	delete dog;
	return 0;
}



 

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
