#include<iostream>
using namespace std;
int main() {
	int case_number;
	bool sum_flag[20001];
	int sequence[100];
	int sequence_len;
	bool b2sequence;
	int sum;
	int i, j;

	case_number = 0;

	while (cin >> sequence_len) {
		b2sequence = true;

		for (i = 0; i < 20001; i++)
			sum_flag[i] = false;	

		case_number++;
		sequence[0] = 1;

		cin >> sequence[1];
		if (sequence[1] < 1)
			b2sequence = false;

		for (i = 2; i < sequence_len; i++) {
			cin >> sequence[i];					
			if (sequence[i] < sequence[i - 1])
				b2sequence = false;
		}

		for (i = 1; i < sequence_len; i++)
			for (j = i; j < sequence_len; j++) {
				sum = sequence[i] + sequence[j];

				if (sum_flag[sum])
					b2sequence = false;
				else
					sum_flag[sum] = true;
			}

		cout << "Case #" << case_number << ": ";

		if (b2sequence)
			cout << "It is a B2-Sequence." << endl;	
		else
			cout << "It is not a B2-Sequence." << endl;

		cout << endl;
	}
}