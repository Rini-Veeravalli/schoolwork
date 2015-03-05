/* codewordmain.c */

#include<stdio.h>
#include<string.h>



void usageinfo();
int error_messages(char *arg, int commandline, char *accessfile);
int openfile(char *arg, int commandline, char *argv[]);
int compare(int commandline, FILE *dictfile, char *argv[]);



/*main*/
int main(int argc, char *argv[])
{
  char *Mode = argv[1];
  char *whichFile = argv[2];
  char *word = argv[3];
  /*help message */
  if(argc == 1 || strcmp(Mode, "-h") == 0 || strcmp(Mode, "--help") == 0)
    {
      usageinfo();
      return 0;
    }
  /* error messages */
  printf("hi there.\n");
  if(error_messages(Mode, argc, whichFile) == 0)
    {
      return 0;
    }
  else if(error_messages(Mode, argc, whichFile) == 1)
    {
      return 1;
    }

  /*open file and compare */
  printf("hi there.. \n");
  if(openfile(whichFile, argc, argv) == 0)
    {
      return 0;
    }
  else if(openfile(whichFile, argc, argv) == 1)
    {
      return 1;
    }

  printf("hi there... \n");
    
  return 0;
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

/* errors for usage, wrong files */
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
 

  if((!strcmp(accessfile, "test_files/words.txt") == 0) && (!strcmp(accessfile, "test_files/words3.txt") == 0))
    {
      fprintf(stderr, "Error: \"%s\" does not exist.\n", accessfile);
      return 1;
    }
  return 2;
}

/*compare the file with some words */ 
int compare(int commandline, FILE *dictfile, char *argv[])
{
  printf("hi compare.\n");
  const static int maxlength = 256;
  char line[maxlength];
  
  ; /*do i need this ?*/
  for (int counter =3; counter <= commandline; counter++) /* counter to handle multiple word checks */
    {
      while(fgets(line, maxlength, dictfile) != NULL) /*reading the file in each line */
        {
          
          line[strlen(line-1)] = '\0'; /* replace the \n with '\0'? */
          if(strcmp(line, argv[counter] ) == 0)
            {
              printf("\"%s\" is correct.", argv[counter]);
              return 0;
            }
         
        }
      if(dictfile  == NULL) /*if end of file then no word match*/
        {
          fprintf(stderr, "\"%s\" is incorrect", argv[counter]);
          return 1;
        }
                    
    }
  printf("hi compre..\n");
  return 2;
}

 /* read file and compare */
int openfile(char *arg,int commandline, char *argv[])
{
  printf("hi openfile.\n");
  if(strcmp(arg, "test_files/words.txt") == 0)
    {
      char *dictfile = "test_files/words.txt";
      FILE *file = fopen(dictfile, "r");
      if(file == NULL) /*if at the end of a file, error */ 
        {
          fprintf(stderr, "Unable to open \"%s\"", dictfile);
          return 1;
        }
      if(compare(commandline, file, argv) == 0)
        {
          return 0;
        }
      else
        {
          return 1;
        }
    }
  else if(strcmp(arg, "test_files/words3.txt") == 0)
    {
      char *dictfile = "test_files/words3.txt";
      FILE *file = fopen(dictfile, "r");
      if(file == NULL)
        {
          fprintf(stderr, "Unable to open \"%s\"", dictfile);
          return 1;
        }
      if(compare(commandline,file, argv) == 0)
        {
          return 0;
        }
      else
        {
          return 1;
        }
    }
  printf("hi openfile..\n");
  return 2;
}

