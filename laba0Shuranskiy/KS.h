#pragma once
#include <string>
class KS
{
	static unsigned int IDks;
	std::string name;//Имя
	unsigned int id;//идентификатор
	int n;//Количество цехов
	int ninwork;//Количсевто цехов в работе
	int efect;//Эффективность
public:
	friend KS creatKS();//Создание компрессорной станции
	friend void printKS(const KS& ks);//Вывод информации о компрессорной станции
	friend void editKS(KS& ks);//Изменение цоехов в работе
	friend void savefileKS(std::ofstream& fout, const KS& ks);//Сохранение информации о компрессорной станции
	friend KS inputfileKS(std::ifstream& fin);//Считывание информации о компрессорной станции
};

