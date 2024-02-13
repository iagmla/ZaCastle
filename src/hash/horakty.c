int horakty_C0[52] = {19, 13, 20, 12, 3, 21, 25, 3, 8, 25, 2, 7, 4, 18, 13, 2, 21, 11, 0, 21, 20, 5, 17, 22, 14, 2, 21, 7, 6, 12, 14, 25, 23, 7, 13, 23, 9, 1, 16, 8, 4, 22, 23, 15, 11, 17, 21, 0, 15, 5, 15, 11};
int horakty_R0[8] = {15, 6, 3, 45, 28, 36, 21, 10};
int horakty_R1[8] = {12, 7, 19, 30, 49, 4, 22, 2};

struct horakty_state {
   int S[52];
   int T[52];
   int rounds;
   int outputlen;
};

void horakty_init(struct horakty_state * state) {
    memcpy(state->S, horakty_C0, 52 * sizeof(int));
}

void horakty_mix0(struct horakty_state *state) {
    state->S[51] = modadd26(state->S[51], state->S[16]);
    state->S[18] = modadd26(state->S[18], state->S[51]);
    state->S[23] = modadd26(state->S[23], state->S[18]);
    state->S[43] = modadd26(state->S[43], state->S[23]);
    state->S[11] = modadd26(state->S[11], state->S[43]);
    state->S[29] = modadd26(state->S[29], state->S[11]);
    state->S[38] = modadd26(state->S[38], state->S[29]);
    state->S[5] = modadd26(state->S[5], state->S[38]);
    state->S[47] = modadd26(state->S[47], state->S[5]);
    state->S[37] = modadd26(state->S[37], state->S[47]);
    state->S[48] = modadd26(state->S[48], state->S[37]);
    state->S[9] = modadd26(state->S[9], state->S[48]);
    state->S[49] = modadd26(state->S[49], state->S[9]);
    state->S[36] = modadd26(state->S[36], state->S[49]);
    state->S[15] = modadd26(state->S[15], state->S[36]);
    state->S[33] = modadd26(state->S[33], state->S[15]);
    state->S[41] = modadd26(state->S[41], state->S[33]);
    state->S[35] = modadd26(state->S[35], state->S[41]);
    state->S[21] = modadd26(state->S[21], state->S[35]);
    state->S[14] = modadd26(state->S[14], state->S[21]);
    state->S[2] = modadd26(state->S[2], state->S[14]);
    state->S[26] = modadd26(state->S[26], state->S[2]);
    state->S[44] = modadd26(state->S[44], state->S[26]);
    state->S[24] = modadd26(state->S[24], state->S[44]);
    state->S[28] = modadd26(state->S[28], state->S[24]);
    state->S[30] = modadd26(state->S[30], state->S[28]);
    state->S[3] = modadd26(state->S[3], state->S[30]);
    state->S[20] = modadd26(state->S[20], state->S[3]);
    state->S[45] = modadd26(state->S[45], state->S[20]);
    state->S[25] = modadd26(state->S[25], state->S[45]);
    state->S[42] = modadd26(state->S[42], state->S[25]);
    state->S[1] = modadd26(state->S[1], state->S[42]);
    state->S[31] = modadd26(state->S[31], state->S[1]);
    state->S[27] = modadd26(state->S[27], state->S[31]);
    state->S[10] = modadd26(state->S[10], state->S[27]);
    state->S[19] = modadd26(state->S[19], state->S[10]);
    state->S[40] = modadd26(state->S[40], state->S[19]);
    state->S[12] = modadd26(state->S[12], state->S[40]);
    state->S[4] = modadd26(state->S[4], state->S[12]);
    state->S[8] = modadd26(state->S[8], state->S[4]);
    state->S[22] = modadd26(state->S[22], state->S[8]);
    state->S[0] = modadd26(state->S[0], state->S[22]);
    state->S[39] = modadd26(state->S[39], state->S[0]);
    state->S[34] = modadd26(state->S[34], state->S[39]);
    state->S[7] = modadd26(state->S[7], state->S[34]);
    state->S[6] = modadd26(state->S[6], state->S[7]);
    state->S[32] = modadd26(state->S[32], state->S[6]);
    state->S[13] = modadd26(state->S[13], state->S[32]);
    state->S[46] = modadd26(state->S[46], state->S[13]);
    state->S[50] = modadd26(state->S[50], state->S[46]);
    state->S[17] = modadd26(state->S[17], state->S[50]);
    state->S[16] = modadd26(state->S[16], state->S[17]);
}

void horakty_mix1(struct horakty_state *state) {
    state->S[40] = modadd26(state->S[40], state->S[1]);
    state->S[0] = modadd26(state->S[0], state->S[2]);
    state->S[5] = modadd26(state->S[5], state->S[3]);
    state->S[22] = modadd26(state->S[22], state->S[4]);
    state->S[39] = modadd26(state->S[39], state->S[5]);
    state->S[43] = modadd26(state->S[43], state->S[6]);
    state->S[50] = modadd26(state->S[50], state->S[7]);
    state->S[28] = modadd26(state->S[28], state->S[8]);
    state->S[14] = modadd26(state->S[14], state->S[9]);
    state->S[42] = modadd26(state->S[42], state->S[10]);
    state->S[8] = modadd26(state->S[8], state->S[11]);
    state->S[23] = modadd26(state->S[23], state->S[12]);
    state->S[17] = modadd26(state->S[17], state->S[13]);
    state->S[12] = modadd26(state->S[12], state->S[14]);
    state->S[29] = modadd26(state->S[29], state->S[15]);
    state->S[36] = modadd26(state->S[36], state->S[16]);
    state->S[33] = modadd26(state->S[33], state->S[17]);
    state->S[47] = modadd26(state->S[47], state->S[18]);
    state->S[13] = modadd26(state->S[13], state->S[19]);
    state->S[1] = modadd26(state->S[1], state->S[20]);
    state->S[44] = modadd26(state->S[44], state->S[21]);
    state->S[24] = modadd26(state->S[24], state->S[22]);
    state->S[10] = modadd26(state->S[10], state->S[23]);
    state->S[31] = modadd26(state->S[31], state->S[24]);
    state->S[4] = modadd26(state->S[4], state->S[25]);
    state->S[16] = modadd26(state->S[16], state->S[26]);
    state->S[18] = modadd26(state->S[18], state->S[27]);
    state->S[6] = modadd26(state->S[6], state->S[28]);
    state->S[27] = modadd26(state->S[27], state->S[29]);
    state->S[34] = modadd26(state->S[34], state->S[30]);
    state->S[46] = modadd26(state->S[46], state->S[31]);
    state->S[21] = modadd26(state->S[21], state->S[32]);
    state->S[38] = modadd26(state->S[38], state->S[33]);
    state->S[20] = modadd26(state->S[20], state->S[34]);
    state->S[25] = modadd26(state->S[25], state->S[35]);
    state->S[26] = modadd26(state->S[26], state->S[36]);
    state->S[35] = modadd26(state->S[35], state->S[37]);
    state->S[32] = modadd26(state->S[32], state->S[38]);
    state->S[48] = modadd26(state->S[48], state->S[39]);
    state->S[9] = modadd26(state->S[9], state->S[40]);
    state->S[30] = modadd26(state->S[30], state->S[41]);
    state->S[51] = modadd26(state->S[51], state->S[42]);
    state->S[7] = modadd26(state->S[7], state->S[43]);
    state->S[15] = modadd26(state->S[15], state->S[44]);
    state->S[45] = modadd26(state->S[45], state->S[45]);
    state->S[2] = modadd26(state->S[2], state->S[46]);
    state->S[19] = modadd26(state->S[19], state->S[47]);
    state->S[41] = modadd26(state->S[41], state->S[48]);
    state->S[3] = modadd26(state->S[3], state->S[49]);
    state->S[37] = modadd26(state->S[37], state->S[50]);
    state->S[11] = modadd26(state->S[11], state->S[51]);
    state->S[49] = modadd26(state->S[49], state->S[0]);
}

void horakty_mix2(struct horakty_state *state) {
    for (int i = 0; i < 52; i++) {
        state->S[i] = modadd26(state->S[i], state->S[(i + 26) % 52]);
    }
}

void horakty_mix3(struct horakty_state *state) {
    for (int i = 0; i < 52; i++) {
        state->S[i] = modadd26(state->S[i], state->T[i]);
    }
}

void horakty_absorb(struct horakty_state *state, int *block) {
    for (int i = 0; i < 26; i++) {
        state->S[i] = modadd26(state->S[i], block[i]);
    }
}

void horakty_round(struct horakty_state *state, int round) {
    horakty_mix0(state);
    rotate_block_left(state->S, 52, horakty_R0[round % 8]);
    horakty_mix1(state);
    //rotate_block_right(state->S, 52, horakty_R1[round % 8]);
    horakty_mix2(state);
    rotate_block_left(state->S, 52, horakty_R1[round % 8]);
    //rotate_block_left(state->S, 52, 1);
}

void horakty_rounds(struct horakty_state *state) {
    memcpy(state->T, state->S, 52 * sizeof(int));
    for (int r = 0; r < state->rounds; r++) {
        horakty_round(state, r);
    }
    horakty_mix3(state);
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
