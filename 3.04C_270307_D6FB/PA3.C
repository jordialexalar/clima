 calibrar(impo)
 int impo;
 { double abs=0;
   int salir=0;
   char ent[7];
   int pul=0;
   int y;
   int j;
   char absor[10];
   say(1,0,textos[28+idioma_textos]);
   lista_pant(wl,1,8,7,2,0,3,1);
   get(1,0+strlen(textos[28+idioma_textos]),ent,1,1,1);

   if (ent[0]>='1' && ent[0]<='7')
   {
   borrar();
   say(2,2,textos[16+idioma_textos]);
   say(3,2,textos[17+idioma_textos]);
   j=espera_teclas(read,stop);
   if (j==0)
     return(0);

   halla_cero(ent,"0");
   if (error_general!=0)
     return(0);

   borrar();
   say(1,1,textos[29+idioma_textos]);

   while (salir==0)
   {

    lee_abs(0,ent,"");
    abs=tiempo_abs/(1000.0);
    flotar(absor,abs,3);
    strcat(absor,"     ");
    say(1,1+strlen(textos[29+idioma_textos]),absor);


    pul=mira_tec();
    if (pul==100 && impo==1)
      { espera(0,10);
        pul=print;
      }

    if (pul!=100)
     {
	switch(pul)
	 {
	  case 0:
            halla_cero(ent,"");
            break;

	  case stop:
 	    salir=1;
	    break;

	  case print:
 	    lineasinforme=0;
            poneninforme(lineasinforme,4,textos[30+idioma_textos]);
            poneninforme(lineasinforme,4+strlen(textos[30+idioma_textos]),absor);
            lineasinforme++;
	    impinforme(lineasinforme,2,2);
	    break;

	 }
     }

   }
  }
}


