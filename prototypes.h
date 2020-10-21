//
// Created by btnt51 on 10/18/2020.
//

#ifndef DISLAB3_PROTOTYPES_H
#define DISLAB3_PROTOTYPES_H
#include <cstdlib>
#include <iostream>
typedef struct MyList
{
    int value = 0;
    struct MyList *next = nullptr;
} MyList;

int pop(MyList **head){
    MyList * prev = nullptr;
    int val;
    if(head == nullptr)
        exit(-1);
    prev = (*head);
    val = prev->value;
    (*head) = (*head)->next;
    delete prev;
    return val;
}

MyList *getN(MyList *head, int n){
    int counter = 0;
    while(counter < n && head)
    {
        head = head->next;
        counter++;
    }
    return head;
}

void First(MyList *head){
    int n = 1;
    if(head->next == nullptr)
        std::cout << "\nError there is no elements in list";
    else {
        auto temp = getN(head, n);
        std::cout << "First element is " << temp->value;
    }
}

int getSize(MyList *head)
{
    int size=0;
    while (head)
    {
        head = head->next;
        size++;
    }
    return size;
}

void Insert(MyList *head, int data, int n)
{
    int i =0;
    MyList *temp = nullptr;
    while (i<n && head->next){
        head = head->next;
        i++;
    }
    temp = new MyList;
    temp->value=data;
    head->next ? temp->next =head->next : temp->next= nullptr;
    head->next = temp;
}

int Delete(MyList **head, int n)
{
    if(getSize(*head) < n){
        std::cout << "Out of list." << std::endl;
        return -1;
    }else if(n==0)
        return pop(head);
    else
    {
        MyList *prev = getN(*head,n-1);
        MyList *element = prev->next;
        int value = element->value;
        prev->next = element->next;
        delete element;
        return value;
    }
}

void Print(MyList *head){
    auto temp = getN(head, 1);
    while(temp){
        std::cout<< temp->value << "|";
        temp=temp->next;
    }
    std::cout << "\n";
}

#endif //DISLAB3_PROTOTYPES_H
