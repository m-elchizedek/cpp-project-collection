#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <limits>

std::string current_file;
std::string buffer;

void create_file() {
    std::string name;

    std::cout << "enter file name: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(std::cin, name);

    name += ".txt";

    std::ofstream file(name);

    if (!file) {
        std::cout << "failed to create file\n";
        return;
    }

    current_file = name;
    buffer.clear();

    std::cout << "file created: " << name << "\n";
}

void open_file() {
    std::string name;

    std::cout << "enter file name: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(std::cin, name);

    name += ".txt";

    std::ifstream file(name);

    if (!file) {
        std::cout << "file not found\n";
        return;
    }

    buffer.clear();
    std::string line;

    while (getline(file, line)) {
        buffer += line + '\n';
    }

    current_file = name;

    std::cout << "file loaded.\n";
}


void edit_file() {
    if (current_file.empty()) {
        std::cout << "no file open.\n";
        return;
    }

    std::cout << ":wq = to save and quit\n";
    std::cout << ":undo = to remove last line\n";
    std::cout << "----Enter text----\n";

    std::string line;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    while (true) {
        getline(std::cin, line);

        if (line == ":wq")
            break;

        if (line == ":undo") {
            size_t pos = buffer.find_last_of('\n');

            if (pos != std::string::npos)
                buffer.erase(pos);
            else
                buffer.clear();

            std::cout << "(last line removed)\n";
            continue;
        }

        buffer += line + '\n';
    }
}


void view_file() {
    if (current_file.empty()) {
        std::cout << "no file open.\n";
        return;
    }

    std::cout << "\n----- FILE CONTENT -----\n";
    std::cout << buffer;
}

void save_file() {
    if (current_file.empty()) {
        std::cout << "no file open.\n";
        return;
    }

    std::ofstream file(current_file);

    if (!file) {
        std::cout << "save failed\n";
        return;
    }

    file << buffer;

    std::cout << "file saved.\n";
}

void search_text() {
    std::string word;

    std::cout << "search for: ";
    std::cin >> word;

    if (buffer.find(word) != std::string::npos)
        std::cout << "found\n";
    else
        std::cout << "not found.\n";
}

int main() {

    std::string command;
    std::string cmds;

    std::cout << "welcome to console system\n";
    std::cout << "would you like to see the commands?(Y/N): ";
    std::cin >> cmds;
    std::transform(cmds.begin(), cmds.end(),
                       cmds.begin(),
                       [](unsigned char c){ return std::tolower(c); });
    if (cmds == "y"){
        std::cout << "the commands are:\n";
        std::cout << "/create/ " << "/open/ " << "/edit/ " << "/view/ " << "/save/ " << "/search/ " << "/exit/\n";

    }else if(cmds == "n"){
        std::cout << "continuing...";
    }else{
        std::cout << "improper content";
    }

    while (true) {

        std::cout << "\nconsole> ";
        std::cin >> command;

        std::transform(command.begin(), command.end(),
                       command.begin(),
                       [](unsigned char c){ return std::tolower(c); });

        if (command == "create")
            create_file();

        else if (command == "open")
            open_file();

        else if (command == "edit")
            edit_file();

        else if (command == "view")
            view_file();

        else if (command == "save")
            save_file();

        else if (command == "search")
            search_text();

        else if (command == "exit")
            break;

        else
            std::cout << "unknown command\n";
    }


    std::cout << "goodbye.\n";
}
