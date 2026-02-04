#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wctype.h>

bool check_input(int argc, string argv[]);
string encrypt_information(string plaintext, int key);
char encrypt_char(char cur_char, int key);

int desired_arg_element = 1;

int main(int argc, string argv[])
{
    if (check_input(argc, argv))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int key = atoi(argv[desired_arg_element]);

    string plaintext = get_string("plaintext: ");
    printf("ciphertext: %s\n", encrypt_information(plaintext, key));
}

string encrypt_information(string plaintext, int key)
{
    for (int i = 0, ptext_length = strlen(plaintext); i < ptext_length; i++)
    {
        if (isalpha(plaintext[i]))
        {
            plaintext[i] = encrypt_char(plaintext[i], key);
        }
        else
        {
            continue;
        }
    }
    return plaintext;
}

char encrypt_char(char cur_char, int key)
{
    int char_value = cur_char + key;
    if (isupper(cur_char))
    {
        if (char_value > 90)
        {
            return ((char_value - 90) % 26) + 64;
        }
        else
        {
            return char_value;
        }
    }
    else
    {
        if (char_value > 122)
        {
            return ((char_value - 122) % 26) + 96;
        }
        else
        {
            return char_value;
        }
    }
}

bool check_input(int argc, string argv[])
{
    if (argc == 2)
    {
        for (int i = 0, second_arg_length = strlen(argv[desired_arg_element]);
             i < second_arg_length; i++)
        {
            if (!isdigit(argv[desired_arg_element][i]))
            {
                return true;
            }
        }
    }
    else
    {
        return true;
    }
    return false;
}
