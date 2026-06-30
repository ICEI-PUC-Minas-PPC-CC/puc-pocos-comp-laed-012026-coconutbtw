/*
 * PROJETO: Avaliacao e Listagem de Coconuts
 * PARTICIPANTES: Luiz Gustavo Ferreira Filho & Jorge Luis de Freitas Junior
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

// Limpa o terminal, linux e windows
void limparTerminal() {
    system("cls || clear");
}

struct Coco
{
    int id;
    int ativo;

    char especie[35];
    char pais[20];

    float preco;
    float nota;
};

struct Coco cocos[10];

// Menu Principal, informa o menu para o usuário
void menuPrincipal()
{
    limparTerminal();

    printf("|=======================================|\n");
    printf("|          SISTEMA DE COCONUTS          |\n");
    printf("|=======================================|\n");
    printf("               [1] Inserir               \n");
    printf("               [2] Listar                \n");
    printf("               [3] Editar                \n");
    printf("               [4] Excluir               \n");
    printf("               [5] Pesquisar             \n");
    printf("               [6] Resumo                \n");
    printf("|---------------------------------------|\n");
    printf("|         [7] Sair do Sistema           |\n");
    printf("|=======================================|\n");
    printf(" >>> Escolha uma opção: ");
}

// Funcão para inserir coconuts
void inserirCoconut()
{
    int indice;

    // Verifica o indice e se esta ativo
    for ( indice = 0; indice < 10; indice++ ) {
	if (cocos[indice].ativo == 0) {
	    break;
        }
    }

    // Alerta de armazamento cheio
    if ( indice == 10 ) {
	printf("\nErro! Sistema está cheio\n");
	return;
    }

    printf("|=======================================|\n");
    printf("|         ADICIONAR OS COCONUTS         |\n");
    printf("|=======================================|\n");

    // limpa o buffer do teclado
    //fflush(stdin);
    while(getchar() != '\n');
    printf("Digite a espécie do coconut: ");
    scanf(" %[^\n]", cocos[indice].especie);

    // limpa o buffer do teclado
    //fflush(stdin);
    while(getchar() != '\n');
    printf("Digite o país nativo do coconut: ");
    scanf(" %[^\n]", cocos[indice].pais);

    printf("Digite o preço do coconut: ");
    scanf("%f", &cocos[indice].preco);
    while ( cocos[indice].preco < 0 ) {
	printf("Preço invalido! Digite novamente\n");
	printf("Digite o preço do coconut: ");
	scanf("%f", &cocos[indice].preco);
    }

    printf("Digite a nota do coconut (0-5): ");
    scanf("%f", &cocos[indice].nota);
    while ( cocos[indice].nota < 0 || cocos[indice].nota > 5) {
	printf("Nota invalida! Digite novamente\n");
	printf("Digite a nota do coconut (0-5): ");
	scanf("%f", &cocos[indice].nota);
    }

    // Deixa o id de 1 a 10
    cocos[indice].id = indice + 1;
    // Deixa o id registrado como ativo
    cocos[indice].ativo = 1;

    printf("\nCoconut armazenado com sucesso no ID: %d\n", cocos[indice].id);
    printf("|=======================================|\n");
    printf(" >>> Pressione ENTER para continuar");

    while(getchar() != '\n');
    getchar();
    //getchar();
}

// Funcão para listar os coconuts
void listarCoconut()
{
    int indice, cadastrados = 0;

    printf("|=======================================|\n");
    printf("|          LISTAGEM DE COCONUTS         |\n");
    printf("|=======================================|\n");

    for ( indice = 0; indice < 10; indice++ ) {
	// Verifica se o indice esta ativo e foi registrado
	if (cocos[indice].ativo == 1) {
	    printf("|=======================================|\n");
	    printf(" ID: %d\n", cocos[indice].id);
	    printf(" Espécie do Coconut: %s\n", cocos[indice].especie);
	    printf(" País nativo: %s\n", cocos[indice].pais);
	    printf(" Preço do Coconut: %.2f\n", cocos[indice].preco);
	    printf(" Nota do Coconut: %.2f\n", cocos[indice].nota);
	    printf("|=======================================|\n");
	    printf(" >>> Pressione ENTER para continuar");
	    cadastrados++;

	    //fflush(stdin);
	    while(getchar() != '\n');
	    getchar();
	    //getchar();
	    //break;
	}
    }


    if ( cadastrados == 0 ) {
	printf(" Não há nenhum Coconut registrado ainda!\n");
	printf("|=======================================|\n");
	printf(" >>> Pressione ENTER para continuar");

	//fflush(stdin);
	while(getchar() != '\n');
	getchar();
	//getchar();
    }
}

// Funcão para pesquisar o coconut que o usuário inserir
void pesquisarCoconut()
{
    int idPesquisa, indice;

    printf("|=======================================|\n");
    printf("|          PESQUISA DE COCONUTS         |\n");
    printf("|=======================================|\n");
    printf(" Insira o ID do Coconut que deseja: ");
    scanf("%d", &idPesquisa);

    for ( indice = 0; indice < 10; indice++ ) { //[indice].id e idPesquisa andam juntos e são validados
	if ( cocos[indice].ativo == 1 && cocos[indice].id == idPesquisa ) {
	    printf("|=======================================|\n");
	    printf("            Coconut existente            \n");
	    printf("|=======================================|\n");
	    printf(" ID: %d\n", cocos[indice].id);
	    printf(" Espécie do Coconut: %s\n", cocos[indice].especie);
	    printf(" País nativo: %s\n", cocos[indice].pais);
	    printf(" Preço do Coconut: %.2f\n", cocos[indice].preco);
	    printf(" Nota do Coconut: %.2f\n", cocos[indice].nota);
	    printf("|=======================================|\n");
	    printf(" >>> Pressione ENTER para continuar");

	    //fflush(stdin);
	    while(getchar() != '\n');
	    getchar();
	    //getchar();
	    break;
	}
    }

    if ( indice == 10 ) { //ele sai do for anterior valendo 10, caso não exista coco ativo
	printf("|=======================================|\n");
	printf("    Não há nenhum Coconut com esse ID    \n");
	printf("|=======================================|\n");
	printf(" >>> Pressione ENTER para continuar");

	while(getchar() != '\n');
	getchar();
	//getchar();
    }
}

// Submenu para a funcão editarCoconut 
void menuEditar()
{

    printf("|---------------------------------------|\n");
    printf("|       O QUE VOCÊ PRECISA EDITAR       |\n");
    printf("|---------------------------------------|\n");
    printf("               [1] Especie               \n");
    printf("               [2] País                  \n");
    printf("               [3] Preço                 \n");
    printf("               [4] Nota                  \n");
    printf("|---------------------------------------|\n");
    printf("|            [5] Sair do Menu           |\n");
    printf("|=======================================|\n");
    printf(" >>> Escolha uma opção: ");
}

// Funcão para edicão de coconuts
void editarCoconut()
{
    int opcao = 0, idPesquisa, indice;

    printf("|=======================================|\n");
    printf("|           EDIÇÃO DE COCONUTS          |\n");
    printf("|=======================================|\n");
    printf(" Insira o ID do Coconut que deseja: ");
    scanf("%d", &idPesquisa);

    for ( indice = 0; indice < 10; indice++ ) {
	if ( cocos[indice].ativo == 1 && cocos[indice].id == idPesquisa ) {
	    printf("|=======================================|\n");
	    printf("            Coconut existente            \n");
	    printf("|=======================================|\n");
	    printf(" ID: %d\n", cocos[indice].id);
	    printf(" Espécie do Coconut: %s\n", cocos[indice].especie);
	    printf(" País nativo: %s\n", cocos[indice].pais);
	    printf(" Preço do Coconut: %.2f\n", cocos[indice].preco);
	    printf(" Nota do Coconut: %.2f\n", cocos[indice].nota);
	    printf("|=======================================|\n");
	    printf(" >>> Pressione ENTER para continuar");

	    //fflush(stdin);
	    while(getchar() != '\n');
	    getchar();
	    //getchar();
	    break;

        }
    }

    if ( indice == 10 ) { //mesma lógica já comentada, sai do for da funcão valendo se for = 10, informa o usuário
	printf("|=======================================|\n");
	printf(" Não há nenhum Coconut registrado ainda!\n");
	printf("|=======================================|\n");
	printf(" >>> Pressione ENTER para continuar");

	while(getchar() != '\n');
	getchar();
	//getchar();
	return; //retorna o usuário pro main, no caso o menu principal
    }

    while ( opcao != 5 ) { //enquanto opcão diferente de 5, deixa o menu rodando, no caso o menuEditar
	menuEditar();
	scanf("%d", &opcao);

	while ( opcao > 5 || opcao < 1 ) { //valida a opcão do usuário se for maior 5 ou menor que 1,
	    printf("\nInválido! Tente novamente.\n\n"); //ele pede a entrada novamente e exibe o menuEditar
	    menuEditar();
	    scanf("%d", &opcao);
	}

	switch ( opcao ) {
	    case 1:
		while(getchar() != '\n');
		//fflush(stdin);
		printf("Insira a nova espécie do Coconut: ");
		scanf(" %[^\n]", cocos[indice].especie); //edita o coco referente ao indice que já foi validado

		printf("|=======================================|\n");
		printf(" >>> Pressione ENTER para continuar");

		while(getchar() != '\n');
		getchar();
		//getchar();
		break;

	    case 2:
		while(getchar() != '\n');
		printf("Insira o novo país do Coconut: ");
		scanf(" %[^\n]", cocos[indice].pais);

		printf("|=======================================|\n");
		printf(" >>> Pressione ENTER para continuar");

		while(getchar() != '\n');
		//getchar();
		getchar(); //pede entrada do enter pro usuário
		break;

	    case 3:
		printf("Digite o novo preço do coconut: ");
		scanf("%f", &cocos[indice].preco);
		while ( cocos[indice].preco < 0 ) {
		    printf("Preço inválido! Digite novamente\n");
		    printf("Digite o novo preço do coconut: ");
		    scanf("%f", &cocos[indice].preco);
		}

		printf("|=======================================|\n");
		printf(" >>> Pressione ENTER para continuar");

		while(getchar() != '\n');
		getchar();
		//getchar();
		break;

	    case 4:
		printf("Digite a nota do coconut (0-5): ");
		scanf("%f", &cocos[indice].nota);
		while ( cocos[indice].nota < 0 || cocos[indice].nota > 5) {
		    printf("Nota inválida! Digite novamente\n");
		    printf("Digite a nota do coconut (0-5): ");
		    scanf("%f", &cocos[indice].nota);
		}

		printf("|=======================================|\n");
		printf(" >>> Pressione ENTER para continuar");

		while(getchar() != '\n');
		getchar();
		//getchar();
		break;
	}
    }
}

// Funcão para excluir os coconuts
void excluirCoconut()
{
    int idPesquisa, indice;
    int excluir; //serve somente pra 1 e 0, e conferir se o exclui ou não,
                 //pensei em usar bool aqui!

    printf("|=======================================|\n");
    printf("|         EXCLUSÃO DE COCONUTS          |\n");
    printf("|=======================================|\n");
    printf(" Insira o ID do Coconut que deseja excluir: ");
    scanf("%d", &idPesquisa);

    for ( indice = 0; indice < 10; indice++ ) {
	    if ( cocos[indice].ativo == 1 && cocos[indice].id == idPesquisa ) {
		printf("|=======================================|\n");
		printf("            Coconut existente            \n");
		printf("|=======================================|\n");
		printf(" ID: %d\n", cocos[indice].id);
		printf(" Espécie do Coconut: %s\n", cocos[indice].especie);
		printf(" País nativo: %s\n", cocos[indice].pais);
		printf(" Preço do Coconut: %.2f\n", cocos[indice].preco);
		printf(" Nota do Coconut: %.2f\n", cocos[indice].nota);
		printf("|=======================================|\n");

		printf("Deseja realmente excluir este Coconut? (1-Sim / 0-Não): ");
		scanf("%d", &excluir);

		while(excluir < 0 || excluir > 1) { //valida a entrada do usuário
		    printf("Invalido! Deseja realmente excluir este Coconut? (1-Sim / 0-Não): ");
		    scanf("%d", &excluir);
		}

		if (excluir == 1) { //caso a entrada do usuário seja 1, o coco referente ao indice fica "inativo", recebe 0
		    cocos[indice].ativo = 0;
		    printf("\nCoconut excluido com sucesso!\n");
		}

		else { //senão a acão é abortada 
		    printf("\nExclusão não realizada.\n");
		}

		printf("|=======================================|\n");
		printf(" >>> Pressione ENTER para continuar");
		getchar();
		getchar();
		break;
	    }
    }

    if ( indice == 10 ) {
        printf("|=======================================|\n");
        printf("     Esse ID específico não existe!\n");
	printf("|=======================================|\n");
    	printf(" >>> Pressione ENTER para continuar");

	while(getchar() != '\n');
        getchar();
	//getchar();
	return;
    }
}

// Funcão para dar um resumo, media de nota e preco, maior e menor preco
void resumoCoconut()
{
    printf("|=======================================|\n");
    printf("|          RESUMO DE COCONUTS           |\n");
    printf("|=======================================|\n");

    float minPreco, maxPreco, minNota, maxNota, mediaPreco, mediaNota;
    float somaPreco=0, somaNota=0; //precisa valer 0

    int ativos=0;

    int idMax;
    int idMin;
    int idMaxNota;
    int idMinNota;

    minPreco=0;
    maxPreco=0;

    int indice;
    for ( indice = 0;  indice < 10; indice++ ) {
        if ( cocos[indice].ativo == 1 ) {
            ativos++;
            somaPreco = somaPreco + cocos[indice].preco;
            somaNota = somaNota + cocos[indice].nota;

            if ( ativos == 1 ) {
                minPreco = cocos[indice].preco;
                maxPreco = cocos[indice].preco;
                minNota = cocos[indice].nota;
                maxNota = cocos[indice].nota;
                idMin = idMax = idMinNota = idMaxNota = cocos[indice].id; //todos recebem o id da struct
            } else {

                if ( cocos[indice].preco < minPreco ) {
                    minPreco = cocos[indice].preco; //confere
                    idMin = cocos[indice].id; //recebe o id do coco referente, meio que o "dono"
                }
                if ( cocos[indice].preco > maxPreco ) {
                    maxPreco = cocos[indice].preco;
                    idMax = cocos[indice].id; //preco
                }
                if ( cocos[indice].nota < minNota ) {
                    minNota = cocos[indice].nota;
                    idMinNota = cocos[indice].id; //nota
                }
                if ( cocos[indice].nota > maxNota ) {
                    maxNota = cocos[indice].nota;
                    idMaxNota = cocos[indice].id; //nota
                }
            }
        }
    }

      if ( ativos == 0 ) { //se ele não passar no for de cima, ele vai cair como 0 e informar pro usuário
            printf("|=======================================|\n");
            printf(" Não há nenhum Coconut registrado ainda!\n");
            printf("|=======================================|\n");
            printf(" >>> Pressione ENTER para continuar");

	    while(getchar() != '\n');
            getchar();
            //getchar();
            return;
       }

    mediaPreco = somaPreco / (float)ativos; //aqui força os ativos que é int ser float
    mediaNota = somaNota / (float)ativos; //aqui força os ativos que é int ser float

    printf(" Cocos cadastrados ativos: %d\n", ativos);
    printf(" Media de Preco: %.2f\n", mediaPreco);
    printf(" Media de Nota: %.1f\n", mediaNota);
    printf(" Coco mais caro: %.2f - ID: %d\n", maxPreco,idMax);
    printf(" Coco mais barato: %.2f - ID: %d\n", minPreco,idMin);
    printf(" Coco com a melhor nota: %.1f - ID: %d\n", maxNota, idMaxNota);
    printf(" Coco com a pior nota: %.1f - ID: %d\n", minNota, idMinNota);
    printf("|=======================================|\n");
    printf(" >>> Pressione ENTER para continuar");

    while(getchar() != '\n');
    getchar();
    //getchar();
    return;
}

// Funcão principal (main)
int main() {

    limparTerminal();

    int opcao = 0;
    setlocale(LC_ALL, ".UTF8");
    SetConsoleOutputCP;
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8); //só assim pro locale ir, tive problemas com o emacs salvando

    for ( int i = 0; i < 10; i++ ) {
	cocos[i].ativo = 0;
    }

    while ( opcao != 7 ) {
	menuPrincipal();
	scanf("%d", &opcao);

	while ( opcao > 7 || opcao < 1 ) {
	    printf("\nInválido! Tente novamente.\n\n");
	    menuPrincipal();
	    scanf("%d", &opcao);
	}

	switch ( opcao ) {
	    case 1:
		limparTerminal();
		inserirCoconut();
		break;

	    case 2:
		limparTerminal();
		listarCoconut();
		break;

	    case 3:
		limparTerminal();
		editarCoconut();
		break;

	    case 4:
		limparTerminal();
		excluirCoconut();
		break;

	    case 5:
		limparTerminal();
		pesquisarCoconut();
		break;

	    case 6:
		limparTerminal();
		resumoCoconut();
		break;
	    }
    }

    return 0;
}
