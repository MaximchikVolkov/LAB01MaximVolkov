#include <stdio.h>
void printPoint(int a, int b);
void scanPointX(int a);
void scanPointY(int a);
void printError();
void pointOnPoint(int a);
void sideAndContinantion(double Y, double yPoint, double xPoint, double endSide, double startSide);
void printSector(int a);
double checkPointX(double a, double b);
double checkPointY(double a, double b);
int j=0;
int main()
{
    double x1=0, y1=0, x2=0, y2=0, x3=0, y3=0, x4=0, y4=0, voidValue, Y12, Y13, Y23, masX[15], masY[15];
    x1=checkPointX(1, x1);
    y1=checkPointY(1, y1);
    x2=checkPointX(2, x2);
    y2=checkPointY(2, y2);
    x3=checkPointX(3, x3);
    y3=checkPointY(3, y3);
    x4=checkPointX(4, x4);
    y4=checkPointY(4, y4);
    printPoint(x1, y1);
    printPoint(x2, y2);
    printPoint(x3, y3);
    printPoint(x4, y4);
    //Анализируем тот случай, когда построение треугольника невозможно
    if((x1==x2 && y1==y2) || (x2==x3 && y2==y3) || (x1==x3 && y1==y3) || (x1==x2 && x1==x3) || (y1==y2 && y2==y3))
        printError();
    else
    {
        //Учитываем тот случай, когда искомая точка может являться вершиной треугольника
        if(x1==x4 && y1==y4)
            pointOnPoint(1);
        if(x2==x4 && y2==y4)
            pointOnPoint(2);
        if(x3==x4 && y3==y4)
            pointOnPoint(3);
        /*Рассматриваем разные вариации расположения всех вершин относительно друг друга
        и приводим все к тому, что справа налево вершины пронумерованы в порядке возрастания*/
        masX[0]=x1;
        masX[1]=x2;
        masX[2]=x3;
        masY[0]=y1;
        masY[1]=y2;
        masY[2]=y3;
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                if(masX[i]>masX[j])
                {
                    voidValue=masX[i];
                    masX[i]=masX[j];
                    masX[j]=voidValue;
                    voidValue=masY[i];
                    masY[i]=masY[j];
                    masY[j]=voidValue;
                }
            }
        }
        x1=masX[0];
        x2=masX[1];
        x3=masX[2];
        y1=masY[0];
        y2=masY[1];
        y3=masY[2];
        if(x2==x3 && x1<x2)
        {
            if(y2>y3)
            {
                voidValue=x2;
                x2=x1;
                x1=voidValue;
                voidValue=y2;
                y2=y1;
                y1=voidValue;
            }
            if(y2<y3)
            {
                voidValue=x2;
                x2=x1;
                x1=voidValue;
                voidValue=y3;
                y3=y1;
                y1=voidValue;
            }
        }
        if(x2==x3 && x1>x2)
        {
            if(y2>y3)
            {
                voidValue=x2;
                x2=x3;
                x3=voidValue;
                voidValue=y2;
                y2=y3;
                y3=voidValue;
            }
        }
        if(x1==x2 && x3>x1)
        {
            if(y1>y2)
            {
                voidValue=x1;
                x1=x3;
                x3=voidValue;
                voidValue=y1;
                y1=y3;
                y3=voidValue;
            }
            if(y1<y2)
            {
                voidValue=x3;
                x3=x1;
                x1=voidValue;
                voidValue=y3;
                y3=y2;
                y2=y1;
                y1=voidValue;
            }
        }
        if(x1==x2 && x3<x1)
        {
            if(y2>y1)
            {
                voidValue=y1;
                y1=y2;
                y2=voidValue;
            }
        }
        if(x1==x3 && x2<x1)
        {
            if(y1>y3)
            {
                voidValue=x2;
                x2=x3;
                x3=voidValue;
                voidValue=y2;
                y2=y3;
                y3=voidValue;
            }
            if(y1<y3)
            {
                voidValue=x3;
                x3=x2;
                x2=voidValue;
                voidValue=y3;
                y3=y2;
                y2=y1;
                y1=voidValue;
            }
        }
        if(x1==x3 && x2>x1)
        {
            if(y1>y3)
            {
                voidValue=x2;
                x2=x1;
                x1=voidValue;
                voidValue=y2;
                y2=y3;
                y3=y1;
                y1=voidValue;
            }
            if(y1<y3)
            {
                voidValue=x1;
                x1=x2;
                x2=voidValue;
                voidValue=y1;
                y1=y2;
                y2=voidValue;
            }
        }
        Y12=((y1-y2)/(x1-x2)*(x4-x1)+y1);
        Y13=((y1-y3)/(x1-x3)*(x4-x3)+y3);
        Y23=((y2-y3)/(x2-x3)*(x4-x2)+y2);
        if(Y12==Y23 && Y23==Y13 && Y12==Y23)
            printError();
        else
        {
            //Рассматриваем случаи нахождения точки на стороне или продолжении стороны треугольника
            sideAndContinantion(Y12, y4, x4, x1, x2);
            sideAndContinantion(Y23, y4, x4, x2, x3);
            sideAndContinantion(Y13, y4, x4, x1, x3);
            if(y2>y1 && y2>y3)
            {
                if(y4>Y12 && y4<Y13 && y4<Y23)
                   printSector(1);
                if(y4<Y12 && y4<Y13 && y4<Y23)
                   printSector(2);
                if(y4<Y12 && y4<Y13 && y4>Y23)
                   printSector(3);
                if(y4<Y12 && y4>Y13 && y4>Y23)
                   printSector(4);
                if(y4>Y12 && y4>Y13 && y4>Y23)
                   printSector(5);
                if(y4>Y12 && y4>Y13 && y4<Y23)
                   printSector(6);
                if(y4<Y12 && y4>Y13 && y4<Y23)
                   printSector(7);
            }
            else
            {
                if(y4<Y12 && y4>Y13 && y4>Y23)
                   printSector(1);
                if(y4<Y12 && y4<Y13 && y4>Y23)
                   printSector(2);
                if(y4<Y12 && y4<Y13 && y4<Y23)
                   printSector(3);
                if(y4>Y12 && y4<Y13 && y4<Y23)
                   printSector(4);
                if(y4>Y12 && y4>Y13 && y4<Y23)
                   printSector(5);
                if(y4>Y12 && y4>Y13 && y4>Y23)
                   printSector(6);
                if(y4>Y12 && y4<Y13 && y4>Y23)
                   printSector(7);
            }
        }
    }
    return 0;
}
void printPoint(int a, int b)
{
    j++;
    printf("Point %d: x: %d y: %d\n", j, a, b);
}
void scanPointX(int a)
{
    printf("Point %d X: ", a);
}
void scanPointY(int a)
{
    printf("Point %d Y: ", a);
}
void pointOnPoint(int a)
{
    printf("Point 4 on Point %d\n", a);
}
void sideAndContinantion(double Y, double yPoint, double xPoint, double endSide, double startSide)
{
    if(Y==yPoint)
    {
        if(startSide<xPoint && xPoint<endSide)
            printf("Point 4 is located on the side of the triangle\n");
        if(xPoint<startSide || xPoint>endSide)
            printf("Point 4 is located on the continuation of the side of the triangle\n");
    }
}
void printError()
{
    printf("Error System, Please correct your data\n");
}
void printSector(int a)
{
    printf("Point is located in %d sector", a);
}
double checkPointX(double a, double b)
{
    double c;
    do
    {
        scanPointX(a);
        fflush(stdin);
        c = scanf("%lf", &b);
    }
    while (c < 1);
    return b;
}
double checkPointY(double a, double b)
{
    double c;
    do
    {
        scanPointY(a);
        fflush(stdin);
        c = scanf("%lf", &b);
    }
    while (c < 1);
    return b;
}
