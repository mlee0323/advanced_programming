#include "std_lib_facilities.h"


void dictionary(vector<string>& words) {
    ifstream ifs("words.txt");
    string word;
    while (ifs >> word) {
        if (word.length() == 5) {
            words.push_back(word);
        }
    }
}

void sortWords(vector<string>& words) {
    sort(words.begin(), words.end());
}

string getRandomWord(const vector<string>& words) {
    int n = words.size();
    int randIndex = randint(n - 1);
    return words[randIndex];
}

string getUserGuess(int tries) {
    cout << "[" << tries + 1 << "/6] Guess the right word: ";
    string guess;
    cin >> guess;
    return guess;
}

void printGuessResult(const string& guess, const string& word) {
    int n = word.length();
    vector<char> result(n, '@');
    for (int i = 0; i < n; i++) {
        if (guess[i] == word[i]) {
            result[i] = '*';
        }
        else if (find(word.begin(), word.end(), guess[i]) != word.end()) {
            result[i] = '#';
        }
    }
    for (char c : result) {
        cout << c;
    }
    cout << endl;
}

bool playGame() {
    vector<string> words;
    dictionary(words);
    sortWords(words);
    string word = getRandomWord(words);
    int tries = 0;
    while (tries < 6) {
        string guess = getUserGuess(tries);
        if (guess == word) {
            cout << endl << "Congratulations!!! You are correct." << endl << endl;

            return true;
        }
        else {
            tries++;
            cout << "==> ";
            printGuessResult(guess, word);
            cout << endl;
        }
    }
    cout << "Oops!!! You lost all your chances. The correct answer is " << "\"" << word << "\"." << endl << endl;
    return false;
}

int dictionary_option(int dictionary_num, int max_dictionary) {
    while (dictionary_num < 1 || dictionary_num > max_dictionary) {
        cout << "Choose an option (1-2): ";
        cin >> dictionary_num;
    }
    return dictionary_num;
}



void showDictionary() {
    bool exitFlag = false;
    vector<string> words;
    dictionary(words);
    sortWords(words);
    while (!exitFlag) {
        cout << "[ DICTIONARY ]" << endl
            << "1. Print" << endl
            << "2. Return" << endl << endl ;
        int selection;
        selection = 0;
        selection = dictionary_option(selection, 2);
        cout << endl;
        if (selection == 1) {
            for (string word : words) {
                cout << word << endl;
            }
            cout << endl << "A total of " << words.size() << " words are available." << endl << endl;
        }
        else if (selection == 2) {
            exitFlag = true;
        }
        else {
            cout << "Invalid selection. Please try again." << endl;
        }
    }
}

void Menu() {
    cout << "<<<WORDLE>>>" << endl
        << "1. Dictionary" << endl
        << "2. Game" << endl
        << "3. Exit" << endl << endl;
}

void GameMenu() {
    bool exitFlag = false;
    vector<string> words;
    while (!exitFlag) {
        cout << "[ GAME ]" << endl;
        cout << "1. Play" << endl;
        cout << "2. Return" << endl;
        int selection;
        selection = 0;
        selection = dictionary_option(selection, 2);
        cout << endl;
        if (selection == 1) {
            cout << "A new 5-letter word has been chosen randomly from the dictionary." << endl << endl;
            playGame();
        }
        else if (selection == 2) {
            exitFlag = true;
        }
        else {
            cout << "Choose an option (1-2): ";
        }
    }
}

int main_option(int main_num, int max_num) {
    while (main_num < 1 || main_num > max_num) {
        cout << "Choose an option (1-3): ";
        cin >> main_num;
    }
    return main_num;
}

int main() {
    srand(time(nullptr));
    bool exitFlag = false;
    while (!exitFlag) {
        Menu();
        int selection;
        selection = 0;
        selection = main_option(selection, 3);
        cout << endl;
        if (selection == 1) {
            showDictionary();
        }
        else if (selection == 2) {
            GameMenu();
        }
        else if (selection == 3) {
            exitFlag = true;
            cout << endl << "Good bye!!!" << endl;
        }
        else {
            cout << "Choose an option (1-3): ";
        }
    }
    return 0;
}