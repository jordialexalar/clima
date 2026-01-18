

           /*  MODULO    FDEFINES.H                  */

           #define TH_1MSEG  0xfc
           #define TL_1MSEG  0x17

           #define TH_50MSEG   0x3c
           #define TL_50MSEG   0xaf


/*             parametros de las lecturas                     */
           #define TIEMPO_DE_CARGA     4
           #define TIEMPO_DE_DESCARGA  40

           #define RET_MOT_FILTRO  14   /* 50 */
/*           #define RET_MOT_PERISTALTICA  5    5 */
           #define RET_MOT_LECTOR1  70   /* 5 */

/*tiempo de retardo en milisegundos despues del posicionamiento de un filtro*/
          #define estab_filtro 3

        #define      ZUMBADOR   2


           #define DISPLAY_OCUPADO    3

           #define BORRAR             0
           #define NOBORRAR           1



               #define true 0xff
               #define false 0x00

               #define veloc 500  /*velocidad movimiento filtros*/

               #define temps 14

               #define beep  30

/*               #define lects 20   10 ES UN BUEN NUMERO*/

               #define tiem_lect 700 /*antes 75*/


               #define tiempo_min_cero 100


               #define fact  5.5  /*antes 10*/


           #define cr 11
           #define feed 16
           #define chupa 90
           #define wash 10
           #define punt 10
           #define cl 12
           #define esc 12
           #define read 13  /*deberia hacer la miama funcion que el start*/
           #define stop 15
           #define print 14
           #define novalid 2
           #define debug 1  /*para hacer que aparezcan las pruebas*/
           #define NINGUNA_TECLA  100



/*longitudes de cada campo*/
       #define LIDEN        2
       #define LTIPO        1
       #define LWL1         1
       #define LWL2         1
       #define LUNITS       2
       #define LTEMP        2
       #define LSTD         6
       #define LFACTOR      6
       #define LLIN_LIM     6
       #define LN_OF_READINGS 4
       #define LINTERVAL_TIME 4
       #define LDELAY         4
       #define LABSORB_LIM    6
       #define LDT_ABSORB_MAX 6
       #define LNORM_ALTO   6
       #define LNORM_BAJO   6
       #define LDECIMALES     1
       #define LSAMP_VOL    6
       #define LREAGENT_VOL 6
       #define LSIPPING_VOL 6
       #define LREADING_DLY 3
       #define LREACTION_TIME 3
       #define LVARIOS_STD 2
       #define LPOS_GRABADA 1
       #define LABSORBLIMM  1
       #define LCONTRA_FACTOR 1



 /* para el motor paso a paso */
                  #define on  1
                  #define off 0

/* para la impresora*/
               #define derecha 0
               #define izquierda 1

/*               #define velocimp 16
               #define tempsimp 8*/

               #define velocimp 80
               #define velocimp1 50  /* para LF */
           #define tempsimp 55

               #define retardo_display  10



   /* ORDEN DE IMPRESION DE LOS PARAMETROS DE LAS TECNICAS */
       #define IDEN        0
       #define TIPO        1
       #define WL1         2
       #define WL2         3
       #define UNITS       4
       #define TEMP        5
       #define STD         6
       #define FACTOR      7
       #define LIN_LIM     8
       #define N_OF_READINGS 9
       #define INTERVAL_TIME 10
       #define DELAY         11
       #define ABSORB_LIM    12
       #define DT_ABSORB_MAX 13
       #define NORM_ALTO   14
       #define NORM_BAJO   15
       #define DECIMALES     16
       #define SAMP_VOL    17
       #define REAGENT_VOL 18
       #define SIPPING_VOL 19
       #define READING_DLY 20
       #define REACTION_TIME 21
       #define VARIOS_STD 22
       #define ABSORBLIMM  23
       #define CONTRA_FACTOR 24
       #define POS_GRABADA 25


       #define NADA         999
       #define FIN          100


       #define PX           0
       #define PY           1

/*       #define retardo_peristaltica 5*/
         #define retardo_peristaltica 25


        #define APARATO_INICIADO    123.456


       #define ABS    0
       #define CONC   1
       #define CIN    2
       #define FXT    3
       #define DIF    4
       #define REL    5
       #define MSTD   6


       #define CLIMA_JR        1
       #define CLIMA           2
       #define CLIMA_PLUS      3
       #define CLIMA_IRAN      4
       #define CLIMA_PLUS_SP   5

       #define STX     0x02
       #define ETX     0x03

     /*  punteros para los PORTS */

       #define PA000  (*(char *) 0x1A000)
       #define PA001  (*(char *) 0x1A001)
       #define PA002  (*(char *) 0x1A002)
       #define PA003  (*(char *) 0x1A003)

       #define PD000  (*(char *) 0x1D000)
       #define PD001  (*(char *) 0x1D001)
       #define PD002  (*(char *) 0x1D002)
       #define PD003  (*(char *) 0x1D003)

       #define PF000  (*(char *) 0x1F000)
       #define PF001  (*(char *) 0x1F001)
       #define PF002  (*(char *) 0x1F002)
       #define PF003  (*(char *) 0x1F003)

       #define PF010  (*(char *) 0x1F010)
       #define PF011  (*(char *) 0x1F011)
       #define PF012  (*(char *) 0x1F012)
       #define PF013  (*(char *) 0x1F013)

       #define PF020  (*(char *) 0x1F020)
       #define PF021  (*(char *) 0x1F021)
       #define PF022  (*(char *) 0x1F022)
       #define PF023  (*(char *) 0x1F023)

       #define YEAR     (*(char *) 0x17FFF)
       #define MONTH    (*(char *) 0x17FFE)
       #define DATE     (*(char *) 0x17FFD)
       #define DAY      (*(char *) 0x17FFC)
       #define HOURS    (*(char *) 0x17FFB)
       #define MINUTES  (*(char *) 0x17FFA)
       #define SECONDS  (*(char *) 0x17FF9)
       #define CONTROL  (*(char *) 0x17FF8)


       sfr CKCON    =    0x8e;

