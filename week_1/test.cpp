#include <iostream>

template <typename T>
void swapFunc(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
void sortFunc(T arr[], size_t size) {
	for (int i = 0; i < size; i++) {
		for (int j = i; j < size; j++) {
			if (arr[i] > arr[j]) {
				swapFunc(arr[i], arr[j]);
			}
		}
	}

	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}



int main()
{

	char sentence[] = { "Alkan" };
	size_t size1 = sizeof(sentence) - 1;//because of the '\0'
	sortFunc(sentence, size1);
	int numbers[] = { 1,3,4,6,3,9,12,5,17,28,39,69,369,31 };
	size_t size2 = sizeof(numbers)/sizeof(*numbers);
	sortFunc(numbers, size2);
	
		return 0;
}