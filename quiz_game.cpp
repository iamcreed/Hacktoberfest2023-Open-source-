#include <iostream>
#include <map>
#include <string>

// Question struct to hold the question and its correct answer
struct Question {
    std::string question;
    std::string correctAnswer;
};

int main() {
    std::map<int, Question> quiz; // Map to store questions with IDs

    // Populate the quiz with questions and correct answers
    quiz[1] = { "What is the capital of France?", "Paris" };
    quiz[2] = { "Which planet is known as the Red Planet?", "Mars" };
    quiz[3] = { "What is the largest mammal?", "Blue Whale" };
    quiz[4] = { "What year did World War II end?", "1945" };
    quiz[5] = { "Who painted the Mona Lisa?", "Leonardo da Vinci" };

    int score = 0;

    std::cout << "Welcome to the Quiz Game!\n";
    std::cout << "Answer the following questions:\n";

    // Iterate through the questions
    for (const auto& pair : quiz) {
        std::cout << "Question " << pair.first << ": " << pair.second.question << "\nYour answer: ";
        std::string userAnswer;
        std::getline(std::cin, userAnswer);

        // Convert the user's answer to lowercase for case-insensitive comparison
        for (char &c : userAnswer) {
            c = tolower(c);
        }

        // Check if the answer is correct
        if (userAnswer == pair.second.correctAnswer) {
            std::cout << "Correct!\n";
            score += 10; // Increase score for each correct answer
        } else {
            std::cout << "Incorrect. The correct answer is: " << pair.second.correctAnswer << "\n";
        }
    }

    std::cout << "\nQuiz complete! Your total score is: " << score << " points out of " << quiz.size() * 10 << " points\n";

    return 0;
}
