//
// Created by sunlggggg on 2017/11/15.
//


#define ElementType int
//交换两个变量指向的内存中的数值
void Swap(ElementType *a, ElementType *b) {
    ElementType t = *a;
    *a = *b;
    *b = t;
}
//从上向下进行调整  开始元素 是A[p]  到最后一个非叶子元素A[(N-1)/2]结束
void PercDown(ElementType *A, int p, int N) {
    /* 将N个元素的数组中以A[p]为根的子堆调整为最大堆 */
    int Parent, Child;
    ElementType X;

    X = A[p]; /* 取出根结点存放的值 */
    //2*p+1 < N   2*p+1 <= N-1(最后一个节点) 当前父节点的左孩子 存在 即 当前节点非叶子节点
    for (Parent = p; (Parent * 2 + 1) < N; Parent = Child) {
        Child = Parent * 2 + 1;
        //如果右孩子存在 则找到两个孩子较大的那个
        if ((Child != N - 1) && (A[Child] < A[Child + 1]))
            Child++; /* Child指向左右子结点的较大者 */
        //不再需要调整 将不会再影响后续子树符合大顶堆的条件
        if (X >= A[Child]) break;
            //继续向下调整
        else /* 下滤X */
            A[Parent] = A[Child];
    }
    //将 最初要向下调整的节点 赋值给最后一个被交换的孩子 （当前已经用Parent指向 child指向的是Parent的孩子中较大的那个）
    A[Parent] = X;
}

void HeapSort(ElementType A[], int N) { /* 堆排序 */
    int i;

    for (i = N / 2 - 1; i >= 0; i--)/* 建立最大堆 */
        PercDown(A, i, N);

    for (i = N - 1; i > 0; i--) {
        /* 删除最大堆顶 */
        Swap(&A[0], &A[i]);
        PercDown(A, 0, i);
    }
}
