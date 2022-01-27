#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct compromisso
{
    int dia, mes, ano;
    int hora, min;
    int iddata, idhora;
    char comp[80];
    struct compromisso *prox;
} Nodo;

int menu ()                                                                         //FUNÇÃO MENU
{
    char opc;

    printf("\t\t\tAGENDA DIGITAL DE COMPROMISSOS v1.0\n\n\n");
    printf("Selecione uma opcao:\n\n");
    printf("[I] - Inserir um compromisso na agenda\n");
    printf("[R] - Remover um compromisso da agenda\n");
    printf("[V] - Vizualizar agenda\n");
    printf("[C] - Consultar compromissos da agenda\n");
    printf("[B] - Buscar compromisso(s) que contem a palavra indicada\n");
    printf("[S] - Salvar em disco os compromissos da agenda\n");
    printf("[L] - Ler do disco os compromissos da agenda\n");
    printf("[F] - Terminar a execucao do programa\n");
    printf("\n\nOpcao:");

    scanf("%c", &opc);
    fflush(stdin);                                                                  //"FFLUSH" PARA LIMPAR ENTRADAS DO TECLADO
    opc = toupper(opc);                                                             //"TOUPPER" PARA GARANTIR A ENTRADA DE CARACTER MAIUSCULO NAS OPÇÕES.

    if(opc == 'I')
        return 0;
    if(opc == 'R')
        return 1;
    if(opc == 'C')
        return 2;
    if(opc == 'B')
        return 3;
    if(opc == 'S')
        return 4;
    if(opc == 'L')
        return 5;
    if(opc == 'F')
        return 6;
    if(opc == 'V')
    	return 9;
    else
        return 7;
}

void inicializa_lista(Nodo **N)                                                     //INICIALIZA LISTA*
{
 *N = NULL;
}

Nodo * Cria_Nodo()                                                                  //ALOCA MEMÓRIA PARA O NODO*
{
     Nodo *p;
     p = (Nodo *) malloc(sizeof(Nodo));
     if(!p)
     {
         printf("Problema de alocação");
         exit(0);
     }
     return p;
}

int consulta(Nodo *N)																//FUNÇÃO PARA CONSULTA DE DADOS POR DATA
{
	int dia, mes, ano, databusc, cont=0;
	Nodo *aux;
	
	system("cls");
 	printf("\t\t\t[C] - Consulta de compromissos agendados\n\n\n");
 	
 	printf("Entre com a data(dia/mes/ano)\n\n");
	
	fflush(stdin);
	printf("Dia: "); scanf("%d", &dia);
	printf("Mes: "); scanf("%d", &mes);
	printf("Ano: "); scanf("%d", &ano);
	
	databusc=((ano*10000)+(mes*100)+(dia));
	fflush(stdin);
	
	printf("\nCompromissos agendados para o dia [%d/%d/%d]:\n\n", dia, mes, ano);
 	
 	aux=(N);	

	if((N) == NULL)
 		printf("A lista esta vazia!!\n\n");
 	else
 	{
    	for(aux = N; aux != NULL; aux = aux->prox)
    	{
			if (databusc == aux->iddata)											//COMPARAÇÃO PELO IDDATA
			{
				cont++;
				printf("Data: %d/%d/%d", aux->dia, aux->mes, aux->ano);
	    		printf("\nHora: %d:%dh", aux->hora, aux->min);
	    		printf("\nCompromisso: %s\n\n", aux->comp);
			}
    	}
 	}
 	if(cont == 0){printf("Nao existe compromissos para esta data\n\n"); }
	system("pause");		
	return 8; 	
}

int imprime_lista(Nodo *N)                                                          //IMPRESSÃO DA LISTA* VIZUALIZAR AGENDA
{
 Nodo *aux;

 system("cls");
 printf("\t\t\t[V] - Vizualizar agenda\n\n\n");

 if(N == NULL)
 printf("\n A lista esta vazia!!\n\n");
 else
 {
    for(aux = N; aux != NULL; aux = aux->prox)
    {
    printf("Data: %d/%d/%d", aux->dia, aux->mes, aux->ano);
    printf("\nHora: %d:%dh", aux->hora, aux->min);
    printf("\nCompromisso: %s\n\n", aux->comp);
    }
 }
 system("pause");
 return 8;
}

void dados_compromisso(Nodo *N)                                                     //FUNÇÃO DE ENTRADA DOS DADOS
{
	
	
    Nodo dados;
    int opc=0;
    char confirmar;

    do
    {
    system("cls");
    confirma_data(&dados);
    fflush(stdin);

    printf("\t\t\tDigite os demais dados do compromisso:\n\n\n");
    printf("Hora: "); scanf("%d", &dados.hora);
    printf("\nMinutos: "); scanf("%d", &dados.min);
    fflush(stdin);
    printf("\nCompromisso: "); fgets(dados.comp,80,stdin); strupr(dados.comp);

    system("cls");
    printf("\t\t\tConfirmar compromisso(S/N)?\n\n\n");
    printf("Data: %d/%d/%d", dados.dia, dados.mes, dados.ano);
    printf("\nHora: %d:%dh", dados.hora, dados.min);
    printf("\nCompromisso: %s", dados.comp);
    fflush(stdin);
    printf("\n\nConfirma: "); scanf("%c", &confirmar);
    fflush(stdin);
    confirmar=toupper(confirmar);

    if(confirmar == 'S')
    {
        opc = 0;
        N->iddata = ((dados.ano*10000)+(dados.mes*100)+(dados.dia));
        N->idhora = ((dados.hora*100)+(dados.min));
        N->dia = dados.dia;
        N->mes = dados.mes;
        N->ano = dados.ano;
        N->hora = dados.hora;
        N->min = dados.min;
        strcpy(N->comp,dados.comp);
    }
    else
    {
        opc = 1;
        system("cls");
        printf("\t\t Insercao Cancelada\n\n");
        system("pause");
	}
    }while(opc == 1);
}

int confirma_data(Nodo *d)                                                          //FUNÇÃO PARA VALIDAÇÃO DA DATA
{
	int dia, mes, ano, result=1;
	fflush(stdin);

	do{
		printf("\t\t\tDigite a data do compromisso (dia/mes/ano):\n\n\n");
		printf("Dia: ");
		scanf("%d", &dia);
		printf("\nMes: ");
		scanf("%d", &mes);
		printf("\nAno: ");
		scanf("%d", &ano);

		printf("\n\n%d/%d/%d\n\n", dia, mes, ano);

		if ( (dia >= 1 && dia <= 31) && (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) )
			result=0;
		if ( (dia >= 1 && dia <= 30) && (mes == 4 || mes == 6 || mes == 9 || mes == 11) )
			result=0;
		if (mes == 2){
			if ( ((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0 ) && (dia >= 1 && dia<=29)){
			result=0;
			}
			else if (dia >= 1 && dia <= 28){
			result=0;
			}
			else{
			result=1;
			}
		}

		if (result == 0){
            d->dia = dia;
            d->mes = mes;
            d->ano = ano;
            system("pause");
			system("cls");
		}
		else{
			printf("\n\nData Invalida\n\n");
			system("pause");
			system("cls");
		}
	}while(result == 1);
}

int insere_compromisso(Nodo **N, Nodo dado)											//FUNÇÃO PARA INSERÇÃO ORDENADA DOS DADOS NA LISTA
{
	Nodo *novo, *aux1, *aux2;
			
	novo=Cria_Nodo();
			
	novo->ano = dado.ano; strcpy(novo->comp,dado.comp); novo->dia = dado.dia; 
	novo->hora = dado.hora; novo->iddata = dado.iddata; novo->mes = dado.mes;
	novo->min = dado.min; novo->prox = dado.prox; novo->idhora = dado.idhora;
					
	if(*N == NULL)																	//ATUALIZA PONTEIRO EXTERNO - PRIMEIRO ITEM DA LISTA
	{		
		novo->prox = NULL;
		*N=novo;
	}	
	else
	{
		if( (novo->iddata < (*N)->iddata) || ((novo->iddata == (*N)->iddata) && (novo->idhora < (*N)->idhora)) )  //COMPARA COM PRIMEIRO ITEM DA LISTA
			insere_inicio_lista(N, dado);
		else
		{
			for(aux1=(*N); aux1->prox != NULL; aux1=aux1->prox)													//COMPARA AUX COM TODOS ELEMENTO ATE PROX NULL
			{
				aux2=aux1->prox;
				if( ((novo->iddata > aux1->iddata) && (novo->iddata < aux2->iddata))
				|| ( ((novo->iddata == aux1->iddata) && (novo->iddata <= aux2->iddata)) && ((novo->idhora >= aux1->idhora) && (novo->idhora <= aux2->idhora)))
				|| ( (novo->iddata == aux1->iddata) && (novo->idhora == aux1->idhora)) )
				{
					aux1->prox = novo;
					novo->prox = aux2;
					break;
				}
			}
			if(aux1->prox == NULL)															//ADIÇÃO DO ULTIMO ELEMENTO
			  insere_fim_lista(N, dado);
		}
	}	
 	return 8;
}

void insere_inicio_lista(Nodo **P, Nodo dado)										//FUNÇÃO PARA INSERIR DADOS NO INICIO DA LISTA*
{
	Nodo *novo;
	novo = Cria_Nodo();
	
	novo->ano = dado.ano; strcpy(novo->comp,dado.comp); novo->dia = dado.dia; 
	novo->hora = dado.hora; novo->iddata = dado.iddata; novo->mes = dado.mes;
	novo->min = dado.min; novo->prox = dado.prox; novo->idhora = dado.idhora;

        novo->prox = (*P);
        (*P) = novo;
}

void insere_fim_lista(Nodo **P, Nodo dado)											//FUNÇÃO PARA INSERIR DADOS NO FIM DA LISTA*
{
	Nodo *novo, *aux;
	novo = Cria_Nodo();
	
	novo->ano = dado.ano; strcpy(novo->comp,dado.comp); novo->dia = dado.dia; 
	novo->hora = dado.hora; novo->iddata = dado.iddata; novo->mes = dado.mes;
	novo->min = dado.min; novo->prox = dado.prox; novo->idhora = dado.idhora;
	
	novo->prox = NULL;
	
	if(*P == NULL)
		(*P)=novo;
	else
	{
		aux=(*P);
		while(aux->prox != NULL)
			aux=aux->prox;
		aux->prox=novo;
	}
	
}

int remover_elemento(Nodo **N)														//FUNÇÃO PARA REMOVER ELEMENTOS DA LISTA
{
	Nodo *aux,*aux2,*ant,*prox;
	int dia,mes,ano,hora,min,datarmv,horarmv,opc,valida=0;
	char descricao[80], *resultado_busc;
	char anulado[80] = "ANULADO!";
	
	fflush(stdin);
	system("cls");
	printf("\t\t[R] - Remover compromisso da agenda\n\n");
	printf("[1] - Remover por data\n");
	printf("[2] - Remover compromisso especifico\n");
	printf("R: "); scanf("%d", &opc); 
	
	switch(opc)
	{
		case 1:
			system ("cls");
			printf("\t\t[2] - Remover compromisso por data\n");
			printf("\nEntre com a data a ser removida(dia/mes/ano)\n\n");
	
			fflush(stdin);
			printf("Dia: "); scanf("%d", &dia);
			printf("\nMes: "); scanf("%d", &mes);
			printf("\nAno: "); scanf("%d", &ano);
					
			datarmv=((ano*10000)+(mes*100)+(dia));
			fflush(stdin);
			if(*N == NULL)
			{
				system("cls");
				printf("\nA Lista esta vazia!!!\n\n\n");
				system("pause");
				return 8;
			}
			if ((*N)->iddata == datarmv)												//COMPARA A DATA PROCURADA COM O A DATA DO PRIMEIRO ELEMENTO		
			{
				if((*N)->prox == NULL)
					{
						free((*N));
						(*N) = NULL;
					}
				else
				{
					while(((*N)->iddata == datarmv) && ((*N)->prox != NULL))			//TRATA SE O ELEMENTO REMOVIDO FOR UNICO
					{
						aux2 = (*N);
						(*N) = (*N)->prox;
						free(aux2);
					}
					if((*N)->prox == NULL)
					{
						free((*N));
						(*N) = NULL;
					}
				}
				valida++;																//VARIAVEL PARA VERIFICAR SE HOUVE A REMOÇÃO
			}	
			else
			{
				for(aux=(*N); aux->prox != NULL; aux=aux->prox)							//REMOÇÃO DO ELEMENTO DO MEIO DA LISTA
				{
					prox = aux->prox;
					if(datarmv == aux->iddata)
					{
						ant->prox = prox;
						free(aux);
						aux=(*N);
						valida++;
					}
					ant = aux;
				}
				if((aux->prox == NULL) && (aux->iddata == datarmv))						//REMOÇÃO DO ULTIMO ELEMENTO DA LISTA
				{
					ant->prox = NULL;
					free(aux);
					valida++;
				}		
			}
			
			if(valida != 0)
			{
				printf("\n\n Compromissos da data [%d/%d/%d] removidos com sucesso!\n\n", dia, mes, ano);
				system("pause");
			}
			else
			{
				printf("\n\n Nao ha compromissos nessa data");
				system("pause");
			}
			return 8;
		break;
			
		case 2:
			system ("cls");
			printf("\t\t[2] - Remover compromisso especifico\n");
			printf("\nEntre com a data do compromisso(dia/mes/ano)\n\n");
			fflush(stdin);
			printf("Dia: "); scanf("%d", &dia);
			printf("\nMes: "); scanf("%d", &mes);
			printf("\nAno: "); scanf("%d", &ano);
			datarmv=((ano*10000)+(mes*100)+(dia));
			
			printf("\nEntre com a hora do compromisso(hora:min)\n");
			printf("\nHora: "); scanf("%d", &hora);
			printf("\nMin: "); scanf("%d", &min);
			horarmv=((hora*100)+(min));
			
			fflush(stdin);
			printf("\nEntre com a descricao do compromisso: ");
			gets(descricao); strupr(descricao);												//STUPR TRANSFORMA ESTRING EM MAIUSCULO
			
			if(*N == NULL)
			{
				system("cls");
				printf("\nA Lista esta vazia!!!\n\n\n");
				system("pause");
				return 8;
			}
			else
			{
				for(aux = (*N); aux != NULL; aux = aux->prox)
				{
    				resultado_busc = strstr(aux->comp, descricao);							//RETORNA O ENDEREÇO DE BUSCA DA CADEIA DE CARACTER
    				if( (resultado_busc != 0) && (aux->iddata == datarmv) && (aux->idhora == horarmv) )
    				{
    					strcpy(aux->comp,anulado);											//COPIA PALAVARA "ANULADO" PARA A DESCRIÇÃO
    					valida++;
    					printf("\nData: %d/%d/%d", aux->dia, aux->mes, aux->ano);
	    				printf("\nHora: %d:%dh", aux->hora, aux->min);
	    				printf("\nCompromisso: %s\n\n", aux->comp);
	    				system("pause");
					}
				}
			}
			if(valida == 0)
			{
				printf("\n\n Nao ha compromissos nessa data\n\n");
				system("pause");
			}
			return 8;
			break;	
	}
}

int buscar_lista(Nodo **N)															//FUNÇÃO DE BUSCA POR OCORRENCIA DE PALAVRAS
{
	Nodo *aux;
	char palavra_busc[20];
	char *resultado_busc;
	int cont=0;																			
	
	fflush(stdin);	
	system("cls");
	
	printf("\t\t[B] - Buscar compromisso(s) que contem a palavra indicada\n\n");
	printf("Digite a palavra para busca: "); gets(palavra_busc); strupr(palavra_busc);
	
	printf("\nOcorrencias da palavra [%s] na agenda:\n\n", palavra_busc);
	
	aux=(*N);
	

	if((*N) == NULL)
 		printf("A lista esta vazia!!\n\n");
 	else
 	{
    	for(aux = (*N); aux != NULL; aux = aux->prox)
    	{
    		resultado_busc = strstr(aux->comp, palavra_busc);								//RETORNA O ENDEREÇO CORRESPONDENTE A CADEIA DE CARACTERE
			if (resultado_busc != 0)
			{
				cont++;
				printf("Data: %d/%d/%d", aux->dia, aux->mes, aux->ano);
	    		printf("\nHora: %d:%dh", aux->hora, aux->min);
	    		printf("\nCompromisso: %s\n\n", aux->comp);
			}
    	}
 	}
 	if(cont == 0){printf("Nao houveram ocorrencias da palavra inserida\n\n"); }
	system("pause");		
	return 8;
}

int salvar_disco(Nodo *N)															//FUNÇÃO PARA SALVAR DADOS EM ARQUIVO TXT
{
	FILE *arquivo;
	char opc;
	Nodo *aux;
	
	do
	{
	system("cls");
	fflush(stdin);
	
	printf("\t\t[S] - Salvar em disco os compromissos da agenda\n\n");
	printf("Salvar dados?(S/N)\nR: "); scanf("%c", &opc); fflush(stdin); opc=toupper(opc);
	
	if(opc == 'S')
	{	
		if(N == NULL)
		{
 			printf("\n A lista esta vazia!!\n\n");
 			system("pause");
 			return 8;
 		}
 		else
 		{
 			arquivo = fopen("agenda.txt", "w");
 			
    		for(aux = N; aux != NULL; aux = aux->prox)
		    {
		    	fprintf(arquivo, "%d %d %d %d %d %d %d %s\n", aux->iddata, aux->idhora, aux->dia, aux->mes, aux->ano,
				aux->hora, aux->min, aux->comp);
	   		}
	   		fclose(arquivo);
		 	printf("\n\nDados salvos com sucesso!!!\n\n");
		 	system("pause");
			return 8;		
 		} 		
	}
	if(opc == 'N')
	{
		printf("\n\n Operacao salvar cancelada!\n\n");
		opc = 'S';
		system("pause");
		return 8;
	}
	else
	{
		printf("\n\nOpcao Invalida!!!\n\n");
		system("pause");
	}
	}while(opc != 'S');
}

int carregar_dados(Nodo **N)														//FUNÇÃO PARA LER DADOS DO ARQUIVO TXT
{
	FILE *arquivo;
	Nodo novo;
	int  teste=0;
	
	system("cls");
	arquivo = fopen("agenda.txt", "r");
	
	if(!arquivo)
	{
		printf("Arquivo nao pode ser aberto");
		return 8;
	}
	else
	while(feof(arquivo)==0)
		{
			fscanf(arquivo,"%d%d%d%d%d%d%d", &novo.iddata, &novo.idhora, &novo.dia, &novo.mes, &novo.ano,
			&novo.hora, &novo.min);
			fgets(novo.comp, sizeof(novo.comp),arquivo);
			if(feof(arquivo)==0)
				insere_compromisso(N, novo);
		}
		printf("\n\nDados carregados com sucesso!\n\n");
	    fclose(arquivo);
	    system("pause");
	    return 8;
}

void main()
{
    int opc=0;                                                                      //VARIAVEL "OPC" DESTINADA PARA OPÇÕES DO SWITCH CASE.
    Nodo *inicio, dados;

    inicializa_lista(&inicio);

    do
    {
        system("cls");
        opc=menu();                                                                 //CHAMADA DA FUNÇÃO MENU PARA INICIALIZAR O PROGRAMA.

        switch(opc)
        {
             case 0:                                                                //[I] - INSERIR UM COMPROMISSO NA AGENDA
				 dados_compromisso(&dados);
                 opc = insere_compromisso(&inicio, dados);
               break;
             case 1:																//[R] - REMOVER UM COMPROMISSO DA AGENDA
             	 opc=remover_elemento(&inicio);										
               break;
             case 2:																//[C] - CONSULTAR COMPROMISSO DA AGENDA
                 opc=consulta(inicio);
               break;
             case 3:
             	 opc=buscar_lista(&inicio);											//[B] - BUSCAR COMPROMISSO(S) QUE CONTEM A PALAVRA INDICADA
               break;
             case 4:																//[S] - SALVAR EM DISCO OS COMPROMISSOS DA AGENDA
                 opc=salvar_disco(inicio);
               break;
             case 5:																//[L] - LER DO DISCO OS COMPROMISSOS DA AGENDA
             	 opc=carregar_dados(&inicio);
               break;
             case 6:																//[F] - TERMINAR A EXECUÇÃO DO PROGRAMA
             	system("cls");
		   		printf("\n\nSaindo do ADC!!!\n\n\n");
               break;
             case 7:
                system("cls");
		   		printf("\n\nOpcao Invalida!!!\n\n\n");
		   		opc = 8;
		   		system("pause");
              break;
             case 9:																//[V] - VIZUALIZAR A AGENDA
             	opc=imprime_lista(inicio);
               break;
        }
    }while(opc == 8);
}
