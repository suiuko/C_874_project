#include<stdio.h>
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