#include "LexiaProject.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

void LexiaProject::loadProject(const std::string& projectPath) {
    std::ifstream file(projectPath);

    if (!file.is_open()) {
        std::cerr << "Error: The project file could not be opened " << projectPath << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string type;
        ss >> type;

        if (type == "minRandomLimit") {
            ss >> minRandomLimit;
        } else if (type == "maxRandomLimit") {
            ss >> maxRandomLimit;
        }
        else if (type == "actionText") {
            std::string actionText;
            // Читаем все оставшиеся слова в строке, включая пробелы
             std::getline(ss, actionText, '\n');
            // Удаляем пробел в начале строки
            if (!actionText.empty() && actionText[0] == ' ') {
                actionText.erase(0, 1);
             }
             actions.push_back(actionText);
        }

    }

    file.close();
}

void LexiaProject::saveProject(const std::string& projectPath) {
    std::ofstream file(projectPath);

    if (file.is_open()) {
        file << "minRandomLimit " << minRandomLimit << std::endl;
        file << "maxRandomLimit " << maxRandomLimit << std::endl;
        for(const auto& action : actions) {
             file << "actionText " << action << std::endl;
        }

        file.close();
    } else {
        std::cerr << "Error: The project file could not be saved " << projectPath << std::endl;
    }
}

void LexiaProject::setMinRandomLimit(int min) {
    minRandomLimit = min;
}

void LexiaProject::setMaxRandomLimit(int max) {
    maxRandomLimit = max;
}

int LexiaProject::getMinRandomLimit() const {
    return minRandomLimit;
}

int LexiaProject::getMaxRandomLimit() const {
    return maxRandomLimit;
}

void LexiaProject::addAction(const std::string& actionText) {
    actions.push_back(actionText);
}