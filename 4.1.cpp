#include <iostream>
#include <algorithm>

struct Node {
    int data, min_val;
    Node* next;

    Node(int data, int min_val, Node* next = nullptr) : data(data), min_val(min_val), next(next) {}
};

class MinStack {
private:
    Node* top = nullptr;

public:
    void push(int data) {
        int current_min_val = top ? std::min(data, top->min_val) : data;
        top = new Node(data, current_min_val, top);
    }

    void pop() {
        if (top) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    int topValue() {
        return top ? top->data : -1;
    }

    int getMin() {
        return top ? top->min_val : -1;
    }
};

int main() {
    MinStack stack;
    std::string command;
    
    while (std::cin >> command) {
        if (command == "exit") break;
        if (command == "push") {
            int value;
            std::cin >> value;
            stack.push(value);
        } else if (command == "pop") {
            stack.pop();
        } else if (command == "top") {
            std::cout << stack.topValue() << std::endl;
        } else if (command == "min") {
            std::cout << stack.getMin() << std::endl;
        }
    }

    return 0;
}