#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <sstream>

struct user {
    std::string username;
    std::string password;
    bool is_active;
};

std::string user_to_json(const std::vector<user>& users) {
    std::ostringstream json;

    json << "[\n";

    for (size_t i = 0; i < users.size(); ++i) {
        json << "  {\n"
            << "    \"username\": \"" << users[i].username << "\",\n"
            << "    \"password\": \"" << users[i].password << "\",\n"
            << "    \"is_active\": "
            << (users[i].is_active ? "true" : "false") << "\n"
            << "  }";

        if (i < users.size() - 1) {
            json << ",";
        }

        json << "\n";
    }

    json << "]";

    return json.str();
}


void login(const std::vector<user>& users) {
    std::string username;
    std::string password;

    std::cout << "Enter username: ";
    std::cin >> username;

    std::cout << "Enter password: ";
    std::cin >> password;

    bool success = false;

    for (const auto& u : users) {
        if (u.username == username &&
            u.password == password &&
            u.is_active) {

            success = true;
            break;
        }
    }

    if (success) {
        std::cout << "Login successful!\n";
    }
    else {
        std::cout << "invalid credentials.\n";
    }
}

void register_user(std::vector<user>& users) {
    std::string username;
    std::string password;

    std::cout << "choose username: ";
    std::cin >> username;

    std::cout << "choose password: ";
    std::cin >> password;

    users.push_back({ username, password, true });

    std::cout << "successfully registered!\n";
}

int main() {
    std::vector<user> users;

    char choice;

    std::cout << "login or register? (l/r): ";
    std::cin >> choice;

    choice = std::tolower(choice);

    if (choice == 'l') {
        login(users);
    }
    else if (choice == 'r') {
        register_user(users);

        std::cout << "\nJSON output:\n";
        std::cout << user_to_json(users) << std::endl;
    }
    else {
        std::cout << "invalid option.\n";
    }

    return 0;
}
