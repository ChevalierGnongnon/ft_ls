#include "../ft_ls.h"

void freeFiles(t_args *args){
    int i;
    
    i = 0;
    while (args->files[i]){
        free(args->files[i]);
        i++;
    }
    free(args->files);
}

void freeArgs(t_args *args){
    if (!args)
        return ;
    if (args->files)
        freeFiles(args);
    if (args->params)
        free(args->params);
    free(args);
}

