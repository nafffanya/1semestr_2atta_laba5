#include <locale>
#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
	//����������� ���������


	//���� ������� ������� � ��������� �����
	//(���� ����� ������������ ����, �� ��������� �������������� � ���� �����������)
	cout << "������� ������ ������� N=";
	int(N);
	cin >> N;
	while (cin.fail() || N <0)
	{
		cin.clear();
		cin.ignore(32767, '\n');
		cout << ("\t�������� ����, ���������.(N>0)\n");
		cout << ("������ ������� N= ");
		cin >> N;
	}

	//���� ����� ������� ��������� �������� � ��������� �����
	cout << "������� ����� ������� ���������,min=";
	int mind;
	cin >> mind;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(32767, '\n');
		cout << ("\t�������� ����, ���������.\n");
		cin >> mind;
	}

	//���� ������ ������� ��������� �������� � ��������� �����
	cout << "������� ������ ������� ���������,max=";
	int maxd;
	cin >> maxd;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(32767, '\n');
		cout << ("\t�������� ����, ���������.\n");
		cin >> maxd;
	}
	cout << endl;

	//�������� ������������� �������
	int* arr = new int[N];

	//������ ��������� ����� ��� ������� rand()
	srand(time(0));

	// ����� �������� ������(��� ������� ���������)
	for (int i = 0; i < N; i++)
	{
		int temp = (double)rand() * (maxd - mind) / RAND_MAX + mind;
		while (temp == 0)
		{
			temp = (double)rand() * (maxd - mind) / RAND_MAX + mind;
		}
		arr[i] = temp;
	}

	//����� ������� �� �����
	cout << "�������� ������ :\n";

	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;


	//����������� ����������� �����
	//1)���������� �������� ������� ��������
	//2)� ����������� �� �������� ������� �������� �������� ���������� ��������

	bool flag = bool(arr[0]%2);
	int position = 0;

	if (flag)
	{
		for (int i = 1; i <= N-1; i+=2)
		{
			if (arr[i] % 2 == 0)
			{
				if(N>2)
				{ 
					if (arr[i + 1] % 2 == 1)
					{
						continue;
					}
					else
					{ 
						position = i + 2;
						break;
					}
				}
			}
			else
			{ 
				position = i+1;
				break;
			}
		}
	}
	else
	{
		for (int i = 1; i <= N - 1; i += 2)
		{
			if (arr[i] % 2 == 1)
			{
				if (N > 2)
				{
					if (arr[i + 1] % 2 == 0)
					{
						continue;
					}
					else
					{
						position = i + 2;
						break;
					}
				}
			}
			else
			{
				position = i+1;
				break;
			}
		}
	}

	//����� ����������
	if (position == 0)
	{
		cout << "����� � ������� ����������, 0";
	}
	else
	{
		cout << "����� �������� , ������� �������� ����������� , " << position;
	}

	//������������ ���������� ������ ��� ������������ ������
	delete []arr;

	//�������, ������� ��� ������� �� ����� ������ ����������
	//(�����, ����� ���� ����� �� �����������)
	_getch();
}
