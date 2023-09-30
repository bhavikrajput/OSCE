#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int lc=0;
    FILE *fp;
    char filename[10];
    char code[80];
    char lbl[10];
    char opc[10];
    char reg[10];
    char oper[10];
    int ntok;

    printf("\n Enter the name of the file:");
    scanf("%s",filename);

    fp=fopen(filename,"r");

    if(fp==NULL)
    {
        printf("\n File not found");
        exit(0);
    }

    else
    {

        while(!feof(fp))
        {
            fgets(code,80,fp);
            ntok=sscanf(code,"%s %s %s %s",lbl,opc,reg,oper);


            switch(ntok)
            {
                case 1: if(strcmp(lbl,"STOP")==0)
                {
                    printf("\n Line counter:- %d",lc);
                    printf("\t Token-1: %s",lbl);
                    lc++;
                }

                else
                {
                    printf("\n \t Token-1: %s",lbl);

                }

                break;

                case 2: if(strcmp(lbl,"START")==0)
                {
                    lc=atoi(opc);
                    printf("\n \tToken-1:%s Token-2: %s",lbl,opc);
                }

                else //Read A or Halt Stop
                {
                    printf("\n Line counter: %d",lc);
                    printf("\t Token-1: %s Token-2: %s",lbl,opc);
                    lc++;
                }

                break;

                case 3: //Mover Areg,B or Loop Print A or A DS 1

                printf("\n Line counter: %d", lc);
                printf("\t Token-1:%s Token-2:%s Token-3:%s",lbl,opc,reg);
                lc++;

                break;

                case 4: //Loop Mover Areg,B

                printf("\n Line counter:%d",lc);

                printf("\t Token-1:%s Token-2:%s Token-3:%s Token-4:%s",lbl,opc,reg,oper);

                break;
            }

        }


    }
    
    }


