
         /*  MODULO F100.C            */

         /*  Modulo que contiene el bucle principal del programa*/


#include <io51.h>
#include <stdio.h>


#include <fdefines.h>
#include <fexterns.h>




  menu()
  {
   int ghj,i,j;
   char ent[10];

       inicializacion();

       check();
/*       P1.5=0; */
/*      pon_fecha();*/
      borrar();
        if (con_peristaltica==1)
        {
               say(2,0,textos[69+idioma_textos]);
               say(3,0,textos[70+idioma_textos]);
               inkey(5);
        }
        borrar();

   /*comienzo del bucle princial*/

      for(;;)
      {
       unsigned char numix[10];
       double j=0.00;
       int pul=100;
       int err=0;
      borrar();
      error_general=0;
      menu_prin=1;
      err=getstr(1,0,ent,3,1,1,0,textos[2+idioma_textos],BORRAR);
      menu_prin=0;

      switch(lastkey)
      {
      case cr:
      pul=arint(ent);
      if ( pul >= 0 && pul < total_tecnicas)
      { haz(pul);
      }
     else
     {
      if (pul==100)
       util();
     }
       break;

      case print:
       oper_dispo();
       break;

      case wash:
    washing();
    break;

      }
     }

}



