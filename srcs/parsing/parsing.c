#include "../ft_ls.h"


int     isOption(char c){
    if (ft_strchr("artlRufgd", c))
        return (1);
    return (0);
}

void    *getOptions(t_args *args){
    char    *options;
    char    *file;
    int     scoreBefore;
    int     scoreNumber;

    options = ft_calloc(1, sizeof(char));
    if (!options)
        return (NULL);
    if (args->argc > 1){
        for (int i = 0; i < args->argc; i++){
            for (int j = 0; j < ft_strlen(args->argv[i]); j++){
                // if it's not printable pass
                if (args->argv[i][j] && !ft_isprint(args->argv[i][j]))
                    j++;
                // if its a '-' count number of them because it might be end of options
                else if (args->argv[i][j] == '-'){
                    scoreNumber = 0;
                    while (j < ft_strlen(args->argv[i])){
                        scoreNumber++;
                        j++;
                    }
                    if (scoreNumber == 1){
                        scoreBefore = 1;
                        j++;
                    }
                    else if (scoreNumber == 2){
                        scoreBefore = 0;
                        j++;
                    }
                }
                if (scoreBefore && isOption(args->argv[i][j])){

                }
                else if (scoreBefore && !isOption(args->argv[i][j])){

                }
                else{
                    
                }
                
            }
        }
    }
}