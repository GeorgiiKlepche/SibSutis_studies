#ifndef RBTREE_H
#define RBTREE_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define COLOR_RED 0
#define COLOR_BLACK 1


#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define BLUE "\033[34m"

struct rbtree {
    int key;            /* Ключ */
    char *value;		/* Данные */
    int color;			/* Цвет */

    struct rbtree *parent;
    struct rbtree *left;
    struct rbtree *right;
};

typedef struct rbtree rbtree;

rbtree *rbtree_create(rbtree *parent, int key, char *value);
rbtree *rbtree_add(rbtree *tree, int key, char *value);
rbtree *rbtree_fixup_add(rbtree *root, rbtree *node);
rbtree *rbtree_left_rotate(rbtree *root, rbtree *node);
rbtree *rbtree_right_rotate(rbtree *root, rbtree *node);
rbtree *rbtree_delete(rbtree *root, int key);
rbtree *rbtree_fixup_delete(rbtree *root, rbtree *x);
rbtree *rbtree_transplant(rbtree *root, rbtree *u, rbtree *v);
rbtree *rbtree_lookup(rbtree *tree, int key);
rbtree *rbtree_min(rbtree *tree);
rbtree *rbtree_max(rbtree *tree);
void tree_print(rbtree *tree);
void tree_print_dfs(rbtree *tree, int indent, int width);
void rbtree_free(rbtree *tree);

#endif
