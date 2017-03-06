//1066. Root of AVL Tree
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>

using namespace std;

struct Node {
    Node* left;
    Node* right;
    int value;
    int height;

    Node(Node* ileft, Node* iright, int ivalue, int iheight) {
        left = ileft;
        right = iright;
        value = ivalue;
        height = iheight;
    }
};

int getHeight(Node* node) {
    return node==NULL?-1:node->height;
}

Node* rotateLeft(Node* node) {
    Node* temp = node->right;
    node->right = temp->left;
    temp->left = node;

    node->height = max(getHeight(node->left), getHeight(node->right))+1;
    temp->height = max(getHeight(temp->left), getHeight(temp->right))+1;

    return temp;
}

Node* rotateRight(Node* node) {
    Node* temp = node->left;
    node->left = temp->right;
    temp->right = node;

    node->height = max(getHeight(node->left), getHeight(node->right))+1;
    temp->height = max(getHeight(temp->left), getHeight(temp->right))+1;

    return temp;
}

Node* rotateLeftRight(Node* node) {
    node->left = rotateLeft(node->left);
    return rotateRight(node);
}

Node* rotateRightLeft(Node* node) {
    node->right = rotateRight(node->right);
    return rotateLeft(node);
}
Node* inse(int inseVal, struct Node* root) {
//    if(inseVal == 61) {
//        printf("hello");
//    }

    if(root == NULL) {
        return new Node(NULL, NULL, inseVal, 0);
    }

    if(root->value-inseVal>0) {
        root->left = inse(inseVal, root->left);

        if(getHeight(root->left) - getHeight(root->right) > 1) {
            if(root->left->value > inseVal) {
                root = rotateRight(root);
            }
            else {
                root = rotateLeftRight(root);
            }
        }
    }
    else {
        root->right = inse(inseVal, root->right);

        if(getHeight(root->right) - getHeight(root->left) > 1) {
            if(root->right->value <= inseVal) {
                root = rotateLeft(root);
            }
            else {
                root = rotateRightLeft(root);
            }
        }
    }

    // 当依旧平衡时调整高度
    root->height = max(getHeight(root->left), getHeight(root->right))+1;
    return root;

}
int main() {
    int n;
    scanf("%d", &n);

    Node* node = NULL;
    for(int i=0; i<n; i++) {
        int val;
        scanf("%d", &val);
        node = inse(val, node);
//        printf("%d\n", node->value);
    }

    printf("%d", node->value);
    return 0;
}
