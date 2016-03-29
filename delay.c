/*
 * =====================================================================================
 *
 *       Filename:  delay.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/29/16 22:34:32
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
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Usage: ./delay ns\n");
        return -1;
    }
    int s = atoi(argv[1]);
    sleep(s);

    return 0;
}


