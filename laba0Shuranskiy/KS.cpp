#include "KS.h"
#include <iostream>
#include <fstream>
#include "utils.h"
#include <string>

unsigned int KS::IDks = 0;

KS KS::creatKS()//�������� ������������� �������
{
	KS ks;
	ks.id = ++KS::IDks;
	cout << "������� ��� ������������� �������\n";
	cin.get();
	getline(cin, ks.name);
	ks.n = getint("������� ���������� �����", 1, 10000);
	ks.ninwork = getint("������� ���������� ����� � ������", 0, ks.n);
	ks.efect = getint("������� ������������� ������������� �������� (������������� ���������� �� 10-�� ������� �����)", 0, 10000);
	return ks;
}

void printKS(const KS& ks)//����� ���������� � ������������� �������
{
	cout << "������ � ������������� �������:\n";
	cout << "��� ������������� �������: " << ks.name << endl;
	cout << "���������� ����� �� ������������� �������: " << ks.n << endl;
	cout << "���������� ����� � ������: " << ks.ninwork << endl;
	cout << "������������� ������������� �������: " << ks.efect << endl;
}

void editKS(KS& ks)//��������� ������ � ������
{
	ks.ninwork = getint("������� ���������� ����� � ������", 0, ks.n);
}

void savefileKS(std::ofstream& fout, const KS& ks)//���������� ���������� � ������������� �������
{
	fout << ks.id << endl;
	fout << ks.name << endl;
	fout << ks.n << endl;
	fout << ks.ninwork << endl;
	fout << ks.efect << endl;
}

KS KS::inputfileKS(std::ifstream& fin)//���������� ���������� � ������������� �������
{
	KS ks;
	fin >> ks.id;
	fin >> ks.name;
	fin >> ks.n;
	fin >> ks.ninwork;
	fin >> ks.efect;
	return ks;
}

KS& selectKS(vector<KS>& Zavod)//����� ������������� �������
{
	unsigned int index = getint("������� ����� ������������� �������", (size_t)1u, Zavod.size());
	return Zavod[index - 1];
}

void deleteKS(vector<KS>& Zavod)//�������� ������������� �������
{
	unsigned int index = getint("������� ����� �����", (size_t)1u, Zavod.size());
	Zavod.erase(Zavod.begin() + index - 1);
}

bool SearchKSByName(const KS& ks, std::string parametr)//����� �� �����
{
	return ks.name == parametr;
}

bool SearchKSByNinwork(const KS& ks, double parametr)//����� �� �������� �� ���������� �����
{
	return 1-ks.n/ks.ninwork >= parametr;
}