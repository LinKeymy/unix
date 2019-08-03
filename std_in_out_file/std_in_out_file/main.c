//
//  main.c
//  std_in_out_file
//
//  Created by SteveLin on 2019/7/26.
//  Copyright © 2019 SteveLin. All rights reserved.
//

#include <stdio.h>
#include "../../apue.3e/include/apue.h"
#include "../../apue.3e/include/unix_error.h"

#include <errno.h>

#define BUFFSIZE 4096

//int main() {
//    size_t n;
//    char buf[BUFFSIZE];
//
//
//    // read 返回读取的字节数
//    while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0) {
//        if (write(STDOUT_FILENO, buf, n) != n) {
//            err_sys("write error");
//        }
//    }
//
//    if (n > 0) {
//        err_sys("read error");
//    }
//    exit(0);
//}


int main(void) {
    char buf[MAXLINE];
    pid_t pid;

    int status;
    
    printf("%% ");
    while (fgets(buf, MAXLINE, stdin) != NULL) {
        if (buf[strlen(buf) - 1] == '\n') {
            buf[strlen(buf) - 1] = 0; // null
        }
        
        /*
         餐叉; 叉(挖掘用的园艺工具);
         n.    (道路、河流等的) 分岔处，分流处，岔口，岔路;
         v.    分岔; 岔开两条分支; 走岔路中的一条; 叉运; 叉掘;
         fork
         英[fɔːk]
         美[fɔːrk]
*/
        if ((pid = fork()) < 0) {
            err_sys("fork error");
        } else if (pid == 0) { // child process
            printf("fork()-- child return %d \n",pid);
            execlp(buf, buf,(char *) 0);
            err_ret("conldn,t exetute: %s",buf);
            exit(127);
        }
        
        printf("fork()-- parent return %d \n",pid);
        
        /* parent */
        if ((pid = waitpid(pid, &status, 0)) < 0) {
            err_sys("waitpid error");
        }
        printf("%% ");
    }
    exit(0);
}
