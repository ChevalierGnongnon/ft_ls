#include "../ft_ls.h"
#include <unistd.h>

void    fatalError(void){
    write(1, "Fatal error\n", 13);
}