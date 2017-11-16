//
// Created by sunlggggg on 2017/11/15.
//


#define ElementType int

//从上向下进行调整  开始元素 是A[p]  到最后一个非叶子元素A[(N-1)/2]结束
void PercDown(ElementType *list, int root, int n){
    ElementType child,rootkey;
    rootkey  = list[root];
    child = 2*root ;
    while (child <= n ) {
        if((child< n ) && (list[child]< list[child+1])){
            child++;
        }
        if(rootkey > list[child])
            break;
        else  {
            list[child/2] = list[child] ;
            child *= 2;
        }
    }
    list[child/2] = rootkey;
}

void heapAdjust(ElementType list[], int n) { /* 堆排序 */
    for(int i = n/2; i> 0 ; i-- ){
        PercDown(list,i,n ) ;
    }
}


int main(void){
    //堆的下标从 0 开始
    ElementType list[] = {-1,212,3432,312132,2323,232342,3,4,5};
    heapAdjust(list, sizeof(list)/ sizeof(int)-1);
    return  0 ;
}