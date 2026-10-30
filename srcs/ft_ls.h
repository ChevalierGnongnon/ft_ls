#ifndef FT_LS_H
# define FT_LS_H
# include "../libft/libft.h"

typedef struct args{
    char    **argv;
    char    **files;
    char    *options;
    int     argc;
} t_args;

void    fatalError(void);
int     getOptions(t_args *args);

#endif