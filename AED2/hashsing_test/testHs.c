#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#define SEED    0x392

unsigned int MurmurHash2 ( const void * key, int len, unsigned int seed )
{
    // Fonte: https://sites.google.com/site/murmurhash/
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

  long int tmp = 0x58;
  int tmp2 = 0x84;
  char name[25];
  strcpy(name, "Segura o dedo");
  double age = 25.1584;

  printf("long int %u\n", MurmurHash2(&tmp,sizeof(long int),SEED));
  printf("int %u\n", MurmurHash2(&tmp2,sizeof(int),SEED));
  printf("name %u\n", MurmurHash2(name,sizeof(name),SEED));
  printf("double %u\n", MurmurHash2(&age,sizeof(double),SEED));
}