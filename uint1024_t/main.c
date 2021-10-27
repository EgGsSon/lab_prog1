#include <stdio.h>
//#include <stlib.h>

int power(int n, int x) {
    int res = 1;
    for(int i = 0; i < x; i++)
        res = res * n;
    return res;
}

typedef struct Uint1024_t{
    unsigned int ls[35];
    int index;
} uint1024_t;

uint1024_t from_uint(unsigned int x) {
    uint1024_t a;
    a.index = 34;
    if(x / power(10,10) != 0) {
        a.ls[33] = x / power(10,9);
        a.index = 33;
    }
    a.ls[34] = x % power(10,9);
    return a;
}

uint1024_t add_op(uint1024_t x, uint1024_t y) {
    uint1024_t res;
    int max_index;
    int remainder = 0;
    
    if(x.index < y.index)
        max_index = x.index;
    else
        max_index = y.index;
    
    for(int i = 34; i >= max_index; i--) {
        int adding = x.ls[i] + y.ls[i] + remainder;
        remainder = 0;
        if(adding / power(10,9) != 0)
            remainder = adding / power(10,9);
        res.ls[i] = adding % power(10,9);
    }
    
    if(max_index != 0) {
        res.index = max_index - 1;
        res.ls[res.index] = remainder;
    }
    else
        res.index = max_index;
    return res;
}



void scanf_value(uint1024_t* x) {
    
    char text[310];
    printf("Enter your number:\n");
    scanf("%s", text);
    int i = 0;
    int z = 34;
    
    while(text[i] != '\0') {
        i++;
    }
    
    i--;
    x->ls[z] = 0;
    for(int k = i; k >= 0; k--) {
        int p = i - k;
        x->ls[z] += (text[k] - '0') * power(10,p);
        if( (i - k) % 8 == 0 && (i - k) != 0) {
            z--;
            i = k - 1;
            x->ls[z] = 0;
        }
        x->index = z;
    }
}

void printf_value(uint1024_t a) {
    while(a.ls[a.index] == 0 && a.index != 34)
        a.index += 1;
    for(int i = a.index; i < 35; i++)
        printf("%d ", a.ls[i]);
    printf("\n");
}

int main(int argc, const char * argv[]) {
    uint1024_t a;
    uint1024_t b;
    scanf_value(&a);
    printf_value(a);
    scanf_value(&b);
    b = add_op(a, b);
    printf("ADDDING\n");
    printf_value(b);
    return 0;
}
