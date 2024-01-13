#include "stdio.h"
#include "stdlib.h"
#include <string.h>

void readSequence(FILE* file, unsigned char byteOld){

        unsigned char byte1 = fgetc(file);
        unsigned char byte2 = fgetc(file);
        unsigned char byte3 = fgetc(file);

        unsigned int largura = byte1 * 16 + (byte2 >> 4);
        unsigned int altura = ( byte2 & 0x0F) * 256 + byte3;
        unsigned int frame_rate = byteOld & 0x0f;

        char frames[8][10] = {"23.976fps", "24.000fps", "25.000fps", "29.970fps","29.970fps", "50.000fps", "59.940fps", "60.000fps"};
        printf("--> Código: %.2x -- Sequence Header -- Width = %d, Height = %d -- Frame rate = %s\n", byteOld, largura, altura, frames[frame_rate-1]);
}

void readSystem(FILE* file, unsigned char byteOld){

    printf("--> Código: %.2x -- System\n", byteOld);
}

void readPicture(FILE* file, unsigned char byteOld){
    unsigned char byte0 = fgetc(file);
    unsigned char byte1 = fgetc(file);

    unsigned char type_tmp = byte1 >> 3;
    unsigned char type = type_tmp & 0x07;

    char types[] = {'I','P','B'};
    printf("--> Código: 00 -- Picture -- Tipo = %c\n",types[type-1]);
    
}

void readGroupofPictures(FILE* file, unsigned char byteOld){
    printf("--> Código: b8 -- Group of Pictures\n");
}

void readSlice(FILE* file, unsigned char byteOld){
    printf("--> Código: %.2x -- Slice\n", byteOld);
}

void readPacketVideo(FILE* file, unsigned char byteOld){
    printf("--> Código: %.2x -- Packet Video\n", byteOld);
}

void readPacketAudio(FILE* file, unsigned char byteOld){
    printf("--> Código: %.2x -- Packet Audio\n", byteOld);
}

int main(int argc, char* argv[]){

    FILE* mpg_file = fopen(argv[1], "r");
    unsigned char prefixCode[4] = {0x00, 0x00, 0x01, '\0'};
    unsigned char readBytes[4] = {0x00, 0x00, 0x01, '\0'};

    readBytes[0] = fgetc(mpg_file);
    readBytes[1] = fgetc(mpg_file);
    readBytes[2] = fgetc(mpg_file);

    int resul = memcmp(prefixCode,readBytes, sizeof(prefixCode));

    while (!feof(mpg_file))
    {

        
        if(resul == 0){

            unsigned char byte4 = fgetc(mpg_file);

            if(byte4 == 0xb3){
                readSequence(mpg_file,byte4);
            }else if(byte4 == 0xbb){
                readSystem(mpg_file,byte4);
            }else if(byte4 == 0x00){
                readPicture(mpg_file,byte4);
            }else if(byte4 == 0xb8){
                readGroupofPictures(mpg_file,byte4);
            }
            else if(byte4 >= 0x01 && byte4 <= 0xAF){
                readSlice(mpg_file,byte4);
            }
            else if(byte4 >= 0xc0 && byte4 <= 0xdf){
                readPacketVideo(mpg_file,byte4);
            }
            else if(byte4 >= 0xe0 && byte4 <= 0xef){
                readPacketAudio(mpg_file,byte4);
            }
            else{
                printf("--> Código: %.2x -- Tipo de stream não implementado\n", byte4);
            }

            readBytes[0] = fgetc(mpg_file);
            readBytes[1] = fgetc(mpg_file);
            readBytes[2] = fgetc(mpg_file);
            resul = memcmp(prefixCode,readBytes, sizeof(prefixCode));
        
        }else{
            readBytes[0] = readBytes[1];
            readBytes[1] = readBytes[2];
            readBytes[2] = fgetc(mpg_file);
            resul = memcmp(prefixCode,readBytes, sizeof(prefixCode));
        }
    
    }
    

    fclose(mpg_file);

    }