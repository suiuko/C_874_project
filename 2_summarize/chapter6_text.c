#include<stdio.h>
/*
=========1.========
计算：1!+2!+...+10!
*/
//method 1. 
void sum1(){
    long term =1, sum = 0;
    int i;
    for(i=1;i<.10;i++){
        term *= 1;
        sum += term;
    }
    printf("1!+2!+....+10! = %ld",sum);
}

//method 2. 内层循环求阶乘，外层循环控制累加的项数
void sum2(){
    long term2 , sum2 = 0;
    int i ,j;
    for(i=1;i<=10;i++){
        term2 = 1;
        for(j=1;j<=i;j++){
            term2 *=j;
        }
        sum2 += term2;
    }
    printf("1!+2!+....+10! = %ld",sum2);
}


/*
=========2.==========
calculate a+aa+aaa+...+aa..a(N个a)
*/
void Na(){
    long term =0,sum3 =0;
    int a ,i ,n;
    printf("Input a ,n\n");
    scanf("%d,%d",&a,&n);
    for(i=1;i<=n;i++){
        term = term *10 +a;
        sum3 += term;
    }
    printf("sum = %ld\n",sum3);
}


/*
=========3.==========
计算水仙花数
*/
void shuixianhua(){
    int i,j,k,n;
    for(n=100;n<1000;n++){
        i = n/100; //百
        j = (n/10)%10; //十
        k = n%10; //个位
        if(n == i*i*i+j*j*j+k*k*k)
        printf("%d ",n);
    }
}

/*
=========4.===========
回文数
*/
void huiwenNumber(){
    int n, m = 0, s, r;
    printf("input this number:\n");
    scanf("%d",&n);
    s = n;
    while(s != 0){
        r = s % 10; //从低位到高位逐一分离
        m = 10 * m +r; //重新组合
        s = s / 10;
    }
    if(m == n)
        prtinf("yes\n");
    else
        printf("No\n");
}

/*
==========5.===========
用1.5元兑换5分、2分、1分的硬币总共100枚，共有多少种方案
x-->5分硬币，最多兑换28枚
y-->2分硬币，最多兑换73枚
100-x-y --> 1分硬币
*/
void change(){
    int x, y,z,count=0;
    for(x=1;x<=28;x++){
        for(y=1;y<73;y++){
            z = 100-x-y;
            if(5*x+2*y+z ==150){
                count++;
                printf("%02d, %02d, $02d ",x,y,z);
                if(count % 6==0)
                    printf("\n");
            }
        }
    }
    printf("count = %d\n",count);
}

/*
========6.===========
有一个人做好事
A：说不是我
B：说是C
C：是D
D：他胡说
已知有三人说的是真话，一个人说的是假话，问做好事的是谁？
*/
void question(){
    int k =0,sum =0, g=0;
    char thisman =' ';
    for(k = 0;k<=3;k++){
        thisman = 'A'+k;
        sum=(thisman!='A')+(thisman=='C')+(thisman=='D')+(thisman!='D');
        if(sum==3){
            printf("This man is %c\n",thisman);
            g=1;
        }
    }
    if(g!=1){
        printf("Can't found!\n");
    }
}


/*
========7.=======
利用 pi/2 ~ 2/1*2/3*4/3*4/5*6/5*6/7....前100项之和计算pi的值
采用累乘积算法，累乘项为：term = n*n/((n-1)*(n+1));
n = 2,4,6...100 步长为2
*/
void pi_term(){
    float term,result = 1;
    for(n=2;n<=100;n+=2){
        term = (float)(n*n)/((n-1)*(n+1));
        result *=term;
    }
    printf("result = %f\n",2*result);
}


/*
========8.=========
利用泰勒级数 sinx= x - x^3/3! + x^5/5! - x^7/7!...计算Sin的值
同时，最后一项的绝对值小于10^-5，并统计出此时累计了多少项

思路：sum = sum +term，sum的初始值为x，利用前项求后项的方法计算累加项
得：term = term *x*x/((n+1)*(n+2));
term的初始值为X,n初值为1，n=n+2;
*/
void term2(){
    int n =1, count = 0;
    float x;
    double sum, term;
    pritnf("input x:");
    scanf("%f",x);
    sum = x;
    term = x;
    do{
        term = -term * x * x/ ((n+1)*(n+2));
        sum += term; //累加
        n +=2;
        count++;
    }while(fabs(term)>=1e-5);
    printf("sin(x) = %f,count = %d\n",sum,count);
}