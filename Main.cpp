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
		cout << "����";
	}
	else if (type == 2) {
		cout << "����";
	}
	cout << "�������� ������ �迭�� " << endl;
	for (int i = 0; i < count - 1; i++)
	{
		cout << array[i] << " , ";
	}
	cout << array[count - 1] << "�Դϴ�." << endl;
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
	// 2�� �Է¹����� �������� ����
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
		cout << "���α׷��� �����մϴ�." << endl;
		exit(0);
	}
}

int main()
{
	// N���� �Է��� �޴´ٰ� ����. N�� �Է¹޾� N�� ũ�⸦ ���� �迭 ����
	int count = 0;
	cout << "��հ� ���� ���� ���ڵ��� ������ �Է��ϼ��� : \n" << "(���� : 0)" << endl;
	cin >> count;
	double* array = new double[count];

	// 0�� �Է¹����� ��� ���α׷� ����
	if (count == 0) {
		cout << "���α׷��� �����մϴ�.";
		exit(0);
	}
	else {

		// �հ� ��� �ʱ�ȭ
		double sum = 0;
		double average = 0;

		for (int i = 0; i < count; i++) {
			cin >> array[i];
		}

		// �հ� ����� �Լ��� ����
		sum = Sum(count, array);
		average = Average(sum, count);

		cout << "���� " << sum << " �̰�, " << "����� " << average << " �Դϴ�." << endl;
	}

	cout << "===============================\n\n";

	// 1�� �Է¹����� �������� ����, 2�� �Է¹����� �������� ����
	// ������ �迭�� ���
	int type = 1;
	int loopTime = 0; // �迭�� ���ĺ��� ���� ��� ���ѷ��� �߻�, ���ѷ��� ���������� 10ȸ �ݺ��Ǹ� ���� Ż��
	while ((type == 1) || (type == 2))
	{
		cout << "�������� ������ " << 1 << " , " << "�������� ������ " << 2 << " �� �Է��ϼ��� :" << endl;
		cout << "(�����Ϸ��� 1�� 2 �̿��� ���ڸ� �Է��ϼ���)" << endl;
		cin >> type;
		SortArray(type, array, count);
		PrintArray(type, count, array);

		loopTime++;
		if (loopTime >= 10) {
			cout << "������������ ���� Ƚ���� �ݺ��߽��ϴ�. ����� �Է��ߴ��� Ȯ���ϼ���. ���α׷��� �����մϴ�." << endl;
			break;
		}
	}

	return 0;
}


