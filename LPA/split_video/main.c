#include "stdio.h"
#include "stdlib.h"
#include <string.h>

int main(int argc, char* argv[]){

    if (argc != 3) {
        fprintf(stderr, "Uso: %s <arquivo_origem> <tamanho_maximo_MB>\n", argv[0]);
        return 1;
    }
    
    char fileName[50];
    int video_index = 1;
    unsigned int index = 0;
    int lastSequence = 0;
    unsigned char prefixCode[4] = {0x00, 0x00, 0x01,0xb3};
    unsigned int readTol;
    unsigned int maxTam = atoi(argv[2]) * 1048576;
    unsigned int buffer_tam =  maxTam + 50000;
    unsigned char* buffer = (unsigned char*)malloc(buffer_tam);
    unsigned long int buffer_size=0;

  
    sprintf(fileName,"video_parte_%d.mpg", video_index);
    FILE* mpg_file = fopen(argv[1], "rb");

    printf("Criando arquivo %s ..\n", fileName);
    FILE* copy_file = fopen(fileName, "wb");

    buffer_size = fread(buffer, 1, buffer_tam, mpg_file);

    int resul = memcmp(prefixCode, buffer + index, sizeof(prefixCode));

    while (index < buffer_size){
        
        if(resul == 0){

            if(index <= maxTam){
                
                lastSequence = index;
                index += 4;

            }else{
                
                fwrite(buffer, 1, lastSequence, copy_file);
                fclose(copy_file);
                
                video_index++;
                sprintf(fileName,"video_parte_%d.mpg", video_index);
                printf("Criando arquivo %s ..\n", fileName);
                copy_file = fopen(fileName, "wb");

                int tmp = buffer_size-lastSequence;
                
                memcpy(buffer,buffer+lastSequence-1, tmp);
                
                int rest = buffer_tam - tmp;

                buffer_size = fread(buffer+tmp, 1, rest, mpg_file);
                
                buffer_size += tmp;
                index = 0;
                lastSequence = 0;

            }
                
        }else{
            index += 1;
            resul = memcmp(prefixCode,buffer+index, sizeof(prefixCode));
        }

    }

    fwrite(buffer, 1, lastSequence, copy_file);
    fclose(copy_file);
    fclose(mpg_file);
    free(buffer);
    
}