
                     /* MODULO FINTER2.C   */

#include <io51.h>
#include <math.h>

#include <fdefines.h>
#include <fexterns.h>


  /* FUNCIONES PARA LOS TEMPORIZADORES  */



interrupt void T1_int()
  {
  /* 50 mseg  */
/*   TH1=0x3c;
     TL1=0xaf;*/

  /* 1 mseg  */
   TH1=0xfc;
   TL1=0x17;
   base_de_tiempos();






/*  if (display_temp==on && temp_alcanz==0 && disp_say==0 && disp_get==0 && calc_abs==0)
     {
	time_temp++;
        tempo_temp();
     }
        */
 }


tempo_temp()
{
      if (time_temp>10)
	 {
	     time_temp=0;
             temper=PA002;
             temper=temper & 0x02;
	     if (temper==0x02)
	      {
		   temp_puesta=on;
		   escribe_temp();
	       temp_alcanz=1;
	      }
	     else
	      {
		if (temp_puesta==on)
		 {
		   temp_puesta=off;
                   escribe_temp();
		 }
		else
		 {
		   temp_puesta=on;
		   escribe_temp();
		 }
	      }

         }
}




 escribe_temp()
  {
      for (tempi=0;tempi<=1;tempi++)
       {
         temper=PD002;
	 temper=temper & 0xfe;
	 PD002=temper;

         temper=PD002;
	 temper=temper & 0xfd;
	 PD002=temper;

         temper=PD002;
	 temper=temper | 0x04;
	 PD002=temper;

         PD001=0x80 + 18 +tempi;

         temper=PD002;
	 temper=temper & 0xfb;
	 PD002=temper;

         temper=PD002;
	 temper=temper & 0xfe;
	 PD002=temper;

         temper=PD002;
	 temper=temper & 0xfd;
	 PD002=temper;

         for (tempi1=0;tempi1<=100;tempi1++)
	   tempi1=tempi1;


         temper=PD002;
	 temper=temper | 0x01;
	 PD002=temper;

         temper=PD002;
	 temper=temper | 0x04;
	 PD002=temper;

         if (temp_puesta==off)
             PD001=' ';
         else
	     PD001=temperat[tempi];

         temper=PD002;
	 temper=temper & 0xfb;
	 PD002=temper;

         temper=PD002;
	 temper=temper & 0xfe;
	 PD002=temper;
         for (tempi1=0;tempi1<=100;tempi1++)
	   tempi1=tempi1;

      }
   }




       clock()
       {
	reloj_tic++;
	if (reloj_tic>=20)
          {
	   reloj_tic=0;
	   reloj_seg++;
 	   if (reloj_seg>=60)
               {
	         reloj_seg=0;
	         reloj_min++;
 	         if (reloj_min>=60)
                    {
	        	reloj_min=0;
		        reloj_hr++;
 	                if (reloj_hr>=24)
                           {
		               reloj_hr=0;
                           }

	             }
	       }
         }
    }





 base_de_tiempos()
  {
   tempo2=tempo2+1;

   if (tempo2>=mili_secs)
   { tempo2=0;
     time_mili=0xff;
   }


   tempo1=tempo1+1;

   if (tempo1>=1000)
   { tempo1=0;
    if(segundo > 0)
     segundo=segundo-1;

     if (segundo <=0)
      { time=0xff;
       }
   }

  }

