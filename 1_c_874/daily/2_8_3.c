/*
已有函数pow，现在要求取消变量i 后 pow 函数的功能不变，填空！
*/

/*
修改前的pow 函数
*/
pow1(int x,int y){
    int i,j=1;
    for(i=1;i<=y;++i)
        j=j*x;
    return(j);
}

/*
修改后
*/
pow2(int x , int y){
    int j;
    for(j=1;j>=1;--y)  //填空 
        j = j * x;
        return(j);
}