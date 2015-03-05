/* codewordmain.c */

#include<stdio.h>
#include<string.h>


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

int error_messages(char *arg, int commandline, char *accessfile )
{
  if(strcmp(arg, "--spellcheck") != 0)
    {
      fprintf(stderr, "Invalid mode \"%s\"\n", arg);
      return 1;
    }
  else if(strcmp(arg, "--spellcheck") == 0 && commandline < 4)
    {
      fprintf(stderr, "Usage: codeword.exe --spellcheck DICTFILE WORDS\n");
      return 1; 
    }
  

  if(!strcmp(accessfile, "text_file/words.txt") == 0 || !strcmp(accessfile, "text_file/words3.txt") == 0)
    {
      fprintf(stderr, "Error: \"%s\" does not exist.\n", accessfile);
      return 1;
    }
  return 1; 
}

int openfile(char *arg)
{
  if(strcmp(arg, "text_file/words.txt") == 0)
    {
      char *dictfile = "text_file/words.txt";
      FILE *file = fopen(dictfile, "r");
      if(file == NULL)
        {
          fprintf(stderr, "Unable to open \"%s\"", dictfile);
          return 1;
        }
      
    }
  else if(strcmp(arg, "text_file/words3.txt") == 0)
    {
      char *dictfile = "text_file/words3.txt";
      FILE *file = fopen(dictfile, "r");
      if(file == NULL)
        {
          fprintf(stderr, "Unable to open \"%s\"", dictfile);
          return 1;
        }
    }
  return 1;
}




/*main*/
int main(int argc, char *argv[])
{
  char *Mode = argv[1];
  char *whichFile = argv[2];
  /*help message */
  if(argc == 1 || strcmp(Mode, "-h") == 0 || strcmp(Mode, "--help") == 0)
    {
      usageinfo();
      return 0;
    }
  /* error messages */ 
  if(error_messages(Mode, argc, whichFile) == 0)
    {
      return 0;
    }
  else
    {
      return 1;
    }

  /*readfile*/
  if(openfile(whichFile) == 0)
    {
      return 0;
    }
  else
    {
      return 1;
    }
}
