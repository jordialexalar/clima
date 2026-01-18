   int i=1;
   while (i<101)
   {
   strcpy(ficher[i+0].code,"0");    /*absorbancia monocromatica*/
   strcpy(ficher[i+0].tipo,"0");
   strcpy(ficher[i+0].wl1,"4");
   strcpy(ficher[i+0].wl2,"0");
   strcpy(ficher[i+0].units,"1");
   strcpy(ficher[i+0].temp,"37");
   strcpy(ficher[i+0].std,"0");
   strcpy(ficher[i+0].factor,"2.0");
   strcpy(ficher[i+0].limlin,"400.0");
   strcpy(ficher[i+0].normalt,"105.0");
   strcpy(ficher[i+0].normbaj,"70.00");
   strcpy(ficher[i+0].sampvol,"10");
   strcpy(ficher[i+0].reacvol,"1000");
   strcpy(ficher[i+0].sipvol,"850");
   strcpy(ficher[i+0].readdly,"2");
   strcpy(ficher[i+0].reactime,"900");
   strcpy(ficher[i+0].absorblim,"00");
   strcpy(ficher[i+0].numlects,"0");
   strcpy(ficher[i+0].intertime,"0");
   strcpy(ficher[i+0].delay,"0");
   strcpy(ficher[i+0].dtabsmax,"0");
   ficher[i+0].pos_grabada='*';
   strcpy(ficher[i+0].absorblimm,"MAX");


   strcpy(ficher[i+1].code,"1");   /*pto. final mono*/
   strcpy(ficher[i+1].tipo,"1");
   strcpy(ficher[i+1].wl1,"4");
   strcpy(ficher[i+1].wl2,"0");
   strcpy(ficher[i+1].units,"1");
   strcpy(ficher[i+1].temp,"37");
   strcpy(ficher[i+1].std,"160.0");
   strcpy(ficher[i+1].factor,"103.0");
   strcpy(ficher[i+1].limlin,"400.0");
   strcpy(ficher[i+1].normalt,"105.0");
   strcpy(ficher[i+1].normbaj,"70.00");
   strcpy(ficher[i+1].sampvol,"10");
   strcpy(ficher[i+1].reacvol,"1000");
   strcpy(ficher[i+1].sipvol,"850");
   strcpy(ficher[i+1].readdly,"2");
   strcpy(ficher[i+1].reactime,"900");
   strcpy(ficher[i+1].absorblim,"00");
   strcpy(ficher[i+1].numlects,"0");
   strcpy(ficher[i+1].intertime,"0");
   strcpy(ficher[i+1].delay,"0");
   strcpy(ficher[i+1].dtabsmax,"0");
   ficher[i+1].pos_grabada='*';
   strcpy(ficher[i+1].absorblimm,"MAX");


   strcpy(ficher[i+2].code,"2");  /*cinetica mono*/
   strcpy(ficher[i+2].tipo,"2");
   strcpy(ficher[i+2].wl1,"4");
   strcpy(ficher[i+2].wl2,"0");
   strcpy(ficher[i+2].units,"1");
   strcpy(ficher[i+2].temp,"37");
   strcpy(ficher[i+2].std,"0");
   strcpy(ficher[i+2].factor,"100");
   strcpy(ficher[i+2].limlin,"0");
   strcpy(ficher[i+2].normalt,"2000");
   strcpy(ficher[i+2].normbaj,"500.0");
   strcpy(ficher[i+2].sampvol,"190");
   strcpy(ficher[i+2].reacvol,"1000");
   strcpy(ficher[i+2].sipvol,"1100");
   strcpy(ficher[i+2].readdly,"0");
   strcpy(ficher[i+2].reactime,"0");
   strcpy(ficher[i+2].absorblim,"2000");
   strcpy(ficher[i+2].numlects,"4");
   strcpy(ficher[i+2].intertime,"15");
   strcpy(ficher[i+2].delay,"20");
   strcpy(ficher[i+2].dtabsmax,"0");
   ficher[i+2].pos_grabada='*';
   strcpy(ficher[i+2].absorblimm,"MAX");

   strcpy(ficher[i+3].code,"3");/*diferencial mono*/
   strcpy(ficher[i+3].tipo,"3");
   strcpy(ficher[i+3].wl1,"4");
   strcpy(ficher[i+3].wl2,"0");
   strcpy(ficher[i+3].units,"1");
   strcpy(ficher[i+3].temp,"37");
   strcpy(ficher[i+3].std,"50.0");
   strcpy(ficher[i+3].factor,"0");
   strcpy(ficher[i+3].limlin,"0");
   strcpy(ficher[i+3].normalt,"5000");
   strcpy(ficher[i+3].normbaj,"5000");
   strcpy(ficher[i+3].sampvol,"2");
   strcpy(ficher[i+3].reacvol,"2");
   strcpy(ficher[i+3].sipvol,"1000");
   strcpy(ficher[i+3].readdly,"0");
   strcpy(ficher[i+3].reactime,"0");
   strcpy(ficher[i+3].absorblim,"0");
   strcpy(ficher[i+3].numlects,"0");
   strcpy(ficher[i+3].intertime,"15");
   strcpy(ficher[i+3].delay,"15");
   strcpy(ficher[i+3].dtabsmax,"5000");
   ficher[i+3].pos_grabada='*';
   strcpy(ficher[i+3].absorblimm,"MAX");

   strcpy(ficher[i+4].code,"0");    /*absorbancia bicromatica*/
   strcpy(ficher[i+4].tipo,"0");
   strcpy(ficher[i+4].wl1,"4");
   strcpy(ficher[i+4].wl2,"2");
   strcpy(ficher[i+4].units,"1");
   strcpy(ficher[i+4].temp,"37");
   strcpy(ficher[i+4].std,"0");
   strcpy(ficher[i+4].factor,"2.0");
   strcpy(ficher[i+4].limlin,"400.0");
   strcpy(ficher[i+4].normalt,"105.0");
   strcpy(ficher[i+4].normbaj,"70.00");
   strcpy(ficher[i+4].sampvol,"10");
   strcpy(ficher[i+4].reacvol,"1000");
   strcpy(ficher[i+4].sipvol,"850");
   strcpy(ficher[i+4].readdly,"2");
   strcpy(ficher[i+4].reactime,"900");
   strcpy(ficher[i+4].absorblim,"00");
   strcpy(ficher[i+4].numlects,"0");
   strcpy(ficher[i+4].intertime,"0");
   strcpy(ficher[i+4].delay,"0");
   strcpy(ficher[i+4].dtabsmax,"0");
   ficher[i+4].pos_grabada='*';
   strcpy(ficher[i+4].absorblimm,"MAX");


   strcpy(ficher[i+5].code,"1");   /*pto. final bi*/
   strcpy(ficher[i+5].tipo,"1");
   strcpy(ficher[i+5].wl1,"4");
   strcpy(ficher[i+5].wl2,"2");
   strcpy(ficher[i+5].units,"1");
   strcpy(ficher[i+5].temp,"37");
   strcpy(ficher[i+5].std,"160.0");
   strcpy(ficher[i+5].factor,"103.0");
   strcpy(ficher[i+5].limlin,"400.0");
   strcpy(ficher[i+5].normalt,"105.0");
   strcpy(ficher[i+5].normbaj,"70.00");
   strcpy(ficher[i+5].sampvol,"10");
   strcpy(ficher[i+5].reacvol,"1000");
   strcpy(ficher[i+5].sipvol,"850");
   strcpy(ficher[i+5].readdly,"2");
   strcpy(ficher[i+5].reactime,"900");
   strcpy(ficher[i+5].absorblim,"00");
   strcpy(ficher[i+5].numlects,"0");
   strcpy(ficher[i+5].intertime,"0");
   strcpy(ficher[i+5].delay,"0");
   strcpy(ficher[i+5].dtabsmax,"0");
   ficher[i+5].pos_grabada='*';
   strcpy(ficher[i+5].absorblimm,"MAX");


   strcpy(ficher[i+6].code,"2");  /*cinetica bi*/
   strcpy(ficher[i+6].tipo,"2");
   strcpy(ficher[i+6].wl1,"4");
   strcpy(ficher[i+6].wl2,"2");
   strcpy(ficher[i+6].units,"1");
   strcpy(ficher[i+6].temp,"37");
   strcpy(ficher[i+6].std,"0");
   strcpy(ficher[i+6].factor,"100");
   strcpy(ficher[i+6].limlin,"0");
   strcpy(ficher[i+6].normalt,"2000");
   strcpy(ficher[i+6].normbaj,"500.0");
   strcpy(ficher[i+6].sampvol,"190");
   strcpy(ficher[i+6].reacvol,"1000");
   strcpy(ficher[i+6].sipvol,"1100");
   strcpy(ficher[i+6].readdly,"0");
   strcpy(ficher[i+6].reactime,"0");
   strcpy(ficher[i+6].absorblim,"2000");
   strcpy(ficher[i+6].numlects,"4");
   strcpy(ficher[i+6].intertime,"15");
   strcpy(ficher[i+6].delay,"20");
   strcpy(ficher[i+6].dtabsmax,"0");
   ficher[i+6].pos_grabada='*';
   strcpy(ficher[i+6].absorblimm,"MAX");

   strcpy(ficher[i+7].code,"3");/*diferencial bi*/
   strcpy(ficher[i+7].tipo,"3");
   strcpy(ficher[i+7].wl1,"4");
   strcpy(ficher[i+7].wl2,"2");
   strcpy(ficher[i+7].units,"1");
   strcpy(ficher[i+7].temp,"37");
   strcpy(ficher[i+7].std,"50.0");
   strcpy(ficher[i+7].factor,"0");
   strcpy(ficher[i+7].limlin,"0");
   strcpy(ficher[i+7].normalt,"5000");
   strcpy(ficher[i+7].normbaj,"5000");
   strcpy(ficher[i+7].sampvol,"2");
   strcpy(ficher[i+7].reacvol,"2");
   strcpy(ficher[i+7].sipvol,"1000");
   strcpy(ficher[i+7].readdly,"0");
   strcpy(ficher[i+7].reactime,"0");
   strcpy(ficher[i+7].absorblim,"0");
   strcpy(ficher[i+7].numlects,"0");
   strcpy(ficher[i+7].intertime,"15");
   strcpy(ficher[i+7].delay,"15");
   strcpy(ficher[i+7].dtabsmax,"5000");
   ficher[i+7].pos_grabada='*';
   strcpy(ficher[i+7].absorblimm,"MAX");
   i=i+8;
   }
