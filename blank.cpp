#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Структура, представляющая информацию о студенте
struct Student {
    string name;
    int labs;
    int practices;

    // Конструктор для удобного создания объектов Student
    Student(string n, int l, int p) : name(n), labs(l), practices(p) {}

    // Метод для вычисления рейтинга стресса студента
    int stressRating() const {
        return labs + practices * 10;
    }
};

int main() {
    // Создаем вектор, хранящий информацию о студентах
    vector<Student> students;

    // Заполняем вектор данными о студентах
    students.push_back(Student("Иван", 2, 3));
    students.push_back(Student("Мария", 1, 5));
    students.push_back(Student("Петр", 3, 2));

    // Находим студента(-ов) с самым высоким рейтингом стресса
    auto maxStressStudent = max_element(students.begin(), students.end(), [](const Student& s1, const Student& s2) {
        return s1.stressRating() < s2.stressRating();
    });

    // Выводим информацию о студенте(-ах) с самым высоким рейтингом стресса
    cout << "Студент(-ы) с самым высоким рейтингом стресса:\n";
    for (const auto& student : students) {
        if (student.stressRating() == maxStressStudent->stressRating()) {
            cout << "Имя: " << student.name << ", Рейтинг стресса: " << student.stressRating() << endl;
        }
    }

    return 0;
}
