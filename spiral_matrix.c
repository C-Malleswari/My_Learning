Problem Statement:

Write a C program to read a 4x4 matrix of integers from the user and then print the matrix elements in spiral order, starting from the top-left corner and moving in a clockwise direction.
Example Input:
1  2  3  4
5  6  7  8
9 10 11 12
13 14 15 16
Expected Output:
Original Matrix:
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16

Spiral Order:
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
	*/



#include<stdio.h>
#define SIZE 4

void spiralmatrix(int matrix[SIZE][SIZE], int n) 
{
	int top_line = 0, bottom_line = n - 1;
    	int left_side = 0, right_side = n - 1;
        int i;
    	while (top_line <= bottom_line && left_side <= right_side) 
    	{
        	for (i = left_side; i <= right_side; i++)
            		printf("%d ", matrix[top_line][i]);
        		top_line++;

        	for (i = top_line; i <= bottom_line; i++)
            		printf("%d ", matrix[i][right_side]);
      	 		right_side--;

      		if (top_line <= bottom_line) 
		{
            		for (i = right_side; i >= left_side; i--)
                		printf("%d ", matrix[bottom_line][i]);
            		bottom_line--;
        	}

        	if (left_side <= right_side) 
		{
            		for (i = bottom_line; i >= top_line; i--)
                		printf("%d ", matrix[i][left_side]);
            		left_side++;
        	}	
    	}
}

int main() 
{
    int matrix[SIZE][SIZE] = 
    {
        {1,  2,  3,  4},
        {5,  6,  7,  8},
        {9, 10, 11, 12},
        {13,14, 15,16}
    };
    printf("spiral order: ");
    spiralmatrix(matrix, SIZE);
}
int main()
{
	int matrix[SIZE][SIZE];
	printf("enter the %d x %d matrix\n",SIZE,SIZE);
	for(int i=0;i<SIZE;i++)
	{
		for(int j=0;j<SIZE;j++)
		{
			scanf("%d",&matrix[i][j]);
		}
		printf("\n");
	}
	for(int i=0;i<SIZE;i++)
        {
                for(int j=0;j<SIZE;j++)
                {
                        printf("%d",&matrix[i][j]);
                }
                printf("\n");
	}
	spiralmatrix(matrix,SIZE);
}

