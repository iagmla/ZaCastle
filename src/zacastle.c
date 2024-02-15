#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include "common/common.c"
#include "hash/horakty.c"
#include "ciphers/akms26_cbc.c"

void usage() {
    printf("ZaCastle v0.02 - by KryptoMagick\n\n");
    printf("Algorithms:\n***********\nakms26-cbc       50!\n\n");
    printf("Usage:\nzacastle <algorithm> -e <input file> <output file> <passphrase>>\n");
    printf("zacastle <algorithm> -d <input file> <output file> <passphrase>\n");
}

int main(int argc, char *argv[]) {
    char *encrypt_symbol = "-e";
    char *decrypt_symbol = "-d";

    if (argc != 6) {
        usage();
        return 0;
    }
    char *algorithm = argv[1];
    char *mode = argv[2];
    char *infile_name = argv[3];
    char *outfile_name = argv[4];
    char *passphrase = argv[5];
    if (access(infile_name, F_OK) == -1 ) {
        printf("%s not found\n", infile_name);
        exit(1);
    }

    if (strcmp(algorithm, "akms26-cbc") == 0) {
        if (strcmp(mode, encrypt_symbol) == 0) {
            akms26_cbc_encrypt(infile_name, outfile_name, passphrase);
        }
        else if (strcmp(mode, decrypt_symbol) == 0) {
            akms26_cbc_decrypt(infile_name, outfile_name, passphrase);
        }
    }
    printf("\n");
    return 0;
}
