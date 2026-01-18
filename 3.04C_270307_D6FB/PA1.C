-Z(XDATA)C_ARGX+400=500
-Z(XDATA)X_UDATA,X_IDATA,ECSTR,RF_XDATA=1500
-Z(XDATA)NO_INIT=8000
ero(&PF020,6);
  pon_acero(&PF020,4);
  pon_acero(&PF020,5);

  h=0x00;
  PF021=h;
   {
     res=mira_tec();
     if (res==mix)
       {
	mixer_onoff();
	res=100;
       }
   } while(res==100 && (time==0x00 || n==0));
   if (time==0xff && n!=0)
     res=1000;
 }
return(res);
}
           break;

         default:
	    posi=0x80;
            break;
        }
        posi=posi+(unsigned char) pos;
	i=0;
	j=0;
	teclado=off;
	 while (cha[i]!='\0')
	 {
         codisp(posi+j);
         displcd(cha[i]);
	   j++;
	   i++;
	 }
	teclado=on;
	 disp_say=0;
      }


  */


 say_int(lan,pos,num)
     int lan,pos;
     int num;
  {
   char t[25];
   intar(t,num);
   say(lan,pos,t);
  }



/*
 get (lin,pos,stri,lon,tipo,enter,update)
     int lin,pos;
     unsigned char stri[];
     int lon,tipo,enter,update;
       { unsigned char posi=0xc0;
	 int error=0;
         int i=0;
	 int hk;
	 int pul=0;
         int primera_tecla=0;
         disp_get=1;


         say(lin,pos,"(");
	 say(lin,pos+lon+1,")");
	 pos=pos+1;

	 if (update==1)
	   say(lin,pos,stri);

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
        lon=lon-1;
        posi=posi+(unsigned char) pos;
	i=0;
        error=0;
        codisp(posi+i);
	if (stri[i] == ' ')
           displcd('_');
/*        stri[i]='\0';*/

         while (pul!=stop && pul!=cr && pul!=print && !(pul==wash && menu_prin==1))
	 {
	    pul=100;
            codisp(posi+i);

	    if (i<lon && stri[i] ==' ')
             {
               displcd('_');
	     }

           pul=keyboard(0);

            if (primera_tecla==0 && update==1 && pul!=stop && pul!=cr && pul!=print && !(pul==wash && menu_prin==1))
	      {
		primera_tecla=1;

                 for(hk=0;hk<=lon;hk++)
                  {
		   displcd(' ');
		  }
              }


            switch(pul)
            {

              case 10:
                 if (menu_prin==1)
		   error=5;
		 else
		 {
                 stri[i]='.';
		 stri[i+1]='\0';
                 codisp(posi+i);
                 displcd(stri[i]);

		 if (i<lon)
                   i++;
                 }
                 break;


              case cr:
		 error=1;
                 break;


              case print:
		 error=3;
                 break;

              case cl:
/*                 borrarl(lin,posi,i);*/

                 for(hk=0;hk<=i;hk++)
                  {stri[hk]=' ';
		  }
                   stri[hk]='\0';
                  say(lin,pos,stri);
                 i=0;
                 break;

              case stop:
		 error=2;
                 break;


	      default:
                  if (pul>=0 && pul <=9)
                   { stri[i]=(unsigned char) pul+48;
		     stri[i+1]='\0';
                     codisp(posi+i);
                     displcd(stri[i]);
		     if (i<lon)
                       i++;
                    }
		    break;
	    }
	 }
	 disp_get=0;
        return(error);
      }



rimelinea(i);
    lf(8);
  }

   lf(salto_despues);
   printer(off);
 }
   limpia_inf();
   return(t);
 }



limpia_inf()
{
int i;
for(i=0;i<6400;i++)
 {
  informe[i]=0x00;
 }
}





limpia_informe()
{
int i;
for(i=0;i<6400;i++)
{informe[i]=0x00;
}
}






checkprint()
{int z;
 z=PA002;
 z=z & 0x1;
 if (z==1)
    {
       borrar();
       say(3,1,"IMPRESORA DESACT....");
       inkey(0);
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
    if (num_canales==2)
     y=5;
    else
     y=4;


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
	   apunta(i,TIPO);
	   j=arint(pficher);
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
	   strcpy(text,codigos[i]);
           poneninforme(lineasinforme,9,text);
           lineasinforme++;
        }

    impinforme(lineasinforme,12,36);

 }







 imprime_tecnica(tecnica)
  int tecnica;
  {
    int i;
    int cien_por_cien=0;
    double tecnica1;
    int que;
    int go;
    int h;
    int t;
    int j;
    int ji;
    int num;
    int err=0;
    int haz=0;
    int ord=0;
    int referencia;
    int numero;
    char text[25];

    int escribe_tiempo=0;
    double cien;

    limpia_informe();
    lineasinforme = 0;

    strcpy(text,textos[6+idioma_textos]);

    poneninforme(0,0,text);
    strcpy(text,textos[6+idioma_textos]);
    poneninforme(3,0,text);
    lineasinforme=4;
    strcpy(text,textos[15+idioma_textos]);
    poneninforme(1,0,text);


    intar(text,tecnica);
    poneninforme(1,0+strlen(textos[15+idioma_textos]),text);


    h=lee_parametro(tecnica,TIPO);

    go=lee_parametro(tecnica,ID);
    strcpy(text,codigos[go+pos_ini_cod]);
    poneninforme(2,0,text);


    lineasinforme = 5;

       for (i=0;parametros[i+(h*20)]!=FIN;i++)
	{


	 ord=parametros[i+(h*20)];


	       if (ord!=NADA)
	       {
	       haz=1;
	       }
	       apunta(tecnica,ord);

	 switch (ord)
	    {
	    case UNIDADES:
	       que=arint(pficher);
	       strcpy(text,units[que]);
	       break;

	    case TIEMPO_RATIO:
	       if (cien_por_cien==0)
		  {
		      strcpy(text,pficher);
		  }
	       else
		  haz=0;
               break;

	    case C_TIEMPO_INCUBACION:
	       escribe_tiempo=arint(pficher);
	       haz=0;
	       break;

	    case TIEMPO_INCUBACION:
	       if (escribe_tiempo==1)
		  {
		      strcpy(text,pficher);
		  }
	       else
		  haz=0;

	       break;

	    case TABLA:
	      num=lee_parametro(tecnica,VARIOS_STD);
	      for(j=0;j<num;j++)
	      {
		borrar();
		lineasinforme++;
		intar(text,j+1);
		poneninforme(lineasinforme,1,text);
		apunta(tecnica,TABLA);
		pficher=pficher+j*12;
		strcpy(text,pficher);
		poneninforme(lineasinforme,5,text);
		pficher=pficher+6;
		strcpy(text,pficher);
		poneninforme(lineasinforme,12,text);
		if (cien_por_cien==0)
		 {
		  cien=arflot(text);
		  if (cien==100.0)
		     cien_por_cien=1;
                 }

		haz=0;
	      }
	      lineasinforme++;
	      break;

	  default:
	      strcpy(text,pficher);
	      break;

	 }


	 if (haz==1)
	    {
	       poneninforme(lineasinforme,strlen(txt_prog[ord]),text);
	       strcpy(text,txt_prog[ord]);
	       poneninforme(lineasinforme,0,text);
	       lineasinforme = lineasinforme + 1;
	       haz=0;
	     }


   tecnica=tecnica;
   }

    impinforme(lineasinforme,12,36);

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
