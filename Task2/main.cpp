#include "iostream"
#include "vector"
#include "string"

using namespace std;

// Функция compute_common_divisors для вектора (динамического массива) из заданных чисел
// строит и возвращает вектор (динамический массив) из общих делителей
vector<int> compute_common_divisors(vector <int>& vec_in);

// Функция enter_number осуществляет проверку
// корректности введенного пользователем числа.
// Число должно быть целым и положительным.
int enter_number();

int main()
{
	setlocale(LC_ALL, "Russian");

	int quantity; // Переменная для количества чисел

	cout << "Введите положительное целое число - количество чисел, для которых необходимо найти общие делители: \n";

	quantity = enter_number(); // Получили "корректное" число

	cout << "Введите " << quantity << " положительных целых чисел, для которых необходимо найти общие делители \n";

	vector <int> num_vector;  // Создаем и заполняем вектор для исходных чисел

	for (int i = 0; i < quantity; i++)
	{
		num_vector.push_back(enter_number());
	}

	// Выведем на экран исходные числа:
	cout << "\nИсходный массив: [";
	for (int i = 0; i < num_vector.size() - 1; i++)
		cout << num_vector.at(i) << ", ";
	cout << num_vector.at(num_vector.size() - 1) << "]\n";

	vector <int> common_divisors_vector; // Создаем вектор для общих делителей

	common_divisors_vector = compute_common_divisors(num_vector); // Вычисляем общие делители

	// Выведем на экран полученные общие делители:
	cout << "Массив из общих делителей: [";
	for (int i = 0; i < common_divisors_vector.size() - 1; i++)
		cout << common_divisors_vector.at(i) << ", ";
	cout << common_divisors_vector.at(common_divisors_vector.size() - 1) << "]\n\n";

	system("pause");
}

// Функция compute_common_divisors для вектора (динамического массива) из заданных чисел
// строит и возвращает вектор (динамический массив) из общих делителей
vector<int> compute_common_divisors(vector <int>& vec_in)
{
	// Определим наименьший элемент в полученном векторе чисел	 
	int min = vec_in.at(0); // Пусть пока переменна min равна первому числу в векторе

	int num; // Переменная для индекса наименьшего элемента

	for (int i = 1; i < vec_in.size(); i++)
	{
		if (vec_in.at(i) < min)
		{
			min = vec_in.at(i);
			num = i;
		}
	}

	// Поместим наименьший элемент массива на первое место в векторе чисел.
	// Для этого поменяем местами первый элемент и минимальный элемент

	if (min != vec_in.at(0))
	{
		int exchange = vec_in.at(0);
		vec_in.at(0) = min;
		vec_in.at(num) = exchange;
	}

	// Создадим вектор для общих делителей
	vector <int> vec_out;

	int temp;

	// 1 является общим делителем для любых целых положительных чисел
	vec_out.push_back(1);

	// Будем делить найденный наименьший элемент min на числа j от 2 до min.
	// Если число j является делителем числа min, то проверяем будет ли 
	// оно делителем для всех остальных чисел исходного вектора, начиная 
	// со второго числа (первое число и есть само min).
	// Если да, то записываем j в вектор для делителей.

	for (int j = 2; j < min + 1; j++)
	{
		temp = 1;

		if (min % j == 0)
		{
			for (int i = 1; i < vec_in.size(); i++)
			{
				if (vec_in.at(i) % j == 0) temp++;
			}

			// Если все элементы вектора исходных чисел поделились на j нацело,
			// то записываем j в вектор делителей

			if (temp == vec_in.size()) vec_out.push_back(j);
		}
	}

	return vec_out; // Возвращаем вектор делителей.
}


// Функция enter_number осуществляет проверку
// корректности введенного пользователем числа.
// Число должно быть целым и положительным.
int enter_number()
{
	string str_number; // В эту переменную будем считывать число в виде строки
	int number; // В эту переменную будет помещено число, преобразованное из строки

	int flag = 0;
	do
	{
		try
		{
			cin >> str_number; // Считаем число в виде строки
			number = stoi(str_number); // Конвертируем строку в число int

			if (number < 1)
				cout << "Введено неположительное число. Введите число еще раз: \n";
			else flag = 1;
		}
		catch (invalid_argument)
		{
			cout << "Число введено неверно. Введите число еще раз: ";
		}
		catch (out_of_range)
		{
			cout << "Число слишком большое. Введите число еще раз: ";
		}
		catch (...)
		{
			cout << "Ошибка! Введите число еще раз: ";
		}

	} while (flag == 0);

	return number; // Возвращаем корректное число
}