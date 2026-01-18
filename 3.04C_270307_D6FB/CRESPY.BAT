append \icc1
del f100.srt
@if %1 == todo goto a

 @if %2 == s goto nt
 \icc1\icc8051 %1.c    -e -ml 
 goto fin
:nt
 \icc1\icc8051 %1.c    -e -ml 
 goto fins

:a
@if %2 == s goto as
\icc1\icc8051 f100.c    -e -ml -r
\icc1\icc8051 finiz.c   -e -ml 
\icc1\icc8051 flcd.c   -e -ml 
\icc1\icc8051 fproces.c   -e -ml 
\icc1\icc8051 fproces1.c   -e -ml 
\icc1\icc8051 finter.c   -e -ml 
\icc1\icc8051 finter1.c   -e -ml 
\icc1\icc8051 finter2.c   -e -ml 
\icc1\icc8051 fstr.c   -e -ml
\icc1\icc8051 fget.c   -e -ml 
\icc1\icc8051 ftecl.c   -e -ml 
\icc1\icc8051 fabs.c    -e -ml 
\icc1\icc8051 fedit.c    -e -ml
\icc1\icc8051 fedit1.c    -e -ml
\icc1\icc8051 fedit2.c    -e -ml
\icc1\icc8051 fprint.c    -e -ml

goto fin

:as
 \icc1\icc8051 f100.c    -e -ml
\icc1\icc8051 finiz.c   -e -ml 
\icc1\icc8051 fproces.c   -e -ml 
\icc1\icc8051 fproces1.c   -e -ml 
\icc1\icc8051 flcd.c   -e -ml
\icc1\icc8051 finter.c   -e -ml 
\icc1\icc8051 finter1.c   -e -ml 
\icc1\icc8051 finter2.c   -e -ml 
\icc1\icc8051 fstr.c   -e -ml 
\icc1\icc8051 fget.c   -e -ml 
\icc1\icc8051 ftecl.c   -e -ml 
\icc1\icc8051 fabs.c    -e -ml 
\icc1\icc8051 fedit.c    -e -ml
\icc1\icc8051 fedit1.c    -e -ml 
\icc1\icc8051 fedit2.c    -e -ml 
\icc1\icc8051 fprint.c    -e -ml
    goto fins


:fin
\icc1\xlink  -f lnk8051 -rt
goto fint

:fins
\icc1\xlink -f lnk8051
\icc1\convert f100.eje -Of100.srt -Gf100.gbl

:fint
 @echo fin
us t
