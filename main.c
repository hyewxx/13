#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    int number;
    char title[10];
};

void main(void) {
    int i;
    struct Book **bookshelf;

    // 1) 포인터 3개(행 3개) 동적 할당
    bookshelf = (struct Book **)malloc(3 * sizeof(struct Book *));
    if (bookshelf == NULL) {
        return;
    }

    // 2) 각 행마다 Book 구조체 10개(열 10개) 동적 할당
    for (i = 0; i < 3; i++) {
        bookshelf[i] = (struct Book *)malloc(10 * sizeof(struct Book));
    }

    // 3) 데이터 저장 및 출력
    bookshelf[1][3].number = 5;
    strcpy(bookshelf[1][3].title, "C++ Programming");

    (bookshelf[2] + 4)->number = 3;
    strcpy((bookshelf[2] + 4)->title, "Communications Theory");

    printf("book (1,3) : %i, %s\n", (bookshelf[1] + 3)->number, (bookshelf[1] + 3)->title);
    printf("book (2,4) : %i, %s\n", bookshelf[2][4].number, bookshelf[2][4].title);

    // 4) 2차원 구조체 메모리 반납
    for (i = 0; i < 3; i++) 
        free(bookshelf[i]);
    free(bookshelf);
}