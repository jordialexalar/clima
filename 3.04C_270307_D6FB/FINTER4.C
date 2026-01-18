

         /* MODULO FINTER4         */





#include <io51.h>
#include <math.h>
#include <fdefines.h>
#include <fexterns.h>








interrupt void SCON_int()
  {
      EA=0;

      if (RI==1)
        {
         car_rec=SBUF;
	 rec++;
         recep1();
         RI=0;
         }


     if (TI==1)
     {
      car_env=0;
      TI=0;
      veces1++;
     }



  EA=1;
  }






 recep1()
 {
         if (car_rec==0x01)
	  {
            if (ocupado==1)
	     {
	      mensaje_recibido=0;
	      SBUF=0x07;
	     }
	    else
	     {
	      SBUF=0x06;
	     }

          }

         if (car_rec==0x03 )
	  {rec=0;
	   mensaje_recibido=0;
	   recibiendo_mensaje=1;
	  }

         if (car_rec==0x04 )
	  {mensaje_recibido=1;
  	   recibiendo_mensaje=0;
	   mensaje[rec]=car_rec;
	  }
         if (recibiendo_mensaje==1)
	  {
           mensaje[rec]=car_rec;
	  }
  }