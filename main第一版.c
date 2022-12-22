/*
更新日志：
build:       1.0.23
author:      joker_yue
date:        2022-05-23
last update: 2020-06-06

23-5-2022：第一版
23-5-2022：添加了管理员登录功能与界面
23-5-2022：添加了输入密码时的密码隐藏功能
23-5-2022：修复了部分界面排版出错的问题
24-5-2022：修复了books.dat无法读取的问题
24-5-2022：添加了图书价格合法性的判断
24-5-2022：添加了在图书查看页面图书库存的判断
24-5-2022：修复了图书查看页面的借出状态错误的问题
24-5-2022：修复了重新进入系统时书籍仓库丢失的问题
24-5-2022：添加了无books.dat的修复功能
24-5-2022：添加了在添加书籍时图书ISBN编号的判断功能
24-5-2022：修复了在添加图书时，图书价格不合法却无法判断的问题
24-5-2022: 添加了删除全部书籍的功能
24-5-2022: 添加了彩色字体
24-5-2022: 修改了books.dat的修复界面，添加了蓝屏 :-)
25-5-2022：修复了在蓝屏时进度条超出100%的问题
25-5-2022：修复了无藏书时也会显示列表头的问题
25-5-2022: 修复了无藏书时也能修改书籍信息的问题
06-6-2022: 添加了删除全部图书的二级确认界面
06-6-2022: 修改了部分界面的字体颜色
06-6-2022: 统一了操作界面的设计风格语言，我们将(Y/N)全部改成了[Y]
06-6-2022: 优化了查看书籍的操作逻辑
*/


//颜色
#define WHITE SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);//白色
#define RED SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);//红色
#define GREEN SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);//绿色
#define BLUE SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE);//蓝色
#define YELLOW SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN);//黄色
#define PINK SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE);//粉色
#define CYAN SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_BLUE);//青色
#define GRAY SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY);//灰色
//使用方法：{YELLOW;  printf("%s","你好");  WHITE; }
//建议项：用户输入字段为BLUE,用户按键选择为GREEN,系统提示为YELLOW,系统警告以及操作错误或被取消为RED,操作成功为GREEN,列表头用WHITE,列表内容为GRAY
//一定要记得改回来白色！

//其他的宏定义
#define HIDE_CURSOR CONSOLE_CURSOR_INFO cursor_info = {1, 0};SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);//隐藏鼠标光标，谨慎使用，无法取消！


#define ERROR_READ 0
#define MAX_BOOKS_NUM 1000
#define MAX_USERS_NUM 1000


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>//用来支持键盘输入(getch)
#include<windows.h>//用来支持颜色设置和屏幕等待



//图书馆结构体
struct Lib{
    char LibName[20];//图书馆名称
    int isEmpty;//是否为空
    int booksNum;//图书数量
}LibR;

//图书结构体
struct Book {
	char isbn[20];		// 发行编号 唯一值
	char name[20];		// 书名
	char author[20];	// 作者
	float price;		// 价格
	char press[20];		// 出版社 
	int isLend;			// 借出标志 
}books[MAX_BOOKS_NUM]; 
// 图书结构体数组， 用于存放所有的图书信息

// 借阅信息结构体 
struct Lend {
	int id;					// 借阅编号 唯一值 
	struct Book book;		// 借出的图书
	char name[20];			// 书名
	char outTime[10];		// 借出时间
	char backTime[10];		// 归还时间 
}lends[MAX_BOOKS_NUM];

//用户结构体
struct User{
    int user_id;//用户id
    char user_name[20];//用户名
    char user_password[20];//密码
    int lendid[10];//借阅id，最多同时借10本书
    int integral;//积分
    int vip;//是否为vip 
    struct Lend lend;//借阅信息
}users[1000];


/*这里都是函数声明*/

// 登录，读取文件
void login(); 
// 管理员菜单
void adminMenu();
// 添加图书，存储文件
void addBook();
// 查询图书，存储文件
void queryBook();
// 存储文件
void saveBooks();
// 读取文件
void loadBooks();
// 删除图书
void delBook();
// 修改图书
void modBook(); 
// 借出书籍
void lendBooks();
// 归还书籍
void backBooks();
// 判断书籍重复
int isBookRepeat(const char *isbn,int i);
// 判断输入的密码
int confirm(const char *msg);//被弃用
int confirml(const char *msg,const  char *m, void*a);
//判断图书是否为空
int isLibEmpty();
//计算藏书数量
int countBooks();



int main(){
	int input;
    loadBooks();
	while(1){
		system("cls");
        system("color 05");//f1中前一个f为背景色，后一个为前景色。蓝色
		// tab ==> 右缩进	 shift+tab <== 左缩进
        WHITE;//白色
		printf("==================================\n=");
        BLUE;//蓝色
		printf("          魔法书库系统\t         ");
        WHITE;//白色
		printf("=\n==================================\n=");
        CYAN;//青色
		printf("           1. 登录\t         ");
        WHITE;//白色
		printf("=\n=           ");
        YELLOW;//黄色
        printf("2. 关于我们\t      	 ");
        WHITE;//白色
		printf("=\n=           ");
        PINK;//粉色
        printf("3. 操作指南\t         ");
        WHITE;//白色
		printf("=\n=           ");	
        RED;//红色
        printf("4. 退出\t         ");
        WHITE;//白色
		printf("=\n==================================\n");
        GRAY;//灰色
		printf("请输入 (1 ~ 4): ");
        GREEN;//绿色
		scanf("%d",&input);
        WHITE;//白色
		switch(input){
			case 1: login();break; 
			case 2: printf("关于我们：\n\t该图书管理软件旨在将图书管理员\n从繁重图书管理模式下拯救出去！");break; 
			case 3: printf("懂不懂熟能生巧这个道理啊喂（战术后仰）。");break; 
			case 4: return 0;
            default: printf("输入错误！");
		}
		system("pause");
	}
	return 0;
 }
 
// 管理员页面
void adminMenu()
{
    int input;

    while (1)
    {
        system("cls");
        system("color 02");//02中前一个0为背景色，黑色。后一个为前景色，绿色，但是这里没用，被FOREGROUND_替代了

        WHITE;//白色
        printf("==================================\n=");
        BLUE;//蓝色
        printf("          图书管理系统          ");
        WHITE;//白色
        printf("=\n==================================\n=");
        YELLOW;//黄色
        printf("          1. 添加图书      	 ");
        WHITE;//白色
        printf("=\n=          ");
        PINK;//粉色
        printf("2. 修改图书      	 ");
        WHITE;//白色
        printf("=\n=          ");
        BLUE;//蓝色
        printf("3. 查询图书      	 ");
        WHITE;//白色
        printf("=\n=          ");
        CYAN;//青色
        printf("4. 删除图书      	 ");
        WHITE;//白色
        printf("=\n=          ");
        YELLOW;//黄色
        printf("5. 借阅图书      	 ");
        WHITE;//白色
        printf("=\n=          ");
        PINK;//粉色
        printf("6. 归还图书      	 ");
        WHITE;//白色
        printf("=\n=          ");
        GREEN;//绿色
        printf("7. 清点图书           ");
        WHITE;//白色
        printf("=\n=");
        RED;//红色
        printf("          0. 退出系统           ");
        WHITE;//白色
        printf("=\n");
        printf("==================================\n");
        GRAY;//灰色
        printf("请输入 0 ~ 7: ");
        GREEN;//绿色
        scanf("%d", &input);
        WHITE;//白色
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
            printf("藏书数量：%d\n",countBooks());
            break;
        case 0:
        WHITE;//白色
            return ;
        }
        system("pause");
    }
}

// 登录密码
void inputPwd(char *pwd, int length){
	char key;
	int i = 0;
	a : while(1) {
		i = 0;
		key = 0;
        YELLOW;//绿色
		printf("请输入密码：\t");
		while(1) {
			key = getch();
			// 退格键
			if(key == '\b') {
				if(i > 0) {
					// ab	\b 退格
					printf("\b \b");
					i--; 
				}
				continue;
			}
			//	13 回车
			else if (key == 13) {
				if(i > 0) break;
				else {
					printf("\n");
					goto a;
				}
			} else {
				if(i < length) {
                    BLUE;//蓝色 
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

//查看书籍
void queryBook(){
	if(isLibEmpty()) {printf("无藏书！\n");return;}

    CYAN;//青色
	printf("  编号   %20s %10s %10s %20s %20s %10s\n", "书名","作者","价格","出版社","ISBN","出借状态");
    WHITE;
    int showindex=1;//显示索引
    
    GRAY;//灰色
	for(int i=0;i<MAX_BOOKS_NUM;i++){
		if(strlen(books[i].name)>0){
			printf("第%03d项  %20s %10s %10.2f %20s %20s",
            showindex++,//显示索引
			books[i].name,
			books[i].author,
			books[i].price,
            books[i].press,
			books[i].isbn);

            if(books[i].isLend==1) {YELLOW;printf("%10s\n","已借出");}
            else {GREEN;printf("%10s\n","未借出");}
            
		}
	}
    WHITE;//白色
}
 
//添加书籍
void addBook()
{
    int i;

    // 查找结构体数组中的空闲位置
    for (i = 0; i < MAX_BOOKS_NUM; i++)
        if (strlen(books[i].name) == 0) //如果书名为空，说明此位置无书本
        {
            // 让用户输入一本图书的信息，保存在结构体数组中的空闲位置上
            printf("请输入ISBN：");
                while(scanf("%s", books[i].isbn))
                {
                    if(isBookRepeat(books[i].isbn,i))
                    printf("已有此书,请重新输入：");
                    else break;
                }

            printf("请输入书名：");
            scanf("%s", books[i].name);

            printf("请输入作者：");
            scanf("%s", books[i].author);

            printf("请输入价格：");
                while(scanf("%f", &books[i].price))
                {
                    if(books[i].price<=0)
                    printf("价格设定错误！清重新输入价格\n");
                    else break;
                }

            printf("请输入出版社：");
            scanf("%s", books[i].press);

            books->isLend=0;//初始化为未借出

            saveBooks(); // 写入文件
            break;
        }

    if (i == MAX_BOOKS_NUM)
        printf("书库已满！");
    else
        printf("保存成功！");
}

// 登录
void login()
{
    char user[10];
    char pwd[10];
    YELLOW;//绿色
    printf("请输入用户名：\t");
    BLUE;//蓝色
    scanf("%s", user);
    WHITE;//白色
    inputPwd(pwd, 10); //输入密码

    //字符串判断，如果是管理员，则跳转到管理员界面
    if (strcmp(user, "admin") == 0 && strcmp(pwd, "admin") == 0)
    {
        GREEN;
        printf("登录成功！\n");
        Sleep(1000);
        WHITE;
        adminMenu();
    }
    else
    {
        RED;
        printf("登录失败！\n");
        WHITE;
        return  ;
    }
}

// 存储书籍信息文件
void saveBooks(){
	//将books存入文件“books.dat”
	FILE*file;//定义文件指针
	file=fopen("books.dat","a+");//以追加模式（a）打开文件
	//file为NULL 那么表示文件不存在，系统会创建该文件
	//参数说明：1写入数据对象，2写入数据大小，3写入次数，4文件指针
	fwrite(books,sizeof(books),1,file);
	fclose(file);//关闭文件 
}

// 读取文件 
void loadBooks(){//黑心商家赚钱的地方啊
    system("color 14");//蓝屏
	FILE*file;
	file=fopen("books.dat","r");//以读模式（r）打开文件
	
	if(file !=NULL){
		//文件不为NULL，就读取文件
        while(1)
        {
            fread(books,sizeof(books),1,file);//循环读入
            if(feof(file)) break;
        }
	}
    else {
        HIDE_CURSOR;//隐藏光标
        printf(":-(\n您的系统遇到问题,需要重新启动,我们正在搜集问题,请勿退出...\n");
        Sleep(1000);
        for(int i=0;i<100;i++)
        {
            printf("%d%%",i);
            Sleep(50);
            printf("\b\b\b");
        }
        printf("检测到丢失books.dat,正在尝试自动修复...\n");
        /* Joker Never Plays Jokes!*/
            remove("books.dat");//删除文件
        Sleep(1000);
        printf("正在添加文件...\n");
        Sleep(1000);
        printf("添加成功，正在重新设置指针...\n");
        file=fopen("books.dat","w");//以写模式（w）打开文件，这样做可以新建文件
        Sleep(1000);
        printf("成功！\n");
        Sleep(500);//延时1秒，想搞快点得加钱
        
        system("cls");//清屏
        system("color Af");//绿屏
        if(file!=NULL)
        {printf("修复完成！请重新启动程序\n");
         printf("系统将在3秒后关闭...\n");
            Sleep(1000);printf("2秒后关闭...\n");
            Sleep(1000);printf("1秒后关闭...\n");
        }
        else {
            system("color 14");//红屏
            printf(":-(\n修复失败！请手动检查或者联系我们\n");
            printf("联系方式：\nQQ:3349305706\nEmail:Joker_Yue@qq.com\n");
            }
        exit(ERROR_READ);
    }
	fclose(file);
} 

// 删除图书
void delBook() {
    //用isbn查找图书
    char isbn[20];
    int i;
    char yn[10];

    char key;//操作键
    RED;
    printf("是否全部删除?[Y]\n");
    WHITE;
    key=getch();

    if(key=='y'||key=='Y')
    {   
        YELLOW;
        printf("高危操作！请输入:");RED;printf("yes");YELLOW;printf("以继续操作:");
        BLUE;
        scanf("%s",yn);
        if(strcmp(yn,"yes")!=0){
            GRAY;
            printf("操作取消！\n");
            WHITE;
            goto ctn;
        }
        remove("books.dat");//删除文件
        FILE *file;//重新定义指针以生成文件
        file=fopen("books.dat","w");//以写模式（w）打开文件，这样做可以新建文件
        GREEN;
        printf("删除成功！\n");
        WHITE;
        fclose(file);//关闭文件

        for(int i=0;i<MAX_BOOKS_NUM;i++)//循环删除
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
    printf("请输入要删除的图书的ISBN: ");
    scanf("%s", isbn);
    for (i = 0; i < MAX_BOOKS_NUM; i++) {
        if (strcmp(books[i].isbn, isbn) == 0) {
            printf("书名： \t%s\n", books[i].name);
            printf("作者： \t%s\n", books[i].author);
            printf("价格： \t%10.2f\n", books[i].price);
            printf("出版社: \t%s\n", books[i].press);
            printf("请确认是否要删除该图书[Y]\n");
            scanf("%s", yn);
            if (strcmp(yn, "y") == 0 || strcmp(yn, "Y") == 0) {
                strcpy(books[i].isbn, "");
                strcpy(books[i].name, "");
                strcpy(books[i].press, "");
                books[i].price = 0;
                //写入文件
                saveBooks();
                GREEN;
                printf("图书删除成功! \n");
                WHITE;
            } else {
                RED;
                printf("用户取消了删除操作！ \n");
                WHITE;
            }
            return;
        }
    }
    //未找到图书
    RED;
    printf("没有该图书！\n");
    WHITE;
}

//修改图书
void modBook() {
    char isbn[20];
    int i;
    char key;  //输入的按键

    if(isLibEmpty()) {
        RED;
        printf("图书库为空！\n");
        WHITE;
        return;
    }
    
    GRAY;//灰色
    printf("是否列出图书列表?[Y]\n");
    key=getch();
    if(key=='y'||key=='Y') queryBook();

    printf("请输入要修改的图书的ISBN: ");
    scanf("%s", isbn);
    for (i = 0; i < MAX_BOOKS_NUM; i++) {
        if (strcmp(books[i].isbn, isbn) == 0)
        {
            WHITE;//白色
            printf("查询成功，找到匹配书籍：\n");
            GRAY;//灰色
            printf("\n\t||书名: \t%s\n", books[i].name);
            printf("\t||作者: \t%s\n", books[i].author);
            printf("\t||价格: \t%10.2f\n", books[i].price);
            printf("\t||出版社：\t%s\n\n", books[i].press);

            YELLOW;//黄色
            printf("是否开始修改?[Y]\n");
            key = getch();
            if (key != 'Y' && key != 'y') {
                RED;//红色
                printf("操作被用户取消！ \n");
                return ;
            }


            //提示用户是否修改每个字段
            printf("请确认是否要修改书名(Y/N)?\n");
            key = getch();
            if (key == 'y' || key == 'Y') {
                printf("请输入:");
                scanf("%s", books[i].name);
                printf("修改成功！\n");
            }

            printf("请确认是否要修改作者?[Y]\n");
            key = getch();
            if (key == 'y' || key == 'Y') {
                printf("请输入:");
                scanf("%s", books[i].author);
                printf("修改成功！\n");
            }

            printf("请确认是否要修改价格?[Y]\n");
            key = getch();
            if (key == 'y' || key == 'Y') {
                printf("请输入:");
                while(scanf("%f", &books[i].price))
                {
                    if(books[i].price<=0)
                    printf("价格设定错误！请重新输入价格\n");
                    else 
                    {
                        printf("修改成功！\n");
                        break;
                    }
                }
            }

            printf("请确认是否要修改出版社?[Y]\n");
            key = getch();
            if (key == 'y' || key == 'Y') {
                printf("请输入:");
                scanf("%s", books[i].press);
                printf("修改成功！\n");
            }
            saveBooks();
            printf("\n图书修改成功!\n");

            return;
        }
    }
    printf("没有该图书！\n");
}

// 借出图书
void lendBooks() {
    char isbn[20];
    int i, j;
    char yn[10];
    char key;

    if(isLibEmpty()) {
        RED;
        printf("图书库为空！\n");
        WHITE;
        return;
    }
    
    GRAY;//灰色
    printf("是否列出图书列表?[Y]\n");
    key=getch();
    if(key=='y'||key=='Y') queryBook();
    WHITE;

    printf("请输入要借出的图书的ISBN: ");
    scanf("%s", isbn);
    for (i = 0; i < MAX_BOOKS_NUM; i++) {
        if (strcmp(books[i].isbn, isbn) == 0) {
            GRAY;//灰色
            printf("书名: \t%s\n", books[i].name);
            printf("作者: \t%s\n", books[i].author);
            printf("价格: \t%10.2f\n", books[i].price);
            printf("出版社: \t%s\n", books[i].press);
            printf("借出状态: \t%s\n", books[i].isLend == 1 ? "借出" : "在库");

            //判断图书是否被借出
            if (books[i].isLend == 1) {
                printf("该图书已经被借出! \n");
                return;
            }

            printf("请确认是否要借出该图书?[Y]\n");
            scanf("%s", yn);
            if (strcmp(yn,"y") == 0 || strcmp(yn,"Y") == 0) {
                //未借出则修改图书状态
                books[i].isLend = 1;

                for (j = 0; j < MAX_BOOKS_NUM; j++) {
                    if (lends[j].id == 0) {
                        //请输入读者信息
                        printf("请输入读者姓名: ");
                        scanf("%s", lends[j].name);
                        printf("请输入借入借出时间: ");
                        scanf("%s", lends[j].outTime);
                        // id自动生成
                        lends[j].id = j + 1;
                        lends[j].book = books[i];
                        break;
                    }
                }
                //写入文库
                saveBooks();
                printf("图书借出成功！\n");
            } else {
                printf("用户取消了借出操作！\n");
            }
            return;
        }
    }
    //没找到，提示用户，终止操作
    printf("没有该图书！\n");
}

// 归还图书 
void backBooks() {
	int id;
	int i,j;
	char name[20] = "";
    char key;

    
    GRAY;//灰色
    printf("是否列出图书列表?[Y]\n");
    key=getch();
    if(key=='y'||key=='Y') queryBook();

    WHITE;
	
	confirml("是否要使用书名查询未归还的图书?[Y]","%s", name);
	if(strlen(name) == 0){
		// 根据借阅编号，查找借阅记录
		printf("请输入借阅编号：");
		scanf("%d",&id); 
	}
	
	for(i=0 ;i < MAX_BOOKS_NUM; i++){
		// 判断借阅状态
		// 归还图书并使用精确查询——名字完全相同 
		if(strcmp( lends[i].book.name, name) == 0 || (id > 0 && lends[i].id == id)){
            GRAY;//灰色
			printf("书		 名  ：\t%s\n",lends[i].book.name);
			printf("作		 者  ：\t%s\n",lends[i].book.name);
			printf("价		 格  ：\t%s\n",lends[i].book.name);
			printf("出  版   社  ：\t%s\n",lends[i].book.name);
			printf("借  阅   人  ：\t%s\n",lends[i].book.name);
			printf("借 出 时 间  ：\t%s\n",lends[i].book.name);
			printf("归 还 时 间  ：\t%s\n",lends[i].book.name);
            WHITE;
			if(strlen(lends[i].backTime) > 0) {
                RED;
				printf("该图书已经归还！"); 
                WHITE;
				return;
			} 
			// 修改借阅记录的归还时间
			printf("请输入归还时间：");
			scanf("%s",lends[i].backTime);
			
			// 修改图书状态
			for(j=0 ;j < MAX_BOOKS_NUM; j++) {
				if(strcmp(books[j].isbn, lends[i].book.isbn) == 0){
					books[j].isLend = 0;
					break;
				}
			}
			
			// 保存
			saveBooks();
			
			// 提示成功
			printf("图书归还成功！");
			return; 
		} 
	}
    RED;
	printf("没有该借阅记录！");
} 

//输入确认
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
        printf("请输入：\n");
        return 1;
    }
/* 
让用户确认输入的函数，用户输入N/n返回0，其他返回1
msg表示提示用户输入的文字 */
}

//输入确认1
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
        printf("请输入：");
        scanf(m,a);
        return 1;
    }
}

//判断书籍重复
int isBookRepeat(const char *isbn,int i)
{
    int j;
    for(j=0;j<MAX_BOOKS_NUM;j++)
    {
        if(strcmp(books[j].isbn,isbn)==0&&j!=i)//如果有重复的isbn
        {
            return 1;
        }
    }
    return 0;
}

//计算藏书数量
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

//判断是否为空
int isLibEmpty() {
    countBooks();
    return LibR.isEmpty;
}


