#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

int main()
{
    system("color F0");
    char sair;
    do{
        const int tam=3;
        int e=0,er,n,i;
        char escolha[tam],move,c,codigo[101];
        do{
            system("cls");
            for(er=0;er<tam;er++)
                escolha[er]=' ';
            escolha[e]=254;
            printf("Te direi os c%cdigos da tabela ASCII!\nEscolha uma das op%c%ces:\n",-94,-121,-28);
            printf("%c Imprimir tabela\n%c Digitar um c%cdigo para descobrir o s%cmbolo\n%c Digitar um s%cmbolo para descobrir o c%cdigo\n",escolha[0],escolha[1],-94,-95,escolha[2],-95,-94);
            do{
                do{
                    move=getch();
                }while(move!=-32 && move!='w' && move!='s' && move!=13 && move!=27 && (move<'1' && move>'3'));
                if(move==-32)
                    move=getch();
            }while(move!='H' && move!='P' && move!='w' && move!='s' && move!=13 && move!=27 && (move<'1' && move>'3'));
            if(move>='1' && move<='3')
                e=move-49;
            switch(move){
                case 'w':
                case 'H':if(e>0) e--;else e=tam-1;break;
                case 's':
                case 'P':if(e<tam-1) e++;else e=0;break;
                case 27:return 0;break;
            }
        }while(move!=13);
        system("cls");
        if(e==0){
            printf("Tabela ASCII\n\n0 = NULL\n1 = Start of Header\n2 = Start of Text\n3 = End of Text\n4 = End of Transmission\n");
            printf("5 = Enquiry\n6 = Acknowledgement\n7 = Bell\n8 = Backspace\n9 = Horizontal Tab (Tab)\n10 = Line Feed\n");
            printf("11 = Vertical Tab\n12 = Form Feed\n13 = Carriage Return (Enter)\n14 = Shift Out\n15 = Shift In\n");
            printf("16 = Data Link Escape\n17 = Device Control 1\n18 = Device Control 2\n19 = Device Control 3\n20 = Device Control 4\n");
            printf("21 = Negative Acknowledgement\n22 = Synchronous Idle\n23 = End of Transmission Block\n24 = Cancel\n");
            printf("25 = End of Medium\n26 = Substitute\n27 = Escape (Esc)\n28 = File Separator\n29 = Group Separator\n");
            printf("30 = Record Separator\n31 = Unit Separator\n32 = Space\n");
            for (n=33,c=n;n<127;n++,c=n)
                    printf("%d = %c\n",n,c);
            printf("127 = Delete (Del)\n");
            for (n=128,c=n;n<255;n++,c=n)
                    printf("%d = %c\n",n,c);
             printf("255 = Non-breaking Space\n");
             printf("Aperte enter ou backspace para voltar ou esc para sair!");
             do{
                sair=getch();
             }while(sair!=13 && sair!=8 && sair!=27);
             if(sair==13)
                sair=8;
        }
        if(e==1){
            do{
                system("cls");
                printf("Digite o c%cdigo: ",-94);
                i=0;
                do{
                    codigo[i]=getch();
                    if((codigo[i]>='0' && codigo[i]<='9')||(codigo[i]=='-' && i==0)){
                        printf("%c",codigo[i]);
                        i++;
                    }
                    if(codigo[i]==8 && i>0){
                        codigo[i]=0;
                        i--;
                        codigo[i]=0;
                        system("cls");
                        printf("Digite o c%cdigo: ",-94);
                        if (codigo[0]!=0)
                            printf("%s",codigo);
                    }
                    if(codigo[i]==27)
                        return 0;
                    if(codigo[i]==8){
                        codigo[i]=13;
                        sair=8;
                        e=-1;
                    }
                }while(codigo[i]!=13);
                codigo[i]=0;
                if(e>=0){
                    n=atoi(codigo);
                    printf("\n");
                    switch (n){
                        case 0:printf("0 = NULL\n");break;
                        case 1:printf("1 = Start of Header\n");break;
                        case 2:printf("2 = Start of Text\n");break;
                        case 3:printf("3 = End of Text\n");break;
                        case 4:printf("4 = End of Transmission\n");break;
                        case 5:printf("5 = Enquiry\n");break;
                        case 6:printf("6 = Acknowledgement\n");break;
                        case 7:printf("7 = Bell\n");break;
                        case 8:printf("8 = Backspace\n");break;
                        case 9:printf("9 = Horizontal Tab (Tab)\n");break;
                        case 10:printf("10 = Line Feed\n");break;
                        case 11:printf("11 = Vertical Tab\n");break;
                        case 12:printf("12 = Form Feed\n");break;
                        case 13:printf("13 = Carriage Return (Enter)\n");break;
                        case 14:printf("14 = Shift Out\n");break;
                        case 15:printf("15 = Shift In\n");break;
                        case 16:printf("16 = Data Link Escape\n");break;
                        case 17:printf("17 = Device Control 1\n");break;
                        case 18:printf("18 = Device Control 2\n");break;
                        case 19:printf("19 = Device Control 3\n");break;
                        case 20:printf("20 = Device Control 4\n");break;
                        case 21:printf("21 = Negative Acknowledgement\n");break;
                        case 22:printf("22 = Synchronous Idle\n");break;
                        case 23:printf("23 = End of Transmission Block\n");break;
                        case 24:printf("24 = Cancel\n");break;
                        case 25:printf("25 = End of Medium\n");break;
                        case 26:printf("26 = Substitute\n");break;
                        case 27:printf("27 = Escape (Esc)\n");break;
                        case 28:printf("28 = File Separator\n");break;
                        case 29:printf("29 = Group Separator\n");break;
                        case 30:printf("30 = Record Separator\n");break;
                        case 31:printf("31 = Unit Separator\n");break;
                        case 32:printf("32 = Space\n");break;
                        case 127:printf("127 = Delete (Del)\n");break;
                        case 255:printf("255 = Non-breaking Space\n");break;
                    }
                    if ((n>32 || n<0)&& n!=127 && n!=255){
                        c=n;
                        printf("%d = %c\n",n,c);
                    }
                    printf("Aperte enter para recome%car, backspace para voltar ou esc para sair!",-121);
                    do{
                        sair=getch();
                    }while(sair!=13 && sair!=8 && sair!=27);
                }
            }while(sair==13);
        }
        if(e==2){
            do{
                system("cls");
                printf("Digite o s%cmbolo: ",-95);
                c=getc(stdin);
                fflush(stdin);
                printf("%c = %d\n",c,c,c);
                printf("Aperte enter para recome%car, backspace para voltar ou esc para sair!",-121);
                do {
                    sair=getch();
                }while(sair!=13 && sair!=8 && sair!=27);
            }while(sair==13);
        }
    }while(sair==8);
}
