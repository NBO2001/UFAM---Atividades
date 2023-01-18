#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 2048
#define SEED    0x392

uint32_t DJB2_hash(const uint8_t *str)
{
    uint32_t hash = 5381;
    uint8_t c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    return hash;
}

uint32_t FNV(const void* key, int len, uint32_t h)
{
    // Source: https://github.com/aappleby/smhasher/blob/master/src/Hashes.cpp
    h ^= 2166136261UL;
    const uint8_t* data = (const uint8_t*)key;
    for(int i = 0; i < len; i++)
    {
        h ^= data[i];
        h *= 16777619;
    }
    return h;
}

uint32_t MurmurOAAT_32(const char* str, uint32_t h)
{
    // One-byte-at-a-time hash based on Murmur's mix
    // Source: https://github.com/aappleby/smhasher/blob/master/src/Hashes.cpp
    for (; *str; ++str) {
        h ^= *str;
        h *= 0x5bd1e995;
        h ^= h >> 15;
    }
    return h;
}

uint32_t KR_v2_hash(const char *s)
{
    // Source: https://stackoverflow.com/a/45641002/5407270
    uint32_t hashval = 0;
    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31*hashval;
    return hashval;
}

uint32_t Jenkins_one_at_a_time_hash(const char *str, size_t len)
{
    uint32_t hash, i;
    for(hash = i = 0; i < len; ++i)
    {
        hash += str[i];
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);
    return hash;
}

uint32_t crc32b(const uint8_t *str) {
    // Source: https://stackoverflow.com/a/21001712
    unsigned int byte, crc, mask;
    int i = 0, j;
    crc = 0xFFFFFFFF;
    while (str[i] != 0) {
        byte = str[i];
        crc = crc ^ byte;
        for (j = 7; j >= 0; j--) {
            mask = -(crc & 1);
            crc = (crc >> 1) ^ (0xEDB88320 & mask);
        }
        i = i + 1;
    }
    return ~crc;
}

inline uint32_t _rotl32(uint32_t x, int32_t bits)
{
    return x<<bits | x>>(32-bits);      // C idiom: will be optimized to a single operation
}

uint32_t Coffin_hash(char const *input) { 
    // Source: https://stackoverflow.com/a/7666668/5407270
    uint32_t result = 0x55555555;
    while (*input) { 
        result ^= *input++;
        result =( result<<5 | result>>(32-5) );
    }
    return result;
}

uint32_t x17(const void * key, int len, uint32_t h)
{
    // Source: https://github.com/aappleby/smhasher/blob/master/src/Hashes.cpp
    const uint8_t * data = (const uint8_t*)key;
    for (int i = 0; i < len; ++i)
    {
        h = 17 * h + (data[i] - ' ');
    }
    return h ^ (h >> 16);
}

uint32_t apply_hash(int hash, const char* line)
{
    switch (hash) {
    case 1: return crc32b((const uint8_t*)line);
    case 2: return MurmurOAAT_32(line, SEED);
    case 3: return FNV(line, strlen(line), SEED);
    case 4: return Jenkins_one_at_a_time_hash(line, strlen(line));
    case 5: return DJB2_hash((const uint8_t*)line);
    case 6: return KR_v2_hash(line);
    case 7: return Coffin_hash(line);
    case 8: return x17(line, strlen(line), SEED);
    default: break;
    }
    return 0;
}


int main(int argc, char* argv[]){
    uint32_t seed = 0x585;
    size_t tm = 5;
    char ts[25];

    //int totV = 16061;

    int totV = 392;

    int *wds = calloc(totV,sizeof(int));

    FILE * arq = fopen("stopwords_br.txt", "r");

    while (fscanf(arq,"%s", ts) == 1){
        // int idx = dupleHashing(ts,strlen(ts), totV)%totV;
        int idx = apply_hash(2,ts)%totV;
        wds[idx]++;
    }
    

    fclose(arq);

    int contOn = 0;
    int contzeros = 0;
    int confitos = 0;
    double tolC = 0.0;
    int maiorConfito = 0;
    
    double quality = 0;

    for(int i=0; i < totV; i++){
        
        quality += wds[i]*wds[i];

        if(wds[i] == 1){
            contOn++;
        }else if(wds[i] == 0){
            contzeros++;
        }else{
            tolC += wds[i];
            if(maiorConfito < wds[i]) maiorConfito = wds[i];
            confitos++;
        }
    }

    quality = quality / (392-10);
    printf("1: %d; 0: %d; C: %d; M: %lf; MaiorC: %d; quality: %lf\n",contOn,contzeros, confitos, tolC/confitos, maiorConfito, quality);
    // int a = 0x25;
    // 

    // printf("%d\n", );
}