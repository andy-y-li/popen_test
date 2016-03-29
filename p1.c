/*
 * =====================================================================================
 *
 *       Filename:  p1.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/29/16 22:44:00
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Andy (gk), andy_y_li@163.com
 *        Company:  RD
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <errno.h>

void *pthread_proc(void *arg)
{
    char buf[1024];
    memset(buf, '\0', sizeof(buf));
    printf("begin popen...\n");
    FILE *fp = popen("ls -l;./delay 5", "r+");
    printf("end of popen\n");
    fread(buf, 1, sizeof(buf),fp);
    printf("%s\n", buf);
    //pclose(fp);
    return NULL;
}

int main()
{
    pthread_t pht;
    int phi = pthread_create(&pht, NULL, pthread_proc, NULL);
    if (phi != 0) {
        fprintf(stderr, "pthread_create error:%s\n", strerror(errno));
        return -1;
    }
    fprintf(stdout, "waiting for thread return..\n");
    int i = 1;
    while(1) {
        phi = pthread_join(pht, NULL);
        if (phi != 0) {
            sleep(1);
            fprintf(stdout, "%d ", i++);
        }
        else {
            fprintf(stdout,"thread return.\n");
            break;
        }
    }
    return 0;
}
