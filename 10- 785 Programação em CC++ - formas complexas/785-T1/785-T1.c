#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

/*
Tarefa 01
Pretende-se  criar um programaem  C  que  fa�a  a  gest�o de uma fila de  espera. Para  o efeito vamoster um array com 10
elementosdo tipo inteiro.
Notas:
Para  realizar  a  marca��o  �  solicitado  ao  utilizador  o  n�  do  utente  (entre  1  e  999)  e colocado na 1� posi��o livre (iguala zero).
A marca��o de urg�ncia colocao utente na posi��oque o utilizador indicar.
A elimina��o retirada lista o n�mero do utente.
Utilize fun��es.
O registo das marca��es deve estar sempre vis�vel e passa a ter as seguintes op��es:
Crie um menu com as seguintes op��es:
-Realizar Marca��o.
-Marca��o de Urg�ncia.
-Eliminar Marca��o.
-Terminar o programa.
*/
  main(){
	setlocale(LC_ALL,"Portuguese");
	int vetor[10]={0,0,0,0,0,0,0,0,0,0};
	int opcao=9;
	do{
		system("cls");
		printf("\nCl�nica Quebra-Ossos\n");
		printf("\nRegisto de Marca��es\n\n");
		for(int i= 0; i< 10; i++){
            printf("%i\t",i);
        }
        printf("\n");
		for(int i = 0; i< 10; i++){
            printf("%i\t",vetor[i]);
        }
		printf("\n----------------------------\n");
		printf("     Menu\n");
		printf("----------------------------\n");
		printf("\n1 �Realizar Marca��o.");
		printf("\n2 �Marca��o de Urg�ncia.");
		printf("\n3 �Eliminar Marca��o.");
		printf("\n9 -Terminar o programa.");
		printf("\n----------------------------\n");
		printf("\n\nDigite a sua op��o:");
		scanf("%i",&opcao);
		switch(opcao){
			case 1:
				RealizaMarcacao(vetor);
				break;
			case 2:
				MarcacaoUrgencia(vetor);
				break;
			case 3:
				EliminarMarcacao(vetor);
				break;
            case 9:
				printf("\nFim do programa.");
				break;
			default:
				printf("\nOp��o inv�lida.");
				sleep(2);
		}
	}while(opcao!=9);
}
// 1 - REALIZAR MARCA��O
void RealizaMarcacao(int v[]){
    printf("*** REALIZAR MARCA��O ***\n");
    int livre= 0;
	for(int i= 0; i < 10; i++){
        if (v[i] ==0){
            livre =1;
        }
        if(livre ==1){
            int utente= 0;
            int valido= 0;
            do{
                printf("O n� do utente situam-se entre 1 e 999.\n");
                printf("Digite o n� do utente\n");
                scanf("%i",&utente);
                if(utente >= 1 && utente <=999){
                    valido =1;
                    int existe= 0;
                    for(int i= 0; i< 10; i++){
                        if(v[i] ==utente){
                            existe=1;
                        }
                    }
                    if(existe ==1){
                        printf("Utente j� possui marca��o!\n");
                    }
                    else{
                        v[indice] = utente;
                    }
                }
                else{
                    printf("N� do utente inv�lido \n");
                }
            }while(valido!= 1);
            break;
        }
	}
	if (livre ==0){
        printf("Todos os hor�rios est�o ocupados!\n");
    }
	system("pause");
}
// 2 - MARCA��O DE URG�NCIA
void MarcacaoUrgencia(int v[]){
	for(int indice = 0; indice < 10; indice++){
        int utente = 0;
        int valido = 0;
        do{
            printf("O n� do utente situam-se entre 1 e 999.\n");
            printf("Digite o n� do utente\n");
            scanf("%i",&utente);
            if(utente >= 1 && utente <= 999){
                int existe = 0;
                for(int i = 0; i < 10; i++){
                    if(v[i] == utente){
                        existe = 1;
                    }
                }
                if(existe== 1){
                    printf("Utente j� possui marca��o!\n");
                    valido = 1;
                }
                else{
                    int agenda= 999;
                    printf("O n� da agenda situam-se entre 0 e 9.\n");
                    printf("Digite o n� da agenda\n");
                    scanf("%i",&agenda);
                    if(agenda >= 0 && agenda <= 9){
                        valido = 1;
                        v[agenda] = utente;
                    }
                    else{
                        printf("N� da agenda inv�lido \n");
                    }
                }
            }
            else{
                printf("N� do utente inv�lido \n");
            }
        }while(valido!= 1);
        break;
	}
	system("pause");
}
// 3 - ELIMINAR MARCA��O
void EliminarMarcacao(int v[]){
    int utente;
    int valido= 0;
    printf("*** ELIMINAR MARCA��O ***\n");
    do{
        printf("O n� do utente situam-se entre 1 e 999.\n");
        printf("Digite o n� do utente\n");
        scanf("%i",&utente);
        if(utente >= 1 && utente <= 999){
            int existe = 0;
            for(int i = 0; i < 10; i++){
                if(v[i] == utente){
                    v[i] =0;
                    printf("Marca��o Elimanda!\n");
                    valido=1;
                    existe=1;
                    break;
                }
            }
            if(existe== 0){
                printf("Utente n�o possui marca��o!\n\n");
                valido = 1;
                break;
            }
        }
        else{
            printf("N� do utente inv�lido \n");
        }
    }while(valido!= 1);
	system("pause");
}
