/* PROGRAMA PARA LA NUEVA CARATULA DE LEUCOFORM CON LA TECLA
6 COMO FUNCION DE CONTAJE Y CAMBIADO EL ORDEN DE LAS TECLAS EL
 3-11-94 */


#include <io51.h>
#include <math.h>
#define true 0xff
#define false 0x00



/* VARIABLES RELACIONADAS CON LA IMPRESORA */


int carsporlin;
unsigned char pasoimp=0x3;
unsigned char impiz[]={0x0,0x0,0x0,0x6,0x0,0x0,0xc,0x0,0x0,0x3,0x0,0x0,0x9};
unsigned char impde[]={0x0,0x0,0x0,0x9,0x0,0x0,0x3,0x0,0x0,0xc,0x0,0x0,0x6};




     /*  punteros para los PORTS */

       #define PA000  (*(char *) 0x1A000)
       #define PA001  (*(char *) 0x1A001)
       #define PA002  (*(char *) 0x1A002)
       #define PA003  (*(char *) 0x1A003)

       #define PD000  (*(char *) 0x1D000)
       #define PD001  (*(char *) 0x1D001)
       #define PD002  (*(char *) 0x1D002)
       #define PD003  (*(char *) 0x1D003)

       #define PF000  (*(char *) 0x1F000)
       #define PF001  (*(char *) 0x1F001)
       #define PF002  (*(char *) 0x1F002)
       #define PF003  (*(char *) 0x1F003)





 int veces;

 unsigned char mens[]={0,0,0,0x0a,0x0d,0,0,'/',0,0,'/',0,0,0x0a,0x0d,

 'L','I','N','F',0,0,0,0x0a,0x0d,
 'M','O','N','O',0,0,0,0x0a,0x0d,
 'S','E','G','M',0,0,0,0x0a,0x0d,
 'C','A','Y','A',0,0,0,0x0a,0x0d,
 'E','O','S','I',0,0,0,0x0a,0x0d,
 'B','A','S','O',0,0,0,0x0a,0x0d,
 'E','R','I','T',0,0,0,0x0a,0x0d,
 'P','R','O',' ',0,0,0,0x0a,0x0d,
  0x01};
 unsigned char recip[50],*rec;
 unsigned char dat,*menp;


   unsigned char lado;
   unsigned char de[15],iz[15],paso;
   unsigned char pac[]={0,0,0}; /*numero de paciente formula*/
   unsigned char paci[]={0,0,0}; /*numero de paciente contador unico*/

 unsigned  char tco,t,h;
 unsigned  char fecha[]={0,0,0,0,0,0};
 int c[]={5,4,3,2,1,0,11,10,9,8,7,6};


   char tecla;
   char disp[10];
   char car_imp[]={0xff,0xc1,0x91,0x83,0xff,                 /*0*/
   0x0,0x82,0xff,0x80,0x0,/*1*/
   0xc3,0xa1,0x91,0x89,0x8f,0x81,0x81,0x89,0x89,0xff, /*2 3*/
   0x1F,0x10,0x10,0x10,0x0F8,0x8F,0x89,0x89,0x89,0x0F9,  /*4  5*/
   0xFF,0x91,0x91,0x91,0x0F1,0x1,0x1,0x1,0x1,0x0FF,  /*6  7*/
   0x0FF,0x91,0x91,0x91,0x0FF,0xF,0x9,0x9,0x9,0x0FF, /*8  9*/


   0xFF,0x2,0x8,0x2,0x0FF,0x81,0x81,0x0FF,0x81,0x81,      /*M I */
   0x0FF,0x89,0x89,0x81,0x81,0x0,0x0,0x0,0x0,0x0,        /*E */


   0x0FF,0x2,0x8,0x2,0x0FF,0xFF,0x81,0x81,0x81,0x0FF,/*M  O*/
   0x0FF,0x2,0x8,0x20,0x0FF,0x0FF,0x81,0x81,0x81,0x0FF,/*N  O*/



   0xFF,0x80,0x80,0x80,0x80,0x81,0x81,0x0FF,0x81,0x81,/*L I*/
   0xFF,0x2,0x08,0x20,0x0FF,0x0FF,0x11,0x11,0x1,0x1, /*N  F*/

   0x0FF,0x81,0x81,0x81,0x81,0x0FF,0x11,0x11,0x11,0x0FF,/*C  A*/
   0x1,0x2,0x0FC,0x2,0x1,0x0FF,0x11,0x11,0x11,0x0FF,    /*Y  A*/



   0x8F,0x89,0x89,0x89,0x0F9,0x0FF,0x89,0x89,0x81,0x81,/*S  E*/
   0x0FF,0x81,0x81,0x91,0x0F0,0xFF,0x2,0x8,0x2,0x0FF,  /*G  M*/


   0x0FF,0x89,0x89,0x81,0x81,0xFF,0x81,0x81,0x81,0x0FF,  /*E O*/
   0x8F,0x89,0x89,0x89,0x0F9,0x0,0x0,0x0,0x0,0x0,         /*S  */


   0xFF,0x91,0x91,0x9F,0x0F0,0x0FF,0x11,0x11,0x11,0x0FF,  /*B  A*/
   0x8F,0x89,0x89,0x89,0x0F9,0xFF,0x81,0x81,0x81,0x0FF,   /*S  O*/

   0xFF,0x11,0x11,0x11,0x01F,0x0FF,0x9,0x29,0x49,0x8F,   /*P  R*/
   0xFF,0x81,0x81,0x81,0x0FF,0x00,0x00,0x00,0x00,0x00,   /*O   */

                };


		/*
   0x0FF,0x2,0x8,0x20,0x0FF,0xFF,0x91,0x91,0x91,0x0FF,
   0xFF,0x89,0x89,0x81,0x81,0x0FF,0x9,0x29,0x49,0x8F,
   0x81,0x81,0x0FF,0x81,0x81,0x1,0x1,0x0FF,0x1,0x1,
   0x40,0x26,0x16,0x68,0x64,0xFF,0x8,0x8,0x8,0x0FF,
   0x255,0x89,0x89,0x81,0x81,255,0x2,0x8,0x2,0x0FF,
   0x0FF,0x11,0x11,0x11,0x0FF,0x0FF,0x9,0x9,0x9,0x0F,
   255,0x80,0x80,0x80,0x80,0x255,0x11,0x11,0x11,0x255,
   0x0FF,0x81,0x0A1,0x0C1,0x0FF,255,0x9,0x29,0x49,0x8F,
   0x0FF,0x89,0x89,0x81,0x81,0x1,0x1,0x0FF,0x1,0x1,
   0x81,0x81,0x0FF,0x81,0x81};
*/


   int cont[24],cong,conx,ncont;

   int valor,mayor;
   float total;
   int ki;
   char resto;


main()
{
int ghj;
valor=100;
 paso=0x0; /*PARTE DE INICIALIZACION */
  borrar();

 PF001=0x0a; /*inicializacion del 8279*/
 PF001=0x34;
 PF001=0x40;
 PF001=0xa0;
 PF001=0xe0;
 PF001=0x90;
  borrar();
    on();
     menp=&mens[0];






tecla=0x0;
t=0x0;
h=0x0;
tco=0x0;
 disp[0]=0xf6;
 disp[1]=0x30;
 disp[2]=0xe5;
 disp[3]=0xf1;
 disp[4]=0x33;
 disp[5]=0xd3;
 disp[6]=0xd7;
 disp[7]=0x70;
 disp[8]=0xf7;
 disp[9]=0x73;

cong=0;
conx=0;
      for (ghj=0;ghj<100;ghj++)  /*  bucle de retardo*/
	{
	ghj=ghj;
	}




 PD003=0x81; /*inicializacion del 8255*/
 paso=0x0;
 PD000=paso;/*inicializo impresora*/
 PD001=0;/*inicializo impresora*/



tco=0x84;
IE=tco;



for(;;)   /*BUCLE PRINCIPAL*/

{ int j;
  inhib_int();

  segur();

   if (tecla==0)

	{   /*  on();*/
	  habil_int();
         }

   else{  int i;
          tecla=0;
          h=t;
          habil_int();

 	  switch (h){

          case 0:
	   lf(15);

	   break;

	  case 6:

              borrar();
              conta ();
	      h=t;
               h=0x0;

            break;

          case 9:
	   pon_valor();
	   break;

	  case 4:
            cont_unic();
            borrar();
	    on();
	    break;

          case 11:


                impreso();
                lf(60);
                break;

	  case 7:
              pon_fecha();
            break;


	  case 8:
              camb_pac(pac);
            break;

           case 10:
	   borrar();
	   on();
	   break;

          default:
             break;
             }
                }


}
  }






conta ()
{
int i,j;
for (i=0;i<24;i++)
{
cont[i]=0;
}
cong=0;
conx=0;
	  resto=0;
            disp_fun();

while ( h!=10 && valor != cong && valor != 0 )

{ inhib_int();

   if (tecla==0)

	{
	  habil_int();
        }

   else{  int i;
          tecla=0;
          h=t;
	  if (h<7 || h==11)         /*es un contador*/
            { if (h==11 || h==6)
	       { if (h==11)
                    ncont=7*3;
		 if (h==6)
		    ncont=0;
	       }
           else
                {ncont=h*3+3;
		}

              if (cong==0 && conx==0)
		 {borrar ();
		 }
             cont[ncont+2]=cont[ncont+2]+1;
	      if (cont[ncont+2]==10)
		   {cont[ncont+2]=0;
                    cont[ncont+1]=cont[ncont+1]+1;
                   }
	      if (cont[ncont+1]==10)
		   {cont[ncont+1]=0;
                    cont[ncont]=cont[ncont]+1;
                   }
                   PF001=0x90+14-(2*(ncont/3));
                   PF000=disp[cont[ncont+2]];
                   PF000=disp[cont[ncont+1]];
             if (ncont<22)
		cong=cong+1;
	     else
	       conx=conx+1;

            }
          habil_int();
    }
   } /*fin del while*/


    if (h==10 && cong==0 && conx==0)
      return;

    mayor=0;
  for (i=0;i<22;i=i+3)

    { cont[i]=100*cont[i]+10*cont[i+1]+cont[i+2];

      total=(100*cont[i])/cong;
/*      (int) total;*/
      resto=total+resto;
       cont[i]=total;

      if (cont[i] >= cont[mayor])
	  mayor=i;

      }
     cont[mayor]=cont[mayor]+(100-resto);

  for (i=0;i<22;i=i+3)
    {
      ki=cont[i];
      cont[i]=cont[i]/100;
      cont[i+1]=(ki-100*cont[i])/10;
      cont[i+2]=(ki-(100*cont[i]+10*cont[i+1]));
     }

    PF001=0x90;  /*posicion cero*/

  for (i=0;i<22;i=i+3)
    {

    if (cont[i]==0)
      {
       PF000=disp[cont[21-i+2]];
       PF000=disp[cont[21-i+1]];
      }


     else


     { PF001=0x90;
      for(j=0;j<16;j++)
       PF000=0x01;

       PF001=0x97;
      for(j=0;j<3;j++)
       PF000=disp[cont[i+2-j]];

       break;
      }

    }

  inc_num(pac);
/*       env_res();*/
       pita(1000);
      impreso();
      lf(60);
                           }



borrar()                 /*borrado del display*/
 {int i;
 PF001=0xd0;
 for (i=0;i<30;i++)
 i=i;
 }

 on()
 {
      PF001=0x9c;

      vis(0x76);         /* write_XDATA(0xf000,0x71);*/
      vis(0xf6);

  }


 inhib_int()
 {
   EA=0;
 }

 habil_int()
 {
	  EA=1;
	  EX1=1;
 }




disp_fun()
 {
	  PF001=0x9c;
          vis(disp[h]);          /*write_XDATA(0xf000,disp[h]);*/
          vis(0x47);         /* write_XDATA(0xf000,0x71);*/

  }


displ (num,pos)                      /*visualizar en una posicion determinadsa*/
  unsigned char num,pos;
  {
   PF001=128+15-pos;
   PF000=num;
  }


  vis(num)                        /*visualizar sin posicion determinada*/
  unsigned char num;
  {
    PF000=num;
  }










camb_pac(pac)
unsigned char pac[];    /*cambiar valor paciente*/
 {int i;
  borrar();
  disp_fun();

  for (i=0;i<3;i++)                /*lo visualizo*/
   { displ(disp[pac[i]],11+i);     /*pac[0] centenas*/
   }
     i=0;
     while (h!=10 && i<3)
    {
     inhib_int();

     if (tecla==0)

	{
	  habil_int();
        }

   else{
          tecla=0;
          h=t;
          habil_int;

           if (h<=9)
	     { switch(i)
		{
		case 0:
		 pac[i]=h;
		 displ(disp[h],11);                   /*centenas*/
		 i++;
		 break;

		case 1:
		 pac[i]=h;
		 displ(disp[h],12);
		 i++;
		 break;

		case 2:
		 pac[i]=h;
		 displ(disp[h],13);
		 i++;
		 break;
                 }
	      }
	  }
	  }
	}


 cont_unic()
  {int i;
  borrar();
  disp_fun();
  for (i=0;i<3;i++)
  {cont[i]=0;
   displ(disp[cont[i]],11+i);
  }
     while (h != 10)
    {
     inhib_int();

     if (tecla==0)

	{
	  habil_int();
        }

   else{
          tecla=0;
          h=t;
          habil_int;

           if (h==4)
	     {
             cont[2]=cont[2]+1;
	      if (cont[2]==10)
		   {cont[2]=0;
                    cont[1]=cont[1]+1;
                   }
	      if (cont[1]==10)
		   {cont[1]=0;
                    cont[0]=cont[0]+1;
                   }
	      if (cont[0]==10)
		   {int p;
		   for (p=0;p<3;p++)
		   cont[p]=0;
                   }

                  for (i=0;i<3;i++)
                  displ(disp[cont[i]],11+i);

	      }
	  }
	  }
   inc_num(paci);

    borrar();


	  }





  pon_valor()
  {int i;
   unsigned char pac[2];
   pac[0]=valor/100;
   pac[1]=(valor-pac[0]*100)/10;
   pac[2]=(valor-pac[0]*100-pac[1]*10);
  borrar();
  disp_fun();


  for (i=0;i<3;i++)                /*lo visualizo*/
   { displ(disp[pac[i]],11+i);
				  /*pac[0] centenas*/
   }
     i=0;
     while (h!=10 && i<3)
    {
     inhib_int();

     if (tecla==0)

	{
	  habil_int();
        }

   else{
          tecla=0;
          h=t;
          habil_int;

           if (h<=9)
	     { switch(i)
		{

		case 0:
		 displ(disp[h],11);
		 pac[i]=h;	    /*centenas*/
		 i++;
		 break;

		case 1:
		 pac[i]=h;
		 displ(disp[h],12);
		 i++;
		 break;

		case 2:
		 pac[i]=h;
		 displ(disp[h],13);
		 i++;
		 break;

                 }
	      }
	  }
	  }
	  valor=pac[0]*100+pac[1]*10+pac[2];
	}



  pon_fecha()
   {int i;
  borrar();
  disp_fun();

  for (i=0;i<6;i++)                /*lo visualizo*/
   { displ(disp[fecha[i]],8+i);
				  /*pac[0] centenas*/
   }

     i=0;
     while (h!=10 && i<6)
    {
     inhib_int();

     if (tecla==0)

	{
	  habil_int();
        }

   else{
          tecla=0;
          h=t;
          habil_int;
		 if (h<=9)
		 {
		 displ(disp[h],8+i);
		 fecha[i]=h;
		 i++;
		 }
	  }
	  }
	}

  inc_num(pac)
  unsigned char pac[];
  {
                    pac[2]=pac[2]+1;
	      if (pac[2]==10)
		   {pac[2]=0;
                    pac[1]=pac[1]+1;
                   }
	      if (pac[1]==10)
		   {pac[1]=0;
                    pac[0]=pac[0]+1;
                   }
	      if (pac[0]==10)
		   {
		   pac[0]=0;
                   }
   }




  comu()

  {   unsigned char ret;
      ret=SCON;
      ret=ret & 0x03;
      if (ret==0x01)
       {rec++;
       *rec=SBUF;
       ret=SCON;
       ret=ret & 0xfe;
       SCON=ret;
       }
        else{

       menp ++;
    ret=SCON;
       ret=ret & 0xfd;
       SCON=ret;


       if (*menp!=0x01){

       veces=veces+1;
      SBUF=*menp;
      }
      }
  }


  env_res()   /*rutina que envia los resultados*/
   {
      int i;
      menp=mens;
      rec=recip;
      mens[0]=0x30+pac[0];
      mens[1]=0x30+pac[1];
      mens[2]=0x30+pac[2];

      mens[5]=0x30+fecha[0];
      mens[6]=0x30+fecha[1];

      mens[8]=0x30+fecha[2];
      mens[9]=0x30+fecha[3];

      mens[11]=0x30+fecha[4];
      mens[12]=0x30+fecha[5];

   for (i=0;i<22;i+=3)
       {
	mens[9*(i/3)+19]=0x30+(unsigned char) cont[i];
        mens[9*(i/3)+20]=0x30+(unsigned char) cont[i+1];
        mens[9*(i/3)+21]=0x30+(unsigned char) cont[i+2];
                                          }

    /*          output(TH1,0xfd);*/

	  TH1=0xe6;  /*velocidad: 1200 */
	   TMOD=0x20;
	   TCON=0x40;
	   PCON=0x00;
	   SCON=0x50;/*1 stop bit */
 	  tco=IE;
          tco=tco | 0x10;
          IE=tco;

         SBUF=*menp;

  }


segur()      /*funcion para apagar la impresora*/
{
paso=0x00;
PD000=paso;
}

pita(h)
int h;
{int i;
 PD002=0x10;
 for (i=1;i<h;i++){
 i=i;
 }
 PD002=0x0;
 }




interrupt void EX1_int()                     /*interrupcion 1*/
    {
int i;
int g;
IE=0x00;

tecla=0xff;
 PF001=0x40;
 g=PF000;
 t=c[g];                /*convierto para el teclado nuevo*/
pita(25);
IE=0x84;
   }







/* -----------------------------------------------------------------------*/

/* FUNCIONES RELACIONADAS CON LA IMPRESORA */

/* -----------------------------------------------------------------------*/











 lf(n)
 int n;
     /*line feed*/
{ int g;
  int i;
  for (g=0;g<n;g++)
 {
   write_XDATA(&PA000, 0x30);

   for (i=0;i<velocimp1;i++)
   i=i;
   write_XDATA(&PA000, 0x90);

   for (i=0;i<velocimp1;i++)
     i=i;

   write_XDATA(&PA000, 0xc0);

   for (i=0;i<velocimp1;i++)
   i=i;

   write_XDATA(&PA000, 0x60);
   for (i=0;i<velocimp1;i++)
   i=i;

 }
 }






 imprime (puntos)
  unsigned char *puntos;
  {int i;
  if(puntos!= 0x00)
  {
   write_XDATA(&PA001,*puntos);

  for (i=0;i<tempsimp;i++)
     i=i;

   write_XDATA(&PA001,0x00);
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
   write_XDATA(&PA000,pasoimp);

   for (j=0;j<velocimp;j++)
     i=i;

 }
 }
 else
 {
  for (i=0;i<n;i++)
 { pasoimp=impiz[pasoimp];
   write_XDATA(&PA000,pasoimp);
   for (j=0;j<velocimp;j++)
    j=j;
 }

 }
 }







retcr ()
    {int i;
    int z;
    z=read_XDATA(&PA002) & 0x1;
 while (z==0)
    {avanceimp(1,1);
     z=read_XDATA(&PA002) & 0x1;
    }
  avanceimp(25,0);
  carsporlin=0;
     }










 printer(onoff)
 int onoff;
 {if (onoff==0)
   {
   write_XDATA(&PA000,0x00);
   write_XDATA(&PA001,0x00);
   estado_printer=0;
   }
  else
   {
   estado_printer=1;
   write_XDATA(&PA000,pasoimp);
   write_XDATA(&PA001,0x00);
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



 impreso()
 {
   int i;
/*   lado=0x00;
     if (cong ==0 && conx==0)
         return;
       paso=0x03;
       cr();
       lf(25);
       for(i=0;i<3;i++)
      imp_car(pac[i]*5,0x00);

    paso_i(30);

    for(i=0;i<6;i=i+2)
    {
     imp_car(fecha[i]*5,0x00);
     imp_car(fecha[i+1]*5,0x00);
     paso_i(5);
    }
    cr();
    lf(20);


   for (i=0;i<24;i=i+3)
   {
     if (cont[i]!=0 ||cont[i+1]!=0 ||cont[i+2]!=0)
       {
	if (lado==0x00)
	 { imp_pal((i/3)*20+50,lado);
	  paso_i(7);
	  if (cont[i]==0)
             paso_i(8);
	  else
	  imp_car(cont[i]*5,lado);

          imp_car(cont[i+1]*5,lado);
          imp_car(cont[i+2]*5,lado);
          paso_d(6);
	  lado=true;
           lf(12);
          }
        else
	 {
          imp_car(cont[i+2]*5,lado);
          imp_car(cont[i+1]*5,lado);

	  if (cont[i]==0)
             paso_d(8);
	  else
	  imp_car(cont[i]*5,lado);

	  paso_d(7);
	  imp_pal((i/3)*20+50,lado);
	  paso_i(6);
	  lado=false;
	  lf(12);
          }


    }
    }
paso=0x00;
   PD000=paso;*/

}

