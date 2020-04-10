// Calculator.h
// WS09 in-lab
#ifndef _SDDS_CALCULATOR_H__
#define _SDDS_CALCULATOR_H__
#include <iostream>
namespace sdds
{
	template<typename T, int N>
	class Calculator{
		T result[N];
	public:
		Calculator(){
			for (int i = 0; i < N; i++){
				result[i] = 0;
			}
		}
		void add(const T* arr1, const T* arr2){
			for (int i = 0; i < N; i++){
				result[i] = arr1[i] + arr2[i];
			}
		}
		void subtract(const T* arr1, const T* arr2){
			for (int i = 0; i < N; i++){
				result[i] = arr1[i] - arr2[i];
			}
		}
		void multiply(const T* arr1, const T* arr2){
			for (int i = 0; i < N; i++){
				result[i] = arr1[i] * arr2[i];
			}
		}
		void divide(const T* arr1, const T* arr2){
			for (int i = 0; i < N; i++){
				result[i] = arr1[i] / arr2[i];
			}
		}
		std::ostream& display(std::ostream& os)const{
			for (int i = 0; i < N; i++){
				os << result[i];
				if (i < N - 1)
					os << ",";
			}
			os << std::endl;
			return os;
		}
		Calculator& operator+=(const T* t){
			for (int i = 0; i < N; i++){
				result[i] += t[i];
			}
			return *this;
		}
		Calculator& operator-=(const T* t){
			for (int i = 0; i < N; i++){
				result[i] -= t[i];
			}
			return *this;
		}
		Calculator& operator*=(const T* t){
			for (int i = 0; i < N; i++){
				result[i] *= t[i];
			}
			return *this;
		}
		Calculator& operator/=(const T* t){
			for (int i = 0; i < N; i++){
				result[i] /= t[i];
			}
			return *this;
		}
	};
}
#endif