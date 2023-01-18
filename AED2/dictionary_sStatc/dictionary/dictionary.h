
typedef struct entrada TEntradaDSD;

typedef struct DSD TDSD;

TDSD* criar_DSD(int tam);

void inserir_DSD(TDSD* dsd, int chave, void* info);
void* buscar_DSD(TDSD* dsd, int chave);
int tamanho_DSD(TDSD* dsd);