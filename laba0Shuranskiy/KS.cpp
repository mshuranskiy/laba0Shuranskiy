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

void KS::savefileKS(std::ofstream& fout)//���������� ���������� � ������������� �������
{
	fout << id << endl;
	fout << name << endl;
	fout << n << endl;
	fout << ninwork << endl;
	fout << efect << endl;
}

void KS::inputfileKS(std::ifstream& fin)//���������� ���������� � ������������� �������
{
	fin >> id;
	fin >> name;
	fin >> n;
	fin >> ninwork;
	fin >> efect;
}