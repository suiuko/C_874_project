//1. 字符数据非格式化输入

int getchar(void);
//返回值是用户输入的第一个字符,该函数没有参数,又一个int型的返回值
//调用改函数的时候,程序就等待用户按键,回车结束

int getc(FIFE *stream);
//从流文件中读取一个字符信息,回车结束
//返回值: 读取对应字符的ASCII码

int getche(void);
//功能: 与getchar()相同, 唯一差别是getche直接从键盘获取键值,不等待用户按回车

int getch(void);
//功能: 与getche()相同,唯一差别是getche回显所插入的字符,getch不回显


//2. 字符数据的非格式化输出

int putchar(int c);
//功能: 显示字符c
//返回: 正常--》返回字符的代码值 ; 出错--?EOF(-1)

int putc(int c,FILE);
//功能:将字符c输出到流文件stream, 如果流文件为stdout,功能与putchar相同

int puts(char *string);
//功能:将字符串string的所有字符输出到屏幕上,输出时将自动换行


//3. 字符串输入

gets(字符数组变量名);
//功能:将输入的字符存放在数组中, 直到遇到回车换行符时返回.
//注意: 回车换行符会变成'\0'

scanf();
//使用%s控制符,遇到回车终止,
//自动在字符串后面加'\0'


//4. 字符串的输出

puts(字符串的地址);
//功能:将字符串中的字符输出到终端上, '\0'转换成'\n'

printf();
//使用%s,%s必须对应字符串第一个字符的地址.遇到'\0'停止, ('\0'不会被输出)


//5. 字符串的长度

strlen(字符串的地址);
//功能: 返回字符个数(不包含'\0')
sizef() 
//字符数+1

//6. 字符串的复制

(1) strcpy 复制
strcpy(字符数组1,字符串2);
//功能: 将字符串2复制到字符数组1中,(包括'\0')

(2)strncpy 
strncpy(字符数组1,字符串2,长度n);
//功能:将字符串2前N个字符复制到字符数组1中去,末尾加'\0'

//7. 字符串的比较

(1)strcmp
strcmp(字符串1,字符串2);
//功能:比较两个字符串的大小, 
//如果字符串1大于字符串2,返回正整数
//如果字符串1小于字符串2,返回负整数
//如果相等,返回0
//比较常用方法: if(strcmp(str1,str2)==0)

(2)stricmp
stricmp(字符串1,字符串2);
//比较两个字符串时,不区分大小写

(3)strncmp
strncmp(字符串1,字符串2,长度n);
//功能:将字符串1前n个字符的子串与字符串2前n个字符的子串进行比较

(4)strnicmp
//功能:和strncmp相同,区别是不分大小


//8. 字符串的连接

strcat(字符数组1,字符串2);
//功能:将字符串2连接到字符数组1的后面(包括'\0')
//其中字符串2没变,而字符数组1中的字符将增加.


//9. 指针
//地址
int a; int *p = &a;
p, &a, &(*p)  //这些都是A的地址

//赋值
int a; int *p; p = &a;
a, *p, *(&a) //这些都是A的值
