#include <iostream>
#include <time.h>

#define STUD "Студент"
#define PROF "Профессор"
#define SCIE "Научный сотрудник"
#define TCHW "Техник"

using namespace std;

template <class T1, class T2> void check_perm(const T1&, const T2*, unsigned int);

class Passcard //клас реализации карточек доступа.
{
private:
    static unsigned int count_for_id; //для присваивания уникального номера карте.
    unsigned int id; //сам уникальный номер.
    string name;
protected:
    string passcard_type;
public:
    Passcard(const unsigned int* database, string name, string passcard_type) {
        this->name = name;
        this->passcard_type = passcard_type;
        this->id = database[count_for_id];
        count_for_id++;
    };
    Passcard(const unsigned int* database, string name) {
        this->name = name;
        this->id = database[count_for_id];
        count_for_id++;
    };
    //геттеры. изменение данных не предусмотренно намеренною. Данне инициализируюся один раз при создании карты.
    string get_name() const { return name; }
    unsigned int get_id() const { return id; }
    string get_passcard_type() const { return passcard_type; }

    ~Passcard(){};
};

class Room //Класс реализации помещений для доступа по картам.
{
private:
    string name;
    int size_;
    const string* passcard_type;
    
public:
    Room(string name, const string* passcard_type, const int size_) : name(name), passcard_type(passcard_type), size_(size_) {};
    
    //функция, эмулирующая пропускной терминал. Проверка доступности помещения через Passcard обитателя универа
    void enter_to_room  (const Passcard &any_Passcard) const {
        bool isCorrect = false;
        for (int i = 0; i < size_; i++)
        {
            if(any_Passcard.get_passcard_type() == passcard_type[i]) {
                isCorrect = true;
                break;
            }
            else
                isCorrect = false;
        }
        if (isCorrect)
            cout << "Доступ в помещение " << name << " разрешен\n";
        else
            cout << "Доступ в помещение " << name << " запрещен!\n";
    }
    //сеттеры и геттеры.
    void set_name(string name) { this->name = name;}
    string get_name() { return name; }
    ~Room(){ };
};

unsigned int Passcard::count_for_id = 0;

int main() {
    //Заполнение базы данных id уникальными числами.
    unsigned int size = 10000;
    unsigned int int_for_add;
    unsigned int *database = new unsigned int[size];
    bool isUnique;
    srand(time(NULL));
    
    for (int i = 0; i < size; )
    {
        int_for_add = rand()%1000000 + 10000;
        isUnique = true;
        for (int j = 0; j < size; j++)
        {
            if(int_for_add == database[j]){
                isUnique = false;
                break;
            }
        } 
        if (isUnique){
            database[i] = int_for_add;
            i++;
        }
    }
    //---------------------------------------------
    
    

    //Массив карт доступа обитателей унивеситета.
    Passcard People[] {
        Passcard (database, "Мещанников Юрий Михайлович"),
        Passcard (database, "Сорокин Павел Юрьевич", STUD),
        Passcard (database, "Сахаров Николай Федорович", SCIE),
        Passcard (database, "Карамазов Никита Александрович", PROF),
        Passcard (database, "Киреев Максим Сергеевич", TCHW)
    };
    
    //Список разрешений для помещений.
    string they_can_toilet1[] { STUD, PROF, TCHW },
        they_can_toilet2 [] { SCIE, TCHW },
        they_can_classrom1 [] { STUD, PROF },
        they_can_classrom2 [] { STUD, PROF },
        they_can_rector_s_office [] { PROF },
        they_can_buffet [] { SCIE, TCHW, STUD, PROF },
        they_can_laboratory [] { SCIE },
        they_can_techroom [] { SCIE, TCHW };
    
    //Массив помещений, "Университет".
    Room University[] {
        Room ("Туалет 1 этаж", they_can_toilet1 , sizeof( they_can_toilet1)/sizeof(string) ),
        Room ("Туалет 2 этаж", they_can_toilet2, sizeof( they_can_toilet2)/sizeof(string) ),
        Room ("Класс математики", they_can_classrom1, sizeof( they_can_classrom1)/sizeof(string) ),
        Room ("Класс русского языка", they_can_classrom2, sizeof(  they_can_classrom2)/sizeof(string) ),
        Room ("Кабинет ректора", they_can_rector_s_office, sizeof( they_can_rector_s_office)/sizeof(string) ),
        Room ("Столовая", they_can_buffet, sizeof( they_can_buffet)/sizeof(string) ),
        Room ("Лаборатория", they_can_laboratory, sizeof( they_can_laboratory)/sizeof(string) ),
        Room ("Техническое помещение", they_can_techroom, sizeof( they_can_techroom)/sizeof(string) )
    };

    unsigned int room_ammount = sizeof(University)/sizeof(Room); //количество помещений в Университете.
    unsigned int passcard_ammount = sizeof(People)/sizeof(Passcard); //количество выпущенных карт доступа.
    
    //Вызов проверки разрешений обитателей университета по Всем помещениям
    for (int i = 0; i < passcard_ammount; i++)
    {
        check_perm(People[i], University, room_ammount);
    }
    
    return 0;
}

template <class T1, class T2> void check_perm(const T1& any_Passcard, const T2* any_Room, unsigned int room_ammount) {
    cout << "\t" << any_Passcard.get_name() << " "<< any_Passcard.get_id()
        << " " << any_Passcard.get_passcard_type() << endl;
    for (int i = 0; i < room_ammount; i++)
    {
        any_Room[i].enter_to_room(any_Passcard);
    }
    cout << endl;
}