/*
 1.write a c program to find the most frequent occur letter in a word
case:1
input : viven
output: v->2 times

case:2
input :cat
output : none
*/

#include <stdio.h>
#include <string.h>

void most_frequent_letter(char *str)
{
    int freq[256] = {0};
    int max = 0;
    char result;
    int i;
    for ( i = 0; str[i] != '\0'; i++)
    {
        freq[(unsigned char)str[i]]++; // Count frequency of each character

        if (freq[(unsigned char)str[i]] > max)
        {
            max = freq[(unsigned char)str[i]];
            result = str[i];
        }
    }
    //printf("Most frequent character: '%c' -> %d times\n", result, max);
    if(max == 1)
    {
            printf("none\n");
    }
    else
    {
            printf("Most frequent character: '%c' -> %d times\n", result, max);
    }

}

int main()
{
    char word[100];
    printf("Enter a word: ");
    fgets(word,sizeof(word),stdin);

    most_frequent_letter(word);

    return 0;
}
