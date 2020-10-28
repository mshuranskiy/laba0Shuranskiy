#pragma once
#include <string>
class Truba
{
	static unsigned int IDt;
	unsigned int id;//Идентификатор
	std::string name;//Имя
	double dlina;//Длина
	int diametr;//Диаметр
	bool sostoyanie;//Состояние в ремонте или нет
public:
	static Truba creatTruba();//Создание трубы
	friend void printTruba(const Truba& t);//Вывод информации о трубе
	friend void editTruba(Truba& t);//Отправить трубу в ремонт
	friend void savefileTruba(std::ofstream& fout, const Truba& t);//Сохранение информации о трубе
	static Truba inputfileTruba(std::ifstream& fin);//Считывание информации о трубе
	friend Truba& selectTruba(vector<Truba>& Truboprovod);//Выбираем нужную трубу
	friend void deleteTruba(vector<Truba>& Truboprovod);//Удаление трубы
	friend bool SearchTrubaByName(const Truba& t, std::string parametr);//Поиск по имени
	friend bool SearchTrubaBySostoyanie(const Truba& t, bool parametr);//Поиск по стостоянию
};

