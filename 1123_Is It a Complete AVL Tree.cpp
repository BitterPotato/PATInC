// 1122
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <queue>
#include <math.h>

using namespace std;

struct Node {
    Node* left;
    Node* right;
    int val;
    int height;

    Node(Node* l, Node* r, int v, int h) {
        left = l;
        right = r;
        val = v;
        height = h;
    }
};

int height(Node* node) {
    return node==NULL?-1:node->height;
}

Node* leftSingleRotate(Node* root) {
    Node* temp = root->right;
    root->right = temp->left;
    temp->left = root;

    root->height = max(height(root->left), height(root->right)) +1;
    temp->height = max(height(temp->left), height(temp->right)) +1;

    return temp;
}
Node* rightSingleRotate(Node* root) {
    Node* temp = root->left;
    root->left = temp->right;
    temp->right = root;

    root->height = max(height(root->left), height(root->right)) +1;
    temp->height = max(height(temp->left), height(temp->right)) +1;

    return temp;
}
Node* leftRightRotate(Node* root) {
    root->left = leftSingleRotate(root->left);
    return rightSingleRotate(root);
}
Node* rightLeftRotate(Node* root) {
    root->right = rightSingleRotate(root->right);
    return leftSingleRotate(root);
}
Node* inser(Node* root, int val) {
    if(root == NULL) {
        root = new Node(NULL, NULL, val, 0);
    }

    else {
        if(root->val < val) {
            root->right = inser(root->right, val);

            if(height(root->right) > height(root->left)+1) {
                if(root->right->val < val)
                    root = leftSingleRotate(root);
                else
                    root = rightLeftRotate(root);
            }
        }
        else {
            root->left = inser(root->left, val);

            if(height(root->left) > height(root->right)+1) {
                if(root->left->val >= val)
                    root = rightSingleRotate(root);
                else
                    root = leftRightRotate(root);
            }
        }
    }

    root->height = max(height(root->left), height(root->right)) +1;

    return root;
}

int main() {
    int n;
    scanf("%d", &n);

    Node* root = NULL;
    for(int i=0; i<n; i++) {
        int val;
        scanf("%d", &val);

        root = inser(root, val);
    }

    queue<Node*> que;
    que.push(root);
    int preCapa = 1;
    int level = 0;
    int valid = true;
    while(true) {
        int tempCapa = 0;
        // 用于判断完全二叉树
        bool judgAdd = true;
        int judgCapa = 0;
        for(int i=0; i<preCapa; i++) {
            Node* node = que.front();
            if(level == 0)
                printf("%d", node->val);
            else
                printf(" %d", node->val);
            que.pop();

            if(node->left != NULL) {
                que.push(node->left);
                tempCapa++;
                judgCapa += judgAdd?1:0;
            }
            else {
                judgAdd = false;
            }
            if(node->right != NULL) {
                que.push(node->right);
                tempCapa++;
                judgCapa += judgAdd?1:0;
            }
            else {
                judgAdd = false;
            }
        }


        level++;
        if(tempCapa == 0) {
            break;
        }
        else {
            if(judgCapa != tempCapa)
                valid = false;
        }

        preCapa = tempCapa;
    }
    printf("\n%s", valid?"YES":"NO");
}
