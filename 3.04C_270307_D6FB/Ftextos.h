
/* TEXTOS DEL PROGRAMA                             */
#define off_textos  610
#define off_txt_prog  100

   int idioma_textos=0;


    char *textos[off_textos]={
    #include <spanish.h>
    #include <english.h>
    #include <french.h>
     ""
    };
   unsigned char *txt_prog[off_txt_prog];

   unsigned char *units[]={"MG/DL","U/L","G/DL",
   "MU/ML","G/L","MCG/ML",
   "%","NG/ML","MCG%","MEQ/L","MCG/DL","MMO/L",
   "MCMO/L","NMO/L","KAT/L","MCKAT/L"};


   unsigned char *wl[]={"000","340","405","500","546","578","630","---","---"};

   unsigned char *tipos[7];




#define off_codigos  400

   int idioma_codigos=0;
   int num_codigos=52;
   int pos_ini_cod;
                       /* 6 digitos */
   unsigned char *codigos[off_codigos]=
   {
     #include <codigos.h>
     ""
   };


