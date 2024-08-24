

#include "iostream"

using namespace std;


struct circularLinkedNode{
    int val;
    circularLinkedNode * next;
    circularLinkedNode(int x) : val(x), next(nullptr) {}

};

/// @brief print the whole circular linked list
/// @param head 
/// @return 
int printList(circularLinkedNode * head){
    int ending = 15;
    int i = 0;
    while(true){
        cout << head->val << endl;
        if (i > ending){
            break;
        }
        head = head->next;
        i++;
    }
    return 0;
}


int main(){
    circularLinkedNode * n0 = new circularLinkedNode(9);
    circularLinkedNode * n1 = new circularLinkedNode(4);
    circularLinkedNode * n2 = new circularLinkedNode(6);
    circularLinkedNode * n3 = new circularLinkedNode(2);

    n0->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n0;

    printList(n0);
    return 0;
}

