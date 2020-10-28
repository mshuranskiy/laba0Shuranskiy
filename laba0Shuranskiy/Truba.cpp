#include "Truba.h"
#include "utils.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

unsigned int Truba::IDt = 0;

Truba Truba::creatTruba()//Создание трубы
{
	Truba t;
	t.id = ++Truba::IDt;
	cout << "Введите имя трубы\n";
	cin.get();
	getline(cin, t.name);
	t.dlina = getint("Введите длину трубы (Еденица измерения: м)", 1.0, 10000.0);
	t.diametr = getint("Введите диаметр трубы(Еденица измерения : мм)", 1, 10000);
	t.sostoyanie = false;
	return t;
}

void printTruba(const Truba& t)//Вывод информации о трубе
{
	cout << "Данные о трубе:\n";
	cout << "Имя трубы: " << t.name << endl;
	cout << "Длина трубы: " << t.dlina << " (м)" << endl;
	cout << "Диаметр турбы: " << t.diametr << " (мм)" << endl;
	cout << "Состояние трубы: " << (t.sostoyanie ? "В ремонте\n" : "Не в ремонте\n");
}

void editTruba(Truba& t)//Отправить трубу в ремонт
{
	t.sostoyanie = !t.sostoyanie;
}

void savefileTruba(std::ofstream& fout, const Truba& t)//Сохранение информации о трубе
{
	fout << t.id << endl;
	fout << t.name << endl;
	fout << t.dlina << endl;
	fout << t.diametr << endl;
	fout << t.sostoyanie << endl;
}

Truba Truba::inputfileTruba(std::ifstream& fin)//Считывание информации о трубе
{
	Truba t;
	fin >> t.id;
	fin >> t.name;
	fin >> t.dlina;
	fin >> t.diametr;
	fin >> t.sostoyanie;
	return t;
}

Truba& selectTruba(vector<Truba>& Truboprovod)//Выбираем нужную трубу
{
	unsigned int index = getint("Введите номер трубы", (size_t)1u, Truboprovod.size());
	return Truboprovod[index - 1];
}

void deleteTruba(vector<Truba>& Truboprovod)//Удаление трубы
{
	unsigned int index = getint("Введите номер трубы", (size_t)1u, Truboprovod.size());
	Truboprovod.erase(Truboprovod.begin() + index - 1);
}

bool SearchTrubaByName(const Truba& t, std::string parametr)//Поиск по имени
{
	return t.name == parametr;
}

bool SearchTrubaBySostoyanie(const Truba& t, bool parametr)//Поиск по стостоянию
{
	return t.sostoyanie == parametr;
}