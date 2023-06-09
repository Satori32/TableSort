#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

template<class T,class F>
std::vector<T> TableSort(const std::vector<T>& A, F op) {//nomaly case is not need this.

	std::vector<std::size_t> X;//table

	for (std::size_t i = 0; i < A.size(); i++) {
		X.push_back(i);
	}

	for (std::size_t i = 0; i < A.size(); i++) {
		for (std::size_t j = i + 1; j < A.size(); j++) {
			//if(A[X[i]] > A[X[j]]){
			if (op(A[X[i]] , A[X[j]])) {
				std::swap(X[i],X[j]);
			}
		}
	}
	/** /
	for (std::size_t i = 0; i < A.size(); i++) {//A[] element is move to only one. 
		A[i] = A[X[i]];
	}
	/**/
	std::vector<T> Y;
	for (std::size_t i = 0; i < A.size(); i++) {//A[] element is move to only one. 
		Y.push_back(A[X[i]]);
	}

	return Y;
 }

 int main() {

	 std::random_device rd;
	 std::mt19937 mt(rd());
	 std::uniform_int_distribution<> ui(0, 128);
	 std::vector<int> V;

	 std::size_t L = 1024;

	 for (std::size_t i = 0; i < L; i++) {
		 V.push_back(ui(mt));
	 }
	 for (auto& o : V) {
		 std::cout << o << ',';
	 }
	 std::cout << std::endl;
	 std::cout << std::endl;

	 std::vector<int> X = V;
	 auto F = [](const auto& A, const auto& B) {return A > B; };

	 auto Y = TableSort(X, F);

	 for (auto& o : Y) {
		 std::cout << o << ',';
	 }
	 std::cout << std::endl;
	 std::cout << std::endl;

	 std::sort(V.begin(), V.end(),F);
	 for (auto& o : V) {
		 std::cout << o << ',';
	 }
	 std::cout << std::endl;
	 std::cout << std::endl;
	 
	 if (V == Y) { std::cout << "OK!" << std::endl; }
	 else
	 {
		 std::cout << "NOT Ok!" << std::endl;
	 }

	 return 0; 
 }
