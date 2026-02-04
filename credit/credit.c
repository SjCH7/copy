#include <cs50.h>
#include <stdio.h>

bool is_valid(long card_number);
void print_card_type(long card_number);
int get_sum_of_multipled_digits(int current_number, long i);
bool process_number(long card_number, long i, bool inside_multipled_number);
void check_length_and_print_result(long first_two_digits_of_card, int identifier, long card_number,
                                   string card_name);

const long min_invalid_card_length = 10000000000000000; // 17 digits
const long max_card_number_length = 1000000000000000;   // 16 digits
const long amex_card_length = 100000000000000;          // 15 digits
const long max_short_visa_card_length = 10000000000000; // 14 digits
const long min_card_number_length = 1000000000000;      // 13 digits

const string amex_card_name = "AMEX";
const string mastercard_card_name = "MASTERCARD";
const string visa_card_name = "VISA";
int sum_result = 0;

int main(void)
{
    long card_number = get_long("Number: ");
    if (card_number >= min_card_number_length && card_number < min_invalid_card_length)
    {
        bool number_is_valid = is_valid(card_number);
        if (number_is_valid)
        {
            print_card_type(card_number);
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

bool is_valid(long card_number)
{
    bool inside_multipled_number = false;
    long i = 10;
    for (; i < card_number; i *= 10)
    {
        inside_multipled_number = process_number(card_number, i, inside_multipled_number);
    }
    inside_multipled_number = process_number(card_number, i, inside_multipled_number);
    return sum_result % 10 == 0;
}
bool process_number(long card_number, long i, bool inside_multipled_number)
{
    int current_number = (card_number % i) / (i / 10);
    if (inside_multipled_number)
    {
        sum_result += get_sum_of_multipled_digits(current_number, i);
    }
    else
    {
        sum_result += current_number;
    }
    if (inside_multipled_number)
    {
        inside_multipled_number = false;
    }
    else
    {
        inside_multipled_number = true;
    }
    return inside_multipled_number;
}

int get_sum_of_multipled_digits(int current_number, long i)
{
    int product = current_number * 2;
    if (product < 10)
    {
        return product;
    }
    else
    {
        int tens = product / 10;
        int ones = product % 10;
        return tens + ones;
    }
}

void print_card_type(long card_number)
{
    long first_two_digits_of_card = card_number;
    while (first_two_digits_of_card >= 100)
    {
        first_two_digits_of_card /= 10;
    }
    int identifier = first_two_digits_of_card / 10;
    if (identifier == 3)
    {
        check_length_and_print_result(first_two_digits_of_card, identifier, card_number,
                                      amex_card_name);
    }
    else if (identifier == 4)
    {
        check_length_and_print_result(first_two_digits_of_card, identifier, card_number,
                                      visa_card_name);
    }
    else if (identifier == 5)
    {
        check_length_and_print_result(first_two_digits_of_card, identifier, card_number,
                                      mastercard_card_name);
    }
}

void check_length_and_print_result(long first_two_digits_of_card, int identifier, long card_number,
                                   string card_name)
{
    bool valid = false;
    if (identifier == 3)
    {
        if (card_number < max_card_number_length && card_number >= amex_card_length &&
            (first_two_digits_of_card == 34 || first_two_digits_of_card == 37))
        {
            valid = true;
        }
    }
    else if (identifier == 4)
    {
        if ((card_number >= max_card_number_length && card_number < min_invalid_card_length) ||
            (card_number >= min_card_number_length && card_number < max_short_visa_card_length))
        {
            valid = true;
        }
    }
    else if (identifier == 5)
    {
        if ((card_number >= max_card_number_length && card_number < min_invalid_card_length) &&
            (first_two_digits_of_card >= 51 && first_two_digits_of_card <= 55))
        {
            valid = true;
        }
    }

    if (valid)
    {
        printf("%s\n", card_name);
    }
    else
    {
        printf("INVALID\n");
    }
}
