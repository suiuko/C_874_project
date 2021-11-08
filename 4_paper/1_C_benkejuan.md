# 第一章 概论

```c
/*
输入不大于4个字符的字符数组, 输出不超过8个字符的回文字符数组
*/
#inculde<stdio.h>

int fun(char *a){
	int i;
	for(i=0;a[i];++i)
	{
		putchar(a[i]);
	}
	--i;
	while(i>=0)
	{
		putchar(a[i]);
		--i;
	}
	return 0;
}

int main(){
	char a[100];
	scanf("%s",a);
	fun(a);
	return 0;
}
```


# 第二章 链表
