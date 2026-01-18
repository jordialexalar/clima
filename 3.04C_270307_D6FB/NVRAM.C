 #include <fdefines.h>

/*  TEXTOS Y DATOS PARA LA PROGRAMACION DE TECNICAS */
   struct tecnicas {
   char iden[liden];
   char tipo[ltipo];
   char wl1[lwl1];
   char wl2[lwl2];
   char units[lunits];
   char temp[ltemp];
   char std[lstd];
   char factor[lfactor];
   char contra_factor;
   char limlin[llimlin];
   char normalt[lnormalt];
   char normbaj[lnormbaj];
   char sampvol[lsampvol];
   char reacvol[lreacvol];
   char sipvol[lsipvol];
   char readdly[lreaddly];
   char reactime[lreactime];
   char absorblim[labsorblim];
   char numlects[lnumlects];
   char intertime[lintertime];
   char delay[ldelay];
   char dtabsmax[ldtabsmax];
   char decs[ldecs];
   char pos_grabada;
   char absorblimm;
   char puntos_std[3];
   };

   struct points
   {
   char puntos[2];
   char puntosx[10][10];
   char puntosy[10][10];
   };

    struct tecnicas ficher[100];
    struct points ficherstd[20];
    char jorge[]="EOT";
    long int cal_per;
