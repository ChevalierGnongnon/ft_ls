#include <unistd.h>
#include "ft_ls.h"

t_params    *initParams(void){
    t_params    *params;

    params = calloc(1, sizeof(t_params));
    if (!params)
        return (NULL);
    // params->listOnlyDirectories = false;
    params->longListingFormat = false;
    // params->noOwner = false;
    // params->noSort = false;
    params->recursive = false;
    params->reversed = false;
    params->showDotStartingEntries = false;
    params->sortByTime = false;
    // params->useAccessDate = false;
    return (params);
}

t_args  *initArgs(int argc, char **argv){
    t_args      *args;

    args = ft_calloc(1, sizeof(t_args));
    if (!args)
        return (NULL);
    args->params = initParams();
    if (!args->params){
        freeArgs(args);
        return (NULL);
    }
    args->argc = argc;
    args->argv = argv;
    args->files = NULL;
    return (args);
}



int main(int argc, char **argv){
    t_args  *args;

    args = initArgs(argc, argv);
    if(!args){
        fatalError();
        exit(2);
    }
    getArguments(args);
    freeArgs(args);
}