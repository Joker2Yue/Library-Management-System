/*������־��
23-5-2022����һ��
23-5-2022������˹���Ա��¼���������
23-5-2022���������������ʱ���������ع���
23-5-2022���޸��˲��ֽ����Ű���������
24-5-2022���޸���books.txt�޷���ȡ������
24-5-2022�������ͼ��۸�Ϸ��Ե��ж�
24-5-2022���������ͼ��鿴ҳ��ͼ������ж�
24-5-2022���޸���ͼ��鿴ҳ��Ľ��״̬���������
24-5-2022���޸������½���ϵͳʱ�鼮�ֿⶪʧ������
24-5-2022���������books.txt���޸�����
24-5-2022�������������鼮ʱͼ��ISBN��ŵ��жϹ���
24-5-2022���޸��������ͼ��ʱ��ͼ��۸񲻺Ϸ�ȴ�޷��жϵ�����
24-5-2022: �����ɾ��ȫ���鼮�Ĺ���
24-5-2022: ����˲�ɫ����
24-5-2022: �޸���books.txt���޸����棬��������� :-)
25-5-2022���޸���������ʱ����������100%������

25-5-2022���ڶ���
25-5-2022: ������û�ϵͳ
25-5-2022: ������û���¼����
25-5-2022��������û�ע�Ṧ��
25-5-2022��������û��˵�����
25-5-2022: �����users.txt���޸����棬��������� :-)
25-5-2022: �޸����޲���ʱҲ���޸��鼮��Ϣ������
26-5-2022: �޸��˲鿴������Ϣʱ�����˳���bug
26-5-2022: �޸��˸�����Ϣ������ʾ��ʽ�����bug
26-5-2022: �޸��˲��ֲ����³��������˳�
26-5-2022: �޸����޷�ע���û�������
26-5-2022: ɾ�����Ͼɵ�Lend�ṹ��
26-5-2022: ��users��books�ṹ������
26-5-2022: �޸������������ⲻ��ȡ��bug
26-5-2022: �޸��˹���Ա�޷���¼������
26-5-2022: ������û��˺��жϺϷ��ԵĹ���
26-5-2022: �����ɾ��ȫ���û��Ĺ���
26-5-2022: �����ɾ��ȫ��ͼ��Ķ�������ȷ��
26-5-2022: �����ɾ��ȫ���û��Ķ�������ȷ��
26-5-2022: �޸��������û�����»���ʾ�û��б��bug
26-5-2022: �޸����û��޷�ע�������
26-5-2022: �޸�����ҳ��������ϵͳ����Ӧ������
26-5-2022: �û�����ġ�������Ϣ���������ߣ�
26-5-2022: �û�����ġ��ҵĽ��ġ��������ߣ�
26-5-2022���û�����ġ�����ͼ�顿�������ߣ�
26-5-2022: �û�����ġ��黹ͼ�顿�������ߣ�
26-5-2022: ������û�ID���û�����������ת������
26-5-2022���޸��˹���Ա���滹�����������
26-5-2022���޸����ڹ���Ա����������û����滹����ʾû�н赽�������
27-5-2022: �޸����û��޷��黹�鱾������
27-5-2022���޸��˹���Ա����ʧ�ܵ�����
27-5-2022���޸����������鼮�ɽ���ȴ������ʾ ���鼮�ɽ��ĵ�����
27-5-2022: ����˵�½���������ж�
27-5-2022: �޸��˵�¼����������ɫ������������
27-5-2022: �޸��˹���Ա����Ĳ����߼�
27-5-2022: ��������û���½����Ļ�ӭ��
27-5-2022��������û�����ϵͳ
28-5-2022: ����˸�������������ɫ
28-5-2022: �����˲��ֽ������ʾ��Ϣ
28-5-2022: �޸����޸��û������˳�������
28-5-2022: ���������û���δ�黹���鱾ʱ�������û�����ע��
*/

#define ERROR_READ 0

#define MAX_BOOKS_NUM 100
#define MAX_USERS_NUM 100
#define TOP_POINTS 10
#define TOP_VIP_GRADE 8

#define WHITE SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE)//��ɫ
#define RED SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);//��ɫ
#define GREEN SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN)//��ɫ
#define BLUE SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE)//��ɫ
#define YELLOW SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN)//��ɫ
#define PINK SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE)//��ɫ
#define CYAN SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_BLUE)//��ɫ
#define GRAY SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY)//��ɫ


#include<stdio.h>//�����������������
#include<stdlib.h>//����memset()
#include<string.h>//����֧��string
#include<conio.h>//����֧�ּ�������(getch)
#include<windows.h>//����֧����ɫ���ú���Ļ�ȴ�
#include<ctype.h>//����֧��isalpha����
#include<malloc.h>//����֧��malloc����
#include<time.h>//����֧����ʾʱ��


//ͼ��ݽṹ��
struct Lib{
    char LibName[20];//ͼ�������
    int isBookEmpty;//�Ƿ�Ϊ��
    int isUserEmpty;//�Ƿ�Ϊ��
    int booksNum;//ͼ������
    int userNum;//�û�����
    int lendBooksNum;//�ѽ�����鱾����
    int unlendBooksNum;//δ������鼮����
}LibR;

//ͼ��ṹ��
struct Book {
	char isbn[20];		// ���б�� Ψһֵ
	char name[20];		// ����
	char author[20];	// ����
	float price;		// �۸�
	char press[20];		// ������ 
	int isLend;			// �����־  
    int lenduserid;         //������ID
    char lendMessage[20];     //���ı�ע
}books[MAX_BOOKS_NUM]; // ͼ��ṹ�����飬 ���ڴ�����е�ͼ����Ϣ

//�û��ṹ��
struct Users
{
    int user_id;//�û�id
    char user_name[10];//�û���
    char user_password[20];//����
    int integral;//����
    int vip;//�Ƿ�Ϊvip 
    char lendBooksIsbn[11][20];//���ĵ��鼮,���ͬʱ��10����
    int lendBooksNum;//���ĵ��鼮����
}users[MAX_USERS_NUM];//�û��ṹ�����飬���ڴ�����е��û���Ϣ


int sys_user_id;//����ϵͳ��½�ĵ��û�ID
int sys_user_index;//����ϵͳ��½�ĵ��û�����


// ��¼����ȡ�ļ�
void login(); 
// ����Ա�˵�
void adminMenu();
// ���ͼ�飬�洢�ļ�
void addBook();
// ��ѯͼ�飬�洢�ļ�
void queryBook();
// ��ϸ�鼮��Ϣ
void showBookDetail();
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
//�ж�ͼ���ظ�
int isBookRepeat(const char *isbn,const int index);
//�ж�ͼ���Ƿ�Ϊ
int isLibEmpty();
//�������������modeΪ0����������Ϊ1�����ѽ����Ϊ2����δ���
int countBooks(int mode);


// ��ȡ�û�
void loadUsers();
// �洢�û�
void saveUsers();
// �û��˵�
void userMenu(const int *user_index);
//ע���û�
void addUser();
//����Ա�޸��û�
void modUserAdm();
//����Ա��ʾ�û�
void showUsers();
// �ҵĽ���
void myLend(const int user_index);
//�û�����
void userLend(const int user_index);
// �û��黹
void userBack(const int user_index);
// �ҵĻ���
void userIntegral(const int user_index);
//����Ա�����û�
void manageUser();
// ����Աɾ���û�
void delUserAdm();
//��users.txt����ʱɾ��
void Rec();
//�����û�����
int countUsers();
//�û���Ϣ
int userLetter(const int user_index);
//ɾ���û�
int delUser(int user_index);
//�ж��û��ظ�
int isUserAvl(const int user_index);
//�ж��û��Ƿ�Ϊ��
int isUserEmpty();
//��ѯ�鼮,mode=1,2����isbn,��������
int searchBook(char *msg, int mode);
//�û�ID���û�������ת��.ģʽΪ0ʱ��ID->����
int ID2Index(const int n,int mode);


// �ж����������
int confirm(char *msg);
int confirml(const char *msg, char *m, void*a);



int main(){
	int input;
    loadUsers();
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
        GREEN;//��ɫ
        printf("4. �û�ע��\t         ");
        WHITE;//��ɫ
		printf("=\n=           ");
        RED;//��ɫ
        printf("9. �˳�\t         ");
        WHITE;//��ɫ
		printf("=\n==================================\n");
        GRAY;//��ɫ
		printf("������ : ");
        GREEN;//��ɫ
        // fflush(stdin);//���»�����
		scanf("%d",&input);
        WHITE;//��ɫ
		switch(input){
			case 1: login();break; 
			case 2: printf("�������ǣ�\n\t��ͼ��������ּ�ڽ�ͼ�����Ա\n�ӷ���ͼ�����ģʽ�����ȳ�ȥ��");break; 
			case 3: printf("���������������������ι��ս����������");break; 
            case 4: addUser();break;
			case 9: return 0;
            default : RED;printf("�����ʽ����,ϵͳ��Ĭ���˳���\n");WHITE;return 0;

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
        printf("=\n=          ");
        BLUE;//��ɫ
        printf("8. �����û�           ");
        WHITE;
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
            showBookDetail();
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
            printf("����������%d\n�ѽ����%d\nδ�����%d",countBooks(0),countBooks(1),countBooks(2));
            break;
        case 8:
            manageUser();
            break;
        case 0:
        WHITE;//��ɫ
            return ;
        }
        system("pause");
    }
}

// �û�����
void userMenu(const int *user_index)//�����Ǵ���������
{
    int input;

    while (1)
    {
        system("cls");
        system("color 02");//02��ǰһ��0Ϊ����ɫ����ɫ����һ��Ϊǰ��ɫ����ɫ����������û�ã���FOREGROUND_�����

        WHITE;//��ɫ
        printf("==================================\n=");
        BLUE;//��ɫ
        printf("       ��ӭ����%10s       ",users[*user_index].user_name);
        WHITE;//��ɫ
        printf("=\n==================================\n=");
        YELLOW;//��ɫ
        printf("          1. �ҵ���Ϣ      	 ");
        WHITE;//��ɫ
        WHITE;//��ɫ
        printf("=\n=          ");
        BLUE;//��ɫ
        printf("2. ��ѯͼ��      	 ");
        WHITE;//��ɫ
        printf("=\n=          ");
        CYAN;//��ɫ
        printf("3. �ҵĽ���      	 ");
        WHITE;//��ɫ
        printf("=\n=          ");
        YELLOW;//��ɫ
        printf("4. ����ͼ��      	 ");
        WHITE;//��ɫ
        printf("=\n=          ");
        PINK;//��ɫ
        printf("5. �黹ͼ��      	 ");
        WHITE;//��ɫ
        printf("=\n=          ");
        GREEN;//��ɫ
        printf("6. �ҵĻ���           ");
        WHITE;//��ɫ
        printf("=\n=");
        RED;//��ɫ
        printf("          0. �˳�ϵͳ           ");
        WHITE;//��ɫ
        printf("=\n");
        printf("==================================\n");
        GRAY;//��ɫ
        printf("������ : ");
        GREEN;//��ɫ
        scanf("%d", &input);
        WHITE;//��ɫ
        switch (input)
        {
        case 1:
            {if(userLetter(*(user_index))==1) {sys_user_id=0; return; system("pause");} }
            break;
        case 2:
            queryBook();
            break;
        case 3:
            myLend(*(user_index));
            break;
        case 4:
            userLend(*(user_index));
            break;
        case 5:
            userBack(*(user_index));
            break;
        case 6:
            userIntegral(*(user_index));
            break;
        case 0:
            {WHITE;//��ɫ
            sys_user_id=0;sys_user_index=0;return;}
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
        GREEN;//��ɫ
		printf("���������룺");
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

// ��¼
void login()
{
    char user[20];
    char pwd[20];
    GREEN;
    printf("�������û�ID��");
    BLUE;//��ɫ

    scanf("%s", user);
    sys_user_id=atoi(user);//�ַ���ת����
    sys_user_index=ID2Index(sys_user_id,0);//����ת����

    if(isalpha(user[0]))
        {
        if( strcmp(user,"admin")!=0 ) 
        {
            RED;
            printf("�û�ID������!\n");
            WHITE;
            return ;
        }}
    
    else if(isdigit(user[0]))
        {
        if(!isUserAvl(sys_user_index) || users[sys_user_index].user_id!=sys_user_id ) 
        {
            RED;
            printf("�û�ID������!\n");
            WHITE;
            return ;
        }}

    else {RED;printf("�û�ID������!\n");WHITE;return;}

    inputPwd(pwd, 20); //��������

    //�ַ����жϣ�����ǹ���Ա������ת������Ա����
    if (strcmp(user, "admin") == 0 && strcmp(pwd, "admin") == 0)
    {
        GREEN;
        printf("��¼�ɹ���\n");
        WHITE;
        adminMenu();
    }

    else if(isdigit(user[0]))
    {
        if (strcmp(pwd, users[sys_user_index].user_password) == 0)
        {   GREEN;
            printf("��¼�ɹ���\n");
            WHITE;
            userMenu(&sys_user_index);
        }
        else
        {   RED;
            printf("�������\n");
            WHITE;
            // login();
            return ;
        }
    }
    else
    {   RED;
        printf("��¼ʧ�ܣ�\n");
        WHITE;
        // login();
        return ;
    }
}

//�����û���Ϣ�ļ�
void saveUsers(){
	//��User�����ļ���user.txt��
	FILE*file;//�����ļ�ָ��
	file=fopen("users.txt","a+");//��׷��ģʽ��a�����ļ�
	//fileΪNULL ��ô��ʾ�ļ������ڣ�ϵͳ�ᴴ�����ļ�
	//����˵����1д�����ݶ���2д�����ݴ�С��3д�������4�ļ�ָ��
	fwrite(users,sizeof(users),1,file);
	fclose(file);//�ر��ļ� 
}

//��ȡ�û���Ϣ�ļ� 
void loadUsers(){//�����̼�׬Ǯ�ĵط���
    system("color 14");//����
	FILE*file;
	file=fopen("users.txt","r");//�Զ�ģʽ��r�����ļ�
	
	if(file !=NULL){
		//�ļ���ΪNULL���Ͷ�ȡ�ļ�
        while(1)
        {
            fread(users,sizeof(users),1,file);
            if(feof(file)) break;
        }
	}
    else {
        CONSOLE_CURSOR_INFO cursor_info = {1, 0};SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);//���ع��
        printf(":-(\n����ϵͳ��������,��Ҫ��������,���������Ѽ�����\n");
        Sleep(1000);
        int i=0;
        for( i=0;i<100;i++)
        {
            printf("%d%%",i);
            Sleep(50);
            printf("\b\b\b");
        }
        printf("��⵽��ʧusers.txt,���ڳ����Զ��޸�...\n");
            remove("users.txt");//ɾ���ļ�
        Sleep(1000);
        printf("��������ļ�...\n");
        Sleep(1000);
        printf("��ӳɹ���������������ָ��...\n");
        file=fopen("users.txt","w");//��дģʽ��w�����ļ��������������½��ļ�
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
            printf("��ϵ��ʽ��\nQQ:848484848\nEmail:");
            }
        exit(ERROR_READ);
    }
	fclose(file);
} 

//ע���û�
void addUser()
{
    int i;
    char c;

    // ���ҽṹ�������еĿ���λ��
    
        system("cls");
        system("color 02");//02��ǰһ��0Ϊ����ɫ����ɫ����һ��Ϊǰ��ɫ����ɫ����������û�ã���FOREGROUND_�����
        
        for (i = 0; i <= MAX_USERS_NUM; i++)
        {
            if (!users[i].user_id && i!=MAX_USERS_NUM) //����û�idΪ�գ�˵����λ�����û�
            {
                printf("�������û�����");
                scanf("%s", users[i].user_name);

                printf("�������û����룺");
                scanf("%s", users[i].user_password);

                users[i].user_id=ID2Index(i,1);//��ʼ���û�id
                users[i].integral=0;//��ʼ���û�����
                users[i].lendBooksIsbn[0][0]='\0';//��ʼ���û�����isbn
                users[i].lendBooksNum=0;//��ʼ���û���������

                printf("����û��ɹ�,�û�idΪ ");
                YELLOW;
                printf("%5d\n", users[i].user_id);
                WHITE;
                printf("�´ε�½��ʹ���û�id��¼\n");

                saveUsers(); // д���ļ�

                // printf("��������������˵�\n");
                c=getchar();//���˵����з�
                // c=getch();//�ȴ��û����������
                break;
            }
            if(i==MAX_USERS_NUM)//���û�п���λ�ã�˵���Ѿ�����
                break;
            
        }

            if(i==MAX_USERS_NUM)//���û�п���λ�ã�˵���Ѿ�����
            {
                RED;
                printf("���ʧ��,�Ƿ����Recovery?(y/n)");
                WHITE;
                c=getch();
                if(c=='y')
                Rec();
            }
     return;
        
    
}

//����Ա����û�
void addUserAdm()
{
    int i;
    // char key;
    GREEN;
    // ���ҽṹ�������еĿ���λ��
    for (i = 0; i <= MAX_USERS_NUM; i++)
        if (strlen(users[i].user_name) == 0) //����û�idΪ�գ�˵����λ�����û�
        {

            printf("�������û�����");
            scanf("%s", users[i].user_name);

            printf("�������û����룺");
            scanf("%s", users[i].user_password);

            users[i].user_id=ID2Index(i,1);//��ʼ���û�id

            printf("�����û��֣�");
            while(scanf("%d",&users[i].integral))
            {
                if(users[i].integral<0) printf("�û������޷�Ϊ��ֵ,���������룺");
                else break;
            }
            GREEN;
            printf("������vip�ȼ���");
            while(scanf("%d",&users[i].vip))
            {
                RED;
                if(users[i].vip<0||users[i].vip>TOP_VIP_GRADE) {
                    printf("VIP�ȼ�ֻ��Ϊ0-%d��,���������룺",TOP_VIP_GRADE);
                    GREEN;
                }
    
                else break;
            }

            saveUsers(); // д���ļ�

            printf("����û��ɹ�,�û�idΪ ");
            YELLOW;
            printf("%5d\n", users[i].user_id);
            WHITE;
            break;
        }

    if (i == MAX_USERS_NUM){
        RED;
        printf("�û�������");
        GREEN;
    }
       
    else
        printf("����ɹ���");
}

//�û���Ϣ
int userLetter(const int user_index)
{
    char key;
    char pswd[20];
    char pswd1[20];//�û�����

	printf("%10s %10s %10s %10s\n","�û�ID","�û���","�û�����","VIP״̬");
    
    GRAY;//��ɫ
			printf("%10d %10s %10d %8d��",
                users[user_index].user_id,
                users[user_index].user_name,
                users[user_index].integral,
                users[user_index].vip);
            printf("\n");
	
    WHITE;//��ɫ


    printf("\n");
    printf("�޸�����:\t[1]\n");
    printf("�鿴������Ϣ:\t[2]\n");
    printf("ע���û�:\t[9]\n");
    printf("�˳�:\t\t[0]\n");

    GRAY;
    printf("��ѡ��");
    WHITE;
    getchar();//���˵��س�
    scanf("%c", &key);
    // key=getchar();

    if(key=='1'){
            printf("����������룺");
            while(scanf("%s",pswd))
            {
            if(strcmp(pswd,users[user_index].user_password)==0)
            {
                printf("�����������룺");
                inputPwd(pswd, 20);//��������
                printf("���ٴ����������룺");
                inputPwd(pswd1, 20);//��������

                if(strcmp(pswd,pswd1)==0&&strcmp(pswd,users[user_index].user_password)!=0)
                {
                    strcpy(users[user_index].user_password,pswd);
                    saveUsers();
                    printf("�޸ĳɹ���\n");
                    break;//�˳�ѭ��
                }
                else if(strcmp(pswd,pswd1)==0&&strcmp(pswd,users[user_index].user_password)==0)
                {
                    YELLOW;    
                    printf("���������������ͬ�����������룡\n");
                    WHITE;
                    printf("����������룺");
                }
                else
                {
                    YELLOW;
                    printf("�����������벻һ�£����������룡\n");
                    WHITE;
                    printf("����������룺");
                }

                saveUsers();
                GREEN;
                printf("�޸ĳɹ���\n");
                WHITE;
            }
            else
            {
                RED;
                printf("����������������룺\n�����룺");
                WHITE;
            }
            }
    }
    else if(key=='2') myLend(user_index);
    else if(key=='9') {if(delUser(user_index)==1) {main();return 1;}else userLetter(user_index);}
    else if(key=='0') return 0;
    else {RED;printf("������������˳�...\n");WHITE;Sleep(1000);return 0;}
    
    return 0;

}

//�û�ע���û���ֻ�ڵ�½ʱʹ��
int delUser(int user_index){
    char passwd[20];//��֤��
    char key;
    RED;
    if(users[user_index].lendBooksNum)//����û��н���
    {
        printf("����ͼ��δ�黹����黹�����ԣ�\n");
        getchar();
        return 0;
    }
    printf("��ȷ��Ҫע������˺���(Y/N)\n");
    WHITE;
    getchar();//���˵��س�
    scanf("%c",&key);

    if(key=='Y'||key=='y'){
        printf("����֤���룺");
        // scanf("%d",&passwd);
        inputPwd(passwd,20);

        if(strcmp(passwd,users[user_index].user_password)==0)
        {
            
            users[user_index].user_id=0;
            users[user_index].integral=0;
            users[user_index].vip=0;
            users[user_index].lendBooksNum=0;//����û���������
            strcpy(users[user_index].user_name,"");
            strcpy(users[user_index].user_password,"");
            memset(&users[user_index],0,sizeof(struct Users));//����û���Ϣ
            saveUsers();//����
            GREEN;
            printf("ע���ɹ�����������˳�\n");
            WHITE;
            getchar();
            return 1;
        }
        else{
            RED;
            printf("�������\n");
            WHITE;
            return 0;
        }
    }
    else{
        YELLOW;
        printf("�������û�ȡ����\n");
        WHITE;
    }

    return 0;
    
}

//����Ա��ʾ�û�
void showUsers()
{
    if(isUserEmpty())
    {   
        YELLOW;
        printf("�û��б�Ϊ�գ�\n");
        WHITE;
        return;
    }
    int i;

	printf("%10s %20s %10s %10s\n","�û�ID","�û���","�û�����","VIP״̬");
    
    GRAY;//��ɫ
	for(i=0;i<MAX_USERS_NUM;i++){
		if(strlen(users[i].user_name)>0)//�û�����Ϊ�գ�˵���û�����
        {
			printf("%10d %20s %10d %10d��",
            users[i].user_id,
            users[i].user_name,
			users[i].integral,
			users[i].vip);
            printf("\n");
		}
	}
    WHITE;//��ɫ
}

//�޸���Ϣ
void modUserAdm()
{
    if(isUserEmpty())
    {   
        YELLOW;
        printf("�û��б�Ϊ�գ�\n");
        WHITE;
        return;
    }
    int id;
    char key;  //����İ���
    
    GRAY;//��ɫ
    printf("�Ƿ��г��û��б�(Y/N)?\n");
    key=getch();
    if(key=='y'||key=='Y') showUsers();

    printf("������Ҫ�޸ĵ��û�ID: ");
    while(scanf("%d",&id))
    {
        id=ID2Index(id,0);//ת��Ϊ����
        if(isUserAvl(id)) break;//�û����ڣ��˳�ѭ��
        else printf("�û������ڣ����������룺");
    }


        if (strlen(users[id].user_name)>0)
        {
            WHITE;//��ɫ
            printf("��ѯ�ɹ����ҵ��û���\n");
            GRAY;
            printf("�û�ID: %d\n",users[id].user_id);
            printf("�û���: %s\n",users[id].user_name);
            printf("�û�����: %d\n",users[id].integral);
            printf("VIP�ȼ�: %d��\n",users[id].vip);
            WHITE;//��ɫ

            YELLOW;//��ɫ
            printf("�Ƿ�ʼ�޸�?[Y]\n");
            WHITE;
            key = getch();
            if (key != 'y' && key != 'Y') {
                RED;//��ɫ
                printf("�������û�ȡ���� \n");
                return ;
            }

            YELLOW;
            //��ʾ�û��Ƿ��޸�ÿ���ֶ�
            printf("��ȷ���Ƿ�Ҫ�޸��û���(Y/N)?\n");
            WHITE;
            key = getch();
            if (key == 'y' || key == 'Y') {
                printf("������:");
                scanf("%s", users[id].user_name);
                printf("�޸ĳɹ���\n");
            }

            YELLOW;
            printf("��ȷ���Ƿ�Ҫ�޸�����(Y/N)?\n");
            WHITE;
            key = getch();
            if (key == 'y' || key == 'Y') {
                printf("������:");
                scanf("%s", users[id].user_password);
                printf("�޸ĳɹ���\n");
            }

            YELLOW;
            printf("��ȷ���Ƿ�Ҫ�޸Ļ���(Y/N)?\n");
            WHITE;
            key = getch();
            if (key == 'y' || key == 'Y') {
                printf("������:");
                while(scanf("%d", &users[id].integral))
                {
                    if(users[id-1].integral<0){
                        RED;
                        printf("�����趨��������������\n");
                        WHITE;
                    }
                    
                    else 
                    {
                        GREEN;
                        printf("�޸ĳɹ���\n");
                        WHITE;
                        break;
                    }
                }
            }

            YELLOW;
            printf("��ȷ���Ƿ�Ҫ�޸�VIP�ȼ�(Y/N)?\n");
            WHITE;
            key = getch();
            if (key == 'y' || key == 'Y') {
                printf("������(0-%d):",TOP_VIP_GRADE);
                while(scanf("%d", &users[id].vip))
                {
                    if(users[id-1].integral<0||users[id-1].vip>TOP_VIP_GRADE)
                    {
                        RED;
                        printf("VIP�ȼ��趨��������������\n");
                        WHITE;
                    }
                    
                    else 
                    {
                        GREEN;
                        printf("�޸ĳɹ���\n");
                        WHITE;
                        break;
                    }
                }
            }



            saveUsers();
            GREEN;
            printf("\n�û���Ϣ�޸ĳɹ�!\n");
            WHITE;

            return;
        }
    RED;
    printf("û�и��û���\n");
    WHITE;
    return ;
}

//����Ա�����û�
void manageUser()
{
    // int id;
    char key;  //����İ���
    int key_num;//���������
    
    GRAY;//��ɫ
    printf("�Ƿ��г��û��б�(Y/N)?\n");
    key=getch();
    if(key=='y'||key=='Y') showUsers();
    
    YELLOW;
    printf("��ѡ��Ҫִ�еĲ���:\n");

    WHITE;printf("1.");GRAY;printf("ɾ���û�\n");
    WHITE;printf("2.");GRAY;printf("�޸��û�\n");
    WHITE;printf("3.");GRAY;printf("����û�\n");
    WHITE;printf("0.");GRAY;printf("����\n");
    WHITE;

    while(scanf("%d",&key_num))
    {
        if(key_num==2){modUserAdm();break;}
        else if(key_num==1) {delUserAdm();break;}
        else if(key_num==3){addUserAdm();break;}
        else if(key_num==0){break;return;}
        else {RED;printf("�������\n");WHITE;}
    }
    return ;
}

//����Աɾ���û�
void delUserAdm()
{
    if(isUserEmpty())
    {
        RED;//��ɫ
        printf("�û��б�Ϊ�գ�\n");
        WHITE;
        return ;
    }
    char key;//����İ���
    int id;
    char yn[20];//����ȷ��ɾ��

    RED;
    printf("�Ƿ�ȫ��ɾ��ȫ���û�?����ܵ�������ĺ��(y/n)\n");
    WHITE;
    key=getch();

    if(key=='y'||key=='Y')
    {
        printf("������");RED;printf("yes");WHITE;printf("�Լ�������:");
        scanf("%s",yn);
        if(strcmp(yn,"yes")!=0){
            printf("����ȡ����\n");
            return ;
        }
        remove("users.txt");//ɾ���ļ�
        FILE *file;//���¶���ָ���������ļ�
        file=fopen("users.txt","w");//��дģʽ��w�����ļ��������������½��ļ�
        GREEN;
        printf("ɾ���ɹ���\n");
        WHITE;
        fclose(file);//�ر��ļ�
        
        memset(users,0,sizeof(users));//��սṹ����
        
        return;
    }



    GRAY;//��ɫ
    printf("�Ƿ��г��û��б�(Y/N)?\n");
    key=getch();
    if(key=='y'||key=='Y') showUsers();

    printf("��ʼ����ɾ���û�������(Y/N)\n");
    getchar();//���˵��س�
    scanf("%c",&key);

    if(key=='y'||key=='Y')
    {
            printf("������Ҫɾ�����û���ID: ");
            while(scanf("%d",&id))
            {
                id=ID2Index(id,0);//ת��IDΪ����
                if(isUserAvl(id)) break;//�û����ڣ��˳�ѭ��
                else {
                    RED;
                    printf("�û������ڣ����������룺");
                    WHITE;
                }
            }


            users[id].user_id=0;
            users[id].integral=0;
            users[id].vip=0;
            strcpy(users[id].user_name,"");
            strcpy(users[id].user_password,"");
            memset(&users[id],0,sizeof(struct Users));//����û���Ϣ
            saveUsers();//����
            GREEN;
            printf("ע���ɹ�����������˳�\n");
            WHITE;
    }
    else {
        RED;
        printf("����������Աȡ������������˳�\n");
        WHITE;
    }
    getchar();  
    return ;

}

//ɾ��user.txt�ļ�
void Rec()
{
    remove("users.txt");//ɾ���ļ�
    return ;
}

// �ҵĻ���
void userIntegral(const int user_index)
{
    if(users[user_index].vip==TOP_VIP_GRADE){
        YELLOW;
        printf("��ǰ�˻�����ʣ�ࣺ%d\n",users[user_index].integral);
        printf("��ǰ�û�VIP�ȼ�Ϊ��%d\n",users[user_index].vip);
    }
    else{
        WHITE;
        printf("��ǰ�˻�����ʣ�ࣺ%d\n",users[user_index].integral);
        printf("��ǰ�û�VIP�ȼ�Ϊ��%d\n",users[user_index].vip);
    }

    if(users[user_index].integral >= TOP_POINTS && users[user_index].vip < TOP_VIP_GRADE) {
        GRAY;
        printf("���Ļ��ֿ��Խ��жһ�VIP�ȼ�,�Ƿ�һ�VIP�ȼ���[Y]\n");
        WHITE;
    }
    else if(users[user_index].vip==TOP_VIP_GRADE) {YELLOW;printf("����Ϊ����VIP8�û�������Ϊ���˳�...\n");WHITE;return ;}
    else return ;
    char yn;
    yn=getch();
    if(yn!='Y'&&yn!='y')
    {
        YELLOW;
        printf("�û�ȡ���˲����������˳�...");
        WHITE;
        return ;
    }

    int wantUP=0;//�û���Ҫ������VIP�ȼ�
    BLUE;
    printf("��������Ҫ�һ���VIP�ȼ���");
    WHITE;
    while(scanf("%d",&wantUP))
    {

    if(wantUP+users[user_index].vip > TOP_VIP_GRADE)
    {
        RED;
        printf("��ߵ�VIP�ȼ�Ϊ%d�������������룺\n",TOP_VIP_GRADE);
        WHITE;
        // scanf("%d",&wantUP);
    }
    else if(users[user_index].integral/TOP_POINTS < wantUP)
    {
        RED;
        printf("���Ļ��ֲ����Զһ���VIP�ȼ������������룺");
        WHITE;
        // scanf("%d",&wantUP);
    }
    else
    {
        users[user_index].vip+=wantUP;
        users[user_index].integral-=wantUP*TOP_POINTS;
        saveUsers();//����
        GREEN;
        printf("�һ��ɹ���\n");
        WHITE;
        break;
    }
    }
    return ;
}

//�ж��û��Ƿ�Ϸ�
int isUserAvl(const int user_index){
    if(user_index>MAX_USERS_NUM||user_index<0) return 0;//�û�ID���Ϸ�������0
    if(users[user_index].user_name) return 1;//�û�����
    return 0;
}

//�����û�����
int countUserNum()
{
    int i;
    int num=0;
    for(i=0;i<MAX_USERS_NUM;i++)
    {
        if(users[i].user_id) num++;//�û����ڣ�������1
    }
    LibR.userNum=num;//�����û�����
    LibR.isUserEmpty=1;//��ʼ��Ϊ1����ʾΪ��
    if(num!=0) LibR.isUserEmpty=0;//����û����ڣ���Ϊ0
    return num;
}

//�ж��Ƿ�û���û�
int isUserEmpty(){
    countUserNum();//�����û�����
    return LibR.isUserEmpty;
}

//�û�ID���û�������ת��
int ID2Index(const int n,int mode)
{
    int change=1001;//�û�ID���û�������ת��ֵ
    if(mode==0) return n-change;//ģʽΪ0ʱ�����û�IDת��Ϊ�û�����
    else return n+change;//ģʽΪ1ʱ�����û�����ת��Ϊ�û�ID
}

//����ȷ��
int confirm(char *mag)
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
        GREEN;
        printf("�����룺\n");
        WHITE;
        return 1;
    }
/* 
���û�ȷ������ĺ������û�����N/n����0����������1
msg��ʾ��ʾ�û���������� */
}

//����ȷ��1
int confirml(const char *msg , char *m, void *a)
{
    char key;
    printf(msg);

    key=getch();

    if(key=='N'||key=='n')
    {
        printf("\n");
        return 0;
    }
    
    else
    {   
        GREEN;
        printf("�����룺");
        WHITE;
        scanf(m,a);
        return 1;
    }
}


























//�鿴�鼮
void queryBook(){
    if(isLibEmpty()) {printf("�޲��飡\n");return;}

    BLUE;
	printf("  ���   %20s %10s %10s %20s %20s %10s\n", "����","����","�۸�","������","ISBN","����״̬");
    WHITE;
    int showindex=1;//��ʾ����
    
    GRAY;//��ɫ
    int i=0;
	for( i=0;i<MAX_BOOKS_NUM;i++){
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
 
//��ʾ�鼮����
void showBookDetail()
{
    char msg[20];
    queryBook();
    if(isLibEmpty()){return;}

    int bookindex=1;

    printf("��ʾ�鼮����?(����ISBN[I]/��������[N]/ȡ��[E])\n");
    char key=getch();
    if(key=='E'||key=='e') {printf("������ȫ����ɣ������˳�...\n");return;}
    else if(key=='I'||key=='i') 
        {        
            GRAY;printf("������Ҫ��ϸ�鿴���鼮��ISBN:");WHITE;
            scanf("%s",msg);
                bookindex=searchBook(msg,1);//�����鼮����
                if(bookindex==-1) {printf("û���ҵ����鼮��");return;}
            
        }
    else if(key=='N'||key=='n') 
        {        
            GRAY;printf("������Ҫ��ϸ�鿴���鼮������:");WHITE;
            scanf("%s",msg);
            {
                bookindex=searchBook(msg,2);//�����鼮����
                if(bookindex==-1) {printf("û���ҵ����鼮��");return;}
            }
        }
    else {RED;printf("δ֪�����������˳�...\n");WHITE;return;}

        printf("\n�ҵ��鼮��\n");
        GRAY;
        printf("����:\t\t%s\n",books[bookindex].name);
        printf("ISBN:\t\t%s\n",books[bookindex].isbn);
        printf("����:\t\t%s\n",books[bookindex].author);
        printf("�۸�:\t\t%.2f\n",books[bookindex].price);
        printf("������:\t\t%s\n",books[bookindex].press);
        if(books[bookindex].isLend) 
        {
            printf("����״̬:\t�ѽ��\n");
            printf("�����û�:\t%s\n",books[bookindex].name);
            printf("�û�ID:\t\t%d\n",books[bookindex].lenduserid);
            printf("��ע:\t\t%s\n",books[bookindex].lendMessage);
            }
        else printf("����״̬:\tδ���\n");
        WHITE;
        return ;
    
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
                    {YELLOW;printf("���д���,���������룺");WHITE;}
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
                    {YELLOW;printf("�۸��趨��������������۸�\n");WHITE;}
                    else break;
                }

            printf("����������磺");
            scanf("%s", books[i].press);

            books[i].isLend=0;//��ʼ��Ϊδ���
            books[i].lendMessage[0]='\0';//��ʼ��Ϊ���ַ���
            books[i].lenduserid=0;//��ʼ��Ϊ0


            saveBooks(); // д���ļ�
            break;
        }

    if (i == MAX_BOOKS_NUM)
        {RED;printf("���������");WHITE;}
    else
        {GREEN;printf("����ɹ���");WHITE;}}

// ��ȡ�ļ� 
void loadBooks(){//�����̼�׬Ǯ�ĵط���
    system("color 14");//����
	FILE*file;
	file=fopen("books.txt","r");//�Զ�ģʽ��r�����ļ�
	
	if(file !=NULL){
		//�ļ���ΪNULL���Ͷ�ȡ�ļ�
        while(1)
        {
            fread(books,sizeof(books),1,file);
            if(feof(file)) break;
        }
	}
    else {
        CONSOLE_CURSOR_INFO cursor_info = {1, 0};SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);//���ع��
        printf(":-(\n����ϵͳ��������,��Ҫ��������,���������Ѽ�����\n");
        Sleep(1000);
        int i=0;
        for( i=0;i<100;i++)
        {
            printf("%d%%",i);
            Sleep(50);
            printf("\b\b\b");
        }
        printf("��⵽��ʧbooks.txt,���ڳ����Զ��޸�...\n");
            remove("books.txt");//ɾ���ļ�
        Sleep(1000);
        printf("��������ļ�...\n");
        Sleep(1000);
        printf("��ӳɹ���������������ָ��...\n");
        file=fopen("books.txt","w");//��дģʽ��w�����ļ��������������½��ļ�
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
            printf("��ϵ��ʽ��\nQQ:848484848\nEmail:");
            }
        exit(ERROR_READ);
    }
	fclose(file);
} 

// �洢�鼮��Ϣ�ļ�
void saveBooks(){
	//��books�����ļ���books.txt��
	FILE*file;//�����ļ�ָ��
	file=fopen("books.txt","a+");//��׷��ģʽ��a�����ļ�
	//fileΪNULL ��ô��ʾ�ļ������ڣ�ϵͳ�ᴴ�����ļ�
	//����˵����1д�����ݶ���2д�����ݴ�С��3д�������4�ļ�ָ��
	fwrite(books,sizeof(books),1,file);
	fclose(file);//�ر��ļ� 
}

// ɾ��ͼ��
void delBook() {
    //��isbn����ͼ��
    
    if(isLibEmpty()) {YELLOW;printf("�޲��飡�����˳�...\n");WHITE;return;}
    char isbn[20];
    int i;
    char yn[10];

    char key;//������
    RED;
    printf("�Ƿ�ȫ��ɾ��?(y/n)\n");
    WHITE;
    key=getch();

    if(key=='y'||key=='Y')
    {
        printf("������:");RED;printf("yes");WHITE;printf("�Լ�������:");
        scanf("%s",yn);
        if(strcmp(yn,"yes")!=0){
            printf("����ȡ����\n");
            goto ctn;
        }
        remove("books.txt");//ɾ���ļ�
        FILE *file;//���¶���ָ���������ļ�
        file=fopen("books.txt","w");//��дģʽ��w�����ļ��������������½��ļ�
        GREEN;
        printf("ɾ���ɹ���\n");
        WHITE;
        fclose(file);//�ر��ļ�
        
        for( i=0;i<MAX_BOOKS_NUM;i++)//ѭ��ɾ��
        {
            if(books->isbn)
            {
                books[i].isbn[0]='\0';
                books[i].name[0]='\0';
                books[i].author[0]='\0';
                books[i].press[0]='\0';
                books[i].price=0;
                books[i].isLend=0;
                books[i].lenduserid=0;
                books[i].lendMessage[0]='\0';
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
            printf("��ȷ���Ƿ�Ҫɾ����ͼ��(Y/N)");
            scanf("%s", yn);
            if (strcmp(yn, "y") == 0 || strcmp(yn, "Y") == 0) {
                strcpy(books[i].isbn, "");
                strcpy(books[i].name, "");
                strcpy(books[i].press, "");
                books[i].price = 0;
                memset(&books[i],0,sizeof(struct Book));//����鼮��Ϣ

                //д���ļ�
                saveBooks();
                printf("ͼ��ɾ���ɹ�! \n");
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
    printf("�Ƿ��г�ͼ���б�(Y/N)?\n");
    key=getch();
    if(key=='y'||key=='Y') queryBook();

    printf("������Ҫ�޸ĵ�ͼ���ISBN: ");
    scanf("%s", isbn);
    for (i = 0; i < MAX_BOOKS_NUM; i++) {
        if (strcmp(books[i].isbn, isbn) == 0)
        {
            WHITE;//��ɫ
            printf("��ѯ�ɹ����ҵ�ƥ���鼮��\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY);//��ɫ
            printf("\n\t||����: \t%s\n", books[i].name);
            printf("\t||����: \t%s\n", books[i].author);
            printf("\t||�۸�: \t%10.2f\n", books[i].price);
            printf("\t||�����磺\t%s\n\n", books[i].press);

            YELLOW;//��ɫ
            printf("�Ƿ�ʼ�޸�(Y/N)?\n");
            key = getch();
            if (key == 'n' || key == 'N') {
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

            printf("��ȷ���Ƿ�Ҫ�޸�����(Y/N)?\n");
            key = getch();
            if (key == 'y' || key == 'Y') {
                printf("������:");
                scanf("%s", books[i].author);
                printf("�޸ĳɹ���\n");
            }

            printf("��ȷ���Ƿ�Ҫ�޸ļ۸�(Y/N)?\n");
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

            printf("��ȷ���Ƿ�Ҫ�޸ĳ�����(Y/N)?\n");
            key = getch();
            if (key == 'y' || key == 'Y') {
                printf("������:");
                scanf("%s", books[i].press);
                printf("�޸ĳɹ���\n");
            }
            saveBooks();

            GREEN;
            printf("\nͼ���޸ĳɹ�!\n");
            WHITE;

            return;
        }
    }
    RED;
    printf("û�и�ͼ�飡\n");
    WHITE;
}

// ���˽�����Ϣ
void myLend(const int user_index)
{
    int i=0;
    int bookindex=1;//�Ƿ��н����¼
    if(users[user_index].lendBooksNum)//����н赽��
    
    for( i=0;i<11;i++)
    {
        if(strlen(users[user_index].lendBooksIsbn[i])) //����н���
        {
            printf("��%2d��.ISBN:%s\n",bookindex++,users[user_index].lendBooksIsbn[i]);
        }
    }
    else {BLUE;printf("����ǰû�н��飬��ȥ����ɣ�\n");WHITE;}
}

//�û�����
void userLend(const int user_index){

    int book_lend_avl=0;//�Ƿ����ڿ��鼮
    int i=0;

    if(users[user_index].lendBooksNum>=10)//����Ѿ�����10������
    {
        printf("���Ѿ�����10������,�����ٽ��ˣ�\n");
        return ;
    }
    GRAY;
    printf("�Ƿ��г��鼮�б�(Y/N)?\n");
    WHITE;
    char key=getch();
    if(key=='y'||key=='Y') queryBook();

    GRAY;
    printf("�Ƿ�ʼ����?(Y/N)\n");
    WHITE;
    key=getch();
    if(key=='n'||key=='N') 
    {
        RED;
        printf("����ȡ����\n");
        return ;
        WHITE;
    }
    
    for( i=0;i<MAX_BOOKS_NUM;i++)
    {
        if(books[i].isLend!=1 && strlen(books[i].isbn))//����鼮δ���������
        {book_lend_avl=1;break;}//����ɽ�
    }

    if(!book_lend_avl) {RED;printf("û�пɽ���鼮��\n");WHITE;return ;}//û�пɽ���鼮

    GRAY;
    printf("������Ҫ���ĵ��鼮��ISBN:");
    WHITE;
    char isbn[20];
    scanf("%s",isbn);
    WHITE;

    for( i=0;i<MAX_BOOKS_NUM;i++)
    {
        if(strcmp(books[i].isbn,isbn)==0)//����ҵ����鼮
        {
            if(books[i].isLend) //����鼮�Ѿ��������
            {
                RED;
                printf("���鼮�Ѿ�������ˣ�\n");
                WHITE;
                return ;
            }
            else //����鼮û�б����
            {
                WHITE;
                books[i].isLend=1;//���Ϊ�Ѿ����
                books[i].lenduserid=ID2Index(user_index,1);//�������ߵ�id��¼���鼮��Ϣ��
                int j=0;
                for( j=0;j<10;j++)
                {
                    if(!strlen(users[user_index].lendBooksIsbn[j]))//������û����黹û����10��
                    {
                        strcpy(users[user_index].lendBooksIsbn[j],books[j].isbn);//���鼮��ISBN�����û��Ľ����¼��
                        users[user_index].lendBooksNum++;//����������1
                        break;
                    }
                }
                saveBooks();//�����鼮��Ϣ
                saveUsers();//�����û���Ϣ
                GREEN;
                printf("���ĳɹ���\n");
                WHITE;
                return ;
            }
        }
    }
}

// �û��黹
void userBack(const int user_index)
{
    if(!users[user_index].lendBooksNum)//���û�н���
    {
        PINK;
        printf("����û�н���ร���ȥ����ɣ�\n");
        WHITE;
        return ;
    }

    int bookFind=0;
    int i=0;
    GRAY;
    printf("�Ƿ��г����Ľ����鼮�б�(Y/N)?\n");
    WHITE;
    char key=getch();
    if(key=='y'||key=='Y') myLend(user_index);
    GRAY;
    printf("������Ҫ�黹���鼮��ISBN:");
    WHITE;
    char isbn[20];
    scanf("%s",isbn);
    
    for( i=0;i<10;i++)
    {
        if(strcmp(users[user_index].lendBooksIsbn[i],isbn)==0)//����û��н��Ȿ��
        {
            int book_index=0;//�鱾��ͼ����е�����
            book_index=searchBook(isbn,1);//�����鼮��ͼ����е�����
            bookFind=1;//�ҵ����鼮
            books[book_index].isLend=0;//���Ϊδ���
            books[book_index].lenduserid=0;//��ս����û�ID
            strcpy(books[book_index].lendMessage,"");//��ձ�ע
            users[user_index].lendBooksNum-=1;//����������1
            users[user_index].integral+=1;//���ּ�һ
            strcpy(users[user_index].lendBooksIsbn[i],"");//��ս����¼�е��鼮ISBN
            saveBooks();//�����鼮��Ϣ
            saveUsers();//�����û���Ϣ
            printf("�黹�ɹ���\n");
            return ;
        }
    }
    
    if(!bookFind) {BLUE;printf("û���ҵ����鼮�����������ƺ�û�н���Ȿ����\n");WHITE;}
}

//�ж��鼮�ظ�
int isBookRepeat(const char *isbn,const int index)
{
    int j;
    for(j=0;j<MAX_BOOKS_NUM;j++)
    {
        if(strcmp(books[j].isbn,isbn)==0&&j!=index)//������ظ���isbn
        {
            return 1;
        }
    }
    return 0;
}

// ����Ա���ͼ��
void lendBooks() {
    
    int book_lend_avl;//ͼ���Ƿ�ɽ�
    int i=0;

    if(!countBooks(2)) {YELLOW;printf("�޿ɽ�����飡\n");WHITE;return;}
    char isbn[20];//Ҫ������鼮��isbn����
    char yn[10];
    char key;
    int userid;//Ҫ���鼮���û�id
    int userindex;//Ҫ������û�����
    int flagbookindex=-1;//���ͼ����books�����е�λ��

    for( i=0;i<MAX_BOOKS_NUM;i++)//����books����
    {
        if(books[i].isLend!=1&&strlen(books[i].isbn)!=0)//�����ͼ��δ���
        {
            book_lend_avl=1;//���ͼ����books�����е�λ��
            break;
        }
    }

    if(book_lend_avl==0)//�������ͼ�鶼�ѽ��
    {
        YELLOW;
        printf("�޿ɽ��ͼ�飡\n");
        WHITE;
        return;
    }

    
    
    GRAY;//��ɫ
    printf("�г�ͼ���б�?[Y]\n");
    WHITE;
    key=getch();
    if(key=='y'||key=='Y') queryBook();

    GRAY;
    printf("��ʼ����?    [Y]\n");
    WHITE;
    key = getch();
    if (key != 'y' && key != 'Y') {
        RED;//��ɫ
        printf("�������û�ȡ���� \n");
        WHITE;
        return ;
    }
    WHITE;//��ɫ

    printf("����������ߵ��û�ID��");
    while(scanf("%d",&userid))//�ж��û�id�Ƿ�Ϸ�
    {   
        userindex=ID2Index(userid,0);//���û�idת��Ϊ�û���users�����е�λ��
        if(!isUserAvl(userindex)) {RED;printf("�û������ڣ�����������:");WHITE;}
        else if(users[userindex].lendBooksNum>=10) {YELLOW;printf("�û���������������������:");WHITE;}
        else break;
    }

    GRAY;
    printf("������Ҫ�����ͼ��ISBN��");
    WHITE;
    while(scanf("%s",isbn))//�ж�ͼ���Ƿ����
    {   
        flagbookindex=searchBook(isbn,1);
        if(flagbookindex==-1) {RED;printf("ͼ�鲻���ڣ�����������:");WHITE;}
        else if(flagbookindex!=-1 && books[flagbookindex].isLend==1) {YELLOW;printf("ͼ���ѽ��������������:");WHITE;}
        else {BLUE;printf("�ҵ�ͼ�飺\n");break;}
    }

    GRAY;//��ɫ
    printf("��      �� : \t%s\n", books[flagbookindex].name);
    printf("��      �� : \t%s\n", books[flagbookindex].author);
    printf("��      �� : \t%10.2f\n", books[flagbookindex].price);
    printf("��  ��  �� : \t%s\n", books[flagbookindex].press);
    printf("�� �� ״ ̬: \t%s\n", books[flagbookindex].isLend == 1 ? "���" : "�ڿ�");

    printf("��ȷ���Ƿ�Ҫ�����ͼ��(Y/N)?");
    WHITE;
    scanf("%s", yn);
    GRAY;
    if (strcmp(yn,"y") == 0 || strcmp(yn,"Y") == 0)
    {
        books[flagbookindex].isLend = 1;//��ͼ��Ľ��״̬��Ϊ1
        books[flagbookindex].lenduserid = userid;//��ͼ��Ľ����id��Ϊ�û�id
        printf("�����뱸ע:");
        scanf("%s", books[flagbookindex].lendMessage);//��ͼ��Ľ�����ڸ�Ϊ��ǰ����
        users[userindex].lendBooksNum+=1;//���û��Ľ���������1
        
        for( i=0;i<11;i++)
        {
            if(users[userindex].lendBooksNum>=10) {printf("���û����������������˳�...");return;}//����û�������������ֱ���˳�
            else if(strlen(users[userindex].lendBooksIsbn[i])==0)//������û��Ľ���isbn����Ϊ�գ���ֱ�����
            {
                strcpy(users[userindex].lendBooksIsbn[i],isbn);//��ͼ���isbn�����û��Ľ���isbn������
                break;
            }
        }

        saveBooks();//����ͼ����Ϣ
        saveUsers();//�����û���Ϣ
        GREEN;
        printf("����ɹ���\n");
    }
    else {RED;printf("ȡ�������\n");}

    WHITE;//��ɫ
    return;
}

// ����Ա�黹ͼ�� 
void backBooks() {

    if(countBooks(1)==0){GREEN;printf("û���鼮�����ģ�\n");return;}
	int backuserid;//������û�id
    int backuserindex;//������û�index
    int flagbookindex=-1;//���ͼ����books�����е�λ��
    char isbn[20] = "";
    char key;
    int i=0;

    

    WHITE;
	
    
    // �����û���ţ����ҽ��ļ�¼
    GRAY;
    printf("������Ҫ�黹���û�ID��");
    WHITE;
    while(scanf("%d",&backuserid))//�ж��û�id�Ƿ�Ϸ�
    {   
        backuserindex=ID2Index(backuserid,0);//���û�idת��Ϊ�û���users�����е�λ��
        if(!isUserAvl(backuserindex)) {RED;printf("�û������ڣ�����������:");WHITE;}
        else break;
    }

    GRAY;
    printf("%s�Ľ��������\n", users[backuserindex].user_name);
    int shownum=1;//��¼�Ѿ���ʾ��ͼ������
    if(users[backuserindex].lendBooksNum == 0) {YELLOW;printf("��û�н��飡\n");return;}
    else
    {
        YELLOW;
        printf("������ %d ����\n", users[backuserindex].lendBooksNum);
        WHITE;
        for( i=0;i<10;i++)
        {
            printf("��%2d��.\tISBN��%s\n", shownum++, users[backuserindex].lendBooksIsbn[i]);//��ӡ�û��Ľ���isbn����
            // if(strlen(users[backuserindex].lendBooksIsbn[i])==0) break;//������û��Ľ���isbn����Ϊ�գ���ֱ���˳�
            if(shownum>users[backuserindex].lendBooksNum) break;//����Ѿ���ʾ��ͼ�����������û��Ľ�����������ֱ���˳�
        }
    }
    
    GRAY;
    printf("������Ҫ�黹��ͼ��ISBN��");
    WHITE;
    while(scanf("%s", isbn))//��ȡͼ��isbn
    {
        flagbookindex=searchBook(isbn,1);//����ͼ�飬��������
        if(flagbookindex==-1) {RED;printf("ͼ�鲻���ڣ�����������:");WHITE;}
        else if(flagbookindex!=-1 && !books[flagbookindex].isLend) {RED;printf("ͼ��δ���������������:");WHITE;}
        else if(flagbookindex!=-1 && books[flagbookindex].lenduserid!=backuserid) {RED;printf("ͼ�鲻���ڴ��û�������������:");WHITE;}
        else {GREEN;printf("�ҵ�ͼ�飺\n");break;}

    }

     GRAY;//��ɫ
        printf("��		 ��  ��\t%s\n",books[flagbookindex].name);
        printf("��		 ��  ��\t%s\n",books[flagbookindex].author);
        printf("��		 ��  ��\t%.2f\n",books[flagbookindex].price);
        printf("��  ��   ��  ��\t%s\n",books[flagbookindex].press);
        printf("��  ��   ��  ��\t%s\n",users[backuserindex].user_name);
        printf("��       ע  ��\t%s\n",books[flagbookindex].lendMessage);
        printf("��   ��  ID  ��\t%d\n",users[backuserindex].user_id);
        GRAY;
        printf("�Ƿ�ȷ�Ϲ黹��(Y/N)\n");
        WHITE;
        key = getch();

        if(key == 'y' || key == 'Y')//���ȷ�Ϲ黹����ͼ��Ľ�����ڸ�Ϊ�գ������û��Ľ���������1
        {
            strcpy(books[flagbookindex].lendMessage,"");//��ձ�ע
            books[flagbookindex].isLend = 0;//��ͼ��Ľ��״̬��Ϊ0
            users[backuserindex].lendBooksNum--;//���û��Ľ���������1
            for( i=0;i<11;i++)//���û��Ľ���isbn�����еĴ�ͼ��isbn��Ϊ��
            {
                if(strcmp(users[backuserindex].lendBooksIsbn[i],isbn)==0) strcpy(users[backuserindex].lendBooksIsbn[i],"");
            }
            saveBooks();//����ͼ����Ϣ
            saveUsers();//�����û���Ϣ
            GREEN;
            printf("�黹�ɹ���\n");
        }
        else {RED;printf("ȡ���黹��\n");}
        


    WHITE;//��ɫ
} 

// ����ͼ�飬�������������û���ҵ�������-1
int searchBook(char *msg, int mode)
{//��һ���ǰ����鼮ISBN���ң��ڶ����ǰ����������ң���������������ʽ��Ϊ1ʱ����ISBN���ң�Ϊ2ʱ������������
    int flagbookindex = -1;//���ͼ����books�����е�λ��
    if(mode == 1)//����ISBN����
    {
        int i=0;
        for( i=0;i<=MAX_BOOKS_NUM;i++)//�ж�ͼ���Ƿ����
        {
            if(strcmp(books[i].isbn,msg)==0) {flagbookindex=i;break;}//����ҵ�����ͼ����books�����е�λ�ø���flagbookindex
            else if(i==MAX_BOOKS_NUM) return -1;//���û���ҵ�
        }
    }
    else if(mode == 2)//������������
    {
        int i=0;
        for( i=0;i<=MAX_BOOKS_NUM;i++)//�ж�ͼ���Ƿ����
        {
            if(strcmp(books[i].name,msg)==0) {flagbookindex=i;break;}//����ҵ�����ͼ����books�����е�λ�ø���flagbookindex
            else if(i==MAX_BOOKS_NUM) return -1;//���û���ҵ�
        }
    }
    return flagbookindex;//����ͼ����books�����е�λ��

}

//�������������modeΪ0����������Ϊ1�����ѽ����Ϊ2����δ���
int countBooks(int mode){ 

    if(mode==0){//modeΪ0ʱ�������鼮����Ŀ
        int i, count = 0;
        for (i = 0; i < MAX_BOOKS_NUM; i++) {
            if (strlen(books[i].isbn) > 0) {
                count++;
            }
        }
        LibR.booksNum = count;
        LibR.isBookEmpty = 0;
        if(count == 0)
            LibR.isBookEmpty = 1;
        return count;
    }


    if(mode==1){//Ϊ1�����ѽ��
        int i, count = 0;
        for (i = 0; i < MAX_BOOKS_NUM; i++) {
            if (strlen(books[i].isbn) > 0 && books[i].isLend==1) {
                count++;
            }
        }
        LibR.lendBooksNum = count;
        return count;
    }

    if(mode==2){//Ϊ2����δ���
        int i, count = 0;
        for (i = 0; i < MAX_BOOKS_NUM; i++) {
            if (strlen(books[i].isbn) > 0 && books[i].isLend==0) {
                count++;
            }
        }
        LibR.unlendBooksNum = count;
        return count;
    }

    else return -1;
}

//�ж��Ƿ�Ϊ��
int isLibEmpty() {
    countBooks(0);
    return LibR.isBookEmpty;
}


