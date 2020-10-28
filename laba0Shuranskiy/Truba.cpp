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

void Truba::savefileTruba(std::ofstream& fout)//���������� ���������� � �����
{
	fout << id << endl;
	fout << name << endl;
	fout << dlina << endl;
	fout << diametr << endl;
	fout << sostoyanie << endl;
}

void Truba::inputfileTruba(std::ifstream& fin)//���������� ���������� � �����
{
	fin >> id;
	fin >> name;
	fin >> dlina;
	fin >> diametr;
	fin >> sostoyanie;
}