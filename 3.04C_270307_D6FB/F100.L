################################################################################
#                                                                              #
#      Micro Series Universal Linker V4.24/DOS         28/Apr/93  04:28:33     #
#                                                                              #
#           Target CPU    =  8051                                              #
#           List file     =  f100.l                                            #
#           Output file 1 =  f100.eje                                          #
#           Output format =  aomf8051                                          #
#           Command line  =  -f lnk8051 (f100 fproces fproces1 ftecl fget      #
#                            fedit fedit1 fedit2 finiz flcd fstr finter        #
#                            finter1 finter2 finter3 finter4 fabs fprint fcom  #
#                            ftest -c8051 -Faomf8051 -D_R=0                    #
#                            -Z(BIT)C_ARGB,BITVARS=0                           #
#                            -Z(DATA)C_ARGD,D_UDATA,D_IDATA=8                  #
#                            -Z(IDATA)C_ARGI,I_UDATA,I_IDATA,CSTACK            #
#                            -Z(XDATA)C_ARGX+400=500                           #
#                            -Z(XDATA)X_UDATA,X_IDATA,ECSTR,RF_XDATA=1500      #
#                            -Z(XDATA)NO_INIT=6000                             #
#                            -Z(CODE)INTVEC,RCODE,D_CDATA,I_CDATA,X_CDATA,     #
#                            C_ICALL,C_RECFN,CSTR,CCSTR,CODE,CONST=0           #
#                            c:\icc1\cl8051l -o f100.eje -l f100.l -a)         #
#                                                                              #
#                                               (c) Copyright IAR Systems 1990 #
################################################################################

