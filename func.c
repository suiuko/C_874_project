//1. 字符数据非格式化输入

int getchar(void);//返回值是用户输入的第一个字符,

//该函数没有参数,又一个int型的返回值
//调用改函数的时候,程序就等待用户按键,回车结束

int getc(FIFE *stream);//从流文件中读取一个字符信息,回车结束

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

//3.数组赋值
memcpy(void *d,void *s,unsigned n)
//将以S为首地址的一片连续的N个字节内存单元拷贝到以d为首地址的一片连续的内存单元中.

//memset 赋值
memset(void *s,char ch,unsigned n)
//将S为首地址的一片连续的N个字节内存单元都赋值给ch

//4. 字符串输入

gets(字符数组变量名);
//功能:将输入的字符存放在数组中, 直到遇到回车换行符时返回.
//注意: 回车换行符会变成'\0'

scanf();
//使用%s控制符,遇到回车终止,
//自动在字符串后面加'\0'


//5. 字符串的输出

puts(字符串的地址);
//功能:将字符串中的字符输出到终端上, '\0'转换成'\n'

printf();
//使用%s,%s必须对应字符串第一个字符的地址.遇到'\0'停止, ('\0'不会被输出)


//6. 字符串的长度

/* 字符串常量占的内存字节数等于字符串中字符数加1*/

strlength(S) 
//求串长,返回串S的元素个数

strlen(字符串的地址);
//功能: 返回字符个数(不包含'\0')

sizeof() 
//字符数+1

//7. 字符串的复制

(1) strcpy 复制
strcpy(字符数组1,字符串2);
//功能: 将字符串2复制到字符数组1中,(包括'\0')

(2)strncpy 
strncpy(字符数组1,字符串2,长度n);
//功能:将字符串2前N个字符复制到字符数组1中去,末尾加'\0'

//8. 字符串的比较

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


//9. 字符串的连接

strcat(字符数组1,字符串2);
//功能:将字符串2连接到字符数组1的后面(包括'\0')
//其中字符串2没变,而字符数组1中的字符将增加.


//10. 指针
//地址
int a; int *p = &a;
p, &a, &(*p)  //这些都是A的地址

//赋值
int a; int *p; p = &a;
a, *p, *(&a) //这些都是A的值


// 11. 文件

//打开.
FILE *fopen(char *filename,chae *mode);
//mode-> r ,w, a(追加),t(打开文本),b(二进制文本) .记得加双引号
fopen("XX.txt","wt");

//关闭
int *fclose(FILE *filepointer);

//字符读
int fgetc(FILE *filepointer)
//从文件指针filepointer中,读入一个字符

//字符输出
int fputc(ch , FILE *filepointer);
//将字符数据ch输出到文件指针指向的文件中去,同时将读写位置指针向前移动

int foef(FILE *filepointer);
//判断文件是否结束,


//字符串读
char *fgets(char *s,int n,FILE *file);
//将file所指的文件中,读取长度最大为n-1的字符串,并在字符串末尾加'\0',然后存在S中.

//字符串写
char fputs(char *s,FILE *file);
//将存放在S中的字符串写到文件file中,注意此函数不会吧'\0'写入文件

//数据块读
fread(void *ptr,size,n,FILE *file);
//从file 读N个大小为size字节,将其放到ptr指向的内存中,同时,将读写位置指针向前移动n*size个字节

fwrite(void *ptr,size,n,FILE *file);
//将ptr所指向的内存中存放的N个大小为SIZE个字节的数据项写入到file所指向的文件中, 
//实际要写入数据的字节数是 n * size. 同时, 将读写位置指针向前移动 n * size 个字节.


int fscanf(FILE *filepointer, const char *format[,address,..])
//功能 : 从filepointer 所指向的文件中读取数据。除了多了一个文件指针的参数外,其他方面与scanf函数完全相同。

int fprintf(FILE *filepointer, const char *format[,address,....]);
//将表达式输出到`filepointer`所指向的文件中,除了多了一个文件指针的参数外, 其他方面与printf函数完全相同.
/*
`fread()``fwrite()`函数可以完成文件的任意数据读/写操作.

>读/写1个字符(或字节)数据时:选用fgetc( )和fputc( )函数。
>读/写1个字符串时:选用fgets( )和fputs( )函数。
>读/写1个(或多个)不含格式的数据时:选用fread( )和fwrite( )函数。
>读/写1个(或多个)含格式的数据时:选用fscanf( )和fprintf( )函数。

对使用文件类型的要求:

>fgetc( )和fputc( )函数主要对文本文件进行读写,但也可对二进制文件进行读写。
>fgets( )和fputs( )函数主要对文本文件进行读写,对二进制文件操作无意义。
>fread( )和fwrite( )函数主要对二进制文件进行读写,但也可对文本文件进行读写。
>fscanf( )和fprintf( )函数主要对文本文件进行读写,对二进制文件操作无意义。

*/

//文件定位读写
void rewind(FILE *filepointer);
//将filepointer 所指向的文件的位置指针重新置回到文件的开头.

int fseek(FILE *filepointer, long offset, int whence);
//将filepointer所指向的文件的位置指针移动到特定的位置. 
//这个位置由`whence`和`offset`决定,即将位置指针移动到距离`whence`的`offset`字节处, 
//`whence`的值见下
//SEEK_SET ,数值:0, 文件的开始处
//SEEK_CUR ,数值:1, 文件的当前位置
//SEEK_END ,数值:2, 文件的末尾

long ftell(FILE *filepointer)
//功能: 返回`filepointer`所指向的文件的当前位置指针的值(用相对文件开头的位移量表示)
