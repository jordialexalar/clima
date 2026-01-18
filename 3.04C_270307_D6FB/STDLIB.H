/*			- STDLIB.H -

   The ANSI-defined 'standard' functions.

   Version: 3.10 [IANR]

*/

#ifndef size_t
#if sizeof((char *)0 - (char *)0) == sizeof(int)
#define size_t		int
#else
#define size_t		long
#endif
#endif

void	*malloc(size_t size);

void	free(void *ptr);

void	exit(int status);

void	*calloc(unsigned int nelem, size_t elsize);

void	*realloc(void *ptr, size_t size);

int atoi (const char *nptr);

long atol (const char *nptr);

double atof (const char *nptr);
