#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct coconuts {
    int precoCoconut;
    int notaCoconut;
    char nomeCoconut[50];
    char regiaoCoconut[50];
};


int main() {

    // Sessão de variaveis
    int opcao;

    // Setar compatibilidade com a língua portuguesa.
    setlocale(LC_ALL, "Portuguese");

    
    do {
	// Menu
	printf("|======================|\n");
	printf("|     COCONUT MENU     |\n");
	printf("|======================|\n");
	printf("| 1. Listar Coconuts   |\n");
	printf("| 2. Adicionar Coconut |\n");
	printf("| 3. Deletar Coconut   |\n");
	printf("| 4. Avaliar Coconut   |\n");
	printf("|----------------------|\n");
	printf("| 0. Sair do Programa  |\n");
	printf("|======================|\n");
	printf(" Selecione a opção: ");
	scanf("%d", &opcao);

	// Opções do Menu
	switch (opcao) {
	    case 1:
		printf("\nListagem de coconuts\n\n");
		break;

	    case 2:
		printf("\nAdionando Coconut\n\n");
		break;

	    case 3:
		printf("\nDeletando Coconut\n\n");
		break;

	    case 4:
		printf("\nAvaliando Coconut\n\n");
		break;

	    case 0:
		printf("\nSaindo...\n\n");
		break;

	    default:
		printf("\nOpção invalida. Tente novamente\n\n");

	}
    // Enquanto o usuário não digitar 0, continua o menu.
    } while ( opcao != 0 );


    return 0;
}
