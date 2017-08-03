//
//  main.cpp
//  Queue Linked List
//
//  Created by Brett Markowitz on 7/28/17.
//  Copyright © 2017 Brett Markowitz. All rights reserved.
//


#include <iostream>
using namespace std;

//function prototypes
struct node* getNode();
void createQueue();

void enqueue();
void dequeue();
void displayQueue();

//node struct
struct node {
    int data;
    node* next;
};
node* start = nullptr;
node* rear = nullptr;



int main()
{
    cout << "Welcome to the queue.\n";
    
    createQueue();
    displayQueue();
    cout << "The data in the start node is " << start->data << " and the data in the rear node is " << rear->data << ".\n";
    
    
    return 0;
}

struct node* getNode()
{
    node* newNode;
    newNode = new node;
    
    cout << "Enter data to store in the node: ";
    cin >> newNode->data;
    
    newNode->next = nullptr;
    
    return newNode;
}

void createQueue()
{
    node* newNode;
    node* temp;
    int amount;
    
    cout << "Enter the number of items to store in the queue: ";
    cin >> amount;
    
    for (int i = 0; i < amount; i++) {
        newNode = getNode();
        if(start == nullptr)
        {
            start = newNode;
            rear = newNode;
        }
        else
        {
            temp = start;
            while(temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            rear = newNode;
        }
    }
}

void enqueue()
{
    node* newNode;
    node* temp;
    newNode = getNode();
    
    if(start == nullptr)
    {
        start = newNode;
        rear = newNode;
        return;
    }
    else
    {
        temp = start;
        while(temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        rear = newNode;
    }
}

void dequeue()
{
    node* temp;
    if(start == nullptr)
    {
        cout << "The queue is already empty.\n";
        return;
    }
    else if(start->next == nullptr)
    {
        temp = start;
        start = nullptr;
        delete temp;
        cout << "The first node in the queue has been deleted.\n";
        return;
    }
    else
    {
        temp = start;
        start = start->next;
        delete temp;
        cout << "The first node in the queue has been deleted.\n";
    }
}

void displayQueue()
{
    node* temp;
    temp = start;
    if(start == nullptr)
    {
        cout << "The queue is empty.\n";
        return;
    }
    else
    {
    while(temp != nullptr)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
    }
}
