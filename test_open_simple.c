/*
 * =====================================================================================
 *
 *       Filename:  test_open_simple.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/29/16 18:02:03
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
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    char buffer[1024];
    memset(buffer,'\0', sizeof(buffer));
 //   FILE *fp = popen("ls -l", "r");
    FILE *fp = popen("bcd-cli.app --usbcdc", "r");
    fread(buffer, 1, sizeof(buffer), fp);
    printf("%s\n", buffer);
    pclose(fp);

    return 0;

}

