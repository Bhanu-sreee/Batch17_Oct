String Functions Assignment

1. WAP to prompt and read a line of text with words separated by space. Tokenise and extract the words. Display them. Impement the following functions for this.

a. int tokenise(char *arr); //tokenise and display tokens , return number of tokens to the caller

[Use strtok() to tokenise]
/*************************************************************************
*
*  FILE NAME    : string_tokenise.c
*
*  DESCRIPTION  : Tokenize a line of text into words and display them.
*
*  DATE      NAME            REFERENCE          REASON
*
*  19-NOV-24 N.Bhanu sree                    Initial creation
*
**************************************************************************/
#include <stdio.h>
#include <string.h>

/*************************************************************************
*       Function Name   : tokenise
*       Description     : Tokenize and display tokens
*       Input           : A string of text
*       Returns         : Number of tokens
*************************************************************************/
int tokenise(char *arr) {
    char *token;
    int count = 0;

    /* Tokenizing the string */
    token = strtok(arr, " ");
    while (token != NULL) {
        printf("Token: %s\n", token);
        count++;
        token = strtok(NULL, " ");
    }
    return count;
}

/*************************************************************************
*       Function Name   : main
*       Description     : Main function to demonstrate tokenisation
*       Returns         : Success or Failure
*************************************************************************/
int main() {
    char input[256];
    int token_count;

    printf("Enter a line of text: ");
    fgets(input, sizeof(input), stdin);

    /* Removing newline character if present */
    input[strcspn(input, "\n")] = '\0';

    token_count = tokenise(input);
    printf("Number of tokens: %d\n", token_count);

    return 0;
}

--------------------------------------------------------------------------------------


2. Implement your own strncat() which shall concatenate n characters from src to dest.

char *strncat(char *dest, const char *src, size_t n)
/*************************************************************************
*
*  FILE NAME    : custom_strncat.c
*
*  DESCRIPTION  : Implementation of custom strncat function.
*
*  DATE      NAME            REFERENCE          REASON
*
*  19-NOV-24 N Bhanu sree                     Initial creation
*
**************************************************************************/
#include <stdio.h>
#include <string.h>

/*************************************************************************
*       Function Name   : custom_strncat
*       Description     : Concatenate `n` characters from src to dest
*       Input           : Destination string, Source string, Number of characters
*       Returns         : Pointer to destination string
*************************************************************************/
char *custom_strncat(char *dest, const char *src, size_t n) {
    char *ptr = dest + strlen(dest); /* Move pointer to end of dest */
    size_t i;

    for (i = 0; i < n && src[i] != '\0'; i++) {
        *ptr++ = src[i];
    }

    *ptr = '\0'; /* Null-terminate dest */
    return dest;
}

/*************************************************************************
*       Function Name   : main
*       Description     : Main function to demonstrate custom_strncat
*       Returns         : Success or Failure
*************************************************************************/
int main() {
    char dest[50] = "Hello, ";
    char src[] = "World!";
    size_t n = 3;

    printf("Before concatenation: %s\n", dest);
    custom_strncat(dest, src, n);
    printf("After concatenation: %s\n", dest);

    return 0;
}










3. WAP to

a. Search for and replace the vowel characters (upper and lower case) with “ay” in a word read from user. Consider a maximum word length of 40 characters.

b. Identify the test inputs to be used

c. Display updated string

/*************************************************************************
*
*  FILE NAME    : replace_vowels.c
*
*  DESCRIPTION  : Replaces vowels in a word with "ay".
*
*  DATE      NAME            REFERENCE          REASON
*
*  19-NOV-24 N.Bhanu sree                    Initial creation
*
**************************************************************************/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*************************************************************************
*       Function Name   : replace_vowels
*       Description     : Replace vowels in the input word with "ay".
*       Input           : Word from user
*       Returns         : None
*************************************************************************/
void replace_vowels(char *word) {
    char result[100] = ""; /* To store the updated string */
    char *ptr = result;

    for (int i = 0; word[i] != '\0'; i++) {
        if (strchr("AEIOUaeiou", word[i]) != NULL) {
            *ptr++ = 'a'; /* Add 'a' */
            *ptr++ = 'y'; /* Add 'y' */
        } else {
            *ptr++ = word[i]; /* Copy the consonant */
        }
    }

    *ptr = '\0'; /* Null-terminate the result */
    printf("Updated string: %s\n", result);
}

/*************************************************************************
*       Function Name   : main
*       Description     : Main function to demonstrate replace_vowels
*       Returns         : Success or Failure
*************************************************************************/
int main() {
    char word[41];

    printf("Enter a word (max 40 characters): ");
    scanf("%40s", word);

    replace_vowels(word);

    return 0;
}





















