#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

class LexiaProject {
public:
    void loadProject(const std::string& projectPath);
    void saveProject(const std::string& projectPath);
    void setMinRandomLimit(int min);
    void setMaxRandomLimit(int max);
    int getMaxRandomLimit() const;
    int getMinRandomLimit() const;
    void addAction(const std::string& actionText);
private:
    int minRandomLimit = 1;
    int maxRandomLimit = 10;
    std::vector<std::string> actions;

};