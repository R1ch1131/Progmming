#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class CustomQueue {
private:
    vector<pair<int, unsigned int>> pq;

    void siftUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (pq[parent].first < pq[index].first) {
                swap(pq[parent], pq[index]);
                index = parent;
            } else {
                break;
            }
        }
    }

    void siftDown(int index) {
        int size = pq.size();
        while (2 * index + 1 < size) {
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;
            int maxChild = leftChild;

            if (rightChild < size && pq[rightChild].first > pq[leftChild].first) {
                maxChild = rightChild;
            }

            if (pq[index].first < pq[maxChild].first) {
                swap(pq[index], pq[maxChild]);
                index = maxChild;
            } else {
                break;
            }
        }
    }

public:
    void enqueue(int k, unsigned int opNumber) {
        pq.push_back({k, opNumber});
        siftUp(pq.size() - 1); 
    }

    void dequeueMax() {
        if (!pq.empty()) {
            pair<int, unsigned int> maxElem = pq[0];
            cout << maxElem.second << " " << maxElem.first << endl;
            pq[0] = pq.back();
            pq.pop_back();
            siftDown(0);
        } else {
            cout << "*" << endl;
        }
    }

    void increaseElement(unsigned int opNumber, int v) {
        for (auto &element : pq) {
            if (element.second >= opNumber) {
                element.first += v;
            }
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