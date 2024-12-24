#include <iostream>
using namespace std;

double Sum(int count, double* array) {
	double sum = 0;

	for (int i = 0; i < count; i++) {
		sum += array[i];
	}

	return sum;
}

double Average(double sum, int count) {
	double average = 0;

	average = sum / count;
	return average;
}

void PrintArray(int type, int count, double* array) {
	if (type == 1) {
		cout << "오름";
	}
	else if (type == 2) {
		cout << "내림";
	}
	cout << "차순으로 정렬한 배열은 " << endl;
	for (int i = 0; i < count - 1; i++)
	{
		cout << array[i] << " , ";
	}
	cout << array[count - 1] << "입니다." << endl;
	cout << "===============================\n\n";
}

void SortArray(int type, double* array, int count) {
	if (type == 1) {
		for (int i = 0; i < count - 1; i++)
		{
			int temp = i;
			for (int j = i + 1; j < count; j++)
			{
				if (array[temp] > array[j]) {
					swap(array[temp], array[j]);
				}
			}
		}
	}
	// 2를 입력받으면 내림차순 정렬
	else if (type == 2) {
		for (int i = 0; i < count - 1; i++)
		{
			int temp = i;
			for (int j = i + 1; j < count; j++)
			{
				if (array[temp] < array[j]) {
					swap(array[temp], array[j]);
				}
			}
		}
	}
	else {
		cout << "프로그램을 종료합니다." << endl;
		exit(0);
	}
}

int main()
{
	// N개의 입력을 받는다고 가정. N을 입력받아 N의 크기를 갖는 배열 생성
	int count = 0;
	cout << "평균과 합을 구할 숫자들의 개수를 입력하세요 : \n" << "(종료 : 0)" << endl;
	cin >> count;
	double* array = new double[count];

	// 0을 입력받으면 즉시 프로그램 종료
	if (count == 0) {
		cout << "프로그램을 종료합니다.";
		exit(0);
	}
	else {

		// 합과 평균 초기화
		double sum = 0;
		double average = 0;

		for (int i = 0; i < count; i++) {
			cin >> array[i];
		}

		// 합과 평균을 함수로 구현
		sum = Sum(count, array);
		average = Average(sum, count);

		cout << "합은 " << sum << " 이고, " << "평균은 " << average << " 입니다." << endl;
	}

	cout << "===============================\n\n";

	// 1을 입력받으면 오름차순 정렬, 2를 입력받으면 내림차순 정렬
	// 정렬한 배열을 출력
	int type = 1;
	int loopTime = 0; // 배열에 알파벳이 들어올 경우 무한루프 발생, 무한루프 방지를위해 10회 반복되면 강제 탈출
	while ((type == 1) || (type == 2))
	{
		cout << "오름차순 정렬은 " << 1 << " , " << "내림차순 정렬은 " << 2 << " 를 입력하세요 :" << endl;
		cout << "(종료하려면 1과 2 이외의 숫자를 입력하세요)" << endl;
		cin >> type;
		SortArray(type, array, count);
		PrintArray(type, count, array);

		loopTime++;
		if (loopTime >= 10) {
			cout << "비정상적으로 많은 횟수를 반복했습니다. 제대로 입력했는지 확인하세요. 프로그램을 종료합니다." << endl;
			break;
		}
	}

	return 0;
}


