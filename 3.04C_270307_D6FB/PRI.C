



imp_car(let,der_izq) /*escribe un caracter*/
char let;
int der_izq;
{  int i;
  long int posletra=0;
  posletra=let;
  posletra=posletra*5;

   if(der_izq==derecha)
   {
   for (i=posletra;i<posletra+5;i++)
  { imprime(letras[i]);
   pasoimp_d(1);
   }
   pasoimp_d(3);
  }

   else
     {
   for (i=posletra+4;i>=posletra;i--)
  { imprime(letras[i]);
   pasoimp_i(1);
   }
   pasoimp_i(3);

     }
   }





cr()
{
 int z;
 z=read_XDATA(0xa002) & 0x1;
 while (z==0)
    {pasoimp_d(1);
     z=read_XDATA(0xa002) & 0x1;
    }
 pasoimp_i(50);
 }





pasoimp(n,derizq)
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




imptest()
 {char mensaje[]="HOLA SOY JORGE";
  int i;
  cr();

 for (i=0;i<15;i++)
  {imp_car(mensaje[i],derecha);
  }

  }