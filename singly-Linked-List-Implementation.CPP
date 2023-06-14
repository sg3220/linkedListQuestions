// Singly-Linked-List-Implementation
#include<bits/stdc++.h>
using namespace std;
    
class singlyLinkedListNode {
    public:
    float Data;
    singlyLinkedListNode* Next;
    singlyLinkedListNode(float Value) {
        this->Data = Value;
        this->Next = NULL;
    }
    ~singlyLinkedListNode() {
        float temporary = this->Data;
        cout<<"Node Containing Value: "<<temporary<<" is released"<<endl;
    }
};

void Traversal(singlyLinkedListNode* &Head) {
    singlyLinkedListNode* pointer01 = Head;
    cout<<pointer01->Data;
    pointer01 = pointer01->Next;
    while(pointer01 != NULL) {
        cout<<"->"<<pointer01->Data;
        pointer01 = pointer01->Next;
    }
    cout<<endl;
}

void insertionBegin(singlyLinkedListNode* &Head, float Value) {
    singlyLinkedListNode* newsinglyLinkedListNode = new singlyLinkedListNode(Value);
    newsinglyLinkedListNode->Next = Head;
    Head = newsinglyLinkedListNode;
}

void insertionEnd(singlyLinkedListNode* &Tail, float Value) {
    singlyLinkedListNode* newsinglyLinkedListNode = new singlyLinkedListNode(Value);
    Tail->Next = newsinglyLinkedListNode;
    Tail = newsinglyLinkedListNode;
}

void insertionMiddle(singlyLinkedListNode *Head, float Key, float Value) {
    singlyLinkedListNode* newsinglyLinkedListNode = new singlyLinkedListNode(Value);
    singlyLinkedListNode* pointer01= Head;
    singlyLinkedListNode* pointer02 = pointer01;
    while (pointer01->Data != Key) {
        pointer02 = pointer01;
        pointer01 = pointer01->Next;
    }
    pointer02->Next = newsinglyLinkedListNode;
    newsinglyLinkedListNode->Next = pointer01;  
}

void deletionBegin(singlyLinkedListNode* &Head) {
    singlyLinkedListNode* pointer = Head;
    Head = Head->Next;
    delete(pointer);
}

void deletionEnd(singlyLinkedListNode* &Head) {
    singlyLinkedListNode* pointer01 = Head;
    singlyLinkedListNode* pointer02 = pointer01;
    while (pointer01->Next != NULL) {
        pointer02 = pointer01;
        pointer01 = pointer01->Next;
    }
    pointer02->Next = NULL;
    delete(pointer01);
}

void deletionMiddle(singlyLinkedListNode * &Head, float Key) {
    singlyLinkedListNode* pointer01 = Head;
    singlyLinkedListNode* pointer02 = pointer01;
    while (pointer01->Data != Key) {
        pointer02 = pointer01;
        pointer01 = pointer01->Next;
    }
    pointer02->Next = pointer01->Next;
    delete(pointer01);
    
}

int main() {
    singlyLinkedListNode* newLinkedList = new singlyLinkedListNode(3.5);
    singlyLinkedListNode* Head = newLinkedList;
    singlyLinkedListNode* Tail = newLinkedList;

    insertionBegin(Head, 2.3);
    insertionEnd(Tail, 7.11);
    insertionMiddle(Head, 7.11, 5.7); 
    Traversal(Head);

    deletionMiddle(Head, 5.7);
    Traversal(Head);

    deletionBegin(Head);
    Traversal(Head);

    deletionEnd(Head);
    Traversal(Head);

    return 0;
}