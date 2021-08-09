#include <stdio.h>
/*========1.=========
公司员工保底薪水500，根据工程利润profit的利润提成关系来计算员工当月薪水
小于1000---没有提成
1000-2000 ---- 提成10%
2000-5000 ---- 提成15%
5000-10000 --- 提成20%
大于10000 ----- 提成25%
*/

// 方法一：if else
void profit_salary1(){
    long profit;  
    float ratio; //提成比率
    float salary = 500; //底薪
    printf("Input profit:\n");
    scanf("ld",&profit);
    //计算比率
    if(profit <= 1000)
        ratio = 0;
    if(1000 < profit && profit <= 2000)
        ratio =(float) 0.10;
    if(2000 < profit && profit<=5000)
        ratio =(float) 0.15;
    if(5000 < profit && profit <=10000)
        ratio =(float) 0.20;
    if(10000<profit)
        ratio =(float) 0.25;
    
    salary += profit * ratio;
    pritnf("salary = %.2f\n",salary);
}

//方法二： 用switch
void profit_salary2(){
    long profit2; 
    int grade; 
    float ratio2; //提成比率
    float salary = 500; //底薪
    printf("Input profit:\n");
    scanf("ld",&profit2);
    //将利润-1 、再整除1000，转化为switch语句中的case标号
    grade = (profit2 - 1)/1000;
    switch (grade)
    {
    case 0: ratio2 = 0; break;  //profit < 1000
    case 1: ratio2 = (float)0.10; break; //1000<profit<=2000
    case 2: 
    case 3: 
    case 4: ratio2 =(float) 0.15; break; 
    case 5: 
    case 6: 
    case 7: 
    case 8: 
    case 9: ratio2 =(float)0.20;break; //5000<profit<=10000
    default: ratio2 =(float)0.25;
        break;
    salary +=profit2 * ratio2;
    printf("salary =%.2f\n",salary);
    }
}


/*
========2.==========
从键盘上输入年份year，判断是否是闰年，
闰年条件：能被4整除、不能被100整除，或者能被400整除
*/
void leap_year(){
    int year, leap =0; //leap =0：预置为非闰年
    printf("Please input the year:\n");
    scanf("%d",&year);
    if(year %4 ==0)
        if(year %100 !=0)
        leap = 1;
    if(year %400 ==0)
        leap =1;
    if(leap==1)
        printf("%d is a leap year\n",year);
    else
        printf("%d isn't a leap year\n",year);
}
//可以优化为：if((year % 4 ==0 && year % 100 !=0)||(year % 400 ==0))
//                leap=1; 


/*
==========3.===========
将百分制成绩转换为五分制成绩
100-90 A； 90-80 B； 80-70 C； 70-60 D ；小于60位E
*/
void score(){
    int score,mark;
    scanf("%d",&score);
    mark = score /10;
    switch(mark){
        default:printf("%d ---E",score); break;
        case 10:
        case 9 :printf("%d ---A",score);break; 
        case 8 :printf("%d ---B",score);break; 
        case 7 :printf("%d ---C",score);break; 
        case 6 :printf("%d ---D",score);break; 
    }
}
