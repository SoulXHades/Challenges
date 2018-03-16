#include <stdio.h>
#define SIZE 100
void compress2D(int data[SIZE][SIZE], int rowSize, int colSize);
int main()
{
   int data[SIZE][SIZE];
   int i,j;
   int rowSize, colSize;

   printf("Enter the array size (rowSize, colSize): \n");
   scanf("%d %d", &rowSize, &colSize);
   printf("Enter the matrix (%dx%d): \n", rowSize, colSize);
   for (i=0; i<rowSize; i++)
      for (j=0; j<colSize; j++)
         scanf("%d", &data[i][j]);
   printf("compress2D(): \n");
   compress2D(data, rowSize, colSize);
   return 0;
}
void compress2D(int data[SIZE][SIZE], int rowSize, int colSize)
{
   int row, col, bit, num;

   for(row=0; row<rowSize; row++)
   {
       //initialize with 1st column data since no need to compare
       bit = data[row][0];
       num = 1;

       for(col=1; col<colSize; col++)
       {
           if(data[row][col] == bit)
            ++num;
           else
           {
               //output compress matrix without assigning to new array
               printf("%d %d ", bit, num);

               //change bit
               bit = 1 - bit;
               //reset number of bit
               num = 1;
           }
       }

       //output compress matrix without assigning to new array
       printf("%d %d\n", bit, num);
   }
}
