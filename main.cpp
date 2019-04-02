#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

class Player {
    public:
        Player() {
            name = chooseName();
            chooseWord();
            cout << "Co chcesz zrobic?(1 - gra, 2 - ranking)\n";
            int x;
            cin >> x;
            if (x == 1) {
                if (loop()) {
                    cout << "Gra skonczona!\n";
                    cout << "Liczba twoich ruchow to: " << moves;
                    cout << "\nTwoje slowo to: " << _word;
                    save(name + ": " + to_string(moves));
                }
            } else if (x == 2) {
                loadRanking();
                return;
            } else {
                return;
            }
        }

        string name;
        string word;
        string _word;
        bool game = true;
        int moves = 0;
        int length;
        int lettersToSeek;

        string chooseName() {
            cout << "Wybierz imie: ";
            string name;
            cin >> name;
            return name;
        }

        bool loop() {
            cout << "Gra w zgadywanie:\n";
            cout << "(Po kazdej literze kliknij Enter by potwierdzic wybor!)\n";
            while (game) {
                char x;
                cin >> x;
                moves++;
                if (isCorrectChar(x)) {
                    if (--lettersToSeek == 0) {
                        game = false;
                        return true;
                    }
                }

            }
            return true;
        }

    private:
        void save(string content) {
            fstream save;
            save.open("save.txt", ios_base::app);
            save << content << "\n";
        }

        bool isCorrectChar(char x) {
            for (int i = 0; i < length; i++) {
                if (x == word[i]) {
                    cout << "Poprawna litera!\n";
                    word[i] = 0;
                    return true;
                }
            }
            return false;
        }

        void chooseWord() {
            int x = rand()%3;
            switch (x) {
                case 1:
                    word = "KOTEK";
                    _word = "KOTEK";
                    length = 5;
                    lettersToSeek = 5;
                    break;
                case 2:
                    word = "PIESEK";
                    _word = "PIESEK";
                    length = 6;
                    lettersToSeek = 6;
                    break;
                default:
                    word = "DOMEK";
                    _word = "DOMEK";
                    length = 5;
                    lettersToSeek = 5;
                    break;
            }
        }

        void loadRanking() {
            fstream saves;
            saves.open("save.txt");
            string row;
            while (!saves.eof()) {
                saves >> row;
                cout << row << "\n";
            }
        }
};

int main() {

    Player player;

    cout << "\n";
    system("pause");
    return 0;
}