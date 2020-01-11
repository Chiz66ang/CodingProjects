#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	//�ڷᱸ���� �˰���
	/*5���� ���� ���Ҹ� ���� �迭�� �����ϰ� 
	������ ��(20����)�� ���Ҹ� �ʱ�ȭ�ϰ� ǥ���غ�����
	*/

	srand(time(0));
	int arr[5];
	int rd = 0;
	int i = 0;
	
	/*
	for (int i = 0; i < 5; i++)
	{
		rd = rand() % 20 + 1; //rd�� ������ ������ �� ����
		arr[i] = rd;
	}
	*/
	
	outer_loop: //Label
	while (i < 5)
	{
		rd = rand() % 20 + 1;
		for (int j = 0; j <= i; j++) //�ߺ� ���� ����
		{
			if (arr[j] == rd)//�ߺ��� ������ Ȯ��
			goto outer_loop; //Label. goto�� �� �Ⱦ���. �ظ��ϸ� ���� �� ��. 
		}
		arr[i++] = rd;
	}

	//������ ������ ���� ������ ������ �����Ѵ�.
	/*���� ���� (Selection Sort)
	int tmp = 0;
	for (int i = 0; i < 5 - 1; i++) //������ ���� ��
	{
		for (int j = i + 1; j < 5; j++) // ������ �� ������ �ִ� ��
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i]; //swap �˰���
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
	*/
	
	/* ��ǰ���� (Bubble Sort) 
	int temp = 0;
	for (int i = 4; i >=0 ; i--)
	{
		for (int j = 0; j < i ; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	*/

	//��������
	int end = sizeof(arr) / sizeof(int);
	int begin = 1;

	for (int i = begin; i < end; i++) //���������� ������ ���� ����
	{
		int temp = arr[i]; //���ذ�
		int idx = i; //���� ���ʰ�
		for (int j = i - 1; arr[j] > temp && j >= 0; j--)
		{
			arr[idx--] = arr[j]; //j�� ���� �����ʷ� �濡 �Ҵ��Ų��.
			arr[j] = temp;
		}
	}



	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << endl;
	}
	

	


	return 0;
}