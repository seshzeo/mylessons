#include <iostream>
#include <fstream>

using namespace std;

class FileWasNotOpenedException : public exception {
public:
    const char* _message;
    FileWasNotOpenedException(const char* message) : _message(message) {}
    virtual const char* _what() const { return _message; }
    ~FileWasNotOpenedException(){}
};

int main() {
    string path = "myFile.txt";
    ifstream textfile; //объект класса библиотеки чтения из файл

    cout << "Введите имя файла с расширением или путь: ";
    cin >> path;
    try {
        textfile.open(path);

        if(!textfile.is_open()) {
            cout << path << " ";
            throw FileWasNotOpenedException("ошибка открытия файла");
            
        } else {
            cout << "\nФайл " << path << " открыт\n";
            cout << "---------------------------------------------------------------------------------\n\n";
            string str;
            
            while(!textfile.eof()) {
                str = "";
                getline(textfile, str);
                cout << str << endl;
            }
            cout << "\n---------------------------------------------------------------------------------\n";
        }
        textfile.close();
    }
    catch(const FileWasNotOpenedException& e) {
        cout << e._what() << '\n';
    }

    

    return 0;
}