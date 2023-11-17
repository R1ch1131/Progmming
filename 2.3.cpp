#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Student {
    string name;
    int age;
};

bool compareNames(const Student& a, const Student& b) {
    return a.name < b.name;
}

bool compareAges(const Student& a, const Student& b) {
    return a.age < b.age;
}

int main() {
    int N;
    cin >> N;

    vector<Student> students(N);
    for (int i = 0; i < N; i++) {
        cin >> students[i].name >> students[i].age;
    }

    stable_sort(students.begin(), students.end(), compareNames);
    sort(students.begin(), students.end(), compareAges);

    for (const auto& student : students) {
        cout << student.name << " " << student.age << endl;
    }

    return 0;
}