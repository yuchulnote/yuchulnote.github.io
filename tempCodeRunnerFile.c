#include <stdio.h>

int main(void)
{
    for(int cur = 1; cur<=9; cur++)
    {
        if(cur%2!=0)
            continue;
        
        for(int is=1; is<=9; is++)
        {
            printf("%d X %d = %d\t", cur, is, cur*is);

            if(cur==is)
                break;
        }
        printf("\n");
    }
    return 0;
}
