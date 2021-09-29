//线性表应用题

/*
======1.=======
从顺序表中删除最小值的元素,并返回被删元素的值, 空出的位置用
最后一个元素填补,如果顺序表为空,则显示错误的信息并退出

思想: 搜索整个顺序表,查找到最小值元素,并记住其位置,搜索结束后用最后一个填空

*/
bool Del_Min(sqList &L, ELemType &value)
{
    if(L.length == 0)
        return false;  //表空,返回
    value = L.data[0];  
    int pos = 0; //assume that 0 element is smallest
    for(int i =1;i<L.length;i++)  //find which is min
        if(L.data[i]< value)  //value remember current min
        {
            vlaue = L.data[i];
            pos = i;
        }
    L.data[pos] L.data[L.length-1]; // the empty space is filled by the last element.
    L.length--;
    return true;  //value 是最小值.
}

/*
======2.========
设计最后一个算法, 将顺序表L的所有元素逆置,要求算法的空间复杂度为1

思想:扫描顺序表L 前面半部分元素,对于元素L.data[i] (0<=i<L.length/2)
将其与后半部分的对应元素L.data[L.length-i-1]进行交换
*/
void Reverse(Sqlist &L)
{
    ElemType temp;   //辅助变量
    for(i=0;i<L.length.2;i++)
    {
        temp = L.data[i]; 
        L.data[i] = L.data[L.length-i-1];
        L.data[L.length-i-1] = tmep;
    }
}


/*
======3.========
对长度为N的顺序表L, 编写一个时间复杂度为N,空间复杂度1,
该算法删除线性表中所有值为X的数据元素.
*/

/*用L记录顺序表L中等于X的元素个数,边扫描L边统计K,
将不等于X的元素向前移动K个位置,最后修改L的长度
*/
void del_x_1(Sqlist &L,Elemtype x)
{
    int k=0, i =0;
    while(i<L.length){
        if(L.data[i]==x)
            k++;
        else
            L.data[i-k]= L.data[i]; //当前元素前移K个位置
        i++;
    }
    L.length = L.length-k; 
}


/*
======4.=======
从有序顺序表中删除其值在定值S和T之间的所有元素,若S或T不合理或顺序表为空,退出

思想: 现寻找大于等于S的第一个元素,寻找大于T,要将这一段元素删除,只需要将后面的元素前移.
*/
bool Del_ S_ t2 (SqList &L, ElemType s, ElemType t) 1
{
//删除有序顺序表L中值在给定值s与t之间的所有元素
    int i,j;
    if(s>=t||L.length==0)
        return false;
    for (i=0; i<L.length&&L.data[i]<s;i++);//寻找值大于等于s的第一个元素
    if (i>=L.length)
        return false; //所有元素值均小于s,返回
    for (j=i;j<L.length && L.data[j]<=t;j++); 
    for(;j<L.length; i++,j++)
        L.data [i]=L.data[j]; //前移，填补被删元素位置
    L.length=i;
    return true;
}


/*
=======5.========
从顺序表中删除其值在定值S和T之间的所有元素,若S或T不合理或顺序表为空,退出

思想: 从前向后扫描顺序表L,  用K记录下元素值在S到T之间的元素个数,对于当前扫描的元素,
若其值不在S到T之间, 则前移K个位置, 否则就执行K++
*/
bool Del_s_t(sqList &L<=,ElemType s, ElemType t)
{
    int i,k=0;
    if(L.length==0||s>=t)
        return false;
    for(i=0;i<L.length;i++){
        if(L.data[i]>=s&&L.data[i]<=t)
            k++;
        else
        L.data[i-k]=L.data[i];//当前元素前移K个位置
    }
     L.length -=k;
     return true;  

}

/*
======6.=======
从有序顺序表中删除所有其值重读的元素, 使表中素有元素的值均不同

思想: 初始时将第一个元素视为非重复的有序表, 之后依次判断后面的元素是否与前面的非重复
有序表的最后一个元素相同, 若相同,则继续向后判断,若不同,则插入前面的非重复有序表的最后,
直到判断到表尾位置.
*/
bool Delete_Same(SeqList& L )
{
    if(L.length == 0)
        return false;
    int i,j;   //i存储第一个不相同的元素, J为工作指针.
    for(i=0;j=1;j<L.length;j++)
        if(L.data[i]!=L.data[j])  //查找下一个与上一个元素值不同的元素
            L.data[++i]=L.data[j];//找到后,将元素前移
    L.length = i+1;
    return true;
}


/*
========7.=======
将两个有序的顺序表合并为一个新的有序顺序表, 并由函数返回结果顺序表.

思想:按2顺序不断取下两个顺序表表头较小的节点,存入新的顺序表中,然后看那个表还有剩余
将剩下的部分加到新的顺序表后面
*/
bool Merge(SeqList A, SeqList B, SeqList &c)
{
    if(A.length+B.length>C.maxSize)
        return false;
    int i=0, j=0, k=0;
    while(i<A.length&&j<B.length){
        if(A.data[i]<=B.data[j])
            C.data[k++]=A.data[i++];
        else
            C.data[k++]=B.data[j++];
    }
    while(i<A.length)
        C.data[k++] = A.data[i++];
    while(j<B.length)
        C.data[k++] = B.data[j++];
    return true;
}


/*
===========8.============
已知在一个一维数组A[m+n]中一次存放两个线性表(a1,...)和(b1....) 试编写一个函数,将数组中
两个顺序表的位置互换

思想:将A中的全部元素逆置, 然后将前N个元素和后M个元素分别逆置
*/
typedef int DataType;
void Reverse(DataType A[],int left, int right, int arraySize) //逆转
{
    if(left>=right||right>=arraySize)
        return;
    int mid=(left+right)/2
    for(int i=0;i<mid-left;i++)
        DataType temp =A[left+i];
        A[left+i] = A[right-i];
        A[right-i] = temp;
}

void Exchange(DataType A[],int m,int n,int arragSize){
    //数组A[M+N]中,从0到M-1存放顺序表A,从M到M+N-1存放顺序表B,
    Reverse(A,0,m+n-1,arratSize);
    Reverse(A,0,n-1,arratSize);
    Reverse(A,n,m+n-1,arratSize);
}


/*
=========9.=========
线性表(A1,...)中的元素递增有序且按顺序存储于计算机内,要求用最少的时间在表中查找数值为X的元素
若找到,则将其后继元素位置互相交换, 找不到则将其插入表中并使表中元素仍递增有序.

思想:最少的时间查找X 就是折半查找
*/
void 