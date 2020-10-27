#pragma once
#include <string>
class Truba
{
	static unsigned int IDt;
	unsigned int id;//Идентификатор
	double dlina;//Длина
	int diametr;//Диаметр
	bool sostoyanie;//Состояние в ремонте или нет
public:
	friend Truba creatTruba();//Создание трубы
	friend void printTruba(const Truba& t);//Вывод информации о трубе
	friend void editTruba(Truba& t);//Отправить трубу в ремонт
	friend void savefileTruba(std::ofstream& fout, const Truba& t);//Сохранение информации о трубе
	friend Truba inputfileTruba(std::ifstream& fin);//Считывание информации о трубе
};

