#include <iostream>
#include <memory.h>

#define MAX_N 5
#define MAX_M 10

using namespace std;

/*
���̳��� ���α׷���
*/
// ���� ����
int n;
int freq[MAX_N];

// dp[s1, s2, s3, s4, s5, c1, c2] : 
// �� ���ڰ� s1, .., s5�� ���Ұ� �ֱ� ������ 2���� ���� ��ȣ�� ������� c1, c2�� ���� ��
// ������ ���� �ٸ� ������
long long dp[MAX_M + 1][MAX_M + 1][MAX_M + 1][MAX_M + 1][MAX_M + 1][MAX_N + 1][MAX_N + 1];

long long Counting(int c1, int c2) {
    long long& ret = dp[freq[0]][freq[1]][freq[2]][freq[3]][freq[4]][c1][c2];
    if (ret != -1)
        return ret;

    // �ʱ������� freq ���� ���� 0�� ����Դϴ�.
    if (freq[0] + freq[1] + freq[2] + freq[3] + freq[4] == 0)
        return 1;

    ret = 0;
    for (int i = 0; i < n; i++)
        if (freq[i] > 0 && i != c1 && i != c2) {
            freq[i]--;
            ret += Counting(c2, i);
            freq[i]++;
        }

    return ret;
}

int main() {
    // �Է�:
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> freq[i];

    // dp���� -1�� �ʱ�ȭ�մϴ�.
    memset(dp, -1, sizeof(dp));

    cout << Counting(n, n);
    return 0;
}