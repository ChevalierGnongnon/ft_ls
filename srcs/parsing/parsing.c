#include "../ft_ls.h"
#include <stdio.h>

static int     isOption(char c){
    if (ft_strchr("artlR", c))
        return (1);
    return (0);
}

static int checkOptions(t_args *args, char *arg){
    for (size_t i = 1; arg[i]; i++){
        if (!isOption(arg[i])){
            invalidOption(args, arg[i]);
        }
    }
    return (1);
}


static void    handleOptions(t_args *args, int i){
    for (size_t j = 1; args->argv[i][j]; j++){
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
                invalidOption(args, args->argv[i][j]);
                break;
        }
    }
}


int     getArguments(t_args *args){
    // char    **files;
    char    **tmpFiles;
    int     fileNumber;
    int     optionsAvailable;

    fileNumber = 0;
    optionsAvailable = 1;
    args->files = ft_calloc(2, sizeof(char *));
    if (!args->files)
        return (0);
    if (args->argc > 1){
        for (int i = 1; i < args->argc; i++){
            if (optionsAvailable && ft_strlen(args->argv[i]) == 2 && strcmp(args->argv[i], "--") == 0)
                optionsAvailable = 0;
            else if (optionsAvailable && args->argv[i][0] == '-' && ft_strlen(args->argv[i]) > 1){
                if (checkOptions(args, args->argv[i]))
                    handleOptions(args, i);
            }
            else {
                tmpFiles = realloc(args->files, sizeof(char *) * (fileNumber + 2));
                if (!tmpFiles)
                    fatalError(args);
                args->files = tmpFiles;
                args->files[fileNumber] = ft_strdup(args->argv[i]);
                if (!args->files[fileNumber])
                    fatalError(args);
                args->files[fileNumber + 1] = NULL;
                fileNumber++;
            }
        }
    }
    int j = 0;
    while (args->files[j])
        j++;
    if (j == 0)
        args->files[0] = ".";
    display(args);
    
    return (1);
}