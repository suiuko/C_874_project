/*
求矩阵X的上三角元素之积，其中矩阵X的行、列数和元素值均由键盘输入。【填空题】
*/
#include <stdio.h>
#define M 10

int main(){
    int x[M][M];
    int n,i,j;
    long s =1;
    printf("Enter a integer(<=10):\n");
    scanf("%d",&n);
    printf("Enter %d data on each line for the array x\n",n);
    for(i=0;i<n;i++) // gap filling 1
        for(j=0;j<n;j++)
            scanf("%d",&x[i][j]);
    for(i=0;i<n;i++){  
        for(j=i;j<n;j++) // gap filling 2
            s *= x[i][j]; // gap filling 3
        printf("%ld\n",s);
    }
}