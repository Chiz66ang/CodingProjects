#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*struct Member
{
	char name[20];
	int num;
	char number[20];
	
};
struct Member mem;
*/

/*void print(struct Member* pmem) //struct Member mem�� ������ ����ü�� �� ����� �� (���� �����ؼ� ����ִ� call by value�ϱ�) �׷��� �޸𸮸� �Ƴ��� ȿ���� ���̱� ���� Member ��ü�� �ּҸ� �޴´ٴ� ���̴�.
{
		printf("�̸�\t%s \n", (*pmem).name); //�ּҸ� ������ ���� �������� �������� �ؾ��Ѵ�. (*pmem).name�̶� ǥ���� pmem->name �̶� ǥ�������ϴ�. ->��� ǥ���� �������� ����
		printf("��ȣ\t%d \n", (*pmem).num);
		printf("����ó\t%s \n", (*pmem).number);
		
	
}*/

/*struct Member get_member()
{
	
	struct Member mem;
	printf("��ȣ �̸� ��ȭ:");
	scanf("%d %s %s", &mem.num, mem.name, mem.number);
	return mem;
	
}*/

/*struct Member* get_member()
{
	static struct Member mem; //Ȥ�� �����Ҵ�
	struct Member* mem = malloc(sizeof(struct Member));
	printf("��ȣ �̸� ��ȭ:");
	scanf("%d %s %s", &(mem->num), mem->name, mem->number);
	return &mem;
	
}*/


//����ü

/*union Aniversary //�굵 (������ ����) �ڷ���. ������ ���� �� �ִ�.
	����ü�� ���� �������� ���� (������ ������ ����)
{
	char birth[16];
	char marriage[16]; 
	//������ ���ﰳ �־ ���� ũ�Ⱑ ū ������ ������ �����. ������ ��� �� ������ ������ 16���� ������ 16����Ʈ�� ����
	
};
*/
/*
����ü ����: �������, �����̳� ��ȥ����� �� �ϳ��� ������ֽø� �� �� ������ �����.
������ ����, ��ȥ������� ���� �� �� ���� ��Ȳ, ������ ������ ��� �غ��ؾ��ϴ� ��Ȳ���� ���δ�.
*/

/*struct Client
	
{
	int num;
	char name[20];
	union Aniversary ani; //��Ÿ�� ��������!
	char sel;
	
*/

/*struct GameItem
{
	char name[50];
	int power;
	int max;


};
*/
/*
 struct GameItem creat_item(char* item_name, int item_power, int item_max)
{
	struct GameItem gi;
	strcpy(gi.name, item_name);
	gi.power = item_power;
	gi.max = item_max;

	return gi;
}
 */
 /*
void print(struct GameItem* pgi, int a)
{
	for (int i = 0; i < 3; i++)
	{
		printf("�����\t%s \n", (pgi[i]).name);
		printf("���ط�\t%d \n", (pgi[i]).power);
		printf("�ִ���Ƚ��\t%d \n \n", (pgi[i]).max);
	}

}*/

int get_cnt()
{
	FILE* fp = fopen("D:\\test\\mem.txt", "r");
	char read[80];
	int cnt = 0;
	while (fscanf(fp, "%s", read) != -1)
	{
		cnt++;
	}
	fclose(fp);
	return cnt;
}

struct Member
{
	char name[20];
	int num;
	char tel[20];

};

struct Member* mem_load()
{
	FILE* fp = fopen("D:\\test\\mem.txt", "r");
	char read[80];
	int cnt = get_cnt();
	struct Member* list = malloc(sizeof(struct Member) * cnt);
	int i = 0;

	while (fscanf(fp, "%s", read) != -1)
	{
		char* name = strtok(read, "|");
		char* snum = strtok(NULL, "|");//�̸� ������
		char* tel = strtok(NULL, "|");//�� ������
		struct Member m;
		strcpy(m.name, name);
		strcpy(m.tel, tel);
		m.num = atoi(snum); //���ڿ�(�ƽ�Ű ����)�� ������ �ٲ��ִ� �Լ� atoi (ascii to intiger)
		list[i++] = m;
	}
	fclose(fp);
	return list;
}

void print_mlist(struct Member* list, int cnt)
{
	printf("ȸ�� ������: \n");
	for (int i = 0; i < cnt; i++)
	{
		printf("%s\t%d\t%s \n", list[i].name, list[i].num, list[i].tel);
	}
	free(list);
}

void mem_update (char* name, char* tel)
{
	struct Member* list = mem_load();
	int cnt = get_cnt();
	for (int i = 0; i < cnt; i++)
	{
		if (strcmp(list[i].name, name) == 0)
		{
			strcpy(list[i].tel, tel);
			break;
		}
	}

	FILE* fp = fopen("D:\\test\\mem.txt", "w");
	for (int i = 0; i < cnt; i++)
	{
		fprintf(fp, "%s|%d|%s\n", list[i].name, list[i].num, list[i].tel);
	}

	fclose(fp);
	free(list);
}

void mem_delete(char* name)
{
	int cnt = get_cnt();
	struct Member* list = mem_load;
	FILE* fp = fopen("D:\\test\\mem.txt", "w");
	for (int i = 0; i < cnt; i++)
	{
		if (strcmp(list[i].name, name) == 0)
		{
			continue; // �����̶�� ���ڿ��� �����ǰ� �������� �����ش�.
		}
		fprintf(fp, "%s|%d|%s\n", list[i].name, list[i].num, list[i].tel);
	}
	free(list);
	fclose(fp);
}

int main()
{ 
	//�Լ� ������
	//mem_update("�̸�","��ȭ��ȣ") --> �̸��� ��ġ�ϴ� ������ ã�� ��ȭ��ȣ�� �ٲ��
	//mem_delete("�̸�") --> �̸��� ���Ե� ������ ������

	mem_update("����", "01022223333");
	//6����
	/*6���� ���� ����
	GameItem ��ü�� �Ӽ����� �̸�, �Ŀ�, �ִ���Ƚ���� �ְ� 
	�̷��� �Ӽ��� ���� ���� �ٸ� ���� ������ 3���� ������ �����ϰ�
	�� ������ ������� �Լ��� �����Ͽ� ��� ���� �������� ������ ȭ�鿡 ǥ�õǵ��� �غ�����
	
	struct GameItem gi[3];

	//struct GameItem cry
	//strcpy(cry.name, "���¢��");
	//cry.power = 3
	//cry.max = 3  �̷��� ��� 3���� ����� ����Լ����� ����ϵ��� �Ѵ�.
	strcpy(gi[0].name, "���¢��");
	gi[0].power = 3;
	gi[0].max = 3;

	strcpy(gi[1].name, "����");
	gi[1].power = 1;
	gi[1].max = 5;

	strcpy(gi[2].name, "����");
	gi[2].power = 6;
	gi[2].max = 3;


	print(&gi);

	//struct GameItem gi[] = {cry, jump, slash}
	//print(gi, sizeof(gi)/sizeof(struct GameItem));// gi�� �� �����, ������ ũ��� �����ش� (�׷� �� struct GameItem�� ũ�Ⱑ ���´�)
	*/

	/*6���� ��������2
	������ GameItem ��ü�� 3�� �����ϸ鼭 ���� ������ �ڵ带 �ݺ��ߴµ� 
	�̷� ������ �ذ��ϱ� ���� �Լ��� �����ϰ�
	�� �Լ��� 3�� ȣ���Ͽ� ������ �ذ��Ϸ��� �Ѵ�.
	������ �̸�, �Ŀ�, ���Ƚ�� �̷��� ���� �Լ��� �����ؼ� GameItem ��ü�� ������ �� �ֵ��� �Լ��� ������ ������.
	

	struct GameItem gi[3];
	gi[0] = creat_item("���¢��", 3, 3);
	gi[1] = creat_item("����", 1, 5);
	gi[2] = creat_item("����", 6, 3);
	print(gi, sizeof(gi) / sizeof(struct GameItem));
	//�ݺ��Ǵ� �ڵ尡 ������ ���� ������ �� ����� �Լ��� �̿��Ͽ� �����ϰ� ������.
	*/
	
	/*6���� ���� �ٷ�� //��Ʈ ����*/

	/*FILE* fp = fopen("D:\\test\\smaple.txt", "a"); //������ ������ ����.. Ȯ���ڴ� �ʼ��� �ƴ�
	//w(����)���� ���� �ι� ������ �� ����Ⱑ �Ǿ� ������ �����ϰ� �ٽ� ����� ����
	//�߰��Ѵٴ� ���� a�� ���ش� (append)
	//�б� ���� r (read)
	fprintf(fp, "���Ͽ� ����\n");
	fprintf(fp, "%d��° ��\n", 2);
	fclose(fp);

	printf("���Ͽ� ���� ���� \n");*/


	/*���Ͽ� �ִ� ���� �޸𸮷� �ҷ��� ȭ�鿡 ǥ���غ��� (fscanfȰ��)
	FILE* fp = fopen("D:\\test\\smaple.txt", "r");
	char buf[32];
	//fscanf(fp, "%s", buf); --> ������ ������
	//fgets(buf, 32, fp); --> �� �� ��ü�� �о��
	while(fgets(buf, 32, fp) !=NULL)
	{ 
	printf("�о�� ���ڿ�: %s \n", buf); //����� "���Ͽ�" --> scanf�� �����̽��� ���е� �� ���ڿ��� �о���� ����.
	}
	printf("���� ��\n");
	*/

	/*6���� ���� ����
	Ű���忡�� ȸ���� �̸� ��ȣ ��ȭ�� �Է¹޾Ƽ�
	"ȫ�浿|11|010-3949-3492" ������ ���ڿ��� ������ �� ȭ�鿡 ǥ���غ�����.

	strcat, sprint���� �Լ��� ����ϸ� ���ڿ��� ������ �� �ִ�.
	*/

	/*
	char member [50];

	char name [10];
	int num;
	char tel [30];
	
	printf("ȸ���� �̸�, ��ȣ, ��ȭ�� �Է��ϼ���:");
	scanf("%s %d %s", name, &num, tel);
	sprintf(member, "%s|%d|%s\n", name, num, tel); //&num�� �ּ�, ���⼭�� ��
	printf("ȸ�� ����: %s \n", member);
	
	FILE* fp = fopen("D:\\test\\mem.txt", "a");
	//fprintf(), fputsf(): �ܼ��� ���ڿ� (������ �Ǿ��ִ� ���ڿ�)�� fputsf�� ���ϴ�.
	fputs(member,fp); //member�� �ִ� ���ڿ��� fp�� ���ڴ�~�̸��̾�.
	fclose(fp);

	printf("��� ���� \n");
	*/

	/*�޸��忡 �� �� �ҷ�����
	FILE* fp = fopen("D:\\test\\mem.txt", "r");
	char read[80];
	while (fscanf(fp, "%s", read) != -1) //fp������ %s�� ������ read�� �����϶�
	{
		printf("%s \n", read);
	};
	fclose(fp);
	//��Ÿ�� ��������..
	*/

	/*���Ͽ� �ִ� �ڷ� �˻��ϱ�
	strtok�� Ȱ���� �̸��� �˻��ϸ� �� ����� �ڷᰡ print�ǵ��� �϶�
	
	FILE* fp = fopen("D:\\test\\mem.txt", "r");
	char read[80];
	char found = 0;
	while (fscanf(fp, "%s", read) != -1) //������ ������ -1�� ������ -1���� �д´ٴ� ���� ������ ������ �аڴٴ� ��
	{
		char* name = strtok(read, "|");
		if (strcmp(name, "ũ��") == 0)
		{
			char*num = strtok(NULL, "|");
			char*tel = strtok(NULL, "|");
			printf("�˻��� ����: %s %s %s \n", name, num, tel);
			found = 1;
			break;
		}
		
	}

	//���� �˻����ж�� "�˻������ �����ϴ�" �޽����� ����Ѵ�.
	//if ������ ���ư����� �ȵ��ư����� Ȯ���ϴ� ����� �����ϰ� (flag ������ �д�) �� ����� Ȯ���ؾ��Ѵ�.
	//found ��� char ������ ����� �˻��� �Ǿ����� 1�� ����, �ƴϸ� 0�� ���� ������ �Ѵ��� �������� if�� �����ش�.
	if (!found) printf("�˻������ �����ϴ�"); //found�� false(0) ��� 
	fclose(fp);
	*/



	



	//���� ȸ���� ���� ������� ���� �Լ��� ���� �ҷ����� ��
	//int cnt = get_cnt();
	//printf("���� ȸ����: %d \n", cnt);

	//ȸ������ŭ ���ڿ� �迭�� �����ϰ�
	//���Ͽ� ����� ��� ȸ���� ������ �ε��Ͽ� (mem_load �Լ�)
	//����ü ��ü�� �ǰ� �Ѵ�. �׸��� �� ��ü���� �迭�� ����.
	//�迭�� �����ؼ� �� ������ ȭ�鿡 ǥ���غ�����.


	//struct Member* list = mem_load();
	//print_mlist(list, get_cnt());
	
	//���Ͽ� �ִ� �ڷ� �����ϱ�
	//��ũ�� �� �����͸� �� �� �޸𸮷� �Űܿ� ������ ������ ã�� �ٲ��ְ� �ٽ� w�� ������ش�.
	//������ ��ȭ��ȣ�� �ٲ㺸��

	/*for (int i = 0; i < cnt; i++) 
	{
		if (strcmp(list[i].name, "����") == 0)
		{
			strcpy(list[i].tel, "01022223333");
			break;
		}

	}

	FILE* fp = fopen("D:\\test\\mem.txt", "w");
	for (int i = 0; i < cnt; i++)
	{
		fprintf(fp, "%s|%d|%s\n", list[i].name, list[i].num, list[i].tel);
	}
	
	fclose(fp);
	free(list);
	*/

	// �� ��ü�� �Լ��� ���� update �Լ��� �����.

	/*Ư�� ȸ�� ���� Delete ����
	FILE* fp = fopen("D:\\test\\mem.txt", "w");
	for (int i = 0; i < cnt; i++)
	{
		if (strcmp(list[i].name, "����") == 0)
		{
			continue; // �����̶�� ���ڿ��� �����ǰ� �������� �����ش�.
		}
		fprintf(fp, "%s|%d|%s\n", list[i].name, list[i].num, list[i].tel);
	}
	*/

	//�Լ� ������
	//mem_updat("�̸�","��ȭ��ȣ") --> �̸��� ��ġ�ϴ� ������ ã�� ��ȭ��ȣ�� �ٲ��
	//mem_delete("�̸�") --> �̸��� ���Ե� ������ ������



	/* ����ü ����
	Ű���忡�� ��ȣ, �̸�, ��ȭ��ȣ�� �Է¹޾Ƽ� ����ü�� �ʱ�ȭ�ϰ�
	�� ����ü�� �ٸ� �Լ��� �����ؼ� (parameter list���ٰ� ����ü ������ �־��ش�)
	ȭ�鿡 ��� ������ ǥ�õǵ��� �غ�����
	

	printf("�̸��� �Է��ϼ���:");
	scanf("%s", mem.name);
	//Ű����� ���� ���ڿ��� ������ mem.name�� ����Ű�� ������ ���������� �־��~
	//strcpy(mem.email, "smith@daum.net") "smith@daum.net"�� �ִ� �ּҷΰ��� "smith@daum.net"�� �����ͼ� mem.email�� ���������� �־��~
	printf("��ȣ�� �Է��ϼ���:");
	scanf("%d", &mem.num);
	printf("��ȭ��ȣ�� �Է��ϼ���:");
	scanf("%s", mem.number);
	print(&mem); //-������ �����ͷ� �޾����� ���⼱ �ּҺ����� �ش�.
	*/

	/*����ü ����2
	get_member() �Լ��� ȣ���ϸ� ���� ���� Member ����ü�� ��ü�� �ǵ����ϰ�
	main()�Լ����� ���ϰ��� �޾Ƽ� ȭ�鿡 ������ ǥ���ϵ��� �غ�����.
	
	struct Member mem = get_member();
	printf("�̸�\t%s \n", mem.num);
	printf("��ȣ\t%s \n", mem.num);
	printf("����ó\t%s \n", mem.num);
	*/

	/*
	����ü ����3
	get_member() �Լ��� Member ����ü ��ü�� �ּҸ� �����Ͽ� 
	main()�Լ����� �޾Ƽ� ȸ�������� ǥ���ϴ� ����� �ۼ��غ�����
	

	struct Member* mem = get_mem_p();
	printf("�̸�\t%s \n", mem->num);
	printf("��ȣ\t%s \n", mem->num);
	printf("��4��ó\t%s \n", mem->num);
	*/

	/*
	����ü ���� 4
	Ű���忡�� ȸ�������� �ټ��� �Է��ϰ� (�迭,loop�� ���� ���� ��)
	Member �迭�� �����Ͽ�
	print_list() �Լ��� �迭�� �����ϸ� --> ���⼭�� ���ο��� ��
	��ü ȸ���� ������ ȭ�鿡 ǥ�õǵ��� �Ѵ�.
	
	 
	struct Member mem[5];//5���� �����Ѵٱ⺸�� �˳��� ���ڸ� �ָ� �ȴ�. //���� �Ҵ��� �ص� �ȴ�.
	int i = 0;
	int num;
	
	while (1)
	{ 
		printf("����(0), ��ȣ, �̸�, ����ó:");
		scanf("%d", &num);
		if (num == 0)
		{
			mem[i].num = 0;
			break;
		}
		mem[i].num = num;
		scanf("%s %s", mem[i].name, mem[i].number);
		i++;

	}

	i = 0;
	while (1)
	{
		if (mem[i].num == 0) break;
		printf("%d\t%s\t%s \n", mem[i].num, mem[i].name, mem[i].number);
		i++;
	}
	

	print�� �Լ��� �ۼ���
	void print_list(struct Member* list)
	{
	int i =0
	while (1)
	{
		if (list[i].num == 0) break;
		printf("%d\t%s\t%s \n", list[i].num, list[i].name, list[i].number);
		i++;
	}
	}
	*/

	//����ü(Structures): �������� ������ �Ѱ��� object(��ü)�� modeling(��ü�� �䳻����)�ϴ� ��
	//�ټ����� �ڷ����� �׷���� �Ѱ��� ��ü�� �𵨸��� �ڷᱸ��
	//��ü(Object, Instance): �繰 ��������� �Ӽ�, ����� ���� ��.
/*
	struct   --> ����ü�� �����Ѵ�
	{
		int num;
		char name[16];
		char email[16];
	}Member; --> ����ü ���� �̸�
	
	Member.
	*/

	/*
	struct Member //Member��� ���ο� �ڷ����� ������// �ڷ������δ� ���ο� ������ ���� �� �ִ�.
	{
		int num;
		char name[16];
		char email[16];
	};

	struct Member mem;//����ü�� ���Ե� �޸� �Ҵ�.
	//mem.email = "smith@daum.net"; --> ����
	//mem.email[0] = 's'; --> �̷��� �ϸ� s,m,i,t,h, ��� ��� �־���� ������ ���ŷ�
	strcpy(mem.email, "smith@daum.net") ; //--> ����ü �ȿ� �ִ� ���ڿ� �ʱ�ȭ�ϴ� ��
	strcpy(mem.name, "Mr.Smith"); //mem.email�� mem.name�� ������ �����̱� ������ �ּҸ� ���������� ���� �� �� ������ strcpy �Լ��� �Ἥ �־��ִ� ���̴�.
	mem.num = 11; //mem.num �� �׳� ���������� �ٷ� ���� ����
	//����ü ���� �ʱ�ȭ �Ϸ�

	printf("��ȣ\t%d \n", mem.num);
	printf("�̸�\t%s \n", mem.name);
	printf("�̸���\t%s \n", mem.email);
	*/

	/*����ü
	union Aniverary ani;
	strcpy(ani.birth, "2000-12-15");
	strcpy(ani.marriage, "2000-11-25");
	printf("������: %s \n", ani.birth); //����� ��ȥ ����� ��¥�� ���´�. ���ϰ� ��ȥ ������� �޸𸮸� �������� ���� �ִ�.
	

	struct Client c1, c2;
	c1.num = 11;
	strcpy(c1.name, "1�� �մ�");
	strcpy(c1.ani.birth, "2000-03-25");
	c1.sel = 0;

	c2.num = 12;
	strcpy(c2.name, "2�� �մ�");
	strcpy(c2.ani.marriage, "2010-05-25");
	c2.sel = 1;

	struct Client cl[2];
	cl[0] = c1;
	cl[1] = c2;

	for (int i = 0; i < 2; i++)
	{
		printf("%d %s ", cl[i].num, cl[i].name);
		if (cl[i].sel == 0) printf("����:%s \n", cl[i].ani.birth);
		else printf("��ȥ:%s \n", cl[i].ani.marriage);

	}
	*/
return 0;
}