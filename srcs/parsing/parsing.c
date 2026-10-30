#include "../ft_ls.h"
#include <stdio.h>

int     isOption(char c){
    if (ft_strchr("artlRufgd", c))
        return (1);
    return (0);
}

int checkOptions(char *arg, char *returned){
    for (size_t i = 1; i < ft_strlen(arg); i++){
        if (!isOption(arg[i])){
            (*returned) = arg[i];
            return (0);
        }     
    }
    return (1);
}

// clear options from repeted characters and -
char *cleanOptions(char *input){
    char    *cleaned;
    char    *tmp;
    int     limit;

    cleaned = calloc(1, sizeof(char));
    if (!cleaned)
        return (NULL);
   
    for (size_t i = 0; i < ft_strlen(input); i++){
        if (ft_isalpha(input[i]) && !ft_strchr(cleaned, input[i])){
            limit = ft_strlen(cleaned);
            tmp = realloc(cleaned, sizeof(char) * (ft_strlen(cleaned) + 2));
            if (!tmp)
                return (NULL);
            cleaned = tmp;
            cleaned[limit] = input[i];
            cleaned[limit + 1] = '\0';
        }
    }
    return (cleaned);
}

int     getOptions(t_args *args){
    char    **files;
    char    **tmpFiles;
    char    *options;
    char    *newOptions;
    char    wrongOne;
    int     fileNumber;
    int     optionsAvailable;

    fileNumber = 0;
    optionsAvailable = 1;
    files = ft_calloc(1, sizeof(char *));
    if (!files)
        return (0);
    options = ft_calloc(1, sizeof(char));
    if (!options)
        return (0);
    if (args->argc > 1){
        for (int i = 1; i < args->argc; i++){
            if (optionsAvailable && ft_strlen(args->argv[i]) == 2 && ft_strncmp(args->argv[i], "--", 2) == 0)
                optionsAvailable = 0;
            else if (optionsAvailable && args->argv[i][0] == '-' && ft_strlen(args->argv[i]) > 1){
                if (checkOptions(args->argv[i], &wrongOne)){
                    newOptions = ft_strjoin(options, args->argv[i]);
                    if (!newOptions)
                        return (0);
                    free(options);
                    options = newOptions;
                }
                else 
                    return (0);
            }
            else {
                tmpFiles = realloc(files, sizeof(char *) * (fileNumber + 2));
                if (!tmpFiles)
                    return (0);
                files = tmpFiles;
                files[fileNumber] = ft_strdup(args->argv[i]);
                if (!files[fileNumber])
                    return (0);
                files[fileNumber + 1] = NULL;
                fileNumber++;
            }
        }
    }
    args->options = cleanOptions(options);
    free(options);
    if (!args->options)
        return (0);
    args->files = files;
    printf("Options:\n");
    printf("%s\n", args->options);
    printf("Paths:\n");
    for (int k = 0; k < fileNumber; k++){
        printf("%s\n", args->files[k]);
    }
    return (1);
}