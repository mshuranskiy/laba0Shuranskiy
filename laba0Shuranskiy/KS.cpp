#include "KS.h"
#include <iostream>
#include <fstream>
#include "utils.h"
#include <string>

unsigned int KS::IDks = 0;

istream& operator >> (istream& in, KS& ks)//�������� ������������� �������
{
	ks.id = ++KS::IDks;
	cout << "������� ��� ������������� �������\n";
	cin.get();
	getline(cin, ks.name);
	ks.n = getint("������� ���������� �����", 1, 10000);
	ks.ninwork = getint("������� ���������� ����� � ������", 0, ks.n);
	ks.efect = getint("������� ������������� ������������� �������� (������������� ���������� �� 10-�� ������� �����)", 0, 10000);
	return in;

}

ostream& operator << (ostream& out, KS& ks)//����� ���������� � ������������� �������
{
	out << "������ � ������������� �������:\n";
	out << "��� ������������� �������: " << ks.name << endl;
	out << "���������� ����� �� ������������� �������: " << ks.n << endl;
	out << "���������� ����� � ������: " << ks.ninwork << endl;
	out << "������������� ������������� �������: " << ks.efect << endl;
	return out;
}

void KS::editKS()//��������� ������ � ������
{
	ninwork = getint("������� ���������� ����� � ������", 0, n);
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

