#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int unique(int a[], int n)
{
    int i, j;
    if (!n)
        return 0;
    qsort(a, n, sizeof(a[0]), cmp);
    for (i = j = 1; i < n; i++) {
        if (a[i] != a[j - 1])
            a[j++] = a[i];
    }
    return j;
}

int bf(int a[], int n, int val)
{
    int l = 0, r = n;
    while (l < r) {
        if (a[(l + r) / 2] < val)
            l = (l + r) / 2 + 1;
        else
            r = (l + r) / 2;
    }
    return l;
}

int d[1 << 19][2];

int query(int t, int l, int r, int a, int b)
{
    if (l == a && r == b)
        return d[t][1];
    if (d[t][0]) {
        d[t << 1][0] += d[t][0];
        d[t << 1][1] += d[t][0];
        d[t << 1 | 1][0] += d[t][0];
        d[t << 1 | 1][1] += d[t][0];
        d[t][0] = 0;
    }
    if (b <= (l + r) / 2)
        return query(t << 1, l, (l + r) / 2, a, b);
    else if (a >= (l + r) / 2)
        return query(t << 1 | 1, (l + r) / 2, r, a, b);
    else {
        int r1 = query(t << 1, l, (l + r) / 2, a, (l + r) / 2);
        int r2 = query(t << 1 | 1, (l + r) / 2, r, (l + r) / 2, b);
        if (r2 > r1)
            return r2;
        else
            return r1;
    }
}

void update(int t, int l, int r, int a, int b, int val)
{
    if (l == a && r == b) {
        d[t][0] += val;
        d[t][1] += val;
        return;
    }
    if (d[t][0]) {
        d[t << 1][0] += d[t][0];
        d[t << 1][1] += d[t][0];
        d[t << 1 | 1][0] += d[t][0];
        d[t << 1 | 1][1] += d[t][0];
        d[t][0] = 0;
    }
    if (b <= (l + r) / 2)
        update(t << 1, l, (l + r) / 2, a, b, val);
    else if (a >= (l + r) / 2)
        update(t << 1 | 1, (l + r) / 2, r, a, b, val);
    else {
        update(t << 1, l, (l + r) / 2, a, (l + r) / 2, val);
        update(t << 1 | 1, (l + r) / 2, r, (l + r) / 2, b, val);
    }
    if (d[t << 1][1] > d[t << 1 | 1][1])
        d[t][1] = d[t << 1][1];
    else
        d[t][1] = d[t << 1 | 1][1];
}

int x[200000];
int a[100000][3];
int n, m;

int main()
{
    int i, j, k;
    while (scanf("%d %d", &n, &m) != EOF) {
        memset(d, 0, sizeof(d));
        for (i = 0; i < n; i++) {
            scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);
            a[i][1]++;
            x[i * 2] = a[i][0], x[i * 2 + 1] = a[i][1];
        }
        k = unique(x, n + n);
        for (i = 0; i < n; i++) {
            a[i][0] = bf(x, k, a[i][0]);
            a[i][1] = bf(x, k, a[i][1]);
            j = query(1, 0, k, a[i][0], a[i][1]);
            if (j + a[i][2] > m)
                puts("0");
            else {
                puts("1");
                update(1, 0, k, a[i][0], a[i][1], a[i][2]);
            }
        }
    }
    return 0;
}