#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


// Função que limpa o terminal
void limparTerminal() {

    system("cls || clear");

}


// Registro principal
struct Coco {

    int id;
    int ativo;

    char tipo[35];
    char pais[15];
    
    float preco;
    float nota;

};


// Capacidade de Armazenar 10 Cocos e Indice e Contador dos Coconuts
struct Coco cocos[10];
int quantidade = 0;


// Menu Principal
void menuPrincipal() {

    printf("|====================================|\n");
    printf("|          SISTEMA DE COCOS          |\n");
    printf("|====================================|\n");
    printf("|            [1] Inserir             |\n");
    printf("|            [2] Listar              |\n");
    printf("|            [3] Editar              |\n");
    printf("|            [4] Excluir             |\n");
    printf("|            [5] Buscar              |\n");
    printf("|            [6] Resumo              |\n");
    printf("|------------------------------------|\n");
    printf("|         [7] Sair do Sistema        |\n");
    printf("|====================================|\n");
    printf(" >>> Escolha uma opção: ");

}


// Menu Registro de Coconuts
void menuInserirCoco() {

    if (quantidade >= 10) {

	printf("Não é possível registrar mais de 10 Coconuts\n");
	return;

    }


    limparTerminal();
    printf("|============================================|\n");
    printf("|        MENU DE INSERÇÃO DE COCONUTS        |\n");
    printf("|============================================|\n");

    // Registro da Especie
    printf("Tipo do Coco: ");
    scanf("%s", cocos[quantidade].tipo);

    // Registro do País Nativo
    printf("País nativo do Coco: ");
    scanf("%s", cocos[quantidade].pais);

    // Registro do Preço
    printf("Preço do Coco: ");
    scanf("%f", &cocos[quantidade].preco);

    // Registro da Nota
    printf("Nota do Coco (de 0 até 5): ");
    scanf("%f", &cocos[quantidade].nota);
    while(cocos[quantidade].nota > 5 || cocos[quantidade].nota < 0) {
      printf("Nota invalida, qual a nota do Coco (de 0 até 5): ");
      scanf("%f", &cocos[quantidade].nota);
    }
    
    // Salva o ID de acordo com a Posição do Indice
    cocos[quantidade].ativo = cocos[quantidade].ativo = 1; //ativa o coco deixa ele = 1 :)
    quantidade++;
    
    
    
    limparTerminal();
    printf("|====================================|\n");
    printf("|    Coco Cadastrado com sucesso!    |\n");
}


// Menu de Listagem dos Coconuts
void menuListarCoco() {

    // Verificar se algum coco foi cadastrado
    if ( quantidade == 0) {
	limparTerminal();

	printf("\nNenhum coco foi cadastrado ainda.\n");
	printf("\nPressione ENTER para continuar >>> ");

	getchar();  // Ele aguarda uma entrada mas não armazena nada pra gente
	getchar();  // E são necessarios dois por causa do quebra linha

	limparTerminal();
	return;
    }             


    int indice;
    for ( indice = 0; indice < quantidade; indice++ ) { //entra na estrutura de repeticao parte q toma conta dos indices
        if (cocos[indice].ativo == 1) {       //toma conta dos cocos ativos ou excluidos

	    limparTerminal();

	    printf("\n  Lista de Coconuts  \n\n");
	    printf("ID: %d\n", indice);
	    printf("Tipo: %s\n", cocos[indice].tipo);
	    printf("País: %s\n", cocos[indice].pais);
	    printf("Preço: R$%.2f \n", cocos[indice].preco);
	    printf("Nota (0-5): %.1f\n", cocos[indice].nota);
	    printf("Pressione ENTER para continuar >> ");
		
	   
	    getchar();        
	    getchar();

	    limparTerminal();

	}
    }
}


int id;
// Menu para pesquisa de Coconuts
void buscarCocos() {

    limparTerminal();
    printf("Buscar qual o seu ID: ");
    scanf("%d", &id);

    printf("|====================================|\n");
    printf("|         RESULTADO DA BUSCA         |\n");
    printf("|====================================|\n");
    printf("           ID: %d                    \n", id);   
    printf("           Tipo: %s                  \n", cocos[id].tipo);       
    printf("           País: %s                  \n", cocos[id].pais);
    printf("           Preço: R$%.2f             \n", cocos[id].preco);
    printf("           Nota (0-5): %.1f          \n", cocos[id].nota);
    printf("|====================================|\n");

    printf("Pressione ENTER para continuar >>> ");

    getchar();
    getchar();

    limparTerminal();

}


int excluir;
// Menu de Exclusão de Coconuts
void excluirCocos() {    

    limparTerminal();
    
    printf("Digite o ID do Coconut que deseja excluir: ");
    scanf("%d", &id);

    if ( id >= 0 && id < quantidade && cocos[id].ativo == 1 ) {
	printf("Coconut encontrado:\n\n");

	printf("ID: %d\n", id);   
	printf("Tipo: %s\n", cocos[id].tipo);       
	printf("País: %s\n", cocos[id].pais);
	printf("Preço: R$%.2f\n", cocos[id].preco);
	printf("Nota (0-5): %.1f\n\n", cocos[id].nota);

	printf("Deseja realmente excluir este coco? (1-Sim) / (0-Nao): ");
	scanf("%d", &excluir);
	    
	if ( excluir == 1 ) {
	    cocos[id].ativo = 0;
	}
    } 

    else {
	printf("Erro, ID invalido ou nao existe");
	printf("\nPressione ENTER para continuar >> ");
	getchar();
	getchar();
    }
}


// Menu de Edição de Coconuts
void editarCocos() {

    limparTerminal();
    printf("Digite o ID do Coconut que deseja editar: ");
    scanf("%d", &id);

    int opcaoEditar = 0;
    
    if ( id >= 0 && id < quantidade && cocos[id].ativo == 1 ) {
	printf("Esse ID é valido!\n");


	while ( opcaoEditar != 5 ) {

	    menuEditarCocos();
	    scanf("%d", &opcaoEditar);

	    while ( opcaoEditar > 5 || opcaoEditar < 1 ) {

		printf("\n invalido! tente novamente.\n\n");
		menuEditarCocos();
		scanf("%d", &opcaoEditar);

	    }

	    switch ( opcaoEditar ) {
		case 1:
		    printf("Digite o novo Tipo do Coconut: ");
		    scanf("%s", cocos[id].tipo);
		    printf("Dados atualizado com sucesso!\n");

		    printf("\nPressione ENTER para continuar >> ");
		    getchar();
		    getchar(); 

		    limparTerminal();

		    break;

		case 2:
		    printf("Digite o novo País nativo do Coconut: ");
		    scanf("%s", cocos[id].pais);
		    printf("Dados atualizado com sucesso!\n");

		    printf("\nPressione ENTER para continuar >> ");
		    getchar();
		    getchar(); 

		    limparTerminal();

		    break;

		case 3:
		    printf("Digite o novo preço: ");
		    scanf("%f", &cocos[id].preco);
		    printf("Dados atualizado com sucesso!\n");

		    printf("\nPressione ENTER para continuar >> ");
		    getchar();
		    getchar(); 

		    limparTerminal();
		    break;

		case 4:
		    printf("Digite a nova Nota do Coconut: ");
		    scanf("%f", &cocos[id].nota);

			while(cocos[id].nota > 5 || cocos[id].nota < 0) {
			printf("Nota inválida! Digite novamente (de 0 até 5): ");
			scanf("%f", &cocos[id].nota);

		    }

		    printf("\nPressione ENTER para continuar >> ");
		    getchar();
		    getchar(); 

		    limparTerminal();
		    break;

		}
	    }
	} 

    else {
	printf("Erro, ID inválido ou nao existe");
	printf("\nPressione ENTER para continuar >> ");
	getchar();
	getchar();
    }
}


// Submenu para editar Coconuts
void menuEditarCocos() {

	printf("|====================================|\n");
	printf("|         EDIÇÃO DE COCONUTS         |\n");
	printf("|====================================|\n");
	printf("|            [1] Tipo                |\n");
	printf("|            [2] País Nativo         |\n");
	printf("|            [3] Preço               |\n");
	printf("|            [4] Nota                |\n");
	printf("|------------------------------------|\n");
	printf("|         [5] Sair do Sistema        |\n");
	printf("|====================================|\n");
	printf(" >>> Qual tópico voce quer editar: ");

}


int main() {

    limparTerminal();
    
    int opcao = 0;
    setlocale(LC_ALL, "Portuguese"); //permite pt_BR

    while ( opcao != 7 ) {

	menuPrincipal();
	scanf("%d", &opcao);

	while ( opcao > 7 || opcao < 1 ) { //verifica a entrada
					
	    printf("\n invalido! tente novamente.\n\n");
	    menuPrincipal();
	    scanf("%d", &opcao);

	}

	switch ( opcao ) {
	    case 1:
	    menuInserirCoco();

	    break;

	    case 2:
	    menuListarCoco();

	    break;

	    case 3:
	    editarCocos();

	    break;

	    case 4:
	    excluirCocos();

	    break;

	    case 5:
	    buscarCocos();

	    break;

	}
    }

    return 0;
}

