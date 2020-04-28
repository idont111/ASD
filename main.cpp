//Черныш Алина
// КМ-93
// посчитать выпуклую оболочку методом грубой силы
//Работа была сдана 02.03.2020

#include <bits/stdc++.h>
using namespace std;

struct points// делаем структру
{
    int x, y;
};

int orientation(points p, points q, points r)
{
    int value = (q.y - p.y) * (r.x - q.x) -
                (q.x - p.x) * (r.y - q.y);

    if (value == 0) return 0;  // колинеарные вектора
    return (value > 0)? 1: 2; // за или против часовой стрелке
}

void convex_hull(points Points[], int number)// функция для вывода результата
{
    if (number < 3) return;// должно быть не меньше 3х точек

    vector<points> hull;//инициализировать переменную "результат"

    int leftpoint = 0;//найти самую крайную
    for (int i = 1; i < number; i++)
        if (Points[i].x < Points[leftpoint].x)
            leftpoint = i;

    int p = leftpoint, q;
    do
    {
        hull.push_back(Points[p]);

        q = (p+1)%number;
        for (int i = 0; i < number; i++)
        {
            if (orientation(Points[p], Points[i], Points[q]) == 2)//проверка противчасосовой стрелки находиться точка q
                q = i;// приписываем значeние
        }
        p = q;// q - самая крайняя точка

    } while (p != leftpoint);  // пока не дойдем до первой точки


    for (int i = 0; i < hull.size(); i++)//вывод результата
        cout << "(" << hull[i].x << ", "
             << hull[i].y << ")\n";
}

int main()
{

    points my_Points[] = {{0, 4}, {1, 3}, {1, 1}, {2, 1},
                          {3, 3}, {0, 0}, {3, 2}};
    printf("The result is:\n");
    int number = sizeof(my_Points)/sizeof(my_Points[0]);
    convex_hull(my_Points, number);
    return 0;
}