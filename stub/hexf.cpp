#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
yasm.exe E:\codes\IAT_patcher\stub\stub64.asm



*/

int main(int argc, char* argv[])
{
    if (argc < 2) {
        printf("No fileName supplied!\n");
        return -1;
    }
    FILE *fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        printf("Unable to open the file!\n");
        return -1;
    }
    int brk = 4;
    int i = 0;

    char c = 0;
    while(!feof(fp)) {
        c = fgetc (fp);
		if (c == EOF) {
			//break;
		}
        if (i == brk) {
            i = 0;
            printf("\n");
        }
        i++;
        printf("0x%2.2x, ", c & 0x0FF);
    }
    printf("0x90\n");
    return 0;
}

