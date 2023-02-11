#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>
#include "./../functionController/func_ctrl.c"

#define MAX_SIZE 1024

void compileReset();
void codeSave(char *name, int maxLine);
int getResult();
void codePush(int lineCnt);
void codeSaveSetFunc(int lineCnt);