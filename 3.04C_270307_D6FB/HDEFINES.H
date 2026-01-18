#define true 0xff
#define false 0x00

#define veloc 100  /*velocidad movimiento filtros*/

#define temps 14
#define lects 1   /*10 ES UN BUEN NUMERO*/
#define tiem_lect 100
#define fact  13.58
#define cr 11
#define punt 10
#define cl 12
#define esc 12
#define read 13  /*deberia hacer la miama funcion que el start*/
#define stop 15
#define print 14
#define novalid 2
#define debug 1  /*para hacer que aparezcan las pruebas*/




/*longitudes de cada campo*/

   #define lcode 2
   #define ltipo 2
   #define lwl1 2
   #define lwl2 2
   #define lunits 2
   #define ltemp 3
   #define lstd 7
   #define lfactor 7
   #define llimlin 7
   #define lnormalt 8
   #define lnormbaj 8
   #define lsampvol 6
   #define lreacvol 6
   #define lsipvol 6
   #define lreaddly 6
   #define lreactime 6
   #define labsorblim 16
   #define lnumlects 3
   #define lintertime 4
   #define ldelay 4
   #define ldtabsmax 6

/*tiempo de retardo despues del posicionamiento de un filtro*/
   #define estab_filtro 1


 /* para el motor paso a paso */
   #define on  1
   #define off 0