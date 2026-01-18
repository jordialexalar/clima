
         /*  MODULO F100.C            */

         /*  Modulo que contiene el bucle principal del programa*/


#include <io51.h>
#include <stdio.h>


#include <fdefines.h>
#include <fvars.h>




  main()
  {
   int ghj,i,j;
   char ent[10];

       inicializacion();

       check();
/*       P1.5=0; */
/*      pon_fecha();*/
      borrar();
	    if (modelo==CLIMA_PLUS)
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


test_tec()
{
char text[10];
     for(;;)
     {

       if (tecla==0xff)
         {
           say(3,1,"TECLA_PULS");
	   intar(text,lastkey1);
	   say(4,1,text);

	   espera(0,2);
	   tecla=0x00;
	   say(3,1,"          ");
	   say(4,1,"          ");
	 }
     }



}

