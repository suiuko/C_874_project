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
void SearchExchangeInsert(ELemType A[],ElemType x){
    int low = 0, high= n-1, mid;
    while(low<=high){
        mid=(low+high)/2; 
        if(A[mid]==x) 
            break;
        else if(A[mid]<x)
            low = mid +1; 
        else 
            high = mid -1;
    } //下面两个if只会执行一个
    if(A[mid] == x&&mid!=n-1){
        //若最后一个元素与X相等, 则不存在与其后继交换的操作
        t =A[mid];
        A[mid] = A[mid+1];
        A[mid+1] =t;
    }
    if(low>high){
        //查找失败,插入元素X
        for(int i=n-1;i>high;i--) //后移元素
            A[i+1] = x; 
    }
}

/*
=========10.========
给定一个含N个整数的数组,请设计一个在时间上尽可能高效的算法,找出数组中未出现的最小正整数
例如:{-5,3,2,3}中未出现的最小正整数为1

1)要求在时间上尽可能高效，因此采用空间换时间的办法。分配一个用于标记的数组B[n],
用来记录A中是否出现了1~n中的正整数，B[0]对应正整数1, B[n-1]对应正整数n,
初始化B中全部为0。由于A中含有n个整数，因此可能返回的值是1~n+1，当A中n
个数恰好为1~n时返回n+1.当数组A中出现了小于等于0或大于n的值时,会导致1~
n中出现空余位置，返回结果必然在1~n中，因此对于A中出现了小于等于0或大于n
的值，可以不采取任何操作。
经过以上分析可以得出算法流程:从A[0]开始遍历A,若0<A[i]<=n.则令B[A[i]-1]=1;
否则不做操作。对A遍历结束后，开始遍历数组B，若能查找到第一一个满足B[i]==0的下标i，
返回i+1即为结果，此时说明A中未出现的最小正整数在1~n之间。若Bii]全部不为0，返
回i+1 (跳出循环时i=n，i+1 等于n+1)，此时说明A中未出现的最小正整数是n+1。
*/

int findMissMin(int A[], int n)
{
    int i, *B;
    B=(int *)malloc(sizeof(int)*n);// 分配空间
    memset(B,0,sizeof(int)*n); //赋初值为0
    for(i =0;i<n;i++)
        if(A[i]>0&&A[i]<=n) //若A[i]的值介于1~n,则标记数组B
            B[A[i]-1]=1;
    for(i=0;i<n;i++)
        if(B[i]==0)
            break;
    return i+1; //返回
}


