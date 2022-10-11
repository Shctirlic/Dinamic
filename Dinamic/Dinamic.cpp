#include <iostream>
#include <cmath> 
#include <cstdlib>
#include <ctime>
using namespace std;

template <typename T>
void fill_arr(T arr[], int length, int begin, int end) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (end - begin) + begin;
}
template <typename T>
void show_arr(T arr[], const int length) {
	cout << '[';
	for (int i = 0; i < length; i++)
		cout << arr[i] << " ,";
	cout << "\b\b]\n";

}

template <typename T>
void add_el(T *&arr, const int length, int num) {
	if (num <= 0)
		return;
	T* tmp = new T[length + num]{};
	for (int i = 0; i < length; i++)
		tmp[i] = arr[i];

	delete[] arr;
	arr = tmp;
}

template <typename T>
void substrack_el(T*& arr, const int length, int num) {
	if(num <= 0)
		return;
	if (num > length) {
		delete[] arr;
		arr = new int[0];
		return;
	}
	T* tmp = new T[length - num];

	for (int i = 0; i < length - num; i++)
		tmp[i] = arr[i];
	delete[]arr;
	arr = tmp;
}

int main() {
	setlocale(LC_ALL, "Russian");
	int n;

	//Динамические переменные

	/*int* point = new int; // выделение участка динамической памяти размером 4 байта с помощью оператора new
	*point = 10;

	cout << "point = " << point << '\n';
	cout << "*point = " << *point << '\n';

	delete point; // Очищение области памяти, на которую направлен указатель
	point = nullptr;

	if (point != nullptr)
		cout << *point << '\n';
	else
		cout << "Указатель нейтрален." << '\n';

	cout << *point << '\n';

	point = new int; // Выделение нового участка памяти
	*point = 15;
	cout << "point = " << point << '\n';
	cout << "*point = " << *point << '\n';

	delete point;


	//Утечка памяти - это явление, в ходе которого значения, используемые в программе остаются в оперативной памяти*/

	//Динамические массивы
	/*cout << "Введите длину массива: ";
	cin >> n;
	if (n < 0)
		cout << "Ошибка! Длина не может быть отрицательной.";
	else {
		int* mass = new int[n]; // выделение динамической памяти для хранения массива
		cout << "Динамический массив: \n";
		srand(time(NULL));


		for (int i = 0; i < n; i++) {
			mass[i] = rand() % 10 + 1;
			cout << mass[i] << " ,";
		}
		cout << "\b\b.\n";
		delete[] mass;
	}*/

	//Задача 1. Увеличение массива
	/*cout << "Задача 1.\nВведите длину массива: ";
	int size1;
	cin >> size1;
	int* arr1 = new int[size1];
	cout << "Изначальный массив: ";

	fill_arr(arr1, size1, 1, 11);
	show_arr(arr1, size1);

	cout << "Введите количестов новых элементов: ";
	cin >> n;

	add_el(arr1, size1, n);
	size1 += n;

	cout << "Итоговый массив: \n";
	show_arr(arr1, size1);*/

	//Задача 2. Уменьшение массива

	cout << "Задача 2.\n Введите длину массива: ";
	int size2;
	cin >> size2;
	int* arr2 = new int[size2];
	fill_arr(arr2, size2, 1, 11);
	cout << "Изначальный массив: ";
	show_arr(arr2, size2);
	cout << "Введите количество элементов для уменьшения: ";
	cin >> n;


	substrack_el(arr2, size2, n);
	size2 -= n;


	//двумерный динамический массив

	//int *mx = new int [4][6]// не работает
	int** mx = new  int* [4];

	for (int i = 0; i < 4; i++)
		mx[i] = new int[6];

	//очищение двумерного динамического массива
	//delete[][]mx; // не работает
	for (int i = 0; i < 4; i++)
		delete[] mx[i];
	delete[]mx;


	return 0;
}