append \icc1

 @if %1 == s goto nt
 \icc1\icc8051 %1.c    -ml
 goto fin
:nt
 \icc1\icc8051 %1.c    -ml
:fin