#include <iostream>

using namespace std;

struct Node
{
    int key; //dat ... ten gi cung duoc
    Node* next;
};

Node* createNode(int data)
{
    Node* newNode = new Node;
    newNode -> key = data;
    newNode -> next = NULL;
    return newNode;
}

void addHead(Node*& pHead, int data)
{
    if (pHead == NULL)
    {
        pHead = createNode(data);
    }
    else
    {
        Node* newNode = createNode(data);
        newNode -> next = pHead;
        pHead = newNode;
    }
}

void PrintList (Node* pHead) // trong moi truong hop 
                            // pHead luon luon la thang dau tien
{
    Node* curNode = pHead;
    while (curNode != NULL)
    {
        cout << curNode -> key << "->";
        curNode = curNode -> next;
    }
}

void addTail(Node* &pHead, int data)
{
    Node* newNode = createNode(data);
    if (pHead == NULL)
    {
        pHead = newNode;
    }
    else{
        Node* curNode = pHead;
        while (curNode -> next != NULL)
        {
            curNode = curNode -> next;
        }
        curNode->next = newNode;
    }
}

void removeHead (Node* &pHead)
{
    if (pHead != NULL)
    {
        Node* nextNode = pHead -> next;
        delete pHead;
        pHead = nextNode;
    }
}

void removeTail (Node* &pHead)
{
    if (pHead != NULL)
    {
        if (pHead -> next == NULL)
        {
            delete pHead;
            pHead = NULL;
        }
    }
    else{
        Node* curNode = pHead;
        while (curNode -> next -> next != NULL)
        {
            curNode = curNode -> next;
        }
        delete curNode -> next;
        curNode -> next = NULL; // quan trong
    }
}

void removeBeforeValue(Node*& pHead, int value) {
    if (pHead == NULL || pHead->next == NULL) {
        return;
    }

    Node* curNode = pHead;
    Node* preNode = NULL;

    while (curNode != NULL && curNode->next != NULL && curNode->next->key != value) {
        preNode = curNode;
        curNode = curNode->next;
    }

    if (preNode == NULL) {
        pHead = curNode->next;
        delete curNode;
    } else {
        preNode->next = curNode->next;
        delete curNode;
    }
}

void addPos(Node*& pHead, int value, int pos) {
    Node* newNode = new Node();
    newNode->key = value;
    newNode->next = NULL;

    if (pos == 0) {
        newNode->next = pHead;
        pHead = newNode;
        return;
    }

    Node* curNode = pHead;
    int i = 0;

    while (curNode != NULL && i < pos - 1) {
        curNode = curNode->next;
        i++;
    }

    if (curNode == NULL) {
        cout << "Invalid position." << endl;
        return;
    }

    newNode->next = curNode->next;
    curNode->next = newNode;
}


int main ()
{
    Node* pHead = NULL;
    addHead(pHead, 1);
    addHead(pHead, 5);
    addHead(pHead, 2);
    addHead(pHead, 7);
    PrintList(pHead);
    cout << endl;
    addTail(pHead, 6);
    PrintList(pHead);
    cout << endl;
    removeBeforeValue(pHead, 1);
    PrintList(pHead);
    cout << endl;
    addPos (pHead, 3, 2);
    PrintList(pHead);
    return 0;
}