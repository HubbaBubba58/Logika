#include <iostream>
#include <string>
#include <windows.h>

struct Student
{
	int number = 0;
	std::string first_name = "Имя";
	std::string middle_name = "Отчество";
	std::string last_name = "Фамилия";
	int age = 0;
	int year_admission = 0;
	int average_score = 0;
	Student* next = nullptr;

	Student()
	{
		std::cout << "Введите имя студента: ";
		std::cin >> first_name;
		std::cout << "Введите фамилия студента: ";
		std::cin >> last_name;
		std::cout << "Введите отчество студента: ";
		std::cin >> middle_name;
		std::cout << "Введите возраст студента: ";
		std::cin >> age;
		std::cout << "Введите год поступления студента: ";
		std::cin >> year_admission;
		std::cout << "Введите средний балл студента: ";
		std::cin >> average_score;
	}
	void output()
	{
		std::cout << "Студент номер " << number << ":" << std::endl;
		std::cout << first_name << std::endl << last_name << std::endl << middle_name << std::endl;
		std::cout << "Возраст: " << age << std::endl;
		std::cout << "Год поступления: " << year_admission << std::endl;
		std::cout << "Средний балл: " << average_score << std::endl;
		return;
	}
};

struct List
{
	Student* first = nullptr;
	Student* last = nullptr;
	bool is_empty()
	{
		return first == nullptr;
	}
	void add_back()
	{
		if (is_empty())
		{
			first = new Student;
			last = first;
			first->number = 1;
			return;
		}
		last->next = new Student;
		int numberX = last->number;
		last = last->next;
		last->number = ++numberX;
		return;
	}
	bool Search_student(unsigned short int* type, int number, std::string value)
	{
		bool found = 0;
		bool anything = 0;
		for (int counter = 0; counter < number; ++counter)
		{
			switch (type[counter])
			{
			case 1:
			{
				for (Student* pointer = first; pointer != nullptr; pointer = pointer->next)
				{
					if (pointer->first_name == value)
					{
						if (!anything)
						{
							std::cout << "По запросу \"" << value << "\" найдено:" << std::endl;
							std::cout << "<------------------------------------------------------>" << std::endl;
							anything = 1;
						}
						pointer->output();
						std::cout << "<------------------------------------------------------>" << std::endl;
						found = 1;
					}
				}
			} break;
			case 2:
			{
				for (Student* pointer = first; pointer != nullptr; pointer = pointer->next)
				{
					if (pointer->last_name == value)
					{
						if (!anything)
						{
							std::cout << "По запросу \"" << value << "\" найдено:" << std::endl;
							std::cout << "<------------------------------------------------------>" << std::endl;
							anything = 1;
						}
						pointer->output();
						std::cout << "<------------------------------------------------------>" << std::endl;
						found = 1;
					}
				}
			} break;
			case 3:
			{
				for (Student* pointer = first; pointer != nullptr; pointer = pointer->next)
				{
					if (pointer->middle_name == value)
					{
						if (!anything)
						{
							std::cout << "По запросу \"" << value << "\" найдено:" << std::endl;
							std::cout << "<------------------------------------------------------>" << std::endl;
							anything = 1;
						}
						pointer->output();
						std::cout << "<------------------------------------------------------>" << std::endl;
						found = 1;
					}
				}
			} break;
			case 4:
			{
				for (Student* pointer = first; pointer != nullptr; pointer = pointer->next)
				{
					if (std::to_string(pointer->age) == value)
					{
						if (!anything)
						{
							std::cout << "По запросу \"" << value << "\" найдено:" << std::endl;
							std::cout << "<------------------------------------------------------>" << std::endl;
							anything = 1;
						}
						pointer->output();
						std::cout << "<------------------------------------------------------>" << std::endl;
						found = 1;
					}
				}
			} break;
			case 5:
			{
				for (Student* pointer = first; pointer != nullptr; pointer = pointer->next)
				{
					if (std::to_string(pointer->year_admission) == value)
					{
						if (!anything)
						{
							std::cout << "По запросу \"" << value << "\" найдено:" << std::endl;
							std::cout << "<------------------------------------------------------>" << std::endl;
							anything = 1;
						}
						pointer->output();
						std::cout << "<------------------------------------------------------>" << std::endl;
						found = 1;
					}
				}
			} break;
			case 6:
			{
				for (Student* pointer = first; pointer != nullptr; pointer = pointer->next)
				{
					if (std::to_string(pointer->average_score) == value)
					{
						if (!anything)
						{
							std::cout << "По запросу \"" << value << "\" найдено:" << std::endl;
							std::cout << "<------------------------------------------------------>" << std::endl;
							anything = 1;
						}
						pointer->output();
						std::cout << "<------------------------------------------------------>" << std::endl;
						found = 1;
					}
				}
			}
			default: std::cout << "Неверный запрос" << std::endl;
			}
		}
		return found;
	}
	void output()
	{
		for (Student* pointer = first; pointer != nullptr; pointer = pointer->next)
		{
			pointer->output();
		}
		return;
	}
	~List()
	{
		if (is_empty())
		{
			return;
		}
		Student* pointer2 = nullptr;
		for (Student* pointer = first; pointer2 != nullptr; pointer = pointer2->next)
		{
			pointer2 = pointer->next;
			delete pointer;
		}
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	printf("Задание 1,2\n");
	const int max_size = 10;
	int array[max_size];
	for (int counter = 0; counter < max_size; ++counter)
	{
		array[counter] = rand() % 200 - 100;
		printf("%d ", array[counter]);
	}
	printf("\n");
	int max_element = 0;
	int min_element = 0;
	for (int counter = 0; counter < max_size; ++counter)
	{
		if (array[max_element] < array[counter])
		{
			max_element = counter;
		}
		if (array[min_element] > array[counter])
		{
			min_element = counter;
		}
	}
	printf("Разница между %d и %d = %d\n", array[max_element], array[min_element], (array[max_element] - array[min_element]));

	printf("\nЗадание 3,4\n");
	int ROWS = 0, COLS = 0;
	std::cout << "Введите количество строк: ";
	std::cin >> ROWS;
	std::cout << "Введите количество столбцов: ";
	std::cin >> COLS;
	int** array2 = new int*[ROWS];
	for (int rows = 0; rows < ROWS; ++rows)
	{
		array2[rows] = new int[COLS];
	}
	for (int rows = 0; rows < ROWS; ++rows)
	{
		for (int cols = 0; cols < COLS; ++cols)
		{
			array2[rows][cols] = rand() % 200 - 100;
		}
	}

	for (int rows = 0; rows < ROWS; ++rows)
	{
		for (int cols = 0; cols < COLS; ++cols)
		{
			printf("%4d ", array2[rows][cols]);
		}
		printf("\n");
	}
	for (int rows = 0; rows < ROWS; ++rows)
	{
		int sum_value_in_row = 0;
		for (int cols = 0; cols < COLS; ++cols)
		{
			sum_value_in_row += array2[rows][cols];
		}
		printf("Сумма элементов строки [%d] = %d\n", rows, sum_value_in_row);
	}
	for (int cols = 0; cols < COLS; ++cols)
	{
		int sum_value_in_col = 0;
		for (int rows = 0; rows < ROWS; ++rows)
		{
			sum_value_in_col += array2[rows][cols];
		}
		printf("Сумма элементов столбца [%d] = %d\n", cols, sum_value_in_col);
	}
	for (int counter = 0; counter < ROWS; ++counter)delete[] array2[counter];
	delete[] array2;

	printf("Задание 5\n");

	std::cout << "Заполните список студентов:\n";
	List list;
	for (bool end = 0; !end; std::cout << "\nЗакончить ввод?\n", std::cin >> end)
	{
		list.add_back();
	}
	list.output();
	unsigned short int* type_search = new unsigned short int[6]{0, 0, 0, 0, 0, 0};
	unsigned short int* buffer = new unsigned short int(-1);
	int *counter = new int(0);
	std::cout << "По каким критериям произвести поиск?:\n1)Имя\n2)Фамилия\n3)Отчество\n4)Возраст\n5)Год поступления\n6)Средний балл\n0)Закончить ввод\n";
	while (*buffer != 0 && *counter < 6)
	{
		std::cin >> *buffer;
		type_search[*counter] = *buffer;
		(* counter)++;
	}
	delete buffer;
	std::string request = "Empty Line";
	std::cout << "Введите значение поиска : ";
	std::cin >> request;
	if (!list.Search_student(type_search, *counter, request))
	{	
		std::cout << "Ничего не найдено." << std::endl;
	}
	delete counter;
	delete[] type_search;
	return 0;
}

//Дописать поиск по нескольким критериям