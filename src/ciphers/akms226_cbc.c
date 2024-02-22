struct akms226_state {
    int L[13];
    int R[13];
    int T0[13];
    int K[16][2][13];
    int last[2][13];
    int next[2][13];
    int rounds;
};

void akms226_load_block(struct akms226_state *state, int *block26) {
    state->L[0] = block26[0];
    state->L[1] = block26[1];
    state->L[2] = block26[2];
    state->L[3] = block26[3];
    state->L[4] = block26[4];
    state->L[5] = block26[5];
    state->L[6] = block26[6];
    state->L[7] = block26[7];
    state->L[8] = block26[8];
    state->L[9] = block26[9];
    state->L[10] = block26[10];
    state->L[11] = block26[11];
    state->L[12] = block26[12];

    state->R[0] = block26[13];
    state->R[1] = block26[14];
    state->R[2] = block26[15];
    state->R[3] = block26[16];
    state->R[4] = block26[17];
    state->R[5] = block26[18];
    state->R[6] = block26[19];
    state->R[7] = block26[20];
    state->R[8] = block26[21];
    state->R[9] = block26[22];
    state->R[10] = block26[23];
    state->R[11] = block26[24];
    state->R[12] = block26[25];
}

void akms226_unload_block(struct akms226_state *state, int *block26) {
    block26[0] = state->L[0];
    block26[1] = state->L[1];
    block26[2] = state->L[2];
    block26[3] = state->L[3];
    block26[4] = state->L[4];
    block26[5] = state->L[5];
    block26[6] = state->L[6];
    block26[7] = state->L[7];
    block26[8] = state->L[8];
    block26[9] = state->L[9];
    block26[10] = state->L[10];
    block26[11] = state->L[11];
    block26[12] = state->L[12];

    block26[13] = state->R[0];
    block26[14] = state->R[1];
    block26[15] = state->R[2];
    block26[16] = state->R[3];
    block26[17] = state->R[4];
    block26[18] = state->R[5];
    block26[19] = state->R[6];
    block26[20] = state->R[7];
    block26[21] = state->R[8];
    block26[22] = state->R[9];
    block26[23] = state->R[10];
    block26[24] = state->R[11];
    block26[25] = state->R[12];
}

void akms226_F(struct akms226_state *state, int r) {
    state->R[0] = modadd26(akms26_S0[state->L[0]], state->R[0]);
    state->R[1] = modadd26(akms26_S0[state->L[1]], state->R[1]);
    state->R[2] = modadd26(akms26_S0[state->L[2]], state->R[2]);
    state->R[3] = modadd26(akms26_S0[state->L[3]], state->R[3]);
    state->R[4] = modadd26(akms26_S0[state->L[4]], state->R[4]);
    state->R[5] = modadd26(akms26_S0[state->L[5]], state->R[5]);
    state->R[6] = modadd26(akms26_S0[state->L[6]], state->R[6]);
    state->R[7] = modadd26(akms26_S0[state->L[7]], state->R[7]);
    state->R[8] = modadd26(akms26_S0[state->L[8]], state->R[8]);
    state->R[9] = modadd26(akms26_S0[state->L[9]], state->R[9]);
    state->R[10] = modadd26(akms26_S0[state->L[10]], state->R[10]);
    state->R[11] = modadd26(akms26_S0[state->L[11]], state->R[11]);
    state->R[12] = modadd26(akms26_S0[state->L[12]], state->R[12]);

    modadd26_block(state->L, 13, state->K[r][0]);
    modadd26_block(state->R, 13, state->K[r][1]);

    memcpy(state->T0, state->R, 13 * sizeof(int));
    memcpy(state->R, state->L, 13 * sizeof(int));
    memcpy(state->L, state->T0, 13 * sizeof(int));

}

void akms226_F_inv(struct akms226_state *state, int r) {
    memcpy(state->T0, state->R, 13 * sizeof(int));
    memcpy(state->R, state->L, 13 * sizeof(int));
    memcpy(state->L, state->T0, 13 * sizeof(int));

    modsub26_block(state->R, 13, state->K[r][1]);
    modsub26_block(state->L, 13, state->K[r][0]);

    state->R[0] = modsub26(state->R[0], akms26_S0[state->L[0]]);
    state->R[1] = modsub26(state->R[1], akms26_S0[state->L[1]]);
    state->R[2] = modsub26(state->R[2], akms26_S0[state->L[2]]);
    state->R[3] = modsub26(state->R[3], akms26_S0[state->L[3]]);
    state->R[4] = modsub26(state->R[4], akms26_S0[state->L[4]]);
    state->R[5] = modsub26(state->R[5], akms26_S0[state->L[5]]);
    state->R[6] = modsub26(state->R[6], akms26_S0[state->L[6]]);
    state->R[7] = modsub26(state->R[7], akms26_S0[state->L[7]]);
    state->R[8] = modsub26(state->R[8], akms26_S0[state->L[8]]);
    state->R[9] = modsub26(state->R[9], akms26_S0[state->L[9]]);
    state->R[10] = modsub26(state->R[10], akms26_S0[state->L[10]]);
    state->R[11] = modsub26(state->R[11], akms26_S0[state->L[11]]);
    state->R[12] = modsub26(state->R[12], akms26_S0[state->L[12]]);

}

void akms226_F2(struct akms226_state * state) {
    modadd26_block(state->L, 13, state->R);
    modadd26_block(state->R, 13, state->L);
    rotate_block_left(state->L, 13, 4);
    rotate_block_right(state->L, 13, 3);
}

void akms226_F2_inv(struct akms226_state * state) {
    rotate_block_left(state->L, 13, 3);
    rotate_block_right(state->L, 13, 4);
    modsub26_block(state->R, 13, state->L);
    modsub26_block(state->L, 13, state->R);
}

void akms226_F3(struct akms226_state *state) {
    state->L[10] = modadd26(state->L[10], state->L[4]);
    state->L[5] = modadd26(state->L[5], state->L[9]);
    state->L[7] = modadd26(state->L[7], state->L[10]);
    state->L[0] = modadd26(state->L[0], state->L[8]);
    state->L[4] = modadd26(state->L[4], state->L[0]);
    state->L[3] = modadd26(state->L[3], state->L[1]);
    state->L[1] = modadd26(state->L[1], state->L[7]);
    state->L[8] = modadd26(state->L[8], state->L[11]);
    state->L[11] = modadd26(state->L[11], state->L[5]);
    state->L[2] = modadd26(state->L[2], state->L[12]);
    state->L[12] = modadd26(state->L[12], state->L[3]);
    state->L[6] = modadd26(state->L[6], state->L[2]);
    state->L[9] = modadd26(state->L[9], state->L[6]);
}

void akms226_F3_inv(struct akms226_state *state) {
    state->L[9] = modsub26(state->L[9], state->L[6]);
    state->L[6] = modsub26(state->L[6], state->L[2]);
    state->L[12] = modsub26(state->L[12], state->L[3]);
    state->L[2] = modsub26(state->L[2], state->L[12]);
    state->L[11] = modsub26(state->L[11], state->L[5]);
    state->L[8] = modsub26(state->L[8], state->L[11]);
    state->L[1] = modsub26(state->L[1], state->L[7]);
    state->L[3] = modsub26(state->L[3], state->L[1]);
    state->L[4] = modsub26(state->L[4], state->L[0]);
    state->L[0] = modsub26(state->L[0], state->L[8]);
    state->L[7] = modsub26(state->L[7], state->L[10]);
    state->L[5] = modsub26(state->L[5], state->L[9]);
    state->L[10] = modsub26(state->L[10], state->L[4]);
}

void akms226_encrypt_block(struct akms226_state * state) {
    for (int r = 0; r < state->rounds; r++) {
        akms226_F(state, r);
        akms226_F3(state);
        akms226_F2(state);
    }
}

void akms226_decrypt_block(struct akms226_state * state) {
    for (int r = state->rounds - 1; r != -1; r--) {
        akms226_F2_inv(state);
        akms226_F3_inv(state);
        akms226_F_inv(state, r);
    }
}

void akms226_key_load(struct akms226_state * state, int *key) {
    state->K[0][0][0] = key[0];
    state->K[0][0][1] = key[1];
    state->K[0][0][2] = key[2];
    state->K[0][0][3] = key[3];
    state->K[0][0][4] = key[4];
    state->K[0][0][5] = key[5];
    state->K[0][0][6] = key[6];
    state->K[0][0][7] = key[7];
    state->K[0][0][8] = key[8];
    state->K[0][0][9] = key[9];
    state->K[0][0][10] = key[10];
    state->K[0][0][11] = key[11];
    state->K[0][0][12] = key[12];

    state->K[0][1][0] = key[13];
    state->K[0][1][1] = key[14];
    state->K[0][1][2] = key[15];
    state->K[0][1][3] = key[16];
    state->K[0][1][4] = key[17];
    state->K[0][1][5] = key[18];
    state->K[0][1][6] = key[19];
    state->K[0][1][7] = key[20];
    state->K[0][1][8] = key[21];
    state->K[0][1][9] = key[22];
    state->K[0][1][10] = key[23];
    state->K[0][1][11] = key[24];
    state->K[0][1][12] = key[25];

    state->K[15][0][0] = key[26];
    state->K[15][0][1] = key[27];
    state->K[15][0][2] = key[28];
    state->K[15][0][3] = key[29];
    state->K[15][0][4] = key[30];
    state->K[15][0][5] = key[31];
    state->K[15][0][6] = key[32];
    state->K[15][0][7] = key[33];
    state->K[15][0][8] = key[34];
    state->K[15][0][9] = key[35];
    state->K[15][0][10] = key[36];
    state->K[15][0][11] = key[37];
    state->K[15][0][12] = key[38];

    state->K[15][1][0] = key[39];
    state->K[15][1][1] = key[40];
    state->K[15][1][2] = key[41];
    state->K[15][1][3] = key[42];
    state->K[15][1][4] = key[43];
    state->K[15][1][5] = key[44];
    state->K[15][1][6] = key[45];
    state->K[15][1][7] = key[46];
    state->K[15][1][8] = key[47];
    state->K[15][1][9] = key[48];
    state->K[15][1][10] = key[49];
    state->K[15][1][11] = key[50];
    state->K[15][1][12] = key[51];
}

void akms226_ksa(struct akms226_state * state, int *key) {
    int key_tmp[26];
    memset(state->K, 0, 16 * 2 * 13 * sizeof(int));
    memcpy(key_tmp, key, 26 * sizeof(int));
    akms226_key_load(state, key);
    akms226_load_block(state, key_tmp);
    for (int r = 1; r < state->rounds - 1; r++) {
        int rr = modsub26(r, 1);
        modadd26_block(state->L, 13, state->K[rr][0]);
        modadd26_block(state->R, 13, state->K[rr][1]);
        akms226_encrypt_block(state);
        for (int i = 0 ; i < 13; i++) {
            state->K[r][0][i] = modadd26(state->K[r][0][i], state->L[i]);
            state->K[r][1][i] = modadd26(state->K[r][1][i], state->R[i]);
        }
    }
}

void akms226_cbc_load_iv(struct akms226_state *state, int *iv26) {
    state->last[0][0] = iv26[0];
    state->last[0][1] = iv26[1];
    state->last[0][2] = iv26[2];
    state->last[0][3] = iv26[3];
    state->last[0][4] = iv26[4];
    state->last[0][5] = iv26[5];
    state->last[0][6] = iv26[6];
    state->last[0][7] = iv26[7];
    state->last[0][8] = iv26[8];
    state->last[0][9] = iv26[9];
    state->last[0][10] = iv26[10];
    state->last[0][11] = iv26[11];
    state->last[0][12] = iv26[12];

    state->last[1][0] = iv26[13];
    state->last[1][1] = iv26[14];
    state->last[1][2] = iv26[15];
    state->last[1][3] = iv26[16];
    state->last[1][4] = iv26[17];
    state->last[1][5] = iv26[18];
    state->last[1][6] = iv26[19];
    state->last[1][7] = iv26[20];
    state->last[1][8] = iv26[21];
    state->last[1][9] = iv26[22];
    state->last[1][10] = iv26[23];
    state->last[1][11] = iv26[24];
    state->last[1][12] = iv26[25];
}

void akms226_cbc_add(struct akms226_state *state) {
    state->L[0] = modadd26(state->L[0], state->last[0][0]);
    state->L[1] = modadd26(state->L[1], state->last[0][1]);
    state->L[2] = modadd26(state->L[2], state->last[0][2]);
    state->L[3] = modadd26(state->L[3], state->last[0][3]);
    state->L[4] = modadd26(state->L[4], state->last[0][4]);
    state->L[5] = modadd26(state->L[5], state->last[0][5]);
    state->L[6] = modadd26(state->L[6], state->last[0][6]);
    state->L[7] = modadd26(state->L[7], state->last[0][7]);
    state->L[8] = modadd26(state->L[8], state->last[0][8]);
    state->L[9] = modadd26(state->L[9], state->last[0][9]);
    state->L[10] = modadd26(state->L[10], state->last[0][10]);
    state->L[11] = modadd26(state->L[11], state->last[0][11]);
    state->L[12] = modadd26(state->L[12], state->last[0][12]);

    state->R[0] = modadd26(state->R[0], state->last[1][0]);
    state->R[1] = modadd26(state->R[1], state->last[1][1]);
    state->R[2] = modadd26(state->R[2], state->last[1][2]);
    state->R[3] = modadd26(state->R[3], state->last[1][3]);
    state->R[4] = modadd26(state->R[4], state->last[1][4]);
    state->R[5] = modadd26(state->R[5], state->last[1][5]);
    state->R[6] = modadd26(state->R[6], state->last[1][6]);
    state->R[7] = modadd26(state->R[7], state->last[1][7]);
    state->R[8] = modadd26(state->R[8], state->last[1][8]);
    state->R[9] = modadd26(state->R[9], state->last[1][9]);
    state->R[10] = modadd26(state->R[10], state->last[1][10]);
    state->R[11] = modadd26(state->R[11], state->last[1][11]);
    state->R[12] = modadd26(state->R[12], state->last[1][12]);
}

void akms226_cbc_next(struct akms226_state *state) {
    memcpy(state->last[0], state->L, 13 *sizeof(int));
    memcpy(state->last[1], state->R, 13 *sizeof(int));
}

void akms226_cbc_next_inv(struct akms226_state *state) {
    memcpy(state->next[0], state->L, 13 * sizeof(int));
    memcpy(state->next[1], state->R, 13 * sizeof(int));
}

void akms226_cbc_last_inv(struct akms226_state *state) {
    memcpy(state->last, state->next, 26 * sizeof(int));
}

void akms226_cbc_sub(struct akms226_state *state) {
    state->L[0] = modsub26(state->L[0], state->last[0][0]);
    state->L[1] = modsub26(state->L[1], state->last[0][1]);
    state->L[2] = modsub26(state->L[2], state->last[0][2]);
    state->L[3] = modsub26(state->L[3], state->last[0][3]);
    state->L[4] = modsub26(state->L[4], state->last[0][4]);
    state->L[5] = modsub26(state->L[5], state->last[0][5]);
    state->L[6] = modsub26(state->L[6], state->last[0][6]);
    state->L[7] = modsub26(state->L[7], state->last[0][7]);
    state->L[8] = modsub26(state->L[8], state->last[0][8]);
    state->L[9] = modsub26(state->L[9], state->last[0][9]);
    state->L[10] = modsub26(state->L[10], state->last[0][10]);
    state->L[11] = modsub26(state->L[11], state->last[0][11]);
    state->L[12] = modsub26(state->L[12], state->last[0][12]);

    state->R[0] = modsub26(state->R[0], state->last[1][0]);
    state->R[1] = modsub26(state->R[1], state->last[1][1]);
    state->R[2] = modsub26(state->R[2], state->last[1][2]);
    state->R[3] = modsub26(state->R[3], state->last[1][3]);
    state->R[4] = modsub26(state->R[4], state->last[1][4]);
    state->R[5] = modsub26(state->R[5], state->last[1][5]);
    state->R[6] = modsub26(state->R[6], state->last[1][6]);
    state->R[7] = modsub26(state->R[7], state->last[1][7]);
    state->R[8] = modsub26(state->R[8], state->last[1][8]);
    state->R[9] = modsub26(state->R[9], state->last[1][9]);
    state->R[10] = modsub26(state->R[10], state->last[1][10]);
    state->R[11] = modsub26(state->R[11], state->last[1][11]);
    state->R[12] = modsub26(state->R[12], state->last[1][12]);
}

void akms226_cbc_encrypt(char *inputfile, char *outputfile, char *passphrase) {
    struct akms226_state state;
    state.rounds = 16;
    int key[50];
    horakty_kdf(passphrase, key, 52, 1000);
    akms226_ksa(&state, key);
    int blocklen = 26;
    int bufsize = 26;
    FILE *infile, *outfile;
    int iv26[blocklen];
    uint8_t iv[blocklen];
    urandom26(iv26, blocklen);
    akms226_cbc_load_iv(&state, iv26);
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
        uint8_t block[26];
        int block26[26];
        if ((b == (blocks - 1)) && (extra != 0)) {
            bufsize = extra;
            for (int p = 0; p < extraletters; p++) {
                block26[(blocklen-1-p)] = (int *)extraletters;
            }
        }
        fread(block, 1, bufsize, infile);
        convert_block_to_int(block, bufsize, block26);
        akms226_load_block(&state, block26);
        akms226_cbc_add(&state);
        akms226_encrypt_block(&state);
        akms226_cbc_next(&state);
        akms226_unload_block(&state, block26);
        convert_block_to_char(block26, blocklen, block);
        fwrite(block, 1, blocklen, outfile);
    }
    fclose(infile);
    fclose(outfile);
} 

void akms226_cbc_decrypt(char *inputfile, char *outputfile, char *passphrase) {
    struct akms226_state state;
    state.rounds = 16;
    int key[50];
    horakty_kdf(passphrase, key, 52, 1000);
    akms226_ksa(&state, key);
    int blocklen = 26;
    int bufsize = 26;
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
    akms226_cbc_load_iv(&state, iv26);
    uint32_t blocks = datalen / blocklen;
    int extra = datalen % blocklen;
    int extraletters = blocklen - (datalen % blocklen);
    outfile = fopen(outputfile, "wb");
    if (extra != 0) {
       blocks += 1;
    }
    for (uint32_t b = 0; b < blocks; b++) {
        uint8_t block[26];
        int block26[26];
        fread(block, 1, bufsize, infile);
        convert_block_to_int(block, bufsize, block26);
        akms226_load_block(&state, block26);
        akms226_cbc_next_inv(&state);
        akms226_decrypt_block(&state);
        akms226_cbc_sub(&state);
        akms226_cbc_last_inv(&state);
        akms226_unload_block(&state, block26);
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
