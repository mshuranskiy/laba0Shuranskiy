#pragma once
#include <string>
#include <iostream>
using namespace std;
template <typename T>
T getint(string text, T border1, T border2)
{
	T value;
	while (1)
	{
		cout << text << endl;
		cin >> value;
		if (cin.fail() || value < border1 || value >border2)
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Введённые данные не корректны. Попробуйте ещё раз.\n";
		}
		else
		{
			return value;
		}
	}
}
