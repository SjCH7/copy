#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <wctype.h>

void print_comparison_result(string player1, string player2);
void print_winner(string winner_name, bool winner_present);
int get_score(string word_of_the_player);
int get_current_letter_score(char letter);
bool find_letter(string letters, char desired_letter);

int main(void)
{
    string player1 = get_string("Player 1: ");
    string player2 = get_string("Player 2: ");
    print_comparison_result(player1, player2);
}

void print_comparison_result(string player1, string player2)
{
    int first_player_score = get_score(player1);
    int second_player_score = get_score(player2);
    if (first_player_score > second_player_score)
    {
        print_winner("Player 1", true);
    }
    else if (second_player_score > first_player_score)
    {
        print_winner("Player 2", true);
    }
    else
    {
        print_winner("Tie!", false);
    }
}

int get_score(string word_of_the_player)
{
    int amount_of_player_points = 0;
    for (int i = 0, players_word_length = strlen(word_of_the_player); i < players_word_length; i++)
    {
        char current_char = word_of_the_player[i];
        if (iswalpha(current_char))
        {
            current_char = towlower(current_char);
            amount_of_player_points += get_current_letter_score(current_char);
        }
        else
        {
            continue;
        }
    }
    return amount_of_player_points;
}

int get_current_letter_score(char letter)
{
    // 1 2 3 4 5 8 10 points arrays of letters
    const string letters[] = {"aeilnorstu", "dg", "bcmp", "fhvwy", "k", "jx", "qz"};
    int amount_of_points_per_letter = 1;
    for (int i = 0, letters_array_length = sizeof(letters) / sizeof(letters[0]);
         i < letters_array_length; i++)
    {
        if (find_letter(letters[i], letter))
        {
            return amount_of_points_per_letter;
        }
        if (amount_of_points_per_letter == 8)
        {
            amount_of_points_per_letter += 2;
        }
        else if (amount_of_points_per_letter == 5)
        {
            amount_of_points_per_letter += 3;
        }
        else
        {
            amount_of_points_per_letter++;
        }
    }
    return 0;
}
bool find_letter(string letters, char desired_letter)
{
    for (int i = 0, letter_array_length = strlen(letters); i < letter_array_length; i++)
    {

        if (desired_letter == letters[i])
        {
            // found
            return true;
        }
    }
    return false;
}
void print_winner(string winner_name, bool winner_present)
{
    if (winner_present)
    {
        printf("%s wins!\n", winner_name);
    }
    else
    {
        // no winners present == tie.
        printf("%s\n", winner_name);
    }
}
