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

思想:
*/


/*
=======5.========
从顺序表中删除其值在定值S和T之间的所有元素,若S或T不合理或顺序表为空,退出
*/


/*
======6.=======
*/