/*			- CTYPE.H -

   The ANSI character testing function declarations.
	   
   Note: Only 7-bit ASCII is supported by these functions.

   Version: 3.00 [IANR]
	   
*/

#define	_U	01
#define	_L	02
#define	_N	04
#define	_S	010
#define _P	020
#define _C	040
#define _X	0100
#define _B	0200

extern const unsigned char _ctype_[129];

int toupper(int c);	/* "toupper" is also available as a function */
int tolower(int c);	/* "tolower" is also available as a function */

#define	isalpha(c)	((_ctype_+1)[c]&(_U|_L))
#define	isupper(c)	((_ctype_+1)[c]&_U)
#define	islower(c)	((_ctype_+1)[c]&_L)
#define	isdigit(c)	((_ctype_+1)[c]&_N)
#define	isxdigit(c)	((_ctype_+1)[c]&(_N|_X))
#define	isspace(c)	((_ctype_+1)[c]&_S)
#define ispunct(c)	((_ctype_+1)[c]&_P)
#define isalnum(c)	((_ctype_+1)[c]&(_U|_L|_N))
#define isprint(c)	((_ctype_+1)[c]&(_P|_U|_L|_N|_B))
#define isgraph(c)	((_ctype_+1)[c]&(_P|_U|_L|_N))
#define iscntrl(c)	((_ctype_+1)[c]&_C)
#define toupper(c)	(islower((c))? (c)&0x5F: (c))
#define tolower(c)	(isupper((c))? (c)|0x20: (c))
