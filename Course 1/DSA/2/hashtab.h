#pragma once
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHTAB_SIZE 2000003

struct listnode {
    char* key;
    int value;
    struct listnode* next;
};

struct listnode* hashtab[HASHTAB_SIZE];

unsigned int hashtab_hash(char* key);
void hashtab_init(struct listnode** hashtab);
void hashtab_add_KP(struct listnode** hashtab, char* key, int value);
struct listnode* hashtab_lookup_KP(struct listnode** hashtab, char* key);
void hashtab_delete_KP(struct listnode** hashtab, char* key);
void hashtab_delete_ELF(struct listnode** hashtab, char* key);
int hashtab_collisions(struct listnode** hashtab);
void hashtab_add_ELFHash(struct listnode** hashtab, char* key, int value);
struct listnode* hashtab_lookup_ELFHash(struct listnode** hashtab, char* key);
void hashtab_add_ELFHash(struct listnode** hashtab, char* key, int value);
