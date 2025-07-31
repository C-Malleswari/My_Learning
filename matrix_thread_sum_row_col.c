#include <stdio.h>
#include <pthread.h>

#define SIZE 3

int matrix[SIZE][SIZE] =
{
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};

void* row_sum(void* arg)
{
    for (int i = 0; i < SIZE; i++)
    {
        int sum = 0;
        for (int j = 0; j < SIZE; j++)
        {
            sum += matrix[i][j];
        }
        printf("Row %d sum = %d\n", i, sum);
    }
    pthread_exit(NULL);
}

void* column_sum(void* arg)
{
    for (int j = 0; j < SIZE; j++)
    {
        int sum = 0;
        for (int i = 0; i < SIZE; i++)
        {
            sum += matrix[i][j];
        }
        printf("Column %d sum = %d\n", j, sum);
    }
    pthread_exit(NULL);
}

int main()
{
    pthread_t t1, t2;

    pthread_create(&t1, NULL, row_sum, NULL);
    pthread_create(&t2, NULL, column_sum, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* row(void* arg) {
    int* (arr)[3] = (int (*)[3]) arg;
    int sum = 0;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            sum += arr[i][j];
        }
        printf("Row %d sum = %d\n", i, sum);
    }

    return NULL;
}


void* col(void* arg) {
    int* (arr)[3] = (int (*)[3]) arg;
	int sum = 0;
    for (int j=0; j<3; j++) {
        for (int i=0; i<3; i++) {
            sum += arr[i][j];
        }
        printf("Column %d sum = %d\n", j, sum);
    }

    return NULL;
}

int main() {
    pthread_t t1, t2;

    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    pthread_create(&t1,NULL,row,matrix);
    pthread_create(&t2,NULL,col,matrix);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}*/
