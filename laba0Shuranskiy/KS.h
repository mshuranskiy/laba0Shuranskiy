#pragma once
#include <string>
#include <vector>
class KS
{
	static unsigned int IDks;
	std::string name;//Имя
	unsigned int id;//идентификатор
	int n;//Количество цехов
	int ninwork;//Количсевто цехов в работе
	int efect;//Эффективность
public:
	static KS creatKS();//Создание компрессорной станции
	friend void printKS(const KS& ks);//Вывод информации о компрессорной станции
	friend void editKS(KS& ks);//Изменение цоехов в работе
	friend void savefileKS(std::ofstream& fout, const KS& ks);//Сохранение информации о компрессорной станции
	static KS inputfileKS(std::ifstream& fin);//Считывание информации о компрессорной станции
	friend KS& selectKS(vector<KS>& Zavod);//Выбор компрессорной станции
	friend void deleteKS(vector<KS>& Zavod);//Удаление компрессорной станции
	friend bool SearchKSByName(const KS& ks, std::string parametr);//Поиск по имени
	friend bool SearchKSByNinwork(const KS& ks, double parametr);//Поиск по проценту не работающих цехов
};

