#include <stdio.h>

/*
========1.==============
输入四位十六进制整数，用反序的方式输出改十六进制数
例如：9AF0 --> 0FA9
思想：用这个数分别对 0x000f , 0x00f0 , 0x0f00, 0xf000进行按位与运算
然后分别进行左移动12位、左移4位、右移4位、右移12位
(0x9AF0 & 0x000F) <<12 ---> 0x0000
(0x9AF0 & 0x00F0) <<4 ---->0x0F00
(0x9AF0 & 0x0F00) >>4 ---->0x00A0
(0x9AF0 & 0xF000) >>12 --->0x0009
*/
void weiyiText(){
    unsigned short a ,b;
    scanf("%4x",&a); //十六进制数给a
    b = (a & 0x000F) << 12; //取a最低一位，左移12位给b
    b += (a & 0x00F0) << 4;
    b += (a & 0x00F0) >> 4;
    b += (a & 0xF000) >> 12;
    printf("%4x\n",b);
}

/*
=========2.==========
输入两个整数变量a 和 b ，要求在不借助其他变量的情况下，对 a b实现变换

思想：先将a和b的值相加给a , 然后将a-b的值给b, 最后将a-b的值（原来B的值），存入a中 
*/
void swap(){
    int a , b;
    scanf("%d %d",&a ,&b);
    printf("before swap: a = %d , b = %d\n", a, b);
    a = a + b;
    b = a - b; // B为 a的数值
    a = a - b; //(a+b)-a = b
    prinf("after swap: a = %d , b = %d", a, b);


}

/*
=========3.===========
二元一次方程，ax2+bx+c=0 ,输入a ,b, c,求X的值
思想：x1 = (-b+sqrt(b*b-4*a*c))/(2*a)
     x2 = (-b-sqrt(b*b-4*a*c))/(2*a)    
*/
void qiugen(){
    float a , b, c;
    float d;
    float x1,x2;
    printf("input a b c:\n");
    scanf("%f%f%f",&a,&b,&c);
    d = sqrt(b*b-4*a*c);
    x1 = (-b + d)/ (2 * a);
    x2 = (-b - d)/ (2 * a);
    printf("x1= %.2f x2= %.2f\n",x1,x2);
}

/*
==========4.===========
假设从键盘输入从某日午夜零点到现在已经历的时间(秒)，
编一程序计算到现在为止已经过了多少天，现在时间是多少。

*/
void time calculation(){
    unsigned long t,r;
    int d, h, m, s;
    pritf("second =");
    scanf("%d",&t);
    d = t / (24*3600); //天数
    r = t % (24*3600); //当天时间的总秒数
    h = r / 3600;      //当天的时数
    m = (r % 3600) /60 ; //当天的分数
    s = (r % 3600) % 60;  //当天的秒数
    printf("have passed days is %d ,current time is %02d:%02d:%02d\n",d,h,m,s);
}
