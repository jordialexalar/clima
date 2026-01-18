
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
   valorx=varx[i-1]+(increx*j);
   valory=coefa*valorx+coefb;
   }
   }
   while (i>0 && varx[i-1] <= varx[i]);



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






if (lastkey==stop)
                    return;

      if (tec==0)
      { salir=1;
      }
      else
      {
        cab_ticket(cual,cal);

       for (i=0;i<20;i++)
        {
        incs[i]=0.0;
	}


       for (i=0;i<lecturas;i++)
      {
          if (i==0)
	      pon_time(0,delay);

          else
	      pon_time(0,interv);

            seguns=0;

           while (time==0x00)
	   {
              if (seguns!=segundo)
	      {
                 seguns=segundo;
                 intar(con,seguns);
	         say(4,17,"    ");
	         say(4,17,con);
	      }
            }


            incs[i]=lee_abs(0,ficher[pul].wl1,ficher[pul].wl2);

            tiempo_incs[i]=tiempo_abs;

            intar(con1,tiempo_incs[i]);


            flotar(con,incs[i],3);


            if (cual>1)
	     {
	      id=i+1;
	      intar(nl,id);
	      strcat(nl,":");

	      say (1,1,strcat(nl,con));

              poneninforme(lineasinforme,4,con);

	     }


	    if (i>0)
            {
                incs[i-1]=incs[i]-incs[i-1];

                tiempo_incs[i-1]=tiempo_incs[i]-tiempo_incs[i-1];


                flotar(con,incs[i-1],3);

               if (incs[i-1]<0)
                   incs[i-1]=incs[i-1] * -1.0;

                intar(con1,tiempo_incs[i-1]);

		say (3,1,con1);
                poneninforme(lineasinforme,12,con);

            }
	    lineasinforme++;
     }


   incabs=0.0;

   if (cual > 1)
   {

     for (i=0;i<(lecturas-1);i++)  /*sumo intervalos*/
       incabs=incs[i]+incabs;

     if (lecturas > 1)
       incabs=(incabs/(lecturas-1)); /*hallo incremento por inter de tiempo*/

     if (cual == 2)
        incabs=incabs*(60.0/interv);
    }
    else
    {incabs=incs[0];
    }

  borrar();

    if (cal==0)
    {
       std=arflot(estan);
       factor=std/incabs;
       flotar(ficher[pul].factor,factor,2);
       strcpy(ficher[pul].std,estan);

       cal++;
         say(1,0,"FACTOR:");
         say(1,0+strlen("FACTOR:"),ficher[pul].factor);

         strcpy(text,ficher[pul].factor);

         poneninforme(2,8,text);

         poneninforme(1,7,estan);
         impinforme(lineasinforme);


    }
    else
    {
        if (cual > 0)
	{
        conc=incabs*factor;
        flotar(con,conc,decimales);
        say(1,0,"CONC.:");
        say(1,0+strlen("CONC.:"),con);
        poneninforme(1,7,con);
        impinforme(lineasinforme);
        }
	else
	{
        conc=incabs;
        flotar(con,conc,decimales);
        say(1,0,"ABS.:");
        say(1,0+strlen("ABS.:"),con);
        poneninforme(1,7,con);
        impinforme(lineasinforme);


	}
      }

   }
}
}





