// ConsoleApplication5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
struct T_List
{
	T_List* right_next;//правый элемент
	T_List* left_next;//левый элемент
	//std::string surname;
	int count;//счетчик элементов
	int age;
};

void ADD_START(T_List* cat, int age)//добавление сначала кота
{
	T_List* p = new T_List;
	p->age = age;
	p->right_next = cat->right_next;
	cat->right_next = p;
	p->left_next = cat; 
	T_List* n = p->right_next;
	n->left_next = p;
	cat->count += 1;
}
void ADD_START(int age,T_List* dog)//добавление сначала собаки
{
	T_List* p = new T_List;
	p->age = age;
	p->left_next = dog->left_next;
	dog->left_next = p;
	p->right_next=dog;
	T_List* n = p->left_next;
	n->right_next = p;
	dog->count += 1;
}
void ADD_END(T_List* cat, int age)//добавление в конец кота
{
	T_List* p = cat;
	while (p->right_next->right_next != nullptr)
	{
		p = p->right_next;
	}
	T_List* tmp = new T_List;
	tmp->age = age;
	tmp->right_next = p->right_next;
	p->right_next->left_next = tmp;
	p->right_next = tmp;
	tmp->left_next = p;
	cat->count += 1;
}
void ADD_END(int age, T_List* dog)//добавление в конец собаки
{

	T_List* p = dog;
	while (p->left_next->left_next != nullptr)
	{
		p = p->left_next;
	}
	T_List* tmp = new T_List;
	tmp->age = age;
	tmp->left_next = p->left_next;
	p->left_next->right_next = tmp;
	p->left_next = tmp;
	tmp->right_next = p;
	dog->count += 1;
}
void ADD_CENTRE(T_List* cat, T_List* dog, int age)//добавление в середину
{
	T_List* p = cat;
	int count = 0;
	while ((cat->count + dog->count+1) / 2 > count)
	{
		p = p->right_next;
		count = count + 1;
	}
	T_List* tmp = new T_List;
	tmp->age = age;
	tmp->right_next = p->right_next;
	p->right_next->left_next = tmp;
	p->right_next = tmp;
	tmp->left_next = p;
	cat->count += 1;
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
	cat->count -= 1;
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
	dog->count -= 1;
}
void DELETE_START_CAT(T_List* cat)//удаление с начала кота
{
	T_List* p = cat->right_next;
	cat->right_next = p->right_next;
	p->right_next->left_next = cat;
	delete p;
	cat->count -= 1;
}
void DELETE_START_DOG(T_List* dog)//удаление с начала собаки
{
	T_List* p = dog->left_next;
	dog->left_next = p->left_next;
	p->left_next->right_next = dog;
	delete p;
	dog->count -= 1;
}
void DELETE_CENTRE(T_List* cat, T_List* dog)//удаление из центра
{
	T_List* p = cat;
	int count = 0;
	while ((cat->count + dog->count + 1) / 2 > count)
	{
		p = p->right_next;
		count = count + 1;
	}
	if ((cat->count + dog->count + 1) % 2 != 0)
		p = p->right_next;
	T_List* tmp = p->left_next;
	tmp->right_next = p->right_next;
	p->right_next->left_next = tmp;
	delete p;
	cat->count -= 1;
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

int main()
{
	T_List* cat = new T_List;
	T_List* dog = new T_List;
	cat->right_next = dog;
	cat->count = 0;
	dog->right_next = nullptr;
	cat->left_next = nullptr;
	dog->left_next = cat;
	dog->count = 0;

	//  
	ADD_START(cat, 10);
	ADD_START(cat, 11);
	ADD_END(12,dog);
	ADD_START(3,dog);
	//ADD_START(2,dog);
	ADD_CENTRE(cat, dog, 5);
	//SEARCH(10, dog);
	PRINT_DOG(dog,cat);
	//DELETE(10, dog);
	//SEARCH(10, dog);
	std::cout << "=======" << std::endl;
	//PRINT_DOG(dog,cat);
	DELETE_CENTRE(cat, dog);
	std::cout << "====="<<std::endl;
	PRINT_CAT(cat, dog);
	PRINT_DOG(dog, cat);
	
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
