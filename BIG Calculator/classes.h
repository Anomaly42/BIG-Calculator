#include <iostream>
#include <string>
using namespace std;
class Number {
public:
	int i;
	int j;
	int k;
	int m;
	int n;
	int o;
	int start;
	int end;
	int deci_position;
	int shift_amount;
	bool sign;
	int inverse;
	const static int length = 200;
	//MUST be even; length excludes sign
	string number;
	int array[length + 1];
	// + 1 to allow signed representation
	void valueReset() {
		for (i = 0;i <= length; i++) {
			array[i] = 0;
		}

	};

	void deciFinder() {
		bool deci = false;
		for (k = 0; k <= number.size() - 1; k++) {
			if (number[k] == '.') {
				deci_position = k;
				deci = true;
			}
		};
		if (deci == false) {
			deci_position = number.size();
		}

	};

	void convert() {
		shift_amount = length/2 + 1 - deci_position;
		if (sign == 0) {
			inverse = 1;
		}
		else if (sign == 1) {
			inverse = -1;
		}
		for (j = 0; j <= number.size() - 1; j++) {
			if (j + shift_amount <= length - 1) {
				if (number[j] == '0') {
											array[j + shift_amount] = 0*inverse;
										}
							else if (number[j] == '1') {
											array[j + shift_amount] = 1*inverse;
										}
							else if (number[j] == '2') {
											array[j + shift_amount] = 2*inverse;
										}
							else if (number[j] == '3') {
											array[j + shift_amount] = 3*inverse;
										}
							else if (number[j] == '4') {
											array[j + shift_amount] = 4*inverse;
										}
							else if (number[j] == '5') {
											array[j + shift_amount] = 5*inverse;
										}
							else if (number[j] == '6') {
											array[j + shift_amount] = 6*inverse;
										}
							else if (number[j] == '7') {
											array[j + shift_amount] = 7*inverse;
										}
							else if (number[j] == '8') {
											array[j + shift_amount] = 8*inverse;
										}
							else if (number[j] == '9') {
											array[j + shift_amount] = 9*inverse;
										}
							else if (number[j] == '.') {
											shift_amount--;

							}

			}



		}
	};

	void signSet() {
		if (sign == 1) {
			array[length] = 1;
		}
		else {
			array[length] = 0;
			sign = 0;
		}
	};

	void numBound() {
		if (sign == 0) {
			inverse = 1;
		}
		else if (sign == 1) {
			inverse = -1;
		}
		for (int x = 0; x <= length - 1; x++) {
		    if (array[x] == 0) {

			}
			else {
				end = x;
			}
		}
		for (int y = length; y >= 0; y--) {
			if (array[y] == 0) {

			}
			else {
				start = y;
			}
		}
	};
	void show() {
		numBound();
		if (inverse == -1) {
						cout << "-";
					}
		for (int z = start; z <= length/2; z++) {
				cout << array[z]*inverse;
		}
		cout << ".";
		for (int z = length/2 + 1; z <= end; z++) {
				cout << array[z]*inverse;
		}


	};

	void showArray() {
		for (int x = 0; x <= length; x++) {
			cout << array[x] << endl;
		}

	};

	void process() {
		valueReset();
		deciFinder();
		convert();
		signSet();
	};

	Number operator+(const Number& b) {
		Number num;
		for (int w = 0; w <= length - 1; w++) {
			num.array[w] = this->array[w] + b.array[w];
		}
		for (int w = length - 1; w >= 0; w--)  {
			if (num.array[w] >= 10) {
				num.array[w - 1] += 1;
				num.array[w] -= 10;
			}
			else if (num.array[w] <= -10) {
							num.array[w - 1] -= 1;
							num.array[w] += 10;
						}

		}
		for (int y = length - 1; y >= 0; y--) {
					if (num.array[y] == 0) {

					}
					else {
						num.start = y;
					}

				}

		if (num.array[num.start] > 0) {
			num.sign = 0;
			for (int w = length - 1; w >= 0; w--) {
						if (num.array[w] < 0) {
							num.array[w] = num.array[w] + 10;
							num.array[w - 1] -= 1;
						}
						else if (num.array[w] >= 0) {

						}
					}

		}
		else if (num.array[num.start] < 0) {
			num.sign = 1;
			for (int w = length - 1; w >= 0; w--) {
						if (num.array[w] > 0) {
							num.array[w] = num.array[w] - 10;
							num.array[w - 1] += 1;
						}
						else if (num.array[w] <= 0) {

						}
					}
		}
		return num;
	};
	Number operator-(const Number& b) {
		Number num;
		for (int w = 0; w <= length - 1; w++) {
			num.array[w] = this->array[w] - b.array[w];
		}
		for (int w = length - 1; w >= 0; w--)  {
			if (num.array[w] >= 10) {
				num.array[w - 1] += 1;
				num.array[w] -= 10;
			}
			else if (num.array[w] <= -10) {
							num.array[w - 1] -= 1;
							num.array[w] += 10;
						}

		}
		for (int y = length - 1; y >= 0; y--) {
					if (num.array[y] == 0) {

					}
					else {
						num.start = y;
					}
				}

		if (num.array[num.start] > 0) {
			num.sign = 0;
			for (int w = length - 1; w >= 0; w--) {
						if (num.array[w] < 0) {
							num.array[w] = num.array[w] + 10;
							num.array[w - 1] -= 1;
						}
						else if (num.array[w] >= 0) {

						}
					}

		}
		else if (num.array[num.start] < 0) {
			num.sign = 1;
			for (int w = length - 1; w >= 0; w--) {
						if (num.array[w] > 0) {
							num.array[w] = num.array[w] - 10;
							num.array[w - 1] += 1;
						}
						else if (num.array[w] <= 0) {

						}
					}
		}
		return num;
		};

	Number operator*(const Number& b) {
		Number num;
		num.valueReset();
		if(this->sign == 0 && b.sign == 0) {
			num.sign = 0;
		}
		else if(this->sign == 1 && b.sign == 0) {
					num.sign = 1;
				}
		else if(this->sign == 0 && b.sign == 1) {
					num.sign = 1;
				}
		else if(this->sign == 1 && b.sign == 1) {
					num.sign = 0;
				}

		for (int x = length - 1; x >= 0; x--) {
			for (int y = length - 1; y >= 0; y--) {
				if (x + y - length/2  >= 0) {
					num.array[x + y - length/2 ] += this->array[y] * b.array[x];
				}
			}
		}

		//carry here
		for (int w = length - 1; w >= 0; w--) {
				if (num.array[w] >= 10 || num.array[w] <= -10) {
						num.array[w - 1] += num.array[w]/10;
						num.array[w] = num.array[w] % 10;
							}
		}
		return num;
	}

};
