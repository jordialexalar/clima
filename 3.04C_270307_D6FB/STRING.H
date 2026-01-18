/*			 - STRING.H -

   The ANSI 'string' function declarations.
	   
   Version: 3.10 [IANR]
	   
*/

#ifndef size_t
#if sizeof((char *)0 - (char *)0) == sizeof(int)
#define size_t		int
#else
#define size_t		long
#endif
#endif

char *strcat(char *s1, const char *s2);

char *strncat(char *s1, const char *s2, size_t n);

char *strcpy(char *s1, const char *s2);

char *strncpy(char *s1, const char *s2, size_t n);

size_t strlen(const char *s);

int strcmp(const char *s1, const char *s2);

int strncmp(const char *s1, const char *s2, size_t n);

