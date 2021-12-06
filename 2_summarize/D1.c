//1. 将循序表L的所有元素逆置

//思想:扫描循序表L的前半部分元素,对于元素L.data[i] (0<=i.L.length/2),将其雨后半部分的对应元素L.data[L.length-i-1]进行交换
void Reverse(Sqlist &L){
    Elemtype temp;
    for(i=0;i<L.length/2;i++){
        temp=L.data[i];
        L.data[i]=L.data[L.length-i-1];
        L.data[L.length-i-1] = temp;
    }
}

//2. 从有序顺序表中删除所有值重复的元素,使表中所有元素的值均不同.
/*
思想: 有序表中相同的元素一定在连续的位置上,用类似于直接插入排序的思想,
初始将第一个元素视为非重复的有序表,之后一次判断后面的元素是否和前面的非重复表的最后一个元素相同
如果相同就继续向后判断,如果不同,则插入前面的非重复顺序表的最后.直到判断到表尾为止.
*/

bool Delete_Same(SeqList &L){
    if(L,length ==0)
        return false;
    int i,j;
    for(i=0;j=1;j<L.length;j++)
        if(L.data[i]!L.data[j]) //查找下一个与上个元素不同的元素
            L.data[++i]=L.data[j]; //找到后,元素前移动
    L.length = i+1;
    return true;
}

//3.将两个有序表 合成一个新的有序表
/*
思想: 按顺序不断取下两个顺序表头较小的结点存入新的顺序表中,然后看哪个表有剩余,将剩下的部分加到新的循序表后面
*/

bool Merge(Seqlist A,Seqlist B,Seqlist &c){
    if(A.length+B.length>C.maxSize)
        return false;
    int i=0;j=0;k=0;
    while(i<A.length&&j<B.length){
        //循环 ,两两比较, 小的存入结果表
        if(A.data[i]<=B.data[j])
            C.data[k++]=A.data[i++];
        else   
            C.data[k++]=B.data[j++];
    }
    while(i<A.length)
        C.data[K++] = A.data[i++];
    while(j<B.length)
        C.data[k++]=B.data[j++];
    C.length = k;
    return true;
}
