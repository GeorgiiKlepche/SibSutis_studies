#include "bstree.h"
#include "hashtab.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#define MAX_WORD 155
#define EXP(x)                                                                        \
    printf("===============================================\nЭксперимент " \
           "№%d:\n",                                                                  \
           x)

int getrand(int min, int max)
{
    return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}

double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

char* get_word(FILE* file)
{
    char word[MAX_WORD];
    int i, k = 0;
    fgets(word, MAX_WORD, file);
    for (i = 0; word[i] != '\n'; i++) {
        k++;
    }
    char* word_1 = malloc(k * sizeof(char));
    for (i = 0; word[i] != '\n'; i++) {
        word_1[i] = word[i];
    }
    return word_1;
}

int main()
{
    system("clear");
    int collis = 0;
    int n = 200000, i;
    int flag;
    char* words[n];
    char* key = NULL;
    char* w = NULL;
    double t, t_1, t_2;
    FILE* file;
    file = fopen("text.txt", "r");
    if (file == NULL) {
        printf("словарь не открылся\n");
        return 1;
    }
    for (i = 0; i < n; i++) {
        key = get_word(file);
        if (key == NULL) {
            printf("слово не считано\n");
            return 1;
        }
        words[i] = key;
    }
    flag = fclose(file);
    if (flag != 0) {
        printf("словарь не закрылся\n");
        return 1;
    }
    EXP(1);
    {
        printf("Bstree:\n");
        bstree* tree = bstree_create(words[0], 0);
        bstree* node = NULL;
        for (i = 1; i <= n; i++) {
            bstree_add(tree, words[i - 1], i - 1);
            if ((i % 10000) == 0) {
                w = words[getrand(0, i - 1)];
                t_1 = wtime();
                node = bstree_lookup(tree, w);
                if (node == NULL) {
                    printf("EROR: lookup\n");
                    return 1;
                }
                t_2 = wtime();
                t = t_2 - t_1;
                printf("%-6d - %.6lf\n", i, t);
            }
        }

        printf("Hashtab:\n");
        hashtab_init(hashtab);
        struct listnode* node_ht = NULL;

        for (int i = 1; i <= n; i++) {
            hashtab_add_KP(hashtab, words[i - 1], i - 1);
            if ((i % 10000) == 0) {
                w = words[getrand(0, i - 1)];
                t_1 = wtime();
                node_ht = hashtab_lookup_KP(hashtab, w);
                if (node_ht == NULL) {
                    printf("EROR: lookup\n");
                    return 1;
                }
                t_2 = wtime();
                t = t_2 - t_1;
                printf("%-6d - %.6lf\n", i, t);
            }
        }
        free(tree);
        free(node);
        free(node_ht);
    }
    /*----------------------------------------------------------*/
    EXP(2);
    {
        printf("Bstree:\n");
        bstree* tree = bstree_create(words[0], 0);
        bstree* node = NULL;
        for (i = 1; i <= n; i++) {
            t_1 = wtime();
            bstree_add(tree, words[i - 1], i - 1);
            if ((i % 10000) == 0) {
                t_1 = wtime();
                bstree_add(tree, words[i - 1], i - 1);
                t_2 = wtime();
                t = t_2 - t_1;
                printf("%-6d - %.6lf\n", i, t);
            }
        }

        printf("Hashtab:\n");
        hashtab_init(hashtab);
        struct listnode* node_ht = NULL;

        for (int i = 1; i <= n; i++) {
            hashtab_add_KP(hashtab, words[i - 1], i - 1);
            if ((i % 10000) == 0) {
                if ((i % 10000) == 0) {
                    t_1 = wtime();
                    hashtab_add_KP(hashtab, words[i - 1], i - 1);
                    t_2 = wtime();
                    t = t_2 - t_1;
                    printf("%-6d - %.6lf\n", i, t);
                }
            }
        }
        free(tree);
        free(node);
        free(node_ht);
    }
    /*----------------------------------------------------------*/
    EXP(6);
    {
        collis = 0;
        printf("Hash KP\n");
        hashtab_init(hashtab);
        struct listnode* node_ht_6 = NULL;
        for (int i = 1; i <= n; i++) {
            hashtab_add_KP(hashtab, words[i - 1], i - 1);
            if ((i % 10000) == 0) {
                w = words[getrand(0, i - 1)];
                t_1 = wtime();
                node_ht_6 = hashtab_lookup_KP(hashtab, w);
                if (node_ht_6 == NULL) {
                    printf("EROR: lookup\n");
                    return 1;
                }
                t_2 = wtime();
                t = t_2 - t_1;
                collis = hashtab_collisions(hashtab);
                printf("n = %d;\t time = %.6lf;\t collisions = %d\n",
                       i,
                       t,
                       collis);
            }
        }
        printf("ELFHash\n");
        hashtab_init(hashtab);
        node_ht_6 = NULL;
        for (int i = 1; i <= n; i++) {
            hashtab_add_ELFHash(hashtab, words[i - 1], i - 1);
            if ((i % 10000) == 0) {
                w = words[getrand(0, i - 1)];
                t_1 = wtime();
                node_ht_6 = hashtab_lookup_ELFHash(hashtab, w);
                if (node_ht_6 == NULL) {
                    printf("EROR: lookup\n");
                    return 1;
                }
                t_2 = wtime();
                t = t_2 - t_1;
                collis = hashtab_collisions(hashtab);
                printf("n = %d;\t time = %.6lf;\t collisions = %d\n",
                       i,
                       t,
                       collis);
            }
        }
    }

    return 0;
}
