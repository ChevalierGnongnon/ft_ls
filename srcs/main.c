#include <unistd.h>
#include "ft_ls.h"


t_args  *initArgs(int argc, char **argv){
    t_args  *args;

    args = ft_calloc(1, sizeof(t_args));
    if (!args)
        return (NULL);
    args->argc = argc;
    args->argv = argv;
    args->options = NULL;
    return (args);
}



int main(int argc, char **argv){
    t_args  *args;

    args = initArgs(argc, argv);
    if(!args){
        fatalError();
        exit(2);
    }
    getOptions(args);
}