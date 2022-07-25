#include <stdio.h>
#include <stdlib.h>

typedef struct tipoFuncionario{

    char funcao;
    int mat;
    float salario;

}tipoFuncionario;

tipoFuncionario funcionariosAdm[2003];
tipoFuncionario funcionariosNAdm[2003];

// Comara funcionarios
char compara(tipoFuncionario a, tipoFuncionario b){

    if(a.salario < b.salario){
        return 1;
    }else{
        return 0;
    }

}
// Funcao que intercala os valores
void intercalary(tipoFuncionario als[], int inicio, int meio, int fim, tipoFuncionario aux[]){

    int i, j,k=inicio;

    i = inicio;
    j = meio + 1;

    while( (i <= meio) && (j <= fim)){

        if(compara(als[i],als[j])){
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

void mergeR(tipoFuncionario v[], int inicio, int fim, tipoFuncionario aux[]){

    int meio; 
    
    if (inicio < fim){
        meio = (inicio+fim)/2;

        mergeR(v, inicio, meio, aux);
        mergeR(v, meio+1, fim, aux);
        intercalary(v,inicio,meio,fim,aux);

    }

}

void merge(tipoFuncionario als[], int tam){

    tipoFuncionario *aux;

    aux = (tipoFuncionario *) malloc(sizeof(tipoFuncionario)*(tam+2));

    mergeR(als,0,tam-1,aux);

}

// Ler inputs
char read(int *tamAdm,int *tamNAdm){

    char funcTmp;
    int matTmp;
    float salTmp;

    scanf("%c ", &funcTmp);

    *tamAdm = 0;
    *tamNAdm = 0;

    if(funcTmp == 'F') return 0;

    scanf("%d ", &matTmp);
    scanf("%f ", &salTmp);

    if(funcTmp == 'A'){
        funcionariosAdm[*tamAdm].funcao = funcTmp;
        funcionariosAdm[*tamAdm].mat = matTmp;
        funcionariosAdm[*tamAdm].salario = salTmp;

        *tamAdm = *tamAdm + 1;
    }

    if(funcTmp == 'N'){
        funcionariosNAdm[*tamNAdm].funcao = funcTmp;
        funcionariosNAdm[*tamNAdm].mat = matTmp;
        funcionariosNAdm[*tamNAdm].salario = salTmp;

        *tamNAdm = *tamNAdm + 1;

    }

    while(1){
        scanf("%c ", &funcTmp);
        if(funcTmp == 'F') return 1;
        scanf("%d ", &matTmp);
        scanf("%f ", &salTmp);

        if(funcTmp == 'A'){
            funcionariosAdm[*tamAdm].funcao = funcTmp;
            funcionariosAdm[*tamAdm].mat = matTmp;
            funcionariosAdm[*tamAdm].salario = salTmp;

            *tamAdm = *tamAdm + 1;
        }

        if(funcTmp == 'N'){
            funcionariosNAdm[*tamNAdm].funcao = funcTmp;
            funcionariosNAdm[*tamNAdm].mat = matTmp;
            funcionariosNAdm[*tamNAdm].salario = salTmp;
            
            *tamNAdm = *tamNAdm + 1;

        }


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

void printCargo(char cargo){
    if(cargo == 'A'){
        printf("Administrativo:\n");
    }else{
        printf("N Administrativo:\n");
    }
}

void mostraMediana(tipoFuncionario v[], int tam){

    if((tam%2)==1){
        printCargo(v[tam/2].funcao);
        printf("%.2f \n", v[tam/2].salario);
    }else{
        if(tam != 0){
            printCargo(v[tam/2].funcao);
            printf("%.2f \n", v[tam/2].salario);
            printf("%.2f \n", v[(tam/2)-1].salario);
        }
    }    

}

int main(){
    
    int tamADM, tamNADM;

    read(&tamADM, &tamNADM);
    
    merge(funcionariosAdm,tamADM);
    
    mostraMediana(funcionariosAdm,tamADM);
    

    //showFuncions(funcionariosNAdm,tamNADM);
    merge(funcionariosNAdm,tamNADM);
    mostraMediana(funcionariosNAdm,tamNADM);

}