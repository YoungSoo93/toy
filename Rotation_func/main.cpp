#include <iostream>
#include <math.h>

using namespace std;
#define PI 3.14159265358979323846
#define DEGREE_TO_RADIAN(degree) ((PI/180)*(degree))

double MCP_X = 0, MCP_Y = 0; // Motion_Current_Position X & Y ��� ������ġ
double MOP_X = 0, MOP_Y = 0; // Motion_Origin_Position X & Y ȸ�� �߽���ġ
double mD = 0, mR = 0; // ȸ���� ���� & ���� ���� ȯ��
double Result_X, Result_Y; // ȸ���Ǿ��� ����

void rotate()
{
	// ������ �ݽð�������� ������ , �׷��� - �����Ͽ� �ð�������� ����
	double cosq = cos(-mR), sinq = sin(-mR);

	// ������ 0,0 �� �ƴҽ�
	MCP_X -= MOP_X, MCP_Y -= MOP_Y;

	// ���� ����
	Result_X = MCP_X * cosq - MCP_Y * sinq;
	Result_Y = MCP_Y * cosq + MCP_X * sinq;


}

int main()
{
	while (true)
	{
		//cout << "�߽� ��ǥ ���� : X = ";
		//cin >> MOP_X;
		//cout << "�߽� ��ǥ ���� : Y = ";
		//cin >> MOP_Y;

		cout << "��� ���� ��ǥ ���� : X = ";
		cin >> MCP_X;
		cout << "��� ���� ��ǥ ���� : Y = ";
		cin >> MCP_Y;

		cout << "������ ���� ���� : �� = ";
		cin >> mD;

		mR = DEGREE_TO_RADIAN(mD);
		rotate();
		cout << "������ " << mD << "�϶� ����� ������ġ��? x = " << Result_X << ", y = " << Result_Y << endl;
		cout << endl;
	}


	/*for (int i = 0; i < 361; i++)
	{
		MCP_X = 0, MCP_Y = 10;
		mD = i;
		mR = DEGREE_TO_RADIAN(mD);
		rotate();
		cout << "������ "<< i <<"�϶� ����� ������ġ��? x = " << Result_X << ", y = " << Result_Y << endl;
	}*/

	return 0;
}