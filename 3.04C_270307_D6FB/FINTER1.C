
                    /* MODULO FINTER1.C  */

#include <io51.h>
#include <math.h>

#include <fdefines.h>
#include <fexterns.h>






  /* TEMPORIZADOR PARA LECTURA DE ABSORBANCIAS  */

interrupt void T0_int()
  {
  tempo=tempo+1;
  }
