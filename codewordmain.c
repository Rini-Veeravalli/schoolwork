/* codewordmain.c */

#include<stdio.h>
#include<string.h>

#define MODE argv[1]

void usageinfo();
int main(int argc, char *argv[])
{
  /*help message */
  if(argc == 1 || strcmp(MODE, "-h") == 0 || strcmp(MODE, "--help") == 0)
    {
      usageinfo();
      return 0;
    }
  
  if(strcmp(MODE, "--spellcheck") != 0)
    {
      fprintf(stderr, "Invalid mode \"%s\"\n", MODE);
      return 1;
    }
  else if(strcmp(MODE, "--spellcheck") == 0 && argc < 4)
    {
      fprintf(stderr, "Usage: codeword.exe --spellcheck DICTFILE WORDS\n");
      return 1;
    }
}











/*help message */
void usageinfo()
{
  printf("Usage:\n");
  printf("codeword.exe [-h/--help]                     : Print this message.\n");
  printf("codeword.exe --spellcheck DICTFILE WORDS     : Check spelling of words.\n");
  printf("codeword.exe --anagram DICTFILE WORDS        : Find anagrams of words.\n");
  printf("codeword.exe --codeword-match DICTFILE WORDS : Find words matching codeword.\n");
  printf("codeword.exe --codeword-show CSVFILE         : Show codeword from csv file.\n");
}


