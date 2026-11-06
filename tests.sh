#!/bin/bash

run() {
    echo "=== $*"
    $VG "$@"
    echo "exit=$?"
    echo
}

# 1. Sans chemin : Files = .
run ./ft_ls
run ./ft_ls -l

# 2. Options (a R l r t), exit=0
run ./ft_ls -l                 # l
run ./ft_ls -la                # l a
run ./ft_ls -l -a              # l a
run ./ft_ls -al                # l a
run ./ft_ls -lRart             # les 5
run ./ft_ls -t -r              # t r
run ./ft_ls -l -l -ll          # l
run ./ft_ls -l srcs -a         # l a, Files = srcs

# 3. Chemins, ordre conservé
run ./ft_ls srcs
run ./ft_ls srcs Makefile libft
run ./ft_ls srcs srcs          # deux fois srcs
run ./ft_ls srcs srcs/         # le / est conservé
run ./ft_ls ""                 # une ligne vide
run ./ft_ls "mon fichier"      # un seul chemin
run ./ft_ls truc               # le parsing ne vérifie pas l'existence

# 4. Le - et le --
run ./ft_ls -                  # Files = -
run ./ft_ls --                 # aucune option, Files = .
run ./ft_ls -- -l              # aucune option, Files = -l
run ./ft_ls -l -- -a           # l, Files = -a
run ./ft_ls -- -l -- -a        # Files = -l, --, -a
run ./ft_ls -- --              # Files = --
run ./ft_ls -- -               # Files = -

# 5. Options invalides : message d'erreur, exit=2, pas d'affichage de display
run ./ft_ls -z
run ./ft_ls -lz
run ./ft_ls -zl
run ./ft_ls -l-a               # lettre fautive : -
run ./ft_ls -la-               # lettre fautive : -
run ./ft_ls ---                # lettre fautive : -
run ./ft_ls srcs -z
run ./ft_ls -la srcs -z Makefile
run ./ft_ls -z -y              # seul z est signalé
run ./ft_ls -u
run ./ft_ls -f
run ./ft_ls -g
run ./ft_ls -d
run ./ft_ls -- -z              # PAS d'erreur, Files = -z

# 6. Tirets pernicieux
run ./ft_ls -l---              # invalid option -- '-'
run ./ft_ls -z --              # z signalé, le -- n'y change rien
run ./ft_ls -l -- --           # l, Files = --
run ./ft_ls - -l               # l, Files = -
run ./ft_ls - --               # Files = -
run ./ft_ls -- - --            # Files = -, --
run ./ft_ls -l - -z            # z signalé
run ./ft_ls "" -z              # z signalé, "" ne bloque pas la suite

# 7. Options longues (ls : unrecognized option, ou valides pour --help et --all)
run ./ft_ls --foo
run ./ft_ls ----
run ./ft_ls --help
run ./ft_ls --all

# 8. Espaces et caractères de contrôle
run ./ft_ls " "                # Files = un espace
run ./ft_ls " -l"              # chemin, ne commence pas par -
run ./ft_ls "-l "              # l, puis espace invalide
run ./ft_ls "- "               # espace invalide
run ./ft_ls -$'\n'             # retour à la ligne invalide
run ./ft_ls -$'\t'             # tabulation invalide
run ./ft_ls $'-l\nz'           # retour à la ligne invalide
run ./ft_ls -$'\x01'           # caractère de contrôle invalide

# 9. Caractères non ASCII (un octet à la fois, char négatif)
run ./ft_ls -é
run ./ft_ls -$'\xff'

# 10. Tailles extrêmes
run ./ft_ls -$(printf 'l%.0s' {1..50000})     # l
run ./ft_ls -$(printf 'l%.0s' {1..50000})z    # z signalé
run ./ft_ls $(printf 'a%.0s' {1..5000})       # chemin de 5000 caractères
run ./ft_ls $(seq 1 20000)                    # 20000 chemins

# 11. Chemins particuliers
run ./ft_ls / // ./ ../ . ..

# 12. Sorties fermées ou pleines (ls : write error et exit=2 pour stdout)
echo "=== stdout fermée"; $VG ./ft_ls >&-; echo "exit=$?"; echo
echo "=== stdout pleine"; $VG ./ft_ls > /dev/full; echo "exit=$?"; echo
echo "=== stderr fermée"; $VG ./ft_ls -z 2>&-; echo "exit=$?"; echo

# 13. Variable d'environnement : les options s'arrêtent au premier chemin
echo "=== POSIXLY_CORRECT"; POSIXLY_CORRECT=1 $VG ./ft_ls srcs -l; echo "exit=$?"; echo
