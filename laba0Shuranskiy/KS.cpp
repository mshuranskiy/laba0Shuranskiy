#include "KS.h"
#include <iostream>
#include <fstream>
#include "utils.h"
#include <string>

unsigned int KS::IDks = 0;

KS creatKS()//�������� ������������� �������
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

void savefileKS(ofstream& fout, const KS& ks)//���������� ���������� � ������������� �������
{
	fout << ks.id << endl;
	fout << ks.name << endl;
	fout << ks.n << endl;
	fout << ks.ninwork << endl;
	fout << ks.efect << endl;
}

KS inputfileKS(ifstream& fin)//���������� ���������� � ������������� �������
{
	KS ks;
	fin >> ks.id;
	fin >> ks.name;
	fin >> ks.n;
	fin >> ks.ninwork;
	fin >> ks.efect;
	return ks;
}