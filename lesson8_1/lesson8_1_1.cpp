#include <iostream>

using namespace std;
class Person {
private:
    string name;
    int age;
    int weight;
    string gender;
public:
    Person(string name, int age, int weight, string gender)
        : name(name),
        age(age),
        weight(weight)
    { set_gender(gender); }

    Person(string name, int weight, string gender)
        : name(name),
        age(1),
        weight(weight)
    { set_gender(gender);}

    Person(string name)
        : name(name),
        age(1),
        weight(3),
        gender("none")
    {}

    string get_name() const { return name; }
    int get_age() const { return age; }
    int get_weight() const { return weight; }
    string get_gender() const { return gender; }

    void set_name(string name) { this->name = name; }
    virtual void set_age(int age) {
        if(age>0)
            this->age = age;
        else
            this->age = 0;
    }
    
    void set_weight(int weight) {
        if(weight>1)
            this->weight = weight;
        else
            this->weight = 1;
    }
    
    void set_gender(string gender)
    {   
        if (gender == "male" || gender == "female")
            this->gender = gender;
        else
            this->gender = "none";
    }

    virtual void SayInfo()  {
        if (this->age < 4)
            cout << name << " says \"Agoo\" because he is still a baby.\n\n";
        else {
            cout << "My name is " << name << ". I`a " << age << " years.\n"
            << "My weight is " << weight << ". My gender is " << gender << ".\n\n";
        }
    }
    virtual void Greetings() { cout << "Hello, i`m " << name << endl; }

    ~Person() { cout << "Goodbye " << name << endl; }
};



class Student: public Person {
private:
    string faculty;
    string group;
    static int count_for_ID;
    int stud_ID_num;
    void set_stud_ID_num() { this->stud_ID_num = count_for_ID; }
public:
    Student(string name, int age, int weight, string gender, string faculty, string group)
        :Person(name,weight,gender),
        faculty(faculty),
        group(group)
    {
        set_age(age);
        set_stud_ID_num();
        count_for_ID++;
    }

    void set_age(int age) override {
        if(age>14)
            this->Person::set_age(age);
        else
            this->Person::set_age(14);
    }

    string get_faculty() const { return faculty; }
    string get_group() const { return group; }
    int get_stud_ID_num() const { return stud_ID_num; }

    void set_faculty(string faculty) { this->faculty = faculty; }
    void set_group(string group) { this->group = group; }

    

    void SayInfo() override {
        cout << "My name is " << this->get_name() << ". I`m a student. I`m " << this->get_age() << " years.\n"
            << "My weight is " << this->get_weight() << ". My gender is " << this->get_gender()
            << ". " << "I study at the Faculty of " << faculty << " in group " << group << ".\n\n";
    }
    
    ~Student()
    {}
};



int Student::count_for_ID = 0;

void PrintProfiler(const Student &); //Демонстрация корректной работы геттеров;
void PrintProfiler(const Person &);

int main() {
    //Инициализация обьектов
    Person Person1("John", 22,64,"male");
    Person Person2("Alex");
    Student Student1("James",22,65,"male","Astronomy","2-astr-15");
    Student Student2("Maya",20,49,"female","Mathematics","1-math-17");
    Student Student3("Jung-Jo",15,45,"male","Philosophy","1-phi-25");
    Student Student4("Genrih",0,45,"m","Philosophy","1-phi-24"); //, age = 14, gender = "none" - переопределение геттеров
    
    //Проверка корректной работы методов
    Person1.SayInfo();
    Person2.SayInfo();
    //Проверка работы переопределения виртуального метода
    Student1.SayInfo();

    Person2.set_gender("male");
    Person2.set_age(5);
    Person2.SayInfo();

    //Проверка корректной работы геттеров
    PrintProfiler(Student1);
    PrintProfiler(Student2);
    PrintProfiler(Student3);
    PrintProfiler(Student4);
    PrintProfiler(Person1);
    PrintProfiler(Person2);

    cout << endl;
    return 0;
}

void PrintProfiler(const Student &any_Student) {
    cout << any_Student.get_name() << "\n\t"
        << "Student\n\t"
        << any_Student.get_age() << " y.o.\n\t"
        << any_Student.get_weight() << " kg.\n\t"
        << any_Student.get_gender() << "\n\tFaculty of "
        << any_Student.get_faculty() << "\n\tgroup: "
        << any_Student.get_group() << "\n\tstudent ID number: "
        << any_Student.get_stud_ID_num()<< endl;
}
void PrintProfiler(const Person &any_Person){
    cout << any_Person.get_name() << "\n\t"
        << any_Person.get_age() << " y.o.\n\t"
        << any_Person.get_weight() << " kg.\n\t"
        << any_Person.get_gender() << endl;
}
