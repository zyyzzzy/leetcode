/*用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )

 

示例 1：

输入：
["CQueue","appendTail","deleteHead","deleteHead"]
[[],[3],[],[]]
输出：[null,null,3,-1]
示例 2：

输入：
["CQueue","deleteHead","appendTail","appendTail","deleteHead","deleteHead"]
[[],[],[5],[2],[],[]]
输出：[null,-1,null,null,5,2]
提示：

1 <= values <= 10000
最多会对 appendTail、deleteHead 进行 10000 次调用

*/

typedef struct {
   int len;
   int top1;
   int top2;
   int *stack1;
   int *stack2;
} CQueue;


CQueue* cQueueCreate() {
    CQueue *queue = (CQueue *)malloc(sizeof(CQueue));
    if(queue == NULL)       return NULL;   //判断是否已经成功开辟空间。

    queue->len = 1000;
    queue->top1 = -1;
    queue->top2 = -1;
    queue->stack1 = (int *)calloc(queue->len,sizeof(int)); //calloc 和malloc 的区别就是calloc 在分配空间时都初始化了。
    queue->stack2 = (int *)calloc(queue->len,sizeof(int));

    if(queue->stack1 == NULL ||queue->stack2 == NULL)
        return NULL;

    return queue; //因为是指针函数 所以需要返回指针，不然会找不到！
}

void cQueueAppendTail(CQueue* obj, int value) {
    if(obj == NULL)     return NULL;

    obj->stack1[++(obj->top1)] = value;

}

int cQueueDeleteHead(CQueue* obj) {
    if(obj->top2 == -1)
    {
        while(obj->top1 != -1)
        {
            obj->stack2[++(obj->top2)] = obj->stack1[(obj->top1)--];//top指针会向下和向上移动来看stack是否为空。
        }
    }
    if(obj->top2 == -1)   return -1;
    else      return obj->stack2[(obj->top2)--];//最后需要(obj->top2)--,否则(obj->top2)永远不会变成-1，即每次调用此函数会一直输出这个要删除的数，而不会为-1。
}

void cQueueFree(CQueue* obj) {
    free(obj->stack1);
    free(obj->stack2);
    free(obj);

}

/**
 * Your CQueue struct will be instantiated and called as such:
 * CQueue* obj = cQueueCreate();
 * cQueueAppendTail(obj, value);
 
 * int param_2 = cQueueDeleteHead(obj);
 
 * cQueueFree(obj);
*/