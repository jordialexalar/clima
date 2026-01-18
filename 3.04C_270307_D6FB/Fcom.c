

     /* MODULO FCOM.C            */


    /*Contiene funciones relacionadas con la comunicaci¢n del fot¢metro*/





#include <io51.h>
#include <math.h>
#include <fdefines.h>
#include <fexterns.h>

char carff[]={0xff,0x00};

  iniz_com()
  {
       TMOD=TMOD & 0x0F;
       TMOD=TMOD | 0x20;
       SCON=0x50;
       SM0=0;
       SM1=1; /* 8 BITS FRECUENCIA VARIABLE  SIN PARIDAD -> MODO 1 (1 st bit)*/
       REN=1;
       ES=1;
       ET1=0;
       EA=1;
       TH1=0xe6;  /*velocidad: 1200  */
       TR1=1;
       RI=0;
       PCON=0x80;  /* DOBLA LA VELOCIDAD A 2400 */
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
       rec++;
      }

  }



 emp_com()
 {
   iniz_com();
 }

 aca_com()
 {
    ES=0;
 }






 env_res(con,go)
 char con[];
 int go;
 {int i,j;
  char text[25];
  select_canal(1);
  for(i=0;i<200;i++)
   mensaje[i]=0x00;

   emp_com();
  i=0;
  while (con[i]!=0x00)
   {
    mensaje[i]=con[i];
    i++;
   }

  if (go!=99)
   {
       strcpy(text,units[go]);
       i=10;
       j=0;

       while (text[j]!=0x00)
    {
       mensaje[i]=text[j];
       i++;
       j++;
    }
   }

   text[0]=dd[0];
   text[1]=dd[1];
   text[2]='/';
   text[3]=mm[0];
   text[4]=mm[1];
   text[5]='/';
   text[6]=yy[0];
   text[7]=yy[1];
   text[8]=yy[2];
   text[9]=yy[3];
   text[10]=0x0;
    i=20;
    j=0;
       while (text[j]!=0x00)
    {
       mensaje[i]=text[j];
       i++;
       j++;
    }

   i=0;
   envia_car(0x03);
   while (i<30)
    {
      envia_car(mensaje[i]);
      i++;
    }
   envia_car(0x04);
   aca_com();
 }







  rec_file()
  {
    int i;
    int co;
    int salir;
    int recoge=0;
    char *p;
    p=&ficher[0];
      select_canal(1);
       ES=0;
        rec=0;
       ocupado=0;
       mensaje_recibido=0;
       emp_com();
       salir=0;
       i=0;
       salir=100;
       borrar();
       say(2,1,textos[182+idioma_textos]);
       say(3,1,"2400 8  NO P  1 ST");
       co=0;
       recibiendo_fichero=1;
       while (salir==100)
       {
        salir=mira_tec();
        if (car_recib>0)
         {
          switch(car_rec)
          {
          case STX:
        recoge=1;
        break;

          case ETX:
        recoge=0;
        salir=0;
        break;

          default:
           {
        if (recoge==1)
        {
         *p=car_rec;
         p++;
         i++;
         if (i>16100)
          {
            recoge=0;
            salir=0;
          }
        }
           }
           break;
          }
        car_recib=0;
         }
       }
       recibiendo_fichero=0;
       REN=0;
       ocupado=1;
       aca_com();
       borrar();
       EA=1;

  }



env_file()
{
    int i;
    int j;
    int co;
    int salir;
    int recoge=0;
    char *p;
    p=&ficher[0];
      select_canal(1);
       ES=0;
        rec=0;
       ocupado=0;
       mensaje_recibido=0;
       emp_com();
       salir=0;
       i=0;
       say(2,2,textos[183+idioma_textos]);
       say(3,1,"2400 8  NO P  1 ST");
       co=0;
       j=0;
       envia_car(STX);
       while (j<16100)
         {
          envia_car(*p);
          j++;
          p++;
         }
        envia_car(ETX);

       aca_com();
       borrar();
}











envia_car(a)
char a;
{
int j;
 car_env=1;
 SBUF=a;
 while (car_env==1)
   j=j;
/* retardo(20);*/
}




borra_tecs()
{
int i;
int j;
 for(i=0;i<100;i++)
 {apunta(i,0);
  for (j=0;j<long_ficha;j++)
   {*pficher=0x00;
    pficher=pficher+1;
   }
 }
}

select_canal(i)
int i;
{
    if (i==1)
     {
      reset_bit(5,3);
      set_bit(5,1);
     }
    else
     {
      set_bit(5,3);
      reset_bit(5,1);
     }

}
