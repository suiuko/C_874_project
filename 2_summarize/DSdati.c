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


//4.设L为带头结点的单链表,编写算法实现从尾到头反向输出每个节点的值
//用栈和递归的思想来实现.
void R_print(LinkList L){
    if(l->next!=NULL){
        R_print(L->next);//递归
    }//if
    if(L!=NULL) print(L->data); //输出函数
} 
    void R_Ignore_head(LInkList L){
        if(L!=NULL) R_print(L->next);
    }


//5.从单链表中删除一个最小的值结点
//用pre和p ,minp,minpre来做
LinkList Delete_min(LinkList &L){
    LNode *pre=L,*p=pre->next; //p为工作指针,pre为其前驱
    LNode *minpre=pre,*minp=p; //保存最小值结点其前驱
    while(p!=NULL){
        if(p->data<minp->data){
            minp=p; //找到比之前还要小的结点
            minpre=pre;
        }
        pre=p; //继续扫描下一个结点
        p=p->next;
    }
    minpre->next=minp->next;// 删除最小值结点
    free(minp);
    return L;
}
    
//6.将带头结点的单链表就地逆置
//第一种 将头结点摘下,从第一个结点开始,一次插入到头结点的后面
LinkList Reverse_l(LinkList L){
    LNode *p.*r; //p为工作指针,r 为p的后继防止断链
    p=L->next; //从第一个元素开始
    L->next=NULL; //先将头结点L的next域置为NULL
    while(p!NULL){
        r=p->next; //暂存一个P的后继
        p->next=L->next;
        L->next=p;
        p=r;
    }
    retrun L;
}


//编写后序遍历二叉树的非递归算法
//LRN  , 用栈的思想
void PostOrder(Bitree T){
    InitStack(S);
    p=T;
    r=NULL;
    while(p||!IsEmpty(S)){
        if(p){ //走到最左边
            Push(S,p);
            p=p->lchild;
        }
        else{
            GetTop(S,p); //读数据
            if(p->lchild&&p->rchild!=r)
                p=p->rchild;
            else{
                pop(S,p);
                visit(p->data);//访问
                r=p;
                p=NULL;
            }
        }
    }
}

//计算二叉树双分枝结点个数与叶子结点个数之差
int func(BiTree T){
    InitStrack S;
    int num2 =0,num0=0;
    BiTree p=T;
    while(p||!IsEmpty(S)){
        if(p){
            Push(S,p);
            p=p->lchild;
        }
        else{
            pop(S,p);
            if(p->lchild!=NULL&&p->rchild!=NULL)
                num2++;
            if(p->lchild==NULL&&p->rchild==NULL)
                num0++;
        }
    }
    return num2-num0;
}

//求指定结点在二叉树中的层次
/*
设二叉树采用二叉链表存储结构,在二叉排序树中,查找一层就下降一层,
因此,查找该结点的次数就是这个结点在二叉排序树中的层次,
*/
int lecel(BiTree bt,BSTNode *p){
    int n=0;
    BiTree t =bt;
    if(bt!=NULL){
        n++;
        while(t->data!=p->data){
            if(p->data<t->data) //在左子树中查找
                t=t->lchild;
            else   
                t=t->rchild;
            n++; //层加一
        }
    }
    return n;
}



//求出二叉排序中的最小和最大的关键字
//思路: 排序树中,最左边就是最小的, 最右边就是最大的
kettype Minkey(BSTNode *bt){
    //MIN
    while(bt->lchild!=NULL)
        bt=bt->lchild;
    return bt->data;
}
kettype Maxkey(BSTNode *bt){
    while(bt->rchild!=NULL)
        bt=bt->rchild;
    return bt->data;
}


//从大到小输出二叉排序树中所有值不小于K的关键字
//由于性质可知,右子树中所有的结点值均大于根结点值,左子树中所有的结点值均小于根结点值, 
//为了从大到小输出,先遍历右子树,再访问根结点,后便利左子树
void Output(BSTNode *bt,Keytype k){
    if(bt==NULL)
        return;
    if(bt->rchild!=NULL)
        Output(bt->rchild,k); //递归输出右子树的结点
    if(bt-<data>=k)
        printf("%d",bt->data);
    if(bt->lchild!=NULL)
        Output(bt->lchild,k); //递归输出左子树的结点
}