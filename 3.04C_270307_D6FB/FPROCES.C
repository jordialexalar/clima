
    /*  MODULO FPROCES.C                */
    /*  Contiene funciones que ejecutan las t‚cnicas*/



#include <io51.h>
#include <math.h>
#include <fdefines.h>
#include <ctype.h>
#include <string.h>
#include <fexterns.h>



  haz(pul)
  int pul;
  {

       double hi=0.00;
       int err=0;
       int cual;
       borrar();

       if (grabada(pul)==0)
     return;

    borrar();
    apunta(pul,TIPO);
    cual=arflot(pficher);
        borrar();


/*    if (printtec==1)
    imprime_tecnica(pul);
        */
    inic_pac();
    carry=0;
    abs_ant=0.0;
    abs_act=0.0;
    
    haz_tecnica(pul,cual);
    time_temp=0;
    display_temp=off;
    inic_pac();
   }







   cab_resul(n,que_tec)
   int n;
   int que_tec;

  {
    char text[25];
    int go;
    limpia_informe();
    lineasinforme = 0;
    poneninforme(0,0,textos[6+idioma_textos]);

       strcpy(text,dd);
       poneninforme(1,1,text);

       poneninforme(1,3,textos[7+idioma_textos]);

       strcpy(text,mm);
       poneninforme(1,4,text);

       poneninforme(1,6,textos[7+idioma_textos]);

       strcpy(text,yy);
       poneninforme(1,7,text);

       apunta(que_tec,IDEN);
       go=arflot(pficher);
       strcpy(text,codigos[go+pos_ini_cod]);
       poneninforme(1,12,text);


       intar(text,que_tec);
       poneninforme(1,20,text);

       apunta(que_tec,TIPO);
       go=arflot(pficher);
       strcpy(text,tipos[go]);
       poneninforme(2,0,text);





       if (n>ABS && n!=MSTD)
      {
       poneninforme(2,7,textos[8+idioma_textos]);

       apunta(que_tec,FACTOR);
       strcpy(text,pficher);
       poneninforme(2,7+strlen(textos[8+idioma_textos]),text);
      }

       apunta(que_tec,TEMP);
       strcpy(text,pficher);
       poneninforme(3,0,text);

    if (contrafact(que_tec)==0 && n>ABS)
    {
    poneninforme(3,7,textos[9+idioma_textos]);

    apunta(que_tec,STD);
    strcpy(text,pficher);
    poneninforme(3,7+strlen(textos[9+idioma_textos]),text);

    }



    poneninforme(4,0,textos[10+idioma_textos]);
    apunta(que_tec,WL1);
    go=arint(pficher);
    strcpy(text,wl[go]);
    poneninforme(4,0+strlen(textos[10+idioma_textos]),text);

       if (n!=CIN && n!=FXT)
       {
       apunta(que_tec,WL2);
       go=arint(pficher);
       if (go > 0)
       {
     poneninforme(4,10,textos[11+idioma_textos]);

         strcpy(text,wl[go]);
         poneninforme(4,10+strlen(textos[11+idioma_textos]),text);

       }

      }

    lineasinforme=4;
  if (n>ABS)
   {
    poneninforme(5,0,textos[12+idioma_textos]);


    apunta(que_tec,SAMP_VOL);
    strcpy(text,pficher);
    poneninforme(5,0+strlen(textos[12+idioma_textos]),text);

    poneninforme(6,0,textos[13+idioma_textos]);


    apunta(que_tec,REAGENT_VOL);
    strcpy(text,pficher);
    poneninforme(6,0+strlen(textos[13+idioma_textos]),text);
    lineasinforme=6;
    }
    lineasinforme++;

    if (n==CONC || n==DIF || n==REL || n==MSTD)
    {
    poneninforme(lineasinforme,0,textos[62+idioma_textos]);
    apunta(que_tec,REACTION_TIME);
    strcpy(text,pficher);
    poneninforme(lineasinforme,0+strlen(textos[62+idioma_textos]),text);
    lineasinforme++;
    }


       if (n==MSTD)
       {
          imp_puntos(que_tec);
       }

    poneninforme(lineasinforme,0,textos[6+idioma_textos]);
    lineasinforme++;
    impinforme(lineasinforme,12,40);

    }



/* inc_numpac()
  {double paciente;
   paciente=arflot(pac);
   if (paciente < 0 || paciente == 999)
     paciente = 0;
   else
     paciente = paciente + 1;

     flotar(pac,paciente,0);

   }

   */

  inic_pac()
  {
   intar(pac,1);
   muestra=1;
   muestra_ant=0;
  }

absorbe(sip)
double sip;
{
int pas=0;
int j=100;
double h=0.0;
char text[20];
if (sip>0.0 && con_peristaltica==1)
 {

    pas=(sip/5000)*cal_per;
    per_pasos(pas,0);
    pita(1);
    espera(0,t_esp_aut);

    pas=(vol_auto/5000)*cal_per;
    per_pasos(pas,0);


 }
}



form_pan(pul)
int pul;
{
char text[12];
int go;

                        say(1,0,textos[18+idioma_textos]);
                        intar(text,pul);
                        say(1,0+strlen(textos[18+idioma_textos]),text);
            apunta(pul,IDEN);
            go=arint(pficher);
                        strcpy(text,codigos[go+pos_ini_cod]);
            say(1,10,text);

            apunta(pul,TEMP);
                        strcpy(temperat,pficher);
            time_temp=0;
            if (*pficher=='T')
                         {
              display_temp=off;
                          temp_alcanz=1;
             }
            else
             {
              display_temp=on;
               temp_alcanz=0;
                         }
                        apunta(pul,TIPO);
                        go=arint(pficher);
            strcpy(text,tipos[go]);
            say(2,0,text);
    }




cojo_parametros(pul,cual)
int pul;
int cual;
{
     apunta(pul,TEMP);
     pon_temp(pficher);

     apunta(pul,WL1);
     strcpy(wl1,pficher);
     pon_filtro(wl1);

     apunta(pul,WL2);
     strcpy(wl2,pficher);

   valsup=lee_parametro_double(pul,NORM_ALTO);
   valinf=lee_parametro_double(pul,NORM_BAJO);
   valabsorblim=lee_parametro_double(pul,ABSORB_LIM);
   vallimlin=lee_parametro_double(pul,LIN_LIM);
   factor=lee_parametro_double(pul,FACTOR);
   decimales=lee_parametro(pul,DECIMALES);
   retardo_cero=0;

   switch (cual)
   {
     case ABS:
    lecturas=1;
    decimales=3;
    sipping=lee_parametro_double(pul,SIPPING_VOL);
    delay=lee_parametro(pul,READING_DLY);
    espera_cero=delay;
    retardo_cero=delay;
    interv=0;
       break;

     case CONC:
       lecturas=1;
       delay=lee_parametro(pul,READING_DLY);
       espera_cero=delay;
       retardo_cero=delay;
       sipping=lee_parametro_double(pul,SIPPING_VOL);
       interv=0;
       break;

     case CIN:
       sipping=lee_parametro_double(pul,SIPPING_VOL);
       lecturas=lee_parametro(pul,N_OF_READINGS);
       if (lecturas > 50)     /* EVITO NUMERO DE LECTURAS MAYOR DE 50 */
      lecturas=50;
       delay=lee_parametro(pul,DELAY);
       interv=lee_parametro(pul,INTERVAL_TIME);
       escribe(pul,CONTRA_FACTOR,"1");
       break;

     case FXT:
       sipping=lee_parametro_double(pul,SIPPING_VOL);
       lecturas=2;
       delay=lee_parametro(pul,DELAY);
       interv=lee_parametro(pul,INTERVAL_TIME);
       break;

     case DIF:
       sipping=lee_parametro_double(pul,SIPPING_VOL);
       lecturas=2;
       delay=lee_parametro(pul,READING_DLY);
       espera_cero=delay;
       retardo_cero=delay;
       interv=delay;
       break;

     case REL:
       sipping=lee_parametro_double(pul,SIPPING_VOL);
       lecturas=2;
       delay=lee_parametro(pul,READING_DLY);
       espera_cero=delay;
       retardo_cero=delay;
       interv=delay;
      break;

     case MSTD:
       sipping=lee_parametro_double(pul,SIPPING_VOL);
       lecturas=1;
       lecturas2=lee_parametro(pul,N_OF_READINGS); /*lecturas por estandar*/
       referencia=lee_parametro(pul,VARIOS_STD);
       apuntastd(referencia,0,0,0);
       fpuntos=arint(pficherstd);
       lecturas1=lecturas2*fpuntos;

    interv=0;
    delay=lee_parametro(pul,READING_DLY);
    espera_cero=delay;
    retardo_cero=delay;
    interv=delay;
    break;
   }
  if (carry_over==1)
   {
    if (sipping>=751.0)
    porcen_carry=porcen_macro;
    if (sipping<751.0 && sipping>500.0)
    porcen_carry=porcen_semimicro;
    if (sipping<=500.0)
    porcen_carry=porcen_micro;
   }

}


correcion_carry()
{
double h;
h=(incabs-abs_ant);
if (h<0.0)
 h=h*-1.0;
if (h<=dif_carry || dif_carry==0.0)
  incabs=(incabs-abs_ant)*(porcen_carry/100.0)+incabs;
else
  abs_act=abs_ant;
}



conc_final(pul,cual)
int pul;
int cual;
{
      fuera_de_rango_max=0;
      fuera_de_rango_min=0;

    switch (cual)
    {
      case ABS:
      conc=incabs;
      break;

      case MSTD:
      ji=0;

/*      conc=0;*/
      conc=(incabs*m[fpuntos-1])+n[fpuntos-1];

      fuera_de_rango_max=1;
      fuera_de_rango_min=0;

      while (ji < fpuntos)
       {
        if (incabs < fpuntosx[ji])
        {
          if (ji > 0)
          {
           conc=(incabs*m[ji])+n[ji];
           fuera_de_rango_max=0;
           fuera_de_rango_min=0;
          }
          else
          {
        conc=0;
           fuera_de_rango_max=0;
           fuera_de_rango_min=1;
          }
           ji=fpuntos+4;
        }

        ji++;
      }
      break;

    default:
       conc=incabs*factor;
       break;
       }


     /*  SACO EL VALOR SIEMPRE POSITIVO  EXCEPTO EN CIN DIF FXT*/

     if (conc < 0 && (cual==CIN || cual==FXT || cual==DIF))
    conc=conc * -1.0;


    /* SACO RESULTADO POR PANTALLA */
    flotar(con,conc,decimales);
    say(3,5,"               ");
    say(3,5,con);
    if (cual != ABS)
      {
       go=lee_parametro(pul,UNITS);
       say(3,14,units[go]);
      }
    else
      go=99;

    /* SACO RESULTADO POR CANAL_SERIE */
     if (a_control==1)
       error_control=env_qc(pul,con);

     env_res(con,go);

     if (cual==CIN || cual==FXT)
        pita(6);

    /* SACO RESULTADO POR IMPRESORA */

    if (cual==CIN)
      {
        flotar(con1,desv_std,3);
        lineasinforme++;
        lineasinforme++;
        strcpy(text,"D. S.:");
        poneninformetxt(lineasinforme,1,textos[42+idioma_textos],con1);
      }

       lineasinforme++;
       poneninforme(lineasinforme,8,con);
       if (error_control==1)
     poneninforme(lineasinforme,17,"*");

       if (cual != ABS)
       {
     strcpy(text,units[go]);
     poneninforme(lineasinforme,1,text);

       if (a_control==0)
       {
    if (fuera_de_rango_max==1)
    {lineasinforme++;
     poneninforme(lineasinforme,1,"AL.:");
     poneninforme(lineasinforme,6,"F.R. MAX");
    }
    else
    {
    if (fuera_de_rango_min==1)
      {lineasinforme++;
       poneninforme(lineasinforme,1,"AL.:");
       poneninforme(lineasinforme,6,"F.R. MIN");
      }

    else
     {
       lineasinforme++;
       if (valsup < conc)
        {
         poneninforme(lineasinforme,1,"AL.:");
         poneninforme(lineasinforme,6,textos[67+idioma_textos]);
        }

       if (vallimlin < conc)
        {
         poneninforme(lineasinforme,1,"AL.:");
         poneninforme(lineasinforme,9,"LL");
        }
       if (valinf > conc)
        {
         poneninforme(lineasinforme,1,"AL.:");
         poneninforme(lineasinforme,6,textos[68+idioma_textos]);
        }
      }

    }
       }
       }
    lineasinforme++;
    impinforme(lineasinforme,12,30);
    error_control=0;
    a_control=0;
}



abs_total(pul,cual)
int pul;
int cual;
{
int i;
     incabs=0.0;

      switch (cual)
      {
    case ABS:
     incabs=incs[0];
     break;

    case CONC:
     incabs=incs[0];
     break;

    case MSTD:
     incabs=incs[0];
     break;

    case REL:
     incabs=incs[0]/incs[1];
     break;

    default:
        for (i=0;i<(lecturas-1);i++)
         incabs=incs[i]+incabs;

         if (lecturas > 1)
           {
           incabs=(incabs/(lecturas-1));
           if (cual==CIN)
            {
              desv_std=0.0;
              if (lecturas > 2)
                 {
                 for (i=0;i<(lecturas-1);i++)
                 desv_std=flotpower(incs[i]-incabs,2)+desv_std;
                 desv_std=desv_std/(lecturas-2);
                 if (desv_std==0.0 || desv_std <0.0)
                       desv_std=0.0;
                 else
                       desv_std=sqrt(desv_std);

                   }


              }
         }

           if (cual == CIN)
          incabs=incabs*(60.0/interv);
           break;

      }
 }


cal_final(pul,cual)
int pul;
int cual;
{
if (cual!=MSTD)
 {
   std=arflot(estan);
   factor=std/incabs;
       /* CAMBIO EL FACTOR A POSITIVO EN CASO DE SER NEGATIVO */
   if (factor < 0.0)
      {
    factor=factor* -1.0;
      }
   flotar(text,factor,2);
   ajusta(text,6);
   escribe(pul,FACTOR,text);
   escribe(pul,STD,estan);
   cal++;
   limpia_informe();
   lineasinforme=0;
   apunta(pul,FACTOR);
   strcpy(text,pficher);
   poneninforme(lineasinforme,0,textos[8+idioma_textos]);
   poneninforme(lineasinforme,8,text);
   lineasinforme++;
   poneninforme(lineasinforme,0,textos[9+idioma_textos]);
   poneninforme(lineasinforme,8,estan);
   lineasinforme++;
   impinforme(lineasinforme,12,40);
 }
else
 {
   cal++;
   lecturas=1;
   referencia=lee_parametro(pul,VARIOS_STD);
   apuntastd(referencia,0,0,0);
   fpuntos=arint(pficherstd);
   limpia_informe();
   lineasinforme=0;
   for(ji=0;ji<fpuntos;ji++)
     {
    apuntastd(referencia,1,PX,ji);
    fpuntosx[ji]=arflot(pficherstd);
    lineasinforme++;
    poneninforme(lineasinforme,4,pficherstd);
    apuntastd(referencia,1,PY,ji);
    fpuntosy[ji]=arflot(pficherstd);
     }
   lineasinforme++;
   impinforme(lineasinforme,12,12);

   for(ji=0;ji<fpuntos;ji++)
     { if (ji>0)
     {
        m[ji]=(fpuntosy[ji]-fpuntosy[ji-1])/(fpuntosx[ji]-fpuntosx[ji-1]);
        n[ji]=(fpuntosy[ji])-(fpuntosx[ji]*m[ji]);
     }
     }

 }
}
