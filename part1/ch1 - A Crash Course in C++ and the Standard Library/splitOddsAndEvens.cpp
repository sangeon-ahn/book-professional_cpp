#include <iostream>
using namespace std;

void splitOddsAndEvensWithArray(const int arr[], size_t size, size_t& oddsSize, size_t& evensSize, int*& odds, int*& evens)
{
    // arr 순회하며 홀짝 센다.
    for (size_t i { 0 }; i < size; ++i) {
        if (arr[i] % 2 == 1) {
            ++oddsSize;
        } else {
            ++evensSize;
        }
    }

    odds = new int[oddsSize];
    evens = new int[evensSize];

    int oddsIdx = 0, evensIdx = 0;
    for (size_t i { 0 }; i < size; ++i) {
        if (arr[i] % 2 == 1) {
            odds[oddsIdx] = arr[i];
        } else {
            evens[evensIdx] = arr[i];
        }
    }
    // odds, evens에 접근하며 홀이면 odds에, 짝이면 evens에 추가.
}

void splitOddsAndEvensWithVector(const vector<int>& arr, vector<int>& odds, vector<int>& evens)
{
    for (int num : arr) {
        if (num % 2 == 0) {
            evens.push_back(num);
        } else {
            odds.push_back(num);
        }
    }
}

struct OddsAndEvens {
    vector<int> odds, evens;
};

// RVO(return value optimization)과 NRVO(named return value optimization)을 이용하여 output parameter 사용을 방지.
OddsAndEvens splitOddsAndEvensWithoutOutputParameters(const vector<int>& arr)
{
    vector<int> odds, evens;
    for (int num : arr) {
        if (num % 2 == 0) {
            evens.push_back(num);
        } else {
            odds.push_back(num);
        }
    }

    return OddsAndEvens {.odds = odds, .evens = evens};
}

int main()
{
    int arr[] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    size_t oddsSize { 0 };
    size_t evensSize { 0 };
    
    int* odds { nullptr };
    int* evens { nullptr };
    
    splitOddsAndEvensWithArray(arr, size(arr), oddsSize, evensSize, odds, evens);    
    delete[] odds; odds = nullptr;
    delete[] evens; evens = nullptr;


    // vector는 따로 delete 해줄 필요 없다. vector 내부에서 알아서 처리해줌.
    vector<int> vec { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    vector<int> vecOdds, vecEvens;

    splitOddsAndEvensWithVector(vec, vecOdds, vecEvens);

    for (auto& num: vecOdds) {
        cout << num;
    }
    cout << endl;
    for (auto& num: vecEvens) {
        cout << num;
    }

    auto oddsAndEvens = splitOddsAndEvensWithoutOutputParameters(vec);
    
}