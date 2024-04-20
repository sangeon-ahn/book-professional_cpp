class Record
{

};

class RecordID 
{

}

// formal한 방식의 주석 -> 별로 안좋다.
// Saves the given record to the datbase.
//
// Parameters:
//  record: If the given record does not yet have a database ID, then the method
//  modifies the record object to store the ID assigned by the database.
// Returns: int
//  An integer representing the ID of the saved record.
// Throws:
//  DatabaseNotOpenedException if the openDatabase() method has not
//  been called yet.
int saveRecord(Record& record);

// 함수 설명부분은 함수 이름으로 알 수 있으므로 제거하였고, 타입은 빌트인 타입에서 커스텀 타입으로 전환함으로써 타입만 읽어도 어떤 값을 리턴하는지 알 수 있도록 하여, 리턴타입 설명 제거.
// Parameters:
//  record: If the given record does not yet have a database ID, then the method
//  modifies the record object to store the ID assigned by the database.
// Throws:
//  DatabaseNotOpenedException if the openDatabase() method has not
//  been called yet.
RecordID saveRecord(Record& record);

// Implements the "insertion sort" algorithm. The algorithm separates the 
void sort(int data[], size_t size)
{
    for (int i { 1 }; i < size; ++i) {
        int element { data[i] };
        int j { i };

        while (j > 0 && data[j - 1] > element) {
            data[j] = data[j - 1];
        }
        data[j] = element;
    }
}

/**
 * Implements the basic functionality of a watermelon
 * TODO: Implement updated algorithms!
*/
export class watermelon
{
    public:
        /**
         * 
         * @param initialSeeds The starting number of seeds, must be > 5.
         * @throws invalid_argument if initialSeeds <= 5. 
        */
       Watermelon(size_t initialSeeds);
}