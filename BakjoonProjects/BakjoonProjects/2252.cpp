#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, M;
struct Student {
    int n;
    int h;
};
bool operator<(Student lhs, Student rhs)
{
    if (lhs.h == rhs.h) return lhs.n < rhs.n;
    return lhs.h > rhs.h;
}
Student students[32000];
vector<int> vCompare[32000];
void dfs(int prev, int cur)
{
    students[cur].h = max(students[cur].h, students[prev].h + 1);

    for (int i = 0; i < vCompare[cur].size(); ++i)
        dfs(cur, vCompare[cur][i]);
}
int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; ++i)
    {
        students[i].n = i + 1;
        students[i].h = 0;
    }

    for (int i = 0; i < M; ++i)
    {
        int lhs, rhs;
        cin >> lhs >> rhs;
        vCompare[rhs - 1].push_back(lhs - 1);
    }

    for (int i = 0; i < N; ++i)
        dfs(i, i);

    sort(students, students + N);

    for (int i = 0; i < N; ++i)
        cout << students[i].n << " ";
}