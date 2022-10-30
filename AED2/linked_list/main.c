#include <stdio.h>
#include <string.h>
#include "linked_list.h"


int last_id(typeList * list){

    typeData * dat;

    int last;

    dat = last_element(list);

    if(dat){
        last = dat->id;

        return last;
    }else{
        return 0;
    }
}

void read_register(typeData * data){

    printf("Name: ");
    scanf("%[^\n]%*c", data->name);

    printf("Age: ");
    scanf("%d%*c", &data->age);

}

void showOp(){
    printf("1 - Adicionar valor\n");
    printf("2 - Ver valores\n");
    printf("3 - Pesquisar usuario\n");
    printf("4 - Remover usuario\n");
    printf("0 - Finalizar\n");
}


int main(int argc, char * argv[]){
    
    typeData dat, * tmpAux;
    typeList list;
    int flag, id;

    create(&list);

    showOp();
    
    scanf("%d%*c", &flag);

    while (flag != 0)
    {
        switch(flag){
            case 1:

                read_register(&dat);

                dat.id = last_id(&list) + 1;

                insert_end(&list,&dat);

                break;

            case 2:
                showDatas(&list);
                break;

            case 3:
            
                scanf("%d", &id);
                tmpAux = seach_in_list(&list, id);
                show_datum(tmpAux);
                break;

            case 4:
            
                scanf("%d", &id);
                dat = remove_with_key(&list, id);
                printf("Registro removido\n");
                break;
            default:
                break;
        }
        
        
        showOp();
        scanf("%d%*c", &flag);

    }
    
   

}