#pragma once
#include <string>
#include <iostream>
class Truba
{
	static unsigned int IDt;
	unsigned int id;//Идентификатор
	std::string name;//Имя
	double dlina;//Длина
	int diametr;//Диаметр
	bool sostoyanie;//Состояние в ремонте или нет
public:
	friend std::istream& operator >> (std::istream& in, Truba& t);//Создание трубы
	friend std::ostream& operator << (std::ostream& out, Truba& t);//Вывод информации о трубе
	void editTruba();//Отправить трубу в ремонт
	friend void savefileTruba(std::ofstream& fout, const Truba& t);//Сохранение информации о трубе
	Truba inputfileTruba(std::ifstream& fin);//Считывание информации о трубе
};

