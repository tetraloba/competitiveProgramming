#include <stdio.h>
#include <stdlib.h>

int main(){
  int x;
  char s[100];

  while( scanf("%s", s) != EOF ){
    if ( s[0] == '+' ){

    } else if ( s[0] == '-' ){

    } else if ( s[0] == '*' ){

    } else {
      x = atoi(s);

    }
  }

  return 0;
}