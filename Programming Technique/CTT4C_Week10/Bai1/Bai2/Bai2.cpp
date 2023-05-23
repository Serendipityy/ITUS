#include <stdlib.h>
#include<iostream>
using namespace std;

// LList node
struct Node {
    int data;
    int priority;
    Node* prev, * next;
};

bool isEmpty(Node* fr) { return (fr == NULL); }

void enQueue(Node** fr, Node** rr, int n, int p)
{
    Node* news = (Node*)malloc(sizeof(Node));
    news->data = n;
    news->priority = p;

    // If linked list is empty
    if (*fr == NULL) {
        *fr = news;
        *rr = news;
        news->next = NULL;
    }
    else {
        // If p is less than or equal front
        // node's priority, then insert at
        // the front.
        if (p <= (*fr)->priority) {
            news->next = *fr;
            (*fr)->prev = news->next;
            *fr = news;
        }

        // If p is more rear node's priority,
        // then insert after the rear.
        else if (p > (*rr)->priority) {
            news->next = NULL;
            (*rr)->next = news;
            news->prev = (*rr)->next;
            *rr = news;
        }

        // Handle other cases
        else {

            // Find position where we need to
            // insert.
            Node* start = (*fr)->next;
            while (start->priority > p)
                start = start->next;
            (start->prev)->next = news;
            news->next = start->prev;
            news->prev = (start->prev)->next;
            start->prev = news->next;
        }
    }
}

// Return the value at rear
int front(Node* fr) { return fr->data; }

// Removes the element with the
// least priority value form the list
int deQueue(Node** fr, Node** rr)
{
    Node* temp = *fr;
    int res = temp->data;
    (*fr) = (*fr)->next;
    free(temp);
    if (*fr == NULL)
        *rr = NULL;
    return res;
}

int main()
{
    Node* f = NULL, * r = NULL;
    int key1 = 1, key2 = 1, d, p;

    while (key1 == 1) {
        cout << "Input data: \n"; cin >> d;
        cout << "Input priority of data: \n"; cin >> p;
        enQueue(&f, &r, d, p);
        cout << "Press 0: Stop.\n";
        cout << "Press 1: Continue.\n";
        cin >> key1;
    }

    cout << "Element front: " << front(f) << endl;
    if (isEmpty(f)) { cout << "Queue empty.\n"; }
    else {
        while (key2 == 1) {
            cout << "Pop element: " << deQueue(&f, &r) << endl;
            cout << "Press 0: Stop.\n";
            cout << "Press 1: Continue.\n";
            cin >> key2;
        }
    }
    cout << "The end\n";
    return 0;
}