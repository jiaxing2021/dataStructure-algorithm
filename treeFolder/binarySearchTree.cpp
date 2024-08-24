

#include "iostream"
#include "queue"
using namespace std;


struct binaryTreeNode
{
    int val;
    binaryTreeNode * left;
    binaryTreeNode * right;

    binaryTreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

};

void inOrder(binaryTreeNode * node, vector <int>& vec){

    if (node == nullptr){
        return;
    }
 
    inOrder(node->left, vec);
    vec.push_back(node->val);
    inOrder(node->right, vec);

    return;
}

int printVec(vector<int> vec){
    for (auto i = vec.begin(); i != vec.end(); ++i)
        cout << *i << " " ;
    cout << endl;

    return 0;
}

binaryTreeNode * searchNode(binaryTreeNode * root, int target){
    while(true){
        if (target == root->val){
        return root;
        }
        if (target < root->val){
        root = root->left;
            if (root == nullptr){
                break;
            }
        }
        if (target > root->val){
        root = root->right;
            if (root == nullptr){
                break;
            }
        }

    }
}

int main(){

    vector <int> vec;

    // initial binary tree
    //       n0
    //    /      \
    //   n1      n2
    //  /  \    /  \
    // n3  n4  n5  n6
    binaryTreeNode * n0 = new binaryTreeNode(4); // n0
    binaryTreeNode * n1 = new binaryTreeNode(2); // n1
    binaryTreeNode * n2 = new binaryTreeNode(6); // n2
    binaryTreeNode * n3 = new binaryTreeNode(1); // n3
    binaryTreeNode * n4 = new binaryTreeNode(3); // n4
    binaryTreeNode * n5 = new binaryTreeNode(5); // n5
    binaryTreeNode * n6 = new binaryTreeNode(7); // n6

    n0->left = n1;
    n0->right = n2;
    n1->left = n3;
    n1->right = n4;
    n2->left = n5;
    n2->right = n6;

    vector <int> postVectorNode;
    inOrder(n0, postVectorNode);
    printVec(postVectorNode);

    int target = 6;
    binaryTreeNode * targetNode = searchNode(n0, target);
    cout << targetNode->val << endl;


    return 0;

}
