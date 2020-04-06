#include <iostream>

using namespace std;

template <class T>
class Array {
private:
	int size;
	T* arr;
public:
	Array(int size_val = 0) {
		size = size_val;
		arr = new T[size];
	}
	void set() {
		for (int i = 0; i < size; i++) {
			cin >> arr[i];
		}
	}
	T get_min() {
		T min = arr[0];
		int min_index = 0;
		for (int i = 0; i < size; i++) {
			if (arr[i] < min) {
				min = arr[i];
				min_index = i;
			}
		}
		cout << "Minimal element: " << min << endl;
		return min_index;
	}
	~Array() {
		delete arr;
	}
};

int main() {
	setlocale(0, "Russian");

	Array<int> test(5);
	test.set();
	cout << "Minimal element index: " << test.get_min() << endl;
	
	return 0;
}
