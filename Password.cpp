#include "Password.h"
#include <string>
#include <cctype> 
using std::string;

/*
  The function receives a string counts how many times the same character 
  occurs at the beginning of the string, before any other characters (or the
  end of the string). The function is case-sensitive so 'Z' is different than
  'z' and any ASCII characters are allowed.
*/
int Password::count_leading_characters(string phrase){
  if (phrase.empty()) { 
    return 0;
  }

  int repetition = 1;
  int index = 0;
  while(index < phrase.length()-1 && phrase[index] == phrase[index+1]){
    repetition++;
    index++;
  }
  return repetition;
}



bool Password::has_mixed_case(string word) {
  bool has_upper = false;
  bool has_lower = false;

  for (char ch : word) {
    if (std::isupper(ch)) has_upper = true;
    if (std::islower(ch)) has_lower = true;
    if (has_upper && has_lower) return true; // Return if both cases are found
  }

  return false; // Return false if not both cases are found
}

