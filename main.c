#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char *pc = NULL;
    int i = 0;

    pc = (char*)malloc(100 * sizeof(char));
    if (pc == NULL) {
        printf("error\n");
        exit(1);
    }

    for (i = 0; i < 26; i++) {
        pc[i] = 'a' + i;
    }
    pc[i] = 0;              // i가 26이 된 상태 → pc[26]에 널 문자('\0', ASCII 0) 저장

    printf("%s\n", pc);     // "abcdefghijklmnopqrstuvwxyz" 출력
    free(pc);
    
    return 0;
}