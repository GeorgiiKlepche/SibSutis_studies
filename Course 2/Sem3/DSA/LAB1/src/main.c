#include "brtree.h"

int main()
{
    struct rbtree *tree = NULL;
    tree = rbtree_add(tree, 10, (char *) "10");
    tree_print(tree);
    printf("_______________________________________\n");
    tree = rbtree_add(tree, 5, (char *) "5");
    tree_print(tree);
    printf("_______________________________________\n");
    tree = rbtree_add(tree, 3, (char *) "3");
    tree_print(tree);
    printf("_______________________________________\n");
    tree = rbtree_add(tree, 11, (char *) "11");
    tree_print(tree);
    printf("_______________________________________\n");
    tree = rbtree_add(tree, 12, (char *) "12");
    tree_print(tree);
    printf("_______________________________________\n");
    tree = rbtree_add(tree, 6, (char *) "6");
    tree_print(tree);
    printf("_______________________________________\n");
    tree = rbtree_add(tree, 8, (char *) "8");
    tree_print(tree);
    printf("_______________________________________\n");
    tree = rbtree_add(tree, 9, (char *) "9");
    tree_print(tree);
    printf("_______________________________________\n");
    printf("_______________________________________\n");
    printf("_______________________________________\n");
    printf("_______________________________________\n");

    tree = rbtree_delete(tree, 10);
    tree_print(tree);
    printf("_______________________________________\n");
    tree = rbtree_delete(tree, 5);
    tree_print(tree);
    printf("_______________________________________\n");
    tree = rbtree_delete(tree, 8);
    tree_print(tree);
    printf("_______________________________________\n");

    rbtree *look = rbtree_lookup(tree, 3);

    printf("%d", look->key);

    rbtree_free(tree);
    return 0;
}
