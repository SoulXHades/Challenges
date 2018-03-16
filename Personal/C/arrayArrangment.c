/*
*** Credit to @iReivax1 for creating this question. ***

Given an array of integers, sort the array according to frequency of elements.
For example, if the input array is {2, 3, 2, 4, 5, 12, 2, 3, 3, 3, 12},
then modify the array to {3, 3, 3, 3, 2, 2, 2, 12, 12, 4, 5}.

If frequencies of two elements are same, print them in increasing order.

(1) Test case:
Enter size:
5
Enter 5 numbers:
1 4 2 1 4
sortedArray(): 1 1 4 4 2

(2) Test case:
Enter size:
1
Enter 1 numbers:
5
sortedArray(): 5
*/

#include <stdio.h>

void sortAr(int ar[], int size);
int main(){
    int array[80];
    int size, i;
    printf("Enter size: \n");
    scanf("%d", &size);
    printf("Enter %d numbers: \n", size);
    for (i = 0; i < size; i++)
        scanf("%d", &array[i]);
    printf("sortedArray(): ");
    sortAr(array, size);
    for (i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
    return 0;
}
void sortAr(int ar[], int size)
{
    int infoAr[size][2], i, j=0, temp, temp1;

    //sort the array
    for(i=0; i<size-1; i++)
    {
        if(ar[i] > ar[i+1])
        {
            temp = ar[i];
            ar[i] = ar[i+1];
            ar[i+1] = temp;

            i = 0;
        }
    }

    infoAr[0][0] = ar[0];
    infoAr[0][1] = 0;

    //store occurrence of values in another array
    for(i=0; i<size; i++)
    {
        if(ar[i] != infoAr[j][0])
        {
            infoAr[++j][0] = ar[i];
            infoAr[j][1] = 0;
        }

        ++infoAr[j][1];
    }

    //stopper
    infoAr[++j][0] = -1;

    //sort occurrence from most to least
    for(i=0; i<size-1; i++)
    {
        if(infoAr[i+1][0] == -1)
            break;

        if(infoAr[i][1] < infoAr[i+1][1])
        {
            temp = infoAr[i][0];
            temp1 = infoAr[i][1];
            infoAr[i][0] = infoAr[i+1][0];
            infoAr[i][1] = infoAr[i+1][1];
            infoAr[i+1][0] = temp;
            infoAr[i+1][1] = temp1;

            i = 0;
        }
    }

    j = 0;

    //put back the array in most occurrence order
    for(i=0; i<size; i++)
    {
        if(infoAr[j][1] == 0)
            ++j;

        ar[i] = infoAr[j][0];
        --infoAr[j][1];
    }
}
