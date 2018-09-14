#include "queue.h"

int main()
{
    Queue Q;

    Q = CreateQueue(5);

    Enqueue(3,Q);

    Enqueue(3,Q);
    Enqueue(3,Q);
    Enqueue(3,Q);
    Enqueue(3,Q);
    Enqueue(3,Q);
    
    printf("%d\n",IsEmpty(Q));
    return 0;
}
