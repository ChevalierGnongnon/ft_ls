#include "../ft_ls.h"

void display(t_args *args){
    if (!args)
        return ;
    printf("Options:\n");
    if (args->params){
        printf("Show dot starting entries (a): %d\n", args->params->showDotStartingEntries);
        printf("Recursive (R): %d\n", args->params->recursive);
        printf("Long listing format(l): %d\n", args->params->longListingFormat);
        printf("Reversed (r): %d\n", args->params->reversed);
        printf("Sort by time (t): %d\n", args->params->sortByTime);
    }
    printf("Files:\n");
    if (args->files){
        int i = 0;
        while(args->files[i]){
            printf("%s\n", args->files[i]);
            i++;
        }
    }
}