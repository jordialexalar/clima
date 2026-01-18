


      /*MODULO FSTR.C           */


       /*Contiene funciones relacionadas con la visualizacion por el display*/

#define RD_RELOJ  0x40
#define WR_RELOJ  0x80


#include <io51.h>
#include <math.h>

#include <fdefines.h>
#include <fexterns.h>

int mira_tec();
int espera_tecla(int);
int len(char *p);


 unsigned long int power(x,n)
 int x,n;
 {int ij;
  unsigned long int p;
  p=1;
  for(ij=1;ij<=n;++ij)
    p=p*x;
   return (p);
 }



 double flotpower(x,n)
 double x;
 int n;
 {int ij;
  double p;
  p=1.0;
  for(ij=1;ij<=n;++ij)
    p=p*x;
   return (p);
 }





  restdiv(a,b)
  int a,b;
  {
   int c;
   int resto;

   c=a/b;
   resto=(a)-(b*c);
   return(resto);
  }














aviso(lin,pos,cha)
     int lin,pos;
     unsigned char cha[];
    {int n;
     borrar();
     say(lin,pos,cha);
     pita(2);
     n=keyboard(0);
     borrar();
     return(n);
     }


borrar()
{
   disp_say=1;
   teclado=off;
  w_cmd(0x01);
  teclado=on;
   disp_say=0;
 
 }




 borrarl(lin,pos,n)
     int lin,pos;
     int n;


       { unsigned char posi=0xc0;
         int i=0;
	 disp_say=1;
         switch(lin)
	 {
         case 1:
	    posi=0x80;
            break;
         case 2:
	    posi=0xc0;
            break;

         case 3:
	    posi=0x94;
	    break;

	 case 4:
	    posi=0xd4;
            break;

         default:
	    posi=0x80;
	    break;
        }
	i=posi;
	i=i+pos;
        posi=(unsigned char) i;
	i=0;
	teclado=off;
        for (i=0;i<n;i++)
	 {
         w_cmd(posi+i);
         w_data(' ');
	 }
	 disp_say=0;
	 teclado=on;
      }




  bcd_a_str(ar,flot)
  char ar[];
  int flot;
  {
   int n;
    ar[2]=0x0;
    n=flot & 0x0f;
    ar[1]=n+0x30;
    flot=flot>>4;
    n=flot & 0x0f;
    ar[0]=n+0x30;
  }


  str_a_bcd(ar)
  char ar[];
  {
    int n;
    n=ar[0]-48;
    if (ar[1]!=0x0)
     {
      n=n*16;
      n=n+ar[1]-48;
     }
    return(n);
  }



  int_a_bcd(flot)
  int flot;
  {
   int n;
     n=flot/10;
     n=flot+n*6;

    return(n);
   }


  intar(ar,flot)
  char ar[];
  int flot;
  {
  unsigned long int partent,of,h,p;
  int j,i;

  int n;
  of=0;
  if (flot==0) /*para el caso de que sea cero */
  {ar[0]='0';
   ar[1]='\0';
   n=0;
   return(n);
  }

  if (flot<0)
   {
    flot=flot*(-1);
    of=1;
    ar[0]='-';
    }
  partent=flot;
  h=10;
  j=1;
  while (partent>=h)
  {
   h=h*10;
   j=j+1;
  }
   for(i=1;i<=j;i++)

   {
   p=partent/power(10,(j-i));
   ar[i-1+of]=p+48;
   partent=partent-p*power(10,(j-i));
   }
   n=j;

   ar[n+of]='\0';
   return(n);

   }



  arint(num)
  unsigned char num[];
  { int i,r;
    int numer=0;
    int numflot=0;
    r=0;
    i=0;

    numer=0;

    for(i=0;num[i]!='\0'&& i<7;i++)
    {
    if (num[i]=='.')
     {  break;
     }
      numer=numer+1;
    }
      r=numer;
      i=0;

     for(i=0;num[i]!='\0'&&i<7;i++)
      {          r=r-1;
		  h=(unsigned char) num[i]-48;

                 numflot= numflot+ h*power(10,r);
       }
	return(numflot);
   }









  double arflot(num1)
  unsigned char num1[];
  { int i,r,j;
    int numer=0;
    unsigned char num[20];
    double numflot=0.00;
    int offset=0;
    int salir;
    salir=0;
    r=0;
    i=0;
    j=0;

    numer=0;
     if (num[0]=='-')
       {
	 offset=1;
       }
	 j=offset;
	 i=0;
	 salir=0;
         while (salir==0)
	   {
	     num[i]=num1[j];
	     if (num1[j]=='\0')
	       {
		salir=1;
	       }
             i++;
	     j++;
	   }



    for(i=0;num[i]!='\0';i++)
    {
    if (num[i]=='.')
     {  break;
     }
      numer=numer+1;
      }
      r=numer;
      i=0;

     for(i=0;num[i]!='\0';i++)
      {
       if (num[i] != '.')
       {double h=0.00;
        r=r-1;
	h=(unsigned char) num[i]-48;

        if (r<0){
	         numflot= numflot+ h/ power(10,(r*(-1)));
                 }
	else     {
		 numflot= numflot+ h*power(10,r);
                 }
	}
	}
	if (offset==1)
	  numflot=numflot * -1.00;

	return(numflot);
	}




  numpaciente()

 {    borrar();
      say(1,0,textos[34+idioma_textos]);
      get(1,0+strlen(textos[34+idioma_textos]),pac,3,1,1,1);
  }


 ajusta(num,l)
 unsigned char num[];
 int l;

 {
 int i;
 int ajustado=0;
   for(i=0;i<l;i++)
    {
      if (num[i]=='\0')
          ajustado=1;

    }
    if (ajustado==0)
      num[l]='\0';
 }


  pon_fecha()
 {    int j;
      char aa[3];
      borrar();
      lee_fecha();
      say(1,5,textos[61+idioma_textos]);

      say(2,1,textos[58+idioma_textos]);
      say(3,1,textos[59+idioma_textos]);
      say(4,1,textos[60+idioma_textos]);
      say(2,10,textos[71+idioma_textos]);
      say(3,10,textos[72+idioma_textos]);
      say(4,10,textos[73+idioma_textos]);

      say(2,1+1+strlen(textos[58+idioma_textos]),dd);
      say(3,1+1+strlen(textos[59+idioma_textos]),mm);
      say(4,1+1+strlen(textos[60+idioma_textos]),yy);
      say(2,10+1+strlen(textos[71+idioma_textos]),hor);
      say(3,10+1+strlen(textos[72+idioma_textos]),min);
      say(4,10+1+strlen(textos[73+idioma_textos]),seg);


      get(2,1+strlen(textos[58+idioma_textos]),dd,2,1,1,1);
      get(3,1+strlen(textos[59+idioma_textos]),mm,2,1,1,1);
      get(4,1+strlen(textos[60+idioma_textos]),yy,4,1,1,1);
      get(2,10+strlen(textos[71+idioma_textos]),hor,2,1,1,1);
      get(3,10+strlen(textos[72+idioma_textos]),min,2,1,1,1);
      get(4,10+strlen(textos[73+idioma_textos]),seg,2,1,1,1);

      CONTROL=WR_RELOJ;
      aa[2]=0x0;
      aa[0]=yy[2];
      aa[1]=yy[3];
      YEAR=str_a_bcd(aa);
      MONTH=str_a_bcd(mm);
      DATE=str_a_bcd(dd);
      HOURS=str_a_bcd(hor);
      MINUTES=str_a_bcd(min);
      SECONDS=str_a_bcd(seg);
      CONTROL=0x00;
  }


lee_fecha()
{ int j;
  char aa[3];
      CONTROL=RD_RELOJ;
      j=YEAR;
      bcd_a_str(aa,j);
      j=arint(aa);
      if (j<90)
       {
	 yy[0]='2';
	 yy[1]='0';
	 yy[2]=aa[0];
	 yy[3]=aa[1];
	 yy[4]=0x0;

       }
       else
       {
	 yy[0]='1';
	 yy[1]='9';
	 yy[2]=aa[0];
	 yy[3]=aa[1];
	 yy[4]=0x0;
       }

      j=MONTH;
      bcd_a_str(mm,j);
      j=DATE;
      bcd_a_str(dd,j);
      j=HOURS;
      bcd_a_str(hor,j);
      j=MINUTES;
      bcd_a_str(min,j);
      j=SECONDS;
      bcd_a_str(seg,j);
      CONTROL=0x00;
}


/*  flotar1(ar,flot,nd)
  char ar[];
  double flot;
  int nd;
  {
  unsigned long int partent,of,h,p;
  int j,i;

  double partdec;
  int n;
  of=0;


  if (flot<0)
   {
    flot=flot*(-1.0000);
    of=1;
    ar[0]='-';
    }
  partent=flot;
  partdec=flot-partent;
  h=10;
  j=1;
  while (partent>=h)
  {
   h=h*10;
   j=j+1;
  }
   for(i=1;i<=j;i++)

   {
   p=partent/power(10,(j-i));
   ar[i-1+of]=p+48;
   partent=partent-p*power(10,(j-i));
   }
   n=j;

   if (nd>0)

  {
   ar[n+of]='.';
   n=n+1;

   for(i=0;i<nd;i++)
   {
   partent=partdec*10;
   partdec=partdec*10.0 - partent;
   ar[i+n+of]=(48+partent);
    }
        n=n+nd;
    }

	ar[n+of]='\0';
   return(n);

   }
  */


  flotar(ar,flot,nd)
  char ar[];
  double flot;
  int nd;
  { int neg=0;


  unsigned long int partent,of,h,p;
  int j,i,pospunt,t,u;

  double partdec;
  int n;
  of=0;

  if (flot<0)
    {
     flot=flot * -1.0;
     neg=1;
     ar[0]='-';
     }

  flot=flot*power(10,nd);

  partent=flot;
  partdec=flot-partent;

  if (partdec > 0.5)
     partent = partent + 1;




  h=10;
  j=1;
  while (partent>=h)
  {
   h=h*10;
   j=j+1;
  }

  pospunt=j-nd;

  if (nd==0)
   pospunt=1000;

  of=0;
  if (pospunt<0)
   { ar[0+neg]='0';
     ar[1+neg]='.';
     t=pospunt;
     u=2;
     while (t<0)
      {ar[u+neg]='0';
       t++;
       u++;
       }
       of=u;
    }


   for(i=1;i<=j;i++)

   {
   if (pospunt==i-1)
    {
     if (i>1)
     {
      ar[i-1+neg]='.';
      of=1;
     }
     else
     {
      ar[0+neg]='0';
      ar[1+neg]='.';
      of=2;

     }
    }
   p=partent/power(10,(j-i));
   ar[i-1+of+neg]=p+48;
   partent=partent-p*power(10,(j-i));
   }
/*    n=j+neg;*/  /* he tocado esto por las letras que aparecen */
    n=j;
    ar[n+of+neg]='\0';

  }



len(p)
char p[];
{
int i;
i=0;
while (p[i]!='\0')
{
 i++;
}
return(i);
}