#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int getrand(int min, int max)
{
    return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}

double wtime() //функция берущая системное время
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

//---------------------------------------------------------------------------
void counting(int mass[], int prom[], int shir) // counting sort
{
    int i = 0, b = 0, j = 0;
    double start, end;
    start = wtime();
    for (i = 0; i < shir; i++) {
        prom[mass[i]] += 1;
    }
    for (j = 0; j < 100001; j++) {
        for (i = 0; i < prom[j]; i++) {
            mass[b] = j;
            b++;
        }
    }
    end = wtime();
    printf("%d - %f\n", shir, (end - start));
}

//---------------------------------------------------------------------------
void bubble(int mass[], int shir) // bubble sort
{
    double start, end, prom;
    start = wtime();
    for (int i = 0; i < shir - 1; i++) {
        for (int b = 0; b < shir - i - 1; b++) {
            if (mass[b] > mass[b + 1]) {
                prom = mass[b];
                mass[b] = mass[b + 1];
                mass[b + 1] = prom;
            }
        }
    }
    end = wtime();
    printf("%d - %f\n", shir, (end - start));
}

//---------------------------------------------------------------------------
void heapify(int arr[], int shir, int i) //вспомогательная функция для heap sort
{
    int largest = i, temp;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < shir && arr[l] > arr[largest]) {
        largest = l;
    }

    if (r < shir && arr[r] > arr[largest]) {
        largest = r;
    }

    if (largest != i) {
        temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, shir, largest);
    }
}

void heap(int arr[], int shir) // heap sort
{
    double start, end;
    start = wtime();

    int temp;
    for (int i = shir / 2 - 1; i >= 0; i--) {
        heapify(arr, shir, i);
    }

    for (int i = shir - 1; i >= 0; i--) {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }

    end = wtime();
    printf("%d - %f\n", shir, (end - start));
}

//---------------------------------------------------------------------------
int main()
{
    int shir, prom[100001];
    int i = 0;
    printf("counting:\n");
    for (shir = 50000; shir <= 1000000; shir += 50000) {
        int mass[shir];
        for (i = 0; i < shir; i++) //заполнение сортируемого массива
        {
            mass[i] = getrand(0, 100000);
        }

        for (i = 0; i < 100001; i++) //зануление вспомогательного массива
        {
            prom[i] = 0;
        }
        counting(mass, prom, shir);
    }

    printf("bubble:\n");
    for (shir = 50000; shir <= 1000000; shir += 50000) {
        int mass[shir];
        for (i = 0; i < shir; i++) //заполнение сортируемого массива
        {
            mass[i] = getrand(0, 100000);
        }
        bubble(mass, shir);
    }

    printf("heap:\n");
    for (shir = 50000; shir <= 1000000; shir += 50000) {
        int mass[shir];
        for (i = 0; i < shir; i++) //заполнение сортируемого массива
        {
            mass[i] = getrand(0, 100000);
        }
        heap(mass, shir);
    }
}
