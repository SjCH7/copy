#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wctype.h>

bool check_input(int argc, string argv[]);
string encrypt_information(string plaintext, string key);
char encrypt_char(char cur_char, string key);
int get_index(char cur_char);

int desired_arg_element = 1;

int main(int argc, string argv[])
{
    if (check_input(argc, argv))
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string plaintext = get_string("plaintext: ");
    printf("ciphertext: %s\n", encrypt_information(plaintext, argv[desired_arg_element]));

    return 0;
}

string encrypt_information(string plaintext, string key)
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

char encrypt_char(char cur_char, string key)
{
    int alphabetical_char_index = get_index(cur_char);
    if (isupper(cur_char))
    {
        return toupper(key[alphabetical_char_index]);
    }
    else
    {
        return tolower(key[alphabetical_char_index]);
    }
}
int get_index(char cur_char)
{
    if (isupper(cur_char))
    {
        return cur_char - 65;
    }
    else
    {
        return cur_char - 97;
    }
}

bool check_input(int argc, string argv[])
{
    if (argc == 2)
    {
        if (strlen(argv[desired_arg_element]) != 26)
        {
            return true;
        }
        bool letters[26];
        for (int i = 0, second_arg_length = strlen(argv[desired_arg_element]);
             i < second_arg_length; i++)
        {
            if (!isalpha(argv[desired_arg_element][i]))
            {
                return true;
            }
            int alpha_char_index = get_index(argv[desired_arg_element][i]);
            if (letters[alpha_char_index])
            {
                return true;
            }
            if (!letters[alpha_char_index])
            {
                letters[alpha_char_index] = true;
            }
        }
    }
    else
    {
        return true;
    }
    return false;
}
