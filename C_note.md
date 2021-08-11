#C语言 

## 第一章

###1. 十进制转换二进制
（1）整数转换
除，反着写
（2）小数部分转换
小数点后 乘，正着写

###二、八、十六进制转换
八进制基数 是2的三次幂
十六进制 2的四次幂
1. 二 ---> 八
 <u>001</u> <u>101</u> 

2. 八 ---> 二
	3位看

3. 二 ---> 十六
	4位  <u>1001</u>

###2.  机器数表示形式
1.原码
符号位： 正0		负数1
正负数的原码都相同，符号位变化

2.反码
（正） 与原码相同
（负）求反
10101 -->(反)110101

3.补码
（正）与原码相同
（负）按位求反，末位加1

###3. 二进制位运算
1. 与运算（&）
	有0则0，两同(1)才同(1)
2. 或运算（｜）
	有1则1，两个不同(0)才不同(0)
3. 非运算（～）
	求反
4. 异或运算（^）
	同0异1

题1：将二进制数10110010的高4位求反，低4位不变的操作是
	答：与(F0)16 按位异或




##第二章程序设计基础
###1.编制C步骤
编辑 -->编译-->链接

###2.琐碎知识点
1. C语言是由多个函数构成

2. a --> 97

   A -->65 

   0 --> 48



##第三章基本数据类型、运算符与表达式
###1. C语言数据类型
1. 基本类型
	占字节：
		-1.int     	 2 / 4
		-2.short      2
		-3.long  	 4
		-4.float 	  4
		-5.double   8
		-6.char  	 1

###2. 常量、变量和标识符
1. 标识符
	- 1. 命名规则：
		>由字母、数字、下划线组成
		>第一个字母必须是字母或下划线
		>关键字不能做变量名

2. 常量
	- 用#define定义
	- 注意：
	
	 			1. 定义时，行尾不能有分号
	 			2.define是预处理命令，不是C语言语句
3. 变量
	必须先定义，后使用

###3. 简单数据类型与表示范围
1. 整型数据
	- 1. 整型常量
		八进制--> 0开头
		十六进制--> 0x开头

2. 内存表示
	**正数的数值在内存中用补码的形式存放**
>小例子：
> -65537：对于16位单元来说，先计算补码： 01 0000 0000 0000 0001-->（求反+1）10 1111 1111 1111 实际存放的为1111 1111 1111 1111 为 -1 而不是 -65537
> 同理： 65535 存放是1 
>  -65535 存放是 1

3. 实型数据
  - 1. 指数形式
  	a E n , a为十进制数， n为十进制整数
  - 2. 实行变量分类和定义
      >1. 单精度： float -->%f
      float 小数点后要有六位。
      最多能表示八位数字，如果没到八位，最后追加的数字是随机的

      >2. 双精度：double -->%lf
      

4. 常用转义字符及其含义
- 1. 字符型常量
>1. 转义字符算一个字符
>2. \\ \表示 \  ;     \"表示 "
>3. \ddd : 1~3位八进制数 所代表的字符，d的值可以是 0～7 的任意数字 
>4. \xhh：1～2位十六进制数所代表的字符， h的值可以是 0~f的任何字符
```c
char a = '\' ; //报错
char a = '\x'; //报错
char ch = '\2344'; //错！八进制最多有3个 ；正：'\234'
char ch = '\x23w'; //错，x后只能有1～2位
strlen("\123456"); // 4位数: \123 4 5 6
strlen("\x234"); //报错
```

- 2. 字符串常量
	> 1. 字符常量只能是单个字符，字符串常量可以含一个或多个字符
	> 2. 字符常量占1个字节的内存空间

 	>	3. 字符串常量占的内存字节数等于字符串中字节数+1
 	> +1的这个字节中存放字符'\0' (ASCII 码为0)
 	>	sizef() --->字节数+1
 	>	strlen --->字节数

5. 简单数据类型的表示范围
	- 1. 整型
		int(16) , 2字节 , -32768 ~ 32767
		short ,2字节 , -32768 ~ 32767
		unsigned int(16) , 2字节 , 0~65535
		unsigned short  , 2字节 , 0~65535
		char , 1字节 , -128 ~ 127
		unsigned char , 1字节 , 0 ~ 255

6. 数据简单输出
	- 1. 格式控制字符：
	>%d:有符号整型，int、 short
	%u:无符号
	%f:float
	%c:字符型，char
	%s:字符串

7. 强制类型转换符
	- 1. 自动转换
	（1）无符号 短 --->长
	高位补0
	（2）有符号 短--->长
	高位补第一位的数字
	- 2. 强制转换
	long double 
	⬆️
	double  < ----    float 	（只要有float就会转乘double）
	⬆️
	long
	⬆️
	unsigned int 
	⬆️
	int < ----- char , short
	(从右到左是必须转换的)

###4. 运算符和表达式
1. 算术运算符、算术表达式
	- 1. 算术运算符
		%只能用于整数
		优先级：类型强制转换运算符>算术运算符>赋值运算符
	- 2. 自增自减运算符、负号运算符
		前置运算--->  ++ / -- 变量：先增/减 后运算
		后置运算--->  变量++ / -- ：先运算 后增/减 
>使用方法：
>1:i+++j :相当于(i++)+j 先将i+j赋值给p,然后i增1
>2:i+++--j：相当于(i++)+(--j) 先对j减1，然后算i+j
>3:i+++i++: 相当于(i++)+(i++)想将i+i赋值，再自增2次
>4:++i+(++i):相当于(++i)+(++I)先把i自增2次，然后算i+i

2. 位运算符、位运算表达式
	- 1. 左移运算(<<   乘2)
	高位丢掉，空出的低位用零填补
	- 2. 右移运算（>>   除2）
	空出的高位用原来的符号填补（负用1，正用0）
	- 3. 移位运算符必须都是整型数

###5. 运算符的优先级和结合性
```c
	<从下到上，从低到高>
	>()
	>~;++;--;-(负号);sizeof				从右向左
	>*;/;%
	>+;-(减法)
	><<;>>
	>&
	>^
	>|
	>=;+=;==;/=;*=;%=;^=;&=;|=     从右向左
	>,
```
###6. 琐碎知识点
1. %只能用于int 和char 型变量
2. m是个三位数，从左到右用a , b , c表示		
	-->百：m/100;  十：(m/10)%10;  个：m%10





##第四章 基本输入/输出
###1. 格式化输出printf
1. 整数的输出
	%  [-] / [+] / [.] / [width] / [l] / [h]
	>[-]：表示输出的数据左对齐，默认右对齐
	>[+]：表示加上+号
	>[width]：无符号整数，表示输出整数的最小域宽（占屏幕的多少格）
	>[.] :无符号整数，表示至少要输出多少位，如果整数的位数小于这个数，需要在左边的空位上补0
	>[l]：输出长整型数据
	>[h]：输出短整型数据

```c
    int a = 123;
    long L = 65537;
    printf("a=%6d-----(a=%%d)\n",a);
    //输出：a=   123-----(a=%6d)
    printf("a=%-6d-----(a=%%-6d)\n",a);
    //输出：a=123   -----(a=%-6d)
    printf("a=%-06d-----(a=%%-06d)\n",a);
    //输出：a=123   -----(a=%-06d)
    printf("a=%+06d-----(a=%%+06d)\n",a);
    //输出：a=+00123-----(a=%+06d)
    printf("a=%+6.6d----(a=%%+6.6d)\n",a);
    //输出：a=+000123----(a=%+6.6d)
    printf("a=%-6.5d-----(a=%%-6.5d)\n",a);
    //输出：a=00123 -----(a=%-6.5d)
    printf("a=%6.4d-----(a=%%6.4d)\n",a);
    //输出：a=  0123-----(a=%6.4d)
    prinf("%hd",L);
    //输出：1 ，65537的十六进制：0x0001 0001 ，取低十六位，则为1
```

2. 实数的输出
	
	% [.] / [#] / [width] / [.] / [l|L]
>[#] :必须输出小数点,如果是别的进制，如八进制，需要把前面的0输出来
>[.] :规定输出实数时，小数部分的位数
>[l] :输出double型数据；默认也是输出double数据
>[L] ：输出long double 型数据

3. 字符和字符串的输出
	输出字符： %[-] / [0] / [width]  c
	输出字符串： %[-] / [0] / [width] /[.] s
>[.] :表示只输出字符串的前多少个字符

注意：
>1:如果上一个不正常的输出会影响到下一个表达式的正常输出
>	 如：printf("a = %d, b = %d\n",f,b)  // float f =2; int a =10,b=100;
>	 输出的f用了float但是用了%d，则不会正常输出2.000000
>	 后面的b会被影响输出

###2. 格式化输入scanf
>scanf("格式控制字符串",变量地址);
>&只能作用于变量，不能作用于表达式，因为表达式不对应具体的内存单元，没有地址，只有值

1. 控制符
 \* ：为抑制符，输入的数据不会复制给相应的变量
2. 注意：
	>使用格式控制符%c输入耽搁字符时候，空格和转义字符均作为有效字符被输入
	>scanf("%2d%*2d%3d",&num1,&num2);  // 输入123456789
	>printf("num1=%d,num2=%d\n",num1,num2); //读取12赋值给num1；读取34舍掉；读取567赋值给num2. 输出结果：num1=12 , num2=567

###3. 字符数据的非格式化输入和输出
1. 字符数据的非格式化输入
	- 1. getchar
			该函数没有参数，有一个int型返回值。
			调用该函数的时候，程序就等待用户按键
	- 2. getc
			int getc (FILE \*stream);
			从流文件stream中读取一个字符信息，当流文件时stdin时，和getchar完全相同
	- 3. getche
		int getche(void);
		和getchar相同，唯一差别是：getche直接从键盘获取键值，不等待用户按回车键，只要用户按，则getche直接返回用户按键的ASCII码，同事用户输入的字符回显在屏幕上。
	- 4. getch
		和getche功能相同，唯一差别为：getche回显输入的字符，但是getch不回显输入的字符。

2. 字符数据的非格式化输出
	- 1. putchar
		现实输出的字符
	- 2. putc
		将字符输出到流文件stream，如果流文件为stdout，功能与putchar相同
	- 3. puts
		将字符串string的所有字符输出到屏幕上，输出时将自动回车换行

3. 清除键盘缓冲区
	fflush

###4. 碎小知识点
1. 格式转换符中，除了X、E、G以外，其他均为小写字符。
2. 算法的描述方法：自然语言描述、伪代码、流程图、N-S图




##第五章选择结构程序设计
###1. 关系运算符、逻辑运算符、条件运算符
1. 关系运算符，关系表达式
	
	>(优先级) 算术运算符>移位运算符>关系运算符>&、 |、 ^>赋值运算符
	
2. 逻辑运算符，逻辑表达式

   | 逻辑运算符 | 含义                         | 结合性 |
   | ---------- | ---------------------------- | ------ |
   | !          | 单目运算符，逻辑非，表示相反 | 右结合 |
   | &&         | 双目运算符，逻辑与，表示并且 | 左     |
   | \|\|       | 双目运算符，逻辑或，表示或者 | 左     |

   ||：两边式子只要有一个式子为真，整个逻辑表达式的值就是真（即为1），否则为假（0）。
   &&：两边都是真，才为真，有一个不真则是假。
	>**逻辑与，左边为0，则右边的不进行计算！！**
	>例子:
		```c
		int a = 1, b = 2, c = 3, d = 4, m = 2, n = 2; 
    	//执行 (m=a>b)&&(n=c>d)后的N的值为：
   	  //左边的M 为0；则后面的 n=c>d 不进行计算，n的值为2.
		```
	
   ！：单目运算符，当右边的式子为真，整个为假；否则为真。

   >(优先级) !、~、++、--、sizeof > 算术运算符 > 移位 > 关系 > &、|、^ > &&、|| > 赋值

3. 条件运算符和条件表达式
	条件运算符为？和：，这是一个三目运算符
	**条件表达式的一般形式为：表达式1 ? 表达式2 : 表达式3**
	
	<规则>：如果表达式1的值为真，则表达式2的值作为条件表达式的值，否则以表达式3的值作为整个条件表达式的值。
	使用条件表达式时，还应注意以下几点：
	
	>1.条件运算符可嵌套，例如：x > 0? 1:(x < 0 ? -1 : 0) 表达式的值是：如果X是正数，则是1，如果是负数，则为-1，如果为0，则为0.
	>2.条件运算符 ? 和 : 是一堆运算符，不能分开单独使用。
	>![](picture/5_1.png)


###2. 选择结构的程序设计
####1. IF语句
1. if 语句
表达式：
```c
if(表达式)
  语句;
```
2. if-else 语句
表达式：
```c
if(表达式)
 	语句1;
else
  语句2;
```

3. if-else-if 语句
```c
if(表达式1)    语句1;
else if(表达式2)  语句2;
else if(表达式3)  语句3;
else  语句N;
```
4. 注意
	- 注意关键词之后均为表达式，注意 真，非
	- C语言规定，在缺少{ }时，else 总是和它上面离他最近的为配对的if 配对

#### 2.switch语句
1. 介绍
格式：
```c
//形式：
switch(表达式){
case 常量表达式 C1: 语句组1;
								break;
case 常量表达式 C2: 语句组2;
								break;
default: 语句组;
			break;
			}
```


2. 执行过程为：

- 当switch后面“表达式”的值，与某个case后面的“常量表达式”的值相同时，就执行case后面的语句组；当执行到break语句时，跳出switch语句，转向执行switch语句的下一条。
- 如果没有任何一个case后面的“常量表达式”的值与“表达式”的值匹配，则执行default后面的语句，在执行switch语句的下一条

注意：
>1. switch后面的表达式，可以是<u>int 、 char 和枚举类</u>中的一种
>
>2. case后面的表示的值需要不相同。
>
>3. case后面必须是常量表达式，不能含变量
>	如果后面的是常量，可以考虑用if-else-if
>	
>4. 多个case子句，可以使用同一个语句，最后break。
>
> ```c
>   case 1:
>   case 2:
>   case 3: b+=2;break;
> ```
>
>5. switch语句可以嵌套
>
> ```c
>   void main(){
>   int x=1,y=0,a=0,b=0;
>   switch(x){
>   	case 1: switch(y){
>   					case 0: a++; break;
>   					case 1: b++; break;
>   					}
>   	case 2: a++; b++; break;
>   	case 3: a++; b++; break;
>   }
>   printf("%d ,%d",a,b);
>   }
> ```
>6. 几个小案例，具体看文件：<chapter5_book.c>

#### 注意事项

1.表达式

>1. 对于表达式(k)?(i++):(i--)来说，其中的表达式k等价于 <u>k!=0</u>
>解释：表达式可以理解为：k为真返回i++ ; k为假返回i--
>C语言中非0表示真，0表示假，k为真用k!=0表示

## 第六章 循环结构
### 1. 循环结构的程序设计
####1. while 语句

```c
  while (表达式) //表达式中可以是任意类型的表达式
  语句;	 //循环体
```
执行过程：
>首先判断表达式的值是否是真（非0），如果是真，则执行循环体内的语句，然后再判断表达式是否为真，如果是真，在执行循环体内的语句，如此往复，直到表达式为假（0）为止。

注意：
>1. 如果while后面的表达式一开始就是假，循环体讲一次也不执行
>2. 退出循环：1）：表达式为假（0） 
>						          2）：循环体中遇到break，return，goto 语句
>3. 要注意循环变量的增值，如果不增，很容易变成死循环


####2. do- while语句
1. 一般形式
```c
do
	语句;  //循环体
while(表达式); //循环条件
```
执行过程：
>首先执行循环体内的语句，然后才判断表达式的值是否为真（非0），如果为真，则再执行循环体内的语句，如此循环往复，知道表达式的值为假（0）为止。

注意：
>1. do-while语句和while语句的区别的在于do-while是先执行后判断，因此<u>do-while至少要执行一次循环体</u>。而while是先判断后执行，如果条件不满足，则循环体语句一次也不执行。
>2. 如果 do-while 后的表达式的值一开始就是假，循环体还是要执行一次
>3. <u>do-while语句的表达式后面必须加分号。</u>



####3. for 语句
1. 一般形式
```c
for(表达式1;表达式2;表达式3)  //循环条件
	语句;  //循环体
```
要求：
>表达式1:一般为赋值表达式，给控制变量赋初值。
>表达式2：关系表达式或逻辑表达式，循环控制条件。
>表达式3:一般为赋值表达式，给控制变量增量或减量

执行过程：
>首先，求表达式1的值，然后判断表达式2是否为真（非0），如果为真，则执行循环体语句，然后求表达式3的值。接下来再判断表达式2是否为真，如果为真，继续执行循环体语句以及求表达式3的值，直到表达式2为假为止。

####4. break 与 continue 语句
1. break语句
	break语句的作用是在循环体中测试到应立即结束循环时，使控制立即跳出循环结构，转而执行循环语句后的第一条语句。

	注意：
	>1. break只能用于while、do-while、for语句构成的循环结构中和switch选择结构中。
	>2. break语句只能终止并跳出包含它的最近一层的循环体。
	>3. 在嵌套循环的情况下，如果想让break语句跳出最外层的循环体，需要设置标志变量tag，然后在每层循环后加上一条语句: if(tag) break; 其值为1表示跳出循环体，为0则不跳出。

2. continue语句
**continue语句和break语句不同，当在循环体中遇到continue语句时，程序将跳过continue语句后面尚未执行的语句，开始下一次循环，即只结束本次循环的执行，并不终止整个循环的执行。**

注意：
>1. continue语句只能用于while、do-while、for语句构成的循环结构中。
>2. 在嵌套循环中，continue语句只对包含它的最内存的循环体语句起作用。

#### 5. go to 语句
goto语句也称为无条件转移语句。
```c
	goto 语句标号;
	
	语句标号;
```

应用：
>1. goto 语句可与条件语句配合使用来实现条件转移，构成循环
>	```c
>		int tag = 0;
>		for(...)
>	{
>		while(...)
>															
> 	{
> 	  ..
> 	   if(..) goto stop;
> 	..
> 	}
> 	 ..
> 	}	
> 		stop:for循环后第一条语句
> 	```
>	2. 在嵌套循环的条件下，利用goto语句可以直接从最内层的循环体跳出最外层的循环体。

#### 6. exit()函数

`void exit(int status);   头文件<stdlib.h>`
exit( )作用时：终止整个程序的执行，强制返回操作系统

###2. 循环结构类型的选择和转换
1. 循环结构类型选择
>1. 如果循环次数在循环体之前就已经确定，一般使用for 循环；如果循环次数时由循环体的执行情况确定的，一般用while循环或者do-while循环。
>当循环体至少执行一次时，使用do-while循环，反之，如果循环体可能一次也不执行，使用while循环。

2. 循环结构类型之间的相互转换


###3. 循环结构程序设计
1. 验证哥德巴赫猜想：任意充分大的偶数，都可以用两个素数之和表示。
```c
/*
思路：输入一个偶数N，将它分为p和q，使= p + q;
让p从2开始，每次增加1，而令q = n - p;如果 q and p是素数，则正为所求，否则令p = p + q再尝试。

要点：判断是否是素数，我们可以领两个表示量：flagp,falgq,初始值为0；若p是素数，令flagp =1,若q是素数，令flagq=1

*/

	#include<stdio.h>
	#include<stdlib.h>
	#include<math.h>
	
	void prime_number(){
		int i, n, p, q, flagp, glagq;
		printf("please input n:");
		scanf("%d",&n); 
		if(n<4 ||n%2!=0) //如果这个数不是偶数
		{
			printf("input data error!\n");
			exit(-1); //程序结束
		}
		
		p=1;
		do{
			p++;
			q = n - p;
			//Determine whether p is prime
			flagp = 1;
			for(i=2;i<=(int) sqrt(p);i++){
			if(p % 1 ==0){
				flagp=0;
				break;
			}
			}
			//Determine whether p is prime
			flagq = 1;
			for(i =2; i<=(int)sqrt(q);i++){
				if(q % i ==0){
					flagq = 0;
					break;
				}
			}
		}while(flagq * flagq ==0); //p q 中有一个不为素数时，继续循环
		printf("%d = %d + %d\n",n,q,p);
	}
```

2. 打印大小可变的菱形图案
```c
	/*
							*
						* * *
					* * * * *
				* * * * * * *
				  * * * * *
				    * * *
              *
关键：1. 确定每行*的个数：当行数i(假设最上面的一行为第一行)<=(size+1)/2时，该行的个数为 n = 2*i-1 ；
否则，n = 2*(size-i+1)-1；
	*/
#include<stdio.h>
#include<stdlib.h>

void rhombus()
{
		int i, j, k, m, n, size;
    pritnf("input size:"); 
    scanf("%d",&size);
    if(size <=0 || size %2 ==0)
    {
    	printf("error!\n");
    	exit(-1);
    }
    for(i = 1;i<=size ;i++) //控制行数
    {
    	n = (i<=(size+1)/2)?i:size-i+1; //每行中"*"号的个数
    	n=2*n-1;
    	m=(size-n)/2+15; //每行打印 * 之前应打印的空格数
    	for(k=1;k>=m;k++)  //打印每行前面的空格
    		printf(" ");
    	for(j =1;j<=n;j++) //打印每行的 *
    		printf("*");
    	printf("\n");  //打印一行后，回车换行
    }
}

```

3. 统计两个整数之间的所有整数中0、1、2、3、4、5、6、7、8、9数码的个数
```c
/*
	问题的关键在于要计算某整数中包含的各个数码的个数，必须对该整数进行分解，求得包含的各个数码，其方法可以通过每次除以10取余数得到，然后对商进行同样的处理，直到商为0时为止。
*/
#include<stdio.h>
#include<stdlib.h>

void statistics(){
	int num1, num2;
	int n,s,r;
	int count0=0,count1=0,count2=0,count3=0,count4=0,count5=0,count6=0,count7=0,count8=0,count9=0;
	printf("input two intrger:");
	scanf("%d%d",&num1,&num2);
	if(num1<0||num2<||num1>num2){
		printf("input error!\n");
		exit(-1);
	}
	for(n=num1;n<num2;n++){
		s = n;
		do{
			r =s % 10;
			switch(r){
					case 0:count0++;break;
					case 1:count1++;break;
					case 2:count2++;break;
					case 3:count3++;break;
					case 4:count4++;break;
					case 5:count5++;break;
					case 6:count6++;break;
					case 7:count7++;break;
					case 8:count8++;break;
					case 9:count9++;break;
			}
			s = s / 10;
		}while(s != 0);
	}
	printf("0 == %-4d  1 -- %-4d 2 -- %-4d 3-- %-4d\n",count0,count1,count2,count3);
	printf("4 == %-4d  5 -- %-4d 6 -- %-4d 7-- %-4d\n",count4,count5,count6,count7);
	printf("8 -- %-4d 9 -- %-4d\n",count8,count9)
}

```

###4. 注意事项
1. 需要在do-while循环语句的后面一定要加分号
2. while循环是先判断后执行，而do-while循环是先执行后判断。
while循环中循环一次可能不执行循环体，而do-while语句是要执行一次循环体。
3. break语句在循环体中的作用是：跳出循环结构，转而执行循环语句后的第一条语句
4. continue语句在循环体中的作用是：结束本次循环，循环执行下一次循环
5. 