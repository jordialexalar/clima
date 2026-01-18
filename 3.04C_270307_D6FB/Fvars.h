      /* MODULO FVARS.H */

   #include <ftextos.h>


   #include <fpasos.h>
   #include <finfo.h>
   
   char con[26];
   char con1[27];
   int modelo=CLIMA_PLUS;
   int temperatura_fija=0;
   int con_peristaltica=0;

   int versi;

   int keyb[3];
   int n_keyb=0;

   int wiper_pos;

   int estado_zumbador;
   int tiempo_zumbador;

   int menu_prin;
   int atenua[]={3,4,5,6};
   unsigned char pito;
   int ipito;
   int tiempo=0;
   unsigned int tempo=0;
   unsigned int tempo1=0;
   unsigned int segundo=0;
   unsigned char time=0x00;
   unsigned int tempo2;
   unsigned int mili_secs;
   unsigned char time_mili;
   unsigned int counter_timer;

   int ceroe=0;

   double arflot(unsigned char *);
   double leead();

    long int halla_abs();
    long int leeabs();
    int power(int x,int n);





  unsigned char recip[50];
  unsigned char dat;



  unsigned  char tco,h;
  unsigned char lastkey;
  int lastkey1;
  int lastkey2;

  char tecla=0x00;


  int valor,mayor;
  float total;
  int ki;
  char resto;





/* -------------------------------------------------*/



   unsigned char lado;

   unsigned char teclas[400];





    unsigned char fecha[9];
    unsigned char dd[3];
    unsigned char mm[3];
    unsigned char yy[5];
    unsigned char hor[3];
    unsigned char min[3];
    unsigned char seg[3];


    unsigned char pac[4];

    unsigned char mens[50];

    


    int menupric;
    int estado_canal_serie;

    int lineasinforme;

    int filtro_actual=0;

    unsigned char pamem;/* variable que contiene los datos que se sacan
             por el port PA del 8255 que controla la descarga,
             la temperatura y el atenuador*/





 /* ESPACIO DE VARIABLES DE PRUEBA */

    
    
    
    int tiempo_abs=0;
    int tiempo_incs[10];





    int parametros[]={

     /*ABSORCIONES*/
     WL1 ,WL2,TEMP,SIPPING_VOL,READING_DLY,FIN ,0x00,0x00,0x00,0x00,
     0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

     /*CONCENTRACIONES */
     WL1 ,WL2 ,UNITS,TEMP,STD,FACTOR,LIN_LIM,NORM_ALTO,
     NORM_BAJO,DECIMALES,SAMP_VOL,REAGENT_VOL,SIPPING_VOL,READING_DLY,
     REACTION_TIME,FIN,0X0,0X0,0X0,0x00,

     /*CINETICAS*/
     WL1,UNITS,TEMP,FACTOR,N_OF_READINGS,INTERVAL_TIME,DELAY,
     ABSORB_LIM,LIN_LIM,NORM_ALTO,NORM_BAJO,DECIMALES,SAMP_VOL,
     REAGENT_VOL,SIPPING_VOL,FIN,0X0,0X0,0X0,0x0,

     /*FIXED TIME */
     WL1,UNITS,TEMP,STD,FACTOR,INTERVAL_TIME,DELAY,
     LIN_LIM,NORM_ALTO,NORM_BAJO,DECIMALES,SAMP_VOL,REAGENT_VOL,
     SIPPING_VOL,FIN,0X0,0X0,0X0,0x0,0x0,

     /*DIF */
     WL1,WL2,UNITS,TEMP,STD,FACTOR,LIN_LIM,NORM_ALTO,NORM_BAJO,
     DECIMALES,SAMP_VOL,REAGENT_VOL,SIPPING_VOL,READING_DLY,REACTION_TIME,FIN,0X0,0X0,0X0,0x0,

     /*COCIENTE */
     WL1,WL2,UNITS,TEMP,STD,FACTOR,LIN_LIM,NORM_ALTO,NORM_BAJO,
     DECIMALES,SAMP_VOL,REAGENT_VOL,SIPPING_VOL,READING_DLY,REACTION_TIME,FIN,0X0,0X0,0X0,0x0,

     /*MULTI STANDARD*/
     WL1 ,WL2 ,UNITS,VARIOS_STD,N_OF_READINGS,TEMP,LIN_LIM,NORM_ALTO,
     NORM_BAJO,DECIMALES,SAMP_VOL,REAGENT_VOL,SIPPING_VOL,READING_DLY,
     REACTION_TIME,FIN,0x0

     };


    int total_tecnicas;





  /*variables comunicacion*/
  int recibiendo_fichero;
  char car_recib;
  unsigned char car_rec;
  int rec;
  char mensaje[200];
  int recibiendo_mensaje;
  int mensaje_recibido;
  unsigned char ret;
  int car_env;
  unsigned char *menp;
  int veces1;
  int ocupado;
  int errortrans;


  /* variables temperatura */

  int display_temp=0;
  int temp_puesta;
  unsigned char temper;
  char temperat[4];
  int temp_alcanz;
  int time_temp;
  int tempi;
  int tempi1;
  int disp_say=0;
  int disp_get=0;
  int calc_abs=0;



  int lects=30;   /* antes 20 */ /* 40 va bien sin condensador */
  int medabs=0;


  int error_general=0;

/*  int retardo_peristaltica=250;*/

 int mseg;


int teclado=1;

int  n_filtros_tamb=8;
char text[20];

int espera_cero=0;



  int muestra;
  int muestra_ant;
  char wl1[2];
  char wl2[2];
  int sigue=0;
  int decimales;
 
 int n_std;
 int n_lect;
 int lecturas;
 int lecturas1;
 int lecturas2;
 int lecturas3;
 int ih;
 double incs[55];
 double incabs=0.0;
 double abs_act=0.0;
 double abs_ant=0.0;

 double desv_std=0.0;
 double valsup=0.0;
 double valinf=0.0;
 double valabsorblim=0.0;
 double vallimlin=0.0;

 double conc=0.0;
 double factor=0.0;
 
 int interv;
 int delay;
 int retardo_cero;
 int salir=0;
 int tec;
 int cal=1;
 int go;
 int seguns;
 int err;
 int sino=0;
 double std;
 char estan[]="                    ";
 int puesto=1;
 int carry=0;
 int jy;
 int numi;
 int lavar=0;
 int referencia;
 int ji;
 double fpuntosx[10];
 double fpuntosy[10];
 int fpuntos;
 double m[10];
 double n[10];
 int fuera_de_rango_max=0;
 int fuera_de_rango_min=0;
 double sipping=0.0;


char puertos[9];
char *p[9];
char bitauno[]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
char bitacero[]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};
int acceso_a_puertos=0;
int porcen_carry=0;
int a_control=0;
int error_control;
