
#include "iostream"
using namespace std;

struct doublyLinkedNode
{
    int val;
    doublyLinkedNode * next;
    doublyLinkedNode * prev;

    doublyLinkedNode(int x) : val(x), next(nullptr), prev(nullptr) {}

};


/// @brief print the whole doubly linked list
/// @param head 
/// @return 
int printList(doublyLinkedNode * head){
    cout << "the positive direction" << endl;
    while(true){
        cout << head->val << endl;
        if (head->next == nullptr){
            break;
        }
        head = head->next;
    }
    cout << "the negative direction" << endl;
    while(true){
        cout << head->val << endl;
        if (head->prev == nullptr){
            break;
        }
        head = head->prev;
    }
    return 0;
}

int main(){
    doublyLinkedNode * n0 = new doublyLinkedNode(8);
    doublyLinkedNode * n1 = new doublyLinkedNode(7);
    doublyLinkedNode * n2 = new doublyLinkedNode(1);
    doublyLinkedNode * n3 = new doublyLinkedNode(0);

    n0->next = n1;
    n1->next = n2;
    n2->next = n3;

    n3->prev = n2;
    n2->prev = n1;
    n1->prev = n0;

    printList(n0);

    return 0;

}
