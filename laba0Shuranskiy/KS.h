#pragma once
#include <string>
#include <vector>
class KS
{
	static unsigned int IDks;
	unsigned int id;//�������������
	int efect;//�������������
public:
	std::string name;//���
	int n;//���������� �����
	int ninwork;//���������� ����� � ������
	friend std::istream& operator >> (std::istream& in, KS& ks);//�������� ������������� �������
	friend std::ostream& operator << (std::ostream& out, KS& ks);//����� ���������� � ������������� �������
	void editKS();//��������� ������ � ������
	void savefileKS(std::ofstream& fout);//���������� ���������� � ������������� �������
	void inputfileKS(std::ifstream& fin);//���������� ���������� � ������������� �������
};

