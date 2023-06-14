// Doubly-Linked-List-Implementation
#include<bits/stdc++.h>
using namespace std;
    
class doublyLinkedListNode {
    public:
    float Data;
    doublyLinkedListNode* Next;
    doublyLinkedListNode* Previous;
    doublyLinkedListNode(float Value) {
        this->Data = Value;
        this->Next = NULL;
        this->Previous = NULL;
    }
    ~doublyLinkedListNode() {
        float temporary = this->Data;
        cout<<"Node Containing Value: "<<temporary<<" is released"<<endl;
    }
};

void TraversalBegin(doublyLinkedListNode* &Head) {
    doublyLinkedListNode* pointer01 = Head;
    cout<<pointer01->Data;
    pointer01 = pointer01->Next;
    while(pointer01 != NULL) {
        cout<<"->"<<pointer01->Data;
        pointer01 = pointer01->Next;
    }
    cout<<endl;
}

void TraversalEnd(doublyLinkedListNode* &Tail) {
    doublyLinkedListNode* pointer01 = Tail;
    cout<<pointer01->Data;
    pointer01 = pointer01->Previous;
    while(pointer01 != NULL) {
        cout<<"->"<<pointer01->Data;
        pointer01 = pointer01->Previous;
    }
    cout<<endl;
}

void insertionBegin(doublyLinkedListNode* &Head, float Value) {
    doublyLinkedListNode* newNode = new doublyLinkedListNode(Value);
    newNode->Next = Head;
    Head->Previous = newNode;
    Head = newNode;
}

void insertionEnd(doublyLinkedListNode* &Tail, float Value) {
    doublyLinkedListNode* newNode = new doublyLinkedListNode(Value);
    Tail->Next = newNode;
    newNode->Previous = Tail;
    Tail = newNode;
}

void insertionMiddle(doublyLinkedListNode *Head, float Key, float Value) {
    doublyLinkedListNode* newNode = new doublyLinkedListNode(Value);
    doublyLinkedListNode* pointer01= Head;
    doublyLinkedListNode* pointer02 = pointer01;
    while (pointer01->Data != Key) {
        pointer02 = pointer01;
        pointer01 = pointer01->Next;
    }
    pointer02->Next = newNode;
    newNode->Previous = pointer02;
    newNode->Next = pointer01;
    pointer01->Previous = newNode;  
}

void deletionBegin(doublyLinkedListNode* &Head) {
    doublyLinkedListNode* pointer = Head;
    Head = Head->Next;
    Head->Previous = NULL;
    delete(pointer);
}

void deletionEnd(doublyLinkedListNode* &Head) {
    doublyLinkedListNode* pointer01 = Head;
    doublyLinkedListNode* pointer02 = pointer01;
    while (pointer01->Next != NULL) {
        pointer02 = pointer01;
        pointer01 = pointer01->Next;
    }
    pointer02->Next = NULL;
    delete(pointer01);
}

void deletionMiddle(doublyLinkedListNode * &Head, float Key) {
    doublyLinkedListNode* pointer01 = Head;
    doublyLinkedListNode* pointer02 = pointer01;
    while (pointer01->Data != Key) {
        pointer02 = pointer01;
        pointer01 = pointer01->Next;
    }
    pointer02->Next = pointer01->Next;
    pointer01->Next->Previous = pointer02;
    delete(pointer01);
    
}

int main() {
    doublyLinkedListNode* newLinkedList = new doublyLinkedListNode(3.5);
    doublyLinkedListNode* Head = newLinkedList;
    doublyLinkedListNode* Tail = newLinkedList;

    insertionBegin(Head, 2.3);
    insertionEnd(Tail, 7.11);
    insertionMiddle(Head, 7.11, 5.7); 
    TraversalBegin(Head);
    TraversalEnd(Tail);

    deletionMiddle(Head, 5.7);
    TraversalBegin(Head);

    deletionBegin(Head);
    TraversalBegin(Head);

    deletionEnd(Head);
    TraversalBegin(Head);

    return 0;
}