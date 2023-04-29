#include <cs50.h>
#include <stdio.h>

int starting_size(void);
int ending_size(int starting_size);
int calculate(int start, int end);

int main(void)
{
    // TODO: Prompt for start size
    int starting_population_size = starting_size();

    // TODO: Prompt for end size
    int ending_population_size = ending_size(starting_population_size);

    // TODO: Calculate number of years until we reach threshold
    int no_of_years = calculate(starting_population_size, ending_population_size);
    // TODO: Print number of years
    printf("Years: %i\n", no_of_years);
}

int starting_size(void)
{
    int starting_size;
    do
    {
        starting_size = get_int("Starting size: ");
    }
    while (starting_size < 9);
    return starting_size;
}

int ending_size(int starting_size)
{
    int ending_size;
    do
    {
        ending_size = get_int("Ending size: ");
    }
    while (ending_size < starting_size);
    return ending_size;

}

int calculate(int start, int end)
{
    int years = 0;
    while (start < end)
    {
        start = start + (start / 3) - (start / 4);
        years++;
    }
    return years;
}