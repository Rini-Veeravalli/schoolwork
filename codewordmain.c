/* codewordmain.c */

#include<stdio.h>
#include<string.h>

void usageinfo();
int main(int argc, char *argv[])
{
  if(argc == 1 || strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)
    {
      usageinfo();
      return 0;
    }
}












void usageinfo()
{
  printf("Usage:\n");
  printf("codeword.exe [-h/--help]                     : Print this message.\n");
  printf("codeword.exe --spellcheck DICTFILE WORDS     : Check spelling of words.\n");
  printf("codeword.exe --anagram DICTFILE WORDS        : Find anagrams of words.\n");
  printf("codeword.exe --codeword-match DICTFILE WORDS : Find words matching codeword.\n");
  printf("codeword.exe --codeword-show CSVFILE         : Show codeword from csv file.\n");
  
}
