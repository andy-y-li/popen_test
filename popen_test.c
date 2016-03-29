#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "apue.h"
#include <sys/wait.h>
#include "popen.h"

//#define	PAGER	"${PAGER:-more}" /* environment variable, or default */
//#define	PAGER	"${bcd/-cli.app --usbcdc}" /* environment variable, or default */
#define	PAGER	"ls -l" /* environment variable, or default */

#define MAXLINE 1024

char str[512] = "";

const char *readFromBCD(FILE *fp)
{
    if (fp == NULL) {
        return NULL;
    }
    memset(str,'\0', sizeof(str));
    char tmp[32];
    while (fread(tmp, 1, sizeof(tmp), fp) == 1) {
        strcat(str, tmp);   
    }
    return str;
}

 int writeToBCDF(FILE *fp,const char *cmd)
{
    if (fp == NULL) {
        return -1;
    }
    int len = fwrite(cmd, 1, strlen(cmd), fp);
    if (len < 0) {
        return -1;
    }
    return 0;
}

int
main(int argc, char *argv[])
{
	char	line[MAXLINE];
	FILE	*fpin, *fpout;

    /*
	if (argc != 2) {
		printf("usage: a.out <pathname>\n");
        return -1;
    }
	if ((fpin = fopen(argv[1], "r")) == NULL) {
		printf("can't open %s", argv[1]);
        return -1;
    }
    */
	//if ((fpout = re_popen(PAGER, "r+")) == NULL) {
	if ((fpout = popen(PAGER, "r+")) == NULL) {
		printf("popen error\n");
        return -1;
    }

    const char *result = readFromBCD(fpout);
    if (strlen(result) > 0) {
        printf("%s\n", result);
    }
    else {
        printf("Nothing\n");
    }

    sleep(1);
    int ret = writeToBCDF(fpout, "9\n");
    if (ret < 0) {
        printf("writeToBCDF error!\n");
        return -1;
    }
   result = readFromBCD(fpout);
    if (strlen(result) > 0) {
        printf("%s\n", result);
    }
    else {
        printf("readFromBCD error!\n");
    }
    /*
	/// copy argv[1] to pager 
	while (fgets(line, MAXLINE, fpin) != NULL) {
		if (fputs(line, fpout) == EOF)
			printf("fputs error to pipe\n");
	}
    */
	if (ferror(fpin))
		printf("fgets error\n");
	//if (re_pclose(fpout) == -1)
	if (pclose(fpout) == -1)
		printf("pclose error\n");

	exit(0);
}

