/*			- STDDEF.H -

   The ANSI 'common' definitions.

   Version: 3.10 [IANR]
	   
*/

#ifndef size_t
#if sizeof((char *)0 - (char *)0) == sizeof(int)
#define size_t		int
#else
#define size_t		long
#endif
#endif

#ifndef NULL
#define	NULL		(void *) 0
#endif

#ifndef ptrdiff_t
#if sizeof((char *)0 - (char *)0) == sizeof(int)
#define ptrdiff_t	int
#else
#define ptrdiff_t	long
#endif
#endif

#ifndef offsetof
#define offsetof(type,member)	((size_t)(&((type *)0)->member))
#endif

