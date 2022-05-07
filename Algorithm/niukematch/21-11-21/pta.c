#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;
List Reverse( List L ){
    List last_one = L,next_one = L->Next,end_next = L;
    while(next_one){
        L = next_one;
        next_one = next_one->Next;
        L->Next = last_one;
        last_one = L;
    }
    end_next = NULL;
    return L;
}