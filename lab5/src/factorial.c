#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h> 
#include <getopt.h>
#include <pthread.h>



sem_t mutex;

struct FacArgs {
    int begin;
    int end;
    int mod;
};
int total_fac = 1;

int Factorial(const struct FacArgs *args) {
int fac = 1;
int i;

for ( i = args->begin; i <= args->end; i++)
    {
        fac*=i;
        fac%=args->mod;
    }
    total_fac*= fac;
    total_fac%= args->mod;

    return fac;
}

void *ThreadFactorial(void *args) {
    struct FacArgs *fac_args = (struct FacArgs *)args;
    void * factorial = (void *)(size_t)Factorial(fac_args);
        sem_post(&mutex);
    return factorial;
}

int main(int argc, char **argv) {

    uint32_t i=0;
    uint32_t k = -1;
    uint32_t pnum = -1;
    uint32_t mod = -1;

    while (1) {
        int current_optind = optind ? optind : 1;

        static struct option options[] = {{"k", required_argument, 0, 0},
                                            {"pnum", required_argument, 0, 0},
                                            {"mod", required_argument, 0, 0},
                                            {}};

        int option_index = 0;
        int c = getopt_long(argc, argv, "", options, &option_index);

        if (c == -1) break;

        switch (c) {
        case 0:
        switch (option_index) {
            case 0:
                k = atoi(optarg);
                if (!k) {
                    printf("Error: bad k value\n");
                    return -1;
                }
                break;
            case 1:
                pnum = atoi(optarg);
                if (!pnum) {
                    printf("Error: bad pnum value\n");
                    return -1;
                }
                break;
            case 2:
                mod = atoi(optarg);
                if (!mod) {
                    printf("Error: bad mod value\n");
                    return -1;
                }
                break;
            default:
                printf("Index %d is out of options\n", option_index);
        }
        break;
        case '?':
            break;

        default:
            printf("getopt returned character code 0%o?\n", c);
        }
    }

    if (optind < argc) {
        printf("Has at least one no option argument\n");
        return 1;
    }

    if (k == -1 || pnum == -1 || mod == -1) {
        printf("Usage: %s —k \"num\" —pnum \"num\" —mod \"num\" \n",
        argv[0]);
        return 1;
    }

    pthread_t threads[pnum];
    struct FacArgs args[pnum];
    double block = (double)k / pnum;

    for (i=0;i<pnum;i++)
    {
        int begin = (int)(block * i)+1;
        int end = (int)(block * (i + 1));
        args[i].begin = begin;
        args[i].end = end;
        args[i].mod = mod;
    }

    for (i = 0; i < pnum; i++) {
        if (pthread_create(&threads[i], NULL, ThreadFactorial, (void *)&args[i])) {
            printf("Error: pthread_create failed!\n");
            return 1;
        }
    }

    sem_init(&mutex, 0, 1); 

    for ( i = 0; i < pnum; i++) {
        int fac = 1;
        sem_wait(&mutex);
        pthread_join(threads[i], (void **)&fac);
        sem_post(&mutex);
    }

    sem_destroy(&mutex);

    printf("Factorial = %d\n", total_fac);
    return 0;
}










// gcc main.c -lpthread -lrt -o factorial 
// factorial --k 9 --pnum 1 --mod 137