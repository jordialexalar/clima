/*			- STDIO.H -

   Subset of ANSI standard I/O function declarations.

   Version: 3.00 [IANR]

*/

#ifndef NULL
#define	NULL	(void *) 0
#endif

#ifndef EOF
#define	EOF	(-1)
#endif

int	putchar(int);
int	getchar(void);
int	sprintf(char *,const char *,...);
int	printf(const char *,...);
int	scanf(const char *,...);
int	sscanf(const char *, const char *,...);
char	*gets(char *);
