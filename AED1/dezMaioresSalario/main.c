#include <stdio.h>
#include <stdlib.h>

typedef struct tipoFuncionario{

    char funcao;
    int mat;
    float salario;

}tipoFuncionario;

// Vetor de funcionarios Administrativos
tipoFuncionario funcionariosTodas[2003];

// Compara funcionarios
char compara(tipoFuncionario a, tipoFuncionario b){

    if(a.salario > b.salario){
        return 1;
    }else{
        return 0;
    }

}
// Funcao que intercala os valores
void intercalary(tipoFuncionario als[], int inicio, int meio, int fim, tipoFuncionario aux[], char (*cmp)(tipoFuncionario, tipoFuncionario)){

    int i, j,k=inicio;

    i = inicio;
    j = meio + 1;

    while( (i <= meio) && (j <= fim)){

        if(cmp(als[i],als[j])){
            aux[k] = als[i];
            i++;
        }else{
            aux[k] = als[j];
            j++;
        }

        k++;
    }

    while( i <= meio){
        aux[k] = als[i];
        i++;
        k++;
    }
    while( j <= fim){
        aux[k] = als[j];
        j++;
        k++;
    }

    for(i=inicio; i < k; i++){ als[i] = aux[i];  }

}

void mergeR(tipoFuncionario v[], int inicio, int fim, tipoFuncionario aux[], char (*cmp)(tipoFuncionario, tipoFuncionario)){

    int meio; 
    
    if (inicio < fim){
        meio = (inicio+fim)/2;

        mergeR(v, inicio, meio, aux, cmp);
        mergeR(v, meio+1, fim, aux, cmp);
        intercalary(v,inicio,meio,fim,aux, cmp);

    }

}

void merge(tipoFuncionario als[], int tam, char (*cmp)(tipoFuncionario, tipoFuncionario)){

    tipoFuncionario *aux;

    aux = (tipoFuncionario *) malloc(sizeof(tipoFuncionario)*(tam+2));

    mergeR(als,0,tam-1,aux, cmp);

    free(aux);

}

// Ler inputs
char read(int *tam){

    char funcTmp;
    int matTmp;
    float salTmp;

    scanf("%c%*c", &funcTmp);

    *tam = 0;

    if(funcTmp == 'F') return 0;

    scanf("%d%*c", &matTmp);
    scanf("%f%*c", &salTmp);

    funcionariosTodas[*tam].funcao = funcTmp;
    funcionariosTodas[*tam].mat = matTmp;
    funcionariosTodas[*tam].salario = salTmp;

    *tam = *tam + 1;


    while(1){

        scanf("%c%*c", &funcTmp);
        if(funcTmp == 'F') return 1;
        scanf("%d%*c", &matTmp);
        scanf("%f%*c", &salTmp);

        funcionariosTodas[*tam].funcao = funcTmp;
        funcionariosTodas[*tam].mat = matTmp;
        funcionariosTodas[*tam].salario = salTmp;

        *tam = *tam + 1;

    }
    

}

// Mostra um funciorario
void sfuncion(tipoFuncionario peo){
    printf("{ mat: %d, funcao: %c, salario: %.2f}\n", peo.mat,peo.funcao, peo.salario);
}

// Mostra funciorarios
void showFuncions(tipoFuncionario v[], int n){

    for(int i=0; i < n; i++){
        sfuncion(v[i]);
    }

}

// Pega o maior salario
float getBiggerSal(tipoFuncionario data[], int tam){

    float maior=0.0;

    for(int i=0; i < tam; i++){

        if(data[i].salario > maior){
            maior = data[i].salario;
        }

    }

    return maior;

}

// Mostrar as matriculas com o salario
void showMat(tipoFuncionario data[], int tam){

    int cnt = 0;

    for(int i=0; i < tam; i++){

        printf("%d %.2f\n", data[i].mat, data[i].salario);

        cnt = cnt + 1;

        if(cnt == 10){
            while (data[cnt].salario == data[i].salario)
            {
               printf("%d %.2f\n", data[cnt].mat, data[cnt].salario);
               cnt = cnt + 1;
            }
            return;

        }
    }

}




int main(){
    
    int tam;
    
    read(&tam);

    merge(funcionariosTodas,tam, compara);
    
    showMat(funcionariosTodas,tam);    

}