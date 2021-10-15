#include<stdio.h>
/*
==========填空&选择题============
1. 函数的实参可以是常量、变量或表达式,
    但是形参只能是变量,不可以是常量或表达式

2. 
    1) 定义函数时, 形参的类型说明需要放在形参前面,不能放在函数体内.
    
    2)如果形参与实参类型不一致,应以形参类型为准.

    3) 函数的隐含存储类型是: extern

    4) 凡是函数中未指定存储类型的局部变量,其隐含的数据类型为: auto

    5)若使用一堆函数名作为函数的实参, 必须在主调函数中说明数组的大小

    6)对形参数组array正确定义的方式为:
    int a[3][4];
    f(a);
    f(int array[][4]) //正确的定义
    
    7)若用数组名作为函数的实参,传递给形参的是数组的首地址

    8)函数调用可以出现在C语言执行语句中,也可也出现在表达式中,甚至可以作为一个函数的实参
    但是不能作为函数的形参.

    9)函数的返回值的类型是由定义该函数时所指定的数据类型来决定的.

    10)只有使用时,才为该类型分配内存的存储类说明: auto 和register
    C语言中变量的存储类型分为两种: 动态存储和静态存储,其存储类型说明符有 auto, static, register, extern
    其中 auto 和register所说明的变量是动态存储类型的变量, 该变量只有在使用时系统才会对其进行分配内存单元.

    11)在一个函数内的复合语句中定义的变量是局部变量,其作用范围是从定义处到复合语句的结束,
    也就是只在本复合语句内有效

*/

//运行结果题
//==========1.============
//以下程序运行后的结果:
float fun(int x, int y)
{
    return (x+y);
}
void main()
{
    int a = 2, b = 5, c = 8;
    printf("3.0f\n",fun((int)fun(a+c,b),a - c))
}
//首先运行: a+c ,b 得到15.000000, 转换成 15, 然后调用fun(15,a-c) 得到9.000000换成 9




//代码题:
/*
==========1.==============
设计一个函数,用来判断一个整数是否是素数
*/
int IsPrimeNumber (int number);

void main()
{
    int a;
    printf("Input a integer number:");
    scnaf("%d",&a);
    if(IsPrimeNumber(a))
        printf("%d is prime number.\n",a);
    else
        printf("%d isn't prime number.\n",a);
}
//函数功能,判断参数是不是素数
//函数入口参数: 整型数, 要求为正整数
//函数返回值:非0表示素数,否则不是素数
int IsPrimeNumber(int number)
{
    int i;
    if(number<=1)
        return (0);
    for(i=2;i<sqrt(number);i++)
        if(number % i == 0) //被整除,不是素数
            return (0);
    return (1);
}


/*
================2.=============== 
设计一个函数,MaxCommonFactor()计算两个正整数的最大公约数

算法思想: 对A和B两个数, 当A>B时, 如果A中含有与B相同的公约数,则A中去掉B后剩余的部分A-B
也应该含有与B相同的公约数,对A-B和B计算公约数就像单于对A和B计算公约数,反复使用,直到A和B相等为止
这时A或B就是他们的最大公约数
*/
#include <stdio.h>
int MaxCommonFactor (int a, int b) ;
void main ( )
{
    int a, b, c;
    printf(" Input two integer number: ") ;
    scanf("%d%d", &a, &b);
    c = MaxCommonFactor(a, b);
    if (c != -1)
        printf ("The biggest common factor of %d and %d is %dn", a, b, c) ;
    else
        printf ("The biggest common factor of %d and %d isn't existln", a, b) ;
}
//函数功能: 计算两个正整数的最大公约数
//函数入口参数: 两个整型数
//函数返回值: 最大公约数, -1表示没有最大公约数
int MaxCommonFactor(int a,int b){
    if(a<=0 || b<=0)
        return(-1);
    while(a!=b)
    {
        if(a>b)
            a=a-b;
        else  
            if(b>a)
                b=b-a;
    }
    return(a);
}


/*
=================3.=================
定义函数Getdata()用于接受键盘输入的一组整形数据,并放入一数组中,另外定义一个函数sort()
用于对输入的这一组数据按照降序排列.

设计思想: GetData函数时用于从键盘接受一组属性数据,因此该函数要带两个行参,一个数组,
一个是数组中元素的个数,sort函数时对数组元素进行降序排列,
*/
#include<stdio.h>
#define N 10
void GetData(int a[],int n);
void Sort(int a[],int n)

void main()
{
    int i,a[N];
    GetData(a,N);
    Sort(a,N);
    printf("After sort:");
    for(i=0;i<N;i++)
        printf("%d",a[i]);
    printf("\n");
}

//通过键盘输入N个整数到数组a中
void GetData (int a[ ] , int n)
{
    int i;
    printf(" Input number :");
    for(i=0;i<n;i++)
        scanf("%d", &a[i] );
}
//对数组a中的n个元素进行降序排列(排列算法:选择排序)
void Sort (int a[ ] , int n)
{
    int i,j,k,t;
    for(i=0;i<n-1;i++)
    {
        k=i;
        for(j=i+1;j<n;j++)
            if (a[j] > a[k])
                k =j;
        if (k !=i)
        {
            t=a[i];
            a[i] = a[k] ;
            a[k] = t;
        }

}