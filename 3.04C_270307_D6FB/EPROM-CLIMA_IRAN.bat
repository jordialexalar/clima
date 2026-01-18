copy clima_I.h modelo.h
\icc1\icc8051 fmain.c    -e -mb
\icc1\icc8051 f100.c    -e -mb
\icc1\icc8051 finiz.c   -e -mb
\icc1\icc8051 ffun.c   -e -mb
\icc1\icc8051 fproces.c   -e -mb
\icc1\icc8051 fproces1.c   -e -mb
\icc1\icc8051 finter.c   -e -mb -RRCODE
\icc1\icc8051 fstr.c   -e -mb
\icc1\icc8051 fget.c   -e -mb
\icc1\icc8051 ftecl.c   -e -mb
\icc1\icc8051 fabs.c    -e -mb
\icc1\icc8051 fedit.c    -e -mb
\icc1\icc8051 fedit1.c    -e -mb
\icc1\icc8051 fedit2.c    -e -mb
\icc1\icc8051 fprint.c    -e -mb
\icc1\icc8051 fcom.c    -e -mb
\icc1\icc8051 ftest.c    -e -mb
\icc1\icc8051 futil.c    -e -mb
\icc1\icc8051 fqc.c    -e -mb -l fqc.lst
\icc1\xlink  -f lnk8051b
hexbin2 f100.eje f100.bin m 0000
copy f100.bin c:\eprom



