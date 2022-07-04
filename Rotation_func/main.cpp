#include <iostream>
#include <math.h>

using namespace std;
#define PI 3.14159265358979323846
#define DEGREE_TO_RADIAN(degree) ((PI/180)*(degree))

double MCP_X = 0, MCP_Y = 0; // Motion_Current_Position X & Y 모션 현재위치
double MOP_X = 0, MOP_Y = 0; // Motion_Origin_Position X & Y 회전 중심위치
double mD = 0, mR = 0; // 회전할 각도 & 각도 라디안 환산
double Result_X, Result_Y; // 회전되어진 각도

void rotate()
{
	// 라디안은 반시계방향으로 증가함 , 그래서 - 적용하여 시계방향으로 적용
	double cosq = cos(-mR), sinq = sin(-mR);

	// 원점이 0,0 이 아닐시
	MCP_X -= MOP_X, MCP_Y -= MOP_Y;

	// 공식 적용
	Result_X = MCP_X * cosq - MCP_Y * sinq;
	Result_Y = MCP_Y * cosq + MCP_X * sinq;


}

int main()
{
	while (true)
	{
		//cout << "중심 좌표 설정 : X = ";
		//cin >> MOP_X;
		//cout << "중심 좌표 설정 : Y = ";
		//cin >> MOP_Y;

		cout << "모션 현재 좌표 설정 : X = ";
		cin >> MCP_X;
		cout << "모션 현재 좌표 설정 : Y = ";
		cin >> MCP_Y;

		cout << "움직일 각도 설정 : θ = ";
		cin >> mD;

		mR = DEGREE_TO_RADIAN(mD);
		rotate();
		cout << "각도가 " << mD << "일때 모션의 현재위치는? x = " << Result_X << ", y = " << Result_Y << endl;
		cout << endl;
	}


	/*for (int i = 0; i < 361; i++)
	{
		MCP_X = 0, MCP_Y = 10;
		mD = i;
		mR = DEGREE_TO_RADIAN(mD);
		rotate();
		cout << "각도가 "<< i <<"일때 모션의 현재위치는? x = " << Result_X << ", y = " << Result_Y << endl;
	}*/

	return 0;
}