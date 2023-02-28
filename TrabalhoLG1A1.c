// TRABALHO DA MAT�RIA LG1A1
//Professora: Eurides Balbino

//Autor: Marcelo Ferreira Cruz
//Prontu�rio: SP3068862
// IFSP campus S�o Paulo

//Bibliotecas
#include <stdio.h>                 //Biblioteca padr�o para usar v�rias funcionalidades do C
#include <stdlib.h>                //Biblioteca para usar os comandos system e o fflush
#include <conio.h>                 //Biblioteca para usar a fun��o getch e getche
#include <locale.h>                //Biblioteca para respeitar a acentua��o gr�fica da l�ngua portuguesa
#include <string.h>                //Biblioteca para usar fun��es para strings
#include "biblioteca_trabLG1A1.h"  //Biblioteca criada pelo programador para definir estruturas heterog�neas do programa

//Vari�veis globais	
log login;                         //vari�vel do tipo log para fazer o login do usu�rio
cadastro reg[5];                   //vari�vel vetor do tipo cadastros
cadastro aux;                      //vari�vel do tipo cadastro para auxilio
int i;                             //indice para percorrer os vetores com o for

//Ponteiros apontando para FILE
FILE * arq0;               
FILE * arq1;
FILE * arq2;
FILE * arq3;
FILE * auxiliar;

//Prot�tipos de fun��es
int main ();
void Login (void);
void MASTER (void);
void Cadastrar (void);
void Visualizar (void);
void RealizaTeste (void);
void SobreOTeste (void);
void Pergunta1 (void);
void Pergunta2 (void);
void Pergunta3 (void);
void Pergunta4 (void);
void Pergunta5 (void);
void RESULTADO (void);

//Corpo do programa main
int main ()
{
	setlocale(LC_ALL,"Portuguese_Brazil");   //Mudar idioma para o portugu�s brasileiro
	Login();                                 //Chamar a fun��o Login
	return(0);                               //Devolve "0" um n�mero inteiro para a fun��o Main
}

//Corpo do programa Login
void Login (void)
{ 
    system("mode  50,8");        //Redimensiona a tela do prompt
    char M[7] = "MASTER";        //Cria uma vari�vel local do tipo char vetor de string, onde nomeio de "MASTER"
    
    //Pedir para o usu�rio digitar o nome
	printf ("\n\nDIGITE SEU NOME       : "); fflush(stdin); //Limpa buffer do teclado
	gets(login.nome); //Captura o que o usu�rio digitou
	
	//Pedir para o usu�rio digitar o prontu�rio
	printf ("\n\nDIGITE SEU PRONTU�RIO : "); fflush(stdin); //Limpa buffer do teclado
	gets(login.prontuario); //Captura o que o usu�rio digitou
	
	//Testa o que o usu�rio digitou no nome � igual o MASTER
	if (strcmp(login.nome,M) == 0)
	{
		MASTER();   //Se for ele prosseguir� para a fun��o MASTER
	}
	RealizaTeste(); //Se n�o ele prosseguir� para a fun��o RealizaTeste
}

//Corpo do programa MASTER
void MASTER (void)
{
	system("mode 66,11");   //Redimensiona a tela
	char opc;               //Vari�vel local ao MASTER, que servir� para pegar a op��o que usu�rio digitar
	
	//Menu de op��es ele se manter� em looping at� a OPC que for escolhida ser f ou F
	do
	{
		system("cls"); //Limpar tela
	    printf("=================================================");
	    printf("\n       TESTE DOS SISTEMAS REPRESENTACIONAIS");
	    printf("\n=================================================");
	    printf("\n      1. Cadastrar question�rio");
	    printf("\n      2. Visualizar question�rio");
        printf("\n      3. Realizar teste");
	    printf("\n      4. Sobre o teste");
	    printf("\n      F. Fim");
     	printf("\n=================================================");
    	printf("\n      Escolha -> ");
    	opc = getche(); //op��o receber� o que o usu�rio digitar
    	switch (opc)
    	{
    		//Caso o usu�rio digitar 1 ela chamar� a fun��o Cadastrar
        	case '1' : Cadastrar(); break;  
        	
			//Caso o usu�rio digitar 2 chamar� a fun��o Visualizar
	        case '2' : Visualizar(); break; 
			 
			//Caso o usu�rio digitar 3 chamar� a fun��o RealizaTeste
	        case '3' : RealizaTeste(); break; 
			    
			//Caso o usu�rio digitar 4 chamar� a fun��o SobreOTeste           
	        case '4' : SobreOTeste(); break;  
			       
			//Caso o usu�rio digitar f ou F o programa vai finalizar        
	        case 'F' : case 'f': exit(0); break;  
			      
			//Caso digitar qualquer coisa diferente dessas op��es mostrar� uma mensagem de erro    
        	default : system("cls"); system("mode 35,4");
			printf("\n\t ERRO AO ESCOLHER!"); getch(); MASTER();
        }
    }
    while (opc =! 'F' || 'f');
} 

//Corpo do programa Cadastra
void Cadastrar (void)
{
	//Preenchimento do vetor reg para cada informa��o da pergunta, na ordem:
	//N�mero da frase, frase, item1, item2, item3, item4
	reg[0].NroFrase = 1;
	strcpy (reg[0].frase , "Eu tomo decis�es importantes baseado em:");
	strcpy (reg[0].item_1 , "intui��o.");
	strcpy (reg[0].item_2 , "o que me soa melhor.");
	strcpy (reg[0].item_3 , "o que me parece melhor.");
	strcpy (reg[0].item_4 , "um estudo preciso e minucioso do assunto.");
	
	reg[1].NroFrase = 2;
	strcpy (reg[1].frase , "Durante uma discuss�o eu sou mais influenciado por:");
	strcpy (reg[1].item_1 , "se eu entro em contato ou n�o com os sentimentos reais do outro.");
	strcpy (reg[1].item_2 , "o tom da voz da outra pessoa.");
	strcpy (reg[1].item_3 , "se eu posso ou n�o ver o argumento da outra pessoa.");
	strcpy (reg[1].item_4 , "a l�gica do argumento da outra pessoa.");
	
	reg[2].NroFrase = 3;
	strcpy (reg[2].frase , "Eu comunico mais facilmente o que se passa comigo:");
	strcpy (reg[2].item_1 , "pelos sentimentos que compartilho.");
	strcpy (reg[2].item_2 , "pelo tom da minha voz.");
	strcpy (reg[2].item_3 , "do modo como me visto e aparento.");
	strcpy (reg[2].item_4 , "pelas palavras que escolho.");
	
	reg[3].NroFrase = 4;
	strcpy (reg[3].frase , "� muito f�cil para min:");
	strcpy (reg[3].item_1 , "escolher os m�veis mais confort�veis.");
	strcpy (reg[3].item_2 , "achar o volume e a sintonia ideais num sistema de som.");
	strcpy (reg[3].item_3 , "escolher as combina��es de cores mais ricas e atraentes.");
	strcpy (reg[3].item_4 , "selecionar o ponto mais relevante relativo a um assunto interessante.");
	
	reg[4].NroFrase = 5;
	strcpy (reg[4].frase , "Eu me percebo assim:");
	strcpy (reg[4].item_1 , "eu sou muito sens�vel � maneira como a roupa veste o meu corpo.");
	strcpy (reg[4].item_2 , "se estou muito em sintonia com os sons dos ambientes.");
	strcpy (reg[4].item_3 , "eu respondo fortemente �s cores e � apar�ncia de uma sala.");
	strcpy (reg[4].item_4 , "se sou muito capaz de raciocinar com fatos e dados novos.");
	
	//Cria��o do arquivo DAT
	//Abre o arquivo
	arq2 = fopen ("TESTE_SISTEMA_REPRESENTACIONAL.DAT" , "w");
	if (arq2 == NULL)
	{
		printf("\nERRO AO CADASTRAR O TESTE_SISTEMA_REPRESENTACIONAL.DAT!");
		getch(); exit(0);
	}
	
	//Grava��o das informa��es para o arquivo DAT
	for (i=0; i<5; i++)
	{
		fwrite (&reg[i] , sizeof(reg[i]),1,arq2);
		if(ferror(arq2))
		{
			printf("\nERRO AO GRAVAR O REGISTRO [%i]",i);
			getch(); break;
		}
	}
	
	//Fecha o arquivo
	fclose (arq2);
	//Mostra na tela a mensagem que o arquivo DAT foi Cadastrada
	printf("\nCadastro do TESTE_SISTEMA_REPRESENTACIONAL.DAT conclu�da.");
	getch();
}

//Corpo do programa Visualizar
void Visualizar (void)
{
	//Abrir o arquivo de texto QUESTION�RIO_1
	auxiliar = fopen ("QUESTION�RIO_1.TXT", "w");
	if (auxiliar == NULL)
	{
		printf ("\nErro ao gerar o QUESTION�RIO_1.TXT!");
		getch(); exit(0);
	}
	
	//Ler o arquivo DAT TESTE_SISTEMA_REPRESENTACIONAL	
	arq3 = fopen ("TESTE_SISTEMA_REPRESENTACIONAL.DAT", "r");
	if (arq3 == NULL)
	{
		printf ("\nErro ao ler o TESTE_SISTEMA_REPRESENTACIONAL.DAT");
		getch(); exit(0);
	}
	
	//formata��o do arquivo de texto conforme como o trabalho foi pedido
	fprintf(auxiliar,"NroFrase\t\t\t\t\tFrases\t\t\t   C item_1\t\t\t\t\t\t\t\t     A item_2\t\t\t\t\t\t\t\t       V item_3\t\t\t\t\t\t\t            D item_4");
    fprintf(auxiliar,"\n=======================================================================================================================================");
	fprintf(auxiliar,"=========================================================================================================================================");
	fprintf(auxiliar,"============================================================================================");
	
	//Enquanto n�o for fim do arquivo
	while ( !feof(arq3))	
	{
		//Ler os registros do arquivo DAT
		fread (&aux, sizeof(aux),1,arq3);
		
		//Se der erro ao ler mostrar na tela
		if(ferror(arq3))
		{
			printf ("\nErro ao ler o registro do QUESTION�RIO_1");
			getch(); break;
		}
		
		//Testar se leu o EOF
		if (!feof(arq3))
		{
			//Mostra no arquivo texto
			fprintf(auxiliar,"\n%2i %70s %2i %-70s %2i %-70s %2i %-65s %2i %-75s"
			,aux.NroFrase,aux.frase,aux.C,aux.item_1,aux.A,aux.item_2,aux.V,aux.item_3,aux.D,aux.item_4);
		}
	}
	fprintf(auxiliar,"\n=======================================================================================================================================");
	fprintf(auxiliar,"=========================================================================================================================================");
	fprintf(auxiliar,"============================================================================================");
	
	//Fecha o arquivo e o auxiliar
	fclose (arq3);
	fclose (auxiliar);
	
	//Abre com o notepad o arquivo QUESTION�RIO_1
	system ("notepad QUESTION�RIO_1");
}

//Corpo do programa RealizaTeste
void RealizaTeste (void)
{
	//Fun��o RealizaTeste vai chamar as fun��es perguntas ap�s o termino
	//mostrar� o resultado e por �ltimo voltar� para o menu
	system ("cls");
	Pergunta1(); Pergunta2(); Pergunta3(); Pergunta4(); Pergunta5(); RESULTADO(); MASTER();
}

//Corpo do programa Pergunta1
void Pergunta1 ()
{
	//Mostra na tela a estrutura da pergunta 1
	system("mode  72,21");
	printf("Nas frases a seguir, pontue com:");
	printf("\n4 a que melhor descreve voc�;");
	printf("\n3 a pr�xima melhor descri��o;");
	printf("\n2 a pr�xima melhor; e");
	printf("\n1 aquela que menos descreve voc�.");
	
	printf("\n\n\n1. Eu tomo decis�es importantes baseado em:");
	printf("\na) intui��o.");
	printf("\nb) o que me soa melhor.");
	printf("\nc) o que me parece melhor.");
	printf("\nd) um estudo preciso e minucioso do assunto.");
	
	//Captura o que o usu�rio digitou e tamb�m faz uma compara��o de poss�veis erros que o usu�rio cometeu
	//A resposta tem que ser entre o n�mero 1 e 4, sendo que todas as respostas diferentes uma das outras
	//Caso ele erre, o programa retornar� uma mensagem de erro e voltar� direto para o menu de escolhas
	printf("\n\n[a] -> "); fflush(stdin); scanf("%i",&reg[0].C);
	if (reg[0].C < 1 || reg[0].C > 4)
	{
		system("cls"); system("mode 35,4");
		printf("\n\t ERRO AO ESCOLHER!"); getch(); MASTER();
	} 
	printf("\n[b] -> "); fflush(stdin); scanf("%i",&reg[0].A);
	
	if (reg[0].A < 1 || reg[0].A > 4 || reg[0].A == reg[0].C)
	{
		system("cls"); system("mode 35,4");
		printf("\n\t ERRO AO ESCOLHER!"); getch(); MASTER();
	} 
	printf("\n[c] -> "); fflush(stdin); scanf("%i",&reg[0].V);
	
	if (reg[0].V < 1 || reg[0].V > 4 || reg[0].V == reg[0].C || reg[0].V== reg[0].A)
	{
		system("cls"); system("mode 35,4");
		printf("\n\t ERRO AO ESCOLHER!"); getch(); MASTER();
	} 
	printf("\n[d] -> "); fflush(stdin); scanf("%i",&reg[0].D);
	
	if (reg[0].D < 1 || reg[0].D > 4 || reg[0].D == reg[0].C || reg[0].D == reg[0].A || reg[0].D == reg[0].V)
	{
		system("cls"); system("mode 35,4");
		printf("\n\t ERRO AO ESCOLHER!"); getch(); MASTER();
	} 
} 

//Corpo do programa Pergunta2
void Pergunta2 ()
{
	//mostra na tela a estrutura da pergunta 2
	system("cls"); system("mode  72,21");
	printf("Nas frases a seguir, pontue com:");
	printf("\n4 a que melhor descreve voc�;");
	printf("\n3 a pr�xima melhor descri��o;");
	printf("\n2 a pr�xima melhor; e");
	printf("\n1 aquela que menos descreve voc�.");
	printf("\n\n\n2. Durante uma discuss�o eu sou mais influenciado por:");
	printf("\na) o tom da voz da outra pessoa.");
	printf("\nb) se eu posso ou n�o ver o argumento da outra pessoa.");
	printf("\nc) a l�gica do argumento da outra pessoa.");
	printf("\nd) se eu entro em contato ou n�o com os sentimentos reais do outro.");
	
	//Captura o que o usu�rio digitou e tamb�m faz uma compara��o de poss�veis erros que o usu�rio cometeu
	//A resposta tem que ser entre o n�mero 1 e 4, sendo que todas as respostas diferentes uma das outras
	//Caso ele erre, o programa retornar� uma mensagem de erro e voltar� direto para o menu de escolhas
	printf("\n\n[a] -> "); fflush(stdin); scanf("%i",&reg[1].A);
	if (reg[1].A < 1 || reg[1].A > 4)
	{
		system("cls"); system("mode 35,4");
		printf("\n\t ERRO AO ESCOLHER!"); getch(); MASTER();
	} 
	printf("\n[b] -> "); fflush(stdin); scanf("%i",&reg[1].V);
	
	if (reg[1].V < 1 || reg[1].V > 4 || reg[1].V == reg[1].A)
	{
		system("cls"); system("mode 35,4");
		printf("\n\t ERRO AO ESCOLHER!"); getch(); MASTER();
	} 
	printf("\n[c] -> "); fflush(stdin); scanf("%i",&reg[1].D);
	
	if (reg[1].D < 1 || reg[1].D > 4 || reg[1].D == reg[1].V || reg[1].D == reg[1].A)
	{
		system("cls"); system("mode 35,4");
		printf("\n\t ERRO AO ESCOLHER!"); getch(); MASTER();
	} 
	printf("\n[d] -> "); fflush(stdin); scanf("%i",&reg[1].C);
	
	if (reg[1].C < 1 || reg[1].C > 4 || reg[1].C == reg[1].D || reg[1].C == reg[1].V || reg[1].C == reg[1].A)
	{
		system("cls"); system("mode 35,4");
		printf("\n\t ERRO AO ESCOLHER!"); getch(); MASTER();
	} 
}

//Corpo do programa Pergunta3
void Pergunta3 ()
{
	//Mostra na tela a estrutura da pergunta 3
	system("cls"); system("mode  72,21");
	printf("Nas frases a seguir, pontue com:");
	printf("\n4 a que melhor descreve voc�;");
	printf("\n3 a pr�xima melhor descri��o;");
	printf("\n2 a pr�xima melhor; e");
	printf("\n1 aquela que menos descreve voc�.");
	printf("\n\n\n3. Eu comunico mais facilmente o que se passa comigo:");
	printf("\na) do modo como me visto e aparento.");
	printf("\nb) pelos sentimentos que compartilho.");
	printf("\nc) pelas palavras que escolho.");
	printf("\nd) pelo tom da minha voz.");
	
	//Captura o que o usu�rio digitou e tamb�m faz uma compara��o de poss�veis erros que o usu�rio cometeu
	//A resposta tem que ser entre o n�mero 1 e 4, sendo que todas as respostas diferentes uma das outras
	//Caso ele erre, o programa retornar� uma mensagem de erro e voltar� direto para o menu de escolhas
	printf("\n\n[a] -> "); fflush(stdin); scanf("%i",&reg[2].V);
	if (reg[2].V < 1 || reg[2].V > 4)
	{
		system("cls"); system("mode 35,4");
		printf("\n\t ERRO AO ESCOLHER!"); getch(); MASTER();
	} 
	printf("\n[b] -> "); fflush(stdin); scanf("%i",&reg[2].C);
	
	if (reg[2].C < 1 || reg[2].C > 4 || reg[2].C == reg[2].V)
	{
		system("cls"); system("mode 35,4");
		printf("\n\t ERRO AO ESCOLHER!"); getch(); MASTER();
	} 
	printf("\n[c] -> "); fflush(stdin); scanf("%i",&reg[2].D);
	
	if (reg[2].D < 1 || reg[2].D > 4 || reg[2].D == reg[2].C || reg[2].D == reg[2].V)
	{
		system("cls"); system("mode 35,4");
		printf("\n\t ERRO AO ESCOLHER!"); getch(); MASTER();
	} 
	printf("\n[d] -> "); fflush(stdin); scanf("%i",&reg[2].A);
	
	if (reg[2].A < 1 || reg[2].A > 4 || reg[2].A == reg[2].D || reg[2].A == reg[2].C || reg[2].A == reg[2].V)
	{
		system("cls"); system("mode 35,4");
		printf("\n\t ERRO AO ESCOLHER!"); getch(); MASTER();
	} 
}

//Corpo do programa Pergunta4
void Pergunta4 ()
{
	//Mostra na tela a estrutura da pergunta 4
	system("cls"); system("mode  72,21");
	printf("Nas frases a seguir, pontue com:");
	printf("\n4 a que melhor descreve voc�;");
	printf("\n3 a pr�xima melhor descri��o;");
	printf("\n2 a pr�xima melhor; e");
	printf("\n1 aquela que menos descreve voc�.");
	printf("\n\n\n4. � muito f�cil para min:");
	printf("\na) achar o volume e a sintonia ideais num sistema de som.");
	printf("\nb) selecionar o ponto mais relevante relativo a um assunto interessante.");
	printf("\nc) escolher os m�veis mais confort�veis.");
	printf("\nd) escolher as combina��es de cores mais ricas e atraentes.");
	
	//Captura o que o usu�rio digitou e tamb�m faz uma compara��o de poss�veis erros que o usu�rio cometeu
	//A resposta tem que ser entre o n�mero 1 e 4, sendo que todas as respostas diferentes uma das outras
	//Caso ele erre, o programa retornar� uma mensagem de erro e voltar� direto para o menu de escolhas
	printf("\n\n[a] -> "); fflush(stdin); scanf("%i",&reg[3].A);
	if (reg[3].A < 1 || reg[3].A > 4)
	{
		system("cls"); system("mode 35,4");
		printf("\n\t ERRO AO ESCOLHER!"); getch(); MASTER();
	} 
	printf("\n[b] -> "); fflush(stdin); scanf("%i",&reg[3].D);
	
	if (reg[3].D < 1 || reg[3].D > 4 || reg[3].D == reg[3].A)
	{
		system("cls"); system("mode 35,4");
		printf("\n\t ERRO AO ESCOLHER!"); getch(); MASTER();
	} 
	printf("\n[c] -> "); fflush(stdin); scanf("%i",&reg[3].C);
	
	if (reg[3].C < 1 || reg[3].C > 4 || reg[3].C == reg[3].D || reg[3].C == reg[3].A)
	{
		system("cls"); system("mode 35,4");
		printf("\n\t ERRO AO ESCOLHER!"); getch(); MASTER();
	} 
	printf("\n[d] -> "); fflush(stdin); scanf("%i",&reg[3].V);
	
	if (reg[3].V < 1 || reg[3].V > 4 || reg[3].V == reg[3].C || reg[3].V == reg[3].D || reg[3].V == reg[3].A)
	{
		system("cls"); system("mode 35,4");
		printf("\n\t ERRO AO ESCOLHER!"); getch(); MASTER();
	} 
}

//Corpo do programa Pergunta5
void Pergunta5 ()
{
	//Mostra na tela a estrutura da pergunta 5
	system("cls"); system("mode  72,21");
	printf("Nas frases a seguir, pontue com:");
	printf("\n4 a que melhor descreve voc�;");
	printf("\n3 a pr�xima melhor descri��o;");
	printf("\n2 a pr�xima melhor; e");
	printf("\n1 aquela que menos descreve voc�.");
	printf("\n\n\n5. Eu me percebo assim:");
	printf("\na) se estou muito em sintonia com os sons dos ambientes.");
	printf("\nb) se sou muito capaz de raciocinar com fatos e dados novos.");
	printf("\nc) eu sou muito sens�vel � maneira como a roupa veste o meu corpo.");
	printf("\nd) eu respondo fortemente �s cores e � apar�ncia de uma sala.");
	
	//Captura o que o usu�rio digitou e tamb�m faz uma compara��o de poss�veis erros que o usu�rio cometeu
	//A resposta tem que ser entre o n�mero 1 e 4, sendo que todas as respostas diferentes uma das outras
	//Caso ele erre, o programa retornar� uma mensagem de erro e voltar� direto para o menu de escolhas
	printf("\n\n[a] -> "); fflush(stdin); scanf("%i",&reg[4].A);
	if (reg[4].A < 1 || reg[4].A > 4)
	{
		system("cls"); system("mode 35,4");
		printf("\n\t ERRO AO ESCOLHER!"); getch(); MASTER();
	} 
	printf("\n[b] -> "); fflush(stdin); scanf("%i",&reg[4].D);
	
	if (reg[4].D < 1 || reg[4].D > 4 || reg[4].D == reg[4].A)
	{
		system("cls"); system("mode 35,4");
		printf("\n\t ERRO AO ESCOLHER!"); getch(); MASTER();
	} 
	printf("\n[c] -> "); fflush(stdin); scanf("%i",&reg[4].C);
	
	if (reg[4].C < 1 || reg[4].C > 4 || reg[4].C == reg[4].D || reg[4].C == reg[4].A)
	{
		system("cls"); system("mode 35,4");
		printf("\n\t ERRO AO ESCOLHER!"); getch(); MASTER();
	} 
	printf("\n[d] -> "); fflush(stdin); scanf("%i",&reg[4].V);
	
	if (reg[4].V < 1 || reg[4].V > 4 || reg[4].V == reg[4].C || reg[4].V == reg[4].D || reg[4].V == reg[4].A)
	{
		system("cls"); system("mode 35,4");
		printf("\n\t ERRO AO ESCOLHER!"); getch(); MASTER();
	} 
}

//Corpo do programa SobreOTeste
void SobreOTeste (void)
{
	//Cria o arquivo de texto REFERENCIAL_TEORICO
	arq1 = fopen("REFERENCIAL_TEORICO.TXT", "w");
	
	//Copia para o arquivo de texto as seguintes mensagens:
	fprintf(arq1,"REFERENCIAL TE�RICO");
	fprintf(arq1,"\n===================");
	fprintf(arq1,"\n\nSegundo Albert Merabian, em seu livro �Silent Messages�, o poder de influ�ncia das palavras n�o passa de 7%%,");
	fprintf(arq1,"\nenquanto a forma como as palavras s�o ditas e a fisiologia representam 38%% e 55%% deste poder, respectivamente.");
	fprintf(arq1,"\n\nPara Merabian 55%% do impacto da comunica��o � n�o-verbal. Corresponde � postura, gestos e contato visual da pessoa enquanto se comunica.");
	fprintf(arq1,"\n\nO tom da voz representa 38%% do impacto da comunica��o.");
	fprintf(arq1,"\n\nPor fim, as palavras propriamente ditas det�m 7%% do impacto da comunica��o.");
	fprintf(arq1,"\n\nAssim sendo, conclui Merabian, n�o � o que dizemos, mas como dizemos que faz a diferen�a na comunica��o.");
	fprintf(arq1,"\n\nAs portas da percep��o s�o os nossos sentidos, nossos olhos, nariz, ouvidos, boca e pele, nossos �nicos pontos de conato com o mundo exterior.");
	fprintf(arq1,"\nDa mesma forma que utilizamos os sentidos para filtrarmos as experi�ncias, utilizamos os sentidos para estruturar nosso pensamento e nossa comunica��o");
	fprintf(arq1,"\n\nDe acordo com a Programa��o Neurolingu�stica existem os seguintes sistemas representacionais.");
	fprintf(arq1,"\n\n- Auditivo");
	fprintf(arq1,"\n- Digital");
	fprintf(arq1,"\n- Cinest�sico");
	fprintf(arq1,"\n- Visual");
	fprintf(arq1,"\n\nAlgumas pessoas captam melhor as mensagens do mundo exterior atrav�s da audi��o, s�o as pessoas chamadas auditivas.");
	fprintf(arq1,"\nOutras pessoas sentem necessidade de perguntar muito, necessitam de muitas informa��es e fatos. Estas s�o as digitais.");
	fprintf(arq1,"\nAs cinest�sicas aprendem melhor por meio das sensa��es t�teis, como o tato, a temperatura, a umidade, as sensa��es internas e as emo��es.");
	fprintf(arq1,"\nJ� as pessoas visuais aprendem melhor quando se valendo da vis�o.");
	fprintf(arq1,"\n\nCada pessoa tem um sistema representacional predominante e adequar a comunica��o ao sistema representacional dominante dela � fundamental para di�logos eficientes.");
	
	//Fecha o arquivo
	fclose (arq1);
	
	//Fun��o para abrir o arquivo de texto REFENCIAL_TEORICO com o notepad
	system ("notepad REFERENCIAL_TEORICO.TXT");
}

//Corpo do programa RESULTADO
void RESULTADO (void)
{
	//Vari�veis locais da fun��o RESULTADO
	int cin,aud,dig,vis;               //Vari�veis int para pegar o resultado da soma e multiplica��o dos itens
	char PERFIL[14];                   //Vari�vel char para pegar o maior resultado do teste
	char ARQ_NOME[200], CHAMADA[200];  //Variaveis para poder nomear o arquivo TXT
	
	//Calculo do resultado do teste
	cin = (int)(reg[0].C + reg[1].C + reg[2].C + reg[3].C + reg[4].C)*2;
	aud = (int)(reg[0].A + reg[1].A + reg[2].A + reg[3].A + reg[4].A)*2;
	dig = (int)(reg[0].D + reg[1].D + reg[2].D + reg[3].D + reg[4].D)*2;
	vis = (int)(reg[0].V + reg[1].V + reg[2].V + reg[3].V + reg[4].V)*2;
	
	//Testar cada vari�vel para saber qual � a maior nota
	//Ao percorrer os ifs ele renomear� o vari�vel PERFIL de acordo com o maior resultado
	if (cin > aud && cin > dig && cin > vis)
	{
		strcpy(PERFIL,"CINEST�SICO");
	}
	if (aud > cin && aud > dig && aud > vis)
	{
		strcpy(PERFIL,"AUDITIVO");
	}
	if (dig > cin && dig > aud && dig > vis)
	{
		strcpy(PERFIL,"DIGITAL");
	}
	if (vis > cin && vis > aud && vis > dig)
    {
    	strcpy(PERFIL,"VISUAL");
	}
	
	//Passa o nome que o usu�rio digitou para letras maiusculas
	for (i=0; i<strlen(login.nome);i++)
	{
		login.nome[i] = toupper(login.nome[i]);
		//Para cada ' ' "espa�o" que o usu�rio digitou, virar� '_' "underline"
		if (login.nome[i] == ' ')
		    login.nome[i] = '_';
	}
	
	//Passa o prontu�rio que o usu�rio digitou para letras maiusculas
	for (i=0; i<strlen(login.prontuario);i++)
	{
		login.prontuario[i] = toupper(login.prontuario[i]);
    }
    
    //Limpa o nome do arquivo
	for (i=0; i<strlen(ARQ_NOME); i++)
	{
		ARQ_NOME[i] = '\0';
	}
	
	//Cria��o da variavel ARQ_NAME servir� para preencher o nome do arquivo texto que ser� exibido no teste do usu�rio
	strcat(ARQ_NOME, "RESULTADO_");
	strcat(ARQ_NOME, login.nome);        //Pega o nome do usu�rio
	strcat(ARQ_NOME, "_");
	strcat(ARQ_NOME, login.prontuario);  //Pega o prontu�rio do usu�rio
	strcat(ARQ_NOME, ".TXT");
	
	//Abre o arquivo renomeado
	arq0 = fopen (ARQ_NOME,"w");
	if (arq0 == NULL)
	{
		printf("\nERRO AO ABRIR O %s!",ARQ_NOME);
		getch(); exit(0);
	}
	fprintf(arq0,"======================== PERFIL REPRESENTACIONAL DE %s ========================",login.nome);
	fprintf(arq0,"\n %i%% Visual \t %i%% Auditivo \t %i%% Cinest�sico \t %i%% Digital",vis,aud,cin,dig);
	fprintf(arq0,"\n===================================================================================");
	fprintf(arq0,"\nAlgumas pessoas captam melhor as mensagens do mundo exterior atrav�s da audi��o, s�o as pessoas chamadas auditivas.");
	fprintf(arq0,"\nOutras pessoas sentem necessidade de perguntar muito, necessitam de muitas informa��es e fatos. Estas s�o as digitais.");
	fprintf(arq0,"\nAs cinest�sicas aprendem melhor por meio das sensa��es t�teis, como o tato, a temperatura, a umidade, as sensa��es internas e as emo��es.");
	fprintf(arq0,"\nJ� as pessoas visuais aprendem melhor quando se valendo da vis�o.");
	fprintf(arq0,"\n===================================================================================");
	fprintf(arq0,"\nSeu perfil �: %s",PERFIL);
	fprintf(arq0,"\n===================================================================================");
	
	//Outra vari�vel para cria��o de uma string que a fun��o system chamar� abrindo com o notepad
	strcpy(CHAMADA, "notepad ");
	strcat(CHAMADA, ARQ_NOME);
	//Fecha arquivo
	fclose (arq0);
	//Fun��o system que chamar� o arquivo de texto Perfil representacional do usu�rio
	system (CHAMADA);
}

