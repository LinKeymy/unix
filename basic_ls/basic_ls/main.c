//
//  main.c
//  basic_ls
//
//  Created by SteveLin on 2019/7/25.
//  Copyright © 2019 SteveLin. All rights reserved.
//



#include <stdio.h>
#include <dirent.h>

#include "../../apue.3e/include/apue.h"
#include "../../apue.3e/include/unix_error.h"


int main(int argc, const char * argv[]) {
    DIR *dp;
    struct dirent *dirp;
    
    if (argc != 2) {
        err_quit("usage: ls diretory_name");
    }
    if ((dp = opendir(argv[1])) == NULL) {
        err_sys("can't open %s",argv[1]);
    }
    while ((dirp = readdir(dp)) != NULL) {
        printf("%s\n", dirp->d_name);
    }
    closedir(dp);
    
    return 0;
}
