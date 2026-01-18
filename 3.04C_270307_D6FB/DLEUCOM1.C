/* PROGRAMA PARA LA NUEVA CARATULA DE LEUCOFORM CON LA TECLA
6 COMO FUNCION DE CONTAJE */


#include <io51.h>
#define true 0xff
#define false 0x00
#define veloc 30
#define temps 14

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

 write_XDATA(0x0f001,0x0a); /*inicializacion del 8279*/
 write_XDATA(0x0f001,0x34);
 write_XDATA(0x0f001,0x40);
 write_XDATA(0x0f001,0xa0);
 write_XDATA(0x0f001,0xe0);
 write_XDATA(0x0f001,0x90);
  borrar();
    on();
     menp=&mens[0];


 de[3]=0x6;
 de[6]=0xc;
 de[9]=0x3;
 de[12]=0x9;

 iz[3]=0x9;
 iz[6]=0x3;
 iz[9]=0xc;
 iz[12]=0x6;




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
/*      for (ghj=0;ghj<10;ghj++)    bucle de retardo
	{
	ghj=ghj;
	}
        */



 write_XDATA(0xd003,0x81); /*inicializacion del 8255*/
 paso=0x0;
 write_XDATA(0xd000,paso);/*inicializo impresora*/
 write_XDATA(0xd001,0);/*inicializo impresora*/



tco=0x84;
output(0xA8,tco);




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
          write_XDATA(0x1ffc,h);
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
              write_XDATA(0x1ff6,0x88);


                impreso();
                lf(60);
                break;

       /*   case 6:
          write_XDATA(0xd002,0xe0);
	  break;
         */
	  case 7:
              pon_fecha();
            break;


	  case 8:
              camb_pac(pac);
            break;

        /*   case 9:
              camb_pac(paci);
	      break;
          */
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



tecl()
{
int i;
int g;
output(IE,0x00);

tecla=0xff;
 write_XDATA(0xf001,0x40);
 g=read_XDATA(0xf000);
 t=c[g];                /*convierto para el teclado nuevo*/
write_XDATA(0x1fff,t);
pita(25);
output(IE,0x84);
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
             write_XDATA(0xf001,0x90+14-(2*(ncont/3)));
             write_XDATA(0xf000,disp[cont[ncont+2]]);
             write_XDATA(0xf000,disp[cont[ncont+1]]);
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

    write_XDATA(0xf001,0x90);  /*posicion cero*/

  for (i=0;i<22;i=i+3)
    {

    if (cont[i]==0)
      {
       write_XDATA(0xf000,disp[cont[21-i+2]]);
      write_XDATA(0xf000,disp[cont[21-i+1]]);
      }


     else


     {write_XDATA(0xf001,0x90);
      for(j=0;j<16;j++)
       write_XDATA(0xf000,0x01);

       write_XDATA(0xf001,0x97);
      for(j=0;j<3;j++)
       write_XDATA(0xf000,disp[cont[i+2-j]]);
       break;
      }




    }


/*        displ(disp[cont[22]],14);
        displ(disp[cont[23]],15);
  */


  inc_num(pac);
       env_res();
       pita(1000);
      impreso();
      lf(60);
                           }



borrar()                 /*borrado del display*/
 {int i;
 write_XDATA(0xf001,0xd0);
 for (i=0;i<30;i++)
 i=i;
 }

 on()
 {
      write_XDATA(0xf001,0x9c);

      vis(0x76);         /* write_XDATA(0xf000,0x71);*/
      vis(0xf6);

  }


 inhib_int()
 {  tco=input(IE);
   tco=tco & 0x7f;
   output(IE,tco);
 }

 habil_int()
 {	  tco=input(IE);
          tco=tco | 0x84;
          output(IE,tco);
  }


cr()
{
 int z;
 z=read_XDATA(0xd002) & 0x1;
 while (z==0)
    {paso_d(1);
     z=read_XDATA(0xd002) & 0x1;
    }
 paso_i(50);
 }





paso_d(n)
int n;            /*paso a la derecha*/
{int i;
 int j;
 for (i=0;i<n;i++)
 { paso=de[paso];
   write_XDATA(0xd000,paso);

   for (j=0;j<veloc;j++)
     i=i;

 }
 }




 paso_i(n)
int n;
     /*paso a la izquierda*/
{ int g;
  int h;
  for (g=0;g<n;g++)
 { paso=iz[paso];
   write_XDATA(0xd000,paso);
   for (h=0;h<veloc;h++)
    g=g;
 }
 }



disp_fun()
 {         write_XDATA(0xf001,0x9c);
          vis(disp[h]);          /*write_XDATA(0xf000,disp[h]);*/
          vis(0x47);         /* write_XDATA(0xf000,0x71);*/


  }


displ (num,pos)                      /*visualizar en una posicion determinadsa*/
  unsigned char num,pos;
  {
  write_XDATA(0xf001,128+15-pos);
  write_XDATA(0xf000,num);
  }


  vis(num)                        /*visualizar sin posicion determinada*/
  unsigned char num;
  {
    write_XDATA(0xf000,num);
  }


 lf(n)
 int n;
     /*line feed*/
{ int g;
  int i;
  for (g=0;g<n;g++)
 {
   write_XDATA(0xd000, 0x30);

   for (i=0;i<veloc;i++)
   i=i;
   write_XDATA(0xd000, 0x90);

   for (i=0;i<veloc;i++)
     i=i;

   write_XDATA(0xd000, 0xc0);

   for (i=0;i<veloc;i++)
   i=i;

   write_XDATA(0xd000, 0x60);
   for (i=0;i<veloc;i++)
   i=i;


 }
 }

imprime(punt)       /*funcion para imprimir columna de puntos*/
 unsigned char punt;
  {int i;
   write_XDATA(0xd001,punt);
   for (i=0;i<temps;i++)
     i=i;
   write_XDATA(0xd001,0);
   }



imp_car(let,der_izq) /*escribe un caracter*/
int let;
unsigned char der_izq;
{  int i;
   if(der_izq==false){
   for (i=let;i<let+5;i++)
  { imprime(car_imp[i]);
   paso_i(1);
   }
   paso_i(3);
		  }

   else
     {
   for (i=let+4;i>=let;i--)
  { imprime(car_imp[i]);
   paso_d(1);
   }
   paso_d(3);

     }
   }




imp_pal(numero,der_izq)
 int numero;
 unsigned char der_izq;
 {
   if (der_izq==false)
     {  int s;
	for(s=numero;s<numero+20;s=s+5)
        imp_car(s,der_izq);
      }
    else
     {  int s;
	for(s=numero+15;s>=numero;s=s-5)
        imp_car(s,der_izq);
      }
}



 impreso()
 {
   int i;
   lado=0x00;
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
   write_XDATA(0xd000,paso);

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
      ret=input(SCON);
      ret=ret & 0x03;
      if (ret==0x01)
       {rec++;
       *rec=input(SBUF);
       ret=input(SCON);
       ret=ret & 0xfe;
       output(SCON,ret);
       }
        else{

       menp ++;
    ret=input(SCON);
       ret=ret & 0xfd;
       output(SCON,ret);


       if (*menp!=0x01){

       veces=veces+1;
      output(SBUF,*menp);
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

	  output(TH1,0xe6);  /*velocidad: 1200 */
	   output(TMOD,0x20);
	   output(TCON,0x40);
	   output(PCON,0x00);
	   output(SCON,0x50);/*1 stop bit */
 	  tco=input(IE);
          tco=tco | 0x10;
          output(IE,tco);

         output(SBUF,*menp);

  }


segur()      /*funcion para apagar la impresora*/
{
paso=0x00;
write_XDATA(0xd000,paso);
}

pita(h)
int h;
{int i;
 write_XDATA(0xd002,0x10);
 for (i=1;i<h;i++){
 i=i;
 }
 write_XDATA(0xd002,0x0);
 }