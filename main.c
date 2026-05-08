#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//funcoes - Luiz
void clearterminal() {
    system("cls"); //apaga o terminal para usuarios de windows - Luiz
}

void menu() {
    printf("______________________\n");
    printf("|      COCONUTS      |\n");
    printf("|1 - Inserir coco    |\n");
    printf("|2 - Listar cocos    |\n");
    printf("|3 - Buscar coco     |\n");
    printf("|4 - Editar coco     |\n");
    printf("|5 - Excluir coco    |\n");
    printf("|6 - Resumo          |\n");
    printf("|7 - Sair            |\n");
    printf("|____________________|\n");
    printf("Escolha uma opção: ");
}

int main()
{
    int opcao;
    setlocale(LC_ALL, "Portuguese");
    menu();
    scanf("%d", &opcao); //primeiro scanf - Luiz

     //condicão minima pra evitar valores invalidos - Luiz
    if(opcao > 6 || opcao < 1) {
        clearterminal();
        printf("\nEntrada invalida! tente novamente.\n\n");
        menu();
    }
    //faz a validacão das opcoes - Luiz
    while(opcao > 7 || opcao < 1)
    {
        scanf("%d", &opcao);
        clearterminal();
        printf("\nEntrada invalida! tente novamente.\n\n");
        menu();
    }
    return 0;
}
