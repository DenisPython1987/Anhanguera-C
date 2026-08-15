#include <stdio.h>
#include <stdlib.h>
#include "arvoreAVL.h"
struct NO{
    int info;
    int alt;
    struct NO *esq;
    struct NO *dir;
};