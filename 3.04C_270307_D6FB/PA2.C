 i=mseg;
 while (i>0)
  i--;
DO);
      	while (time_mili==0x0)
	  y++;
      mseg=y;

(on);
	           temp_alcanz=1;
	      }
	     else
	      {
		if (temp_puesta==on)
		 {
		   temp_puesta=off;
		   say_temp(off);
		 }
		else
		 {
		   temp_puesta=on;
		   say_temp(on);
		 }
	      }

}




say_temp(onoff)
     int onoff;
       {
	 int pos=18;
	 unsigned char posi=0x80;
 	 posi=posi+pos;
	 codisp(posi);
	 if (onoff==on)
	   displcd('3');
	 else
	   displcd(' ');
	 posi++;
	 codisp(posi);
	 if (onoff==on)
  	   displcd('7');
	 else
  	   displcd(' ');
      }


displ_temp(onoff)
int onoff;
{
 if (onoff==1)
  {
    visu_temp=on;
    temp_alcanz=0;
  }
 else
  {
    visu_temp=off;
    say_temp(off);
  }
}
ades de absorbancia*/
double lee_abs(n,filtro1,filtro2)
  int n;
  char filtro1[];
  char filtro2[];
  {   long int tiempo=0;
       double abs=0;
   if (n==1)
    aviso(1,1,"PONGA MUESTRA Y PULSE TECLA");
        tiempo=media_tiempo_desc(filtro1,filtro2);
	if (medabs==0)
          tiempo=tiempo/fact;


	tiempo_abs=tiempo;

        abs=tiempo/1000.0;

      return(abs);
   }











  cod_posibles()
  {
    char text[25];
    double j;
    int h;
    int i;


    lineasinforme = 0;
    /*pongo linea de guiones*/


    poneninforme(0,2,textos[49+idioma_textos]);
    strcpy(text,textos[6+idioma_textos]);
    poneninforme(1,0,text);
    lineasinforme=2;


    lineasinforme++;

       for (i=0;i<num_codigos;i++)
	{
           j=i;

           intar(text,i);

           poneninforme(lineasinforme,5,text);
           strcpy(text,codigos[i]);

           poneninforme(lineasinforme,9,text);
           lineasinforme++;


        }


    impinforme(lineasinforme,12,12);

 }




 imprime_tecnica(tecnica)
  int tecnica;
  {

    int i;
    double tecnica1;
    int que;
    int h;
    int t;
    int j;
    int ji;
    int err=0;
    int haz=0;
    int ord=0;
    int referencia;
    int numero;
    char text[25];


    limpia_informe();
    lineasinforme = 0;

    strcpy(text,textos[6+idioma_textos]);

    poneninforme(0,0,text);
    strcpy(text,textos[6+idioma_textos]);
    poneninforme(3,0,text);
    lineasinforme=4;
    strcpy(text,textos[18+idioma_textos]);
    poneninforme(1,0,text);
    tecnica1=tecnica;

    flotar(text,tecnica1,0);
    poneninforme(1,0+strlen(textos[18+idioma_textos]),text);

    apunta(tecnica,TIPO);
    h=arflot(pficher);

    strcpy(text,tipos[h+idioma_tipos]);
    poneninforme(1,10,text);


    apunta(tecnica,IDEN);
    j=arflot(pficher);

    strcpy(text,codigos[j+pos_ini_cod]);
    poneninforme(2,0,text);


    lineasinforme = 5;

       for (i=0;parametros[i+(h*30)]!=FIN;i++)
	{


	 ord=parametros[i+(h*30)];


               if (ord!=NADA)
	       {
               strcpy(text,txt_prog[ord]);
               poneninforme(lineasinforme,0,text);
	       haz=1;
               }
               apunta(tecnica,ord);

         switch (ord)
	    {
	    case UNIDADES:
               que=arflot(pficher);
               strcpy(text,units[que]);
               break;


	    case INR:
               que=arflot(pficher);
               if (que==1)
                 strcpy(text,"S");
               else
                 strcpy(text,"N");
               break;


	    case RATIO:
               que=arflot(pficher);
               if (que==1)
                 strcpy(text,"S");
               else
                 strcpy(text,"N");
               break;






          default:
              strcpy(text,pficher);
	      break;

         }


         if (haz==1)
	    {
               poneninforme(lineasinforme,strlen(txt_prog[ord]),text);
               lineasinforme = lineasinforme + 1;
	       haz=0;
	     }


   tecnica=tecnica;
   }







    impinforme(lineasinforme,12,12);

 }

