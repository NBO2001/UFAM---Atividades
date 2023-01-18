#include <stdio.h>
#include "ltrb/typeTree.h"

int main(int argc, char * argv[]){

    typeTreeRedAndBlack * tree = newTreeRB();

    int tmp, rt;

    for(int i=0; i < 4; i++){

        scanf("%d", &tmp);
        insertTreeRB(tree,tmp);

    }

    while (scanf("%d", &tmp) == 1){
        rt = searchTreeRB(tree, tmp);

        if(rt >= 0){
            printf("%d\n", rt);
        }else{
            printf("N achei\n");
        }
    }
    

}
