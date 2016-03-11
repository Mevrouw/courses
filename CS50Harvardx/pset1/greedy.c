/**
 * greedy.c
 *
 * Tjitske Lohstroh
 *
 * Outputs the minimum number of coins possible the cashier can give back in change.
 */
 
#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    // declaring variables:
    float change_f = 0;
    int coin_count = 0;

    // asks the user how much change is owed and get input:
    do
    {
        printf("how much change is owed?\n");
        change_f = GetFloat();
    }
    while (change_f < 0);

    // change is converted into cents, and from float to int:    
    int change_cents = round(change_f * 100);


    // number of coins is calculated:
    while (change_cents >= 25)
    {   
        change_cents = change_cents - 25;
        coin_count++;
    }

    while (change_cents >= 10)
    {
        change_cents = change_cents - 10;
        coin_count++;
    }

    while (change_cents >= 5)
    {
        change_cents = change_cents - 5;
        coin_count++;
    }

    while (change_cents >= 1)
    {
        change_cents = change_cents - 1;
        coin_count++;
    }
    printf("%d\n", coin_count );
}
