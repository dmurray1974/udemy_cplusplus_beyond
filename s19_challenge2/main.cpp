#include <iostream>
#include <fstream>

void print_header() {
    std::cout << std::setw(15) << std::left << "Student"
              << std::setw(5) << "score" << std::endl;
    std::cout << std::setw(20) << std::setfill('-') << "" << std::endl;
    std::cout << std::setfill(' ') << std::endl;
}

void print_footer(double average) {
    std::cout << std::setw(20) << std::setfill('-') << std::endl;
    std::cout << std::setfill(' ') << std::endl;
    std::cout << std::setw(15) << std::left << "Average Score"
            << std::setw(5) << std::right << average  << std::endl;
}

void print_student(const std::string &student, int score) {
    std::cout << std::setprecision(1) << std::fixed;
    std::cout << std::setw(15) << std::left << student
              << std::setw(5) << std::right << score << std::endl;
}

int process_response(const std::string &response, const std::string &answer_key) {
    int score {0};
    for (size_t i = 0; i < answer_key.size(); i++) {
        if (response.at(i) == answer_key.at(i)) {
            score++;
        }
    }
    return score;
}

int main() {

    std::ifstream inputFile;
    std::string answer_key {};
    std::string name {};
    std::string response {};
    int running_sum {0};
    int total_students {0};
    double average_score {0.0};

    inputFile.open("../studentGrades.txt");
    if (!inputFile) {
        std::cerr << "Could not open file" << std::endl;
        return 1;
    }

    inputFile >> answer_key;

    print_header();

    while (inputFile >> name >> response) {
        ++total_students;
        int score = process_response(response, answer_key);
        running_sum += score;
        print_student(name, score);
    }

    if (total_students != 0) {
        average_score = static_cast<double>(running_sum) / total_students;
    }

    print_footer(average_score);

    inputFile.close();
    return 0;
}