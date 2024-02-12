int modadd26(int a, int b) {
    int x = (a + b) % 26;
    if (x < 0) {
        x += 26;
    }
    return x;
}

int modsub26(int a, int b) {
    int x = (a - b) % 26;
    if (x < 0) {
        x += 26;
    }
    return x;
}

int modmul26(int a, int b) {
    int x = (a * b) % 26;
    if (x < 0) {
        x += 26;
    }
    return x;
}

int affine_add26(int a, int b, int c) {
    int x = ((a * b) + c) % 26;
    if (x < 0) {
        x += 26;
    }
    return x;
}

int convert_to_int(uint8_t x) {
    return (int)x - 65;
}

uint8_t convert_to_char(int x) {
    return (uint8_t)x + 65;
}

void convert_block_to_int(uint8_t *block, int blocklen, int *x) {
    for (int i = 0; i < blocklen; i++) {
        x[i] = convert_to_int(block[i]);
    }
}

void convert_block_to_char(int *block, int blocklen, uint8_t *x) {
    for (int i = 0; i < blocklen; i++) {
        x[i] = convert_to_char(block[i]);
    }
}

void modadd26_block(int *blockA, int blocklen, int *blockB) {
    for (int i = 0; i < blocklen; i++) {
        blockA[i] = modadd26(blockA[i], blockB[i]);
    }
}

void modsub26_block(int *blockA, int blocklen, int *blockB) {
    for (int i = 0; i < blocklen; i++) {
        blockA[i] = modsub26(blockA[i], blockB[i]);
    }
}

void rotate_block_left(int *block, int blocklen, int n) {
    int tmp;
    for (int i = 0; i < n; i++) {
        for (int x = 0; x < blocklen - 1; x++) {
            tmp = block[x];
            block[x] = block[x + 1];
            block[x+1] = tmp;
        }
    }
}

void rotate_block_right(int *block, int blocklen, int n) {
    int tmp;
    for (int i = 0; i < n; i++) {
        for (int x = blocklen - 1; x != 0; x--) {
            tmp = block[x];
            block[x] = block[x - 1];
            block[x-1] = tmp;
        }
    }
}

void urandom26 (int *block, int num_bytes) {
    FILE *randfile;
    randfile = fopen("/dev/urandom", "rb");
    int c = 0;
    uint8_t buf[1];
    while (c != num_bytes) {
        fread(buf, 1, 1, randfile);
        if ((buf[0] >= 0) && (buf[0] <= 25)) {
            block[c] = buf[0];
            c += 1;
        }
    }
    printf("%d\n", c);
    fclose(randfile);
}
