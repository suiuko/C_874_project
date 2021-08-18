#include<stdio.h>
/*
===1.=====
键盘中统计数组字符个数
*/
int n=0;c;
c = getchar();
while(c!='\n'){
    if(c>='0'&&c<='9')
        n++;
    c = getchar();
}

/*
=====2.======
输出100以内能被3整除且个位数为6的所有整数
*/
void zhengchu(){
    for(i=0;i<10;i++){
        j=i*10 +6;
        if(j%3)
            continue;
        printf("%d",j);
    }
}

/*
======3.======
Fibonacci 数列的前40个数，并按照4列一行输出，特点：1、2个数都是1；从第3个数开始
没个数都是前面两个数的和
*/
void fibonacci(){
    long f1 =1, f2 = 1;
    int i;
    for(i=1;i<=20;i++){
        printf("%-12d%-12d",f1,f2);
        if(i%2==0)
            printf("\n");
        f1 = f1+f2;
        f2 = f1+f2;
    }
}