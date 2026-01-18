
      /*MODULO FPRINT.C                    */

      /*Contiene funciones relacionadas con la impresion*/



#include <fdefines.h>
#include <io51.h>
#include <math.h>
#include <fexterns.h>
#include <stdio.h>
#include <ctype.h>

extern unsigned char letras[];




/* unsigned char letras[3];*/

int carsporlin;
unsigned char pasoimp=0x3;

/*unsigned char impde[]={0x06,0x0c,0x09,0x03};
 unsigned char impiz[]={0x06,0x03,0x09,0x0c};*/


unsigned char impiz[]={0x0,0x0,0x0,0x6,0x0,0x0,0xc,0x0,0x0,0x3,0x0,0x0,0x9};
unsigned char impde[]={0x0,0x0,0x0,0x9,0x0,0x0,0x3,0x0,0x0,0xc,0x0,0x0,0x6};







 lf(n)
 int n;
     /*line feed*/
{ int g;
  int i;
  for (g=0;g<n;g++)
 {
   write_XDATA(0xa000, 0x30);

   for (i=0;i<velocimp;i++)
   i=i;
   write_XDATA(0xa000, 0x90);

   for (i=0;i<velocimp;i++)
     i=i;

   write_XDATA(0xa000, 0xc0);

   for (i=0;i<velocimp;i++)
   i=i;

   write_XDATA(0xa000, 0x60);
   for (i=0;i<velocimp;i++)
   i=i;


 }
 }






 imprime (puntos)
  unsigned char puntos;
  {int i;
  if(puntos!= 0x00)
  {
   write_XDATA(0xa001,puntos);

  for (i=0;i<tempsimp;i++)
     i=i;

   write_XDATA(0xa001,0x00);
  }
 }







imp_letra(let,der_izq) /*escribe un caracter*/
char let;
int der_izq;
{  int i;
  long int posletra=0;
  posletra=let;
  posletra=posletra*5;

   if(der_izq==derecha)
   {
   for (i=posletra;i<posletra+5;i++)
  {
   avanceimp(1,0);
   imprime(letras[i]);
   }
   avanceimp(2,0);
  }

   else
     {
   avanceimp(2,1);

   for (i=posletra+4;i>=posletra;i--)
  {
   imprime(letras[i]);
   avanceimp(1,1);
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
   write_XDATA(0xa000,pasoimp);

   for (j=0;j<velocimp;j++)
     i=i;

 }
 }
 else
 {
  for (i=0;i<n;i++)
 { pasoimp=impiz[pasoimp];
   write_XDATA(0xa000,pasoimp);
   for (j=0;j<velocimp;j++)
    j=j;
 }

 }
 }







/*retcr ()
    {int i;
    int z;
    z=read_XDATA(0xa002) & 0x1;
 while (z==0)
    {avanceimp(1,1);
     z=read_XDATA(0xa002) & 0x1;
    }
  avanceimp(25,0);
  carsporlin=0;
     }


  */


 retcr ()
    {int i;
    int z;
    z=read_XDATA(0xa002) & 0x1;
 while (z==1)
    {avanceimp(1,1);
     z=read_XDATA(0xa002) & 0x1;
    }
  avanceimp(25,0);
  carsporlin=0;
     }








 printer(onoff)
 int onoff;
 {if (onoff==0)
   {
   write_XDATA(0xa000,0x00);
   write_XDATA(0xa001,0x00);
   estado_printer=0;
   }
  else
   {
   estado_printer=1;
   write_XDATA(0xa000,pasoimp);
   write_XDATA(0xa001,0x00);
   }
   }







  imprimelinea (linea,deriz)
  char linea[];
  int deriz;
  {
    int i;
    if (deriz == 0)
   {
       for (i=0;i<20;i++)
       {imp_letra(linea[i],deriz);
       }
       lf(10);
    }
   else
    {
       for (i=19;i>=0;i--)
       {imp_letra(linea[i],deriz);
       }
       lf(10);

    }
   }





 poneninforme(linea,col,line)
 int linea;
 int col;
 char line[];
 { int i,j;
  i=col;
  j=0;
       while (i<20 && line[j] !='\0')
       {
       informe[linea][i]=line[j];
       j++;
       i++;
       }
   strcpy(line,"                    ");

  }






 impinforme(numlineas)
  int numlineas;
 {int i;
  int deiz=1;
  printer(on);
  retcr();
  lf(10);
  for (i=0;i<=numlineas;i++)
  {
   if (deiz == 1)
    deiz = 0;
   else
    deiz = 1;

    if (i>0)
       cambiodesentido(deiz);

    imprimelinea(informe[i],deiz);
    strcpy(informe[i],"                   ");
   }
   lf(10);
   printer(off);
   }




imptest()
 {char mensaje[]="012345678901234567890";
  int i;
  int j;

 for (j=0;j<10;j++)
 {
  poneninforme(0,mensaje);

  }
 impinforme();

  }






 cambiodesentido(derizq)
 int derizq;
{   avanceimp(2,derizq);
}





 imprime_tecnica(tecnica)
  int tecnica;
  { int i;
    double tecnica1;
    int que;
    int h;
    int t;
    int j;
    int err=0;
    int haz=0;
    int ord=0;
    char text[25];



    lineasinforme = 0;
    /*pongo linea de guiones*/

    strcpy(text,"--------------------");

    poneninforme(0,0,text);
    strcpy(text,"--------------------");
    poneninforme(3,0,text);
    lineasinforme=4;
    strcpy(text,"TEST:");
    poneninforme(1,0,text);
    tecnica1=tecnica;

    flotar(text,tecnica1,0);
    poneninforme(1,6,text);


    h=arflot(ficher[tecnica].tipo);

    strcpy(text,tipos[h]);
    poneninforme(2,0,text);

    j=arflot(ficher[tecnica].code);

    strcpy(text,codigos[j]);
    poneninforme(2,12,text);


    lineasinforme = 5;

       for (i=0;parametros[i+(h*20)]!=FIN;i++)
	{


	 ord=parametros[i+(h*20)];


         inf=ord;

               strcpy(text,txt_prog[ord]);
               poneninforme(lineasinforme,0,text);
	       haz=1;



         switch (ord) {

	    case WL1:
               que=arflot(ficher[tecnica].wl1);

               strcpy(text,wl[que]);

               break;


	    case WL2:
               que=arflot(ficher[tecnica].wl2);
               if (que != 0)
                { strcpy(text,wl[que]);
                  haz=0;
		 }
               break;



	    case UNITS:
               que=arflot(ficher[tecnica].units);

               strcpy(text,units[que]);

               break;


	    case TEMP:
               strcpy(text,ficher[tecnica].temp);
               break;

	    case STD:
               strcpy(text,ficher[tecnica].std);
               break;

	    case FACTOR:
               strcpy(text,ficher[tecnica].factor);
               break;

	    case LIN_LIM:
               strcpy(text,ficher[tecnica].limlin);
               break;

	    case NORM_ALTO:
               strcpy(text,ficher[tecnica].normalt);
               break;

	    case NORM_BAJO:
               strcpy(text,ficher[tecnica].normbaj);
               break;

	    case SAMP_VOL:
               strcpy(text,ficher[tecnica].sampvol);
               break;

	    case REAGENT_VOL:
               strcpy(text,ficher[tecnica].reacvol);
               break;

	    case SIPPING_VOL:
               strcpy(text,ficher[tecnica].sipvol);
               break;


	    case READING_DLY:
               strcpy(text,ficher[tecnica].readdly);
               break;

	    case REACTION_TIME:
               strcpy(text,ficher[tecnica].reactime);
               break;

	    case ABSORB_LIM:
               strcpy(text,ficher[tecnica].absorblim);
               poneninforme(lineasinforme,len(txt_prog[ord]),text);
               strcpy(text,ficher[tecnica].absorblimm);
               poneninforme(lineasinforme,len(txt_prog[ord])+labsorblim,text);
               lineasinforme = lineasinforme + 1;
	       haz=0;
               break;

	    case N_OF_READINGS:
               strcpy(text,ficher[tecnica].numlects);
               break;

	    case INTERVAL_TIME:
               strcpy(text,ficher[tecnica].intertime);
               break;

	    case DELAY:
               strcpy(text,ficher[tecnica].delay);
               break;

	    case DT_ABSORB_MAX:
               strcpy(text,ficher[tecnica].dtabsmax);
               break;

	    case DECIMALES:
               strcpy(text,ficher[tecnica].decs);
               break;


         }


         if (haz==1)
	    {
               poneninforme(lineasinforme,len(txt_prog[ord]),text);
               lineasinforme = lineasinforme + 1;
	       haz=0;
	     }


   tecnica=tecnica;
   }







    impinforme(lineasinforme);

 }




 test_graf()
 {
  int i;
  int j;
  int px,py;
  int jy,jres;

  double increx=0.0;
  double increy=0.0;
  double increpuntx=0.0;
  double increpunty=0.0;
  double coefa;
  double coefb;
  double valorx;
  double valory;

  increx=100.0/(varx[numpuntos-1]-varx[0]);
  increy=100.0/(vary[numpuntos-1]-vary[0]);

  increpuntx=(varx[numpuntos-1]-varx[0])/100.0;
  increpunty=(vary[numpuntos-1]-vary[0])/100.0;

  for (i=0;i<numpuntos;i++)
  {
   j=0;
   valorx=(varx[i]-varx[0])*increx;
   valory=(vary[i]-vary[0])*increy;
   if (i>0)
    {
     coefa=(vary[i]-vary[i-1])/(varx[i]-varx[i-1]);
     coefb=(coefa*varx[i])+vary[i];
    }

   do
   {
   px=valorx;
   py=valory;
   jy=py/8;
   jres=restdiv(py,8);
   mapimp[jy][px-1]=power(2,7-jres);
   j++;
   if (i>0)
   {
   valorx=varx[i-1]+(increpuntx*j);
   valory=coefa*valorx+coefb;
   }
   }
   while (i>0 && valorx <= varx[i]);



  }
  imp_grafica();
  }






 imp_grafica()
 {int i;
  int j;
  int deiz=1;
  printer(on);
  retcr();
  lf(10);
  for (i=0;i<=13;i++)
  {
   if (deiz == 1)
    deiz = 0;
   else
    deiz = 1;

    if (i>0)
       cambiodesentido(deiz);

    if (deiz==derecha)
      {
       if (i==13)
       {
       for(j=0;j<120;j++)
       {
       avanceimp(1,0);
       imprime(0x03);
       }
       }
       else
       {
       avanceimp(1,0);
       imprime(0xff);
       avanceimp(1,0);
       imprime(0xff);
       imprimelingraf(mapimp[13-i],deiz);
       }
       }
    else
      {
       if (i==13)
       {
       for(j=0;j<120;j++)
       {
       imprime(0x03);
       avanceimp(1,1);
       }
       }
       else
       {
       imprimelingraf(mapimp[13-i],deiz);
       imprime(0xff);
       avanceimp(1,1);
       imprime(0xff);
       avanceimp(1,1);
       }
      }


    lf(8);
   }
   lf(10);
   printer(off);
   }




  imprimelingraf (letras,der_izq)
  char letras[];
  int der_izq;
  {  int i;

   if(der_izq==derecha)
   {
   for (i=0;i<120;i++)
  {
   avanceimp(1,0);
   imprime(letras[i]);
   }
  }

   else
     {

   for (i=119;i>=0;i--)
  {
   imprime(letras[i]);
   avanceimp(1,1);
   }

     }
   }






