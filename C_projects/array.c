#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int find_max(int* arr, int size) //�ִ밪 ���ϱ� ����
{/*
	int max = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > max) max = arr[i];
	}
*/
}

int* creat_arr(int size)
{
	/* �迭������ �����Ҵ�
	//int arr[size] -->�̰� runtime �� �Ҵ�Ǿ �ȉ�. (�����Ҵ�)
	//�̷� �� ���� �Ҵ��� ����
	
	int *arr = malloc(size); //�����Ҵ�
	for (int i = 0; i < size; i++)
	{
		arr[i] = i + 1; //���⼭ �迭 ���� arr�� ���� �־��� ��
	}
	return arr;
	*/
}

void swap(int arr[], int size)
{
	/*
	for (int i = 0; i < size / 2; i++) //i�� ������ ������ ���ư��� ����
	{
		tmp = arr[i];
		arr[i] = arr[size - i];
		arr[size - 1] = tmp;
	}
	*/
}


//call by value�� call by reference
void change(int i) //arguement�� �޴� ��: parameter
{
	//i = i + 10;
	//printf("change()���� i= %d \n", i); //10
	//���⿡���� ���� i���� �ƴ϶� 0�̶�� ���� ���簡 �Ǿ� �� ���̱� ������ main�Լ����� i�� print���� ��, int i = 0�̶�� ���� ������ �ʾұ� ������ 0���� ��µǴ� ���̴�.

}

//call by value�� call by reference
void change2(int* ip) //parameter�� �����Ͱ� �����
{
	//*ip = *ip + 10;
	//printf("change2()���� ip= %d \n", *ip);
	//���⼭ *ip�� i������ ����. �׷��Ƿ� i������ ���� �Լ��� ���� ó��/����ȴ�. �׷��� main �Լ����� print���� �� i�� ���� ����Ǵ� ���̴�.
}

void chgadd(int**p)// p�� ������ �ι� �������ϸ� ������ ��������
{
	/*
	static int i = 10;//static (�Լ��� ������ �������� �ʴ´�)
	*p = &i; //*p�� main�� �ִ� p�� ����.
	*/
}



int main()
{
	//5���� ��ħ ����
	//Ű���忡�� ���ڿ��� �Է� �ޱ�
	//���ڿ��� ���ҷ� �ϴ� �迭
	//ȸ�� 5���� �̸��� �迭�� �����ϰ� ȭ�鿡 ǥ���غ�����


	/*char name[5][30];//30 ũ���� ���� �迭�� 5�� �����ض�~ 

	for (int i =0; i < 5; i++)
	{
		printf("�̸��� �Է��ϼ���:");
		scanf("%s", name[i]); //name�� ġ�� �迭�� ù��° �ּҸ� ����Ű�� �ֱ� ������ ù��° ���ҿ��� ���ο� ������ ����ǰ� �ִ� ���̾ name[i]��� �ؼ� ���� �Է� ���� ���� �迭�� ������ �� �ֵ��� ������Ѵ�.
	}

	for (int i = 0; i < 5; i++)
	{
		printf("�Էµ� �̸���: %s \n", name[i]);
	}
	*/
	/*������ ����
	char* name[] = { ����, ����, ���� }; //"����" "����" "����"��� ���ڿ��� �ִ� �ּҰ� ����Ǿ��ִ� ������ ������ ���� �� char*[]. �� ���ÿ��� �̰ɾ��� ������.. �ֳ�? ��Ʈ�� �����ִ� id ���� ����.
	for (int i = 0; i < sizeof(name) / sizeof(char*); i++)
	{
		printf("%d. %s \n", i + 1, name[i]);
	}
	*/

	/*Ű���忡�� ���ڿ��� �Է� �ޱ�
	printf("�̸��� �Է��ϼ���:");
	//char* name = NULL; --> ������ ����
	char name[20]; --> ������ ���� �ʴ´�. ������ ���� ����
	scanf("%s", name);
	printf("�Էµ� �̸���: %s \n", name);
	*/

	/*
	//Ű���忡�� �Էµ� ���ڿ��� ���� ���о��� �� �� ��ü �б�
	// �̸� ��ȣ ��ȭ��ȣ<enter>ġ�� 3���� ���� ��� �б� (scanf�� �����̽� ġ�� ù�ڷḸ �о�´�)
	//gets()�Լ��� �̿��Ͽ� �� ���� ��ü�� �Է¹޾� ǥ���غ�����
	char info [50];
	printf("�̸� ��ȣ ��ȭ��ȣ�� �Է��ϼ���:");
	gets_s(info, 50); //���� �Է�
	//puts(info); //���� ��� (�� ������ ���)
	//printf("����� ������: %s", info); (������ ���� �پ��� ������ ���� ����� �� �ִ�)
	

	//Ű���忡�� �Է¹޴� ���ɾ� scanf
	//���ڿ����� �Է¹޴� ���ɾ� sscanf (���ڿ��� �� �������� ���� ���� �з����ִ� �Լ�)
	//sscanf (string scanf) �Ἥ ���� ������ �� ��ū���� �з��غ���
	char name [20];
	int num;
	int num2;
	sscanf(info, "%s %d %d", name, &num, &num2); //�̸� ��ȣ ��ȭ��ȣ�� ���ڿ�, ����, ������ �и��Ͽ� name, num, num2�� �ּҿ� �����϶�.
	printf("�̸�: %s ��ȭ��ȣ:%d ��ȣ:%d", name, num2, num);
	*/


	//����: ������ ������ �� �����ڷ� ����(�����̽���)�� ���⺸�� | �̷� ��ȣ�� ���־���
	/* strtok( string token) ���ڿ� �ӿ��� �ּ� �ǹ̸� ���� �ܾ ã�Ƴ���
	char str[30] = "����|3|241355";
	char* field[] = { "�̸�", "��ȣ", "�ּ�" };
	char* prt= strtok(str, "|");
	
	for(int i =0; prt!=NULL ;i++)
	{
		printf("%s\t%s \n", field[i], prt);
		prt = strtok(NULL, "|"); //�̰� �׳� �̷� ����
	}
	*/

	



	//���ڹ迭(���ڿ�) �ٷ��
	//char str[] = { 'H', 'e', 'l', 'l', 'o', '\0'};
	//printf("%s \n", str); //'\0'�� ���� ������ ���� �迭�� ���� �ν����� ���ϰ� �߰����� ������ ���ڵ鵵 ����Ѵ�.
	//'\0'�� ���� �迭�� �������� �˷��ش�. (c��� ������ �׷�)
	//char str[] = "Hello"; //""�� �Ἥ ���ڿ��� �־��ָ�, \0�� �ڵ����� ���Ե� �ų� �������� 
	//printf("%c", str[0]); //����� H //�̰͵� �迭�̴� ������ �������ָ� �ϳ��� ��°���
	//str[0] = 'h'; //���Ҹ� �����Ͽ� �ٸ� ���� ���������� �����ϰ� ����� �� �ִ�.
	//printf("%c", str[0]); //����� h
	//�迭 ������ ������ ��������� ���ڿ��� ����� �ƴϴ� (�� ���ҿ� ������) �ٲ� �� �ִ�.//�迭 ������ ������ ���

	//char* str = "Hello";
	//�����ͷ� ����� ���ڿ��� ������� ������ �� ����. ������ str�� �������� ���� �����ϴ� (�ٸ� �ּҸ� ���� �� �ִ�).
	//"Hello"�� ���ڿ� ���
	//str[0] = 'h';
	//printf("%s \n", str); //���α׷��� ���ư��� �ʰ� ����. ������� ��.
	//str�� ������ �ִ� ���ڿ� ���� �Ұ� (const char* str = "Hello")�� ����.

	//str = "World";
	//printf("%s \n", str); //world��� �� ��µȴ�.
	//char str2[6];//������ ��� (�� �Ѱ��Ѱ��� ��ĥ �� ������ �������� �ּҸ� �ٲ� �� ����)
	//str2[0] = 'H';

	//char* str2 = "Hello";

	//printf("%d %d \n", str, str2);
	//str�� str2�� �ּҰ� ����. "Hello"�� �ΰ��� �ƴ� ������ ���̴�. 

	//c��� ���ڿ� �Լ� string.h �̿� ����
	//char dest[20];
	//strcpy(dest,"Hello"); //���ڿ� copy(����) string copy //ù��°�� 
	//"Hello"(�ҽ�)�� dest�� "Hello"��� ���ڿ� ����� �����϶�.
	//printf("dest = %s \n", dest); ����� Hello

	//���ڿ� �Լ� ����
	/*strcat(str1,str2) ���ڿ��� �����϶�� �Լ�
	char dest[20] = "Hello";
	char* cnt = "World";
	strcat_s (dest,cnt, 20);
	printf("%s \n", dest);
	*/

	//strcmp(str1, str2) 
	//string compare : str1 �� str2�� ���϶�. 
	//���� �� �ִ� ��: 0 (���ڿ��� ������ ��ġ), 1(������ �� ū ���ڿ��̸�: ascii�ڵ忡�� �� ū ��(������ ���ʿ� ���´�), -1 (������ �� ���� ���ڿ��̸�: ascii�ڵ忡�� �� ���� �� (������ ���ʿ� ����)




	/*������ ������ ���� �Լ����� �ٲٴ� ���� call by reference ������ ����
	int a = 5;
	int* p = &a;
	printf("*p=%d \n", *p);// = 5

	//���� ���� ������ ���� �Լ��� ȣ���Ͽ� p�� �ּҸ� �ٸ� �ּҷ� �����غ�����.
	//����� 10�� �������� �غ�����

	chgadd(&p); //call by reference (p�� ����մ� �ּҸ� �ٲ��ִ� ��)
	printf("*p=%d \n", *p);
	*/

	/*�����Ϳ� �迭
	int arr[] = { 1,2,3,4,5 }; //4byte������ 5�� �ִ°�. �ּҴ� byte���� �����ϱ� �ּҵ� 20���� ������.
	//ù ������ �ּҸ� �˸�, ������ �迭�� �ּҵ� �� �� �ִ�. (��¥�� ���������� ������ ����)
	// arr[0] = 1�� �ִ� �ּ�

	printf("%d", *(arr + 0)); //*(arr+0) �� ���� ��� = arr[0] �迭�� �����ϴ� ���İ� ���ƺ������� ���� ��ҿ� ���� �ǹ̰� �ٲ��
	printf("%d", *(arr + 1)); //arr[1]
	printf("%d", *(arr + 2)); //arr[2]
	printf("%d", *(arr + 3)); //arr[3]
	printf("%d", *(arr + 4)); //arr[4]
	*/

	/*������ �迭
	int score[2][3]  = { //2�����迭 (1���� �迭�� ���ҷ� �Ŵ��� �迭�̴�~) //score[]�迭�� ����ִ� �ּҴ� �� ù��° �ּ� {1}�� ����ִ� �ּ�
		{1,2,3}, //�̰� �ϳ��� ���� �迭
		{4,5,6}  // {��ü= �迭�� �迭}
	}; //--> �� 3��(������ �迭��)�� ������ �ִ� �迭�� 2�� (�� �� ���� 6��)
	//e.g.�� ���� �л��� �� ���� ����
	//���� ���ϰ� ������ ������ ������ �޸𸮿��� {1,2,3},{4,5,6}�̷������� �� �̾����ִ�.
	
	//score[0][0] = 10; //score �迭�� 1��° ���ҿ� �ִ� 1��° ��
	//score[0][1] = 20;
	//score[0][2] = 30;
	//score[1][0] = 40;
	//score[1][1] = 50;
	*/

	//������ �迭 ����
	/*���� ���ҵ��� ������ ������ Ȱ���Ͽ� ��� ǥ���غ�����

	int* b = score;
	for (int i = 0 ;i<6 ;i++) //i<6�� 2*3�� �� ������ ����
	{
		printf("%d", *(b + i));
	}
	*/

	//������ �迭 (�����͸� ���ҷ� �ϴ� �迭: �ּҸ� ��� �ִ� �迭), ���� �迭 (������ ���ҷ� �ϴ� �迭)
	//���� ������ �ּҸ� ���ҷ� �ϴ� �迭
	/*
	int* parr[3]; //int* ���� ������ �ּҸ� parr[3] 3�� ������ �迭�� �����ϰڴ�.
	int a, b, c;
	parr[0] = &a; //ù ���ҿ��� a�� �ּҸ� �ִ´�
	parr[1] = &b;
	parr[2] = &c;

	a = 1; //a�� 1�̶�� ���̴�
	b = 3;
	c = 6;
	*/
	//parr�迭�� �̿��Ͽ� a,b,c�� ����� ���� ǥ���غ�����.
	
	/*for (int i = 0; i < 3; i++)
	{
		printf("%d \t", *parr[i]); //parr[i]��� ǥ�� ��ü�� �ּҸ� ã�ư��ڴٴ� �ǹ�. �̹� �ּҸ� ã�ư����� *�� �ѹ� �ٿ��� �� �ּ��� ���� ã�ư���.
	}
	*/
	//�� �ٸ� ǥ��: printf("%d", **parr); ���⼭�� parr�� ������ *parr�� �ּҸ� �����ϰ� �� ���� �����ϱ� ���� **parr�� ���ش�.
	
	


	/*�����Ҵ� �迭����
	int *arr = creat_arr(8);
	for (int i = 0; i < 8; i++)
	{
		printf("%d ", arr[i]);
	}
	//�������� �Ҵ� ������ �޸𸮸� �ʼ������� ����������Ѵ�.

	free(arr); //�����Ҵ� �޸� ����
	*/

	//�迭 ������ ���� �Ҵ� ����
	//1~5���� ������ �迭�� �����ϰ� �� �迭�� �ٸ� �Լ��� �����ؼ� 
	//�������� �迭�� �����ϴ� �Լ��� �ۼ��غ�����.
	
	//���� ����
	//Call by value, Call by reference(address)
	/* call by value�� call by reference ����
	int i = 0;
	//change(i); //parameter�� �Ѿ�� ������ ��: argument //printf�ϸ� 0 --> �� �ٲ��� �ʾ�����? (call by value --> �����Լ������� ���� �ٲ� �� ����. �׷��� 0�� ���)

	change2(&i);
	printf("main()���� i= %d \n", i);
	*/



	//Array (�迭)
	/* int a, b, c; //3���� ���� ���� --> for loop ���� x
	a = 1;
	b = 2;
	c = 3;

	int arr[3]; //3���� ���� ���� --> for loop ���� ����
	//arr�� �迭 ����, ������ ���
	//������: �Ҵ�� �޸��� ù��° ������ �޸� �ּҸ� ������.
	//���: �ٸ� �޸��� �ּҸ� ���Ҵ� �� �� ������ �ǹ�
	//�迭 ���� ����
	 
	//�迭 ���� �ʱ�ȭ
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;
	*/
	//printf("arr: %d \n", arr);--> �޸� �ּҰ� ���´�. arr�޸� �ּҿ� �� ���� ���Ϸ��� ������(*arr)�� �ϰų�, arr[index ��]�� �ش�.
	//�� �ٸ� �迭 ���� �ʱ�ȭ ���
	//int nums[] = { 1,2,3 };
	//[3]�̶�� '���� 3���� Ȯ���ض�~'��� ������ ��� {}�ȿ� ���� ������ �����Ϸ��� �ڵ����� ��� ������ �����ϰ� {}�ȿ� ���� �־��ش�
	//�ǹ������� �� �Ⱦ��̰�, ������ �� ��
	//int num2[3] = { 0, };
	//[]�ȿ� �� ������ŭ ������ Ȯ���ϰ� �� ó���� ��(����)�� {}�� ���� ���� �ʱ�ȭ�ϰ�, ������ ��(����)���� ��ĭ(0)���� �ʱ�ȭ�϶�.

	// �迭�� ���� ũ��� �����Ͻ�(�ڵ��ϰ� ������ ��)�� ������ �� �־�� �Ѵ�. 
	/* ����: Ű����� �迭������ ũ�⸦ �����ϰ� �;���. 
	printf("������ ������ �Է��ϼ���:");
	int size;
	scanf("%d", &size);
	int nums[size]; �� �� �Ŀ� ������� �־�� �Ѵٴ� �޽����� �ߴµ�, �迭������ ���� ũ�Ⱑ ������ �� �������� �ʰ� runtime �� �����Ǳ� ������ �ȉ�.. c������.
	*/

	/*
	int a, b, c;
	a = 1;
	b = 2;
	c = 3;
	//-->���� for loop�� ���� ���� ���������� ���� �� �� ����.
	*/
	/*
	int arr[3];
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;

	for (int i = 0; i < 3; i++)
	{
		printf("d%", arr[i]);
	}
	*/

	/*�������� 10���� ���� �迭�� �غ��ϰ� ������ ���� �ʱ�ȭ�մϴ�.
	//��� ������ ���� �ִ밪�� ǥ���غ�����.
	//loop�� �ΰ��� �϶� (�ʱ�ȭ�ϴ� ����, ����ϴ� ����)
	int arr[10];
	srand(time(0));
	int max = 0;
	
	for (int i = 0; i < 10; i++)
	{
		arr[i] = rand() % 30 + 1;
	}							//�ʱ�ȭ �ϴ� ����

	for (int i = 0; i < 10; i++)
	{
		printf("%d \n", arr[i]); //�ƴϸ� *(arr*i) �׳� *arr�ϸ� ���� ù��° ���� �ҷ��´�.
		
	}							//����ϴ� ����

	for (int i = 0; i < 10; i++)
	{
		if (arr[i] > max) max = arr[i];
	}
	printf("�ִ밪: %d \n", max); //print�� �ѹ��� �ϸ� �Ǵϱ� �������� ���ְ�, max �˻�� ��� ������ ����� �ϴϱ� ������ �����ش�.
	*/

	/*swap �˰�����: �±�ȯ�ϴ� �˰�����
	int a = 1;
	int b = 2;
	a = b;
	b = a; �̰� ������ �ȵ�
	int tmp = a; //�ٸ� �޸� �������� a�� ���� ���� ������ b���� �ش�
	a = b;
	b = tmp;
	printf("a = %d \t b = %d \n", a, b);
	*/

	/* �迭���� ������
	int swap[] = { 1,2,3,4,5 };
	int tmp;

	for (int i = 0; i < 5 / 2; i++) //i�� ������ ������ ���ư��� ����
	{
		tmp = swap[i];
		swap[i] = swap[4 - i];
		swap[4 - 1] = tmp;
	}

	for (int i = 0; i < 5 / 2; i++)
	{
		printf("%d", swap[i]);
	}
	*/

	/* �迭���� �ִ밪 ���ϱ� ����
	int swap[] = { 1,2,3,4,5 };
	int max = find_max(swap, sizeof(swap) / sizeof(int));
	printf("�迭���� ���� �ִ밪:%d \n", max);
	*/



	return 0;
}