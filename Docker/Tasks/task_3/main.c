#include "fcgi_stdio.h"
#include <stdio.h>

int main(){
    while (FCGI_Accept() >= 0)
    {
        FCGI_printf("Content-Type: text/html\r\n\r\n");
        FCGI_printf("Hello world!");
    }
    return 0;
}



