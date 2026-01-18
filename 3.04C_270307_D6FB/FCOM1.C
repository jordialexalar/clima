

         /* MODULO FCOM.C            */


        /*Contiene funciones relacionadas con la comunicaci¢n del fot¢metro*/





#include <io51.h>
#include <math.h>
#include <fdefines.h>
#include <fexterns.h>






 int sigue_enviando;
 int car_env;
 long int veces1;
 long int car_rec;
  comu()

  {   unsigned char ret;
      double vez;
      char jd[20];

      ret=SCON;

      ret=ret & 0x03;

    if (ret==0x01)  /*es una recepcion*/
       {
         *rec=SBUF;
         RI=1;
         rec++;
	 car_rec++;

       }


        else{  /* es una interrupcion de transmision*/

       TI=0;
       car_env++;
  }
  }







  env_res()   /*rutina que envia los resultados*/
   {
      int i;
      unsigned char reg;
      unsigned char reg1;
      unsigned char reg2;
      unsigned char reg3;
      unsigned char reg4;
      unsigned char reg5;
      unsigned char reg6;


      char p[]={0x0d,0x0a,0x01,'\0'};
      menp=mens;

      rec=recip;
      strcpy(mens,"HOLA QUE TAL");

     strcat(mens,p);

      aviso(1,1,mens);


         PCON=0x00;

	 reg=TMOD;
	 reg=reg & 0x0f;
	 reg=reg | 0x20;
         TMOD=reg;


           SM1=1;  /* 8 BITS FRECUENCIA VARIABLE */

           REN=1;
           ES=1;

           ET1=0;
           EA=1;

           TH1=0xe6;  /*velocidad: 1200 */
           TR1=1;


           SBUF=*menp;

         estado_canal_serie=on;


	 while (estado_canal_serie==on)
	 {i=i;
	 }

        if (estado_canal_serie==on)
	  {
	   borrar();
	   say(2,2,"grave error de comunicaci¢n");
	   }

	  SCON=0x00;
          TMOD=reg1;
          TCON=reg2;
          PCON=reg3;
          IE=reg4;
          IP=reg5;
          SCON=reg6;


  }





  recep()   /*rutina que recibe*/
   {
      int i;
      unsigned char reg;
      rec=recip;

         PCON=0x00;

	 reg=TMOD;
	 reg=reg & 0x0f;
	 reg=reg | 0x20;
         TMOD=reg;


           SM1=1;  /* 8 BITS FRECUENCIA VARIABLE */

           REN=1;
           ES=1;

           ET1=0;
           EA=1;

           TH1=0xe6;  /*velocidad: 1200 */
           TR1=1;



         estado_canal_serie=on;


	 while (estado_canal_serie==on)
	 {i=i;
	 }


	  SCON=0x00;

          aviso(2,2,recip);
  }









  env_tec()
  {
    unsigned char reg;
    char *p;
    char text[25];
    double j;
    int h;
    int i;
    char tec1[3];
    char tec2[3];
    int pul1=0;
    int pul2=0;
    int err;
    int salir;
       rec=recip;
       borrar();
       say(1,1,"ENVIO DE TECNICAS");
       keyboard(0);

      *menp=0x06;
      veces=0;

         PCON=0x00;

	 reg=TMOD;
	 reg=reg & 0x0f;
	 reg=reg | 0x20;
         TMOD=reg;


           SM1=1;  /* 8 BITS FRECUENCIA VARIABLE */

           REN=1;
           ES=1;

           ET1=0;
           EA=1;

           TH1=0xe6;  /*velocidad: 1200 */
           TR1=1;

           while (recip[0]!=0x01)
	   {i=i;
	   }
           aviso(1,1,"ya ha llegado");

           car_env=0;
           SBUF=*menp;
           while (car_env==0)
	    i=i;

	    aviso(1,1,"enviado 6");

            menp=&ficher[0];

         estado_canal_serie=on;

         salir=0;
	 veces1=0;
	 while (salir==0)
	 {
           car_env=0;
           SBUF=*menp;
           while (car_env==0)
	    i=i;
	    menp++;
	    veces1++;
            if (veces1>14060)
                salir=1;
	 }
          *menp=0x04;
           car_env=0;
           SBUF=*menp;
           while (car_env==0)
	    i=i;

	  SCON=0x00;

 }







  rec_tec()
  {
    unsigned char reg;
    char *p;
    char text[25];
    double j;
    int h;
    int i;
    char tec1[3];
    char tec2[3];
    int pul1=0;
    int pul2=0;
    int err;
    int salir;
       rec=recip;
       borrar();
      *menp=0x06;
      veces=0;

         PCON=0x00;

	 reg=TMOD;
	 reg=reg & 0x0f;
	 reg=reg | 0x20;
         TMOD=reg;


           SM1=1;  /* 8 BITS FRECUENCIA VARIABLE */

           REN=1;
           ES=1;

           ET1=0;
           EA=1;

           TH1=0xe6;  /*velocidad: 1200 */
           TR1=1;

           while (recip[0]!=0x01)
	   {i=i;
	   }
           aviso(1,1,"ya ha llegado");
            rec=&ficher[0];

           car_env=0;
           SBUF=*menp;
           while (car_env==0)
	    i=i;

/*	    aviso(1,1,"enviado 6");*/

         estado_canal_serie=on;

         salir=0;
	 veces1=0;
	 car_rec=0;
	 while (car_rec <14060)
	 {
          i=i;
	 }

	  aviso(1,1,"YA HA ACABADO");
          *menp=0x06;
           car_env=0;
           SBUF=*menp;
           while (car_env==0)
	    i=i;

	  SCON=0x00;




 }



