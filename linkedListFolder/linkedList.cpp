

#include "iostream"
using namespace std;


struct linkedNode{
    int val;
    linkedNode * next;
    linkedNode(int x) : val(x), next(nullptr) {}

};

/// @brief access an element in a linked list
/// @param head the head node of that linked list
/// @param n the nth element
/// @return 
linkedNode * accessNode(linkedNode * head, int target){
    for (int i = 0; i<target; i++){
        if (head == nullptr){
            return nullptr;
        }
        head = head->next;
    }
    return head;
}

/// @brief insert a new element between two nodes
/// @param newNode 
/// @param PrevNode 
/// @return 
int insertNode(linkedNode * newNode, linkedNode * PrevNode){
    linkedNode * lastNode = PrevNode->next;
    PrevNode->next = newNode;
    newNode->next = lastNode;

    return 0;
}


/// @brief delete an element from a linked list
/// @param head 
/// @param target 
/// @return 
int deleteNode(linkedNode * head, int target){
    linkedNode * prevNode;
    for (int i = 0; i<target; i++){
        if (head->next == nullptr){
            return 0;
        }
        prevNode = head;
        head = head->next;
    }
    prevNode->next = head->next; 
    return 0;
}


/// @brief print the whole linked list
/// @param head 
/// @return 
int printList(linkedNode * head){
    cout << "start to print the linked list....." << endl;
    while(true){
        cout << head->val << endl;
        if (head->next == nullptr){
            break;
        }
        head = head->next;
    }
    return 0;
}

/// @brief check the value in a linked list
/// @param head 
/// @param target 
/// @return 
int findVal(linkedNode * head, int target){
    int index = 0;
    while(true){
        if (head->val == target){
            return index;
        }
        head = head->next;
        index++;
    }
    
}

int main(){
    linkedNode * n0 = new linkedNode(9);
    linkedNode * n1 = new linkedNode(4);
    linkedNode * n2 = new linkedNode(6);
    linkedNode * n3 = new linkedNode(2);

    n0->next = n1;
    n1->next = n2;
    n2->next = n3;


    printList(n0);
    
    return 0;

}
