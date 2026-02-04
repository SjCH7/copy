#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <wctype.h>

void determine_and_print_grade(int grade);
int calculate_grade(string text);
bool is_sentence_indicator(char current_char);

int main(void)
{
    string text = get_string("Text: ");
    determine_and_print_grade(calculate_grade(text));
}
void determine_and_print_grade(int grade)
{
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 1 && grade <= 15)
    {
        printf("Grade %i\n", grade);
    }
    else
    {
        printf("Grade 16+\n");
    }
}

int calculate_grade(string text)
{
    double letters = 0;
    double sentences = 0;
    double amount_of_words = 0;
    for (int i = 0, text_length = strlen(text); i < text_length; i++)
    {
        if (iswalpha(text[i]))
        {
            letters++;
            continue;
        }
        if (iswblank(text[i]))
        {
            amount_of_words++;
            continue;
        }
        if (is_sentence_indicator(text[i]))
        {
            sentences++;
            continue;
        }
    }
    if (letters > 0)
    {
        // adding last word
        amount_of_words++;
    }
    // letters / amount of words == amount of letters per 1 word;
    letters = (letters / amount_of_words) * 100;
    sentences = (sentences / amount_of_words) * 100;
    double index = 0.0588 * letters - 0.296 * sentences - 15.8;

    return llround(index);
}
bool is_sentence_indicator(char current_char)
{
    const string sentence_indicators = ".!?";
    for (int i = 0, indicators_length = strlen(sentence_indicators); i < indicators_length; i++)
    {
        if (current_char == sentence_indicators[i])
        {
            return true;
        }
    }
    return false;
}
