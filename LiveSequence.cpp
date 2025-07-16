#include <iostream>
#include <string>
#include <deque>
#include <chrono>
#include <thread>
#include <windows.h> 

/*
This program was inspired by the movie "Brick," which featured a security feature that relied on a specific photon signal to open a door.
The system operated in real time and interpreted the signals until a specific sequence was achieved.
*/


using namespace std;
using namespace std::chrono;

int main() {
    string password;
    cout << "=== Live checking of text ===\n";
    cout << "Set a password: ";
    cin >> password;
    cin.ignore();

    const int time_limit_sec = 10;
    auto start_time = steady_clock::now();

    deque<char> buffer;

    cout << " You have " << time_limit_sec << " seconds.\n";
    cout << "Start typing:\n";

    while (true) {
        auto now = steady_clock::now();
        auto elapsed = duration_cast<seconds>(now - start_time).count();
        if (elapsed >= time_limit_sec) {
            cout << "\n=======Sequence=NOT=detected.\n";
            return 0;
        }
        for (int vk = 32; vk <= 126; ++vk) {
            SHORT state = GetAsyncKeyState(vk);
            if (state & 0x8000) {
                char ch = static_cast<char>(vk);
                cout << ch;
                buffer.push_back(ch);
                if (buffer.size() > password.size())
                    buffer.pop_front();
                string current(buffer.begin(), buffer.end());
                bool match = true;
                for (size_t i = 0; i < password.size(); ++i) {
                    if (tolower(current[i]) != tolower(password[i])) {
                        match = false;
                        break;
                    }
                }

                if (match) {
                    cout << "\n =======Sequence=detected=======\n";
                    return 0;
                }

                while (GetAsyncKeyState(vk) & 0x8000)
                    this_thread::sleep_for(milliseconds(10));
            }
        }

        this_thread::sleep_for(milliseconds(5));
    }

    return 0;
}
