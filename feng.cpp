//
// Created by Tsing on 7/24/2017.
//

int swap1(int &a, int &b) {
    int c = a;
    a = b;
    b = c;
    return 0;
}
void swap(int *a,int*b){
    // wrong!
    int *c=a;
    a=b;
    b=c;
}

int main22() {
    int a = 1, b = 2;
//    swap1(a, b);
    swap(&a, &b);
    return 0;
}