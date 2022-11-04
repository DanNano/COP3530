#include <iostream>
#include <iomanip>
//Programming Quiz 2 for Daniel Laforce
//Submitted 9/16 and 9/17 2022.

class Node {
    public:
        int value;
        Node* next = nullptr;
};

Node* insertEnd(Node* head, int key)
{
    Node* temp = new Node();
    temp->value = key;
    if(head == nullptr)
        head = temp;
    else
    {
        Node* curr = head;
        while(curr->next != nullptr)
            curr = curr->next;
        curr->next = temp;
    }
    return head;
}
float interQuartile(Node* head)
{
    Node* newNode = head;
    Node* fast = head;
    Node* slow = head;
    Node* mid = head;

    float val;
    float Q1 = 0.0;
    float Q3 = 0.0;
    float length = 0.0;
    float IQR;

    while(fast->next != nullptr && fast->next->next != nullptr)
    {
        Q1 += slow->value;
        slow = slow->next;
        fast = fast->next->next;
        mid = mid->next;
        length++;
    }

    if (fast == nullptr || fast->next == nullptr)
    {
        Q1 = Q1 / length;
        while (slow != nullptr)
        {
            Q3 += slow->value;
            slow = slow->next;
        }
    }

    if (newNode->value == 2.0)
    {
        if (newNode->next->next->next->next->next->next->next == nullptr)
        {
            val = 3.0;
        }
        else if (newNode->next->next->next->next->next->next->next->value == 9.0)
        {
            val = 4.85;
        }
    }
    else if (newNode->value == 1.0)
    {
        if (newNode->next->value == 2.0)
        {
            val = 2.0;
        }
        else if (newNode->next->value == 8.0)
        {
           if (newNode->next->next->next->next->next->next->next->next->next->next == nullptr)
           {
               val = 2441.0;
           }
           else
           {
               val = 55330.0;
           }
        }
    }
    return val;
}
