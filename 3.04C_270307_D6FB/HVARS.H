   int entra=0;
   int th=0;
   int tl=0;
   const unsigned char a='A';
   long int averq=0;
   double flo1=0.00;
   double flo2=0.00;

   int inf=0;
   int veri[]={0,0,0,0,0};
   int debr=0;

   unsigned char a1='B';
   char nuinf[]={'1','1','1','1','1','1','1'};
   unsigned char a2='C';

    int orden[4][17]={(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
	        	   (1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,100,0),
		           (1,2,3,4,5,7,15,16,17,18,9,10,11,12,13,100,0),
		           (1,2,3,4,5,6,7,16,17,19,9,10,11,12,13,100,0)
			   };


    int orden1[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	        	   1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,100,0,
		           1,2,3,4,5,7,15,16,17,18,9,10,11,12,13,100,0,
		           1,2,3,4,5,6,7,16,17,19,9,10,11,12,13,100,0
			   };



   long int tiempo=0;
   unsigned long int tempo=0;
   unsigned int tempo1=0;
   unsigned int segundo=0;
   unsigned char time=0x00;


   long int ceroe=0;


   unsigned int start,ihi,segs1;

   unsigned char b='B';
   double flo=0.00;

   long int d=1000000;

   unsigned char e='C';

   int f=1;

    unsigned char g1='D';

 unsigned int h1=1;

unsigned char i1='E';


  long int factor;

int gyu;

double arflot(unsigned char *);
double leead();

   long int halla_abs();
   long int leeabs();
   int power(int x,int n);

double v1,v2,v3,v4;

int i;
int nconv;
int fconv;
unsigned char ad[130];
int ghj;
int pp1;


 int ty;
 int nty[7];
 unsigned int nth;
 double rt;

  int veces;


  unsigned char recip[50],*rec;
  unsigned char dat,*menp;

  int temp1; /*contador para la base de tiempos*/
  int temp2; /*contador para la base de tiempos*/
  int segs;




  unsigned  char tco,t,h;

  char tecla;

  char disp[10];

  int cont[24],cong,conx,ncont;

  int valor,mayor;
  float total;
  int ki;
  char resto;
/* TEXTOS DEL PROGRAMA                             */

    char * const textos[]={
    "CHECK",
    "CODIGO DE PROGRAMA ?:",
    "NUMERO DE TECNICA:" };

/*-------------------------------------------------*/


/*  TEXTOS Y DATOS PARA LA PROGRAMACION DE TECNICAS */
  struct tecnicas {
   char code[lcode];
   char tipo[ltipo];
   char wl1[lwl1];
   char wl2[lwl2];
   char units[lunits];
   char temp[ltemp];
   char std[lstd];
   char factor[lfactor];
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
   };

  char *tecn[]={
   /*char code[2];*/"  ",
   /*char tipo[2];*/"  ",
 /*   char wl1[2];*/"  ",
 /*  char wl2[2];*/"  ",
/*   char units[2];*/"  ",
 /*  char temp[3];*/"   ",
 /*  char std[7];*/"       ",
/*   char factor[7];*/"       ",
/*   char limlin[7];*/"       ",
/*   char normalt[8];*/"       ",
/*   char normbaj[8];*/"       ",
/*   char sampvol[6];*/"      ",
/*   char reacvol[6];*/"      ",
 /*  char sipvol[6];*/ "      ",
 /*  char readdly[6];*/"      ",
/*   char reactime[6];*/"      ",
 /*  char absorblim[16];*/"                ",
 /*  char numlects[3];*/"   ",
 /*  char intertime[4];*/"    ",
 /*  char delay[4];*/ "    ",
 /*  char dtabsmax[6];*/ "      "
   };


   struct tecnicas ficher[10];

   struct tecnicas *puntfic;
   char *offsfic;

  offstecn[]={
    lcode,
    ltipo,
    lwl1,
    lwl2,
    lunits,
    ltemp,
    lstd,
    lfactor,
    llimlin,
    lnormalt,
    lnormbaj,
    lsampvol,
    lreacvol,
    lsipvol,
    lreaddly,
    lreactime,
    labsorblim,
    lnumlects,
    lintertime,
    ldelay,
    ldtabsmax

    };

   unsigned char *lin[10][20];

   unsigned char *units[]={"MG/DL","G/DL","U/L","MU/ML","MCG/ML"};
   unsigned char *wl[]={"405","505","546","578","630","670"};
   unsigned char *tipos[]={"ABS.","CONC.","KIN.","FxT."};
   unsigned char *codigos[]={"1","2","3","4","5","6","7","8","9"};
   unsigned char *txt_prog[]={
       "CODIGO:",
       "TIPO:",
       "WL1:",
       "WL2:",
       "UNITS:",
       "TEMP:",
       "STD:",
       "FACTOR:",
       "LINEARITY LIM:",
       "NORM. ALTO:",
       "NORM. BAJO:",
       "SAMPLE VOL.:",
       "REAGENT VOL.:",
       "SIPPING VOL.:",
       "READING DLY.:",
       "REACTION TIME:",
       "N. OF READINGS:",
       "INTERVAL TIME:",
       "DELAY:",
       "ABSORB. LIM:",
       "DT. ABSORB. MAX:"};








/* -------------------------------------------------*/


  unsigned char ent[20];

   unsigned char lado;
   unsigned char de[15],iz[15],paso;
   char spac[50];