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

ostream& operator << (ostream& out,const Truba& t)//����� ���������� � �����
{
	out << "������ � �����:\n";
	out << "id �����: " << t.id << endl;
	out << "id ������� ������������� �������: " << t.inputks << endl;
	out << "id �������� ������������� �������: " << t.outputks << endl;
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
	fout << inputks << endl;
	fout << outputks << endl;
	fout << name << endl;
	fout << dlina << endl;
	fout << diametr << endl;
	fout << sostoyanie << endl;
}

void Truba::inputfileTruba(std::ifstream& fin)//���������� ���������� � �����
{
	fin >> id;
	fin >> inputks;
	fin >> outputks;
	fin >> name;
	fin >> dlina;
	fin >> diametr;
	fin >> sostoyanie;
}

std::string Truba::getname()//����������� �����
{
	return name;
}

bool Truba::getsostoyanie()//���������� ���������
{
	return sostoyanie;
}

unsigned int Truba::getid()//����������� id
{
	return id;
}

void Truba::setinputks(unsigned int value)
{
	inputks = value;
}

void Truba::setoutputks(unsigned int value)
{
	outputks = value;
}

unsigned int Truba::getinputks()
{
	return inputks;
}

unsigned int Truba::getoutputks()
{
	return outputks;
}
