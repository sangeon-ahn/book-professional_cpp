#include <string>
#include <iostream>
using namespace std;

template <typename Key, typename Value>
class KeyValuePair
{
    public:
        KeyValuePair(Key key, Value value) : m_key{key}, m_value{value} {};
        
        const Key& getKey() const { return m_key; }
        const Value& getValue() const { return m_value; }

        void setKey(Key key) { m_key = key; }
        void setValue(Value value) { m_value = value; }
    private:
        Key m_key;
        Value m_value;
};

int main()
{
    KeyValuePair<string, int> pair { "sangeonAhn", 26}; 
    
    decltype(auto) key = pair.getKey();
    decltype(auto) value = pair.getValue();

    cout << "key: " << key << endl;
    cout << "value: " << value << endl; 
}