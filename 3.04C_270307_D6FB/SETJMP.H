/*			- SETJMP.H -
 
   The ANSI "setjmp" and "longjmp" function declarations.
	   
   Version: 3.10 [IANR]
   
*/

#ifdef __JMP_BUF__

typedef char jmp_buf[__JMP_BUF__];

#else

typedef char jmp_buf[8];

#endif

int setjmp (jmp_buf env);

void longjmp (jmp_buf env, int val);

