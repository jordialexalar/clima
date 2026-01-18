                     /* MODULO FPASOS.H   */

   unsigned char de[]={0x60,0xc0,0x90,0x30};
/*   unsigned char iz[]={0x50,0x48,0x28,0x30};*/
   unsigned char iz[]={0x06,0x03,0x09,0x0c};

   unsigned char paso=0x00;


/* 1 . NARANJA AMARILLO NEGRO ROJO - BICOLORES (MOTOR MAE) */
/* 1 . VERDE ROSA VERDE/B ROSA/B NEGRO/B NARANJA NEGRO BLANCO (MOTOR MBA) */

   unsigned char periz[]={0x60,0x30,0x90,0xc0};
   unsigned char perde[]={0xc0,0x90,0x30,0x60};

   unsigned char perpaso=0x00;


/*    int pasos_filtro[]={0,1,8,14,19,26,31,37,42};*/

/* NEGRO MARRON NARANJA AMARILLO (MOTOR LOBER) */
/*      int pasos_filtro[]={0,49,7,15,21,28,35,42,0};*/

      int pasos_filtro[]={0,6,13,19,26,33,40,47,6};


