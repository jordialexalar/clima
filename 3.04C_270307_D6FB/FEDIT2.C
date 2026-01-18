       /*MODULO   FEDIT2.C        */


       /*Contiene funciones para edicion de t‚cnicas*/


#include <fdefines.h>
#include <fexterns.h>
#include <string.h>

extern int espera_tecla(int nun,int nun1);


  busca(entr)
  char entr[];
  {
/*    int i;
    int esta=0;
    int cua;

    for(i=0;i<10;i++)
    {
    if (strcmp(entr,ficher[i].iden) == 0)
      {esta=1;
       cua=i;
       break;
      }
    }
    if (esta==0)
    return(-1);
    else
    return(cua);*/
}








lista_pant(w,j,y,sep,lin,bor,items_por_linea,h)
char *w[];
int j;
int y;
int sep;
int bor;
int items_por_linea;
int h;
{
int posh,posv,salir;
int page=0;
int colu;
int calo;
int tec;
int t;

char cadena[20] ;
int items;

          posh=lin;
          salir=0;
          posv=0;
          t=j;

          while (salir==0 && t<y)
          {
          if (bor==1)
              borrar();
           posv=0;
           posh=lin;
           page++;
           items=items_por_linea;

        while (posh<5 && t<y)
        {
            intar(cadena,h);
            say(posh,posv,cadena);
            colu=posv+strlen(cadena);
            say(posh,colu,".");
            say(posh,colu+1,w[t]);

            posv=posv+sep;

            items--;
           if (items==0)
             {posv=0;
              posh++;
              items=items_por_linea;
             }
           h++;
           t++;
           }
          if (page>1 || (page==1 && t<y))
          {
           if (espera_teclas(print,stop)==0)
              salir=1;
          }
          }

  }




camb_fact(pul)
int pul;
{
int salir;
int err;
double floatnum;
salir=0;

               while (salir==0 )
          {
          say(1,0,txt_prog[FACTOR]);
          apunta(pul,FACTOR);
          err=get(1,strlen(txt_prog[FACTOR]),pficher,LFACTOR,1,1,1);
              floatnum=arflot(pficher);
          if (floatnum<0 || floatnum >99999 || *pficher==' ')
        salir=0;
              else
        salir=1;
          }

}




camb_estan(pul)
int pul;

{
int salir;
int err;
double floatnum;
salir=0;

salir=0;
              while (salir==0)
          {
          say(1,0,txt_prog[STD]);
          apunta(pul,STD);
          err=get(1,strlen(txt_prog[STD]),pficher,LSTD,1,1,1);
              floatnum=arflot(pficher);
          if (floatnum<0 || floatnum >9999 || *pficher==' ')
        salir=0;
          else
        salir=1;
          }

}




busca_pos_puntos()
{
int i,j;
int salir;
int salir1;
int ref;
int yaesta;
int posicion=100;
i=0;
salir1=0;


while (i<20 && salir1==0)
{
 j=0;
 salir=0;
 yaesta=0;
 while (j<100 && salir==0)
 {
  apunta(j,POS_GRABADA);
  if (*pficher=='*' )
  {
  apunta(j,TIPO);
  if (*pficher=='6')
  {
    apunta(j,VARIOS_STD);
    ref=arint(pficher);
    if (ref==i)
    {
     salir=1;
     yaesta=1;
    }
  }
  }
  j++;
 }
 if (yaesta==0)
  {
   salir1=1;
   posicion=i;
  }
  i++;
}
return(posicion);
}



pide_puntos(referencia,mod,todos)
int referencia;
int mod;
int todos;
{
 int ji;
 int numero;
 int err;
 char ctexto[25];
              apuntastd(referencia,0,0,0);
              numero=arint(pficherstd);

              for (ji=0;ji<numero;ji++)
          {
                   say(2,9,textos[64+idioma_textos]);
           intar(ctexto,ji+1);
               say(2,15,ctexto);
                   borrarl(3,0,19);
                   borrarl(4,0,19);
                   if (todos==0)
                   {
                          say(3,0,"ABS.:");
                   }
                    say(4,0,"CONC.:");
                    if (todos==0)
                     {
                          apuntastd(referencia,1,PX,ji);
                          err=get(3,6,pficherstd,9,1,1,mod);
                         }

                    apuntastd(referencia,1,PY,ji) ;
                    err=get(4,6,pficherstd,9,1,1,mod);
               }


    borrarl(2,9,19);
        borrarl(3,0,19);
    borrarl(4,0,19);
 }



borrar_tecnica(pul)
int pul;
{
char *pt;
int i;

pt=&ficher[0];
pt=pt+(pul*long_ficha);
i=0;
while (i<long_ficha)
 {
  *pt=0x0;
   pt++;
   i++;
 }
}

  borrar_tecnicas()
  {
    char text[25];
    double j;
    int h;
    int i;
    char tec1[3];
    char tec2[3];
    int pul1=0;
    int pul2=0;
    int err;
    int t;

       borrar();

      say(1,0,textos[45+idioma_textos]);
      err=get(1,strlen(textos[45+idioma_textos]),tec1,3,1,1,0);
       if (err==novalid)
     return;

       pul1=arflot(tec1);
       if (pul1<0 || pul1>total_tecnicas)
         return;

      say(2,0,textos[46+idioma_textos]);
      err=get(2,strlen(textos[46+idioma_textos]),tec2,3,1,1,0);
       if (err==novalid)
        return;

      pul2=arflot(tec2);

       if (pul2<0 || pul2>total_tecnicas)
         return;

       if (pul1>pul2)
        return;



       for (i=pul1;i<=pul2;i++)
      {
        borrar_tecnica(i);
        t=mira_tec();
        if (t==stop)
           i=pul2+2;
      }


 }



