#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#define SEED    0x392

static inline uint32_t murmur_32_scramble(uint32_t k) {
    k *= 0xcc9e2d51;
    k = (k << 15) | (k >> 17);
    k *= 0x1b873593;
    return k;
}
uint32_t murmur3_32(const uint8_t* key, size_t len, uint32_t seed)
{
	uint32_t h = seed;
    uint32_t k;
    /* Read in groups of 4. */
    for (size_t i = len >> 2; i; i--) {
        // Here is a source of differing results across endiannesses.
        // A swap here has no effects on hash properties though.
        memcpy(&k, key, sizeof(uint32_t));
        key += sizeof(uint32_t);
        h ^= murmur_32_scramble(k);
        h = (h << 13) | (h >> 19);
        h = h * 5 + 0xe6546b64;
    }
    /* Read the rest. */
    k = 0;
    for (size_t i = len & 3; i; i--) {
        k <<= 8;
        k |= key[i - 1];
    }
    // A swap is *not* necessary here because the preceding loop already
    // places the low bytes in the low places according to whatever endianness
    // we use. Swaps only apply when the memory is copied in a chunk.
    h ^= murmur_32_scramble(k);
    /* Finalize. */
	h ^= len;
	h ^= h >> 16;
	h *= 0x85ebca6b;
	h ^= h >> 13;
	h *= 0xc2b2ae35;
	h ^= h >> 16;
	return h;
}

unsigned long long int get_hash(char* s, int n) {
  long long p = 31, m = 1e9 + 7;
  unsigned long long hash = 0;
  long long p_pow = 1;
  for(int i = 0; i < n; i++) {
    hash = (hash + (s[i] - 'a' + 1) * p_pow) % m;
    p_pow = (p_pow * p) % m;
  }
  return hash;
}

unsigned long long int hashV2(char* key) {

	unsigned long long int hashVal = 0;

	while (*key != 0) {

		hashVal = (hashVal << 4) + *(key++);

		long g = hashVal & 0xF0000000L;

		if (g != 0) hashVal ^= g >> 24;

		hashVal &= ~g;

	}

	return hashVal;

}	

unsigned long hashV3(unsigned char *str)
{
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}

unsigned long long int dupleHashing(char* s, int n, int instanceTam){

    unsigned long long int h = murmur3_32(s,n,0x85);
    h = h + (hashV2(s));

    return h%instanceTam;
}

unsigned int MurmurHash2 ( const void * key, int len, unsigned int seed )
{
	// 'm' and 'r' are mixing constants generated offline.
	// They're not really 'magic', they just happen to work well.

	const unsigned int m = 0x5bd1e995;
	const int r = 24;

	// Initialize the hash to a 'random' value

	unsigned int h = seed ^ len;

	// Mix 4 bytes at a time into the hash

	const unsigned char * data = (const unsigned char *)key;

	while(len >= 4)
	{
		unsigned int k = *(unsigned int *)data;

		k *= m; 
		k ^= k >> r; 
		k *= m; 
		
		h *= m; 
		h ^= k;

		data += 4;
		len -= 4;
	}
	
	// Handle the last few bytes of the input array

	switch(len)
	{
	case 3: h ^= data[2] << 16;
	case 2: h ^= data[1] << 8;
	case 1: h ^= data[0];
	        h *= m;
	};

	// Do a few final mixes of the hash to ensure the last few
	// bytes are well-incorporated.

	h ^= h >> 13;
	h *= m;
	h ^= h >> 15;

	return h;
} 

int main(int argc, char * argv[]){

    uint32_t seed = 0x585;
    size_t tm = 5;
    char ts[25];

    int totV = 420;

    int *wds = calloc(totV,sizeof(int));

    FILE * arq = fopen("stopwords_br.txt", "r");

    while (fscanf(arq,"%s", ts) == 1){
        // int idx = dupleHashing(ts,strlen(ts), totV)%totV;
        int idx = hashV3(ts)%totV;
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

    quality = quality / (11581-10);
    printf("1: %d; 0: %d; C: %d; M: %lf; MaiorC: %d; quality: %lf\n",contOn,contzeros, confitos, tolC/confitos, maiorConfito, quality);
    // int a = 0x25;
    // 

    // printf("%d\n", );
}
