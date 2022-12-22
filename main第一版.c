/*
������־��
build:       1.0.23
author:      joker_yue
date:        2022-05-23
last update: 2020-06-06

23-5-2022����һ��
23-5-2022������˹���Ա��¼���������
23-5-2022���������������ʱ���������ع���
23-5-2022���޸��˲��ֽ����Ű���������
24-5-2022���޸���books.dat�޷���ȡ������
24-5-2022�������ͼ��۸�Ϸ��Ե��ж�
24-5-2022���������ͼ��鿴ҳ��ͼ������ж�
24-5-2022���޸���ͼ��鿴ҳ��Ľ��״̬���������
24-5-2022���޸������½���ϵͳʱ�鼮�ֿⶪʧ������
24-5-2022���������books.dat���޸�����
24-5-2022�������������鼮ʱͼ��ISBN��ŵ��жϹ���
24-5-2022���޸��������ͼ��ʱ��ͼ��۸񲻺Ϸ�ȴ�޷��жϵ�����
24-5-2022: �����ɾ��ȫ���鼮�Ĺ���
24-5-2022: ����˲�ɫ����
24-5-2022: �޸���books.dat���޸����棬��������� :-)
25-5-2022���޸���������ʱ����������100%������
25-5-2022���޸����޲���ʱҲ����ʾ�б�ͷ������
25-5-2022: �޸����޲���ʱҲ���޸��鼮��Ϣ������
06-6-2022: �����ɾ��ȫ��ͼ��Ķ���ȷ�Ͻ���
06-6-2022: �޸��˲��ֽ����������ɫ
06-6-2022: ͳһ�˲����������Ʒ�����ԣ����ǽ�(Y/N)ȫ���ĳ���[Y]
06-6-2022: �Ż��˲鿴�鼮�Ĳ����߼�
*/


//��ɫ
#define WHITE SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);//��ɫ
#define RED SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);//��ɫ
#define GREEN SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);//��ɫ
#define BLUE SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE);//��ɫ
#define YELLOW SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN);//��ɫ
#define PINK SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE);//��ɫ
#define CYAN SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_BLUE);//��ɫ
#define GRAY SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY);//��ɫ
//ʹ�÷�����{YELLOW;  printf("%s","���");  WHITE; }
//������û������ֶ�ΪBLUE,�û�����ѡ��ΪGREEN,ϵͳ��ʾΪYELLOW,ϵͳ�����Լ����������ȡ��ΪRED,�����ɹ�ΪGREEN,�б�ͷ��WHITE,�б�����ΪGRAY
//һ��Ҫ�ǵøĻ�����ɫ��

//�����ĺ궨��
#define HIDE_CURSOR CONSOLE_CURSOR_INFO cursor_info = {1, 0};SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);//��������꣬����ʹ�ã��޷�ȡ����


#define ERROR_READ 0
#define MAX_BOOKS_NUM 1000
#define MAX_USERS_NUM 1000


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>//����֧�ּ�������(getch)
#include<windows.h>//����֧����ɫ���ú���Ļ�ȴ�



//ͼ��ݽṹ��
struct Lib{
    char LibName[20];//ͼ�������
    int isEmpty;//�Ƿ�Ϊ��
    int booksNum;//ͼ������
}LibR;

//ͼ��ṹ��
struct Book {
	char isbn[20];		// ���б�� Ψһֵ
	char name[20];		// ����
	char author[20];	// ����
	float price;		// �۸�
	char press[20];		// ������ 
	int isLend;			// �����־ 
}books[MAX_BOOKS_NUM]; 
// ͼ��ṹ�����飬 ���ڴ�����е�ͼ����Ϣ

// ������Ϣ�ṹ�� 
struct Lend {
	int id;					// ���ı�� Ψһֵ 
	struct Book book;		// �����ͼ��
	char name[20];			// ����
	char outTime[10];		// ���ʱ��
	char backTime[10];		// �黹ʱ�� 
}lends[MAX_BOOKS_NUM];

//�û��ṹ��
struct User{
    int user_id;//�û�id
    char user_name[20];//�û���
    char user_password[20];//����
    int lendid[10];//����id�����ͬʱ��10����
    int integral;//����
    int vip;//�Ƿ�Ϊvip 
    struct Lend lend;//������Ϣ
}users[1000];


/*���ﶼ�Ǻ�������*/

// ��¼����ȡ�ļ�
void login(); 
// ����Ա�˵�
void adminMenu();
// ���ͼ�飬�洢�ļ�
void addBook();
// ��ѯͼ�飬�洢�ļ�
void queryBook();
// �洢�ļ�
void saveBooks();
// ��ȡ�ļ�
void loadBooks();
// ɾ��ͼ��
void delBook();
// �޸�ͼ��
void modBook(); 
// ����鼮
void lendBooks();
// �黹�鼮
void backBooks();
// �ж��鼮�ظ�
int isBookRepeat(const char *isbn,int i);
// �ж����������
int confirm(const char *msg);//������
int confirml(const char *msg,const  char *m, void*a);
//�ж�ͼ���Ƿ�Ϊ��
int isLibEmpty();
//�����������
int countBooks();



int main(){
	int input;
    loadBooks();
	while(1){
		system("cls");
        system("color 05");//f1��ǰһ��fΪ����ɫ����һ��Ϊǰ��ɫ����ɫ
		// tab ==> ������	 shift+tab <== ������
        WHITE;//��ɫ
		printf("==================================\n=");
        BLUE;//��ɫ
		printf("          ħ�����ϵͳ\t         ");
        WHITE;//��ɫ
		printf("=\n==================================\n=");
        CYAN;//��ɫ
		printf("           1. ��¼\t         ");
        WHITE;//��ɫ
		printf("=\n=           ");
        YELLOW;//��ɫ
        printf("2. ��������\t      	 ");
        WHITE;//��ɫ
		printf("=\n=           ");
        PINK;//��ɫ
        printf("3. ����ָ��\t         ");
        WHITE;//��ɫ
		printf("=\n=           ");	
        RED;//��ɫ
        printf("4. �˳�\t         ");
        WHITE;//��ɫ
		printf("=\n==================================\n");
        GRAY;//��ɫ
		printf("������ (1 ~ 4): ");
        GREEN;//��ɫ
		scanf("%d",&input);
        WHITE;//��ɫ
		switch(input){
			case 1: login();break; 
			case 2: printf("�������ǣ�\n\t��ͼ��������ּ�ڽ�ͼ�����Ա\n�ӷ���ͼ�����ģʽ�����ȳ�ȥ��");break; 
			case 3: printf("���������������������ι��ս����������");break; 
			case 4: return 0;
            default: printf("�������");
		}
		system("pause");
	}
	return 0;
 }
 
// ����Աҳ��
void adminMenu()
{
    int input;

    while (1)
    {
        system("cls");
        system("color 02");//02��ǰһ��0Ϊ����ɫ����ɫ����һ��Ϊǰ��ɫ����ɫ����������û�ã���FOREGROUND_�����

        WHITE;//��ɫ
        printf("==================================\n=");
        BLUE;//��ɫ
        printf("          ͼ�����ϵͳ          ");
        WHITE;//��ɫ
        printf("=\n==================================\n=");
        YELLOW;//��ɫ
        printf("          1. ���ͼ��      	 ");
        WHITE;//��ɫ
        printf("=\n=          ");
        PINK;//��ɫ
        printf("2. �޸�ͼ��      	 ");
        WHITE;//��ɫ
        printf("=\n=          ");
        BLUE;//��ɫ
        printf("3. ��ѯͼ��      	 ");
        WHITE;//��ɫ
        printf("=\n=          ");
        CYAN;//��ɫ
        printf("4. ɾ��ͼ��      	 ");
        WHITE;//��ɫ
        printf("=\n=          ");
        YELLOW;//��ɫ
        printf("5. ����ͼ��      	 ");
        WHITE;//��ɫ
        printf("=\n=          ");
        PINK;//��ɫ
        printf("6. �黹ͼ��      	 ");
        WHITE;//��ɫ
        printf("=\n=          ");
        GREEN;//��ɫ
        printf("7. ���ͼ��           ");
        WHITE;//��ɫ
        printf("=\n=");
        RED;//��ɫ
        printf("          0. �˳�ϵͳ           ");
        WHITE;//��ɫ
        printf("=\n");
        printf("==================================\n");
        GRAY;//��ɫ
        printf("������ 0 ~ 7: ");
        GREEN;//��ɫ
        scanf("%d", &input);
        WHITE;//��ɫ
        switch (input)
        {
        case 1:
            addBook();
            break;
        case 2:
            modBook();
            break;
        case 3:
            queryBook();
            break;
        case 4:
            delBook();
            break;
        case 5:
            lendBooks();
            break;
        case 6:
            backBooks();
            break;
        case 7:
            printf("����������%d\n",countBooks());
            break;
        case 0:
        WHITE;//��ɫ
            return ;
        }
        system("pause");
    }
}

// ��¼����
void inputPwd(char *pwd, int length){
	char key;
	int i = 0;
	a : while(1) {
		i = 0;
		key = 0;
        YELLOW;//��ɫ
		printf("���������룺\t");
		while(1) {
			key = getch();
			// �˸��
			if(key == '\b') {
				if(i > 0) {
					// ab	\b �˸�
					printf("\b \b");
					i--; 
				}
				continue;
			}
			//	13 �س�
			else if (key == 13) {
				if(i > 0) break;
				else {
					printf("\n");
					goto a;
				}
			} else {
				if(i < length) {
                    BLUE;//��ɫ 
					printf("*");
					pwd[i] = key;
				} else {
					continue;
				}
			}
			i++;
		}
		pwd[i] = '\0';
		printf("\n");
		break;
	}	
}

//�鿴�鼮
void queryBook(){
	if(isLibEmpty()) {printf("�޲��飡\n");return;}

    CYAN;//��ɫ
	printf("  ���   %20s %10s %10s %20s %20s %10s\n", "����","����","�۸�","������","ISBN","����״̬");
    WHITE;
    int showindex=1;//��ʾ����
    
    GRAY;//��ɫ
	for(int i=0;i<MAX_BOOKS_NUM;i++){
		if(strlen(books[i].name)>0){
			printf("��%03d��  %20s %10s %10.2f %20s %20s",
            showindex++,//��ʾ����
			books[i].name,
			books[i].author,
			books[i].price,
            books[i].press,
			books[i].isbn);

            if(books[i].isLend==1) {YELLOW;printf("%10s\n","�ѽ��");}
            else {GREEN;printf("%10s\n","δ���");}
            
		}
	}
    WHITE;//��ɫ
}
 
//����鼮
void addBook()
{
    int i;

    // ���ҽṹ�������еĿ���λ��
    for (i = 0; i < MAX_BOOKS_NUM; i++)
        if (strlen(books[i].name) == 0) //�������Ϊ�գ�˵����λ�����鱾
        {
            // ���û�����һ��ͼ�����Ϣ�������ڽṹ�������еĿ���λ����
            printf("������ISBN��");
                while(scanf("%s", books[i].isbn))
                {
                    if(isBookRepeat(books[i].isbn,i))
                    printf("���д���,���������룺");
                    else break;
                }

            printf("������������");
            scanf("%s", books[i].name);

            printf("���������ߣ�");
            scanf("%s", books[i].author);

            printf("������۸�");
                while(scanf("%f", &books[i].price))
                {
                    if(books[i].price<=0)
                    printf("�۸��趨��������������۸�\n");
                    else break;
                }

            printf("����������磺");
            scanf("%s", books[i].press);

            books->isLend=0;//��ʼ��Ϊδ���

            saveBooks(); // д���ļ�
            break;
        }

    if (i == MAX_BOOKS_NUM)
        printf("���������");
    else
        printf("����ɹ���");
}

// ��¼
void login()
{
    char user[10];
    char pwd[10];
    YELLOW;//��ɫ
    printf("�������û�����\t");
    BLUE;//��ɫ
    scanf("%s", user);
    WHITE;//��ɫ
    inputPwd(pwd, 10); //��������

    //�ַ����жϣ�����ǹ���Ա������ת������Ա����
    if (strcmp(user, "admin") == 0 && strcmp(pwd, "admin") == 0)
    {
        GREEN;
        printf("��¼�ɹ���\n");
        Sleep(1000);
        WHITE;
        adminMenu();
    }
    else
    {
        RED;
        printf("��¼ʧ�ܣ�\n");
        WHITE;
        return  ;
    }
}

// �洢�鼮��Ϣ�ļ�
void saveBooks(){
	//��books�����ļ���books.dat��
	FILE*file;//�����ļ�ָ��
	file=fopen("books.dat","a+");//��׷��ģʽ��a�����ļ�
	//fileΪNULL ��ô��ʾ�ļ������ڣ�ϵͳ�ᴴ�����ļ�
	//����˵����1д�����ݶ���2д�����ݴ�С��3д�������4�ļ�ָ��
	fwrite(books,sizeof(books),1,file);
	fclose(file);//�ر��ļ� 
}

// ��ȡ�ļ� 
void loadBooks(){//�����̼�׬Ǯ�ĵط���
    system("color 14");//����
	FILE*file;
	file=fopen("books.dat","r");//�Զ�ģʽ��r�����ļ�
	
	if(file !=NULL){
		//�ļ���ΪNULL���Ͷ�ȡ�ļ�
        while(1)
        {
            fread(books,sizeof(books),1,file);//ѭ������
            if(feof(file)) break;
        }
	}
    else {
        HIDE_CURSOR;//���ع��
        printf(":-(\n����ϵͳ��������,��Ҫ��������,���������Ѽ�����,�����˳�...\n");
        Sleep(1000);
        for(int i=0;i<100;i++)
        {
            printf("%d%%",i);
            Sleep(50);
            printf("\b\b\b");
        }
        printf("��⵽��ʧbooks.dat,���ڳ����Զ��޸�...\n");
        /* Joker Never Plays Jokes!*/
            remove("books.dat");//ɾ���ļ�
        Sleep(1000);
        printf("��������ļ�...\n");
        Sleep(1000);
        printf("��ӳɹ���������������ָ��...\n");
        file=fopen("books.dat","w");//��дģʽ��w�����ļ��������������½��ļ�
        Sleep(1000);
        printf("�ɹ���\n");
        Sleep(500);//��ʱ1�룬�����ü�Ǯ
        
        system("cls");//����
        system("color Af");//����
        if(file!=NULL)
        {printf("�޸���ɣ���������������\n");
         printf("ϵͳ����3���ر�...\n");
            Sleep(1000);printf("2���ر�...\n");
            Sleep(1000);printf("1���ر�...\n");
        }
        else {
            system("color 14");//����
            printf(":-(\n�޸�ʧ�ܣ����ֶ���������ϵ����\n");
            printf("��ϵ��ʽ��\nQQ:3349305706\nEmail:Joker_Yue@qq.com\n");
            }
        exit(ERROR_READ);
    }
	fclose(file);
} 

// ɾ��ͼ��
void delBook() {
    //��isbn����ͼ��
    char isbn[20];
    int i;
    char yn[10];

    char key;//������
    RED;
    printf("�Ƿ�ȫ��ɾ��?[Y]\n");
    WHITE;
    key=getch();

    if(key=='y'||key=='Y')
    {   
        YELLOW;
        printf("��Σ������������:");RED;printf("yes");YELLOW;printf("�Լ�������:");
        BLUE;
        scanf("%s",yn);
        if(strcmp(yn,"yes")!=0){
            GRAY;
            printf("����ȡ����\n");
            WHITE;
            goto ctn;
        }
        remove("books.dat");//ɾ���ļ�
        FILE *file;//���¶���ָ���������ļ�
        file=fopen("books.dat","w");//��дģʽ��w�����ļ��������������½��ļ�
        GREEN;
        printf("ɾ���ɹ���\n");
        WHITE;
        fclose(file);//�ر��ļ�

        for(int i=0;i<MAX_BOOKS_NUM;i++)//ѭ��ɾ��
        {
            if(books->isbn)
            {
                books[i].isbn[0]='\0';
                books[i].name[0]='\0';
                books[i].author[0]='\0';
                books[i].press[0]='\0';
                books[i].price=0;
                books[i].isLend=0;
            }
        }
        return;
    }

    ctn:
    printf("������Ҫɾ����ͼ���ISBN: ");
    scanf("%s", isbn);
    for (i = 0; i < MAX_BOOKS_NUM; i++) {
        if (strcmp(books[i].isbn, isbn) == 0) {
            printf("������ \t%s\n", books[i].name);
            printf("���ߣ� \t%s\n", books[i].author);
            printf("�۸� \t%10.2f\n", books[i].price);
            printf("������: \t%s\n", books[i].press);
            printf("��ȷ���Ƿ�Ҫɾ����ͼ��[Y]\n");
            scanf("%s", yn);
            if (strcmp(yn, "y") == 0 || strcmp(yn, "Y") == 0) {
                strcpy(books[i].isbn, "");
                strcpy(books[i].name, "");
                strcpy(books[i].press, "");
                books[i].price = 0;
                //д���ļ�
                saveBooks();
                GREEN;
                printf("ͼ��ɾ���ɹ�! \n");
                WHITE;
            } else {
                RED;
                printf("�û�ȡ����ɾ�������� \n");
                WHITE;
            }
            return;
        }
    }
    //δ�ҵ�ͼ��
    RED;
    printf("û�и�ͼ�飡\n");
    WHITE;
}

//�޸�ͼ��
void modBook() {
    char isbn[20];
    int i;
    char key;  //����İ���

    if(isLibEmpty()) {
        RED;
        printf("ͼ���Ϊ�գ�\n");
        WHITE;
        return;
    }
    
    GRAY;//��ɫ
    printf("�Ƿ��г�ͼ���б�?[Y]\n");
    key=getch();
    if(key=='y'||key=='Y') queryBook();

    printf("������Ҫ�޸ĵ�ͼ���ISBN: ");
    scanf("%s", isbn);
    for (i = 0; i < MAX_BOOKS_NUM; i++) {
        if (strcmp(books[i].isbn, isbn) == 0)
        {
            WHITE;//��ɫ
            printf("��ѯ�ɹ����ҵ�ƥ���鼮��\n");
            GRAY;//��ɫ
            printf("\n\t||����: \t%s\n", books[i].name);
            printf("\t||����: \t%s\n", books[i].author);
            printf("\t||�۸�: \t%10.2f\n", books[i].price);
            printf("\t||�����磺\t%s\n\n", books[i].press);

            YELLOW;//��ɫ
            printf("�Ƿ�ʼ�޸�?[Y]\n");
            key = getch();
            if (key != 'Y' && key != 'y') {
                RED;//��ɫ
                printf("�������û�ȡ���� \n");
                return ;
            }


            //��ʾ�û��Ƿ��޸�ÿ���ֶ�
            printf("��ȷ���Ƿ�Ҫ�޸�����(Y/N)?\n");
            key = getch();
            if (key == 'y' || key == 'Y') {
                printf("������:");
                scanf("%s", books[i].name);
                printf("�޸ĳɹ���\n");
            }

            printf("��ȷ���Ƿ�Ҫ�޸�����?[Y]\n");
            key = getch();
            if (key == 'y' || key == 'Y') {
                printf("������:");
                scanf("%s", books[i].author);
                printf("�޸ĳɹ���\n");
            }

            printf("��ȷ���Ƿ�Ҫ�޸ļ۸�?[Y]\n");
            key = getch();
            if (key == 'y' || key == 'Y') {
                printf("������:");
                while(scanf("%f", &books[i].price))
                {
                    if(books[i].price<=0)
                    printf("�۸��趨��������������۸�\n");
                    else 
                    {
                        printf("�޸ĳɹ���\n");
                        break;
                    }
                }
            }

            printf("��ȷ���Ƿ�Ҫ�޸ĳ�����?[Y]\n");
            key = getch();
            if (key == 'y' || key == 'Y') {
                printf("������:");
                scanf("%s", books[i].press);
                printf("�޸ĳɹ���\n");
            }
            saveBooks();
            printf("\nͼ���޸ĳɹ�!\n");

            return;
        }
    }
    printf("û�и�ͼ�飡\n");
}

// ���ͼ��
void lendBooks() {
    char isbn[20];
    int i, j;
    char yn[10];
    char key;

    if(isLibEmpty()) {
        RED;
        printf("ͼ���Ϊ�գ�\n");
        WHITE;
        return;
    }
    
    GRAY;//��ɫ
    printf("�Ƿ��г�ͼ���б�?[Y]\n");
    key=getch();
    if(key=='y'||key=='Y') queryBook();
    WHITE;

    printf("������Ҫ�����ͼ���ISBN: ");
    scanf("%s", isbn);
    for (i = 0; i < MAX_BOOKS_NUM; i++) {
        if (strcmp(books[i].isbn, isbn) == 0) {
            GRAY;//��ɫ
            printf("����: \t%s\n", books[i].name);
            printf("����: \t%s\n", books[i].author);
            printf("�۸�: \t%10.2f\n", books[i].price);
            printf("������: \t%s\n", books[i].press);
            printf("���״̬: \t%s\n", books[i].isLend == 1 ? "���" : "�ڿ�");

            //�ж�ͼ���Ƿ񱻽��
            if (books[i].isLend == 1) {
                printf("��ͼ���Ѿ������! \n");
                return;
            }

            printf("��ȷ���Ƿ�Ҫ�����ͼ��?[Y]\n");
            scanf("%s", yn);
            if (strcmp(yn,"y") == 0 || strcmp(yn,"Y") == 0) {
                //δ������޸�ͼ��״̬
                books[i].isLend = 1;

                for (j = 0; j < MAX_BOOKS_NUM; j++) {
                    if (lends[j].id == 0) {
                        //�����������Ϣ
                        printf("�������������: ");
                        scanf("%s", lends[j].name);
                        printf("�����������ʱ��: ");
                        scanf("%s", lends[j].outTime);
                        // id�Զ�����
                        lends[j].id = j + 1;
                        lends[j].book = books[i];
                        break;
                    }
                }
                //д���Ŀ�
                saveBooks();
                printf("ͼ�����ɹ���\n");
            } else {
                printf("�û�ȡ���˽��������\n");
            }
            return;
        }
    }
    //û�ҵ�����ʾ�û�����ֹ����
    printf("û�и�ͼ�飡\n");
}

// �黹ͼ�� 
void backBooks() {
	int id;
	int i,j;
	char name[20] = "";
    char key;

    
    GRAY;//��ɫ
    printf("�Ƿ��г�ͼ���б�?[Y]\n");
    key=getch();
    if(key=='y'||key=='Y') queryBook();

    WHITE;
	
	confirml("�Ƿ�Ҫʹ��������ѯδ�黹��ͼ��?[Y]","%s", name);
	if(strlen(name) == 0){
		// ���ݽ��ı�ţ����ҽ��ļ�¼
		printf("��������ı�ţ�");
		scanf("%d",&id); 
	}
	
	for(i=0 ;i < MAX_BOOKS_NUM; i++){
		// �жϽ���״̬
		// �黹ͼ�鲢ʹ�þ�ȷ��ѯ����������ȫ��ͬ 
		if(strcmp( lends[i].book.name, name) == 0 || (id > 0 && lends[i].id == id)){
            GRAY;//��ɫ
			printf("��		 ��  ��\t%s\n",lends[i].book.name);
			printf("��		 ��  ��\t%s\n",lends[i].book.name);
			printf("��		 ��  ��\t%s\n",lends[i].book.name);
			printf("��  ��   ��  ��\t%s\n",lends[i].book.name);
			printf("��  ��   ��  ��\t%s\n",lends[i].book.name);
			printf("�� �� ʱ ��  ��\t%s\n",lends[i].book.name);
			printf("�� �� ʱ ��  ��\t%s\n",lends[i].book.name);
            WHITE;
			if(strlen(lends[i].backTime) > 0) {
                RED;
				printf("��ͼ���Ѿ��黹��"); 
                WHITE;
				return;
			} 
			// �޸Ľ��ļ�¼�Ĺ黹ʱ��
			printf("������黹ʱ�䣺");
			scanf("%s",lends[i].backTime);
			
			// �޸�ͼ��״̬
			for(j=0 ;j < MAX_BOOKS_NUM; j++) {
				if(strcmp(books[j].isbn, lends[i].book.isbn) == 0){
					books[j].isLend = 0;
					break;
				}
			}
			
			// ����
			saveBooks();
			
			// ��ʾ�ɹ�
			printf("ͼ��黹�ɹ���");
			return; 
		} 
	}
    RED;
	printf("û�иý��ļ�¼��");
} 

//����ȷ��
int confirm(const char *mag)
{
    char key;
    printf(mag);

    key=getch();

    if(key=='N'||key=='n')
    {
        printf("\n");
        return 0;
    }
    
    else
    {
        printf("�����룺\n");
        return 1;
    }
/* 
���û�ȷ������ĺ������û�����N/n����0����������1
msg��ʾ��ʾ�û���������� */
}

//����ȷ��1
int confirml(const char *msg ,const char *m, void *a)
{
    char key;
    printf(msg);

    key=getch();

    if(key!='y'&&key!='Y')
    {
        printf("\n");
        return 0;
    }
    
    else
    {
        printf("�����룺");
        scanf(m,a);
        return 1;
    }
}

//�ж��鼮�ظ�
int isBookRepeat(const char *isbn,int i)
{
    int j;
    for(j=0;j<MAX_BOOKS_NUM;j++)
    {
        if(strcmp(books[j].isbn,isbn)==0&&j!=i)//������ظ���isbn
        {
            return 1;
        }
    }
    return 0;
}

//�����������
int countBooks(){ 
    int i, count = 0;
    for (i = 0; i < MAX_BOOKS_NUM; i++) {
        if (strlen(books[i].isbn) > 0) {
            count++;
        }
    }
    LibR.booksNum = count;
    LibR.isEmpty = 0;
    if(count == 0)
        LibR.isEmpty = 1;
    return count;
}

//�ж��Ƿ�Ϊ��
int isLibEmpty() {
    countBooks();
    return LibR.isEmpty;
}


