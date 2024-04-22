#include <initializer_list>
#include <iostream>
#include <vector>
#include <exception>

using namespace std;

class EvenSequence
{
    public:
        EvenSequence(initializer_list<double> args) {
            if (args.size() % 2 != 0) {
                throw invalid_argument(" args's size is not even.");
            }
            nums.assign(args);
        }
        
        void printNums() {
            for (const auto& num : nums) {
                cout << num << endl;
            }
        }
    private:
        vector<double> nums;
};

int main()
{
    try {
        // EvenSequence es { 1.1, 2.8, 4.4, 44.3 };
        EvenSequence es { 1.1, 2.8, 4.4 };
        es.printNums();
    } catch (const invalid_argument& e) {
        cerr << "ERROR" << e.what() << endl;
    }
}