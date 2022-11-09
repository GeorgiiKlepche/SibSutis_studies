#include "bstree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void count(bstree* tree, int* k)
{
    if (tree != NULL) {
        count(tree->right, k);
        (*k)++;
        count(tree->left, k);
    }
}

bstree* bstree_create(char* key, int value)
{
    bstree* node = malloc(sizeof(bstree));
    if (node != NULL) {
        node->key = key;
        node->value = value;
        node->left = NULL;
        node->right = NULL;
    }
    return node;
}

void bstree_add(bstree* tree, char* key, int value)
{
    bstree* parent = NULL;
    while (tree != NULL) {
        parent = tree;
        if (strcmp(key, tree->key) < 0) {
            tree = tree->left;
        } else if (strcmp(key, tree->key) > 0) {
            tree = tree->right;
        } else {
            return;
        }
    }
    bstree* node = bstree_create(key, value);
    if (strcmp(key, parent->key) < 0) {
        parent->left = node;
    } else {
        parent->right = node;
    }
}

bstree* bstree_lookup(bstree* tree, char* key)
{
    while (tree != NULL) {
        if (strcmp(key, tree->key) < 0) {
            tree = tree->left;
        } else if (strcmp(key, tree->key) > 0) {
            tree = tree->right;
        } else {
            return tree;
        }
    }
    return NULL;
}

void replace_node(bstree* parent, bstree* node, bstree* child)
{
    if (parent != NULL) {
        if (strcmp(node->key, parent->key) < 0) {
            parent->left = child;
        } else {
            parent->right = child;
        }
    }
}

bstree* delete_node(bstree* tree, bstree* node, bstree* parent)
{
    if (node->left == NULL) {
        replace_node(parent, node, node->right);
        if (parent == NULL) {
            tree = node->right;
        }
    } else if (node->right == NULL) {
        replace_node(parent, node, node->left);
        if (parent == NULL) {
            tree = node->left;
        }
    } else {
        bstree* min = node->right;
        bstree* minparent = min;
        while (min->left != NULL) {
            minparent = min;
            min = min->left;
        }
        replace_node(parent, node, min);
        if (parent == NULL) {
            tree = min;
        }
        if (node->right != min) {
            minparent->left = min->right;
            min->left = node->left;
            min->right = node->right;
        } else {
            min->left = node->left;
        }
    }
    free(node);
    return tree;
}

bstree* bstree_delete(bstree* tree, char* key)
{
    bstree* parent = NULL;
    bstree* node = tree;
    while ((node != NULL) && (strcmp(node->key, key) != 0)) {
        parent = node;
        if (strcmp(key, node->key) < 0) {
            node = node->left;
        } else {
            node = node->right;
        }
    }
    if (node == NULL) {
        return tree;
    }
    return delete_node(tree, node, parent);
}

bstree* bstree_min(bstree* tree)
{
    while (tree->left != NULL) {
        tree = tree->left;
    }
    return tree;
}

bstree* bstree_max(bstree* tree)
{
    while (tree->right != NULL) {
        tree = tree->right;
    }
    return tree;
}
