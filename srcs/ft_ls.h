#ifndef FT_LS_H
# define FT_LS_H
# include <stdbool.h>
# include "../libft/libft.h"


typedef struct s_params{
    bool        showDotStartingEntries; // -a
    bool        recursive;     // -R
    bool        longListingFormat;     // -l
    bool        reversed;    // -r
    bool        sortByTime;    // -t 
} t_params;

typedef struct s_args{
    t_params    *params;
    char        **argv;
    char        **files;
    int         argc;
} t_args;


void    fatalError(void);
int     getArguments(t_args *args);
void    freeArgs(t_args *args);



#endif