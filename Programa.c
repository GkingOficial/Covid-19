#include "./Libs/tree lib/Árvore binária.c"

int main() {
    FILE *file;
    CSV csv;
    BINARY_TREE tree;
    BINARY_TREE *busca;
    char optionUser[30];
    int choice;
    int ordenacao;
    int teveABusca = 0;
    int treeOrdering = 0;

    file = fopen("./Data/amostra de dados.csv", "r");
    setRowsAndColumns(file, &csv);
    readCSV(file, &csv);
    printCSV(csv);
    printf("\n(Digite help para saber mais)\n");

    do {
        printf(">>> ");
        setbuf(stdin, NULL);
        scanf("%[^\n]s", optionUser);
        
        if(strcmp(optionUser, "ordenate") == 0) {
            
            printf("Ordernar por...\n[ 1 ] Quantidade de casos\n[ 2 ] Nível de sedentarismo\n[ 3 ] Qualidade do sono\n[ 4 ] Qualidade da alimentação\n[ 5 ] Qualidade psicológica\n");
            printf("Escolha uma opção: ");
            scanf("%d", &choice);

            if(treeOrdering != choice) {
                generateTree(&tree, &csv, choice);
                treeOrdering = choice;
            }
            teveABusca = 0;
            
            printf("Tipo de ordenação...\n[ 1 ] Crescente\n[ 2 ] Decrescente\nEscolha a opção: ");
            scanf("%d", &ordenacao);
            printTitle(csv);
            if(ordenacao == 1) {
                ascendingOrder(tree);
            } else {
                descendingOrder(tree);
            }
        } else if(strcmp(optionUser, "generate csv file") == 0) {
            char nameOfFile[32];
            printf(">>> Nome do arquivo: ");
            setbuf(stdin, NULL);
            scanf("%31[^\n]s", nameOfFile);

            if(teveABusca) {
                if(generateFromTreeToCSVFile(busca, nameOfFile, 1, csv)) {
                    printf("File created successfully!!!\n");
                }
            } else {
                if(treeOrdering > 0) {
                    if(generateFromTreeToCSVFile(&tree, nameOfFile, ordenacao, csv)) {
                        printf("File created successfully!!!\n");
                    }
                } else {
                    if(generateFromCsvToCSVFile(csv, nameOfFile)) {
                        printf("File created successfully!!!\n");
                    }
                }
            }
        } else if(strcmp(optionUser, "search") == 0) {
            int quantidade;
            
            printf("Procurar com base em...\n[ 1 ] Quantidade de casos\n[ 2 ] Nível de sedentarismo\n[ 3 ] Qualidade do sono\n[ 4 ] Qualidade da alimentação\n[ 5 ] Qualidade psicológica\n");

            printf("Escolha uma opção: ");
            scanf("%d", &choice);

            if(treeOrdering != choice) {
                generateTree(&tree, &csv, choice);
                treeOrdering = choice;
            }
            printf("Quantidade: ");
            scanf("%d", &quantidade);
            
            printTitle(csv);
            busca = buscaNaArvore(&tree, quantidade, choice);
            teveABusca = 1;
            ascendingOrder(*busca);
        } else if(strcmp(optionUser, "help") == 0) {
            printf("\nFunções:\n- ordenate (faz a ordenação crescente ou decrescente dos dados a partir de um campo especificado)\n- generate csv file (gera arquivo csv a partir da última tabela amostrada no programa)\n- search (faz a busca de um determinado valor dentro dos dados a partir de um campo especificado)\n- exit (finaliza o programa)\n- help (amostra todas as funcionalidades do programa)\n\n");
        }
    } while(strcmp(optionUser, "exit"));
    fclose(file);
}
