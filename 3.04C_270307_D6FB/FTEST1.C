

       /*  MODULO FTEST.C               */

      /*  Contiene funciones para testear diferentes partes del fotometro*/



#include <io51.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>


#include <fdefines.h>




#include <fexterns.h>

extern long int tiempo_desc();


  test()

  {
   int salir=0;
   int ghj,i,j;

   borrar();






   /*comienzo del bucle princial*/


      for(;;)
      { int sal=0;
       unsigned char numix[10];
       double j=0.00;
       int pul=100;

      say(1,0,"NUMERO DE TEST:");
      sal=get(1,0+strlen("NUMERO DE TEST:"),ent,2,1,1);
      if (sal==novalid)
	break;

        pul=arflot(ent);


       if (pul<100)

       { borrar();

	switch(pul)
	 {int y,ty;
          int err=0;
	  int pul=0;
          long int cero,tiempo1;

	  char absor[6];
	  double abs,rt;
	  unsigned char sal;
	  int j;
          unsigned char num,*p;
          unsigned char numi[25];
          unsigned char numix[25];
	  char nu[25];
	  int t1=0;
	  int t2=0;
	  double hi;

	 case 1:
             test_filtros();
	     break;
         case 2:
             test_filtros_paso();
	     break;

	 case 6:
             if (posicion_inicial())
	      aviso(1,1,"POSICION INICIAL ENCONTRADA");
             break;




         case 30:
	    test_temporizador();
	    break;



         case 3:
	     motor_filtro(on);
             paso_i(48);
	     motor_filtro(off);
             break;

         case 10:     /*introduce tecnicas*/
            rellena();
	    break;




         case 60:
	    test_per2();
            break;

         case 61:
	    test_per1();
            break;




	 case 80:
	    test_temp();
            break;

	 case 85:
	    test_serv();
            break;

         case 88:
	    env_res();
            break;

         case 89:
	    recep();
            break;

         case 90:
	  env_tec();
	  break;

         case 91:
	  rec_tec();
	  break;

         case 99:
	  env_res();
	  break;
	 }
        }
     }

}






 test_filtros()
 {
  int n;
  char f[2];
  f[1]='\0';
  for (n=1;n<9;n++)
   {f[0]=n+48;
    say(2,1,"FILTRO:    ");
    say(2,1+strlen("FILTRO:"),f);
    pon_filtro(f);
    espera(0,3);
    }
  }




 test_filtros_paso()
{
 int i=0;
 double r=0;
 char ri[8];
 int z;
 unsigned int n=0;
 borrar();

 if (posicion_inicial())
   {
     say(1,1,"TESTEANDO FILTROS:");

    for (i=0;i<48;i++)
    { paso_i(1);
      r=i;
      flotar(ri,r,0);
      say (2,1,ri);
      pita(20);
      espera(0,3);

     }


   }
   else
   {aviso(1,1,"ERROR EN EL DISCO DE FILTROS");
   }
    return(z);
 }





   test_temp()
   {  int err=0;
      int salir=0;
      unsigned char h=0x00;

            borrar();
            say(1,0,"TEMPERATURA:      ");
            err=get(1,0+strlen("TEMPERATURA:"),ent,3,1,1);
	    borrar();
            if (err!=novalid)
	    {
	      pon_temp(ent);
 	      say (1,5,ent);
             }
            while (salir==0)
	    {
             h=read_XDATA(0xa002);
             h=h & 0x02;
	     if (h==0x02)
	      {
		aviso(3,3,"TEMPERATURA ALCANZADA, PULSE TECLA ...");
                salir=1;
	      }
	     if (mira_tec()!=100)
	      salir=1;

       }
      }




   rellena()
   {
      int i=0;
      while(i<100)
      {

   strcpy(ficher[i].code,"1");   /*pto. final bi*/
   strcpy(ficher[i].tipo,"1");
   strcpy(ficher[i].wl1,"4");
   strcpy(ficher[i].wl2,"2");
   strcpy(ficher[i].units,"1");
   strcpy(ficher[i].temp,"37");
   strcpy(ficher[i].std,"160.0");
   strcpy(ficher[i].factor,"103.0");
   strcpy(ficher[i].limlin,"400.0");
   strcpy(ficher[i].normalt,"105.0");
   strcpy(ficher[i].normbaj,"70.00");
   strcpy(ficher[i].sampvol,"10");
   strcpy(ficher[i].reacvol,"1000");
   strcpy(ficher[i].sipvol,"850");
   strcpy(ficher[i].readdly,"2");
   strcpy(ficher[i].reactime,"900");
   strcpy(ficher[i].absorblim,"00");
   strcpy(ficher[i].numlects,"0");
   strcpy(ficher[i].intertime,"0");
   strcpy(ficher[i].delay,"0");
   strcpy(ficher[i].dtabsmax,"0");
   strcpy(ficher[i].decs,"2");
   ficher[i].pos_grabada='*';
   i++;
   }
   }





 test_per2()
{
 int i=0;
 double r=0;
 int y=0;

     y=100;
    motor_peris(on);
    per_pasos(200,0);
    motor_peris(off);

 }


 test_per1()
{
 int i=0;
 double r=0;
 int y=0;
    motor_peris(on);

     y=100;

   while(y==100)
   {
    per_pasos(200,0);

 }
    motor_peris(off);
}





  test_temporizador()
  {
   int min,seg,i;
   int tec;

   char hora[25];
   char n[25];
   min=0;
   seg=0;
   borrar();
   strcpy(hora,"00:00");
   say(2,2,hora);
   tec=100;
   espera(0,1);
   while (tec==100)
   {
     pon_time(0,1);
     seg++;
     if (seg==60)
      {seg=0;
       min++;
      }
     if (min<10)
      { strcpy(hora,"0");
      }
      else
      {strcpy(hora,"");
      }

      intar(n,min);
      strcat(hora,n);
      strcat(hora,":");

     if (seg<10)
      { strcat(hora,"0");
       intar(n,seg);
       strcat(hora,n);
      }
      else
      {
       intar(n,seg);
       strcat(hora,n);
      }

     say(2,2,hora);

    while(time==0x00)
     i=i;

    tec=mira_tec();

    }
    }



 test_serv()
{unsigned char pasos[4];
 int salir=0;
 int j;
 int i=0;
 unsigned char pas;
 pasos[0]=0x99;
 pasos[1]=0xcc;
 pasos[2]=0x66;
 pasos[3]=0x33;

           while (salir==0)
	    {
	     if (mira_tec()!=100)
	      salir=1;
              pas=pasos[i];
   write_XDATA(0xa000, pas);
   i=i+1;
   if (i > 3)
     i=0;
   for (j=0;j<25;j++)
   j=j;

 }
 }




