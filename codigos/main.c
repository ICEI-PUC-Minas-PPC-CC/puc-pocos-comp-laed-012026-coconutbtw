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
    int qualidade;

    char tipo[35];
    char pais[15];
    char regiao[15];
    
    float preco;
    float nota;

};

// Capacidade de Armazenar 10 Cocos e Indice e Contador dos Coconuts
struct Coco cocos[10];
int quantidade = 0;


// Menu Principal
void menuPrincipal() {
    printf("|=============================================|\n");
    printf("|              SISTEMA DE COCOS               |\n");
    printf("|=============================================|\n");
    printf("|            [1] Inserir Registro             |\n");
    printf("|            [2] Listar Todos                 |\n");
    printf("|            [3] Editar Registro              |\n");
    printf("|            [4] Excluir Registro             |\n");
    printf("|            [5] Buscar por Filtro            |\n");
    printf("|            [6] Resumo Geral                 |\n");
    printf("|---------------------------------------------|\n");
    printf("|            [7] Sair do Sistema              |\n");
    printf("|=============================================|\n");
    printf(" >> Escolha uma opção: ");
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
    printf("Digite a espécie do Coco: ");
    scanf("%s", cocos[quantidade].tipo);

    // Registro do País Nativo
    printf("Digite o país nativo do Coco: ");
    scanf("%s", cocos[quantidade].pais);

    // Registro da Região
    printf("Digite a região do país nativo do Coco: ");
    scanf("%s", cocos[quantidade].regiao);

    // Registro do Preço
    printf("Digite o preço do Coco: ");
    scanf("%f", &cocos[quantidade].preco);

    // Registro da Nota
    printf("Qual a nota do Coco (de 0 até 5): ");
    scanf("%f", &cocos[quantidade].nota);

    // Registro Binário
    printf("O coco é bom? (1-Sim | 0-Não): ");
    scanf("%d", &cocos[quantidade].qualidade);

    // Salva o ID de acordo com a Posição do Indice
    quantidade++;
    
    printf("Coco Cadastrado com sucesso!\n\n");
}

// Menu de Listagem dos Coconuts
void menuListarCoco() {

    // Verificar se algum coco foi cadastrado
    if ( quantidade == 0 ) {
	limparTerminal();

	printf("\nNenhum coco foi cadastrado ainda.\n");
	printf("\nPressione ENTER para continuar >> ");

	getchar();  // Ele aguarda uma entrada mas não armazena nada pra gente
	getchar();  // E são necessarios dois por causa do quebra linha

	limparTerminal();
	return;
    }             


    int indice;

    for ( indice = 0; indice < quantidade; indice++ ) {

	limparTerminal();

	printf("\n  Lista de Coconuts  \n\n");
	printf("ID: %d\n", indice);
	printf("Tipo: %s\n", cocos[indice].tipo);
	printf("País: %s\n", cocos[indice].pais);
	printf("Região: %s\n", cocos[indice].regiao);
	printf("Preço: R$%.2f \n", cocos[indice].preco);
	printf("Nota: %.1f\n", cocos[indice].nota);
	printf("Qualidade (0-5): %d/5\n\n", cocos[indice].qualidade);
	printf("Pressione ENTER para continuar >> ");

	getchar();
	getchar();

	limparTerminal();

	}
}


int main() {

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
	    menuInserirCoco(); //caso 1 ele entra na funcão inserir

	    break;

	    case 2:
	    menuListarCoco();

	    break;

	}
    }

    return 0;
}


