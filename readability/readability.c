#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Input Sentence

    string text = get_string("Text: ");

    // Calc No. Of Letters
    // int count_letters(string text)
    int letters = 0;
    int words = 1;
    int sentences = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i])) // isaplha INSTEAD OF isupper
        {
            letters++;
        }

        // Calc No. Of Words
        else if (text[i] == ' ')
        {
            words++;
        }

        // Calc. No. Of Sentences
        else if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences++;
        }
    }

    // Coleman-Liau Eq.
    float L = (float) letters / (float) words * 100;
    float S = (float) sentences / (float) words * 100;

    int index = round(0.0588 * L - 0.296 * S - 15.8);

    // Print Reading Level
    // int grade = 0;
    // printf("Grade: %i\n", grade);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}