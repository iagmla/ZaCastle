int akms26_S0[26] = {8, 5, 2, 25, 22, 19, 16, 13, 10, 7, 4, 1, 24, 21, 18, 15, 12, 9, 6, 3, 0, 23, 20, 17, 14, 11};
int akms26_S0i[26] = {20, 11, 2, 19, 10, 1, 18, 9, 0, 17, 8, 25, 16, 7, 24, 15, 6, 23, 14, 5, 22, 13, 4, 21, 12, 3};

struct akms26_state {
    int S[5][5];
    int T[5][5];
    int K[16][5][5];
    int last[5][5];
    int next[5][5];
    int rounds;
};

void akms26_key_first_round(struct akms26_state *state, int *key26) {
    state->K[0][0][0] = key26[0];
    state->K[0][0][1] = key26[1];
    state->K[0][0][2] = key26[2];
    state->K[0][0][3] = key26[3];
    state->K[0][0][4] = key26[4];
    state->K[0][1][0] = key26[5];
    state->K[0][1][1] = key26[6];
    state->K[0][1][2] = key26[7];
    state->K[0][1][3] = key26[8];
    state->K[0][1][4] = key26[9];
    state->K[0][2][0] = key26[10];
    state->K[0][2][1] = key26[11];
    state->K[0][2][2] = key26[12];
    state->K[0][2][3] = key26[13];
    state->K[0][2][4] = key26[14];
    state->K[0][3][0] = key26[15];
    state->K[0][3][1] = key26[16];
    state->K[0][3][2] = key26[17];
    state->K[0][3][3] = key26[18];
    state->K[0][3][4] = key26[19];
    state->K[0][4][0] = key26[20];
    state->K[0][4][1] = key26[21];
    state->K[0][4][2] = key26[22];
    state->K[0][4][3] = key26[23];
    state->K[0][4][4] = key26[24];
}

void akms26_key_last_round(struct akms26_state *state, int *key26) {
    state->K[15][0][0] = key26[25];
    state->K[15][0][1] = key26[26];
    state->K[15][0][2] = key26[27];
    state->K[15][0][3] = key26[28];
    state->K[15][0][4] = key26[29];
    state->K[15][1][0] = key26[30];
    state->K[15][1][1] = key26[31];
    state->K[15][1][2] = key26[32];
    state->K[15][1][3] = key26[33];
    state->K[15][1][4] = key26[34];
    state->K[15][2][0] = key26[35];
    state->K[15][2][1] = key26[36];
    state->K[15][2][2] = key26[37];
    state->K[15][2][3] = key26[38];
    state->K[15][2][4] = key26[39];
    state->K[15][3][0] = key26[40];
    state->K[15][3][1] = key26[41];
    state->K[15][3][2] = key26[42];
    state->K[15][3][3] = key26[43];
    state->K[15][3][4] = key26[44];
    state->K[15][4][0] = key26[45];
    state->K[15][4][1] = key26[46];
    state->K[15][4][2] = key26[47];
    state->K[15][4][3] = key26[48];
    state->K[15][4][4] = key26[49];
}

void akms26_ksa(struct akms26_state *state, int *key26, int rounds) {
    akms26_key_first_round(state, key26);
    akms26_key_last_round(state, key26);
}

void akms26_sub_block(struct akms26_state *state) {
    state->S[0][0] = akms26_S0[state->S[0][0]];
    state->S[0][1] = akms26_S0[state->S[0][1]];
    state->S[0][2] = akms26_S0[state->S[0][2]];
    state->S[0][3] = akms26_S0[state->S[0][3]];
    state->S[0][4] = akms26_S0[state->S[0][4]];
    state->S[1][0] = akms26_S0[state->S[1][0]];
} 


void akms26_sub_block(struct akms26_state *state) {
    state->S[0][0] = akms26_S0[state->S[0][0]];
    state->S[0][1] = akms26_S0[state->S[0][1]];
    state->S[0][2] = akms26_S0[state->S[0][2]];
    state->S[0][3] = akms26_S0[state->S[0][3]];
    state->S[0][4] = akms26_S0[state->S[0][4]];
    state->S[1][0] = akms26_S0[state->S[1][0]];
    state->S[1][1] = akms26_S0[state->S[1][1]];
    state->S[1][2] = akms26_S0[state->S[1][2]];
    state->S[1][3] = akms26_S0[state->S[1][3]];
    state->S[1][4] = akms26_S0[state->S[1][4]];
    state->S[2][0] = akms26_S0[state->S[2][0]];
    state->S[2][1] = akms26_S0[state->S[2][1]];
    state->S[2][2] = akms26_S0[state->S[2][2]];
    state->S[2][3] = akms26_S0[state->S[2][3]];
    state->S[2][4] = akms26_S0[state->S[2][4]];
    state->S[3][0] = akms26_S0[state->S[3][0]];
    state->S[3][1] = akms26_S0[state->S[3][1]];
    state->S[3][2] = akms26_S0[state->S[3][2]];
    state->S[3][3] = akms26_S0[state->S[3][3]];
    state->S[3][4] = akms26_S0[state->S[3][4]];
    state->S[4][0] = akms26_S0[state->S[4][0]];
    state->S[4][1] = akms26_S0[state->S[4][1]];
    state->S[4][2] = akms26_S0[state->S[4][2]];
    state->S[4][3] = akms26_S0[state->S[4][3]];
    state->S[4][4] = akms26_S0[state->S[4][4]];
}

void akms26_sub_block_inv(struct akms26_state *state) {
    state->S[0][0] = akms26_S0i[state->S[0][0]];
    state->S[0][1] = akms26_S0i[state->S[0][1]];
    state->S[0][2] = akms26_S0i[state->S[0][2]];
    state->S[0][3] = akms26_S0i[state->S[0][3]];
    state->S[0][4] = akms26_S0i[state->S[0][4]];
    state->S[1][0] = akms26_S0i[state->S[1][0]];
    state->S[1][1] = akms26_S0i[state->S[1][1]];
    state->S[1][2] = akms26_S0i[state->S[1][2]];
    state->S[1][3] = akms26_S0i[state->S[1][3]];
    state->S[1][4] = akms26_S0i[state->S[1][4]];
    state->S[2][0] = akms26_S0i[state->S[2][0]];
    state->S[2][1] = akms26_S0i[state->S[2][1]];
    state->S[2][2] = akms26_S0i[state->S[2][2]];
    state->S[2][3] = akms26_S0i[state->S[2][3]];
    state->S[2][4] = akms26_S0i[state->S[2][4]];
    state->S[3][0] = akms26_S0i[state->S[3][0]];
    state->S[3][1] = akms26_S0i[state->S[3][1]];
    state->S[3][2] = akms26_S0i[state->S[3][2]];
    state->S[3][3] = akms26_S0i[state->S[3][3]];
    state->S[3][4] = akms26_S0i[state->S[3][4]];
    state->S[4][0] = akms26_S0i[state->S[4][0]];
    state->S[4][1] = akms26_S0i[state->S[4][1]];
    state->S[4][2] = akms26_S0i[state->S[4][2]];
    state->S[4][3] = akms26_S0i[state->S[4][3]];
    state->S[4][4] = akms26_S0i[state->S[4][4]];
}

void akms26_rotate_block(struct akms26_state *state) {
    int tmp;
    tmp = state->S[1][0];
    state->S[1][0] = state->S[1][1];
    state->S[1][1] = tmp;

    tmp = state->S[1][1];
    state->S[1][1] = state->S[1][2];
    state->S[1][2] = tmp;

    tmp = state->S[1][2];
    state->S[1][2] = state->S[1][3];
    state->S[1][3] = tmp;

    tmp = state->S[1][3];
    state->S[1][3] = state->S[1][4];
    state->S[1][4] = tmp;
}

void akms26_rotate_state(struct akms26_state *state) {
    memcpy(state->T[0], state->S[0], 5 * sizeof(int));
    memcpy(state->T[1], state->S[1], 5 * sizeof(int));
    memcpy(state->T[2], state->S[2], 5 * sizeof(int));
    memcpy(state->T[3], state->S[3], 5 * sizeof(int));
    memcpy(state->T[4], state->S[4], 5 * sizeof(int));

    memcpy(state->S[1], state->T[0], 5 * sizeof(int));
    memcpy(state->S[2], state->T[1], 5 * sizeof(int));
    memcpy(state->S[3], state->T[2], 5 * sizeof(int));
    memcpy(state->S[4], state->T[3], 5 * sizeof(int));
    memcpy(state->S[0], state->T[4], 5 * sizeof(int));
}

void akms26_rotate_state_inv(struct akms26_state *state) {
    memcpy(state->T[0], state->S[0], 5 * sizeof(int));
    memcpy(state->T[1], state->S[1], 5 * sizeof(int));
    memcpy(state->T[2], state->S[2], 5 * sizeof(int));
    memcpy(state->T[3], state->S[3], 5 * sizeof(int));
    memcpy(state->T[4], state->S[4], 5 * sizeof(int));

    memcpy(state->S[0], state->T[1], 5 * sizeof(int));
    memcpy(state->S[1], state->T[2], 5 * sizeof(int));
    memcpy(state->S[2], state->T[3], 5 * sizeof(int));
    memcpy(state->S[3], state->T[4], 5 * sizeof(int));
    memcpy(state->S[4], state->T[0], 5 * sizeof(int));
}

void akms26_mix0(struct akms26_state *state) {
    modadd26_block(state->S[2], 5, state->S[0]);
    modadd26_block(state->S[4], 5, state->S[2]);
    modadd26_block(state->S[1], 5, state->S[4]);
    modadd26_block(state->S[3], 5, state->S[1]);
    modadd26_block(state->S[0], 5, state->S[3]);
}

void akms26_mix0_inv(struct akms26_state *state) {
    modsub26_block(state->S[0], 5, state->S[3]);
    modsub26_block(state->S[3], 5, state->S[1]);
    modsub26_block(state->S[1], 5, state->S[4]);
    modsub26_block(state->S[4], 5, state->S[2]);
    modsub26_block(state->S[2], 5, state->S[0]);
}

void akms26_encrypt_block(struct akms26_state *state, int rounds) {
    for (int r = 0; r < rounds; r++) {
        akms26_sub_block(state);
        akms26_rotate_state(state);
        akms26_mix0(state);
    }
}

void akms26_decrypt_block(struct akms26_state *state, int rounds) {
    for (int r = rounds - 1; r != -1; r--) {
        akms26_mix0_inv(state);
        akms26_rotate_state_inv(state);
        akms26_sub_block_inv(state);
    }
}

void akms26_load_block(struct akms26_state *state, int *block) {
    state->S[0][0] = block[0];
    state->S[0][1] = block[1];
    state->S[0][2] = block[2];
    state->S[0][3] = block[3];
    state->S[0][4] = block[4];
    state->S[1][0] = block[5];
    state->S[1][1] = block[6];
    state->S[1][2] = block[7];
    state->S[1][3] = block[8];
    state->S[1][4] = block[9];
    state->S[2][0] = block[10];
    state->S[2][1] = block[11];
    state->S[2][2] = block[12];
    state->S[2][3] = block[13];
    state->S[2][4] = block[14];
    state->S[3][0] = block[15];
    state->S[3][1] = block[16];
    state->S[3][2] = block[17];
    state->S[3][3] = block[18];
    state->S[3][4] = block[19];
    state->S[4][0] = block[20];
    state->S[4][1] = block[21];
    state->S[4][2] = block[22];
    state->S[4][3] = block[23];
    state->S[4][4] = block[24];
}

void akms26_unload_block(struct akms26_state *state, int *block) {
    block[0] = state->S[0][0];
    block[1] = state->S[0][1];
    block[2] = state->S[0][2];
    block[3] = state->S[0][3];
    block[4] = state->S[0][4];
    block[5] = state->S[1][0];
    block[6] = state->S[1][1];
    block[7] = state->S[1][2];
    block[8] = state->S[1][3];
    block[9] = state->S[1][4];
    block[10] = state->S[2][0];
    block[11] = state->S[2][1];
    block[12] = state->S[2][2];
    block[13] = state->S[2][3];
    block[14] = state->S[2][4];
    block[15] = state->S[3][0];
    block[16] = state->S[3][1];
    block[17] = state->S[3][2];
    block[18] = state->S[3][3];
    block[19] = state->S[3][4];
    block[20] = state->S[4][0];
    block[21] = state->S[4][1];
    block[22] = state->S[4][2];
    block[23] = state->S[4][3];
    block[24] = state->S[4][4];
}

void akms26_cbc_load_iv(struct akms26_state *state, int *iv26) {
    state->last[0][0] = iv26[0];
    state->last[0][1] = iv26[1];
    state->last[0][2] = iv26[2];
    state->last[0][3] = iv26[3];
    state->last[0][4] = iv26[4];
    state->last[1][0] = iv26[5];
    state->last[1][1] = iv26[6];
    state->last[1][2] = iv26[7];
    state->last[1][3] = iv26[8];
    state->last[1][4] = iv26[9];
    state->last[2][0] = iv26[10];
    state->last[2][1] = iv26[11];
    state->last[2][2] = iv26[12];
    state->last[2][3] = iv26[13];
    state->last[2][4] = iv26[14];
    state->last[3][0] = iv26[15];
    state->last[3][1] = iv26[16];
    state->last[3][2] = iv26[17];
    state->last[3][3] = iv26[18];
    state->last[3][4] = iv26[19];
    state->last[4][0] = iv26[20];
    state->last[4][1] = iv26[21];
    state->last[4][2] = iv26[22];
    state->last[4][3] = iv26[23];
    state->last[4][4] = iv26[24];
}

void akms26_cbc_add(struct akms26_state *state) {
    state->S[0][0] = modadd26(state->S[0][0], state->last[0][0]);
    state->S[0][1] = modadd26(state->S[0][1], state->last[0][1]);
    state->S[0][2] = modadd26(state->S[0][2], state->last[0][2]);
    state->S[0][3] = modadd26(state->S[0][3], state->last[0][3]);
    state->S[0][4] = modadd26(state->S[0][4], state->last[0][4]);
    state->S[1][0] = modadd26(state->S[1][0], state->last[1][0]);
    state->S[1][1] = modadd26(state->S[1][1], state->last[1][1]);
    state->S[1][2] = modadd26(state->S[1][2], state->last[1][2]);
    state->S[1][3] = modadd26(state->S[1][3], state->last[1][3]);
    state->S[1][4] = modadd26(state->S[1][4], state->last[1][4]);
    state->S[2][0] = modadd26(state->S[2][0], state->last[2][0]);
    state->S[2][1] = modadd26(state->S[2][1], state->last[2][1]);
    state->S[2][2] = modadd26(state->S[2][2], state->last[2][2]);
    state->S[2][3] = modadd26(state->S[2][3], state->last[2][3]);
    state->S[2][4] = modadd26(state->S[2][4], state->last[2][4]);
    state->S[3][0] = modadd26(state->S[3][0], state->last[3][0]);
    state->S[3][1] = modadd26(state->S[3][1], state->last[3][1]);
    state->S[3][2] = modadd26(state->S[3][2], state->last[3][2]);
    state->S[3][3] = modadd26(state->S[3][3], state->last[3][3]);
    state->S[3][4] = modadd26(state->S[3][4], state->last[3][4]);
    state->S[4][0] = modadd26(state->S[4][0], state->last[4][0]);
    state->S[4][1] = modadd26(state->S[4][1], state->last[4][1]);
    state->S[4][2] = modadd26(state->S[4][2], state->last[4][2]);
    state->S[4][3] = modadd26(state->S[4][3], state->last[4][3]);
    state->S[4][4] = modadd26(state->S[4][4], state->last[4][4]);
}

void akms26_cbc_next(struct akms26_state *state) {
    memcpy(state->last, state->S, 25 * sizeof(int));
}

void akms26_cbc_next_inv(struct akms26_state *state) {
    memcpy(state->next, state->S, 25 * sizeof(int));
}

void akms26_cbc_last_inv(struct akms26_state *state) {
    memcpy(state->last, state->next, 25 * sizeof(int));
}

void akms26_cbc_sub(struct akms26_state *state) {
    state->S[0][0] = modsub26(state->S[0][0], state->last[0][0]);
    state->S[0][1] = modsub26(state->S[0][1], state->last[0][1]);
    state->S[0][2] = modsub26(state->S[0][2], state->last[0][2]);
    state->S[0][3] = modsub26(state->S[0][3], state->last[0][3]);
    state->S[0][4] = modsub26(state->S[0][4], state->last[0][4]);
    state->S[1][0] = modsub26(state->S[1][0], state->last[1][0]);
    state->S[1][1] = modsub26(state->S[1][1], state->last[1][1]);
    state->S[1][2] = modsub26(state->S[1][2], state->last[1][2]);
    state->S[1][3] = modsub26(state->S[1][3], state->last[1][3]);
    state->S[1][4] = modsub26(state->S[1][4], state->last[1][4]);
    state->S[2][0] = modsub26(state->S[2][0], state->last[2][0]);
    state->S[2][1] = modsub26(state->S[2][1], state->last[2][1]);
    state->S[2][2] = modsub26(state->S[2][2], state->last[2][2]);
    state->S[2][3] = modsub26(state->S[2][3], state->last[2][3]);
    state->S[2][4] = modsub26(state->S[2][4], state->last[2][4]);
    state->S[3][0] = modsub26(state->S[3][0], state->last[3][0]);
    state->S[3][1] = modsub26(state->S[3][1], state->last[3][1]);
    state->S[3][2] = modsub26(state->S[3][2], state->last[3][2]);
    state->S[3][3] = modsub26(state->S[3][3], state->last[3][3]);
    state->S[3][4] = modsub26(state->S[3][4], state->last[3][4]);
    state->S[4][0] = modsub26(state->S[4][0], state->last[4][0]);
    state->S[4][1] = modsub26(state->S[4][1], state->last[4][1]);
    state->S[4][2] = modsub26(state->S[4][2], state->last[4][2]);
    state->S[4][3] = modsub26(state->S[4][3], state->last[4][3]);
    state->S[4][4] = modsub26(state->S[4][4], state->last[4][4]);
}

void akms26_cbc_encrypt(char *inputfile, char *outputfile, char *passphrase) {
    struct akms26_state state;
    state.rounds = 16;
    int blocklen = 25;
    int bufsize = 25;
    FILE *infile, *outfile;
    int iv26[blocklen];
    uint8_t iv[blocklen];
    urandom26(iv26, blocklen);
    akms26_cbc_load_iv(&state, iv26);
    infile = fopen(inputfile, "rb");
    outfile = fopen(outputfile, "wb");
    convert_block_to_char(iv26, blocklen, iv);
    fwrite(iv, 1, blocklen, outfile);
    fseek(infile, 0, SEEK_END);
    uint32_t datalen = ftell(infile);
    datalen -= 1;
    fseek(infile, 0, SEEK_SET);
    uint32_t blocks = datalen / blocklen;
    int extra = datalen % blocklen;
    int extraletters = blocklen - (datalen % blocklen);
    if (extra != 0) {
       blocks += 1;
    }
    for (uint32_t b = 0; b < blocks; b++) {
        uint8_t block[25];
        int block26[25];
        if ((b == (blocks - 1)) && (extra != 0)) {
            bufsize = extra;
            for (int p = 0; p < extraletters; p++) {
                block26[(blocklen-1-p)] = (int *)extraletters;
            }
        }
        fread(block, 1, bufsize, infile);
        convert_block_to_int(block, bufsize, block26);
        akms26_load_block(&state, block26);
        akms26_cbc_add(&state);
        akms26_encrypt_block(&state, state.rounds);
        akms26_cbc_next(&state);
        akms26_unload_block(&state, block26);
        convert_block_to_char(block26, blocklen, block);
        fwrite(block, 1, blocklen, outfile);
    }
    fclose(infile);
    fclose(outfile);
} 

void akms26_cbc_decrypt(char *inputfile, char *outputfile, char *passphrase) {
    struct akms26_state state;
    state.rounds = 16;
    int blocklen = 25;
    int bufsize = 25;
    FILE *infile, *outfile;
    int iv26[blocklen];
    uint8_t iv[blocklen];
    infile = fopen(inputfile, "rb");
    fseek(infile, 0, SEEK_END);
    uint32_t datalen = ftell(infile);
    datalen -= blocklen;
    fseek(infile, 0, SEEK_SET);
    fread(iv, 1, blocklen, infile);
    convert_block_to_int(iv, blocklen, iv26);
    akms26_cbc_load_iv(&state, iv26);
    uint32_t blocks = datalen / blocklen;
    int extra = datalen % blocklen;
    int extraletters = blocklen - (datalen % blocklen);
    outfile = fopen(outputfile, "wb");
    if (extra != 0) {
       blocks += 1;
    }
    for (uint32_t b = 0; b < blocks; b++) {
        uint8_t block[25];
        int block26[25];
        fread(block, 1, bufsize, infile);
        convert_block_to_int(block, bufsize, block26);
        akms26_load_block(&state, block26);
        akms26_cbc_next_inv(&state);
        akms26_decrypt_block(&state, state.rounds);
        akms26_cbc_sub(&state);
        akms26_cbc_last_inv(&state);
        akms26_unload_block(&state, block26);
        if (b == (blocks - 1)) {
            int padcheck = block26[blocklen - 1];
            int g = blocklen - 1;
            int count = 0;
            for (int p = 0; p < padcheck; p++) {
                if ((int)block26[g] == padcheck) {
                    count += 1;
                }
                g = g - 1;
            }
            if (padcheck == count) {
                blocklen = blocklen - count;
            }
        }
        convert_block_to_char(block26, blocklen, block);
        fwrite(block, 1, blocklen, outfile);
    }
    fclose(infile);
    fclose(outfile);
} 
