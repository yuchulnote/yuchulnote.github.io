#include<stdio.h>
#include<math.h>

struct point //포인트라는 구조체 선언
{
    int x;
    int y;
    int z;
}; //구조체 안의 멤버 x,y,z 선언

int main()
{
    struct point p1, p2;
    int num1, num2, num3;
    double result;

    printf("3차원 점 A1의 좌표를 입력하시오");
    scanf("%d %d %d", &p1.x, &p1.y, &p1.z);

    printf("3차원 점 A2의 좌표를 입력하시오");
    scanf("%d %d %d", &p2.x, &p2.y, &p2.z);

    num1 = p1.x - p2.x;
    num2 = p1.y - p2.y;
    num3 = p1.z - p2.z;

    result = sqrt(num1*num1 + num2*num2 + num3*num3);

    printf("3차원 점 A1 과 A2 사이의 거리는 %f 입니다.\n", result);

    return 0;
}