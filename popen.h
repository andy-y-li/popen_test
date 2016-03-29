/*
 * =====================================================================================
 *
 *       Filename:  popen.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/29/16 17:17:55
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Andy (gk), andy_y_li@163.com
 *        Company:  RD
 *
 * =====================================================================================
 */

#ifndef _RE_POPEN_H
#define _RE_POPEN_H


FILE *
re_popen(const char *cmdstring, const char *type);

int
re_pclose(FILE *fp);

#endif

