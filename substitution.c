#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

char CAPLETTERS[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char lowLETTERS[] = "abcdefghijklmnopqrstuvwxyz";
char checkLETTERS[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char checkletters[] = "abcdefghijklmnopqrstuvwxyz";

string key;
string KEY;

int totalcheck = 0;
char check[100000];
int count_check(string key);

int k;
int n = 1;
char letters[100000];
string count_letters(string text);

int i;
//int num;
//int asciinumber1;
//int asciinumber2;
//int check_letters(string checking);

int main(int argc, string argv[])

{
    if (argv[1] == (void *)0)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (argv[2])
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (strlen(argv[1]) < 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

KEY = argv[1];
key = argv[1];


//checks for a properly given key using the check key function (if the check is passed, every index in the key should be 0, if there is any non 0, check failed)
int checkcount = count_check(key);
for (i = 0; i < strlen(checkletters); i++)
{
    if (checkletters[i] == '0') continue;
    printf("Key must only contain english letters of the alphabet and must not have duplicate letters.\n");
    return 1;
}

//take plain text input from user to be ciphered
string text = get_string("plaintext: ");

//sends the text through the cipher function
string lettercount = count_letters(text);

//prints the given ciphered text
printf("ciphertext: %s\n", lettercount);
return 0;
}


string count_letters(string text)
{

    for (int j = 0; j < strlen(text); j++)      //sets up the outer most loop to check each char of the users text string
    {
         for (k = 0; k < strlen(key); k++)      //sets up the nested loop to to check each char in the users text against the LETTERS array
         {
               if (text[j] == lowLETTERS[k])    //if the current char  matches any letters in the lowLETTERS array, set n = 0 and exit loop
               {
                   n = 0;
                   break;
               }
               else if (text[j] == CAPLETTERS[k])   //if the current char matches any letters in the CAPLETTERS array, set n = 2 and exit loop
               {
                    n = 2;
                    break;
               }
                else
               {
                 n = 1;                          //if no match is found, set n = 1;
               }

         }
         if (n == 0)                            //if n = 0; populate the current letter array index with the current index of the key
         {
                     //Converts the given words to all lower

                        i = 0;
                        while (key[i])
                    {
                        char LOW = key[i];
                        char DOWN = tolower(LOW);
                        key[i] = DOWN;
                        i = i + 1;
                    }

                    letters[j] = key[k];          // if n = 0 then set the letters array to the current index of the key
         }
         else if (n == 2)                         //if n = 2, populate the current letter array with index of the KEY
         {
                     //Converts the given words to all uppercase
                    i = 0;
                    while (KEY[i])
             {
                   char CAP = KEY[i];
                   char UP = toupper(CAP);
                   KEY[i] = UP;
                   i = i + 1;
             }

            letters[j] = KEY[k];                       //if n = 2, populate the current letter array with index of the KEY
         }
         else
         {
             letters[j] = text[j];                      //if n = 1, set the current letter array to the current text index
         }
         //totalLetters = totalLetters + letters[j];    //add the current lettercount to the total letters
    }
    return letters;
}



int count_check(string x)
{
    totalcheck = 0;
    for (int j = 0; j < strlen(x); j++)                //sets up the outer most loop to check each letter of the users key
    {
         for (k = 0; k < strlen(checkLETTERS); k++)    //sets up the nested loop to to check each sentence in the users key against the checkLETTERS array
         {
               if (x[j] == checkLETTERS[k])            //if the current char matches any chars in the checkLETTERS array, set n = 0 and exit loop
               {

                   n = 0;
                   break;
               }
               else if (x[j] == checkletters[k])       //if no match is found, check the checkletters array next, if match found here set n = 0 and exit
               {
                n = 0;
                break;
               }
         }
         if (n == 0)                                   //if n = 0; populate the current sentence array index with '0'
         {
            checkLETTERS[k] = '0';
            checkletters[k] = '0';
         }
         else
         {
            checkLETTERS[k] = '1';                     //if n = 1, set the current index of the sentence array to 1

         }
         totalcheck = totalcheck + checkLETTERS[k];    //add the current sentence count to the total sentences
    }
    return totalcheck;
}