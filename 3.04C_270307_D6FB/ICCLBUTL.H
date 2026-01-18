/*			- ICCLBUTL.H -

   Low-level declarations for non-ANSI functions
   used by the C library.

   Version: 3.00 [IANR]

*/

#include "stdarg.h"

		/*-----------------------------------------*/
		/* Formatters used by "scanf" and "sscanf" */
		/*-----------------------------------------*/

int _formatted_read (const char **line,		/* Full ANSI */
                            const char **format,
		            va_list ap);

int _medium_read (const char **,		/* Without floating point */
                         const char **,
			 va_list);


		/*-------------------------------------------*/
		/* Formatters used by "printf" and "sprintf" */
		/*-------------------------------------------*/

int _formatted_write (const char *format,	/* Full ANSI */
			     void outputf(char, void *),
			     void *sp,
			     va_list ap);

int _medium_write (const char *format,		/* Without floating point */
			  void outputf(char, void *),
			  void *sp,
			  va_list ap);

int _small_write (const char *format,		/* Very reduced version */
			 void outputf(char, void *),
			 void *sp,
			 va_list ap);


