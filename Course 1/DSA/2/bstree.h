#pragma once
#include <stdio.h>
#define NEW_LINE printf("\n")

typedef struct bstree {
    int value;
    char* key;
    struct bstree* left;
    struct bstree* right;
} bstree;

bstree* bstree_create(char* key, int value);
void bstree_add(bstree* tree, char* key, int value);
bstree* bstree_lookup(bstree* tree, char* key);
bstree* bstree_delete(bstree* tree, char* key);
bstree* bstree_min(bstree* tree);
bstree* bstree_max(bstree* tree);
bstree* delete_node(bstree* tree, bstree* node, bstree* parent);
void replace_node(bstree* parent, bstree* node, bstree* child);
