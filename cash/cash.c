#include <cs50.h>
#include <stdio.h>

void print_minimum_amount_of_coins_needed(int change);
int get_amount_of_biggest_coins(int coin_value, int change);
const int quarter = 25;
const int dime = 10;
const int nickel = 5;
const int penny = 1;
int main(void)
{
    int change;
    do
    {
        change = get_int("Change owed: ");
    }
    while (change <= 0);
    print_minimum_amount_of_coins_needed(change);
}

void print_minimum_amount_of_coins_needed(int change)
{
    int amount_of_coins_needed = 0;
    while (change > 0)
    {
        if (change / quarter >= 1)
        {
            int amount_of_quarters = get_amount_of_biggest_coins(quarter, change);
            change -= (amount_of_quarters * quarter);
            amount_of_coins_needed += amount_of_quarters;
        }
        else if (change / dime >= 1)
        {
            int amount_of_dimes = get_amount_of_biggest_coins(dime, change);
            change -= (amount_of_dimes * dime);
            amount_of_coins_needed += amount_of_dimes;
        }
        else if (change / nickel >= 1)
        {
            int amount_of_nichkels = get_amount_of_biggest_coins(nickel, change);
            change -= (amount_of_nichkels * nickel);
            amount_of_coins_needed += amount_of_nichkels;
        }
        else if (change / penny >= 1)
        {
            int amount_of_pennies = get_amount_of_biggest_coins(penny, change);
            change -= (amount_of_pennies * penny);
            amount_of_coins_needed += amount_of_pennies;
        }
    }
    printf("%i\n", amount_of_coins_needed);
}

int get_amount_of_biggest_coins(int coin_value, int change)
{
    int result = change / coin_value;
    return result;
}
