int horakty_C0[52] = {19, 13, 20, 12, 3, 21, 25, 3, 8, 25, 2, 7, 4, 18, 13, 2, 21, 11, 0, 21, 20, 5, 17, 22, 14, 2, 21, 7, 6, 12, 14, 25, 23, 7, 13, 23, 9, 1, 16, 8, 4, 22, 23, 15, 11, 17, 21, 0, 15, 5, 15, 11};

struct horakty_state {
   int S[4][13];
   int T[4][13];
   int rounds;
   int outputlen;
};

void horakty_init(struct horakty_state *state) {
    memcpy(state->S, horakty_C0, 52 * sizeof(int));
}

void horakty_mix0(struct horakty_state *state) {
    modadd26_block(state->S[0], 13, state->S[2]);
    rotate_block_left(state->S[0], 13, 3);
    modadd26_block(state->S[3], 13, state->S[0]);
    rotate_block_right(state->S[1], 13, 6);
    modadd26_block(state->S[2], 13, state->S[3]);
    rotate_block_left(state->S[2], 13, 10);
    modadd26_block(state->S[1], 13, state->S[2]);
    rotate_block_right(state->S[3], 13, 2);
}

void horakty_round(struct horakty_state *state) {
    horakty_mix0(state);
}

void horakty_rounds(struct horakty_state *state) {
    memcpy(state->T, state->S, 52 * sizeof(int));
    for (int r = 0; r < state->rounds; r++) {
        horakty_round(state);
    }
    modadd26_block(state->S[0], 13, state->T[0]);
    modadd26_block(state->S[1], 13, state->T[1]);
    modadd26_block(state->S[2], 13, state->T[2]);
    modadd26_block(state->S[3], 13, state->T[3]);
}

void horakty_absorb(struct horakty_state *state, int *block) {
    state->S[0][0] = modadd26(state->S[0][0], block[0]);
    state->S[0][1] = modadd26(state->S[0][1], block[1]);
    state->S[0][2] = modadd26(state->S[0][2], block[2]);
    state->S[0][3] = modadd26(state->S[0][3], block[3]);
    state->S[0][4] = modadd26(state->S[0][4], block[4]);
    state->S[0][5] = modadd26(state->S[0][5], block[5]);
    state->S[0][6] = modadd26(state->S[0][6], block[6]);
    state->S[0][7] = modadd26(state->S[0][7], block[7]);
    state->S[0][8] = modadd26(state->S[0][8], block[8]);
    state->S[0][9] = modadd26(state->S[0][9], block[9]);
    state->S[0][10] = modadd26(state->S[0][10], block[10]);
    state->S[0][11] = modadd26(state->S[0][11], block[11]);
    state->S[0][12] = modadd26(state->S[0][12], block[12]);

    state->S[1][0] = modadd26(state->S[1][0], block[13]);
    state->S[1][1] = modadd26(state->S[1][1], block[14]);
    state->S[1][2] = modadd26(state->S[1][2], block[15]);
    state->S[1][3] = modadd26(state->S[1][3], block[16]);
    state->S[1][4] = modadd26(state->S[1][4], block[17]);
    state->S[1][5] = modadd26(state->S[1][5], block[18]);
    state->S[1][6] = modadd26(state->S[1][6], block[19]);
    state->S[1][7] = modadd26(state->S[1][7], block[20]);
    state->S[1][8] = modadd26(state->S[1][8], block[21]);
    state->S[1][9] = modadd26(state->S[1][9], block[22]);
    state->S[1][10] = modadd26(state->S[1][10], block[23]);
    state->S[1][11] = modadd26(state->S[1][11], block[24]);
    state->S[1][12] = modadd26(state->S[1][12], block[25]);
}

void horakty_output(struct horakty_state *state, int *output, int outputlen) {
    memcpy(output, state->S, outputlen * sizeof(int));
}

void horakty_kdf(char *input, int *output, int outputlen, int iters) {
    int blocklen = 26;
    struct horakty_state state;
    state.rounds = 64;
    horakty_init(&state);
    int inputlen = strlen(input);
    int input_int[inputlen];
    convert_block_to_int(input, strlen(input), input_int);
    int blocks = inputlen / blocklen;
    int extra = inputlen % blocklen;
    if (extra != 0) {
        blocks += 1;
    }
    int c = 0;
    for (int b = 0; b < blocks; b++) {
        int block26[26] = {0};
        if (b == (blocks - 1) && (extra != 0)) {
            blocklen = extra;
        }
        for (int x = 0; x < blocklen; x++) {
            block26[x] = input_int[c];
            c += 1;
        }
        horakty_absorb(&state, block26);
        horakty_rounds(&state);
    }
    for (int i = 0; i < iters; i++) {
        horakty_rounds(&state);
    }
    horakty_output(&state, output, outputlen);
}

/* For testing purposes only */

void horakty_crypt(char *outputfile, char *passphrase) {
    int blocklen = 26;
    struct horakty_state state;
    state.rounds = 64;
    horakty_init(&state);
    int key[52];
    horakty_kdf(passphrase, key, 52, 10000);
    int inputlen = 1000000;
    FILE *outfile;
    outfile = fopen(outputfile, "wb");
    int blocks = inputlen / blocklen;
    int extra = inputlen % blocklen;
    if (extra != 0) {
        blocks += 1;
    }
    int c = 0;
    for (int b = 0; b < blocks; b++) {
        int block26[52] = {0};
        if (b == (blocks - 1) && (extra != 0)) {
            blocklen = extra;
        }
        horakty_rounds(&state);
        memcpy(block26, state.S, 52 * sizeof(int));
        uint8_t block[52];
        convert_block_to_char(block26, 52, block);
        fwrite(block, 1, 52, outfile);
    }
    fclose(outfile);
}
