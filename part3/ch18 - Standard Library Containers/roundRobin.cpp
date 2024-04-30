#include <cstddef>
#include <stdexcept>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

template <typename T>
class RoundRobin
{
    public:
        explicit RoundRobin(size_t numExpected = 0);
        virtual ~RoundRobin() = default;

        // copy constructor delete
        RoundRobin(const RoundRobin& src) = delete;
        RoundRobin& operator=(const RoundRobin& rhs) = delete;

        RoundRobin(RoundRobin&& src) noexcept = default;
        RoundRobin& operator=(RoundRobin&& rhs) noexcept = default;

        void add(const T& element);
        void remove(const T& element);

        T& getNext();
    private:
        vector<T> m_elements;
        typename vector<T>::iterator m_nextElement;
};

template <typename T> RoundRobin<T>::RoundRobin(size_t numExpected)
{
    m_elements.reserve(numExpected);
    m_nextElement = begin(m_elements);
}

template <typename T> void RoundRobin<T>::add(const T& element)
{
    ptrdiff_t pos { m_nextElement - begin(m_elements) };
    m_elements.push_back(element);
    
    m_nextElement = begin(m_elements) + pos;
}

template <typename T> void RoundRobin<T>::remove(const T& element)
{
    for (auto it { begin(m_elements)}; it != end(m_elements); ++it) {
        if (*it == element) {
            ptrdiff_t newPos;

            if (m_nextElement == end(m_elements) - 1 && m_nextElement == it) {
                newPos = 0;
            } else if (m_nextElement <= it) {
                newPos = m_nextElement - begin(m_elements);
            } else {
                newPos = m_nextElement - begin(m_elements) - 1;
            }

            m_elements.erase(it);
            m_nextElement = begin(m_elements) + newPos;
            return;
        }
    }
}

template <typename T> T& RoundRobin<T>::getNext()
{
    if (m_elements.empty()) {
        throw out_of_range{"No elements in the list"};
    }

    auto& toReturn { *m_nextElement };

    ++m_nextElement;
    if (m_nextElement == end(m_elements)) { m_nextElement = begin(m_elements);}
    return toReturn;
}

class Process final
{
    public:
        explicit Process(string name) : m_name{name} {}

        void doWorkDuringTimeSlice()
        {
            cout << "Process " << m_name << " performing work during time slice." << endl;
        }
    private:
        string m_name;
};

class Scheduler final
{
    public:
        explicit Scheduler(const vector<Process>& processes)
        {
            for (auto& process : processes) { m_processes.add(process);}
        }

        void scheduleTimeSlice()
        {
            try {
                m_processes.getNext().doWorkDuringTimeSlice();
            } catch (const out_of_range& e) {
                cerr << "No more processes to schedule." << endl;
            }
        }

        void removeProcess(const Process& process)
        {
            m_processes.remove(process);
        }
    private:
        RoundRobin<Process> m_processes;
};

int main()
{
    vector<Process> processes { Process {"1"}, Process{"2"}, Process{"3"}};

    Scheduler scheduler { processes };
    for (size_t i { 0 }; i < 4; ++i) { scheduler.scheduleTimeSlice();}

    scheduler.removeProcess(processes[1]);
    cout << "Removed second process" << endl;

    for (size_t i { 0}; i < 4; ++i) { scheduler.scheduleTimeSlice();}
}