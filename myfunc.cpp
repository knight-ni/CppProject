#include "myfun.h"

int add(int a, int b) {
    int sum = a + b;
    return sum;
}

int *gen_int_array(int nlen) {
    int *p;
    int max = 0;
    p = (int *) malloc(sizeof(int) * nlen);
    memset(p, 0, nlen * sizeof(int));
    for (int *i = p; i < p + nlen; i++) {
        *i = rand();
//        cout << *i <<endl;
        if (*i >= max) {
            max = *i;
        }
    }
//    memcpy(arr2,p,sizeof(int)*nlen);
//    free(p);
    return p;
}

void get_narcissistic_num() {
    int val = 100;
    int a = 0;
    int b = 0;
    int c = 0;
    do {
        a = val / 100;
        b = val / 10 % 10;
        c = val % 10;
        if (a * a * a + b * b * b + c * c * c == val) {
            cout << val << " 是水仙花数" << endl;
        }
        val++;
    } while (val < 1000);
}

void guess_num(){
    int num = rand()/100;
    int val;
    cout << "输入数字" <<endl;
    cin >> val;
    while(val!=num){
        if (val>num){
            cout << "过大" <<endl;
        } else if (val<num) {
            cout << "过小" <<endl;
        }
        cout << "重新输入数字" <<endl;
        cin >> val;
    }
}

void strike_dest(){
    for (int i=1; i<=100; i++){
        if (i%7==0 || i%10 == 7 || i/10%7==7){
            cout <<"敲桌子"<< endl;
        } else {
            cout << i <<endl;
        }
    }
}

void draw_array(){
    for (int j=0; j<10; j++) {
        for (int i=0; i<10; i++) {
            cout << "*\t";
        }
        cout << endl;
    }
}

void multi_table(){
    for (int i=1; i<10; i++){
        for (int j=1; j<=i; j++)
        {
            cout << i << "*" <<j <<"=" << i*j <<"\t";
        }
        cout <<endl;
    }
}

void test_int_array(){
    int arr[5];
    cout <<"size of arr is: " << sizeof(arr)<< endl;
    cout <<"size of arr[0] is: " << sizeof(arr[0])<<endl;
    int len = sizeof(arr)/sizeof(arr[0]);      //手动计算容量 数组内存长度除以单个元素长度
    cout << "数组首地址：" << &arr <<endl;    //返回数组首地址
    //len = size(arr);
    for (int i=0;i<len;i++) {
        arr[i] = i;
        cout <<"第" <<i <<"个元素的地址：" << &arr[i] <<endl;    //返回数组首个元素地址
    }
}

void reverse_int_array(){
    int nlen=5;
    int *p;
    int max=0;
    p = (int *) malloc(sizeof(int)*nlen);
    memset(p,0,nlen*sizeof(int));
    for (int *i=p;i<p+nlen;i++) {
        *i = rand() ;
        cout << *i <<endl;
        if(*i>=max){
            max = *i;
        }
    }
    cout << "Max:" << max <<endl;
    int arr2[5];
    memcpy(arr2,p,sizeof(int)*nlen);
    free(p);
    cout << "reverse" <<endl;
    int start=0;
    int end=size(arr2)-1;
    while (start<=end)
    {
        int tmp = arr2[start];
        arr2[start] = arr2[end];
        arr2[end] = tmp;
        start++;
        end--;
    }
    for(int i=0;i<nlen;i++){
        cout<<arr2[i]<<endl;
    }
}

void pop_up(){
    int arr[] = {2, 4, 0, 6, 7, 5, 1, 3, 9, 8};
    for (int i = 1; i < size(arr); i++) {
        for (int j = 0; j < size(arr) - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }

    for (int i = 0; i < size(arr); i++) {
        cout << arr[i] << endl;
    }
}

void two_demension_int_array(){
    /*
     int arr[2][3];
    for (int i=0; i<2;i++){
        for(int j=0;j<3;j++){
            arr[i][j] = i*j;
        }
    }
     */
    int arr2[2][3] = {
            {1,2,3},
            {4,5,6}
    };

    //int arr3[2][3] = { 1,2,3,4,5,6 };

    //int arr4[][3] = { 1,2,3,4,5,6 };

    for(int i=0;i<2;i++){
        for (int j=0;j<3;j++){
            cout << arr2[i][j] << "\t";
        }
        cout << endl;
    }
}

void calc_int_array(){
    string names[] = {"张三","李四","王五"};
    int grade[3][3] = {
            {100,100,100},
            {90,50,100},
            {60,70,80}
    };
    int cols = sizeof(grade[0])/sizeof(grade[0][0]);
    int rows = sizeof(grade)/sizeof(grade[0]);

    for(int i=0;i<rows;i++){
        int sum = 0;
        for(int j=0;j<cols;j++){
            sum+=grade[i][j];
        }
        cout <<names[i] <<"的总分" <<sum <<endl;
    }
}

void test_pointer(){
    int nlen = 10;
    int *p = NULL;       //空指针
    int *p1 =(int *)0x01142;     //野指针 非法访问地址 无权限
    cout << "size of int pointer:" << sizeof(p) <<endl;
    p = gen_int_array(nlen);
    for (int *i = p; i < p + nlen; i++) {
        cout << *i << endl;
    }
}

void const_point() {
    int a = 10;
    int b = 20;
    const int *p = &a;  //常量指针 指向的数值不能更改 但指向地址可以更改 如 *p = 100 错误
    p = &b;           //指针允许修改
    int *const p1 = &a;  //指针常量 指向地址不能修改 但指向数值可以更改  如 p1 = &b 错误
    *p1 = b;
    const int * const p2 = &a; // 同事修饰指针和常量  都不能修改
}