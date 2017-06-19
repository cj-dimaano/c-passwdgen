/*******************************************************************************
  File: main.c
  Author: CJ Dimaano
  Date created: April 17, 2016
  Last upadted: April 22, 2016
  
  Compile with:
  gcc main.c
  
  Run with:
  ./a.out
  
  Summary:
  Generates 64 randomized 8-character strings.
  
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
 * valid
 *   Valid password characters.
 */
static const char * const valid_char[] = {
  "abcdefghijklmnopqrstuvwxyz",
  "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
  "0123456789",
  "!@#$%^&*()"
  "`-=[]\\;',./"
  "~_+{}|:\"<>?"
};

/**
 * valid_str
 *   Returns true if a string is a valid password.
 *
 *
 * @param str
 *   The string to be validated.
 *
 *
 * @return
 *   True if the string is a valid password; otherwise, false.
 */
static inline int valid_str(const char * const str) {
  /* Forward declarations. */
  size_t i, j, len;
  int count = 0;
  
  /* Check if the string contains at least one capital letter, lower case
       letter, number, and special character. */
  for(i = 0; i < 4; i++) {
    len = strlen(valid_char[i]);
    for(j = 0; j < len && strchr(str, valid_char[i][j]) == NULL; j++);
    if(j < len) {
      count++;
    }
  }
  
  /* Return whether or not the string is valid. */
  return (count == 4);
}

/**
 * genchar
 *   Generates a random character from the set of valid characters.
 *
 *
 * @return
 *   A random character from the set of valid characters.
 */
static inline char genchar(void) {
  /* Forward declarations. */
  int i, j;
  const char *str;
  
  /* Select a random category of characters. */
  i = rand() % 4;
  str = valid_char[i];
  j = strlen(str);
  
  /* Select a random character from the category. */
  return str[rand() % j];
}

/**
 * genpasswd
 *   Generates a random password.
 *
 *
 * @param buf
 *   Placeholder for the password string.
 *
 * @param len
 *   Length of the buffer.
 */
static inline void genpasswd(char *buf, const size_t len) {
  /* Forward declarations. */
  size_t i;
  
  /* Generate random strings until a valid password is produced. */
  do {
    for(i = 0; i < len; i++) {
      buf[i] = genchar();
    }
  } while(!valid_str(buf));
}

/*******************************************************************************
  main.
*******************************************************************************/

int main(void) {
  /* Forward declarations. */
  int i;
  const size_t len = 8;
  char buf[(const size_t)(len + 1)];
  buf[len] = 0;
  
  /* Set the random number generator seed. */
  srand(time(NULL));
  
  /* Print 16 lines of 4 strings. */
  for(i = 0; i < 16; i++) {
    /* Generate the first string. */
    genpasswd(buf, len);
    printf("%s   ", buf);
    
    /* Generate the second string. */
    genpasswd(buf, len);
    printf("%s   ", buf);
    
    /* Generate the third string. */
    genpasswd(buf, len);
    printf("%s   ", buf);
    
    /* Generate the fourth string. */
    genpasswd(buf, len);
    printf("%s\n", buf);
  }
  
  return 0;
}
