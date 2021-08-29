#include<stdio.h>
/*
=========1.========
输入10个整数,将这10个整数按升序排列输出,并且奇数在前,偶数在后
<思想>:讲输入的10个整数 按照奇偶性扽别放在数组a的左部分和右部分,
方法就是设置两个整型变量 odd  even,分别表示奇数和偶数在舒徐中元素的下标.
odd初始值为0,没存放一个奇数odd+1, even初始值为9,每存放一个even -1

*/

void jiou()
{
    int i, j, even, odd, n, t, a[10];
    odd = 0; // 奇数 
    even = 9;  //偶数
    for(i=0,i<10;i++){
        scanf("%d",&n);
        if(n%2==0)
            a[add++] = n;
        else
            a[even--] = n;  //偶数放在右边
    }
    for(i=0;i<odd-1;i++)   //通过选择排序进行升序排列
    {
        n = i;
        for(j=i+1;j<odd;j++){
            if(a[j]<a[n]){
                n=j;
            }
            if(n!=i){
                t = a[i];
                a[i] = a[n];
                a[n] = t;
            }
        }

        for(i = odd;i<9;i++){
            n=i;
            for(j=i+1;j<10;j++)
                if(a[j]<a[n])
                n=j;
            if(n!=i){
                t=a[i];
                a[i]=a[n];
                a[n]=t;
            }
        }

        for(i=0;i<10;i++){
            printf("%d",a[i]);
        }
    }
}


/*
=========2.=============
从键盘输入10个整数,编程实现将其中最大的数和最小的数的位置对换后, 在输出调整后的数组
<思想>: 先输入的10个整数存入数组A中,然后通过对比找到最大值和最小值元素的下标,
分别用变量MAX和 MIN表示,最后交换最大数和最小数

*/

void Max_Min(){
    int i, max, min, a[10];
    printf("Input 10 integer number:\n");
    for(i=0;i<10;i++){
        scanf("%d",&a[i]);
    }
    max = 0;
    min = 0;
    for(i=1;i<10;i++){  //求最大值和最小值的元素下标
        if(a[i]>a[max])
            max = i;
        if(a[i]<a[min])
            min = i;
    }
    i=a[max];
    a[max]=a[min];
    a[min]=i;
    for(i=0;i<10;i++){
        printf("%d",&a[i]);
    }
}