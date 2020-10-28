#pragma once
#include <string>
#include <iostream>
class Truba
{
	static unsigned int IDt;
	unsigned int id;//Идентификатор
	double dlina;//Длина
	int diametr;//Диаметр
public:
	std::string name;//Имя
	bool sostoyanie;//Состояние в ремонте или нет
	friend std::istream& operator >> (std::istream& in, Truba& t);//Создание трубы
	friend std::ostream& operator << (std::ostream& out,const Truba& t);//Вывод информации о трубе
	void editTruba();//Отправить трубу в ремонт
	void savefileTruba(std::ofstream& fout);//Сохранение информации о трубе
	void inputfileTruba(std::ifstream& fin);//Считывание информации о трубе
};

