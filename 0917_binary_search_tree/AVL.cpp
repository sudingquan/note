/*************************************************************************
	> File Name: AVL.cpp
	> Author: sudingquan
	> Mail: 1151015256@qq.com
	> Created Time: 四  9/19 18:28:04 2019
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key, h;
    struct Node *lchild, *rchild;
} Node;

Node _NIL, *NIL = &_NIL;

//先于主函数执行
__attribute__((constructor))
void init_NIL() {
    NIL->key = 0;
    NIL->h = 0;
    NIL->lchild = NIL->rchild = NIL;
    return ;
}

Node *get_new_node(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->lchild = p->rchild = NIL;
    p->h = 1;
    return p;
}

void update_height(Node *root) {
    int h1 = root->lchild->h;
    int h2 = root->rchild->h;
    root->h = (h1 > h2 ? h1 : h2) + 1;
    return ;
}

Node *left_rotate(Node *root) {
    Node *temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    update_height(root);
    update_height(temp);
    return temp;
}

Node *right_rotate(Node *root) {
    Node *temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    update_height(root);
    update_height(temp);
    return temp;

}

Node *maintain(Node *root) {
    if (abs(root->lchild->h - root->rchild->h) <= 1) return root;
    if (root->lchild->h > root->rchild->h) {
        if (root->lchild->rchild->h > root->lchild->lchild->h) {
            root->lchild = left_rotate(root->lchild);
        }
        root = right_rotate(root);
    } else {
        if (root->rchild->lchild->h > root->rchild->rchild->h) {
            root->rchild = right_rotate(root->rchild);
        }
        root = left_rotate(root);
    }
    return root;
}

Node *insert(Node *root, int key) {
    if (root == NIL) return get_new_node(key);
    if (root->key == key) return root;
    if (root->key > key) root->lchild = insert(root->lchild, key);
    else root->rchild = insert(root->rchild, key);
    update_height(root);
    return maintain(root);
}

Node *predeccessor(Node *root) {
    Node *temp = root->lchild;
    while (temp->rchild != NIL) temp = temp->rchild;
    return temp;
}

Node *erase(Node *root, int key) {
    if (root == NIL) return root;
    if (root->key > key) root->lchild = erase(root->lchild, key);
    else if (root->key < key) root->rchild = erase(root->rchild, key);
    else {
        if (root->lchild == NIL || root->rchild == NIL) {
            Node *temp = (root->lchild == NIL ? root->rchild : root->lchild);
            free(root);
            return temp;
        } else {
            Node *temp = predeccessor(root);
            root->key = temp->key;
            root->lchild = erase(root->lchild, temp->key);
        }
    }
    update_height(root);
    return maintain(root);
}

void clear(Node *root) {
    if (root == NIL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}

int main() {
    
    return 0;
}
