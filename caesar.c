#include "caesar.h"
#include <stdio.h>

/*
Takes in a character, and applies the proper caeser cipher to it, checking if it wraps around the end of the alphabet.
Returns the modified char.
*/
char caesar(char s, int n) {
  int num = (int)s;
  if(num >= 65 && num <= 90) {
    num = num + n%26;
    if(num > 90) num = 65 + (num - 91);
    else if(num < 65) num = 90 - (64 - num);
  }else if(num >= 97 && num <= 122) {
    num = num + n%26;
    if(num > 122) num = 97 + (num - 123);
    else if(num < 97) num = 122 - (96 - num);
  }
  return (char)num;
}