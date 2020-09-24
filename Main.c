#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void OneDimensional()
{
    int size = 0;
    int *Arr = NULL;

    printf("Enter the Size:\n");
    scanf("%d", &size);

    Arr = (int *) malloc(size * sizeof(int));     // Allocate memory

    printf("Enter the Elements:\n");    // input array
    for(int i = 0; i < size; i++)
    {
        scanf("%d", &Arr[i]);
    }

    printf("Entered Elements:\n");      // Display data  
    for(int i = 0; i < size; i++)
    {
        printf("%d\n", Arr[i]);
    }
    
    free(Arr);
}

void TwoDimensional()
{
    int rows = 0, i = 0, j = 0, cols = 0 ;
    int **Arr = NULL;

    printf("Enter Number of rows : \n");
    scanf("%d",&rows);

    printf("Enter Number of columns : \n");
    scanf("%d",&cols);

    Arr = (int **) malloc(rows * sizeof(int *));    // step 2

    for(i = 0; i < rows ; i++)
    {
        Arr[i] = (int *) malloc(cols * sizeof(int));    // step 3
    }

    printf("Enter the elements\n");

    for(i = 0; i < rows ; i++)
    {
        for(j = 0; j < cols ; j++)
        {
            scanf("%d\t",&Arr[i][j]);
        }
    }

    printf("Elements are\n");

    for(i = 0; i < rows ; i++)
    {
        for(j = 0; j < cols ; j++)
        {
            printf("%d\t",Arr[i][j]);
        }
        printf("\n");
    }
    
    // Memory de-allocation 
    for(i = 0; i < rows ; i++)
    {
        free(Arr[i]);
        
    }

    // Memory de-allocation 
    free(Arr);

}

/*

int Arr[2][3][4];

Arr is 3 dimensional array which contains 2 two dimensional array
 each 2 dimentional array contains 3 one dimensional array
 each one dimensional array contains 4 elements in it
 and each element is of type integer.
*/

void ThreeDimensional()
{
    int first = 0 , second = 0 , third = 0 , i = 0 , j = 0, k = 0 ;
    int ***Arr = NULL;  //step 1 

    printf("Enter the value of three dimensional\n");
    scanf("%d%d%d",&first,&second,&third);

    //step 2
    Arr = (int ***)malloc(first * sizeof(int **));

    // step 3
    for(i = 0; i < first ; i++)
    {
        Arr[i] = (int **)malloc(second * sizeof(int *));
    }

    // step 4
    for(i = 0; i < first ; i++)
    {
        for(j = 0; j < second ; j++)
        {
            Arr[i][j] = (int *)malloc(third * sizeof(int));
        }
    }

    printf("Please enter the elements\n");
    // Accept the values
    for(i = 0; i < first ; i++)
    {
        for(j = 0; j < second ; j++)
        {
            for(k = 0; k < third ; k++)
            {
                scanf("%d",&Arr[i][j][k]);
            }
        }
    }

    printf("Entered Elements are:\n");
    for(i = 0; i < first ; i++)
    {
        for(j = 0; j < second ; j++)
        {
            for(k = 0; k < third ; k++)
            {
                printf("%d\t",Arr[i][j][k]);
            }
            printf("\n");
        }
        printf("\n--------------\n");
    }

     // free the step 4
    for(i = 0; i < first ; i++)
    {
        for(j = 0; j < second ; j++)
        {
            free(Arr[i][j]);
        }
    }

    //free the step 3
    for(i = 0; i < first ; i++)
    {
        free(Arr[i]);
    }

    free(Arr);

}

int main()
{
    int choice = 0;

    printf("Enter your choice\n");
    printf("1: OneDimensional\n2: TwoDimensional\n3: ThreeDimensional\n");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            OneDimensional();
            break;

        case 2:
            TwoDimensional();
            break;

        case 3:
            ThreeDimensional();
            break;
        default:
            printf("Wrong choice!\n");
            break;            
    }

    return 0;
}