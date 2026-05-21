## Шаблони(templates)

- Шаблоните са мощнa характеристикa на C++, която ни позволява да пишем общи програми. Можем да създадем една функция, която да работи с различни типове данни, като използваме шаблон.

- Компилаторът генерира т. нар. шаблонна функция, като замества параметрите на шаблона с типовете на съответните фактически параметри.

## Идея, особености и използване
Шаблоните на функции са специални функции, които могат да работят с много различни типове. Това ни позволява да създадем шаблон за функция, чиято функционалност може да бъде адаптирана
към повече от един тип или клас данни, без да се повтаря код за всеки отделен тип.

В C ++ това може да се постигне, като се използват параметри на шаблона. Това е специален вид параметър, който може да се използва за предаване на тип като аргумент:
точно както обикновените параметри на функцията могат да се използват за подаване на стойности към дадена функция, параметрите на шаблона позволяват да се подават типове на функции.

Форматът за деклариране на шаблони на функции с типови параметри е:

```c++
template <class identifier> function_declaration;
template <typename identifier> function_declaration;
```

## Шаблони на функции

# Дефиниция 
Шаблонът на функцията започва с ключовата дума template, последван от параметър(и) на шаблона вътре в <>, което е последвано от дефиницията на функцията.

```c++
template <typename T>
T functionName(T parameter1, T parameter2, ...) 
{
    //...
}
```
В горния пример - T е шаблонен аргумент, който приема различни типове данни (int, float и т.н.), а typename е ключова дума.
Когато аргумент от тип данни се предаде на functionName(), компилаторът генерира нова версия на functionName() за дадения тип данни.
(В горния пример резултатът, който функцията връща също е от указания тип - Т).

# Можем да добавяме няколко параметъра на шаблона => няколко различни типа

```c++
template <typename T, typename S>
void print_pair(T a, S b) {
	cout << a << " and type is: " << typeid(a).name() << endl;
	cout << b << " and type is: " << typeid(b).name() << endl;
}
```


```c++
#include <iostream>
using namespace std;

template <typename T1, typename T2>
void printPair(T1 a, T2 b) {
    cout << "(" << a << ", " << b << ")" << endl;
}

int main() {
    printPair(1, 3.14);        // (1, 3.14)
    printPair("hello", 42);    // (hello, 42)
    printPair('A', true);      // (A, 1)
    return 0;
}
```

## Шаблони на клас
Клас, който работи не с променливи от някакъв дефиниран тип, а с абстрактни променливи, се нарича шаблонен клас

## Пример:Релизиране на  структурата от данни Стек(Stack)

<img width="512" height="333" alt="image" src="https://github.com/user-attachments/assets/40cabfca-948b-41b8-a3dd-462ee510207b" /> 

Пример:

```c++
int main()
{
  Stack st;

  for(size_t i = 0; i < 1000; i++)
       st.push(i);
  Stack st1 = st;
  Stack st2;
  st2 = st1;

  while (!st2.empty())
        std::cout << st2.pop() << ' ';
  std::cout << std::endl;
  return 0;
}
```

## Шаблони при наследяване

Това е комбинация между: наследяване (inheritance) и шаблонни класове (template classes).

Използва се, когато искаме:

- базовият клас да работи с различни типове данни;
- наследниците да разширяват поведението;
- да имаме полиморфизъм чрез виртуални функции.

Пример:

Student.hpp
```c++
#pragma once
#include <iostream>
#include <cstring>

template<typename T>
class Student
{
protected:
    char* name;
    T fn;

    void copyFrom(const Student<T>& other)
    {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);

        fn = other.fn;
    }

    void free()
    {
        delete[] name;
    }

public:
    Student(const char* name = "", T fn = T())
    {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);

        this->fn = fn;
    }

    Student(const Student<T>& other)
    {
        copyFrom(other);
    }

    Student<T>& operator=(const Student<T>& other)
    {
        if (this != &other)
        {
            free();
            copyFrom(other);
        }

        return *this;
    }

    virtual ~Student()
    {
        free();
    }

    virtual void print() const = 0;

    virtual Student<T>* clone() const = 0;
};

```

Bachelor.hpp
```c++
#pragma once
#include "Student.hpp"

template<typename T>
class Bachelor : public Student<T>
{
private:
    char* speciality;

    void copyFrom(const char* speciality)
    {
        this->speciality = new char[strlen(speciality) + 1];
        strcpy(this->speciality, speciality);
    }

    void free()
    {
        delete[] speciality;
    }

public:
    Bachelor(const char* name, T fn, const char* speciality)
        : Student<T>(name, fn)
    {
        copyFrom(speciality);
    }

    Bachelor(const Bachelor<T>& other)
        : Student<T>(other)
    {
        copyFrom(other.speciality);
    }

    Bachelor<T>& operator=(const Bachelor<T>& other)
    {
        if (this != &other)
        {
            Student<T>::operator=(other);

            free();
            copyFrom(other.speciality);
        }

        return *this;
    }

    ~Bachelor() 
    {
        free();
    }

    void print() const override
    {
        std::cout << "Bachelor -> ";

        std::cout << "Name: "
                  << this->name
                  << " FN: "
                  << this->fn
                  << " Speciality: "
                  << speciality
                  << std::endl;
    }

    Student<T>* clone() const override
    {
        return new Bachelor<T>(*this);
    }
};
```
Master.hpp
```c++
#pragma once
#include "Student.hpp"

template<typename T>
class Master : public Student<T>
{
private:
    char* thesis;

    void copyFrom(const char* thesis)
    {
        this->thesis = new char[strlen(thesis) + 1];
        strcpy(this->thesis, thesis);
    }

    void free()
    {
        delete[] thesis;
    }

public:
    Master(const char* name, T fn, const char* thesis)
        : Student<T>(name, fn)
    {
        copyFrom(thesis);
    }

    Master(const Master<T>& other)
        : Student<T>(other)
    {
        copyFrom(other.thesis);
    }

    Master<T>& operator=(const Master<T>& other)
    {
        if (this != &other)
        {
            Student<T>::operator=(other);

            free();
            copyFrom(other.thesis);
        }

        return *this;
    }

    ~Master() 
    {
        freeThesis();
    }

    void print() const override
    {
        std::cout << "Master -> ";

        std::cout << "Name: "
                  << this->name
                  << " FN: "
                  << this->fn
                  << " Thesis: "
                  << thesis
                  << std::endl;
    }

    Student<T>* clone() const override
    {
        return new Master<T>(*this);
    }
};
```
University.hpp
```c++
#pragma once
#include "Bachelor.hpp"
#include "Master.hpp"

template<typename T>
class University
{
private:
    Student<T>** students;

    size_t size;
    size_t capacity;

    void copyFrom(const University<T>& other)
    {
        size = other.size;
        capacity = other.capacity;

        students = new Student<T>*[capacity];

        for (size_t i = 0; i < size; i++)
        {
            students[i] = other.students[i]->clone();
        }
    }

    void free()
    {
        for (size_t i = 0; i < size; i++)
        {
            delete students[i];
        }

        delete[] students;
    }

    void resize()
    {
        capacity *= 2;

        Student<T>** newStudents =  new Student<T>*[capacity];

        for (size_t i = 0; i < size; i++)
        {
            newStudents[i] = students[i];
        }

        delete[] students;

        students = newStudents;
    }

public:
    University()
    {
        size = 0;
        capacity = 4;

        students = new Student<T>*[capacity];
    }

    University(const University<T>& other)
    {
        copyFrom(other);
    }

    University<T>& operator=(const University<T>& other)
    {
        if (this != &other)
        {
            free();
            copyFrom(other);
        }

        return *this;
    }

    ~University()
    {
        free();
    }

    void addStudent(const Student<T>& student)
    {
        if (size >= capacity)
        {
            resize();
        }

        students[size++] = student.clone();
    }

    void print() const
    {
        for (size_t i = 0; i < size; i++)
        {
            students[i]->print();
        }
    }
};
```

main.cpp
```c++
#include "University.hpp"

int main()
{
    Bachelor<int> b1( "Ivan",  1001, "Computer Science");

    Bachelor<int> b2( "Maria", 1002, "Software Engineering" );

    Master<int> m1( "Georgi", 2001, "Artificial Intelligence");

    University<int> uni;

    uni.addStudent(b1);
    uni.addStudent(b2);
    uni.addStudent(m1);

    uni.print();

    return 0;
}
```

## Нетипови шаблонни параметри 

Това са шаблонни параметри, които НЕ са типове, а стойности.

template<int N> - Тук N е число.

Пример

Array.hpp
```c++
pragma once

#include <iostream>

template<typename T, size_t N>

class Array

{

private:

    T data[N];

public:

    void fill(const T& value)

    {

        for (size_t i = 0; i < N; i++)

        {

            data[i] = value;

        }

    }

    void print() const

    {

        for (size_t i = 0; i < N; i++)

        {

            std::cout << data[i] << ' ';

        }

        std::cout << std::endl;

    }

};

#include "Array.hpp"

int main()
{
    Array<int, 5> arr;

    arr.fill(7);

    arr.print();

    return 0;
}
```

Нетиповите шаблонни параметри са параметри на шаблон, които представляват стойности, а не типове. 
Най-често са числа, указатели или constexpr стойности. Използват се, когато искаме дадена информация 
да е известна още по време на компилация.

## Задачи

## Задача 1
Реализирайте структурата от данни Vector. Структурата трябва да осигурява достъп до произволен елемент, както и добавяне и премахване на елемент на произволна позиция.

Реализирайте следните член-функции:

- pushBack(..)
- pushAt(..)
- popBack(..)
- popAt(..) 
- operator[]
- empty(..)
- clear(..)
- swap(..)

## Задача 2
Релизирайте структурата от данни опашка(Queue). 

Опашката трябва да работи с произволни типове.
След като е добавен един елемент в края на опашката, той ще може да бъде извлечен (премахнат) единствено след като бъдат
премахнати всички елементи преди него в реда, в който са добавени.

```c++
int main()
{
	quene<int> q;
	q.enqueue(3);
	q.enqueue(5);
	q.enqueue(10);

	cout << q.dequeue() << endl; //3
	cout << q.dequeue() << endl; //5
	cout << q.dequeue() << endl; //10

	cout << q.isEmpty() << endl; //1	
}
```

## Задача 3
Да се реализира клас Sorted<T, capacity>, който реализира "винаги сортиран" масив от елементи T.

В Sorted може да има максимум capacity елемента от тип T.

Класът да има методи add(T& elem), remove (T& elem) и print(), които съответно добавят елемент, махат елемент и отпечатват елементите разделени с нов ред.

## Задача 4

Да се дефинира шаблон на клас Relation<Т>, който съдържа два обекта от тип T, наречени subject и object, и низ с произволна дължина relation,
описващ връзката между тези обекти. 


Пример:
```c++
Relation<int> r1(2,6,“is smaller than”),r2(6,3,“is divisible by”); 
```

За шаблона да се реализират голямата четворка и операция за отпечатване void print().

Пример: 
```c++
r1.print(): 2 is smaller than 6. 
```

За инстанцията на шаблона Relation<int> реализирайте и оператор за композиция * по следния начин.

```c++
Ако r = r1 * r2, то r.subject = r1.subject, r.object = r2.object

Тоест r1.object == r2.subject
```

Пример: 

```c++
(r1*r2).print(): 

2 is smaller than 6, which is divisible by 3 
Композицията се допуска само ако r1.object == r2.subject, в противен случай резултатът e r1.
```

Пример за невалидна композиция:
```c++
Relation<int> r1(2, 6, "is smaller than");
Relation<int> r2(7, 3, "is divisible by");

6 != 7 и връща r1.
```
