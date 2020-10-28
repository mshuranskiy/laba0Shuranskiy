#include "Truba.h"
#include "utils.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

unsigned int Truba::IDt = 0;
istream& operator >> (istream& in, Truba& t)//�������� �����
{
	t.id = ++Truba::IDt;
	cout << "������� ��� �����\n";
	cin.get();
	getline(cin, t.name);
	t.dlina = getint("������� ����� ����� (������� ���������: �)", 1.0, 10000.0);
	t.diametr = getint("������� ������� �����(������� ��������� : ��)", 1, 10000);
	t.sostoyanie = false;
	return in;
}

ostream& operator << (ostream& out, Truba& t)//����� ���������� � �����
{
	out << "������ � �����:\n";
	out << "��� �����: " << t.name << endl;
	out << "����� �����: " << t.dlina << " (�)" << endl;
	out << "������� �����: " << t.diametr << " (��)" << endl;
	out << "��������� �����: " << (t.sostoyanie ? "� �������\n" : "�� � �������\n");
	return out;
}


void Truba::editTruba()//��������� ����� � ������
{
	sostoyanie = !sostoyanie;
}

void savefileTruba(std::ofstream& fout, const Truba& t)//���������� ���������� � �����
{
	fout << t.id << endl;
	fout << t.name << endl;
	fout << t.dlina << endl;
	fout << t.diametr << endl;
	fout << t.sostoyanie << endl;
}

Truba Truba::inputfileTruba(std::ifstream& fin)//���������� ���������� � �����
{
	Truba t;
	fin >> id;
	fin >> name;
	fin >> dlina;
	fin >> diametr;
	fin >> sostoyanie;
	return t;
}