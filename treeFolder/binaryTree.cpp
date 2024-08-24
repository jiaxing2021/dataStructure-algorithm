

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

// level oreder
vector<int> breadthFirstTraversal(binaryTreeNode * node){
    queue <binaryTreeNode *> queueNode;
    queueNode.push(node);

    vector <int> vectorNode;

    while(!queueNode.empty()){
        binaryTreeNode *n = queueNode.front();
        queueNode.pop();
        vectorNode.push_back(n->val);
        if (n->left != nullptr){
            queueNode.push(n->left);
        }
        if (n->right != nullptr){
            queueNode.push(n->right);
        }
    }

    return vectorNode;
}

// depth order 
void preOrder(binaryTreeNode * node, vector <int>& vec){

    if (node == nullptr){
        return;
    }
    vec.push_back(node->val);
    // cout << node->val << " ";
    preOrder(node->left, vec);
    preOrder(node->right, vec);

    return;
}

void inOrder(binaryTreeNode * node, vector <int>& vec){

    if (node == nullptr){
        return;
    }
 
    inOrder(node->left, vec);
    vec.push_back(node->val);
    inOrder(node->right, vec);

    return;
}


void postOrder(binaryTreeNode * node, vector <int>& vec){

    if (node == nullptr){
        return;
    }
    postOrder(node->left, vec);
    postOrder(node->right, vec);
    vec.push_back(node->val);

    return;
}


int printVec(vector<int> vec){
    for (auto i = vec.begin(); i != vec.end(); ++i)
        cout << *i << " " ;
    cout << endl;

    return 0;
}

int main(){

    vector <int> vec;

    // initial binary tree
    //       n0
    //    /      \
    //   n1      n2
    //  /  \    /  \
    // n3  n4  n5  n6
    binaryTreeNode * n0 = new binaryTreeNode(8);
    binaryTreeNode * n1 = new binaryTreeNode(5);
    binaryTreeNode * n2 = new binaryTreeNode(1);
    binaryTreeNode * n3 = new binaryTreeNode(9);
    binaryTreeNode * n4 = new binaryTreeNode(0);
    binaryTreeNode * n5 = new binaryTreeNode(2);
    binaryTreeNode * n6 = new binaryTreeNode(4);

    n0->left = n1;
    n0->right = n2;
    n1->left = n3;
    n1->right = n4;
    n2->left = n5;
    n2->right = n6;

    vec = breadthFirstTraversal(n0);
    printVec(vec);

    vector <int> preVectorNode;
    preOrder(n0, preVectorNode);
    printVec(preVectorNode);

    vector <int> inVectorNode;
    inOrder(n0, inVectorNode);
    printVec(inVectorNode);

    vector <int> postVectorNode;
    postOrder(n0, postVectorNode);
    printVec(postVectorNode);

    return 0;

}
