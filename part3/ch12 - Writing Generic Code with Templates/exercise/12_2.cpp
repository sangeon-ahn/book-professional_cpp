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

template <>
class KeyValuePair<const char*, const char*>
{
    public:
        KeyValuePair(const char*& key, const char*& value) : m_key{key}, m_value{value} {}

        const string& getKey() const { return m_key; }
        const string& getValue() const { return m_value; }

        void setKey(const char*& key) { m_key = key;}
        void setValue(const char*& value) { m_value = value;}
    private:
        string m_key;
        string m_value;
};

int main()
{
    const char* s1 { "hello" };
    const char* s2 { "world" };

    KeyValuePair<const char*, const char*> pair { s1, s2 };

    cout << pair.getKey() << pair.getValue() << endl;
}