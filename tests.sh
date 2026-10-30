#!/bin/bash
# VG="valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes"

run() {
    echo "=== $*"
    "$@"
    echo
}

run ./ft_ls
run ./ft_ls -l
run ./ft_ls srcs
run ./ft_ls -l srcs
run ./ft_ls srcs Makefile libft

run ./ft_ls -la
run ./ft_ls -l -a
run ./ft_ls -al
run ./ft_ls -lRart
run ./ft_ls -l -l -ll
run ./ft_ls -l srcs -a

run ./ft_ls -
run ./ft_ls -- -l
run ./ft_ls -l -- -a
run ./ft_ls -- -l -- -a
run ./ft_ls -- --
run ./ft_ls -- -

run ./ft_ls ""
run ./ft_ls srcs srcs
run ./ft_ls srcs srcs/
run ./ft_ls "mon fichier"
run ./ft_ls *.c

run ./ft_ls -z
run ./ft_ls -lz
run ./ft_ls -l-a
run ./ft_ls srcs -z
run ./ft_ls -- -z
run ./ft_ls -u
