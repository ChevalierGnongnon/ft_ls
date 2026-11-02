#include "../ft_ls.h"
#include <stdio.h>

static int     isOption(char c){
    if (ft_strchr("artlR", c))
        return (1);
    return (0);
}

static int checkOptions(char *arg, char *returned){
    for (size_t i = 1; i < ft_strlen(arg); i++){
        if (!isOption(arg[i])){
            (*returned) = arg[i];
            return (0);
        }     
    }
    return (1);
}


static void    handleOptions(t_args *args, int i){
    for (size_t j = 1; j < ft_strlen(args->argv[i]); j++){
        switch(args->argv[i][j]){
            case 'l':
                args->params->longListingFormat = true;
                break;
            case 'R':
                args->params->recursive = true;
                break;
            case 'a':
                args->params->showDotStartingEntries = true;
                break;
            case 'r':
                args->params->reversed = true;
                break;
            case 't':
                args->params->sortByTime = true;
                break;
            default:
                fatalError();
                break;
        }
    }
}


int     getArguments(t_args *args){
    char    **files;
    char    **tmpFiles;
    char    wrongOne;
    int     fileNumber;
    int     optionsAvailable;

    fileNumber = 0;
    optionsAvailable = 1;
    files = ft_calloc(1, sizeof(char *));
    if (!files)
        return (0);
    if (args->argc > 1){
        for (int i = 1; i < args->argc; i++){
            if (optionsAvailable && ft_strlen(args->argv[i]) == 2 && ft_strncmp(args->argv[i], "--", 2) == 0)
                optionsAvailable = 0;
            else if (optionsAvailable && args->argv[i][0] == '-' && ft_strlen(args->argv[i]) > 1){
                if (checkOptions(args->argv[i], &wrongOne))
                    handleOptions(args, i);
                else 
                    return (freeArgs(args), fatalError(), 0);
            }
            else {
                tmpFiles = realloc(files, sizeof(char *) * (fileNumber + 2));
                if (!tmpFiles)
                    return (freeArgs(args), fatalError(), 0);
                files = tmpFiles;
                files[fileNumber] = ft_strdup(args->argv[i]);
                if (!files[fileNumber])
                    return (freeArgs(args), fatalError(), 0);
                files[fileNumber + 1] = NULL;
                fileNumber++;
            }
        }
    }
    args->files = files;
    for (int k = 0; k < fileNumber; k++){
        printf("%s\n", args->files[k]);
    }
    return (1);
}