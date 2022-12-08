#include "Dicionario/Dicionario.h"

void Explicacao(){
    printf("\n# Caso o arquivo esteja na mesma pasta que o programa:\n\t-Digite o nome.");
    printf("\n# Caso esteja em uma outra pasta junto com o programa:\n\t-Digite a pasta/nome do arquivo.");
    printf("\n# Caso esteja em uma pasta fora do programa:\n\t-Digite [../] para cada vez que o programa precise sair da sua pasta para a desejada e o nome do arquivo.\n");
}
int Verifica_arquivo(FILE* text){
    if((text)==NULL){
        printf("\n\t@@@@@ Erro na abertura do arquivo @@@@@@\n\n");
        printf("\n********************************************************************************************************************************\n");         
        return 0;
    }
    else{
        //system("clear");
        printf("\n********************************************************************************************************************************\n");
        printf("\n**************************************     DICIONARIO DO ARQUIVO    ************************************************************\n");
        printf("\n********************************************************************************************************************************\n");      
        return 1;
    }
}
int Opcoes1(){
    int a;
    printf("\n\t[1]-Substituir arquivo\n\t[2]-Exibir dicionario completo\n\t[3]-Exibir determinada lista de palavras\n\t[4]-Exibir linhas de ocorrencia de uma palavra\n\t[5]-Remover palavra\n\t[6]-Remove final de uma lista\n\t[7]-Exibir quantidade de palavras com determinada letra\n\t[8]-Exibir quantidade de palavras no dicionario\n\t[9]-Sair\n\t");
    scanf("%d",&a);
    return a;
}
int Opcoes2(){
    int b;
    printf("\n[1]-Adicionar arquivo\n[2]-Sair\n");
    scanf("%d",&b);
    return b;
}
int Opcoes3(){
    int c;
    printf("\n[1]-Exibir linhas\n[2]-Nao Exibir linhas\n");
    scanf("%d",&c);
    return c;
}
int Termina(){
    printf("\n**********************************************************************************************************************************\n");
    printf("**********************************************************************************************************************************\n");
    printf("**********************************************************************************************************************************\n");
    return 0;
}
int main(){
    FILE *arquivo;
    int choice=0,termina=1,aceito=0;
    int n;
    char letra, palavra[50];
    char nome_arq[100];
    Dicionario dicionario;
    do{
        switch (choice){
             //Le o nome do arquivo //
            case 1:
                Cria_Dicionario(&dicionario);
                Explicacao();
                printf("\n# Digite o nome do arquivo/caminho: ");
                //Entrando com o arquivo
                fscanf(stdin, "%s", nome_arq); 
                //Abrindo o arquivo//
                arquivo=fopen(nome_arq, "r");
                aceito=Verifica_arquivo(arquivo);
                choice=aceito;
                fflush(arquivo);
                if(aceito)
                    Constroi_Dicionario(&dicionario, arquivo);
                break;
            //Mostra todas as palavras do dicionario//
            case 2:
                n = Opcoes3();
                Ordenacao_Dicionario(&dicionario, n);
                break;
            //Mostra todas as palavras que comecam com uma letra especifica//
            case 3:
                n = Opcoes3();
                printf("\n\t# Digite a letra: ");
                getchar();
                scanf("%c", &letra);
                Imprime_Lista(&dicionario, letra, n);
                break;
            //Mostra todas as linhas que determinada palavra aparece no texto//
            case 4:
                getchar();
                printf("\n\t# Digite uma palavra: ");
                scanf("%s",&palavra);
                Imprime_Linhas(&dicionario, palavra);
                break;
            //Remove palavra//
            case 5:
                getchar();
                printf("\n\t# Digite uma palavra: ");
                scanf("%s",&palavra);
                n = Verifica_Dicionario(&dicionario, palavra[0]);
                if(n!=-1) Remove_Palavra(&(dicionario.dicionario[n]), palavra);
                break;
            //Remove palavra do final//
            case 6:
                getchar();
                printf("\n\t# Digite uma letra: ");
                scanf("%c",&letra);
                n = Verifica_Dicionario(&dicionario, letra);
                if(n!=-1) Remove_Palavra_Final(&(dicionario.dicionario[n]));
                else printf("@@@@ Lista de palavras nao encontrada @@@@\n");
                break;
            //Mostra a quantidade de palavras de uma lista//
            case 7:
                getchar();
                printf("\n\t# Digite uma letra: ");
                scanf("%c",&letra);
                n = Verifica_Dicionario(&dicionario, letra);
                if(n!=-1) printf("# Quantidade de palavras com %c: %d", letra, Tamanho_Lista(&(dicionario.dicionario[n])));
                else printf("@@@@ Lista de palavras nao encontrada @@@@\n");
                break;
            //Mostra a quantidade de palavras do dicioanrio//
            case 8:
                printf("\n# Quantidade de palavras no dicionario: %d\n",Tamanho_Dicionario(&dicionario));
                 break;
            //Sai do dicionario//
            case 9:
                termina=Termina();
                break;
            //Volta pro comeco//
            default:
                if(Opcoes2()==1)
                    choice=1;
                else
                    choice=9;
                break;
        } 
        if(termina&&aceito){
            //Opcoes de operacoes com dicionario para o usuario//
            choice=Opcoes1();
        }
     }while(termina);
     return 0;
}