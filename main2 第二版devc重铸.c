/*更新日志：
23-5-2022：第一版
23-5-2022：添加了管理员登录功能与界面
23-5-2022：添加了输入密码时的密码隐藏功能
23-5-2022：修复了部分界面排版出错的问题
24-5-2022：修复了books.txt无法读取的问题
24-5-2022：添加了图书价格合法性的判断
24-5-2022：添加了在图书查看页面图书库存的判断
24-5-2022：修复了图书查看页面的借出状态错误的问题
24-5-2022：修复了重新进入系统时书籍仓库丢失的问题
24-5-2022：添加了无books.txt的修复功能
24-5-2022：添加了在添加书籍时图书ISBN编号的判断功能
24-5-2022：修复了在添加图书时，图书价格不合法却无法判断的问题
24-5-2022: 添加了删除全部书籍的功能
24-5-2022: 添加了彩色字体
24-5-2022: 修改了books.txt的修复界面，添加了蓝屏 :-)
25-5-2022：修复了在蓝屏时进度条超出100%的问题

25-5-2022：第二版
25-5-2022: 添加了用户系统
25-5-2022: 添加了用户登录功能
25-5-2022：添加了用户注册功能
25-5-2022：添加了用户菜单界面
25-5-2022: 添加了users.txt的修复界面，添加了蓝屏 :-)
25-5-2022: 修复了无藏书时也能修改书籍信息的问题
26-5-2022: 修复了查看个人信息时意外退出的bug
26-5-2022: 修复了个人信息界面显示格式错误的bug
26-5-2022: 修复了部分操作下程序意外退出
26-5-2022: 修复了无法注册用户的问题
26-5-2022: 删除了老旧的Lend结构体
26-5-2022: 将users与books结构体联动
26-5-2022: 修复了主界面意外不读取的bug
26-5-2022: 修复了管理员无法登录的问题
26-5-2022: 添加了用户账号判断合法性的功能
26-5-2022: 添加了删除全部用户的功能
26-5-2022: 添加了删除全部图书的二级操作确认
26-5-2022: 添加了删除全部用户的二级操作确认
26-5-2022: 修复了在无用户情况下会显示用户列表的bug
26-5-2022: 修复了用户无法注册的问题
26-5-2022: 修复了主页界面输入系统无响应的问题
26-5-2022: 用户界面的【个人信息】功能上线！
26-5-2022: 用户界面的【我的借阅】功能上线！
26-5-2022：用户界面的【借阅图书】功能上线！
26-5-2022: 用户界面的【归还图书】功能上线！
26-5-2022: 添加了用户ID和用户数组索引的转化函数
26-5-2022：修复了管理员界面还不了书的问题
26-5-2022：修复了在管理员界面借出书后，用户界面还是显示没有借到书的问题
27-5-2022: 修复了用户无法归还书本的问题
27-5-2022：修复了管理员借阅失败的问题
27-5-2022：修复了明明有书籍可借阅却还是显示 无书籍可借阅的问题
27-5-2022: 添加了登陆界面更多的判断
27-5-2022: 修复了登录界面字体颜色不正常的问题
27-5-2022: 修改了管理员借书的操作逻辑
27-5-2022: 添加了在用户登陆界面的欢迎语
27-5-2022：添加了用户积分系统
28-5-2022: 添加了更多界面的字体颜色
28-5-2022: 更改了部分界面的提示信息
28-5-2022: 修复了修改用户意外退出的问题
28-5-2022: 设置了在用户有未归还的书本时不允许用户进行注销
*/

#define ERROR_READ 0

#define MAX_BOOKS_NUM 100
#define MAX_USERS_NUM 100
#define TOP_POINTS 10
#define TOP_VIP_GRADE 8

#define WHITE SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE)//白色
#define RED SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);//红色
#define GREEN SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN)//绿色
#define BLUE SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE)//蓝色
#define YELLOW SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN)//黄色
#define PINK SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE)//粉色
#define CYAN SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_BLUE)//青色
#define GRAY SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY)//灰色


#include<stdio.h>//基本输入输出函数库
#include<stdlib.h>//用于memset()
#include<string.h>//用来支持string
#include<conio.h>//用来支持键盘输入(getch)
#include<windows.h>//用来支持颜色设置和屏幕等待
#include<ctype.h>//用来支持isalpha函数
#include<malloc.h>//用来支持malloc函数
#include<time.h>//用来支持显示时间


//图书馆结构体
struct Lib{
    char LibName[20];//图书馆名称
    int isBookEmpty;//是否为空
    int isUserEmpty;//是否为空
    int booksNum;//图书数量
    int userNum;//用户数量
    int lendBooksNum;//已借出的书本数量
    int unlendBooksNum;//未借出的书籍数量
}LibR;

//图书结构体
struct Book {
	char isbn[20];		// 发行编号 唯一值
	char name[20];		// 书名
	char author[20];	// 作者
	float price;		// 价格
	char press[20];		// 出版社 
	int isLend;			// 借出标志  
    int lenduserid;         //借阅者ID
    char lendMessage[20];     //借阅备注
}books[MAX_BOOKS_NUM]; // 图书结构体数组， 用于存放所有的图书信息

//用户结构体
struct Users
{
    int user_id;//用户id
    char user_name[10];//用户名
    char user_password[20];//密码
    int integral;//积分
    int vip;//是否为vip 
    char lendBooksIsbn[11][20];//借阅的书籍,最多同时借10本书
    int lendBooksNum;//借阅的书籍数量
}users[MAX_USERS_NUM];//用户结构体数组，用于存放所有的用户信息


int sys_user_id;//正在系统登陆的的用户ID
int sys_user_index;//正在系统登陆的的用户索引


// 登录，读取文件
void login(); 
// 管理员菜单
void adminMenu();
// 添加图书，存储文件
void addBook();
// 查询图书，存储文件
void queryBook();
// 详细书籍信息
void showBookDetail();
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
//判断图书重复
int isBookRepeat(const char *isbn,const int index);
//判断图书是否为
int isLibEmpty();
//计算藏书数量，mode为0返回总数，为1返回已借出，为2返回未借出
int countBooks(int mode);


// 读取用户
void loadUsers();
// 存储用户
void saveUsers();
// 用户菜单
void userMenu(const int *user_index);
//注册用户
void addUser();
//管理员修改用户
void modUserAdm();
//管理员显示用户
void showUsers();
// 我的借阅
void myLend(const int user_index);
//用户借阅
void userLend(const int user_index);
// 用户归还
void userBack(const int user_index);
// 我的积分
void userIntegral(const int user_index);
//管理员管理用户
void manageUser();
// 管理员删除用户
void delUserAdm();
//在users.txt过大时删除
void Rec();
//计算用户数量
int countUsers();
//用户信息
int userLetter(const int user_index);
//删除用户
int delUser(int user_index);
//判断用户重复
int isUserAvl(const int user_index);
//判断用户是否为空
int isUserEmpty();
//查询书籍,mode=1,2查找isbn,查找书名
int searchBook(char *msg, int mode);
//用户ID和用户索引的转化.模式为0时，ID->索引
int ID2Index(const int n,int mode);


// 判断输入的密码
int confirm(char *msg);
int confirml(const char *msg, char *m, void*a);



int main(){
	int input;
    loadUsers();
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
        GREEN;//绿色
        printf("4. 用户注册\t         ");
        WHITE;//白色
		printf("=\n=           ");
        RED;//红色
        printf("9. 退出\t         ");
        WHITE;//白色
		printf("=\n==================================\n");
        GRAY;//灰色
		printf("请输入 : ");
        GREEN;//绿色
        // fflush(stdin);//更新缓冲区
		scanf("%d",&input);
        WHITE;//白色
		switch(input){
			case 1: login();break; 
			case 2: printf("关于我们：\n\t该图书管理软件旨在将图书管理员\n从繁重图书管理模式下拯救出去！");break; 
			case 3: printf("懂不懂熟能生巧这个道理啊喂（战术后仰）。");break; 
            case 4: addUser();break;
			case 9: return 0;
            default : RED;printf("输入格式有误,系统将默认退出！\n");WHITE;return 0;

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
        printf("=\n=          ");
        BLUE;//绿色
        printf("8. 管理用户           ");
        WHITE;
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
            printf("藏书数量：%d\n已借出：%d\n未借出：%d",countBooks(0),countBooks(1),countBooks(2));
            break;
        case 8:
            manageUser();
            break;
        case 0:
        WHITE;//白色
            return ;
        }
        system("pause");
    }
}

// 用户界面
void userMenu(const int *user_index)//这里是传入索引！
{
    int input;

    while (1)
    {
        system("cls");
        system("color 02");//02中前一个0为背景色，黑色。后一个为前景色，绿色，但是这里没用，被FOREGROUND_替代了

        WHITE;//白色
        printf("==================================\n=");
        BLUE;//蓝色
        printf("       欢迎您：%10s       ",users[*user_index].user_name);
        WHITE;//白色
        printf("=\n==================================\n=");
        YELLOW;//黄色
        printf("          1. 我的信息      	 ");
        WHITE;//白色
        WHITE;//白色
        printf("=\n=          ");
        BLUE;//蓝色
        printf("2. 查询图书      	 ");
        WHITE;//白色
        printf("=\n=          ");
        CYAN;//青色
        printf("3. 我的借阅      	 ");
        WHITE;//白色
        printf("=\n=          ");
        YELLOW;//黄色
        printf("4. 借阅图书      	 ");
        WHITE;//白色
        printf("=\n=          ");
        PINK;//粉色
        printf("5. 归还图书      	 ");
        WHITE;//白色
        printf("=\n=          ");
        GREEN;//绿色
        printf("6. 我的积分           ");
        WHITE;//白色
        printf("=\n=");
        RED;//红色
        printf("          0. 退出系统           ");
        WHITE;//白色
        printf("=\n");
        printf("==================================\n");
        GRAY;//灰色
        printf("请输入 : ");
        GREEN;//绿色
        scanf("%d", &input);
        WHITE;//白色
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
            {WHITE;//白色
            sys_user_id=0;sys_user_index=0;return;}
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
        GREEN;//绿色
		printf("请输入密码：");
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

// 登录
void login()
{
    char user[20];
    char pwd[20];
    GREEN;
    printf("请输入用户ID：");
    BLUE;//蓝色

    scanf("%s", user);
    sys_user_id=atoi(user);//字符串转整型
    sys_user_index=ID2Index(sys_user_id,0);//整型转索引

    if(isalpha(user[0]))
        {
        if( strcmp(user,"admin")!=0 ) 
        {
            RED;
            printf("用户ID不存在!\n");
            WHITE;
            return ;
        }}
    
    else if(isdigit(user[0]))
        {
        if(!isUserAvl(sys_user_index) || users[sys_user_index].user_id!=sys_user_id ) 
        {
            RED;
            printf("用户ID不存在!\n");
            WHITE;
            return ;
        }}

    else {RED;printf("用户ID不存在!\n");WHITE;return;}

    inputPwd(pwd, 20); //输入密码

    //字符串判断，如果是管理员，则跳转到管理员界面
    if (strcmp(user, "admin") == 0 && strcmp(pwd, "admin") == 0)
    {
        GREEN;
        printf("登录成功！\n");
        WHITE;
        adminMenu();
    }

    else if(isdigit(user[0]))
    {
        if (strcmp(pwd, users[sys_user_index].user_password) == 0)
        {   GREEN;
            printf("登录成功！\n");
            WHITE;
            userMenu(&sys_user_index);
        }
        else
        {   RED;
            printf("密码错误！\n");
            WHITE;
            // login();
            return ;
        }
    }
    else
    {   RED;
        printf("登录失败！\n");
        WHITE;
        // login();
        return ;
    }
}

//储存用户信息文件
void saveUsers(){
	//将User存入文件“user.txt”
	FILE*file;//定义文件指针
	file=fopen("users.txt","a+");//以追加模式（a）打开文件
	//file为NULL 那么表示文件不存在，系统会创建该文件
	//参数说明：1写入数据对象，2写入数据大小，3写入次数，4文件指针
	fwrite(users,sizeof(users),1,file);
	fclose(file);//关闭文件 
}

//读取用户信息文件 
void loadUsers(){//黑心商家赚钱的地方啊
    system("color 14");//蓝屏
	FILE*file;
	file=fopen("users.txt","r");//以读模式（r）打开文件
	
	if(file !=NULL){
		//文件不为NULL，就读取文件
        while(1)
        {
            fread(users,sizeof(users),1,file);
            if(feof(file)) break;
        }
	}
    else {
        CONSOLE_CURSOR_INFO cursor_info = {1, 0};SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);//隐藏光标
        printf(":-(\n您的系统遇到问题,需要重新启动,我们正在搜集问题\n");
        Sleep(1000);
        int i=0;
        for( i=0;i<100;i++)
        {
            printf("%d%%",i);
            Sleep(50);
            printf("\b\b\b");
        }
        printf("检测到丢失users.txt,正在尝试自动修复...\n");
            remove("users.txt");//删除文件
        Sleep(1000);
        printf("正在添加文件...\n");
        Sleep(1000);
        printf("添加成功，正在重新设置指针...\n");
        file=fopen("users.txt","w");//以写模式（w）打开文件，这样做可以新建文件
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
            printf("联系方式：\nQQ:848484848\nEmail:");
            }
        exit(ERROR_READ);
    }
	fclose(file);
} 

//注册用户
void addUser()
{
    int i;
    char c;

    // 查找结构体数组中的空闲位置
    
        system("cls");
        system("color 02");//02中前一个0为背景色，黑色。后一个为前景色，绿色，但是这里没用，被FOREGROUND_替代了
        
        for (i = 0; i <= MAX_USERS_NUM; i++)
        {
            if (!users[i].user_id && i!=MAX_USERS_NUM) //如果用户id为空，说明此位置无用户
            {
                printf("请输入用户名：");
                scanf("%s", users[i].user_name);

                printf("请设置用户密码：");
                scanf("%s", users[i].user_password);

                users[i].user_id=ID2Index(i,1);//初始化用户id
                users[i].integral=0;//初始化用户积分
                users[i].lendBooksIsbn[0][0]='\0';//初始化用户借书isbn
                users[i].lendBooksNum=0;//初始化用户借书数量

                printf("添加用户成功,用户id为 ");
                YELLOW;
                printf("%5d\n", users[i].user_id);
                WHITE;
                printf("下次登陆请使用用户id登录\n");

                saveUsers(); // 写入文件

                // printf("按任意键返回主菜单\n");
                c=getchar();//过滤掉换行符
                // c=getch();//等待用户按下任意键
                break;
            }
            if(i==MAX_USERS_NUM)//如果没有空闲位置，说明已经满了
                break;
            
        }

            if(i==MAX_USERS_NUM)//如果没有空闲位置，说明已经满了
            {
                RED;
                printf("添加失败,是否进入Recovery?(y/n)");
                WHITE;
                c=getch();
                if(c=='y')
                Rec();
            }
     return;
        
    
}

//管理员添加用户
void addUserAdm()
{
    int i;
    // char key;
    GREEN;
    // 查找结构体数组中的空闲位置
    for (i = 0; i <= MAX_USERS_NUM; i++)
        if (strlen(users[i].user_name) == 0) //如果用户id为空，说明此位置无用户
        {

            printf("请输入用户名：");
            scanf("%s", users[i].user_name);

            printf("请设置用户密码：");
            scanf("%s", users[i].user_password);

            users[i].user_id=ID2Index(i,1);//初始化用户id

            printf("请设置积分：");
            while(scanf("%d",&users[i].integral))
            {
                if(users[i].integral<0) printf("用户积分无法为负值,请重新输入：");
                else break;
            }
            GREEN;
            printf("请设置vip等级：");
            while(scanf("%d",&users[i].vip))
            {
                RED;
                if(users[i].vip<0||users[i].vip>TOP_VIP_GRADE) {
                    printf("VIP等级只能为0-%d级,请重新输入：",TOP_VIP_GRADE);
                    GREEN;
                }
    
                else break;
            }

            saveUsers(); // 写入文件

            printf("添加用户成功,用户id为 ");
            YELLOW;
            printf("%5d\n", users[i].user_id);
            WHITE;
            break;
        }

    if (i == MAX_USERS_NUM){
        RED;
        printf("用户已满！");
        GREEN;
    }
       
    else
        printf("保存成功！");
}

//用户信息
int userLetter(const int user_index)
{
    char key;
    char pswd[20];
    char pswd1[20];//用户密码

	printf("%10s %10s %10s %10s\n","用户ID","用户名","用户积分","VIP状态");
    
    GRAY;//灰色
			printf("%10d %10s %10d %8d级",
                users[user_index].user_id,
                users[user_index].user_name,
                users[user_index].integral,
                users[user_index].vip);
            printf("\n");
	
    WHITE;//白色


    printf("\n");
    printf("修改密码:\t[1]\n");
    printf("查看借阅信息:\t[2]\n");
    printf("注销用户:\t[9]\n");
    printf("退出:\t\t[0]\n");

    GRAY;
    printf("请选择：");
    WHITE;
    getchar();//过滤掉回车
    scanf("%c", &key);
    // key=getchar();

    if(key=='1'){
            printf("请输入旧密码：");
            while(scanf("%s",pswd))
            {
            if(strcmp(pswd,users[user_index].user_password)==0)
            {
                printf("请输入新密码：");
                inputPwd(pswd, 20);//输入密码
                printf("请再次输入新密码：");
                inputPwd(pswd1, 20);//输入密码

                if(strcmp(pswd,pswd1)==0&&strcmp(pswd,users[user_index].user_password)!=0)
                {
                    strcpy(users[user_index].user_password,pswd);
                    saveUsers();
                    printf("修改成功！\n");
                    break;//退出循环
                }
                else if(strcmp(pswd,pswd1)==0&&strcmp(pswd,users[user_index].user_password)==0)
                {
                    YELLOW;    
                    printf("新密码与旧密码相同，请重新输入！\n");
                    WHITE;
                    printf("请输入旧密码：");
                }
                else
                {
                    YELLOW;
                    printf("两次输入密码不一致，请重新输入！\n");
                    WHITE;
                    printf("请输入旧密码：");
                }

                saveUsers();
                GREEN;
                printf("修改成功！\n");
                WHITE;
            }
            else
            {
                RED;
                printf("密码错误！请重新输入：\n旧密码：");
                WHITE;
            }
            }
    }
    else if(key=='2') myLend(user_index);
    else if(key=='9') {if(delUser(user_index)==1) {main();return 1;}else userLetter(user_index);}
    else if(key=='0') return 0;
    else {RED;printf("输入错误！正在退出...\n");WHITE;Sleep(1000);return 0;}
    
    return 0;

}

//用户注销用户，只在登陆时使用
int delUser(int user_index){
    char passwd[20];//验证用
    char key;
    RED;
    if(users[user_index].lendBooksNum)//如果用户有借书
    {
        printf("您有图书未归还，请归还后重试！\n");
        getchar();
        return 0;
    }
    printf("你确定要注销你的账号吗？(Y/N)\n");
    WHITE;
    getchar();//过滤掉回车
    scanf("%c",&key);

    if(key=='Y'||key=='y'){
        printf("请验证密码：");
        // scanf("%d",&passwd);
        inputPwd(passwd,20);

        if(strcmp(passwd,users[user_index].user_password)==0)
        {
            
            users[user_index].user_id=0;
            users[user_index].integral=0;
            users[user_index].vip=0;
            users[user_index].lendBooksNum=0;//清空用户借书数量
            strcpy(users[user_index].user_name,"");
            strcpy(users[user_index].user_password,"");
            memset(&users[user_index],0,sizeof(struct Users));//清空用户信息
            saveUsers();//保存
            GREEN;
            printf("注销成功！按任意键退出\n");
            WHITE;
            getchar();
            return 1;
        }
        else{
            RED;
            printf("密码错误！\n");
            WHITE;
            return 0;
        }
    }
    else{
        YELLOW;
        printf("操作被用户取消！\n");
        WHITE;
    }

    return 0;
    
}

//管理员显示用户
void showUsers()
{
    if(isUserEmpty())
    {   
        YELLOW;
        printf("用户列表为空！\n");
        WHITE;
        return;
    }
    int i;

	printf("%10s %20s %10s %10s\n","用户ID","用户名","用户积分","VIP状态");
    
    GRAY;//灰色
	for(i=0;i<MAX_USERS_NUM;i++){
		if(strlen(users[i].user_name)>0)//用户名不为空，说明用户存在
        {
			printf("%10d %20s %10d %10d级",
            users[i].user_id,
            users[i].user_name,
			users[i].integral,
			users[i].vip);
            printf("\n");
		}
	}
    WHITE;//白色
}

//修改信息
void modUserAdm()
{
    if(isUserEmpty())
    {   
        YELLOW;
        printf("用户列表为空！\n");
        WHITE;
        return;
    }
    int id;
    char key;  //输入的按键
    
    GRAY;//灰色
    printf("是否列出用户列表(Y/N)?\n");
    key=getch();
    if(key=='y'||key=='Y') showUsers();

    printf("请输入要修改的用户ID: ");
    while(scanf("%d",&id))
    {
        id=ID2Index(id,0);//转换为索引
        if(isUserAvl(id)) break;//用户存在，退出循环
        else printf("用户不存在，请重新输入：");
    }


        if (strlen(users[id].user_name)>0)
        {
            WHITE;//白色
            printf("查询成功，找到用户：\n");
            GRAY;
            printf("用户ID: %d\n",users[id].user_id);
            printf("用户名: %s\n",users[id].user_name);
            printf("用户积分: %d\n",users[id].integral);
            printf("VIP等级: %d级\n",users[id].vip);
            WHITE;//白色

            YELLOW;//黄色
            printf("是否开始修改?[Y]\n");
            WHITE;
            key = getch();
            if (key != 'y' && key != 'Y') {
                RED;//红色
                printf("操作被用户取消！ \n");
                return ;
            }

            YELLOW;
            //提示用户是否修改每个字段
            printf("请确认是否要修改用户名(Y/N)?\n");
            WHITE;
            key = getch();
            if (key == 'y' || key == 'Y') {
                printf("请输入:");
                scanf("%s", users[id].user_name);
                printf("修改成功！\n");
            }

            YELLOW;
            printf("请确认是否要修改密码(Y/N)?\n");
            WHITE;
            key = getch();
            if (key == 'y' || key == 'Y') {
                printf("请输入:");
                scanf("%s", users[id].user_password);
                printf("修改成功！\n");
            }

            YELLOW;
            printf("请确认是否要修改积分(Y/N)?\n");
            WHITE;
            key = getch();
            if (key == 'y' || key == 'Y') {
                printf("请输入:");
                while(scanf("%d", &users[id].integral))
                {
                    if(users[id-1].integral<0){
                        RED;
                        printf("积分设定错误！请重新输入\n");
                        WHITE;
                    }
                    
                    else 
                    {
                        GREEN;
                        printf("修改成功！\n");
                        WHITE;
                        break;
                    }
                }
            }

            YELLOW;
            printf("请确认是否要修改VIP等级(Y/N)?\n");
            WHITE;
            key = getch();
            if (key == 'y' || key == 'Y') {
                printf("请输入(0-%d):",TOP_VIP_GRADE);
                while(scanf("%d", &users[id].vip))
                {
                    if(users[id-1].integral<0||users[id-1].vip>TOP_VIP_GRADE)
                    {
                        RED;
                        printf("VIP等级设定错误！请重新输入\n");
                        WHITE;
                    }
                    
                    else 
                    {
                        GREEN;
                        printf("修改成功！\n");
                        WHITE;
                        break;
                    }
                }
            }



            saveUsers();
            GREEN;
            printf("\n用户信息修改成功!\n");
            WHITE;

            return;
        }
    RED;
    printf("没有该用户！\n");
    WHITE;
    return ;
}

//管理员管理用户
void manageUser()
{
    // int id;
    char key;  //输入的按键
    int key_num;//输入的数字
    
    GRAY;//灰色
    printf("是否列出用户列表(Y/N)?\n");
    key=getch();
    if(key=='y'||key=='Y') showUsers();
    
    YELLOW;
    printf("请选择要执行的操作:\n");

    WHITE;printf("1.");GRAY;printf("删除用户\n");
    WHITE;printf("2.");GRAY;printf("修改用户\n");
    WHITE;printf("3.");GRAY;printf("添加用户\n");
    WHITE;printf("0.");GRAY;printf("返回\n");
    WHITE;

    while(scanf("%d",&key_num))
    {
        if(key_num==2){modUserAdm();break;}
        else if(key_num==1) {delUserAdm();break;}
        else if(key_num==3){addUserAdm();break;}
        else if(key_num==0){break;return;}
        else {RED;printf("输入错误！\n");WHITE;}
    }
    return ;
}

//管理员删除用户
void delUserAdm()
{
    if(isUserEmpty())
    {
        RED;//红色
        printf("用户列表为空！\n");
        WHITE;
        return ;
    }
    char key;//输入的按键
    int id;
    char yn[20];//二级确认删除

    RED;
    printf("是否全部删除全部用户?这可能导致意外的后果(y/n)\n");
    WHITE;
    key=getch();

    if(key=='y'||key=='Y')
    {
        printf("请输入");RED;printf("yes");WHITE;printf("以继续操作:");
        scanf("%s",yn);
        if(strcmp(yn,"yes")!=0){
            printf("操作取消！\n");
            return ;
        }
        remove("users.txt");//删除文件
        FILE *file;//重新定义指针以生成文件
        file=fopen("users.txt","w");//以写模式（w）打开文件，这样做可以新建文件
        GREEN;
        printf("删除成功！\n");
        WHITE;
        fclose(file);//关闭文件
        
        memset(users,0,sizeof(users));//清空结构数组
        
        return;
    }



    GRAY;//灰色
    printf("是否列出用户列表(Y/N)?\n");
    key=getch();
    if(key=='y'||key=='Y') showUsers();

    printf("开始进行删除用户操作？(Y/N)\n");
    getchar();//过滤掉回车
    scanf("%c",&key);

    if(key=='y'||key=='Y')
    {
            printf("请输入要删除的用户的ID: ");
            while(scanf("%d",&id))
            {
                id=ID2Index(id,0);//转换ID为索引
                if(isUserAvl(id)) break;//用户存在，退出循环
                else {
                    RED;
                    printf("用户不存在，请重新输入：");
                    WHITE;
                }
            }


            users[id].user_id=0;
            users[id].integral=0;
            users[id].vip=0;
            strcpy(users[id].user_name,"");
            strcpy(users[id].user_password,"");
            memset(&users[id],0,sizeof(struct Users));//清空用户信息
            saveUsers();//保存
            GREEN;
            printf("注销成功！按任意键退出\n");
            WHITE;
    }
    else {
        RED;
        printf("操作被管理员取消！按任意键退出\n");
        WHITE;
    }
    getchar();  
    return ;

}

//删除user.txt文件
void Rec()
{
    remove("users.txt");//删除文件
    return ;
}

// 我的积分
void userIntegral(const int user_index)
{
    if(users[user_index].vip==TOP_VIP_GRADE){
        YELLOW;
        printf("当前账户积分剩余：%d\n",users[user_index].integral);
        printf("当前用户VIP等级为：%d\n",users[user_index].vip);
    }
    else{
        WHITE;
        printf("当前账户积分剩余：%d\n",users[user_index].integral);
        printf("当前用户VIP等级为：%d\n",users[user_index].vip);
    }

    if(users[user_index].integral >= TOP_POINTS && users[user_index].vip < TOP_VIP_GRADE) {
        GRAY;
        printf("您的积分可以进行兑换VIP等级,是否兑换VIP等级？[Y]\n");
        WHITE;
    }
    else if(users[user_index].vip==TOP_VIP_GRADE) {YELLOW;printf("您已为尊贵的VIP8用户，正在为您退出...\n");WHITE;return ;}
    else return ;
    char yn;
    yn=getch();
    if(yn!='Y'&&yn!='y')
    {
        YELLOW;
        printf("用户取消了操作，正在退出...");
        WHITE;
        return ;
    }

    int wantUP=0;//用户想要提升的VIP等级
    BLUE;
    printf("请输入想要兑换的VIP等级：");
    WHITE;
    while(scanf("%d",&wantUP))
    {

    if(wantUP+users[user_index].vip > TOP_VIP_GRADE)
    {
        RED;
        printf("最高的VIP等级为%d级！请重新输入：\n",TOP_VIP_GRADE);
        WHITE;
        // scanf("%d",&wantUP);
    }
    else if(users[user_index].integral/TOP_POINTS < wantUP)
    {
        RED;
        printf("您的积分不足以兑换该VIP等级，请重新输入：");
        WHITE;
        // scanf("%d",&wantUP);
    }
    else
    {
        users[user_index].vip+=wantUP;
        users[user_index].integral-=wantUP*TOP_POINTS;
        saveUsers();//保存
        GREEN;
        printf("兑换成功！\n");
        WHITE;
        break;
    }
    }
    return ;
}

//判断用户是否合法
int isUserAvl(const int user_index){
    if(user_index>MAX_USERS_NUM||user_index<0) return 0;//用户ID不合法，返回0
    if(users[user_index].user_name) return 1;//用户存在
    return 0;
}

//计算用户数量
int countUserNum()
{
    int i;
    int num=0;
    for(i=0;i<MAX_USERS_NUM;i++)
    {
        if(users[i].user_id) num++;//用户存在，数量加1
    }
    LibR.userNum=num;//保存用户数量
    LibR.isUserEmpty=1;//初始化为1，表示为空
    if(num!=0) LibR.isUserEmpty=0;//如果用户存在，则为0
    return num;
}

//判断是否没有用户
int isUserEmpty(){
    countUserNum();//计算用户数量
    return LibR.isUserEmpty;
}

//用户ID和用户索引的转化
int ID2Index(const int n,int mode)
{
    int change=1001;//用户ID和用户索引的转化值
    if(mode==0) return n-change;//模式为0时，将用户ID转化为用户索引
    else return n+change;//模式为1时，将用户索引转化为用户ID
}

//输入确认
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
        printf("请输入：\n");
        WHITE;
        return 1;
    }
/* 
让用户确认输入的函数，用户输入N/n返回0，其他返回1
msg表示提示用户输入的文字 */
}

//输入确认1
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
        printf("请输入：");
        WHITE;
        scanf(m,a);
        return 1;
    }
}


























//查看书籍
void queryBook(){
    if(isLibEmpty()) {printf("无藏书！\n");return;}

    BLUE;
	printf("  编号   %20s %10s %10s %20s %20s %10s\n", "书名","作者","价格","出版社","ISBN","出借状态");
    WHITE;
    int showindex=1;//显示索引
    
    GRAY;//灰色
    int i=0;
	for( i=0;i<MAX_BOOKS_NUM;i++){
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
 
//显示书籍详情
void showBookDetail()
{
    char msg[20];
    queryBook();
    if(isLibEmpty()){return;}

    int bookindex=1;

    printf("显示书籍详情?(查找ISBN[I]/查找书名[N]/取消[E])\n");
    char key=getch();
    if(key=='E'||key=='e') {printf("操作已全部完成，正在退出...\n");return;}
    else if(key=='I'||key=='i') 
        {        
            GRAY;printf("请输入要详细查看的书籍的ISBN:");WHITE;
            scanf("%s",msg);
                bookindex=searchBook(msg,1);//查找书籍索引
                if(bookindex==-1) {printf("没有找到该书籍，");return;}
            
        }
    else if(key=='N'||key=='n') 
        {        
            GRAY;printf("请输入要详细查看的书籍的书名:");WHITE;
            scanf("%s",msg);
            {
                bookindex=searchBook(msg,2);//查找书籍索引
                if(bookindex==-1) {printf("没有找到该书籍，");return;}
            }
        }
    else {RED;printf("未知操作，正在退出...\n");WHITE;return;}

        printf("\n找到书籍：\n");
        GRAY;
        printf("书名:\t\t%s\n",books[bookindex].name);
        printf("ISBN:\t\t%s\n",books[bookindex].isbn);
        printf("作者:\t\t%s\n",books[bookindex].author);
        printf("价格:\t\t%.2f\n",books[bookindex].price);
        printf("出版社:\t\t%s\n",books[bookindex].press);
        if(books[bookindex].isLend) 
        {
            printf("出借状态:\t已借出\n");
            printf("借书用户:\t%s\n",books[bookindex].name);
            printf("用户ID:\t\t%d\n",books[bookindex].lenduserid);
            printf("备注:\t\t%s\n",books[bookindex].lendMessage);
            }
        else printf("出借状态:\t未借出\n");
        WHITE;
        return ;
    
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
                    {YELLOW;printf("已有此书,请重新输入：");WHITE;}
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
                    {YELLOW;printf("价格设定错误！清重新输入价格\n");WHITE;}
                    else break;
                }

            printf("请输入出版社：");
            scanf("%s", books[i].press);

            books[i].isLend=0;//初始化为未借出
            books[i].lendMessage[0]='\0';//初始化为空字符串
            books[i].lenduserid=0;//初始化为0


            saveBooks(); // 写入文件
            break;
        }

    if (i == MAX_BOOKS_NUM)
        {RED;printf("书库已满！");WHITE;}
    else
        {GREEN;printf("保存成功！");WHITE;}}

// 读取文件 
void loadBooks(){//黑心商家赚钱的地方啊
    system("color 14");//蓝屏
	FILE*file;
	file=fopen("books.txt","r");//以读模式（r）打开文件
	
	if(file !=NULL){
		//文件不为NULL，就读取文件
        while(1)
        {
            fread(books,sizeof(books),1,file);
            if(feof(file)) break;
        }
	}
    else {
        CONSOLE_CURSOR_INFO cursor_info = {1, 0};SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);//隐藏光标
        printf(":-(\n您的系统遇到问题,需要重新启动,我们正在搜集问题\n");
        Sleep(1000);
        int i=0;
        for( i=0;i<100;i++)
        {
            printf("%d%%",i);
            Sleep(50);
            printf("\b\b\b");
        }
        printf("检测到丢失books.txt,正在尝试自动修复...\n");
            remove("books.txt");//删除文件
        Sleep(1000);
        printf("正在添加文件...\n");
        Sleep(1000);
        printf("添加成功，正在重新设置指针...\n");
        file=fopen("books.txt","w");//以写模式（w）打开文件，这样做可以新建文件
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
            printf("联系方式：\nQQ:848484848\nEmail:");
            }
        exit(ERROR_READ);
    }
	fclose(file);
} 

// 存储书籍信息文件
void saveBooks(){
	//将books存入文件“books.txt”
	FILE*file;//定义文件指针
	file=fopen("books.txt","a+");//以追加模式（a）打开文件
	//file为NULL 那么表示文件不存在，系统会创建该文件
	//参数说明：1写入数据对象，2写入数据大小，3写入次数，4文件指针
	fwrite(books,sizeof(books),1,file);
	fclose(file);//关闭文件 
}

// 删除图书
void delBook() {
    //用isbn查找图书
    
    if(isLibEmpty()) {YELLOW;printf("无藏书！正在退出...\n");WHITE;return;}
    char isbn[20];
    int i;
    char yn[10];

    char key;//操作键
    RED;
    printf("是否全部删除?(y/n)\n");
    WHITE;
    key=getch();

    if(key=='y'||key=='Y')
    {
        printf("请输入:");RED;printf("yes");WHITE;printf("以继续操作:");
        scanf("%s",yn);
        if(strcmp(yn,"yes")!=0){
            printf("操作取消！\n");
            goto ctn;
        }
        remove("books.txt");//删除文件
        FILE *file;//重新定义指针以生成文件
        file=fopen("books.txt","w");//以写模式（w）打开文件，这样做可以新建文件
        GREEN;
        printf("删除成功！\n");
        WHITE;
        fclose(file);//关闭文件
        
        for( i=0;i<MAX_BOOKS_NUM;i++)//循环删除
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
    printf("请输入要删除的图书的ISBN: ");
    scanf("%s", isbn);
    for (i = 0; i < MAX_BOOKS_NUM; i++) {
        if (strcmp(books[i].isbn, isbn) == 0) {
            printf("书名： \t%s\n", books[i].name);
            printf("作者： \t%s\n", books[i].author);
            printf("价格： \t%10.2f\n", books[i].price);
            printf("出版社: \t%s\n", books[i].press);
            printf("请确认是否要删除该图书(Y/N)");
            scanf("%s", yn);
            if (strcmp(yn, "y") == 0 || strcmp(yn, "Y") == 0) {
                strcpy(books[i].isbn, "");
                strcpy(books[i].name, "");
                strcpy(books[i].press, "");
                books[i].price = 0;
                memset(&books[i],0,sizeof(struct Book));//清空书籍信息

                //写入文件
                saveBooks();
                printf("图书删除成功! \n");
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
    printf("是否列出图书列表(Y/N)?\n");
    key=getch();
    if(key=='y'||key=='Y') queryBook();

    printf("请输入要修改的图书的ISBN: ");
    scanf("%s", isbn);
    for (i = 0; i < MAX_BOOKS_NUM; i++) {
        if (strcmp(books[i].isbn, isbn) == 0)
        {
            WHITE;//白色
            printf("查询成功，找到匹配书籍：\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY);//灰色
            printf("\n\t||书名: \t%s\n", books[i].name);
            printf("\t||作者: \t%s\n", books[i].author);
            printf("\t||价格: \t%10.2f\n", books[i].price);
            printf("\t||出版社：\t%s\n\n", books[i].press);

            YELLOW;//黄色
            printf("是否开始修改(Y/N)?\n");
            key = getch();
            if (key == 'n' || key == 'N') {
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

            printf("请确认是否要修改作者(Y/N)?\n");
            key = getch();
            if (key == 'y' || key == 'Y') {
                printf("请输入:");
                scanf("%s", books[i].author);
                printf("修改成功！\n");
            }

            printf("请确认是否要修改价格(Y/N)?\n");
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

            printf("请确认是否要修改出版社(Y/N)?\n");
            key = getch();
            if (key == 'y' || key == 'Y') {
                printf("请输入:");
                scanf("%s", books[i].press);
                printf("修改成功！\n");
            }
            saveBooks();

            GREEN;
            printf("\n图书修改成功!\n");
            WHITE;

            return;
        }
    }
    RED;
    printf("没有该图书！\n");
    WHITE;
}

// 个人借阅信息
void myLend(const int user_index)
{
    int i=0;
    int bookindex=1;//是否有借书记录
    if(users[user_index].lendBooksNum)//如果有借到书
    
    for( i=0;i<11;i++)
    {
        if(strlen(users[user_index].lendBooksIsbn[i])) //如果有借书
        {
            printf("第%2d本.ISBN:%s\n",bookindex++,users[user_index].lendBooksIsbn[i]);
        }
    }
    else {BLUE;printf("您当前没有借书，快去借书吧！\n");WHITE;}
}

//用户借阅
void userLend(const int user_index){

    int book_lend_avl=0;//是否有在库书籍
    int i=0;

    if(users[user_index].lendBooksNum>=10)//如果已经借了10本书了
    {
        printf("您已经借了10本书了,不能再借了！\n");
        return ;
    }
    GRAY;
    printf("是否列出书籍列表(Y/N)?\n");
    WHITE;
    char key=getch();
    if(key=='y'||key=='Y') queryBook();

    GRAY;
    printf("是否开始借阅?(Y/N)\n");
    WHITE;
    key=getch();
    if(key=='n'||key=='N') 
    {
        RED;
        printf("操作取消！\n");
        return ;
        WHITE;
    }
    
    for( i=0;i<MAX_BOOKS_NUM;i++)
    {
        if(books[i].isLend!=1 && strlen(books[i].isbn))//如果书籍未借出且有书
        {book_lend_avl=1;break;}//有书可借
    }

    if(!book_lend_avl) {RED;printf("没有可借的书籍！\n");WHITE;return ;}//没有可借的书籍

    GRAY;
    printf("请输入要借阅的书籍的ISBN:");
    WHITE;
    char isbn[20];
    scanf("%s",isbn);
    WHITE;

    for( i=0;i<MAX_BOOKS_NUM;i++)
    {
        if(strcmp(books[i].isbn,isbn)==0)//如果找到了书籍
        {
            if(books[i].isLend) //如果书籍已经被借出了
            {
                RED;
                printf("该书籍已经被借出了！\n");
                WHITE;
                return ;
            }
            else //如果书籍没有被借出
            {
                WHITE;
                books[i].isLend=1;//标记为已经借出
                books[i].lenduserid=ID2Index(user_index,1);//将借阅者的id记录在书籍信息中
                int j=0;
                for( j=0;j<10;j++)
                {
                    if(!strlen(users[user_index].lendBooksIsbn[j]))//如果该用户借书还没有满10本
                    {
                        strcpy(users[user_index].lendBooksIsbn[j],books[j].isbn);//把书籍的ISBN存入用户的借书记录中
                        users[user_index].lendBooksNum++;//借书数量加1
                        break;
                    }
                }
                saveBooks();//保存书籍信息
                saveUsers();//保存用户信息
                GREEN;
                printf("借阅成功！\n");
                WHITE;
                return ;
            }
        }
    }
}

// 用户归还
void userBack(const int user_index)
{
    if(!users[user_index].lendBooksNum)//如果没有借书
    {
        PINK;
        printf("您还没有借书喔，快去借书吧！\n");
        WHITE;
        return ;
    }

    int bookFind=0;
    int i=0;
    GRAY;
    printf("是否列出您的借阅书籍列表(Y/N)?\n");
    WHITE;
    char key=getch();
    if(key=='y'||key=='Y') myLend(user_index);
    GRAY;
    printf("请输入要归还的书籍的ISBN:");
    WHITE;
    char isbn[20];
    scanf("%s",isbn);
    
    for( i=0;i<10;i++)
    {
        if(strcmp(users[user_index].lendBooksIsbn[i],isbn)==0)//如果用户有借这本书
        {
            int book_index=0;//书本在图书馆中的索引
            book_index=searchBook(isbn,1);//查找书籍在图书馆中的索引
            bookFind=1;//找到了书籍
            books[book_index].isLend=0;//标记为未借出
            books[book_index].lenduserid=0;//清空借书用户ID
            strcpy(books[book_index].lendMessage,"");//清空备注
            users[user_index].lendBooksNum-=1;//借书数量减1
            users[user_index].integral+=1;//积分加一
            strcpy(users[user_index].lendBooksIsbn[i],"");//清空借书记录中的书籍ISBN
            saveBooks();//保存书籍信息
            saveUsers();//保存用户信息
            printf("归还成功！\n");
            return ;
        }
    }
    
    if(!bookFind) {BLUE;printf("没有找到该书籍，看起来您似乎没有借过这本书呢\n");WHITE;}
}

//判断书籍重复
int isBookRepeat(const char *isbn,const int index)
{
    int j;
    for(j=0;j<MAX_BOOKS_NUM;j++)
    {
        if(strcmp(books[j].isbn,isbn)==0&&j!=index)//如果有重复的isbn
        {
            return 1;
        }
    }
    return 0;
}

// 管理员借出图书
void lendBooks() {
    
    int book_lend_avl;//图书是否可借
    int i=0;

    if(!countBooks(2)) {YELLOW;printf("无可借出藏书！\n");WHITE;return;}
    char isbn[20];//要借出的书籍的isbn号码
    char yn[10];
    char key;
    int userid;//要借书籍的用户id
    int userindex;//要借书的用户索引
    int flagbookindex=-1;//标记图书在books数组中的位置

    for( i=0;i<MAX_BOOKS_NUM;i++)//遍历books数组
    {
        if(books[i].isLend!=1&&strlen(books[i].isbn)!=0)//如果该图书未借出
        {
            book_lend_avl=1;//标记图书在books数组中的位置
            break;
        }
    }

    if(book_lend_avl==0)//如果所有图书都已借出
    {
        YELLOW;
        printf("无可借出图书！\n");
        WHITE;
        return;
    }

    
    
    GRAY;//灰色
    printf("列出图书列表?[Y]\n");
    WHITE;
    key=getch();
    if(key=='y'||key=='Y') queryBook();

    GRAY;
    printf("开始借阅?    [Y]\n");
    WHITE;
    key = getch();
    if (key != 'y' && key != 'Y') {
        RED;//红色
        printf("操作被用户取消！ \n");
        WHITE;
        return ;
    }
    WHITE;//白色

    printf("请输入借阅者的用户ID：");
    while(scanf("%d",&userid))//判断用户id是否合法
    {   
        userindex=ID2Index(userid,0);//将用户id转换为用户在users数组中的位置
        if(!isUserAvl(userindex)) {RED;printf("用户不存在，请重新输入:");WHITE;}
        else if(users[userindex].lendBooksNum>=10) {YELLOW;printf("用户借书已满，请重新输入:");WHITE;}
        else break;
    }

    GRAY;
    printf("请输入要借出的图书ISBN：");
    WHITE;
    while(scanf("%s",isbn))//判断图书是否存在
    {   
        flagbookindex=searchBook(isbn,1);
        if(flagbookindex==-1) {RED;printf("图书不存在，请重新输入:");WHITE;}
        else if(flagbookindex!=-1 && books[flagbookindex].isLend==1) {YELLOW;printf("图书已借出，请重新输入:");WHITE;}
        else {BLUE;printf("找到图书：\n");break;}
    }

    GRAY;//灰色
    printf("书      名 : \t%s\n", books[flagbookindex].name);
    printf("作      者 : \t%s\n", books[flagbookindex].author);
    printf("价      格 : \t%10.2f\n", books[flagbookindex].price);
    printf("出  版  社 : \t%s\n", books[flagbookindex].press);
    printf("借 出 状 态: \t%s\n", books[flagbookindex].isLend == 1 ? "借出" : "在库");

    printf("请确认是否要借出该图书(Y/N)?");
    WHITE;
    scanf("%s", yn);
    GRAY;
    if (strcmp(yn,"y") == 0 || strcmp(yn,"Y") == 0)
    {
        books[flagbookindex].isLend = 1;//将图书的借出状态改为1
        books[flagbookindex].lenduserid = userid;//将图书的借出者id改为用户id
        printf("请输入备注:");
        scanf("%s", books[flagbookindex].lendMessage);//将图书的借出日期改为当前日期
        users[userindex].lendBooksNum+=1;//将用户的借书数量加1
        
        for( i=0;i<11;i++)
        {
            if(users[userindex].lendBooksNum>=10) {printf("此用户借书已满！正在退出...");return;}//如果用户借书已满，则直接退出
            else if(strlen(users[userindex].lendBooksIsbn[i])==0)//如果该用户的借书isbn数组为空，则直接添加
            {
                strcpy(users[userindex].lendBooksIsbn[i],isbn);//将图书的isbn放入用户的借书isbn数组中
                break;
            }
        }

        saveBooks();//保存图书信息
        saveUsers();//保存用户信息
        GREEN;
        printf("借出成功！\n");
    }
    else {RED;printf("取消借出！\n");}

    WHITE;//白色
    return;
}

// 管理员归还图书 
void backBooks() {

    if(countBooks(1)==0){GREEN;printf("没有书籍被借阅！\n");return;}
	int backuserid;//还书的用户id
    int backuserindex;//还书的用户index
    int flagbookindex=-1;//标记图书在books数组中的位置
    char isbn[20] = "";
    char key;
    int i=0;

    

    WHITE;
	
    
    // 根据用户编号，查找借阅记录
    GRAY;
    printf("请输入要归还的用户ID：");
    WHITE;
    while(scanf("%d",&backuserid))//判断用户id是否合法
    {   
        backuserindex=ID2Index(backuserid,0);//将用户id转换为用户在users数组中的位置
        if(!isUserAvl(backuserindex)) {RED;printf("用户不存在，请重新输入:");WHITE;}
        else break;
    }

    GRAY;
    printf("%s的借阅情况：\n", users[backuserindex].user_name);
    int shownum=1;//记录已经显示的图书数量
    if(users[backuserindex].lendBooksNum == 0) {YELLOW;printf("他没有借书！\n");return;}
    else
    {
        YELLOW;
        printf("他借了 %d 本书\n", users[backuserindex].lendBooksNum);
        WHITE;
        for( i=0;i<10;i++)
        {
            printf("第%2d本.\tISBN：%s\n", shownum++, users[backuserindex].lendBooksIsbn[i]);//打印用户的借书isbn数组
            // if(strlen(users[backuserindex].lendBooksIsbn[i])==0) break;//如果该用户的借书isbn数组为空，则直接退出
            if(shownum>users[backuserindex].lendBooksNum) break;//如果已经显示的图书数量大于用户的借书数量，则直接退出
        }
    }
    
    GRAY;
    printf("请输入要归还的图书ISBN：");
    WHITE;
    while(scanf("%s", isbn))//获取图书isbn
    {
        flagbookindex=searchBook(isbn,1);//查找图书，返回索引
        if(flagbookindex==-1) {RED;printf("图书不存在，请重新输入:");WHITE;}
        else if(flagbookindex!=-1 && !books[flagbookindex].isLend) {RED;printf("图书未借出，请重新输入:");WHITE;}
        else if(flagbookindex!=-1 && books[flagbookindex].lenduserid!=backuserid) {RED;printf("图书不属于此用户，请重新输入:");WHITE;}
        else {GREEN;printf("找到图书：\n");break;}

    }

     GRAY;//灰色
        printf("书		 名  ：\t%s\n",books[flagbookindex].name);
        printf("作		 者  ：\t%s\n",books[flagbookindex].author);
        printf("价		 格  ：\t%.2f\n",books[flagbookindex].price);
        printf("出  版   社  ：\t%s\n",books[flagbookindex].press);
        printf("借  阅   人  ：\t%s\n",users[backuserindex].user_name);
        printf("备       注  ：\t%s\n",books[flagbookindex].lendMessage);
        printf("用   户  ID  ：\t%d\n",users[backuserindex].user_id);
        GRAY;
        printf("是否确认归还？(Y/N)\n");
        WHITE;
        key = getch();

        if(key == 'y' || key == 'Y')//如果确认归还，则将图书的借出日期改为空，并将用户的借书数量减1
        {
            strcpy(books[flagbookindex].lendMessage,"");//清空备注
            books[flagbookindex].isLend = 0;//将图书的借出状态改为0
            users[backuserindex].lendBooksNum--;//将用户的借书数量减1
            for( i=0;i<11;i++)//将用户的借书isbn数组中的此图书isbn改为空
            {
                if(strcmp(users[backuserindex].lendBooksIsbn[i],isbn)==0) strcpy(users[backuserindex].lendBooksIsbn[i],"");
            }
            saveBooks();//保存图书信息
            saveUsers();//保存用户信息
            GREEN;
            printf("归还成功！\n");
        }
        else {RED;printf("取消归还！\n");}
        


    WHITE;//白色
} 

// 搜索图书，返回索引，如果没有找到，返回-1
int searchBook(char *msg, int mode)
{//第一个是按照书籍ISBN查找，第二个是按照书名查找，第三个是搜索方式，为1时按照ISBN查找，为2时按照书名查找
    int flagbookindex = -1;//标记图书在books数组中的位置
    if(mode == 1)//按照ISBN查找
    {
        int i=0;
        for( i=0;i<=MAX_BOOKS_NUM;i++)//判断图书是否存在
        {
            if(strcmp(books[i].isbn,msg)==0) {flagbookindex=i;break;}//如果找到，则将图书在books数组中的位置赋给flagbookindex
            else if(i==MAX_BOOKS_NUM) return -1;//如果没有找到
        }
    }
    else if(mode == 2)//按照书名查找
    {
        int i=0;
        for( i=0;i<=MAX_BOOKS_NUM;i++)//判断图书是否存在
        {
            if(strcmp(books[i].name,msg)==0) {flagbookindex=i;break;}//如果找到，则将图书在books数组中的位置赋给flagbookindex
            else if(i==MAX_BOOKS_NUM) return -1;//如果没有找到
        }
    }
    return flagbookindex;//返回图书在books数组中的位置

}

//计算藏书数量，mode为0返回总数，为1返回已借出，为2返回未借出
int countBooks(int mode){ 

    if(mode==0){//mode为0时返回总书籍的数目
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


    if(mode==1){//为1返回已借出
        int i, count = 0;
        for (i = 0; i < MAX_BOOKS_NUM; i++) {
            if (strlen(books[i].isbn) > 0 && books[i].isLend==1) {
                count++;
            }
        }
        LibR.lendBooksNum = count;
        return count;
    }

    if(mode==2){//为2返回未借出
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

//判断是否为空
int isLibEmpty() {
    countBooks(0);
    return LibR.isBookEmpty;
}


