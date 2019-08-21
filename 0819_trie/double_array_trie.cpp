/*************************************************************************
	> File Name: double_array_trie.cpp
	> Author: sudingquan
	> Mail: 1151015256@qq.com
	> Created Time: 三  8/21 14:14:43 2019
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define BASE 26
#define BEGIN_LETTER 'a'

typedef struct Node {
    int flag;
    struct Node *next[BASE];
} Node;

typedef struct DATrie {
    int *base, *check;
    int root, size;
} DATrie;

DATrie *get_datrie(int n) {
    DATrie *tree = (DATrie *)calloc(sizeof(DATrie), 1);
    tree->root = 1;
    tree->size = n;
    tree->base = (int *)calloc(sizeof(int), n);
    tree->check = (int *)calloc(sizeof(int), n);
    tree->check[tree->root] = 1;
    return tree;
}

Node *get_new_node() {
    Node *p = (Node *)calloc(sizeof(Node), 1);
    return p;
}

int insert(Node *root, const char *str) {
    int cnt = 0;
    Node *p = root;
    for (int i = 0; str[i]; i++) {
        int ind = str[i] - BEGIN_LETTER;
        if (p->next[ind] == NULL) p->next[ind] = get_new_node(), cnt += 1;
        p = p->next[ind];
    }
    p->flag = 1;
    return cnt;
}

void clear(Node *root) {
    if (root == NULL) return ;
    for (int i = 0; i < BASE; i++) {
        clear(root->next[i]);
    }
    free(root);
    return ;
}

int get_base_value(Node *root, DATrie *tree) {
    int base = 1, flag;
    do {
        flag = 1;
        base += 1;
        for (int i = 0; i < BASE; i++) {
            if (root->next[i] == NULL) continue;
            if (tree->check[base + i] == 0) continue;
            flag = 0;
            break;
        }
    } while (!flag);
    return base;
}

int build_datrie(int ind, Node *root, DATrie * tree) {
    int base = tree->base[ind] = get_base_value(root, tree);
    int ans = ind;
    for (int i = 0; i < BASE; i++) {
        if (root->next[i] == NULL) continue;
        tree->check[base + i] = ind;
    }
    for (int i = 0; i < BASE; i++) {
        if (root->next[i] ==  NULL) continue;
        int temp = build_datrie(base + i, root->next[i], tree);
        if (temp > ans) ans = temp;
    }
    if (root->flag) tree->check[ind] = -tree->check[ind];
    return ans;
}

int query(DATrie *tree, const char *str) {
    int p = tree->root;
    for (int i = 0; str[i]; i++) {
        int ind = str[i] - BEGIN_LETTER;
        if (abs(tree->check[tree->base[p] + ind]) != p) return 0;
        p = tree->base[p] + ind;
    }
    return tree->check[p] < 0;
}

void clear_da(DATrie * tree) {
    if (tree == NULL) return ;
    free(tree->base);
    free(tree->check);
    free(tree);
    return ;
}

int main() {
    int n, cnt1 = 1, cnt2;
    char str[100];
    scanf("%d", &n);
    Node *root = get_new_node();
    while (n--) {
        scanf("%s", str);
        cnt1 += insert(root, str);
    }
    DATrie *tree = get_datrie(cnt1 * BASE + 5);
    cnt2 = build_datrie(tree->root, root, tree) + 1;
    while (~scanf("%s", str)) {
        printf("search %s, result = %s\n", str, query(tree, str) ? "YES" : "NO");
    }
    int mem1 = cnt1 * sizeof(Node), mem2 = cnt2 * sizeof(int) * 2 + sizeof(int) * 2;
    printf("Trie memory : %d bytes\n", mem1);
    printf("Double Array Trie memory : %d bytes\n", mem2);
    printf("memory rate : %.4lf%%\n", 1.0 * mem2 / mem1 * 100);
    clear_da(tree);
    clear(root);
    return 0;
}
