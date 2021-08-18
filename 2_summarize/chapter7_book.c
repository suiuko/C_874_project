/*
=====1.======
输入多个城市的名字，按升序排列输出

*/
#include<stdio.h>
#include<string.h>
#define CITYNUM 10
void city(){
    int i, j, k, num;
    cahr city[CITYNUM][20];
    cahr str[80];
    num=0; //实际输入的城市数初始化为0
    for(i=o;i<CITYNUM;i++){//输入城市名字符串（长度不能超过19）
        printf("input the name of the %dth city:\n",i+1);
        gets(str);
        if(str[0] == 0) //输入空串，表示输入结束
            break;
        if(strlen(str)>19) //城市名字字符串大于19，重新输入
        {
            i--;
            continue;
        }
        strcpy(city[i],str); // 将输入的城市名保存到字符串数组中
        num++;
    } 
    for(i=0;i<num-1;i++) //选择排序（升序）
    {
        k=i; //k为当前城市名最小的字符串数组的下标，初始假设为i;
        for(j=i+1;j<num;j++) //查找比city[k]小的字符串的下标放入k中
            if(strimp(city[k],city[j]>0))
                k=j;
            if(k!=i){ //将最小城市名的字符串city[k] 与city[i]交换
                strcpy(str,city[i]);
                strcpy(city[i],city[k]);
                strcpy(city[k],str);
            }
    }

    for(i=0;i<num;i++){  //show
        printf("%s ",city[i]);
    }
    printf("\n");
}

/*
=====2.求解幻方问题========
N阶幻方就是把1～n^2排成 N*N的方阵，使得每行中的各元素之和，每列中个元素之和
以及每条对接线上的元素之和都是同一个数字S

*/

#include<stdio.h>
#define MAX 15

void huanfang(){
    int m, mm, i, j, k, ni, nj;
    int magic[MAX][MAX]= {0};

    printf("ENTER THE NUMBER YOU WANTED:\n");
    scanf("%d",&m);
    if((m<=0)||(m%2 == 0)) {
        printf("error\n");
        return;
    }
    mm = n * m;
    i=0; //第一个值的位置
    j=m/2;
    for(k=1;k<=mm;k++){
        magic[i][j] = k;
        //求右上方方格的坐标
        if(i==0) //最上一行
            ni=m-1;//下一个位置在最下一行
        else 
            ni=i-1;
        if(j==m-1) //最右端
            nj=0; // 下一个位置在最左端
        else
            nj=j+1;
        //判断右上方方格是否已有效
        if(magic[ni][nj] == 0) //右上方无值
        {
            i = ni;
            j = nj;
        }
        else //右上方方格已填上数
            i++;
    }

    for(i=0;i<m;i++)// show
    {
        for(j=0;j<m;j++)
            printf("%d",magic[i][j]);
        printf("\n");
    }
}