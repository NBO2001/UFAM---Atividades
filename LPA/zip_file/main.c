#include <stdio.h>
#include <stdlib.h>

typedef struct zip_file_hdr zip_file_hdr;

struct zip_file_hdr {
    int signature;
    short version;
    short flags;
    short compression;
    short mod_time;
    short mod_date;
    int crc;
    int compressed_size;
    int uncompressed_size;
    short name_length;
    short extra_field_length;
} __attribute__ ((packed));

long int print_header(zip_file_hdr* file, FILE* arq){

    char* string = malloc(file->name_length+1);

    fread(string, file->name_length, 1, arq);
    string[file->name_length] = '\0';
    
    printf("\t--> Nome do Arquivo: %s\n", string);
    printf("\t--> Tamanho Compactado: %d\n", file->compressed_size);
    printf("\t--> Tamanho Descompactado: %d\n", file->uncompressed_size);

    free(string);

    fseek(arq, file->extra_field_length + file->compressed_size, SEEK_CUR);

}

int main(int argc, char* *argv){

    FILE *zip_file = fopen(argv[1], "rb");
    zip_file_hdr *file_hdr = malloc(sizeof(zip_file_hdr));
    int cont=1;
    unsigned tam=1;
    int signature = 0x04034b50;

    while (tam==1)
    {   
        tam = fread(file_hdr, sizeof(zip_file_hdr), 1, zip_file);

        if(file_hdr->signature == signature){
            printf("Arquivo %d ..\n", cont);

            print_header(file_hdr, zip_file);

            cont++;
        }
        else
            tam = -1;
            
    }

    
}
