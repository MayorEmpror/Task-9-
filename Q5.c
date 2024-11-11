#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LEN 100

struct encoder_memory
{
  char string[MAX_LEN];
  char key_input[MAX_LEN];
  char *ciphered_values;
  int *ASCII_string;
  int *Key_ascii;
  int *cipher;
};
void cipher(char string[], char key[])
{
  struct encoder_memory memo;
  strcpy(memo.string, string);
  strcpy(memo.key_input, key);
  // printf("%s",memo.string);
  int len_string = strlen(memo.string);
  int len_key = strlen(memo.key_input);
  // printf("\n string lenth is %d",len_string);
  memo.ASCII_string = (int *)malloc(len_string * sizeof(int));
  memo.Key_ascii = (int *)malloc(len_string * sizeof(int));
  memo.cipher = (int *)malloc(len_string * sizeof(int));
  memo.ciphered_values = (char *)malloc(len_string * sizeof(char));

  int j = 0;
  for (int i = 0; memo.string[i] != '\0'; i++)
  {
    memo.ASCII_string[i] = (int)memo.string[i];
    memo.Key_ascii[i] = (int)memo.key_input[j];
    j += 1;
    if (memo.key_input[j] == '\0')
    {
      j = 0;
    }
  }
  for (int i = 0; i < len_string; i++)
  {
    if (memo.ASCII_string[i] != 32)
    {
      memo.ASCII_string[i] -= 64;
    }
    else
      memo.ASCII_string[i] = 20;
    if (memo.Key_ascii[i] != 32)
    {
      memo.Key_ascii[i] -= 64;
    }
  }
  for (int i = 0; i < len_string; i++)
  {
    memo.cipher[i] = memo.ASCII_string[i] + memo.Key_ascii[i];
  }
  for (int i = 0; i < len_string; i++)
  {
    memo.cipher[i] = memo.cipher[i] % 26;
  }
  for (int i = 0; i < len_string; i++)
  {
    memo.cipher[i] += 64;
  }
  for (int i = 0; i < len_string; i++)
  {
    memo.ciphered_values[i] = (char)memo.cipher[i];
  }

  printf("Entered string  : %s\n ", memo.string);
  printf("Ciphered string : %s\n ", memo.ciphered_values);
}
void encoder()
{
  char string[MAX_LEN];
  char key_s[MAX_LEN];
  printf("Enter the sentence : ");
  fgets(string, MAX_LEN, stdin);
  string[strcspn(string, "\n")] = 0;
  printf("Enter the key : ");
  fgets(key_s, MAX_LEN, stdin);
  key_s[strcspn(key_s, "\n")] = 0;
  cipher(string, key_s);
}

int main()
{
  encoder();
  return 0;
}