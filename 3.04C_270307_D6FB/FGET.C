


      /*MODULO FGET.C           */


       /*Contiene funciones relacionadas con la visualizacion por el display*/




#include <io51.h>
#include <math.h>

#include <fdefines.h>
#include <fexterns.h>

 say(lan,pos,cha)
     int lan,pos;
     char cha[];
       { unsigned char posi;
	 unsigned char j;
	 int i=0;
	 disp_say=1;
	 switch(lan)
	 {
	 case 1:
	    posi=0x80;
	    break;
	 case 2:
	    posi=0xc0;
            break;

	 case 3:
	    posi=0x94;
            break;

	 case 4:
	    posi=0xd4;
            break;

	 default:
	    posi=0x80;
	    break;
	}
	posi=posi+(unsigned char) pos;
	i=0;
	j=0;

	teclado=off;
	  w_cmd(posi+j);
	  w_cmd(0x06);
	 while (cha[i]!='\0')
	 {
/*	  w_cmd(posi+j);*/
	  w_data(cha[i]);
	  j++;
	  i++;
	 }
	disp_say=0;
	teclado=on;
      }






 get(lin,pos,stri,lon,tipo,enter,update)
     int lin,pos;
     unsigned char stri[];
     int lon,tipo,enter,update;
       {
	 int error=0;
	 int i=0;
	 int hk;
	 int pul=0;
	 int primera_tecla=0;


	 say(lin,pos,"(");
	 say(lin,pos+lon+1,")");
	 pos=pos+1;

	 if (update==1)
	   say(lin,pos,stri);

	lon=lon-1;
	i=0;
	error=0;
	if (stri[i] == ' ')
	   say(lin,pos+i,"_");

	 while (pul!=stop && pul!=cr && pul!=print && !(pul==wash && menu_prin==1))
	 {
	    pul=100;

	    if (i<lon && stri[i] ==' ')
	     {
	       say(lin,pos+i,"_");
	     }

	   pul=inkey(0);
	   if (pul==1000)
	     pul=cr;
	    if (primera_tecla==0 && update==1 && pul!=stop && pul!=cr && pul!=print && !(pul==wash && menu_prin==1))
	      {
		primera_tecla=1;
                 for(hk=0;hk<=lon;hk++)
		  {
     	           say(lin,pos+hk," ");
		  }
	      }


	    switch(pul)
	    {


	      case 10:
		 if (menu_prin==1)
		   error=5;
		 else
		 {
		  if (i>0)
		   {
		    stri[i]='.';
		    stri[i+1]='\0';
		    say(lin,pos+i,".");
		    if (i<lon)
		      i++;
		   }
		 }
		 break;

	      case cr:
		 error=1;
		 break;

              case print:
		 error=3;
                 break;

	      case cl:
        	 for(hk=0;hk<=i;hk++)
		  {stri[hk]=' ';
		  }
		   stri[hk]='\0';
		  say(lin,pos,stri);
                 i=0;
                 break;

	      case stop:
		 error=2;
		 break;

	      default:
		  if (pul>=0 && pul <=9)
                   { stri[i]=(unsigned char) pul+48;
		     stri[i+1]='\0';
		     say(lin,pos,stri);
		     if (i<lon)
		       i++;
		    }
		    break;
	    }
	 }
	return(error);
      }


 getstr(lin,pos,stri,lon,tipo,enter,update,txt,bor)
     int lin,pos;
     unsigned char stri[];
     int lon,tipo,enter,update;
     char txt[];
     int bor;
     {
       int blancos;
       int err;
       int po;
       po=pos;
       blancos=lon+2+strlen(txt);
       say(lin,pos,txt);
       pos=pos+strlen(txt);
       err=get(lin,pos,stri,lon,tipo,enter,update);
       if (bor==BORRAR)
	  borrarl(lin,po,blancos);

       return(err);
     }



 say_int(lan,pos,num,cha)
     int lan,pos;
     int num;
     char cha[];
  {
   char t[25];
   intar(t,num);
   say(lan,pos,cha);
   say(lan,pos+strlen(cha),t);
  }

 say_double(lan,pos,num,decims,cha)
  int lan,pos;
  double num;
  int decims;
  char cha[];
  {
   char t[25];
   flotar(t,num,decims);
   say(lan,pos,cha);
   say(lan,pos+strlen(cha),t);
  }



say_bcd(lan,pos,num)
  int lan,pos;
  unsigned char num;
  {
   char t[25];
   int num1;
   num1=num & 0x0f;
   intar(t,num1 );
   say(lan,pos+1,t);
   num=num>>4;
   num1=num & 0x0f;
   intar(t,num1 );
   say(lan,pos,t);
  }



 borrarstr(lan,pos,cha)
     int lan,pos;
     char cha[];
       {
       int n,i;
       char tx[45];
       n=strlen(cha);
       for(i=0;i<n;i++)
	{
	 tx[i]=0x20;
	}
       tx[i]=0x00;
       say(lan,pos,tx);
       }


