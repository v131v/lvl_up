int find(int *a, int sizeA, int *b, int sizeB, int *ans) {
    int k = 0;

    for (int i = 0; i < sizeA; i++) {

        bool fg = true;
        for (int j = 0; j < sizeB; j++) {

            if (a[i] == b[j]) {
                fg = false;
                break;
            }
        }

        if (fg) {
            ans[k] = i;
            ++k;
        }
    }

    return k;
}
