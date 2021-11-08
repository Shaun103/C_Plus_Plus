#include <iostream>
#include <algorithm>
// https://www.youtube.com/watch?v=p-sprvJX07E

void someFunction(){

    int a=1, b=2, c =3, d=4, e=5;

    int x1 = min(a,
                min(b,
                    min(c,
                        min(d,e))));
}

void someBetterFunction(){

    int a=1, b=2, c =3, d=4, e=5;
    int x2 = min({ a, b, c, d, e });
}

int main(int argc, char * argv[]){ 

    std::cout << someFunction << std::endl;
    std::cout << someBetterFunction << std::endl;

return 0;
}  