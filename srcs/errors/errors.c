#include "../ft_ls.h"

void    invalidOption(t_args *args, char option){
    ft_putstr_fd("ls: invalid option -- '", 2);
    ft_putchar_fd(option, 2);
    ft_putstr_fd("'\n", 2);
    if (args)
        freeArgs(args);
    exit(2);
}

// lstat fails
void    cannotAccess(t_args *args, char *path){
    ft_putstr_fd("ls: cannot access '", 2);
    ft_putstr_fd(path, 2);
    strerror(errno);
    if (args)
        freeArgs(args);
}

// Opendir fails
void    cannotOpen(t_args *args, char *path){
    ft_putstr_fd("ls: cannot open directory '", 2);
    ft_putstr_fd(path, 2);
    strerror(errno);
    if (args)
        freeArgs(args);
}

void fatalError(t_args *args){
    ft_putstr_fd("Fatal error\n", 2);
    if (args)
        freeArgs(args);
    exit(2);
}


