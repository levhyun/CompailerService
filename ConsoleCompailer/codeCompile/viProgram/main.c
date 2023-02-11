#include "./../headerFile/header.h"

int main() {
    while(1){
        printf("프로그램 종료 : CRTL + C                                              편집기 종료 : ENTER -> :wq\n");
        printf("----------------------------------------------CODE----------------------------------------------\n");

        int lineCnt = 0;
        int lineNumber = 1;

        while(1) {
            fgets(line[lineCnt].str, sizeof(line[lineCnt].str), stdin);
            line[lineCnt].str[strlen(line[lineCnt].str)-1] = 0;
            if(!strcmp(line[lineCnt].str,":wq")) {
                break;
            }
            lineCnt++;
        }
        codePush(lineCnt);

        printf("------------------------------------------------------------------------------------------------\n");
        

        int maxLine = getResult();
        printf("\n---------------------------------------------result---------------------------------------------\n");
        for(int i = 0; i < maxLine; i++){
            printf("%s", result[i].str);
        }     
        printf("\n------------------------------------------------------------------------------------------------\n");

        codeSaveSetFunc(lineCnt);
        compileReset();
    }
}

void codeSaveSetFunc(int lineCnt){
    while (1){        
        char save[1];
        char temp[MAX_SIZE];
        printf("코드를 저장하시겠습니까?[y/n]:");
        scanf("%c", save);
        fgets(temp, sizeof(temp), stdin);
        if(save[0] == 'n'){
            break;
        } else if(save[0] == 'y'){
            char fileName[MAX_SIZE];
            printf("저장할 이름을 입력하세요:");
            fgets(fileName, sizeof(fileName), stdin);
            fileName[strlen(fileName)-1] = 0;
            codeSave(fileName, lineCnt);
            break;
        }
    }
}