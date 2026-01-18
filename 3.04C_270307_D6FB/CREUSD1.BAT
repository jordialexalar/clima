del f100.srt
@if %1 == todo goto a

 @if %2 == s goto nt
 icc8051 %1.c -e   -m0
 goto fin
:nt
 icc8051 %1.c -e   -m0 -j -P
 goto fins

:a
@if %2 == s goto as
icc8051 f100.c -e   -m0
icc8051 finiz.c -e  -m0
icc8051 fdisp.c -e  -m0
icc8051 fabs.c -e   -m0
icc8051 fedit.c -e   -m0
icc8051 fproces.c -e   -m0
icc8051 fprint.c -e   -m0
icc8051 fcom.c -e   -m0
icc8051 nvram.c -e   -m0
xlib comfil
goto fin

:as
 icc8051 f100.c -e   -m0 -j
    icc8051 finiz.c -e  -m0 -j
    icc8051 fdisp.c -e  -m0 -j
    icc8051 fabs.c -e   -m0 -j
    icc8051 fedit.c -e   -m0 -j
    icc8051 fproces.c -e   -m0 -j
    icc8051 fprint.c -e   -m0 -j
    icc8051 fcom.c -e   -m0 -j
    icc8051 nvram.c -e   -m0 -j
    xlib comfil
    goto fins


:fin
xlink f100 nvram fedit fcom fproces finiz fdisp fabs  fprint startfot -Faomf8051 -f lnk8051 -xs -o f100.eje -m -l f100.plb
goto fint

:fins
xlink f100 nvram fedit fcom finiz fdisp fproces fabs fprint startfot -Faomf8051 -f lnk8051 -xs  -o f100.eje -m -l f100.plb
convert f100.eje -Of100.srt -Gf100.gbl

:fint

 @echo fin
 usd t