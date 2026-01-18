/*haz_tecnica1(pul,cual)
int pul;
int cual;

 {double f=0.0;
  int sigue=0;
  int decimales;
  int i;
  int fix=0;
  float fi=0.0;
 char text[25];
 double id;
 int lecturas;
 double incs[20];
 double incabs=0.0;
 double conc=0.0;
 double factor=0.0;
 char con[]="                         ";
 char nl[20];
 int interv;
 int delay;
 int salir=0;
 int tec;
 int cal=1;
 int seguns;
 int err;
 int sino=0;
 double std;
 char estan[]="                    ";

 borrar();
   pon_temp(ficher[pul].temp);
   interv=arflot(ficher[pul].intertime);
   factor=arflot(ficher[pul].factor);
   decimales=arflot(ficher[pul].decs);


   if (cual==2)
    {   lecturas=arflot(ficher[pul].numlects);
       delay=arflot(ficher[pul].delay);
    }
   if (cual==3)
     {  lecturas=2;
        delay=arflot(ficher[pul].delay);
     }

   if (cual==1 )
     {  lecturas=1;
        delay=arflot(ficher[pul].readdly);
     }

   if (cual==0 )
     {  lecturas=1;
        delay=0;
     }


  if (std!=0 && cual!=2 && cual!=0)
    sino=aviso(1,1,"CALIBRAR (S/N)");

    if (lastkey==stop)
      return;

  if (sino==1)
    {
    say(1,1,"NUEVO ESTANDAR:");
    err=get(1,1+len("CONC. ESTANDAR:"),estan,7,1,1);
    borrar();
    say(2,1,"PONGA BLANCO");
    say(3,1,"PULSE START ...");
    tec=espera_tecla(read);
    borrar();
    if (lastkey==stop)
      return;

    halla_cero(0,ficher[pul].wl1,ficher[pul].wl2);
    cal=0;
    }

 else
  {
   factor=arflot(ficher[pul].factor);
    say(2,1,"PONGA BLANCO");
    say(3,1,"PULSE START ...");
    tec=espera_tecla(read);
    borrar();
    if (lastkey==stop)
      return;

    halla_cero(0,ficher[pul].wl1,ficher[pul].wl2);
  }
   borrar();




      while (salir==0)
      {
          borrar();
          if (cal==0)
             {
                say(1,1,"INTRODUZCA ESTANDAR");
                say(2,1,"PULSE TECLA START ...");
              }
          else
              {
               say(2,0,"INTRODUZCA MUESTRA");
               say(3,0,"PULSE START ...");

              }
                tec=espera_tecla(read);
                borrar();
                if (lastkey==stop)
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

            incs[i]=redondeo(incs[i],3);

            flotar(con,incs[i],3);

            if (cual>1)
	     {
	      id=i+1;
	      flotar(nl,id,0);
	      strcat(nl,":");
	      say (1,1,strcat(nl,con));
              poneninforme(lineasinforme,4,con);
	     }


	    if (i>0)
            {
                incs[i-1]=incs[i]-incs[i-1];
                if (incs[i-1]<0)
                   incs[i-1]=incs[i-1]*-1.0;

                incs[i-1]=redondeo(incs[i-1],3);

                flotar(con,incs[i-1],3);
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

        */


