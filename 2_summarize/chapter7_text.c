#include<stdio.h>
#include<string.h>

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

/*
=========3.=========
编写一个程序,其功能是给一维数组A输入任意的6个整数,假设为5 7 4 8 9 1,
然后建立一个具有一下内容的方阵,并打印下来
5 7 4 8 9 1
1 5 7 4 8 9 
8 1 5 7 4 8
8 9 1 5 7 4
4 8 9 1 5 7
7 4 8 9 1 5

<思想>:将数组A的数据循环显示6次,每次显示后将数组元素进行循环右移
方法:将a[5]保存到变量t中,再将a[0]~a[4]往右移一个位置,即a[5]=a[4],
a[4]=a[3],....a[1]=a[0],然后将a[0]=t.
*/


void youyi(
    int i , j, t ,a[6];
    printf("input 6 integer number:\n");
    for(i=0;i<6;i++)
        scanf("%d",&a[i]);
    for(i=0;i<6;i++)  
    {
        for(j=0;i<6;j++)   //显示结果
            printf("%d",a[j]);
        printf("\n");
        t = a[5];
        for(j=5;j>0;j--){
            a[j]=a[j-1];  //右移动
        }
        a[0] = t;
    }
)

/*
=======4.=========
输入5*5阶的矩阵,
A.求两条对角线上的个元素之和
B.求两条对角线上行、列小表均为偶数的个元素之积
<思想>: 通过两重for循环将键盘输入的5*5的矩阵元素存放在二维数组A中,采用累加和算法:sum = sum+a[i][i]
累计左对角线上的元素之和,同时用sum = sum+a[i][4-i],累计右对角线上的元素之和(除去两对角线上的交叉元素a[2][2])
采用累成算法:mul = mul*a[i][i],累乘左对角线上行、列下标均为偶数的元素之积,
同时用mul=mul*a[i][4-i]累成右对角线上行、列下标均为偶数的元素之积(除去两对角线上的交叉元素a[2][2])

*/

void array(){
    int i, j, sum =0, mul =1, a[5][5];
    printf("input 5*5 array\n");  //输入5*5的矩阵
    for(i = 0;i<5;i++){
        for(j=0;j<5;j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("\n");

    for(i=0;i<5;i++){
        sum += a[i][i];  //对左对角线 累加
        if(i !=2)   //对右对角线的元素进行累加
            sum +=a[i][4-i];
        if(i%2 !=0)  //如果行下标为奇数, 进入下一次循环
            continue;
        mul *=a[i][i];  //对左对角线上行、列下标均为偶数的元素进行累乘
        if(i!=2)  //对右对角线上行、列下标均为偶数的元素进行累乘(中间的元素除外)
            mul *=a[i][4-i];
    }
    printf("sum = %d  mul = %d\n",sum ,mul);
}

/*
========5.========
打印杨辉三角形
<思路>:对于有6行的杨辉三角形,用一个6行6列的二维数组 a[6][6]来表示.
对于第i行的元素,a[i][0]=1; a[i][i]=1 (i=0,1,2....5),a[i][j]=a[i-1][j-1]+a[i-1][j] (j=1,2...i-1)
然后显示二维数组中计算的结果,其中第1行显示1个数据,第2行显示2个数据,...第6行显示6个数据
*/

void yanghui(){
    int i, j,a[N][N];
    for(i=0;i<N;i++){
        a[i][0]=1;
        a[i][i]=1;
        for(j=1;j<i;j++){
            a[i][j] = a[i-1][j-1] + a[i-1][j];
        }
    }

    for(i = 0;i<N;i++)  //显示结果
    {
        for(j=0;j<N-i-1;j++)
            printf(" ");
        for(j = 0;j<=i;j++)
            printf("%2d ",a[i][j]);
        printf("\n");
    }    
}


/*
=========6.=========
编写一程序实现将用户输入的一字符串以反向形式输出, 
<思想> 通过gets库函数将键盘输入的一字符串存放到一个字符数组中,
然后利用for循环将数组中的字符串从高位到低位逐个输出
*/
#define N 60
void reverse(){
    char str[N];
    int i;
    printf("INput a string:");
    gets(str);
    printf("After reverse:");
    for(i=strlen(str)-1; i>=0;i--)
        printf("%c",str[i]);
    printf("\n");
}

/*
===========7.============
将字符数组S2中的全部字符复制到字符数组S1中,不用strcpy函数,
复制时,'\0'也要复制过去. '\0'后面的字符不复制.

<思想>:使用 while(1)循环将S2 中的字符从左到右逐一复制到S1中,
如果此时复制的字符是'\0',则循环结束,输出字符串S1
*/
#define N 60
void stradd(){
    char s1[N], s2[N] = "abcdefg\0hijk";
    unsigned int i;
    i=0;
    while(1)
    {
        s1[i] = s2[i];
        if(s2[i] == '\0')
            break;
        i++;
    }
    printf("After string copy: %s\n",s1);
}


/*
=========8.========
不用strcat函数编程实现字符串连接函数strcat的功能,将字符串srcStr连接到字符串dstStr的尾部

<思想>:先找到dststr的结尾符'\0'的位置,然后通过for循环将字符串srcStr中的字符逐一复制到dstStr的后面
直到字符串srcStr的结尾符'\0'为止,最后在dsrStr的后面加上结尾符'\0'
*/

void stradd2(){
    char dsrStr[20] = "12345", srcStr[20] = "67890";
    unsigned int i, j;
    for(i=0;dstStr[i]!='\0';i++) //找到dstStr穿中'\0'所在的位置 i
        for(j=0;srcStr[j]!='\0';j++)
            dstStr[i+j] = srcStr[j];
        dstStr[i+j] = '\0';
        printf("After strcat: dstStr = %s\n",dstStr);
}


/*
=======9.=======
有一个已拍好序的整形数组,要求从键盘输入一个整数按原来的排序规律将它插入数组中
并输出结果, 比如: 原来的数据为1 3 5 7,需插入4 ,插入后为1 3 4 5 7

<思想:>假设插入前数组元素的个数为num,首先要找到在整形数组中要插入的位置,
其具体的方法: 通过循环将插入的整数N与数组中的元素a[i]从右往左进行比较,
如果此时数组元素a[i]>n,则插入的位置在元素a[i]之前的某一位置,
将a[i]往右移一个位置,循环继续.
如果a[i]<=n, 则插入的位置刚好就在a[i]之后,即a[i+1]的位置,循环结束
*/

void shengxuadd(){
    int a[10]={1,3,5,7,9}, sum = 5, i, n;
    printf("before insert: "); //显示插入之前数组元素的值
    for(i=0;i<sum;i++)
        printf("%d",a[i]);
    printf("\n");

    printf("input a number: ");
    scanf("%d",&n);
    for(i = num-1;i>=0;i--)  //从右到左将与N进行比较
        if(a[i]>n) //数组元素比N大
            a[i+1] = a[i]; //将该数组元素往右移一个位置
        else
            break;  //否则跳出循环,要插入的位置就是在第i个元素之后
    a[i+1] = n;

    printf("After insert: "); // 显示插入后的值
    for(i=0;i<num+1;i++)
        printf("%d",a[i]);
    printf("\n");
}