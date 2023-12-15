#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

class CustomQueue {
private:
    priority_queue<pair<int, unsigned int>> pq;

public:
    void enqueue(int k, unsigned int opNumber) {
        pq.push({k, opNumber});
    }

    void dequeueMax() {
        if (!pq.empty()) {
            pair<int, unsigned int> maxElem = pq.top();
            cout << maxElem.second << " " << maxElem.first << endl;
            pq.pop();
        } else {
            cout << "*" << endl;
        }
    }

    void increaseElement(unsigned int opNumber, int v) {
        vector<pair<int, unsigned int>> temp;
        while (!pq.empty()) {
            pair<int, unsigned int> current = pq.top();
            pq.pop();
            if (current.second >= opNumber) {
                current.first += v;
            }
            temp.push_back(current);
        }
        for (auto &element : temp) {
            pq.push(element);
        }
    }
};

int main() {
    CustomQueue queue;
    string command;
    while (cin >> command) {
        if (command == "enqueue") {
            int k;
            cin >> k;
            static unsigned int opNumber = 1;
            queue.enqueue(k, opNumber);
            opNumber++;
        } else if (command == "dequeue_max") {
            queue.dequeueMax();
        } else if (command == "inc") {
            unsigned int i, v;
            cin >> i >> v;
            queue.increaseElement(i, v);
        }
    }
    return 0;
}