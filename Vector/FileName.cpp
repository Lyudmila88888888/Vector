#include <iostream>
#include <vector> //подключение библиотеки содержащей в себе
// класс вектор и его агрегаторы
#include <algorithm>





int main() {
	setlocale(LC_ALL, "Russian");
	
	// Класс Вектор
	std::vector<int> vect1{10, 20, 30}; //vect1(10, 1) 10 ЭЛЕМЕНТОВ ЗАПОЛНЯЮТСЯ 1
	vect1.push_back(7);
	vect1.push_back(42);
	vect1.push_back(105);
	vect1.push_back(777);
	vect1.push_back(58);
	vect1.push_back(49);
	vect1.push_back(72);

	std::sort(vect1.begin(), vect1.end());// если отсортировать с конца по убыванию то (vect1.rbegin(), vect1.rend())

	vect1.reserve(100); // резерв элементов
	
	std::cout << "Size: " << vect1.size() << std::endl; // размер - ячейки заполненные элементами
	std::cout << "Capacity: " << vect1.capacity() << std::endl; // общее количество элементов, добавляется если используется метод push back

	vect1.shrink_to_fit();// метод убирает все зарезервированные элементы из памяти
	vect1.resize(10); // позволяет поменять размер ветора как в большую так и в меньшую сторону

	std::cout << "Size: " << vect1.size() << std::endl; // размер - ячейки заполненные элементами
	std::cout << "Capacity: " << vect1.capacity() << std::endl;

	std::cout << "Max size: " << vect1.max_size() << std::endl;

	std::cout << vect1.size() << std::endl;
	//vect1.push_back(77);
	if (!vect1.empty())// метод empty проводит проверку не пустой ли вектор
		vect1.pop_back();// удаляет последний элемент вектора
	

	std::cout << vect1.front() << std::endl; // метод дает (ссылку) значение самого первого элемента
	std::cout << vect1.back() << std::endl;//метод  дает(ссылку) значение самого последнего элемента

	vect1.front() = 155;
	vect1.back() = 999;
	
	//std::cout << vect1[10] << std::endl;
	std::cout << vect1.at(3) << std::endl; //метод  обращениея к элементу как в квадратных скобочках
	// метод обладает специальной проверкой как мы писали с if exeption
	// перимущества гарантия безопасности
	//недостатки работает медленно

	std::cout << vect1.size() << std::endl;
	for (size_t i{}; i < vect1.size(); ++i)
		std::cout << vect1[i] << ' ';
	std::cout << std::endl;
	
	// Итераторы

	std::vector<int> vect2{ 10, 20, 30, 40 };

	std::vector<int>::iterator iter = vect2.begin();
	//std::vector<int>::const_iterator iter = vect2.cbegin();
	std::cout << *iter << std::endl;
	*iter = 100;
	++iter;
	std::cout << *iter << std::endl;

	//for (std::vector<int>::const_iterator i = vect2.begin(); i != vect2.end(); ++i)
		for (auto i = vect2.cbegin(); i != vect2.cend(); ++i)
		//for (std::vector<int>::const_iterator i = vect2.cbegin(); i != vect2.cend(); ++i)
		//for (std::vector<int>::reverse_iterator i = vect2.rbegin(); i != vect2.rend(); ++i)
		std::cout << *i << ' ';
	std::cout << std::endl;

	int sum = 0;

	// Цикл foreach
	for (auto el : vect2) // перебрать с помощью предыдущего цикла/ Нельзя обнулить элементы, можно только получить значения
		sum += el;
	std::cout << sum << std::endl;

	auto num1 = 10; // автоматически определяется тип данных, не меняется потом
	auto num2 = 5.5;
	auto sym = 'a';
	auto f = false;
	

	return 0;

}