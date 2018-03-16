#include <stdio.h>
void swapMinMax1D(int ar[], int size);
int main()
{
 int ar[50],i,size;

 printf("Enter array size: \n");
 scanf("%d", &size);
 printf("Enter %d data: \n", size);
 for (i=0; i<size; i++)
 scanf("%d",ar+i);
 swapMinMax1D(ar, size);
 printf("swapMinMax1D(): ");
 for (i=0; i<size; i++)
 printf("%d ",*(ar+i));
 return 0;
}
void swapMinMax1D(int ar[], int size)
{
 //i is count
 //max_pos is position of latest max num
 //min_pos2 is position of latest min num
 //temp is for swapping of variable
 int i, max_pos, min_pos, temp;

 if(ar[0] > ar[1])
 {
     max_pos = 0;
     min_pos = 1;
 }
 else
 {
     max_pos = 1;
     min_pos = 0;
 }

 for(i=2; i<size; i++)
 {
     if(ar[i] >= ar[max_pos])
     {
         if(ar[min_pos] == ar[max_pos])
            min_pos = max_pos;

         max_pos = i;
     }
     else if(ar[i] <= ar[min_pos])
        min_pos = i;
 }

 temp = ar[max_pos];
 ar[max_pos] = ar[min_pos];
 ar[min_pos] = temp;
}
