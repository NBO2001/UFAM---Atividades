#include <stdio.h>
#include <stdlib.h>

typedef struct tipoFuncionario{

    char funcao;
    int mat;
    float salario;

}tipoFuncionario;

// Vetor de funcionarios Administrativos
tipoFuncionario funcionariosAdm[2003];
// Vetor de funcionarios Nao Administrativos
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
char read(int *tamAdm,int *tamNAdm){

    char funcTmp;
    int matTmp;
    float salTmp;

    scanf("%c%*c", &funcTmp);

    *tamAdm = 0;
    *tamNAdm = 0;

    if(funcTmp == 'F') return 0;

    scanf("%d%*c", &matTmp);
    scanf("%f%*c", &salTmp);

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
        scanf("%c%*c", &funcTmp);
        if(funcTmp == 'F') return 1;
        scanf("%d%*c", &matTmp);
        scanf("%f%*c", &salTmp);

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
void showMat(tipoFuncionario data[], int tam, float salario){

    for(int i=0; i < tam; i++){

        if(data[i].salario == salario){
            printf("%d\n", data[i].mat);
        }

    }

}

// Mostra mediana
void mostraMediana(tipoFuncionario v[], int tam){

    // Ser for uma tamanho impar, mostra o meio;
     if(tam==0){
            printf("%.2f\n",0.0);
            return;
    }
    if((tam%2)==1){   
        printf("%.2f\n", v[tam/2].salario);
    }else{
        // Se for par, mostra o meio e o anterio ao meio, desde que sejam diferentes.
         if(tam==0){
                printf("%.2f\n",0.0);
                return;
        }

        if(tam != 0){
            
            if(v[tam/2].salario != v[(tam/2)-1].salario){

                printf("%.2f\n", v[(tam/2)-1].salario);
                printf("%.2f\n", v[tam/2].salario);
            }else{
                printf("%.2f\n", v[tam/2].salario);
            }
        }
    }    

}


int main(){
    
    int tamADM, tamNADM;
    float tmp;
    read(&tamADM, &tamNADM);

    merge(funcionariosAdm,tamADM, compara);
    
    tmp = getBiggerSal(funcionariosAdm, tamADM);

    printf("Administrativo: %.2f\n", tmp);
    
    showMat(funcionariosAdm, tamADM, tmp);
    
    merge(funcionariosNAdm,tamNADM, compara);
    
    tmp = getBiggerSal(funcionariosNAdm, tamNADM);

    printf("N Administrativo: %.2f\n", tmp);

    showMat(funcionariosNAdm, tamNADM, tmp);

}