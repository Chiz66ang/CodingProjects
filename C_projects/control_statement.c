#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Ű���忡�� ���� �Ѱ��� ���� �Ѱ��� �Է¹޾Ƽ� �α����� �����Ѵ�
���ڴ� �̿����� id�� �����ϰ�, ���ڴ� ��ȣ�� �����Ѵ�.
���̵� B�̰� ��ȣ�� 2222�� �̿��ڸ� �α��� ���� �޽����� ����ϰ�
�α��ο� ������ �̿��ڿ��Դ� �α��� ���� �޽����� ǥ���Ѵ�*/

void login(char id, int pw)
{/*
	char* result;
	if ((id == 'B') && (pw == 2222)) result = "�α��� ����";
	else result = "�α��� ����";
	printf("%s \n", result);
	*/
}

int add(int a)
{
	/*������ ������ switch �Լ��� ǥ���غ��ÿ�
	int sum = 0;
	switch (a)
	{
	case 1: sum += 1;  //�帧�� ���� �� ���
	case 2: sum += 2; 
	case 3: sum += 3; 
	case 4: sum += 4; 
	case 5: sum += 5; 
	case 6: sum += 6; 
	case 7: sum += 7; 
	case 8: sum += 8; 
	case 9: sum += 9; 
	case 10: sum += 10;
	}

	return sum; */
}

char* day(int wday)
{ /*������ ������ switch �Լ��� ǥ���غ��ÿ�
	char* sday; //static�� ��� �� ���� �ϰų� ���� �ʾƵ� �Ǳ� ����
	switch (wday)
	{
	case 0: sday = "��"; break;
	case 1: sday = "��"; break;
	case 2: sday = "ȭ"; break;
	case 3: sday = "��"; break;
	case 4: sday = "��"; break;
	case 5: sday = "��"; break;
	case 6: sday = "��"; break;
	}
	
	return sday;
	*/
}
int main()
{
	/*������ ������ switch �������� �ذ��غ�����

	time_t tm_t = time(0);
	struct tm* ptm = localtime(&tm_t);
	int wday = ptm->tm_wday;


	char* sday = day(wday);
	printf("������ %s ���� �Դϴ�. \n", sday);
	*/

	/*�ð� ���ϱ�
	time_t tm_t = time(0);
	struct tm* ptm = localtime(&tm_t);
	int wday = ptm->tm_wday;
	//�̰� time����ϰ� �䱸�ϴ� ��ɾ� ���� �ϱ�
	//char* sday;


	if		(wday == 2) wday = "ȭ"; //sday =ȭ
	else if (wday == 3) wday = "��"; //0= �Ͽ��� �����ؼ� ���� ���� ��.

	printf("������: %s �����Դϴ� \n", wday); //sday
	wday�������� int (����)�� ������ ���־��� ������ char*�� �Ἥ ���� ������ �ٽ� �������ִ� ���� �Ǵ�.
	*/

	/*�α��� ����
	
	char id;
	int pw;
	printf("���̵�� ��й�ȣ�� �Է��ϼ���: \n");
	scanf("%c", &id);
	scanf("%d", &pw); //���ڿ� ���ڸ� ��� id�� �ν� �ؼ� ���� �����ϱ� �ȵž���. �̷��� �и��س����� ��
	login(id, pw);
	*/
	
	


	//��� (Control Statment)

	/*������ �ΰ��� �� ���� �����ڸ� ������, if�����ε� �����Ҵ�.
	srand (time(0));
	int rd = rand();
	char* res = (rd % 2 == 0) ? "¦��" : "Ȧ��";

	printf("res: %s \n", res);

	char* result;
	if (rd % 2 == 0) result = "¦��";
	else result = "Ȧ��";
	printf("result: %s \n", result);
	*/

	/*switch ����
	int a = 1;
	switch (a)
	{
	case 0: printf("0�Դϴ�. \n");
	case 1: printf("1�Դϴ�. \n");
	case 2: printf("2�Դϴ�. \n");
	case 3: printf("3�Դϴ�. \n");
	default: printf("�� ���� \n");
	}
	*/

	/*switch ����
	//Ű���忡�� �Էµ� ���� �Լ��� �����ϸ� �� �Լ��� �޾Ƶ��� ������ 10���� �ջ��� ����� �����ϴ� ����� �ۼ��غ�����
	
	printf("���� �Է��ϼ���: \n");
	int a;
	scanf("%d", &a);
	int sum = add(a);
	printf("%d~10���� �ջ��� ���: %d \n", a, sum);
	*/

	

	printf("���α׷� ����... \n");
	return 0;
}