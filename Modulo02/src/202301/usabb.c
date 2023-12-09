#include "stdlib.h"
#include "stdio.h"
#include "wchar.h"
#include "locale.h"
#include "abb.h"

typedef struct {
    int hashing;
    wchar_t palavra[80];
    int tamanho;
}t_palavra;

t_palavra* criar_palavra(wchar_t palavra[], unsigned int hashing, int tamanho){
    t_palavra* nova = malloc(sizeof (t_palavra));
    nova->hashing = hashing;
    nova->tamanho = tamanho;
    wcscpy(nova->palavra,palavra);
    return nova;
}

int comparar_palavra(void *pp1, void *pp2){
    t_palavra* p1=pp1;
    t_palavra* p2 = pp2;
    return (p1->hashing - p2->hashing);
}

void destruir_palavra(void *p1){
    free((t_palavra*) p1);
}

void imprimir_palavra(void *p){
    t_palavra *pp = p;
    wprintf(pp->palavra);
    printf(" %u %d\n", pp->hashing, pp->tamanho);
}

static short _e_pontuacao(wint_t c){
    if ((c<=47)){
        return 1;
    }else if((c>=58) && (c<=63)){
        return 1;
    }else if ((c>=91) && (c<=96)){
        return 1;
    }else if((c>=123) && (c<=127)){
        return 1;
    }else if((c>=48) && (c<=57)){
        return 1;
    }else{
        return 0;
    }
}


t_palavra* ler_palavra(FILE* f){
    wchar_t palavra[600];
    int pesos[] = {179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,
283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,
419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541};    
    int i=0;
    unsigned int codigo=0;
    for (wint_t c; (c = fgetwc(f)) != WEOF;){
        
        //printf("%d\n", c);
        if ((c==10) || (c==32) || (_e_pontuacao(c))){
            palavra[i]='\0';
            if (i>=2){
                t_palavra *nova = criar_palavra(palavra, codigo, i);
                return nova;
            }
            i=0;
            codigo=0;

        }else{
            codigo += c * pesos[i];
            palavra[i++] = c;
        }
    }
    palavra[i]='\0';
    if (i>=2){
        t_palavra *nova = criar_palavra(palavra, codigo, i);
        return nova;
    }
    return NULL;
}


int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, "C.UTF-8");

    FILE *f = fopen(argv[1], "r, ccs=UTF-8");
    if (!f)
        return 1;
    
    t_abb *obra = criar_abb(comparar_palavra, destruir_palavra, imprimir_palavra);

    int continua =1;
    do{
        t_palavra* nova = ler_palavra(f);
        if (nova==NULL)
            continua = 0;
        else{
          if( buscar_abb(obra,nova) == NULL){
            inserir_abb(obra,nova);
          }else{
            destruir_palavra(nova);
          }
        }
    } while(continua); 

    imprimir_abb(obra);

    fclose(f);
    return 0;
}