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

/*void print(struct Member* pmem) //struct Member mem을 넣으면 구조체가 또 생기는 것 (값을 복사해서 집어넣는 call by value니까) 그러니 메모리를 아끼고 효율을 높이기 위해 Member 객체의 주소를 받는다는 뜻이다.
{
		printf("이름\t%s \n", (*pmem).name); //주소를 줬으니 값을 얻으려면 역참조를 해야한다. (*pmem).name이란 표현을 pmem->name 이라 표현가능하다. ->라는 표현은 역참조와 같다
		printf("번호\t%d \n", (*pmem).num);
		printf("연락처\t%s \n", (*pmem).number);
		
	
}*/

/*struct Member get_member()
{
	
	struct Member mem;
	printf("번호 이름 전화:");
	scanf("%d %s %s", &mem.num, mem.name, mem.number);
	return mem;
	
}*/

/*struct Member* get_member()
{
	static struct Member mem; //혹은 동적할당
	struct Member* mem = malloc(sizeof(struct Member));
	printf("번호 이름 전화:");
	scanf("%d %s %s", &(mem->num), mem->name, mem->number);
	return &mem;
	
}*/


//공용체

/*union Aniversary //얘도 (개발자 정의) 자료형. 변수를 만들 수 있다.
	공용체는 값을 공용으로 쓴다 (공용인 공간에 저장)
{
	char birth[16];
	char marriage[16]; 
	//변수가 오억개 있어도 가장 크기가 큰 변수의 공간만 만든다. 지금의 경우 두 변수의 공간이 16으로 같으니 16바이트를 생성
	
};
*/
/*
공용체 예시: 사은행사, 생일이나 결혼기념일 중 하나를 얘기해주시면 그 날 선물을 드려요.
생일을 쓸지, 결혼기념을을 쓸지 알 수 없는 상황, 하지만 변수는 모두 준비해야하는 상황에서 쓰인다.
*/

/*struct Client
	
{
	int num;
	char name[20];
	union Aniversary ani; //오타를 조심하자!
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
		printf("기술명\t%s \n", (pgi[i]).name);
		printf("피해량\t%d \n", (pgi[i]).power);
		printf("최대사용횟수\t%d \n \n", (pgi[i]).max);
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
		char* snum = strtok(NULL, "|");//이름 다음거
		char* tel = strtok(NULL, "|");//그 다음거
		struct Member m;
		strcpy(m.name, name);
		strcpy(m.tel, tel);
		m.num = atoi(snum); //문자열(아스키 문자)를 정수로 바꿔주는 함수 atoi (ascii to intiger)
		list[i++] = m;
	}
	fclose(fp);
	return list;
}

void print_mlist(struct Member* list, int cnt)
{
	printf("회원 정보는: \n");
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
			continue; // 순용이라는 문자열이 누락되고 나머지만 적어준다.
		}
		fprintf(fp, "%s|%d|%s\n", list[i].name, list[i].num, list[i].tel);
	}
	free(list);
	fclose(fp);
}

int main()
{ 
	//함수 만들어보기
	//mem_update("이름","전화번호") --> 이름과 일치하는 정보를 찾아 전화번호를 바꿔라
	//mem_delete("이름") --> 이름이 포함된 정보를 지워라

	mem_update("순용", "01022223333");
	//6일차
	/*6일차 복습 예제
	GameItem 객체의 속성에는 이름, 파워, 최대사용횟수가 있고 
	이런한 속성을 가진 서로 다른 게임 아이템 3개의 정보를 생성하고
	그 정보를 출력전용 함수에 전달하여 모든 게임 아이템의 정보가 화면에 표시되도록 해보세요
	
	struct GameItem gi[3];

	//struct GameItem cry
	//strcpy(cry.name, "울부짖기");
	//cry.power = 3
	//cry.max = 3  이렇게 기술 3개를 만들고 출력함수에서 출력하도록 한다.
	strcpy(gi[0].name, "울부짖기");
	gi[0].power = 3;
	gi[0].max = 3;

	strcpy(gi[1].name, "도약");
	gi[1].power = 1;
	gi[1].max = 5;

	strcpy(gi[2].name, "베기");
	gi[2].power = 6;
	gi[2].max = 3;


	print(&gi);

	//struct GameItem gi[] = {cry, jump, slash}
	//print(gi, sizeof(gi)/sizeof(struct GameItem));// gi의 총 사이즈를, 변수의 크기로 나눠준다 (그럼 각 struct GameItem의 크기가 나온다)
	*/

	/*6일차 복습예제2
	위에서 GameItem 객체를 3개 생성하면서 거의 동일한 코드를 반복했는데 
	이런 문제를 해결하기 위해 함수를 정의하고
	그 함수를 3번 호출하여 문제를 해결하려고 한다.
	아이템 이름, 파워, 사용횟수 이런한 값을 함수로 전달해서 GameItem 객체를 리턴할 수 있도록 함수를 정의해 보세요.
	

	struct GameItem gi[3];
	gi[0] = creat_item("울부짖기", 3, 3);
	gi[1] = creat_item("도약", 1, 5);
	gi[2] = creat_item("베기", 6, 3);
	print(gi, sizeof(gi) / sizeof(struct GameItem));
	//반복되는 코드가 있으면 유지 보수할 때 힘드니 함수를 이용하여 간단하게 만들어보자.
	*/
	
	/*6일차 파일 다루기 //노트 참고*/

	/*FILE* fp = fopen("D:\\test\\smaple.txt", "a"); //폴더을 만들진 못함.. 확장자는 필수는 아님
	//w(쓰기)모드로 열면 두번 돌렸을 때 덮어쓰기가 되어 파일을 삭제하고 다시 만드는 개념
	//추가한다는 모드는 a를 써준다 (append)
	//읽기 모드는 r (read)
	fprintf(fp, "파일에 쓰기\n");
	fprintf(fp, "%d번째 행\n", 2);
	fclose(fp);

	printf("파일에 쓰기 성공 \n");*/


	/*파일에 있는 것을 메모리로 불러와 화면에 표시해보기 (fscanf활용)
	FILE* fp = fopen("D:\\test\\smaple.txt", "r");
	char buf[32];
	//fscanf(fp, "%s", buf); --> 공백을 구분함
	//fgets(buf, 32, fp); --> 한 행 전체를 읽어옴
	while(fgets(buf, 32, fp) !=NULL)
	{ 
	printf("읽어온 문자열: %s \n", buf); //결과는 "파일에" --> scanf는 스페이스로 구분된 한 문자열만 읽어오기 때문.
	}
	printf("파일 끝\n");
	*/

	/*6일차 오후 예제
	키보드에서 회원의 이름 번호 전화를 입력받아서
	"홍길동|11|010-3949-3492" 형식의 문자열을 생성한 후 화면에 표시해보세요.

	strcat, sprint등의 함수를 사용하면 문자열을 조합할 수 있다.
	*/

	/*
	char member [50];

	char name [10];
	int num;
	char tel [30];
	
	printf("회원의 이름, 번호, 전화를 입력하세요:");
	scanf("%s %d %s", name, &num, tel);
	sprintf(member, "%s|%d|%s\n", name, num, tel); //&num은 주소, 여기서는 값
	printf("회원 정보: %s \n", member);
	
	FILE* fp = fopen("D:\\test\\mem.txt", "a");
	//fprintf(), fputsf(): 단순한 문자열 (조합이 되어있는 문자열)은 fputsf가 편리하다.
	fputs(member,fp); //member에 있는 문자열을 fp에 쓰겠다~이말이야.
	fclose(fp);

	printf("기록 성공 \n");
	*/

	/*메모장에 쓴 것 불러오기
	FILE* fp = fopen("D:\\test\\mem.txt", "r");
	char read[80];
	while (fscanf(fp, "%s", read) != -1) //fp에가서 %s을 가져와 read에 저장하라
	{
		printf("%s \n", read);
	};
	fclose(fp);
	//오타를 조심하자..
	*/

	/*파일에 있는 자료 검색하기
	strtok을 활용해 이름을 검색하면 그 사람의 자료가 print되도록 하라
	
	FILE* fp = fopen("D:\\test\\mem.txt", "r");
	char read[80];
	char found = 0;
	while (fscanf(fp, "%s", read) != -1) //파일이 끝나면 -1이 나오니 -1까지 읽는다는 것은 파일을 끝까지 읽겠다는 것
	{
		char* name = strtok(read, "|");
		if (strcmp(name, "크앙") == 0)
		{
			char*num = strtok(NULL, "|");
			char*tel = strtok(NULL, "|");
			printf("검색된 정보: %s %s %s \n", name, num, tel);
			found = 1;
			break;
		}
		
	}

	//만약 검색실패라면 "검색결과가 없습니다" 메시지를 출력한다.
	//if 루프가 돌아갔는지 안돌아갔는지 확인하는 결과를 저장하고 (flag 변수를 둔다) 그 결과를 확인해야한다.
	//found 라는 char 변수를 만들어 검색이 되었으면 1의 값을, 아니면 0의 값을 내놓게 한다음 마지막에 if로 돌려준다.
	if (!found) printf("검색결과가 없습니다"); //found가 false(0) 라면 
	fclose(fp);
	*/



	



	//현재 회원의 수가 몇명인지 세는 함수를 만들어서 불러오기 함
	//int cnt = get_cnt();
	//printf("현재 회원수: %d \n", cnt);

	//회원수만큼 문자열 배열을 생성하고
	//파일에 저장된 모든 회원의 정보를 로드하여 (mem_load 함수)
	//구조체 객체가 되게 한다. 그리고 그 객체들을 배열에 저장.
	//배열에 저장해서 그 내용을 화면에 표시해보세요.


	//struct Member* list = mem_load();
	//print_mlist(list, get_cnt());
	
	//파일에 있는 자료 수정하기
	//디스크에 든 데이터를 싹 다 메모리로 옮겨와 수정할 정보를 찾아 바꿔주고 다시 w로 덮어씌워준다.
	//순용의 전화번호를 바꿔보자

	/*for (int i = 0; i < cnt; i++) 
	{
		if (strcmp(list[i].name, "순용") == 0)
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

	// 이 전체를 함수로 만들어서 update 함수를 만든다.

	/*특정 회원 삭제 Delete 과정
	FILE* fp = fopen("D:\\test\\mem.txt", "w");
	for (int i = 0; i < cnt; i++)
	{
		if (strcmp(list[i].name, "순용") == 0)
		{
			continue; // 순용이라는 문자열이 누락되고 나머지만 적어준다.
		}
		fprintf(fp, "%s|%d|%s\n", list[i].name, list[i].num, list[i].tel);
	}
	*/

	//함수 만들어보기
	//mem_updat("이름","전화번호") --> 이름과 일치하는 정보를 찾아 전화번호를 바꿔라
	//mem_delete("이름") --> 이름이 포함된 정보를 지워라



	/* 구조체 예제
	키보드에서 번호, 이름, 전화번호를 입력받아서 구조체를 초기화하고
	그 구조체를 다른 함수로 전달해서 (parameter list에다가 구조체 변수를 넣어준다)
	화면에 모든 정보가 표시되도록 해보세요
	

	printf("이름을 입력하세요:");
	scanf("%s", mem.name);
	//키보드로 받은 문자열을 고오대로 mem.name이 가리키는 공간에 순차적으로 넣어라~
	//strcpy(mem.email, "smith@daum.net") "smith@daum.net"이 있는 주소로가서 "smith@daum.net"을 가져와서 mem.email에 순차적으로 넣어라~
	printf("번호을 입력하세요:");
	scanf("%d", &mem.num);
	printf("전화번호을 입력하세요:");
	scanf("%s", mem.number);
	print(&mem); //-위에서 포인터로 받았으니 여기선 주소변수를 준다.
	*/

	/*구조체 예제2
	get_member() 함수를 호출하면 리턴 값이 Member 구조체의 객체가 되도록하고
	main()함수에서 리턴값을 받아서 화면에 정보를 표시하도록 해보세요.
	
	struct Member mem = get_member();
	printf("이름\t%s \n", mem.num);
	printf("번호\t%s \n", mem.num);
	printf("연락처\t%s \n", mem.num);
	*/

	/*
	구조체 예제3
	get_member() 함수가 Member 구조체 객체의 주소를 리턴하여 
	main()함수에서 받아서 회원정보를 표시하는 기능을 작성해보세요
	

	struct Member* mem = get_mem_p();
	printf("이름\t%s \n", mem->num);
	printf("번호\t%s \n", mem->num);
	printf("연4락처\t%s \n", mem->num);
	*/

	/*
	구조체 예제 4
	키보드에서 회원정보를 다수개 입력하고 (배열,loop를 통해 받을 것)
	Member 배열에 저장하여
	print_list() 함수에 배열을 전달하면 --> 여기서는 내부에서 함
	전체 회원의 정보가 화면에 표시되도록 한다.
	
	 
	struct Member mem[5];//5개를 지정한다기보단 넉넉한 숫자를 주면 된다. //동적 할당을 해도 된다.
	int i = 0;
	int num;
	
	while (1)
	{ 
		printf("종료(0), 번호, 이름, 연락처:");
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
	

	print를 함수로 작성시
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

	//구조체(Structures): 여러개의 변수가 한개의 object(객체)를 modeling(객체를 흉내낸다)하는 것
	//다수개의 자료형을 그룹지어서 한개의 객체를 모델링한 자료구조
	//객체(Object, Instance): 사물 나름대로의 속성, 기능을 갖춘 것.
/*
	struct   --> 구조체를 정의한다
	{
		int num;
		char name[16];
		char email[16];
	}Member; --> 구조체 변수 이름
	
	Member.
	*/

	/*
	struct Member //Member라는 새로운 자료형을 정의함// 자료형으로는 새로운 변수를 만들 수 있다.
	{
		int num;
		char name[16];
		char email[16];
	};

	struct Member mem;//구조체에 포함된 메모리 할당.
	//mem.email = "smith@daum.net"; --> 오류
	//mem.email[0] = 's'; --> 이렇게 하면 s,m,i,t,h, 등등 계속 넣어줘야 함으로 번거롭
	strcpy(mem.email, "smith@daum.net") ; //--> 구조체 안에 있는 문자열 초기화하는 법
	strcpy(mem.name, "Mr.Smith"); //mem.email과 mem.name은 포인터 정수이기 때문에 주소를 직접적으로 변결 할 수 없으니 strcpy 함수를 써서 넣어주는 것이다.
	mem.num = 11; //mem.num 은 그냥 변수임으로 바로 적용 가능
	//구조체 변수 초기화 완료

	printf("번호\t%d \n", mem.num);
	printf("이름\t%s \n", mem.name);
	printf("이메일\t%s \n", mem.email);
	*/

	/*공용체
	union Aniverary ani;
	strcpy(ani.birth, "2000-12-15");
	strcpy(ani.marriage, "2000-11-25");
	printf("생일은: %s \n", ani.birth); //결과는 결혼 기념일 날짜가 나온다. 생일과 결혼 기념일이 메모리를 공용으로 쓰고 있다.
	

	struct Client c1, c2;
	c1.num = 11;
	strcpy(c1.name, "1번 손님");
	strcpy(c1.ani.birth, "2000-03-25");
	c1.sel = 0;

	c2.num = 12;
	strcpy(c2.name, "2번 손님");
	strcpy(c2.ani.marriage, "2010-05-25");
	c2.sel = 1;

	struct Client cl[2];
	cl[0] = c1;
	cl[1] = c2;

	for (int i = 0; i < 2; i++)
	{
		printf("%d %s ", cl[i].num, cl[i].name);
		if (cl[i].sel == 0) printf("생일:%s \n", cl[i].ani.birth);
		else printf("결혼:%s \n", cl[i].ani.marriage);

	}
	*/
return 0;
}