/*************************************************************************
	> File Name: trie.cpp
	> Author: sudingquan
	> Mail: 1151015256@qq.com
	> Created Time: 一  8/19 19:11:48 2019
 ************************************************************************/

#include <stdlib.h>
#include <stdio.h>

#define BASE 26
#define BASE_LETTER 'a'
typedef struct Node {
    int flag;
    struct Node *next[BASE];
} Node;

Node *get_new_node() {
    Node *p = (Node *)calloc(sizeof(Node), 1);
    return p;
}

inline int code(char ch) {
    return ch - BASE_LETTER;
}

void insert(Node *root, char *str) {
    Node *p = root;
    for (int i = 0; str[i]; i++) {
        if (p->next[code(str[i])] == NULL) p->next[code(str[i])] = get_new_node();
        p = p->next[code(str[i])];
    }
    p->flag = 1;
    return ;
}

int query(Node *root, char *str) {
    Node *p = root;
    for (int i = 0; str[i]; i++) {
        p = p->next[code(str[i])];
        if (p == NULL) return 0;
    }
    return p->flag;
}

void output(Node *root, int k, char *buff) {
    if (root == NULL) return ;
    if (root->flag) printf("%s\n", buff);
    for (int i = 0; i < BASE; i++) {
        buff[k] = BASE_LETTER + i;
        buff[k + 1] = '\0';
        output(root->next[i], k + 1, buff);
    }
    return ;
}

void clear(Node *root) {
    if (root == NULL) return ;
    for (int i = 0; i < BASE; i++) {
        clear(root->next[i]);
    }
    return ;
}

int main() {
    char str[1000];
    int n;
    scanf("%d", &n);
    Node *root = get_new_node();
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        insert(root, str);
    }
    output(root, 0, str);
    while (~scanf("%s", str)) {
        printf("query %s, result = %s\n", str, query(root, str) ? "Yes" : "No");
    }
    return 0;
}
