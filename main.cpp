#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Node.h"

using namespace std;

int main() {
    int x;
    int minimum;
    int currentNum;
    Node* previous;
    Node* doublePre;
    Node* head= new Node();
    Node* current= head;
    cout<<"enter a list of integers and -1 to stop"<<endl;
    cin>>x;
    //populate the linked list with at least 7 nodes
    while(x!=-1){
       Node* n= new Node(x);
       current->InsertAfter(n);
       current=n; //current=current->getNext;
       cin>>x;

    }

    //print the nodes of the linked list
    current=head->getNext();
    while(current!=nullptr)
    {
        current->printNode();
        current=current->getNext();
    }

    //1) find the node that has the minimum value

    current = head;
    minimum = current->getValue();

    while (current != nullptr) {

        currentNum = current->getValue();

        if (currentNum < minimum) {
            minimum = currentNum;
        }

        current = current->getNext();

    }


    //2) remove the 4th node from the list

    current = head;
    current = current->getNext();
    previous = head;

    for (int i = 0; i < 3; i++) {
        current=current->getNext();
        previous = previous->getNext();
    }

    previous->setNext(current->getNext());
    current->setNext(nullptr);
    delete current;

    current=head->getNext();
    while(current!=nullptr)
    {
        current->printNode();
        current=current->getNext();
    }

    //3) remove the last node

    current = head;
    current = current->getNext();
    current = current->getNext();
    previous = head;
    previous = previous->getNext();
    doublePre = head;

    while (current != nullptr) {
        current = current->getNext();
        previous = previous->getNext();
        doublePre = doublePre->getNext();
    }

    doublePre->setNext(nullptr);
    delete previous;

    current=head->getNext();
    while(current!=nullptr)
    {
        current->printNode();
        current=current->getNext();
    }

    //4) remove the first node

   current = head;
    head = head->getNext();
    delete current;

    current=head->getNext();
    while(current!=nullptr)
    {
        current->printNode();
        current=current->getNext();
    }


    //6) delete all nodes
    delete head;

    current=head->getNext();
    while(current!=nullptr)
    {
        current->printNode();
        current=current->getNext();
    }


    return 0;
}