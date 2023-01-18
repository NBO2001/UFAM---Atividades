
struct entrada{
    int chave;
    void* info;
};

typedef int(*TFuncaoHash)(int);
typedef struct DSD TDSD;
typedef struct entrada TEntradaDSH;

TDSD* criar_DSD(int tam, TFuncaoHash hashing);
void inserir_DSD(TDSD* hash, int chave, void* info);
void* buscar_DSD(TDSD* hash, int chave);
int tamanho_DSD(TDSD* hash);