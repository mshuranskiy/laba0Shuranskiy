#include"GTS.h"
#include<set>
#include<map>
#include<vector>


void GTS::editGTS(map<int, Truba>& Truboprovod)
{
	while (true)
	{
		cout << "1-��������� ������������� �������\n";
		cout << "0-�����\n";
		int i = getint("������� ����� ��������", 0, 1);
		switch (i)
		{
		case 1:
		{
			unsigned int ks = getint("������� id ������ ������������ �������", 0u, KS::IDks);
			idks.insert(ks);
			unsigned int t;
			while (true)
			{
				t = getint("������� id ����� ������� ����� ��������� ������������� �������", 0u, Truba::IDt);
				if (Truboprovod[t].getinputks() == 0 && Truboprovod[t].getoutputks() == 0)
					break;
				else
					cout << "������ ����� ��� �������������\n";
			}
			idt.insert(t);
			Truboprovod[t].setinputks(ks);
			unsigned int ks1;
			while (true)
			{
				ks1 = getint("������� id ������ ������������ �������", 0u, KS::IDks);
				if (ks1 != ks)
					break;
				else
					cout << "���� �������������� ������� �� ����� ���� ������ � �������";
			}
			idks.insert(ks1);
			Truboprovod[t].setoutputks(ks1);
			break;
		}
		case 0:
		{
			return;
		}
		default:
		{
			cout << "������ ������� �� ���������. ���������� ��� ���.\n";
		}
		}
	}
}

void GTS::savefilegts(std::ofstream& fout)
{
	if (idks.size() > 0)
	{
		for (auto& n : idks)
		{
			fout << n << endl;
		}
	}
	if (idks.size() > 0)
	{
		for (auto& n : idt)
		{
			fout << n << endl;
		}
	}
}

int GTS::inputfilegts(std::ifstream& fin)
{
	int n;
	fin >> n;
	return n;
}

int** GTS::creatematrix(int n)
{
	matrix = new int* [n]();
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[n]();
	}
	return matrix;
}

void GTS::deletematrix(int n)
{
	for (int i = 0; i < n; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

void GTS::editmatrix(map<int, Truba>& Truboprovod)
{
	vector<unsigned int> sortedidks;
	for (auto& v : idks)
	{
		sortedidks.push_back(v);
	}
	int n = idks.size();
	for (auto& infotruba : Truboprovod)
	{
		int first = -1;
		int second = -1;
		for (int i = 0; i < n; i++)
		{
			if (infotruba.second.getinputks() == sortedidks[i])
				first = i;
		}
		for (int i = 0; i < n; i++)
		{
			if (infotruba.second.getoutputks() == sortedidks[i])
				second = i;
		}
		if (first > -1 && second > -1)
			matrix[first][second] = 1;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matrix[i][j];
		}
		cout << endl;
	}
}

vector<unsigned int> GTS::tgtssort(map<int, Truba>& Truboprovod)
{
	vector<unsigned int> sorted;
	vector<unsigned int> vks;
	for (auto& v : idks)
	{
		vks.push_back(v);
	}
	int n = idks.size();
	matrix = creatematrix(n);
	editmatrix(Truboprovod);
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			int sum = 0;
			for (int j = 0; j < n; j++)
			{
				sum += matrix[i][j];
			}
			if (sum == 0)
			{
				sorted.push_back(vks[i]);
				for (int j = 0; j < n; j++)
				{
					matrix[j][i] = 0;
				}
				matrix[i][i] = 1;
			}
		}
		/*for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << matrix[i][j];
			}
			cout << endl;
		}*/
	}
	
	deletematrix(n);
	reverse(sorted.begin(), sorted.end());
	return sorted;
}

void GTS::deleteidks(int value)
{
	idks.erase(idks.find(value));
}

set<int> GTS::getidks()
{
	return idks;
}

set<int> GTS::getidt()
{
	return idt;
}

void GTS::setidks(int value)
{
	idks.insert(value);
}

void GTS::setidt(int value)
{
	idt.insert(value);
}
