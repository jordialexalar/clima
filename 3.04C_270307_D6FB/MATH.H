/*			- MATH.H -

   The ANSI-defined (+ a few additional) mathematical functions.
	   
   Version: 3.00 [IANR]

*/

double atan (double arg);

double atan2 (double arg1, double arg2);

double cos (double arg);

double exp (double arg);

double log (double arg);

double log10 (double arg);

double modf (double value, double *iptr);

double pow (double arg1, double arg2);

double sin (double arg);

double sqrt (double arg);

double tan (double arg);

double floor (double arg);

double ceil (double arg);

double frexp (double arg1, int *arg2);

#ifdef MATH_EXTENSIONS

double acos (double arg);

double asin (double arg);

double exp10 (double arg);

#endif

