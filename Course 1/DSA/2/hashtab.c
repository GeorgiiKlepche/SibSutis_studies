#include "hashtab.h"

unsigned int Hash_KP(char* s)
{
    unsigned int h = 0, hash_mul = 31;

    while (*s) {
        h = h * hash_mul + (unsigned int)*s++;
    }
    return h % HASHTAB_SIZE;
}

unsigned int ELFHash(char* s)
{
    unsigned int h = 0, g;
    while (*s) {
        h = (h << 4) + (unsigned int)*s++;
        g = h & 0xF0000000L;
        if (g)
            h ^= g >> 24;
        h &= ~g;
    }
    return h % HASHTAB_SIZE;
}

void hashtab_init(struct listnode** hashtab)
{
    int i;

    for (i = 0; i < HASHTAB_SIZE; i++) {
        hashtab[i] = NULL;
    }
}

void hashtab_add_KP(struct listnode** hashtab, char* key, int value)
{
    struct listnode* node;

    int index = Hash_KP(key);
    node = malloc(sizeof(*node));
    if (node != NULL) {
        node->key = key;
        node->value = value;
        node->next = hashtab[index];
        hashtab[index] = node;
    }
}

void hashtab_add_ELFHash(struct listnode** hashtab, char* key, int value)
{
    struct listnode* node;

    unsigned int index = ELFHash(key);
    node = malloc(sizeof(*node));
    if (node != NULL) {
        node->key = key;
        node->value = value;
        node->next = hashtab[index];
        hashtab[index] = node;
    }
}

struct listnode* hashtab_lookup_KP(struct listnode** hashtab, char* key)
{
    struct listnode* node;

    int index = Hash_KP(key);
    for (node = hashtab[index]; node != NULL; node = node->next) {
        if (strcmp(node->key, key) == 0) {
            return node;
        }
    }
    return NULL;
}

struct listnode* hashtab_lookup_ELFHash(struct listnode** hashtab, char* key)
{
    struct listnode* node;

    int index = ELFHash(key);
    for (node = hashtab[index]; node != NULL; node = node->next) {
        if (strcmp(node->key, key) == 0) {
            return node;
        }
    }
    return NULL;
}

void hashtab_delete_KP(struct listnode** hashtab, char* key)
{
    struct listnode *node, *prev = NULL;
    int index = Hash_KP(key);
    for (node = hashtab[index]; node != NULL; node = node->next) {
        if (strcmp(node->key, key) == 0) {
            if (prev == NULL) {
                hashtab[index] = node->next;
            } else {
                prev->next = node->next;
            }
            free(node);
            return;
        }
        prev = node;
    }
}

void hashtab_delete_ELF(struct listnode** hashtab, char* key)
{
    struct listnode *node, *prev = NULL;
    int index = ELFHash(key);
    for (node = hashtab[index]; node != NULL; node = node->next) {
        if (strcmp(node->key, key) == 0) {
            if (prev == NULL) {
                hashtab[index] = node->next;
            } else {
                prev->next = node->next;
            }
            free(node);
            return;
        }
        prev = node;
    }
}

int hashtab_collisions(struct listnode** hashtab)
{
    int collisions = 0, i;
    struct listnode* node;

    for (i = 0; i < HASHTAB_SIZE; i++) {
        for (node = hashtab[i]; node != NULL; node = node->next) {
            if (node->next != NULL) {
                collisions++;
            }
        }
    }
    return collisions;
}
