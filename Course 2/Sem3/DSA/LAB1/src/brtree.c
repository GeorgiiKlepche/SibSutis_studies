#include "brtree.h"

struct rbtree EmptyNode = {0, 0, COLOR_BLACK, NULL, NULL, NULL};
struct rbtree *NullNode = &EmptyNode;

struct rbtree *rbtree_create(struct rbtree *parent, int key, char *value)
{
    struct rbtree *node;

    node = (struct rbtree*) malloc(sizeof(*node));
    if (node != NULL) {
        node->key = key;
        node->value = value;

        node->color = COLOR_RED; /* красный */
        node->parent = parent;
        node->left = NullNode;
        node->right = NullNode;
    }
    else
      return NULL;
    return node;
}

struct rbtree *rbtree_add(struct rbtree *root, int key, char *value)
{
    struct rbtree *node, *parent = NullNode;

    /* Отыскиваем листовой узел */
    for (node = root; node != NullNode && node != NULL;) {
      parent = node;
      if (key < node->key)
          node = node->left;
      else if (key > node->key)
          node = node->right;
      else
          return root;
    }

    /* Создаем элемент и связываем с узлом */
    node = rbtree_create(parent, key, value);
    if (parent != NullNode) {
	    if (key < parent->key)
	        parent->left = node;
        else
	        parent->right = node;
    }
    else
	    root = node;
    root = rbtree_fixup_add(root, node);
    return root;
}

struct rbtree *rbtree_fixup_add(struct rbtree *root, struct rbtree *node) {
    struct rbtree *uncle;

    /* Current node is RED */
    while (node != root &&
           node->parent->color == COLOR_RED) {
      if (node->parent ==
          node->parent->parent->left) {
          /* Node in left tree of grandfather */
          uncle = node->parent->parent->right;
          if (uncle->color == COLOR_RED) {
            /* Case 1 - uncle is RED */
            node->parent->color = COLOR_BLACK;
            uncle->color = COLOR_BLACK;
            node->parent->parent->color = COLOR_RED;
            node = node->parent->parent;
          }
          else {
            /* Cases 2 & 3 - uncle is BLACK */
            if (node == node->parent->right) {
            /* Reduce case 2 to case 3 */
            node = node->parent;
            root = rbtree_left_rotate(root, node);
            }
            /* Case 3 */
            node->parent->color = COLOR_BLACK;
            node->parent->parent->color = COLOR_RED;
            root = rbtree_right_rotate(root,
            node->parent->parent);
          }
      }
      else {
        /*
        * Node in right tree of grandfather
        *
        * Cases 4, 5, 6 - node in right tree
        * of grandfather
        */
        uncle = node->parent->parent->left;
        if (uncle->color == COLOR_RED) {
          /* Uncle is RED – case 4 */
          node->parent->color = COLOR_BLACK;
          uncle->color = COLOR_BLACK;
          node->parent->parent->color = COLOR_RED;
          node = node->parent->parent;
        }
        else {
          /* Uncle is BLACK */
          if (node == node->parent->left) {
            node = node->parent;
            root = rbtree_right_rotate(root, node);
          }
          node->parent->color = COLOR_BLACK;
          node->parent->parent->color = COLOR_RED;
          root = rbtree_left_rotate(root, node->parent->parent);
        }
      }
    }
    root->color = COLOR_BLACK;
    return root;
}

struct rbtree *rbtree_left_rotate(struct rbtree *root, struct rbtree *node)
{
    struct rbtree *right = node->right;
    /* Create node->right link */
    node->right = right->left;
    if (right->left != NullNode)
        right->left->parent = node;
    /* Create right->parent link */
    if (right != NullNode)
        right->parent = node->parent;
    if (node->parent != NullNode) {
        if (node == node->parent->left)
            node->parent->left = right;
        else
            node->parent->right = right;
    }
    else {
        root = right;
    }
    right->left = node;
    if (node != NullNode)
        node->parent = right;
    return root;
}

struct rbtree *rbtree_right_rotate(struct rbtree *root, struct rbtree *node)
{
    struct rbtree *left = node->left;
    /* Create node->left link */
    node->left = left->right;
    if (left->right != NullNode)
        left->right->parent = node;
    /* Create left->parent link */
    if (left != NullNode)
        left->parent = node->parent;
    if (node->parent != NullNode) {
        if (node == node->parent->right)
            node->parent->right = left;
        else
            node->parent->left = left;
    }
    else {
        root = left;
    }
    left->right = node;
    if (node != NullNode)
        node->parent = left;
    return root;
}

struct rbtree *rbtree_delete(struct rbtree *root, int key)
{
    struct rbtree *z, *y, *x;
    z = rbtree_lookup(root, key);
    if ((z == NULL) || (z == NullNode))
        return root;
    y = z;
    int y_color = y->color;
    if (z->left == NullNode || z->left == NULL) {
        /* Нет левого поддерева */
        x = z->right;
        root = rbtree_transplant(root, z, z->right);
    }
    else if (z->right == NullNode || z->right == NULL) {
        /* Нет правого поддерева */
        x = z->left;
        root = rbtree_transplant(root, z, z->left);
    }
    else {
        /*Узел z имеет оба поддерева */
        y = rbtree_min(z->right);
        y_color = y->color;
        x = y->right;
        if (y->parent == z) {
            x->parent = y;
        }
        else {
            root = rbtree_transplant(root, y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        root = rbtree_transplant(root, z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }
    if (y_color == COLOR_BLACK)
        root = rbtree_fixup_delete(root, x);
    free(z);
    return root;
}

struct rbtree *rbtree_lookup(struct rbtree *tree, int key)
{
    while (tree != NULL) {
        if (key == tree->key) {
            return tree;
        } else if (key < tree->key) {
            tree = tree->left;
        } else {
            tree = tree->right;
        }
    }
    return tree;
}

struct rbtree *rbtree_transplant(struct rbtree *root, struct rbtree *u, struct rbtree *v)
{
    if ((u->parent == NULL) || (u->parent == NullNode))
        root = v;
    else if (u == u->parent->left)
        u->parent->left = v;
    else
        u->parent->right = v;
    v->parent = u->parent;
    return root;
}

struct rbtree *rbtree_fixup_delete(struct rbtree *root, struct rbtree *x)
{
    struct rbtree *w;
    while ((x != root) && (x->color == COLOR_BLACK)) {
        if (x == x->parent->left) {
            w = x->parent->right;
            if (w->color == COLOR_RED) {
                w->color = COLOR_BLACK;
                x->parent->color = COLOR_RED;
                root = rbtree_left_rotate(root, x->parent);
                w = x->parent->right;
            }
            if ((w->left->color == COLOR_BLACK) && (w->right->color == COLOR_BLACK)) {
                w->color = COLOR_RED;
                x = x->parent;
            }
            else {
                if (w->right->color == COLOR_BLACK) {
                    w->left->color = COLOR_BLACK;
                    w->color = COLOR_RED;
                    root = rbtree_right_rotate(root, w);
                    w = x->parent->right;
                }
                w->color = x->parent->color;
                x->parent->color = COLOR_BLACK;
                w->right->color = COLOR_BLACK;
                root = rbtree_left_rotate(root, x->parent);
                x = root;
            }
        }
        else {
            w = x->parent->left;
            if (w->color == COLOR_RED) {
                w->color = COLOR_BLACK;
                x->parent->color = COLOR_RED;
                root = rbtree_right_rotate(root, x->parent);
                w = x->parent->left;
            }
            if ((w->right->color == COLOR_BLACK) && (w->left->color == COLOR_BLACK)) {
                w->color = COLOR_RED;
                x = x->parent;
            }
            else {
                if (w->left->color == COLOR_BLACK) {
                    w->right->color = COLOR_BLACK;
                    w->color = COLOR_RED;
                    root = rbtree_left_rotate(root, w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = COLOR_BLACK;
                w->left->color = COLOR_BLACK;
                root = rbtree_right_rotate(root, x->parent);
                x = root;
            }
        }
    }
    x->color = COLOR_BLACK;
    return root;
}

struct rbtree *rbtree_min(struct rbtree *tree)
{
    if (tree == NULL)
        return NULL;

    while ((tree->left != NULL) && (tree->left != NullNode))
        tree = tree->left;
    return tree;
}

struct rbtree *rbtree_max(struct rbtree *tree)
{
    if (tree == NULL)
        return NULL;

    while ((tree->right != NULL) && (tree->right != NullNode))
        tree = tree->right;
    return tree;
}
void tree_print(struct rbtree *tree)
{
    tree_print_dfs(tree, 80, 30);
    printf("\n\n");
}
void tree_print_dfs(struct rbtree *tree, int indent, int width)
{
    int i;
    if ((tree == NULL) || (tree == NullNode))
        return;

    if (tree->parent != NULL) {
        if (tree == tree->parent->right) {
            indent += width;
            width -= 9;
        }
        else {
            indent -= width;
            width -= 9;
        }
    }

    for (i = 0; i < indent; i++)
        printf(" ");
    if (tree-> color == COLOR_RED)
        printf("%s %d %s\n", RED, tree->key, RESET);
    else
        printf("%s %d %s\n", BLUE, tree->key, RESET);



    tree_print_dfs(tree->left, indent, width);
    tree_print_dfs(tree->right, indent, width);

}
void rbtree_free(struct rbtree *tree)
{
    if ((tree->left != NULL) && (tree->left != NullNode)) {
        rbtree_free(tree->left);
    }
    if ((tree->right != NULL) && (tree->right != NullNode)) {
        rbtree_free(tree->right);
    }
    free(tree);
}
