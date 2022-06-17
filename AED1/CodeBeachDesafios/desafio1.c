#include <stdio.h>

int main(){
	
	int arrayBaguncad[3], i, mediana;
	
	for(i = 0; i < 3; i++){
		
		scanf("%d", &arrayBaguncad[i] );
		
	}
    
    if ( arrayBaguncad[0] > arrayBaguncad[1]){

        if (arrayBaguncad[0] > arrayBaguncad[2]){
            
            if (arrayBaguncad[2] > arrayBaguncad[1]){

                mediana = arrayBaguncad[2];
            }else{
                mediana = arrayBaguncad[1];
            }
        }else{
            mediana = arrayBaguncad[0];
        }
    }else{
        if (arrayBaguncad[1] > arrayBaguncad[2]){

            if (arrayBaguncad[0] > arrayBaguncad[2] ){
                mediana = arrayBaguncad[0];
            }else{
                mediana = arrayBaguncad[2];
            }
        }else{
            mediana = arrayBaguncad[1];
        }
    }
    
	printf("%d", mediana);
	
	return 0;
}