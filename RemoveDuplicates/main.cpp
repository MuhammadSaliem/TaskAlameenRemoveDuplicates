
#include <iostream>
#include <unordered_set>
using namespace std;


/********************** Linkedlist **********************/

//Node
class Node {
public:
    int data;
    Node* next;
};

//Singly LinkedList
class LinkedList
{
public:
    Node* head, * tail;

public:
    LinkedList()
    {
        head = tail = NULL;
    }

    void push(int n)
    {
        Node* tmp = new Node();
        tmp->data = n;
        tmp->next = NULL;

        if (head == NULL )
            head = tail = tmp;

        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
    }

    void printLinkedList()
    {
        Node* tmpHead = head;

        while (tmpHead != NULL) {
            cout << tmpHead->data << " -> ";
            tmpHead = tmpHead->next;
        }
        cout << endl;
        delete(tmpHead);
    }
};


/********************** Remove Duplicates **********************/

    
    //1- Merge sort apporach: time complexity O(NlogN)

    //2- Using hashing apporach: time complexity O(N)
    void deleteDuplicatesHashing(Node* head)
    {
        Node* current = head;
        Node* prev = NULL;
       
        unordered_set<int> set;

        while (current != NULL) {
            if (set.find(current->data) != set.end()) {
                prev->next = current->next;
                delete (current);
            }
            else {
                set.insert(current->data);
                prev = current;
            }
            current = prev->next;
        }
    }

    /*********** Solution ***********/
    //3-Brute force apporach: time complexity O(N^2)
    //No temp buffer is used.
    void deleteDuplicates(Node* head)
    {
        Node* current = head;
        while (current != NULL)
        {
            Node* outer = current;
            while (outer->next != NULL)
            {
                if (outer->next->data == current->data)
                    outer->next = outer->next->next;
                
                else
                    outer = outer->next;
            }
            current = current->next;
        }
    };


int main()
{
    //Declare and initialize a linkedlist
    LinkedList* linkedList = new LinkedList(); 
    linkedList->push(2);
    linkedList->push(6);
    linkedList->push(2);
    linkedList->push(7);
    linkedList->push(8);
    linkedList->push(1);
    linkedList->push(1);
    linkedList->push(7);

    cout << "Before:  ";
    linkedList->printLinkedList();

    deleteDuplicates(linkedList->head); 

    cout << "After :  ";
    linkedList->printLinkedList();

    return 0;
}
