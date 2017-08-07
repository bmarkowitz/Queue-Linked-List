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

void menu();

//node struct
struct node {
    int data;
    node* next;
};
node* start = nullptr;
node* rear = nullptr;

//queue: inserts at rear, deletes from start



int main()
{
    cout << "Welcome to the queue.\n";
    
    cout << "To perform queue operations, you must first create a queue." << endl;
    
    createQueue();
    
    menu();
    
    int choice;
    cin >> choice;
    
    while(choice != 9)
    {
        
        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                displayQueue();
                break;
                
            default:
                break;
        }
        menu();
        cin >> choice;
    }
    
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
        cout << "The queue is already empty." << endl << endl;
        return;
    }
    else if(start->next == nullptr)
    {
        temp = start;
        start = nullptr;
        delete temp;
        cout << "The first node in the queue has been deleted." << endl << endl;
        return;
    }
    else
    {
        temp = start;
        start = start->next;
        delete temp;
        cout << "The first node in the queue has been deleted."  << endl << endl;
    }
}

void displayQueue()
{
    node* temp;
    temp = start;
    if(start == nullptr)
    {
        cout << "The queue is empty." << endl << endl;
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

void menu()
{
    cout << "1: Add an item to the queue" << endl;
    cout << "2: Delete an item from the queue" << endl;
    cout << "3: Display the queue" << endl;
    cout << "9: Exit the program" << endl;
}
