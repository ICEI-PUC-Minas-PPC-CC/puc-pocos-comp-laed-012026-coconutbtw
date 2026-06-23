
/*
PROJETO: Avaliação e Listagem de Coconuts
PARTICIPANTES: Jorge Luis de Freitas Junior & Luiz Gustavo Ferreira Junior
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Função que limpa o terminal
void limparTerminal()
{
    system("cls || clear");
}

// registro 
struct Coco 
{
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
 
void menuPrincipal()
{
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

void menuInserirCoco() {

    int indiceVazio = -1;
    int i;

    for ( i = 0; i < 10; i++ ) {
    if ( cocos[i].ativo == 0 ) {
        indiceVazio = i;
        break;
         }
    }

    if ( indiceVazio == -1 ) {
        printf("Não é possível registrar mais de 10 Coconuts. O sistema está cheio!\n");
        printf("\nPressione ENTER para continuar >> ");
        getchar();
        getchar();
        return;
    }

    limparTerminal();
    printf("|============================================|\n");
    printf("|        MENU DE INSERÇÃO DE COCONUTS        |\n");
    printf("|============================================|\n");

    printf("Tipo do Coco: ");
    scanf(" %[^\n]", cocos[quantidade].tipo); //tipo 
    
    printf("País nativo do Coco: ");
    scanf(" %[^\n]", cocos[quantidade].pais); //pais

    printf("Preço do Coco: ");
    scanf("%f", &cocos[quantidade].preco); //preco

    printf("Nota do Coco (de 0 até 5): "); //nota
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


// menu de listagem
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
    for ( indice = 0; indice < quantidade; indice++ ) 
    { //entra na estrutura de repeticao parte q toma conta dos indices
        if (cocos[indice].ativo == 1) //toma conta dos cocos ativos ou excluidos
        {
        limparTerminal();
	    printf("\nLista de Coconuts  \n\n");
	    printf("ID: %d\n", indice);
	    printf("Tipo: %s\n", cocos[indice].tipo);
	    printf("País: %s\n", cocos[indice].pais);
	    printf("Preço: R$%.2f \n", cocos[indice].preco);
	    printf("Nota (0-5): %.1f\n", cocos[indice].nota);

        printf("Pressione ENTER para continuar>");
    
        getchar();
        getchar();
	    }
    } 
    limparTerminal();
}

int id;
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

void resumoCocos() {

    limparTerminal();

    if ( quantidade == 0 ) {
        printf("Nenhum coco foi cadastrado ainda.\n");
        printf("\nPressione ENTER para continuar >> ");
        getchar();
        getchar();
        return;
    }

    int i;
    int totalAtivos = 0;
    float somaPrecos = 0;
    float somaNotas = 0;
    int idMaisCaro = -1, idMaisBarato = -1;
    int idMelhorNota = -1, idPiorNota = -1;

    for ( i = 0; i < quantidade; i++ ) {

        if ( cocos[i].ativo == 1 ) 
        {
            totalAtivos++;
            somaPrecos += cocos[i].preco;
            somaNotas += cocos[i].nota;
        }
}

    if(totalAtivos==0)
{
        printf("Nenhum coco ativo no momento (todos foram excluidos).\n");           printf("\nPressione ENTER para continuar >> ");
        getchar();
        getchar();
        return;
}
    printf("|====================================|\n");
    printf("|       RESUMO / ESTATISTICAS         |\n");
    printf("|====================================|\n");
    printf("Total de Coconuts ativos: %d\n", totalAtivos);
    printf("Preco medio: R$%.2f\n", somaPrecos / totalAtivos);
    printf("Nota media: %.1f\n", somaNotas / totalAtivos);
    printf("|====================================|\n");
    printf("\nPressione ENTER para continuar >> ");
    getchar();
    getchar();

    limparTerminal();
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

        case 6:
        resumoCocos();
        break;

	}
    }

    return 0;
}
