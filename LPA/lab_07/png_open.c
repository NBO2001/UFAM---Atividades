#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

typedef struct type_header type_header;
typedef struct type_ihdr type_ihdr;

struct type_header{

    int length;
    char chuck_type[4];

}__attribute__((packed));

struct type_ihdr{
    int width;
    int heigth;
    char bit_depth;
    char colour_type;
    char compression_method;
    char filter_method;
    char interlace_method;
    int crc;
}__attribute__((packed));

int print_ihdr(type_header* header, FILE* file){
    
    int status = 1;

    type_ihdr* ihdr = malloc(sizeof(type_ihdr));

    int read_tol;

    if(ihdr){
        read_tol = fread(ihdr, sizeof(type_ihdr), 1, file);
    }else{
        read_tol = 0;
        status = -1; // -1 para falta de memoria
    }


    if(read_tol == 1){
        printf("\t--> Largura:\t%d\n", ntohl(ihdr->width) );
        printf("\t--> Altura:\t%d\n", ntohl(ihdr->heigth)); 
    }else{
        if(status == 1){
            status = 0; // Erro de leitura
        }
    }

    if(ihdr){
        free(ihdr);
    }

    return status;
}

int main(int argc, char* *argv){

    char signature[8] = "\x89\x50\x4E\x47\x0D\x0A\x1A\x0A";
    char signature_read[8];
    char types[7][5] = {"IHDR", "PLTE", "IDAT", "IEND", "bKGD", "tEXt", "tIME"};
    FILE* file = fopen(argv[1], "r");

    int read_tol = fread(signature_read,sizeof(signature_read),1, file);

    int resultCmp = memcmp(signature,signature_read, sizeof(signature_read));

    if(resultCmp != 0) return 0;
    int cont = 1;
    int flag = 1;
    while (flag && !feof(file))
    {
        type_header* header = malloc(sizeof(type_header));
        read_tol = fread(header, sizeof(type_header), 1, file);
        header->length = ntohl(header->length);

        if(read_tol == 1){

            printf("Lendo chunk %d:\n", cont);
            printf("    --> Tamanho:\t%d\n", header->length);
            printf("    --> Type:\t%s\n", header->chuck_type);

            if(memcmp(header->chuck_type, types[0], sizeof(header->chuck_type)) == 0){
                print_ihdr(header,file);
            }else if(memcmp(header->chuck_type, types[3], sizeof(header->chuck_type)) == 0){
                flag = 0;
            }
            else{
                fseek(file, header->length + sizeof(int), SEEK_CUR);
            }

        }

        free(header);
        
        cont++;
    }
    

    fclose(file);
}