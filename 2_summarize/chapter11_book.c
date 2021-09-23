/*
======1.本章小结 和 常见错误列举=======

1. 常见错误
(1)结构体、联合体、枚举类型少了右花括号的分号.
(2)把复杂数据类型名当作变量名.
下面做法是错的: 
*/
struct Date
{
    int year,month,day;
};
Date.year = 2004;
Date.month = 10;
Date.day = 18;
// 上面的赋值是错的, 以下是对的
struct Date d;
d.year = 2004;
d.month=10;
d.day=18;

/*
3. 定义复杂数据类型是 为 成员变量赋初值
*/
struct Date
{
    int year;
    int month = 10;  // 错误, 定义数据类型时,不能赋初值
    int day;
}

/*
结构体中含有自身类型的成员.
*/
struct Date 
{
    int year, month, day;
    struct Date nextdate; // 错误, Date类型不能包含 Date的成员
};
//但结构体中可以包含自身类型的指针
struct Date
{
    int year, month, day;
    struct Date *nextdate; 
};

/*
4.把一种类型的结构体变量赋值给另一中类型的结构体变量

*/
