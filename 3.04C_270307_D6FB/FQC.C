

#include <io51.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <fdefines.h>
#include <fexterns.h>

#define NOCONTROL  200

double ds;
double cv;
double mitja;
double v_diana;
int num;
double valors[30];
double lim_sup=0.0;
double lim_inf=0.0;

char *pt_diana;
char *pt_limsup;
char *pt_liminf;
char *pt_datos;
char *pt_fechas;




edit_qc()
{
int po;
int i;
int contr;
int tecnic;
int salir;
int hg;
salir=0;
 for(i=1;i<11;i++)
  {
    if (control[i]!=NOCONTROL)
     {
      if (grabada(control[i])==0)
	control[i]=NOCONTROL;
     }

  }
while (salir==0)
{
borrar();
text[0]=0x0;
getstr(1,0,text,2,1,1,0,textos[184+idioma_textos],BORRAR);
if (lastkey==stop)
 return(0);

if (lastkey==print)
 impr_controls();

if (lastkey==cr)
 {
   tecnic=arint(text);
   if (tecnic>0 && tecnic<total_tecnicas)
    {
      if (grabada(tecnic))
       {
	     salir=1;
	 for(i=1;i<11;i++)
	  {
	    if (control[i]==tecnic)
	     {
	      locate(i);
	      say(2,0,textos[185+idioma_textos]);
	      say(3,0,textos[166+idioma_textos]);
	      po=strlen(textos[166+idioma_textos]);
	      say(3,0+po,pt_diana);
	      inkey(0);
	      borrarstr(2,0,textos[185+idioma_textos]);

	      salir=0;
	      if (lastkey==1)
		{
		   control[i]=NOCONTROL;
		}
	      i=12;

	     }
	  }
       }
      else
       {
	 aviso(1,1,textos[84+idioma_textos]);
       }
     }
  }
 }
  contr=0;
  for(i=1;i<11;i++)
   {
    if (control[i]==NOCONTROL)
      {
       contr=i;
       i=20;
      }
   }
   if (contr>0 && contr<11)
    {
		   control[contr]=tecnic;
		   pedir_datos(contr);
		   if (lastkey==stop)
		     control[contr]=0;
		   else
		     impr_cont(contr);
    }
   else
    {
	aviso(1,1,textos[186+idioma_textos]);
    }

 }



impr_cont(pul)
int pul;
{
int j;
      lineasinforme=0;
      poneninforme(lineasinforme,8,textos[76+idioma_textos]);
      lineasinforme++;
      apunta(control[pul],IDEN);
      j=arint(pficher);
      strcpy(text,codigos[j+pos_ini_cod]);
      locate(pul);
      poneninforme(lineasinforme,1,text);

      intar(text,control[pul]);
      poneninforme(lineasinforme,8,text);

      lineasinforme++;
      intar(text,n_datos[pul]);
      poneninformetxt(lineasinforme,1,textos[77+idioma_textos],text);
      poneninformetxt(lineasinforme,8,textos[166+idioma_textos],pt_diana);
      lineasinforme++;
      poneninformetxt(lineasinforme,1,textos[86+idioma_textos],pt_limsup);
/*      poneninformetxt(lineasinforme,11,textos[87+idioma_textos],pt_liminf); */
      lineasinforme++;
      poneninforme(lineasinforme,0,"--------------------");
      lineasinforme++;
      impinforme(lineasinforme,10,1);


}

impr_controls()
{
int i;
int h;
int j;
lineasinforme=0;
  for(i=1;i<11;i++)
   {
    if (control[i]!=NOCONTROL)
      {
	   intar(text,control[i]);
	   poneninforme(lineasinforme,0,text);
	   strcpy(text,".");
	   poneninforme(lineasinforme,2,text);

	   apunta(control[i],IDEN);
	   j=arint(pficher);
	   strcpy(text,codigos[j+pos_ini_cod]);
	   poneninforme(lineasinforme,6,text);
	   lineasinforme++;
      }

   }

   if (lineasinforme>0)
      impinforme(lineasinforme,10,10);
}


exist_qc(pul)
int pul;
{
 int tec;
 int er=0;
 if (control[pul]>0)
 {
    er=1;
 }
return(er);
}


ver_qc()
{
int pul;
int pul1;
int i;
borrar();
text[0]=0x0;
getstr(1,0,text,2,1,1,0,textos[2+idioma_textos],BORRAR);
if (lastkey==cr)
 {
   pul=arint(text);
   if (pul>0 && pul<total_tecnicas)
    {
      if (grabada(pul))
       {
	 for(i=1;i<11;i++)
	  {
	   if (control[i]==pul)
	    {
	     haz_control(i);
	     i=12;
	    }
	  }
       }
      else
       {
	 aviso(1,1,textos[84+idioma_textos]);
	 return(0);
       }

    }
 }

}


haz_control(pul)
int pul;
{
 int salir=0;
 int i=0;
 int j;
 int decs;
 double val=0;
 num=0;

 decs=lee_parametro(control[pul],DECIMALES);

while (salir==0)
{
     borrar();

       mitja=0.0;
       coge_valors(pul);
       num=n_datos[pul];
       for(i=0;i<num;i++)
	{
	  mitja=mitja+valors[i];
	}
       mitja=mitja/num;
       ds=0.0;
       for(i=0;i<num;i++)
	{
	   val=valors[i]-mitja;
	   val=flotpower(val,2);
	   ds=ds+val;
	}
	ds=ds/(num-1);
	ds=sqrt(ds);
	cv=(ds/mitja)*100.0;

	apunta(control[pul],IDEN);
	j=arint(pficher);
	say(1,0,codigos[j+pos_ini_cod]);
	say_int(1,10,num,textos[77+idioma_textos]);

	say_double(2,0,mitja,decs,textos[82+idioma_textos]);


	say_double(2,10,ds,2,textos[78+idioma_textos]);

	say_double(3,0,cv,2,textos[79+idioma_textos]);
	say_double(3,10,(mitja/v_diana),2,textos[80+idioma_textos]);

       inkey(0);


   if (lastkey==print)
    {
      locate(pul);
      lineasinforme=0;
      poneninforme(lineasinforme,8,textos[76+idioma_textos]);
      lineasinforme++;
      apunta(control[pul],IDEN);
      j=arint(pficher);
      strcpy(text,codigos[j+pos_ini_cod]);
      locate(pul);
      poneninforme(lineasinforme,1,text);
      lineasinforme++;
      intar(text,n_datos[pul]);
      poneninformetxt(lineasinforme,1,textos[77+idioma_textos],text);
      poneninformetxt(lineasinforme,8,textos[166+idioma_textos],pt_diana);
      lineasinforme++;
      poneninformetxt(lineasinforme,1,textos[86+idioma_textos],pt_limsup);
/*      poneninformetxt(lineasinforme,11,textos[87+idioma_textos],pt_liminf); */
      lineasinforme++;
      poneninforme(lineasinforme,0,"--------------------");
      lineasinforme++;
      impinforme(lineasinforme,10,1);

      lineasinforme=0;
      poneninforme(lineasinforme,1,textos[82+idioma_textos]);
      flotar(text,mitja,decs);
      poneninforme(lineasinforme,5,text);
      lineasinforme++;
      poneninforme(lineasinforme,1,textos[78+idioma_textos]);
      flotar(text,ds,2);
      poneninforme(lineasinforme,5,text);
      lineasinforme++;
      poneninforme(lineasinforme,1,textos[79+idioma_textos]);
      flotar(text,cv,2);
      poneninforme(lineasinforme,5,text);
      lineasinforme++;
      poneninforme(lineasinforme,1,textos[80+idioma_textos]);
      flotar(text,(mitja/v_diana),2);
      poneninforme(lineasinforme,1+strlen(textos[80+idioma_textos]),text);
      lineasinforme++;

      impinforme(lineasinforme,0,10);


      lineasinforme=0;
      for(i=0;i<num;i++)
       {
	poneninforme(lineasinforme,1,pt_fechas);
	pt_fechas=pt_fechas+11;
	poneninforme(lineasinforme,13,pt_datos);
	pt_datos=pt_datos+10;
	lineasinforme++;
	if (lineasinforme>=8)
	  {
	   impinforme(lineasinforme,0,0);
	   lineasinforme=0;
	  }
       }
       if (lineasinforme>0)
	{
	   impinforme(lineasinforme,0,0);
	   lineasinforme=0;
	}
      lineasinforme++;

    }


   if (lastkey==stop)
     salir=1;
 }
}




coge_valors(pul)
int pul;
{
 int i;
 locate(pul);
 v_diana=arflot(pt_diana);
 for(i=0;i<n_datos[pul];i++)
  {
    valors[i]=arflot(pt_datos);
    pt_datos=pt_datos+10;
  }
}



env_qc(pul,con)
int pul;
char con[];
{
 int i;
 int j;
 char *po;
 double mt;
 mt=arflot(con);

 for(i=1;i<11;i++)
  {
    if (control[i]==pul)
     {
	coge_lim(i);
	if (mt>lim_sup || mt<lim_inf)
	   return(1);

	 j=0;
	 while (con[j]!=0x0 && j<9)
	 {
	   datos_control[(i*200)+(pos_datos[i]*10)+j]=con[j];
	   j++;
	 }
	   datos_control[(i*200)+(pos_datos[i]*10)+j]=0x0;

	   fechas_control[(i*220)+(pos_datos[i]*11)+0]=dd[0];
	   fechas_control[(i*220)+(pos_datos[i]*11)+1]=dd[1];
	   fechas_control[(i*220)+(pos_datos[i]*11)+2]='/';

	   fechas_control[(i*220)+(pos_datos[i]*11)+3]=mm[0];
	   fechas_control[(i*220)+(pos_datos[i]*11)+4]=mm[1];
	   fechas_control[(i*220)+(pos_datos[i]*11)+5]='/';
	   for (j=0;j<4;j++)
	     fechas_control[(i*220)+(pos_datos[i]*11)+j+6]=yy[j];
	   fechas_control[(i*220)+(pos_datos[i]*11)+10]=0x0;


	   pos_datos[i]++;
	   if (pos_datos[i]>19)
	    pos_datos[i]=0;
	   n_datos[i]++;
	   if (n_datos[i]>20)
	    n_datos[i]=20;


     }

  }
  return(0);
}

locate(pul)
int pul;
{
 pt_diana=&control_diana[0];
 pt_diana=pt_diana+10*pul;
 pt_limsup=&limites_control[0];
 pt_limsup=pt_limsup+pul*20;
 pt_liminf=&limites_control[0];
 pt_liminf=pt_liminf+pul*20+10;
 pt_datos=&datos_control[0];
 pt_datos=pt_datos+pul*200;
 pt_fechas=&fechas_control[0];
 pt_fechas=pt_fechas+pul*220;
}

iniz_control(pul)
int pul;
{
 int i;
   for (i=pul*200;i<(pul*200)+200;i++)
     {
       datos_control[i]=0x0;
     }
   for (i=pul*220;i<(pul*220)+220;i++)
     {
       fechas_control[i]=0x0;
     }
    n_datos[pul]=0;
    pos_datos[pul]=0;
    for(i=0;i<20;i++)
      {
       limites_control[(pul*20)+i]=0x0;
      }
    for(i=0;i<10;i++)
      {
       control_diana[(pul*10)+i]=0x0;
      }
}

pedir_datos(pul)
int pul;
{
 int i;
 char *pt;
 int j;

	 locate(pul);
	 iniz_control(pul);
	 borrar();
	 locate(pul);
	   apunta(control[pul],IDEN);
	   j=arint(pficher);
	   say(1,0,codigos[j+pos_ini_cod]);

		   text[0]=0x0;
		   getstr(2,0,text,7,1,1,0,textos[166+idioma_textos],BORRAR);
		   if (lastkey==cr)
		    {
		      strcpy(pt_diana,text);
		      text[0]=0x0;
		      getstr(2,0,text,7,1,1,0,textos[162+idioma_textos],BORRAR);
		      if (lastkey==cr)
		       {
			 strcpy(pt_limsup,text);
			 strcpy(pt_liminf,text);

		       }
		     }

}

coge_lim(pul)
int pul;
{
 int i;
 char *pt;
     pt_diana=&control_diana[0];
     pt_diana=pt_diana+10*pul;

    pt=&limites_control[0];
    pt=pt+pul*20;
    lim_sup=arflot(pt)+arflot(pt_diana);
    pt=&limites_control[0];
    pt=pt+(pul*20)+10;
    lim_inf=arflot(pt_diana)-arflot(pt);
}

