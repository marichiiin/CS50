#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // ASK THE USER TO CHOOSE BETWEEN 1 TO 8
    int n = 0;
    do
    {
        n = get_int("Choose between 1 to 8: ");
    }
    while (n < 1 || n > 8);

    //CREATE THE PYRAMID ACCORDING TO THE USERS INPUT

    for (int i = 0; i < n; i++)
    {
        // HERE IS THE LOOP FOR CREATING SPACES THAT MAKES THE HASH GO TO THE RIGHT
        for (int rows = n - 1; rows > i; rows--)
        {
            printf(" ");
        }
        // HERE IS THE LOOP FOR CREATING THE HASHES
        for (int j = 0; j <= i; j++)
        {
            printf("#");

            if (j == i)
            {
                printf("  ");

                for (int h = 0; h <= i; h++)
                {
                    printf("#");
                }
            }

        }
        printf("\n");
    }

}