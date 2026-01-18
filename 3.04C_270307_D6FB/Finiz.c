    /*  MODULO FINIZ.C                        */

    /* Modulo que contiene las rutinas de inicializaci¢n de los*/
    /* microcontroladores */


#include <io51.h>
#include <math.h>
#include <fdefines.h>
#include <fexterns.h>

  inicializacion()
  {
    int i,j;
    int p;          
    unsigned int rp; 
    char *prp;
    valor=100;

    paso=0;

    if (printtec!=0)
    printtec=1;

     inic_8231();

/*         P1.5=0; */

      TMOD=0x11;
     /*primero que idioma, despues que_veter,ya que funciona en funcion del idioma*/

      if (idioma<0 || idioma>2)
       idioma=0;

     que_idioma(idioma);

     que_veter(veters);

     n_filtros_tamb=8;

     retards();

     activa_timer(2);
     espera(0,1);


       inic_8279();

       inic_8255();
       printer(h);

      tco=0x86;

      iniz_lcd();

      inic_pot();

      if (control_fabricacion != APARATO_INICIADO)
       {
         prp=&control_diana[0];
         prp=prp-22;
         for (rp=0;rp<5016;rp++)
           {
            *prp=0x0;
             prp=prp+1;
           }
         
         iniz_fab();
       }  

      if (fact_peris<0.0 || fact_peris>3.0)
        fact_peris=0.0;

      if (dif_carry<0 || dif_carry>3)
        dif_carry=2.0;
        
      if (wipers[25]>100 || wipers[25] < 0 )
         wipers[25]=14;

      if (wipers[30]>100 || wipers[30] < 0)
          wipers[30]=44;

      if (wipers[37]>100 || wipers[37] < 0)
         wipers[37]=80;

      wl[7]=&filtro7[0];
      wl[8]=&filtro8[0];

      p=arint(filtro7);

      if (p<=0 || p>999)
        strcpy(filtro7,"---");

      p=arint(filtro8);
      if (p<=0 || p>999)
         strcpy(filtro8,"---");

      if (porcen_macro<=0 || porcen_macro>=100)
         porcen_macro=0;

      if (porcen_semimicro<=0 || porcen_semimicro>=100)
         porcen_semimicro=0;

      if (porcen_micro<=0 || porcen_micro>=100)
         porcen_micro=2;

      if (t_esp_aut<0 || t_esp_aut>15)
         t_esp_aut=2;
 
      if (vol_auto<0.0 || vol_auto >999.0)
         vol_auto=150.0;

      if (arflot(password)<=0.0)
        strcpy(password,"201168");

      if (desde_tecnica<0 || desde_tecnica>99)
        {
         desde_tecnica=0;                     
         hasta_tecnica=50;
        }  

      def_par();

      def_model();
      lee_fecha();

  }







inic_8231()
{
 IP=0x02;

 IE=0x00; /*desactivo interrupciones*/

 EA=1; /*activo interrupciones*/

 PT2=1;

 }



inic_8279()
{

 teclas[1]=9;
 teclas[2]=6;
 teclas[4]=3;
 teclas[8]=punt;
 teclas[16]=stop;
 teclas[32]=feed;
 teclas[128]=chupa;
 teclas[129]=8;
 teclas[130]=5;
 teclas[132]=2;
 teclas[136]=0;
 teclas[144]=read;
 teclas[257]=7;
 teclas[258]=4;
 teclas[260]=1;
 teclas[264]=cl;

 teclas[272]=cr;
 teclas[320]=print;
       tecla=0x0;
       lastkey=0x0;
       h=0x0;
       tco=0x0;
       ET1=1;

}







inic_8255()
{
int i;
p[0]=&PF000;
p[1]=&PF001;
p[2]=&PF002;
p[3]=&PF010;
p[4]=&PF011;
p[5]=&PF012;
p[6]=&PF020;
p[7]=&PF021;
p[8]=&PF022;

for (i=0;i<9;i++)
 puertos[i]=0x0;

 PF023=0x89; /*inicializacion del 8255*/
 /* PORT A OUTPUT ;  PORT B OUTPUT ; PORT C LOWER INPUT
    PORT C UPPER INPUT */

 PF003=0x89; /* inicializacion del 8255*/
 /* PORT A OUTPUT ;  PORT B OUTPUT ; PORT C LOWER INPUT
    PORT C UPPER INPUT */
 escribe_puerto(0,0);

 PF013=0x88; /* inicializacion del 8255*/
 /* PORT A OUTPUT ;  PORT B OUTPUT ; PORT C LOWER OUTPUT
    PORT C UPPER INPUT */
 escribe_puerto(7,0xff);

}





def_par()
{
int i;
       for(i=0;i<7;i++)
       {
          tipos[i]=textos[i+150+idioma_textos];
       }
       txt_prog[0]=textos[121+idioma_textos];
       txt_prog[1]=textos[122+idioma_textos];
       txt_prog[WL1]=textos[123+idioma_textos];
       txt_prog[WL2]=textos[124+idioma_textos];
       txt_prog[UNITS]=textos[125+idioma_textos];
       txt_prog[TEMP]=textos[126+idioma_textos];
       txt_prog[STD]=textos[127+idioma_textos];
       txt_prog[FACTOR]=textos[128+idioma_textos];
       txt_prog[LIN_LIM]=textos[129+idioma_textos];
       txt_prog[N_OF_READINGS]=textos[130+idioma_textos];
       txt_prog[INTERVAL_TIME]=textos[131+idioma_textos];
       txt_prog[DELAY]=textos[132+idioma_textos];
       txt_prog[ABSORB_LIM]=textos[133+idioma_textos];
       txt_prog[DT_ABSORB_MAX]=textos[134+idioma_textos];
       txt_prog[NORM_ALTO]=textos[135+idioma_textos];
       txt_prog[NORM_BAJO]=textos[136+idioma_textos];
       txt_prog[DECIMALES]=textos[137+idioma_textos];
       txt_prog[SAMP_VOL]=textos[138+idioma_textos];
       txt_prog[REAGENT_VOL]=textos[139+idioma_textos];
       txt_prog[SIPPING_VOL]=textos[140+idioma_textos];
       txt_prog[READING_DLY]=textos[141+idioma_textos];
       txt_prog[REACTION_TIME]=textos[142+idioma_textos];
       txt_prog[VARIOS_STD]=textos[143+idioma_textos];


       longitud[IDEN]=LIDEN;
       longitud[TIPO]=LTIPO;
       longitud[WL1]=LWL1;
       longitud[WL2]=LWL2;
       longitud[UNITS]=LUNITS;
       longitud[TEMP]=LTEMP;
       longitud[STD]=LSTD;
       longitud[FACTOR]=LFACTOR;
       longitud[LIN_LIM]=LLIN_LIM;
       longitud[N_OF_READINGS]=LN_OF_READINGS;
       longitud[INTERVAL_TIME]=LINTERVAL_TIME;
       longitud[DELAY]=LDELAY;
       longitud[ABSORB_LIM]=LABSORB_LIM;
       longitud[DT_ABSORB_MAX]=LDT_ABSORB_MAX;
       longitud[NORM_ALTO]=LNORM_ALTO;
       longitud[NORM_BAJO]=LNORM_BAJO;
       longitud[DECIMALES]=LDECIMALES;
       longitud[SAMP_VOL]=LSAMP_VOL;
       longitud[REAGENT_VOL]=LREAGENT_VOL;
       longitud[SIPPING_VOL]=LSIPPING_VOL;
       longitud[READING_DLY]=LREADING_DLY;
       longitud[REACTION_TIME]=LREACTION_TIME;
       longitud[VARIOS_STD]=LVARIOS_STD;
       longitud[CONTRA_FACTOR]=LCONTRA_FACTOR;
       longitud[POS_GRABADA]=LPOS_GRABADA;
       longitud[ABSORBLIMM]=LABSORBLIMM;

       offset[0]=0;
       long_ficha=0;
       for (i=1;i<26;i++)
       {
    offset[i]=longitud[i-1]+1+offset[i-1];

       }

       for (i=0;i<26;i++)
       {
          long_ficha=long_ficha+longitud[i]+1;
       }
       long_ficha_std=203;
   }




 def_model()
 {
   int i,j;

 if (lee_bit(2,6)==0)
      temperatura_fija=1;
 else
      temperatura_fija=0;      

  con_peristaltica=0;

 if (lee_bit(2,1)==1 && lee_bit(2,2)==1 && lee_bit(2,3)==1)
  {
   modelo=CLIMA_PLUS;               

  }
 if (lee_bit(2,1)==0 && lee_bit(2,2)==1 && lee_bit(2,3)==1)
  {
   modelo=CLIMA;
  }
 if (lee_bit(2,1)==1 && lee_bit(2,2)==0 && lee_bit(2,3)==1)
 {

   modelo=CLIMA_JR;
  }
 if (lee_bit(2,1)==1 && lee_bit(2,2)==1 && lee_bit(2,3)==0)
   {

   modelo=CLIMA_IRAN;
   }

 if (lee_bit(2,1)==1 && lee_bit(2,2)==0 && lee_bit(2,3)==0)
  {
   modelo=CLIMA_PLUS_SP;               

  }




/* La siguiente linea sirve para forzar el aparto a un modelo */ 
/*  modelo=CLIMA_IRAN;   */
  
 switch(modelo)
 {

 case CLIMA_JR:
        /*MODELO 1*/ /* 50 TECNICAS,NO TODOS LOS TIPOS,
        1  TEMPERATURA */
   temperatura_fija=2;        
   total_tecnicas=50;
   versi=2;
   carry_over=0;
   break;

 case CLIMA:
        /*MODELO 2*/ /*  100 TECNICAS,
         TODOS LOS TIPOS, 3 TEMPERATURAS */
   total_tecnicas=100;
   versi=1;
   carry_over=0;
   break;


 case CLIMA_PLUS:
   /*MODELO 3*/ /* PERISTALTICA, 100 TECNICAS,
     TODOS LOS TIPOS, 3 TEMPERATURAS */
   total_tecnicas=100;
   versi=0;
   con_peristaltica=1;
   break;


 case CLIMA_IRAN:
        /*MODELO 4*/ /* NO PERISTALTICA, 100 TECNICAS,
         TODOS LOS TIPOS, 1 TEMPERATURA */
temperatura_fija=2;  
   total_tecnicas=100;
   versi=3;
   carry_over=0;
   break;

 case CLIMA_PLUS_SP:
   /*MODELO 3*/ /* PERISTALTICA, 100 TECNICAS,
     TODOS LOS TIPOS, 1 TEMPERATURAS */
   temperatura_fija=2;        
   total_tecnicas=100;
   versi=0;
   con_peristaltica=1;
   break;
 


 }
   i=0;
   j=0;
   while (i<7)
   {

    if (parametros[j]==WL2 && modelo==CLIMA_JR)
    parametros[j]=NADA;

    if (parametros[j]==SIPPING_VOL && con_peristaltica!=1)
    parametros[j]=NADA;

    if (parametros[j]==FIN)
    i++;
   j++;
   }


}


check()
{
 borrar();
 say(2,7,textos[0+idioma_textos]);
 pon_filtro("1");
 pon_temp("37");


}

retards()
{
     int y;
     y=0;
      pon_time_mili(1);
    while (time_mili==0x0)
      y++;
      mseg=y;

}


retardo(t)
int t;
{
    t=t*mseg;
    while (t>0)
      t--;
}

