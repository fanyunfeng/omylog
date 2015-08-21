#define _XOPEN_SOURCE
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

time_t timestamp(const char* message, const char* fmt){
  struct tm tm; 

  strptime(message, fmt, &tm);
  return mktime(&tm);
}


double getValue(const char* message, const char* name, int len){
  char ch;
  const char* p = strstr(message, name);

  if(p == NULL){
    return 0;
  }

  p += len;

  while(*p){
    ch = *p;
    switch(ch){
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    case '.':
    case '-':
    case '+':
      goto findStart;
      break;
    default:
      break;
    }
    
    ++ p;
  }

  return 0;

findStart:
  return atof(p);
}

int main(int argc, char** argv){
  char message[] = "2015-08-21T17:48:11 provider:8 lines:11 seconds:2.534911948";

  printf("%s\n", message);

  time_t time = timestamp(message, "%FT%T");
  printf("%ld\n", time);

  {
    char name[] = "provider";
    double v = getValue(message, name, strlen(name));
    printf("%s:%f\n", name, v);
  }

  {
    char name[] = "seconds";
    double v = getValue(message, name, strlen(name));
    printf("%s:%f\n", name, v);
  }

  return 0;
}
