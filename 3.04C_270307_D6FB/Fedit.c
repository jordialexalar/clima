       /*MODULO   FEDIT.C        */


       /*Contiene funciones para edicion de t‚cnicas*/

#include <io51.h>
#include <stdio.h>
#include <fdefines.h>
#include <fexterns.h>






  editar(quehago)
  int quehago;
  {
       double hi=0.00;
       int pul=100;
       int err=0;
       int tec;
       char ent[7];
       ent[0]='\0';
       borrar();


      say(1,0,textos[2+idioma_textos]);
      err=get(1,strlen(textos[2+idioma_textos]),ent,2,1,1,0);
       if (err==novalid)
     return;

    pul=arflot(ent);

    if (pul<total_tecnicas && ent[0]!=' ' && ent[0]!='\0')
       { 
          borrar();
         if (quehago==0)
          {
            if (((pul>=desde_tecnica && pul<=hasta_tecnica) && cod_access()==1) || (pul<desde_tecnica || pul>hasta_tecnica))
              {
                apunta(pul,POS_GRABADA);
                if (*pficher=='*')
                 {
                  say(1,1,textos[56+idioma_textos]);
                  say(2,1,textos[57+idioma_textos]);
                  tec=keyboard(0);
                  if (tec==1)
                    edit(pul);
                  }
                 else
                  {
                     edit(pul);
                  }
              }
         }
        else
           {
             if (grabada(pul) && quehago==1)
               {
               if (((pul>=desde_tecnica && pul<=hasta_tecnica) && cod_access()==1) || (pul<desde_tecnica || pul>hasta_tecnica))
                 {
                  camb_fact(pul);
                 } 
               } 
             if (grabada(pul) && quehago==2 && contrafact(pul)==0)
               {
               if (((pul>=desde_tecnica && pul<=hasta_tecnica) && cod_access()==1) || (pul<desde_tecnica || pul>hasta_tecnica))
                 {
                   camb_estan(pul);
                 }  
               } 
           }
       }
  }




grabada(pul)
int pul;
{
apunta(pul,POS_GRABADA);
if (*pficher=='*')
  return(1);
return(0);
}




contrafact(pul)
int pul;
{
apunta(pul,CONTRA_FACTOR);
if (*pficher=='1')
  return(1);
return(0);
}



apunta(ficha,registro)
int ficha;
int registro;
{
pficher=&ficher[0];
pficher=pficher+(ficha*long_ficha)+offset[registro];
}



apuntastd(ficha,registro,eje,pont)
int ficha;
int registro;
int eje;
int pont;
{
  pficherstd=&ficherstd[0];
  pficherstd=pficherstd+(ficha*long_ficha_std)+(registro*3)+(eje*100)+(pont*10);
}



escribe(ficha,registro,que)
int ficha;
int registro;
char que[];
{
char *pt;
pt=&ficher[0];
pt=pt+(ficha*long_ficha)+offset[registro];
strcpy(pt,que);
}

lee_parametro(pul,que)
int pul,que;
{
    int y;
    apunta(pul,que);
    y=arint(pficher);
    return(y);
}

double lee_parametro_double(pul,que)
{
    double y;
    apunta(pul,que);
    y=arflot(pficher);
    return(y);
}



cod_access()
{ 
  int salir;
  double h;
  salir=0;
 if (lee_bit(2,5)!=0)  
   return(1);
   
  while (salir==0)
    {
      getstr(3,1,text,6,1,1,0,textos[190+idioma_textos],BORRAR);
      if (lastkey==stop)
       salir=100;
      if (lastkey==cr)
        {
          if (strcmp(password,text)==0)
            salir=1; 
        }   
    }           
   if (salir==1)
     return(1);
  return(0);
}
