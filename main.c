#include "caesar.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Prints off an error, then closes the program.
*/
void err(const char* e) {
  printf("%s", e);
  exit(-1);
}

/*
Reads in the paths to the files from the command line, then opens the input file, applies the caesar cipher to it,
and writes the result to a specified output file.
*/
int main(int argc, char** argv) {
  if(argc != 4) err("Input count was not 3.");
  else {
    FILE *in = fopen(argv[1], "r");
    if(in == NULL) err("No input file found.");
    FILE *out = fopen(argv[2], "w");
    if(out == NULL) err("Output file could not be written.");
    int offset = atoi(argv[3]);
    if(offset < -25 || offset > 25) err("Range must be between -25 and 25, inclusive.");
    int ch = getc(in);
    while(ch != EOF) {
      char c = caesar(ch, offset);
      printf("%c", c);
      fputc(c, out);
      ch = getc(in);
    }
  }
  return 0;
}