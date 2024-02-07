#include<iostream>
#include "addd.hpp"
#include "minuss.hpp"

using namespace std;

int main()
{
    printf("hello world\n");

    int a=10;
    int b=5;

    int res1=addd(a,b);
    int res2=minuss(a,b);

    printf("a + b = %d\n",res1);
    printf("a - b = %d\n",res2);
    return 0;
}