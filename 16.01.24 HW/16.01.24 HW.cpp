#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <string>

using namespace std;


//Task String
class MyString
{
    char* str;
    static int count;
    int field = 69;
public:
    MyString()
    {
        str = new char[field];
        str[0] = '\0';
        count++;
    }
    MyString(const char* text)
    {
        str = new char[strlen(text) + 1];
        strcpy_s(str, strlen(text) + 1, text);
        count++;
    }

    MyString(const MyString& other)
    {
        str = new char[strlen(other.str) + 1];
        strcpy_s(str, strlen(other.str) + 1, other.str);
        count++;
    }

    MyString& operator=(const MyString& other)
    {
        if (this != &other)
        {
            delete[] str;
            str = new char[strlen(other.str) + 1];
            strcpy_s(str, strlen(other.str) + 1, other.str);
        }
        return *this;
    }

    MyString operator++()
    {
        int overload = strlen(str);
        char* temp = new char[overload + 2];
        strcpy_s(temp, overload + 2, str);
        temp[overload] = 'x';
        temp[overload + 1] = '\0';
        delete[] str;
        str = temp;
        return *this;
    }

    MyString operator--()
    {
        int overload = strlen(str);
        if (overload > 0)
        {
            char* temp = new char[overload];
            strncpy_s(temp, overload, str, overload - 1);
            temp[overload - 1] = '\0';
            delete[] str;
            str = temp;
        }
        return *this;
    }

    MyString operator++(int)
    {
        MyString postfixInc(*this);
        int overload = strlen(str);
        char* temp = new char[overload + 2];
        strcpy_s(temp, overload + 2, str);
        temp[overload] = 'x';
        temp[overload + 1] = '\0';
        delete[] str;
        str = temp;
        return postfixInc;
    }

    MyString operator--(int)
    {
        MyString postfixDic(*this);
        int overload = strlen(str);
        if (overload > 0)
        {
            char* temp = new char[overload];
            strncpy_s(temp, overload, str, overload - 1);
            temp[overload - 1] = '\0';
            delete[] str;
            str = temp;
        }
        return postfixDic;
    }

    MyString operator+(int n) const
    {
        MyString result(*this);
        int overload = strlen(result.str);
        char* temp = new char[overload + n + 1];
        strcpy_s(temp, overload + n + 1, result.str);
        for (int i = overload; i < overload + n; ++i)
        {
            temp[i] = 'x';
        }
        temp[overload + n] = '\0';
        delete[] result.str;
        result.str = temp;
        return result;
    }

    friend MyString operator+(int n, const MyString& Str)
    {
        return Str + n;
    }

    MyString operator-(int n) const
    {
        MyString result(*this);
        int overload = strlen(result.str);
        if (n < overload)
        {
            char* temp = new char[overload - n + 1];
            strncpy_s(temp, overload - n + 1, result.str, overload - n);
            temp[overload - n] = '\0';
            delete[] result.str;
            result.str = temp;
        }
        else
        {
            delete[] result.str;
            result.str = new char[1];
            result.str[0] = '\0';
        }
        return result;
    }

    void input()
    {
        char buffer[256];
        cout << "Enter your string: ";
        cin.getline(buffer, 256);
        delete[] str;
        str = new char[strlen(buffer) + 1];
        strcpy_s(str, strlen(buffer) + 1, buffer);
    }

    void output() const
    {
        cout << "String: " << str << endl;
    }

    static int getCount()
    {
        return count;
    }
    ~MyString()
    {
        delete[] str;
        count--;
    }
};


int MyString::count = 0;




////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



//Task phonebook
class Contact
{
    char* name;
    char* lastname;
    char* middlename;
    char* phoneNumber;
public:
    Contact() : name(nullptr), lastname(nullptr), middlename(nullptr), phoneNumber(nullptr) {}

    Contact(const char* Name, const char* LastName, const char* Surname, const char* PhoneNumber)
    {
        name = new char[strlen(Name) + 1];
        strcpy_s(name, strlen(Name) + 1, Name);

        lastname = new char[(strlen(LastName) + 1)];
        strcpy_s(lastname, strlen(LastName) + 1, LastName);

        middlename = new char[(strlen(Surname) + 1)];
        strcpy_s(middlename, strlen(Surname) + 1, Surname);

        phoneNumber = new char[(strlen(PhoneNumber) + 1)];
        strcpy_s(phoneNumber, strlen(PhoneNumber) + 1, PhoneNumber);

    }
    Contact(const Contact& other)
    {
        name = new char[strlen(other.name) + 1];
        strcpy_s(name, strlen(other.name) + 1, other.name);

        lastname = new char[strlen(other.lastname) + 1];
        strcpy_s(lastname, strlen(other.lastname) + 1, other.lastname);

        middlename = new char[strlen(other.middlename) + 1];
        strcpy_s(middlename, strlen(other.middlename) + 1, other.middlename);

        phoneNumber = new char[strlen(other.phoneNumber) + 1];
        strcpy_s(phoneNumber, strlen(other.phoneNumber) + 1, other.phoneNumber);
    }
    void Set()
    {
        char bufferName[30];
        char bufferLastName[30];
        char bufferSurname[30];
        char bufferPhoneNumber[30];


        cout << "Enter the name: ";
        cin >> bufferName;


        cout << "Enter your lastname: ";
        cin >> bufferLastName;


        cout << "Enter your surname: ";
        cin >> bufferSurname;


        cout << "Enter your phonenumber: ";
        cin >> bufferPhoneNumber;


        name = new char[strlen(bufferName) + 1];
        strcpy_s(name, strlen(bufferName) + 1, bufferName);

        lastname = new char[strlen(bufferLastName) + 1];
        strcpy_s(lastname, strlen(bufferLastName) + 1, bufferLastName);

        middlename = new char[(strlen(bufferSurname) + 1)];
        strcpy_s(middlename, strlen(bufferSurname) + 1, bufferSurname);

        phoneNumber = new char[(strlen(bufferPhoneNumber) + 1)];
        strcpy_s(phoneNumber, strlen(bufferPhoneNumber) + 1, bufferPhoneNumber);

    }


    Contact& operator =(const Contact& other)
    {
        if (this != &other)
        {
            delete[] name;
            delete[] lastname;
            delete[] middlename;
            delete[] phoneNumber;

            name = new char[strlen(other.name) + 1];
            strcpy_s(name, strlen(other.name) + 1, other.name);

            lastname = new char[strlen(other.lastname) + 1];
            strcpy_s(lastname, strlen(other.lastname) + 1, other.lastname);

            middlename = new char[strlen(other.middlename) + 1];
            strcpy_s(middlename, strlen(other.middlename) + 1, other.middlename);

            phoneNumber = new char[strlen(other.phoneNumber) + 1];
            strcpy_s(phoneNumber, strlen(other.phoneNumber) + 1, other.phoneNumber);
        }
        return *this;
    }

    void Output()
    {
        if (name == nullptr || lastname == nullptr || middlename == nullptr || phoneNumber == nullptr)
        {
            cout << "Not full contact." << endl;
            return;
        }
        cout << "Name: " << name << endl;
        cout << "LastName: " << lastname << endl;
        cout << "Surname: " << middlename << endl;
        cout << "Phonenumber: " << phoneNumber << endl;
    }
    ~Contact()
    {

    }
};


Contact* addContact(Contact* contact, int& size, const Contact& newStudent)
{
    Contact* newStudents = new Contact[size + 1];
    for (int i = 0; i < size; i++)
    {
        newStudents[i] = contact[i];
    }
    newStudents[size] = newStudent;
    delete[] contact;
    size++;
    return newStudents;
}


Contact* removeStudent(Contact* сontact, int& size, int index)
{
    if (index < 0 || index >= size)
    {

        cout << "Unknown index: " << index << endl;
        return сontact;
    }
    Contact* newStudents = new Contact[size - 1];
    for (int i = 0; i < index; ++i) {
        newStudents[i] = сontact[i];
    }
    for (int i = index + 1; i < size; ++i) {
        newStudents[i - 1] = сontact[i];
    }
    delete[] сontact;
    size--;
    return newStudents;
}


void printContact(Contact* contact, int size)
{
    for (int i = 0; i < size; i++)
    {
        contact[i].Output();
    }
}


int main()
{
    //Task String
    MyString str;
    str.input();
    ++str;
    str.output();
    cout << "Count: " << str.getCount() << endl;

    --str;
    str.output();
    cout << "Count: " << str.getCount() << endl;

    str.input();
    str++;
    str.output();
    cout << "Count: " << str.getCount() << endl;

    str--;
    str.output();
    cout << "Count: " << str.getCount() << endl;

    str.input();
    str = str + 5;
    str.output();
    cout << "Count: " << str.getCount() << endl;

    str.input();
    str = str - 2;
    str.output();
    cout << "Count: " << str.getCount() << endl;

    str.input();
    MyString result = 10 + str;
    str.output();
    cout << "Count: " << str.getCount() << endl;




    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    //Task Phonebook
    int size = 1;
    Contact* сontact = new Contact[size];

    сontact[0] = { "Oleg", "Kravchuk", "Sergeevich", "+380974862369" };
    Contact newContact = { "Sasha", "Ovcharenko", "Genadich", "+380964371963" };

    сontact = addContact(сontact, size, newContact);
    printContact(сontact, size);

    сontact = removeStudent(сontact, size, 0);
    printContact(сontact, size);

    delete[] сontact;
}