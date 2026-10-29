#ifndef FT_LS_H
# define FT_LS_H
# include "../libft/libft.h"

typedef struct args{
    char    **argv;
    char    **options;
    int     argc;
} t_args;

int     fatalError();


#endif