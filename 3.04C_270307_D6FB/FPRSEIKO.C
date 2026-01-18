

      /*MODULO FPRINT.C                    */

      /*Contiene funciones relacionadas con la impresion*/



#include <fdefines.h>
	       #define VELOCIDAD_LF       3
	       #define VELOCIDAD_CABEZAL  3
	       #define TIEMPO_IMPRESION   3

#include <io51.h>
#include <math.h>
#include <fexterns.h>
#include <stdio.h>
#include <ctype.h>

extern unsigned char letras[];

char informe[70][20];


/* unsigned char letras[3];*/

int carsporlin;
unsigned char pasoimp=0x3;

/*unsigned char impde[]={0x06,0x0c,0x09,0x03};
 unsigned char impiz[]={0x06,0x03,0x09,0x0c};*/


unsigned char impiz[]={0x0,0x0,0x0,0x6,0x0,0x0,0xc,0x0,0x0,0x3,0x0,0x0,0x9};
unsigned char impde[]={0x0,0x0,0x0,0x9,0x0,0x0,0x3,0x0,0x0,0xc,0x0,0x0,0x6};


 char lfs[]={0x30,0x90,0xc0,0x60};





 lf(n)
 int n;
     /*line feed*/
{ int g;
  int i;
  i=0;
  n=n*4;
  for (g=0;g<n;g++)
 {
   PA000=lfs[i];
   espera_mili(VELOCIDAD_LF);
   i++;
   if (i>3)
    i=0;
 }
 }






 imprime (puntos)
  unsigned char *puntos;
  {int i;
  if(puntos!= 0x00)
  {
   PA001=*puntos;

   espera_mili(TIEMPO_IMPRESION);

   PA001=0x00;
  }
 }







imp_letra(let,der_izq) /*escribe un caracter*/
char let;
int der_izq;
{  int i;
   char  *p;
   long int posletra=0;

   if (let=='x')
    {  posletra=0;
       p=letrasx;
    }
    else
    { p=letras;
      if (let==0x00)
	posletra=0;
      else
        posletra=let-32;
      posletra=posletra*5;
     }

   if(der_izq==derecha)
   {
   p=p+posletra;
   for (i=posletra;i<posletra+5;i++)
  {
   avanceimp(1,0);
   imprime(p);
   p++;
   }
   avanceimp(2,0);
  }

   else
     {
   avanceimp(2,1);
   p=p+posletra+4;
   for (i=posletra+4;i>=posletra;i--)
  {
   imprime(p);
   avanceimp(1,1);
   p--;
   }

    }
   }









avanceimp(n,derizq)
int n;
int derizq;

{int i;
 int j;

 if (derizq==derecha)
 {
 for (i=0;i<n;i++)
 { pasoimp=impde[pasoimp];
   PA000=pasoimp;
   espera_mili(VELOCIDAD_CABEZAL);

 }
 }
 else
 {
  for (i=0;i<n;i++)
 { pasoimp=impiz[pasoimp];
   PA000=pasoimp;
   espera_mili(VELOCIDAD_CABEZAL);
 }

 }
 }







retcr ()
    {int i;
    int z;
    z=PA002;
    z=z & 0x1;
 while (z==0)
    {avanceimp(1,1);
     z=PA002;
     z=z & 0x1;
    }
  avanceimp(25,0);
  carsporlin=0;
     }










 printer(onoff)
 int onoff;
 {if (onoff==0)
   {
   PA000=0x00;
   PA001=0x00;
   estado_printer=0;
   }
  else
   {
   estado_printer=1;
   PA000=pasoimp;
   PA001=0x00;
   }
   }







  imprimelinea (linea,deriz)
  char *linea;
  int deriz;
  {
    int i;
    if (deriz == 0)
   {
       for (i=0;i<20;i++)
       {
   	   imp_letra(*linea,deriz);
	   linea++;
       }
       lf(12);
    }
   else
    {  linea=linea+19;
       for (i=19;i>=0;i--)
       {
	  imp_letra(*linea,deriz);
	  linea--;

       }
       lf(12);

    }
   }





 poneninforme(linea,col,line)
 int linea;
 int col;
 char line[];
 { int i,j;
   char *p;
   p=&informe[0][0];
  i=col;
    j=0;
    p=p+(linea*20)+col;

       while (i<20 && line[j]!='\0')
       {
          *p=line[j];
           p++;
           j++;
           i++;
       }

  }






 impinforme(numlineas,salto_antes,salto_despues)
  int numlineas;
  int salto_antes;
  int salto_despues;

 {int i;
  int t;
  int deiz=1;
  int nu;
  int j;
  char *p;
  nu=0;

  if (printtec == 0)
      return;

  p=&informe[0][0];

  printer(on);
  retcr();
  lf(salto_antes);

  for (i=0;i<=numlineas;i++)
  {
       p=&informe[0][0];
       nu=0;
       p=p+(i*20);
       for (j=0;j<20;j++)
       {if (*p!=0x00)

	  {nu=1;
	   j=22;
	  }
	  p++;
       }
       p=&informe[0][0];
       p=p+(i*20);

   if (nu==1)
   {
   if (deiz == 1)
    deiz = 0;
   else
    deiz = 1;

    if (i>0)
       cambiodesentido(deiz);

    imprimelinea(p,deiz);
       p=&informe[0][0];
       p=p+(i*20);

       for (j=0;j<20;j++)
       {
       *p=0x00;
       p++;
       }

      }
    else
      lf(12);


       t=mira_tec();

   if (t==stop)
     i=numlineas+2;

   }

   lf(salto_despues);
   printer(off);
   return(t);
   }


 cambiodesentido(derizq)
 int derizq;
{   avanceimp(2,derizq);
}









imp_puntos(quina)
int quina;
{ int referencia;
  int numero;
  int ji;
  char text[25];

              apunta(quina,VARIOS_STD);
              referencia=arint(pficher);
	      apuntastd(referencia,0,0,0);
	      numero=arint(pficherstd);

              for (ji=0;ji<numero;ji++)
	      {
	       intar(text,ji+1);

               poneninforme(lineasinforme,0,text);
               poneninforme(lineasinforme,2,textos[43+idioma_textos]);
	       apuntastd(referencia,1,PX,ji);
	       strcpy(text,pficherstd);
               poneninforme(lineasinforme,2+strlen(textos[43+idioma_textos]),text);

               lineasinforme++;

	       intar(text,ji+1);
               poneninforme(lineasinforme,0,text);
               poneninforme(lineasinforme,2,textos[44+idioma_textos]);
	       apuntastd(referencia,1,PY,ji);
	       strcpy(text,pficherstd);
               poneninforme(lineasinforme,2+strlen(textos[44+idioma_textos]),text);

               lineasinforme++;

	      }
}



 limpia_informe()
 {int u;
  char *p;
  p=informe[0];
  for (u=0;u<1400;u++)
  {
  *p=0x00;
  p++;
  }
 }



  imprimir_tecnicas()
  {
    char text[25];
    double j;
    int h;
    int i;
    char tec1[3];
    char tec2[3];
    int pul1=0;
    int pul2=0;
    int err;
    int t;

       borrar();

      say(1,0,textos[45+idioma_textos]);
      err=get(1,strlen(textos[45+idioma_textos]),tec1,3,1,1,0);
       if (err==novalid)
	 return;

        pul1=arflot(tec1);
       if (pul1<0 || pul1>total_tecnicas)
	 return;

      say(2,0,textos[46+idioma_textos]);
      err=get(2,strlen(textos[46+idioma_textos]),tec2,3,1,1,0);
       if (err==novalid)
	 return;

        pul2=arflot(tec2);

       if (pul2<0 || pul2>total_tecnicas)
	 return;

       if (pul1>pul2)
	 return;



       for (i=pul1;i<=pul2;i++)
	{  apunta(i,POS_GRABADA);
           if (*pficher=='*')
	   {
              imprime_tecnica(i);

           }
            t=mira_tec();
            if (t==stop)
               i=pul2+2;


        }

 }




actimp()
{
  borrar();
  if (printtec == 1)
   {
    printtec=0;
    aviso(1,1,textos[47+idioma_textos]);
   }
  else
   {
    printtec=1;
    aviso(1,1,textos[48+idioma_textos]);
   }
}


  oper_dispo()
  {
    char text[25];
    double j;
    int h;
    int i;
    int t;
    int y;
    int hy;
      hy=0;
    lineasinforme = 0;
    /*pongo linea de guiones*/


    poneninforme(0,0,text_func[0+idioma_text_func]);
    poneninforme(1,0,textos[6+idioma_textos]);
    lineasinforme=2;
    if (modelo==RAL122)
     y=11;
    else
     y=10;

    for (i=1;i<y;i++)
    {

    lineasinforme++;
    poneninforme(lineasinforme,0,text_func[i+idioma_text_func]);

    }
    lineasinforme++;
    hy=impinforme(lineasinforme,12,0);

      if (hy!=stop)
      {
       for (i=0;i<total_tecnicas;i++)
	{
	   lineasinforme=0;
	   apunta(i,POS_GRABADA);
           if (*pficher=='*')
	   {
           j=i;
	   intar(text,i);

           poneninforme(lineasinforme,0,text);
           strcpy(text,".");
           poneninforme(lineasinforme,2,text);
           apunta(i,IDEN);
           j=arflot(pficher);
           h=j;
           strcpy(text,codigos[h+pos_ini_cod]);

           poneninforme(lineasinforme,6,text);
	   hy=impinforme(lineasinforme,0,0);
         }

           if (hy==stop)
	   {
             i=total_tecnicas+2;
           }
        }
       }

 }








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
	   strcpy(text,codigos[i+pos_ini_cod]);

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
    poneninforme(2,0,text);

    apunta(tecnica,IDEN);
    j=arflot(pficher);

    strcpy(text,codigos[j+pos_ini_cod]);
    poneninforme(2,12,text);


    lineasinforme = 5;

       for (i=0;parametros[i+(h*20)]!=FIN;i++)
	{


	 ord=parametros[i+(h*20)];


               if (ord!=NADA && ord!=VARIOS_STD)
	       {
               strcpy(text,txt_prog[ord]);
               poneninforme(lineasinforme,0,text);
	       haz=1;
               }
               apunta(tecnica,ord);

         switch (ord) {

	    case WL1:
               que=arflot(pficher);
               strcpy(text,wl[que]);
               break;


	    case WL2:
               que=arflot(pficher);
               if (que != 0.0)
                { strcpy(text,wl[que]);
                  haz=1;
		 }
		else
		{
		 haz=0;
		}
               break;



	    case UNITS:
               que=arflot(pficher);

               strcpy(text,units[que]);

               break;


	    case TEMP:
               strcpy(text,pficher);
               break;


	    case STD:
               if (contrafact(tecnica))
	       { haz=0;
	       }
	       else
	       {
	       haz=1;
	       apunta(tecnica,STD);
               strcpy(text,pficher);
	       }
               break;


	    case ABSORB_LIM:
               strcpy(text,pficher);
               poneninforme(lineasinforme,strlen(txt_prog[ord]),text);
	       apunta(tecnica,ABSORBLIMM);
               if (*pficher=='1')
                 strcpy(text,"MAX");
               else
                 strcpy(text,"MIN");
               poneninforme(lineasinforme,strlen(txt_prog[ord])+longitud[ABSORB_LIM],text);
               lineasinforme = lineasinforme + 1;
	       haz=0;
               break;


	    case VARIOS_STD:
              imp_puntos(tecnica);
              haz=0;
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