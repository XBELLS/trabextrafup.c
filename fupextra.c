#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 int comparar(char *a, char *b){
     int tamA = strlen(a);
     int tamB = strlen(b);
     
     if(tamA>tamB){
        return 1;
     }
     else if(tamA<tamB){
         return -1;
     }
     else{
         for(int i=0; i<tamA; i++){
             if(a[i] > b[i]){
                 return 1;
             }
             if(a[i] < b[i]){
                 return -1;
             }
             }
             return 0;
         }
     }
     
    char *soma(char *a, char *b){
    int tamA = strlen(a);
    int tamB = strlen(b);
    
    int digA; //esses dois sao pra evitar que ao percorrer o indice na soma,
    //se um numero for menor que o outro, o indice nao chege à -1.
    int digB; 
    
    
    int maiorTam; //variavel para qual o maior tamanho
    
    
    int i = tamA - 1;
    int j = tamB - 1; //qtde de indice
    int vaiUm = 0; //vai um da soma
    int somaAtual;
    int digResult;
    
    
    //verifica qual o maior tamanho e atribui à variavel maiorTam
    if(tamA>tamB){
        maiorTam = tamA;
    }else{
        maiorTam = tamB;
    }
    
    char *resultado = (char*) malloc(maiorTam + 2); //resultado ocupa + 1 caractere, + 1 com o \0
    int k = maiorTam; //qtde de indices do resultado
    
    resultado[maiorTam + 1] = '\0'; 
    
    while(i >= 0 || j >= 0){
        if(i >=0 ){ //verifica que o indice nao fica - 1
            digA = a[i] - '0';
        }
        else{
            digA = 0;
        }
        
        if(j >= 0){
            digB = b[j] - '0';
        }
        else{
            digB = 0;
        }
        
        somaAtual = digA + digB + vaiUm;
        
        
        digResult = somaAtual % 10; //usa o %10 porque pega o resto, o ultimo numero
        vaiUm = somaAtual / 10; //usa o /10 pq pega o primeiro numero do resultado
        
        
        resultado[k] = digResult + '0';
        
        i--;
        j--;
        k--;
    }
    //verifica se sobrou algum numero pra adicionar na prox coluna 
    if(vaiUm > 0){
        resultado[0] = vaiUm + '0';
        return resultado;
    }
    else{
        return &resultado[1];
    }

}

    char *subtracao(char *a, char *b){
    int comp = comparar(a, b);

    if(comp == 0){
        char *resultado = (char*) malloc(2);
        resultado[0] = '0';
        resultado[1] = '\0';
        return resultado;
    }

    char *maior;
    char *menor;
    int negativo = 0;

    if(comp == 1){
        maior = a;
        menor = b;
    }
    else{
        maior = b;
        menor = a;
        negativo = 1;
    }

    int tamMaior = strlen(maior);
    int tamMenor = strlen(menor);

    char *resultado = (char*) malloc(tamMaior + 2);

    int i = tamMaior - 1;
    int j = tamMenor - 1;
    int k = tamMaior - 1;

    int emprestimo = 0;
    int digMaior;
    int digMenor;
    int subAtual;

    resultado[tamMaior] = '\0';

    while(i >= 0){

        if(i >= 0){
            digMaior = maior[i] - '0';
        }else{
            digMaior = 0;
        }

        if(j >= 0){
            digMenor = menor[j] - '0';
        }else{
            digMenor = 0;
        }

        subAtual = digMaior - digMenor - emprestimo;

        if(subAtual < 0){
            subAtual += 10;
            emprestimo = 1;
        }else{
            emprestimo = 0;
        }

        resultado[k] = subAtual + '0';

        i--;
        j--;
        k--;
    }

    int inicio = 0;

    while(resultado[inicio] == '0' && resultado[inicio + 1] != '\0'){
        inicio++;
    }

    if(negativo){

        int tamanho = strlen(&resultado[inicio]);

        char *final = (char*) malloc(tamanho + 2);

        final[0] = '-';

        for(int x = 0; x <= tamanho; x++){
            final[x + 1] = resultado[inicio + x];
        }

        free(resultado);

        return final;
    }

    return &resultado[inicio];
}

char *multiplicacao(char *a, char *b){


int negativo = 0;

if(a[0] == '-' && b[0] == '-'){
    a++;
    b++;
}
else if(a[0] == '-'){
    negativo = 1;
    a++;
}
else if(b[0] == '-'){
    negativo = 1;
    b++;
}

char *resultado = "0";

char contador[10000] = "0";

while(comparar(contador, b) == -1){

    resultado = soma(resultado, a);

    char *novoContador = soma(contador, "1");

    strcpy(contador, novoContador);
}

if(negativo){

    int tam = strlen(resultado);

    char *final = (char*) malloc(tam + 2);

    final[0] = '-';

    strcpy(final + 1, resultado);

    return final;
}

return resultado;
}
 
    char *divisao(char *a, char *b){


if(comparar(b, "0") == 0){
    return "Erro";
}

char *quociente = "0";

while(comparar(a, b) >= 0){

    a = subtracao(a, b);

    quociente = soma(quociente, "1");
}

return quociente;

}

    
    char *exponenciacao(char *base, char *expoente){

    char *resultado = "1";
    char contador[10000] = "0";
    
    if(expoente[0] == '-'){
    return "Expoente negativo nao suportado";
    }
    
    while(comparar(contador, expoente) == -1){

    resultado = multiplicacao(resultado, base);

    char *novoContador = soma(contador, "1");

    strcpy(contador, novoContador);
    }
    
    return resultado;

    }
    
    
    
    char *fatorial(char *n){

    if(comparar(n, "0") == 0){
    return "1";
}

char *resultado = "1";

while(comparar(n, "1") == 1){

    resultado = multiplicacao(resultado, n);

    n = subtracao(n, "1");
}

resultado = multiplicacao(resultado, "1");

return resultado;
        
    }

int main(){
char a[10000];
char b[10000];
int opcao;


do{
    printf("\n===== CALCULADORA =====\n");
    printf("1 - Soma\n");
    printf("2 - Subtracao\n");
    printf("3 - Multiplicacao\n");
    printf("4 - Divisao\n");
    printf("5 - Exponenciacao\n");
    printf("6 - Fatorial\n");
    printf("0 - Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    switch(opcao){

        case 1:
            printf("Digite o primeiro numero: ");
            scanf("%s", a);

            printf("Digite o segundo numero: ");
            scanf("%s", b);

            printf("Resultado: %s\n", soma(a, b));
            break;

        case 2:
            printf("Digite o primeiro numero: ");
            scanf("%s", a);

            printf("Digite o segundo numero: ");
            scanf("%s", b);

            printf("Resultado: %s\n", subtracao(a, b));
            break;

        case 3:
            printf("Digite o primeiro numero: ");
            scanf("%s", a);

            printf("Digite o segundo numero: ");
            scanf("%s", b);

            printf("Resultado: %s\n", multiplicacao(a, b));
            break;

        case 4:
            printf("Digite o dividendo: ");
            scanf("%s", a);

            printf("Digite o divisor: ");
            scanf("%s", b);

            printf("Resultado: %s\n", divisao(a, b));
            break;

        case 5:
            printf("Digite a base: ");
            scanf("%s", a);

            printf("Digite o expoente: ");
            scanf("%s", b);

            printf("Resultado: %s\n", exponenciacao(a, b));
            break;

        case 6:
            printf("Digite o numero: ");
            scanf("%s", a);

            printf("Resultado: %s\n", fatorial(a));
            break;

        case 0:
            printf("Encerrando...\n");
            break;

        default:
            printf("Opcao invalida!\n");
    }

}while(opcao != 0);

return 0;


}
