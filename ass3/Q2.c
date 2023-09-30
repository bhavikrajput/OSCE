#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int mem[1000];
int reg[4];
int PC;
int last;


void Load()
{
    char filename[30];

    printf("\n Enter the name of the file");
    scanf("%s",filename);

    FILE *fp=fopen(filename,"r");

    int address;
    int t;

    int i;

    while(!feof(fp))
    {
        fscanf(fp,"%d %d",&address,&t);

        if(address!=-1)
        last=address;

        if(address==-1)
        PC=t;
    }


    rewind(fp);

    for(i=PC;i<=last;i++)
    {
        fscanf(fp,"%d %d",&address,&t);

        mem[i]=t;
        
    }

}


void Run()
{

    printf("\n The contents loaded in memory are:-");
    int i;

    for(i=PC;i<=last;i++)
    {
        printf("\n %d",mem[i]);
    }

}


void Execute(int x)
{
    int opc;
    int reg1;
    int target;
    int command;
    int i=PC;
     int temp;

    while(1)
    {

        command=mem[i];

        target=command%1000;
        opc=(command/1000)/10;
        reg1=(command/1000)%10;

        printf("\n Areg:%d",reg[reg1-1]);

        switch(opc)
        {
            case 0: exit(0);
            break;

            case 1: reg[reg1-1]=reg[reg1-1]+mem[target];
            break;

            case 9: printf("\n Enter the number:");
            scanf("%d",&mem[target]);
            break;

            case 10:printf("\n The output is %d",mem[target]);
            break;

            case 11:
            temp=mem[target];
            mem[target]=reg[reg1-1];
            reg[reg1-1]=temp;
            break;

            case 12:reg[reg1-1]=reg[reg1-1]+1;
            break;

            case 13: reg[reg1-1]=reg[reg1-1]-1;
            break;

            case 14: mem[target]=mem[target]+1;
            break;

            case 15:mem[target]=mem[target]-1;
            break;

            case 16:mem[target]=mem[target]+reg[reg1- 1];
            break;

            case 17:mem[target]=mem[target]-reg[reg1-1];
            break;

            case 18: mem[target]=mem[target]*reg[reg1-1];
            break;

            case 19: mem[target]=mem[target]/reg[reg1-1];
            break;
            
            case 20: printf("\n The output is %d",reg[reg1-1]);
            break;

            case 21: printf("\n Enter the value:");
            scanf("%d",&reg[reg1-1]);
            break;

            case 22: reg[reg1-1]=0;
            break;

            case 23: reg[reg1-1]=1;
            break;
        }

        i++;
            

        }

        exit(0);
        


    }


int main()
{
    Load();
    Run();
    Execute(1);

}
