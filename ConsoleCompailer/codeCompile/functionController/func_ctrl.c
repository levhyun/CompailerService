#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>

#define MAX_SIZE 1024

struct{
    char str[MAX_SIZE];
}line[MAX_SIZE];

struct{
    char str[MAX_SIZE];
}result[MAX_SIZE];

void compileReset() {
    FILE* fileHandle;

    fileHandle = fopen("./../codes/compileCode.c","w");
    fputs("",fileHandle);
    fclose(fileHandle);

    fileHandle = fopen("./../result/codeResult.txt","w");
    fputs("",fileHandle);
    fclose(fileHandle);

    system("rm -rf ./../codeOut/compileCode.out");
    
    system("clear");
}

void codeSave(char *name, int maxLine) {
    printf("name : %s\n", name);
    FILE* fileHandle;
    char command[MAX_SIZE];
    char location[MAX_SIZE];
    
    sprintf(command, "mkdir ./../saveCode/%s", name);
    system(command);

    sprintf(command, "touch ./../saveCode/%s/%s.c", name, name);
    system(command);
    sprintf(location, "./../saveCode/%s/%s.c", name, name);
    fileHandle = fopen(location,"a");
    for (int i = 0; i < maxLine; i++) {
        fputs(line[i].str,fileHandle);
        if(i != maxLine-1){
            fputc('\n',fileHandle);
        }
    }
    fclose(fileHandle);

    sprintf(command, "touch ./../saveCode/%s/%s.txt", name, name);
    system(command);
    sprintf(location, "./../saveCode/%s/%s.txt", name, name);
    fileHandle = fopen(location,"a");
    for (int i = 0; i < maxLine; i++) {
        char num[MAX_SIZE+2];
        sprintf(num, "[%d] ", i+1);
        fputs(num ,fileHandle);
        fputs(line[i].str,fileHandle);
        if(i != maxLine-1){
            fputc('\n',fileHandle);
        }
    }
    fclose(fileHandle);
}

int getResult() {
    int pre = 0;

    system("gcc ./../codes/compileCode.c -o ./../codeOut/compileCode.out");
    system("./../codeOut/compileCode.out > ./../result/codeResult.txt"); 
    FILE* fileHandle = fopen("./../result/codeResult.txt","r");
    while (!feof(fileHandle)) {
        fgets(result[pre++].str, MAX_SIZE, fileHandle);
    }
    fclose(fileHandle);

    return pre;
}

void codePush(int lineCnt) {    
    FILE* fileHandle = fopen("./../codes/compileCode.c","a");
    for (int i = 0; i < lineCnt; i++) {
        fputs(line[i].str,fileHandle);
        if(i != lineCnt-1){
            fputc('\n',fileHandle);
        }
    }
    fclose(fileHandle);
}