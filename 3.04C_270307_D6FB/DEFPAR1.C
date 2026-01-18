 /*absorciones*/
 parametros[h++]=WL1;
       if (tiene_pelt==1)
          parametros[h++]=TEMP;
       else
          parametros[h++]=NADA;
 parametros[h++]=FIN;

 /*concentraciones*/
 h=20;
       parametros[h++]=WL1;
       parametros[h++]=WL2 ;
       parametros[h++]=UNITS;

       if (tiene_pelt==1)
          parametros[h++]=TEMP;
       else
          parametros[h++]=NADA;

       parametros[h++]=STD;
       parametros[h++]=FACTOR;
       parametros[h++]=LIN_LIM;
       parametros[h++]=NORM_ALTO;
       parametros[h++]=NORM_BAJO;
       parametros[h++]=DECIMALES;
       parametros[h++]=SAMP_VOL;
       parametros[h++]=REAGENT_VOL;
       if (tiene_peris==1)
          parametros[h++]=SIPPING_VOL;
       else
          parametros[h++]=NADA;
       parametros[h++]=READING_DLY;
       parametros[h++]=REACTION_TIME;
       parametros[h++]=FIN;

 /*cineticas*/
       h=40;
       parametros[h++]=WL1  ;
       parametros[h++]=UNITS ;
       if (tiene_pelt==1)
          parametros[h++]=TEMP;
       else
          parametros[h++]=NADA;
       parametros[h++]=FACTOR ;
       parametros[h++]=N_OF_READINGS   ;
       parametros[h++]=INTERVAL_TIME   ;
       parametros[h++]=DELAY  ;
       parametros[h++]=ABSORB_LIM    ;
       parametros[h++]=LIN_LIM;
       parametros[h++]=NORM_ALTO   ;
       parametros[h++]=NORM_BAJO;
       parametros[h++]=DECIMALES;
       parametros[h++]=SAMP_VOL  ;
       parametros[h++]=REAGENT_VOL   ;
       if (tiene_peris==1)
          parametros[h++]=SIPPING_VOL;
       else
          parametros[h++]=NADA;
       parametros[h++]=FIN   ;

 /*fixed time*/
       h=60;
       parametros[h++]=WL1     ;
       parametros[h++]=WL2      ;
       parametros[h++]=UNITS     ;
       if (tiene_pelt==1)
          parametros[h++]=TEMP;
       else
          parametros[h++]=NADA;
       parametros[h++]=STD         ;
       parametros[h++]=FACTOR       ;
       parametros[h++]=INTERVAL_TIME ;
       parametros[h++]=DELAY;
       parametros[h++]=NADA;  /* HABIA DT_ABS_MAX*/
       parametros[h++]=LIN_LIM;
       parametros[h++]=NORM_ALTO     ;
       parametros[h++]=NORM_BAJO      ;
       parametros[h++]=DECIMALES    ;
       parametros[h++]=SAMP_VOL;
       parametros[h++]=REAGENT_VOL ;
       if (tiene_peris==1)
          parametros[h++]=SIPPING_VOL;
       else
          parametros[h++]=NADA;
       parametros[h++]=FIN;

 /*diferenciales*/
       h=80;
       parametros[h++]=WL1     ;
       parametros[h++]=WL2      ;
       parametros[h++]=UNITS     ;
       if (tiene_pelt==1)
          parametros[h++]=TEMP;
       else
          parametros[h++]=NADA;
       parametros[h++]=STD         ;
       parametros[h++]=FACTOR       ;
       parametros[h++]=NADA;  /* DELAY*/
       parametros[h++]=NADA;   /*DT_ABSORB_MAX   */
       parametros[h++]=LIN_LIM;
       parametros[h++]=NORM_ALTO     ;
       parametros[h++]=NORM_BAJO      ;
       parametros[h++]=DECIMALES    ;
       parametros[h++]=SAMP_VOL;
       parametros[h++]=REAGENT_VOL ;
       if (tiene_peris==1)
          parametros[h++]=SIPPING_VOL;
       else
          parametros[h++]=NADA;
       parametros[h++]=FIN;

 /*codiente*/
       h=100;
       parametros[h++]=WL1     ;
       parametros[h++]=WL2      ;
       parametros[h++]=UNITS     ;
       if (tiene_pelt==1)
          parametros[h++]=TEMP;
       else
          parametros[h++]=NADA;
       parametros[h++]=STD         ;
       parametros[h++]=FACTOR       ;
       parametros[h++]=LIN_LIM;
       parametros[h++]=NORM_ALTO     ;
       parametros[h++]=NORM_BAJO      ;
       parametros[h++]=DECIMALES    ;
       parametros[h++]=SAMP_VOL;
       parametros[h++]=REAGENT_VOL ;
       if (tiene_peris==1)
          parametros[h++]=SIPPING_VOL;
       else
          parametros[h++]=NADA;
       parametros[h++]=FIN;


       txt_prog[0]="IDENTIFICACION:";
       txt_prog[1]="TIPO:";
       txt_prog[WL1]="WL1:";
       txt_prog[WL2]="WL2:";
       txt_prog[UNITS]="UNIDADES:";
       txt_prog[TEMP]="TEMPERATURA:";
       txt_prog[STD]="STD:";
       txt_prog[FACTOR]="FACTOR:";
       txt_prog[LIN_LIM]="LIMIT. LIN.:";
       txt_prog[N_OF_READINGS]="N. DE LECTS.:";
       txt_prog[INTERVAL_TIME]="INTERVALO:";
       txt_prog[DELAY]="ESPERA:";
       txt_prog[ABSORB_LIM]="ABS. LIM:";
       txt_prog[DT_ABSORB_MAX]="DT. ABS. MAX:";
       txt_prog[NORM_ALTO]="NORM. ALTO:";
       txt_prog[NORM_BAJO]="NORM. BAJO:";
       txt_prog[DECIMALES]="DECIMALES:";
       txt_prog[SAMP_VOL]="VOL. MUESTRA:";
       txt_prog[REAGENT_VOL]="VOL. REACTIVO:";
       txt_prog[SIPPING_VOL]="VOL. ABSOR.:";
       txt_prog[READING_DLY]="RETARDO LECT.:";
       txt_prog[REACTION_TIME]="TIEMPO REAC.:";


