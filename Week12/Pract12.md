## Статично и динамично свързване

Пример за статично свързване:


```c++
#include <iostream>
using namespace std;

struct A
{ 
    void f() const 
    {
	std::cout << "A::f()" << std::endl;
    }	
};

struct B : public A
{
    void f() const 
    {
	std::cout << "B::f()" << std::endl;
    }	
};

int main()
{
	B* bPtr = new B();

	A* aPtr = bPtr;
	
	bPtr->f(); // B::f()
	aPtr->f(); // A::f()
	
	delete bPtr;
}
```

Но какво ще отпечата тук?

```c++
void func(const A& obj) 
{
     obj.f();
}	
int main()
{
	B* bPtr = new B();

	A* aPtr = bPtr;
	
	func(*aPtr); // A::f()
	func(*bPtr); // A::f()
}
```

- Статично свързване - изборът на функцията, която трябва да се изпълни става по време на компилация.
- Динамично свързване – изборът на функцията, която трябва да се изпълни става по време на изпълнение на програмата.


```c++
#include <iostream>
using namespace std;

struct A
{
    virtual void f() const 
    {
	std::cout << "A::f()" << std::endl;
    }	
};

struct B : public A
{
    void f() const 
    {
       std::cout << "B::f()" << std::endl;
    }	
};

struct C : public A
{
    void f() const 
    {
       std::cout << "C::f()" << std::endl;
    }	
};

int main()
{
	A* ptrs[3];
	A obj1;
	B obj2;
	C obj3;
	
	ptrs[0] = &obj1;
	ptrs[1] = &obj2;
	ptrs[2] = &obj3;
	
	ptrs[0]->f(); // A::f()
	ptrs[1]->f(); // B::f()
	ptrs[2]->f(); // C::f()
}
```

## Виртуални таблици

Виртуални таблици - таблица с указатели към функции.

- Член-функция, която е декларирана в основен клас(Base class) и е предефинирана от производен клас(Derived class).
- Гарантират, че правилната функция ще се извика за даден обект, независимо от типа reference/pointer(типа препратка),
използван за извикване на функцията. Те се използват главно за постигане на Runtime polymorphism.

## Правила за виртуални функции

- не могат да бъдат static.
- Прототипът на виртуалните функции трябва да бъде един и същ както в базовия, така и в производния клас.
- Винаги се дефинират в базовия клас, като се предефинират в производния. Не е задължително производния клас да заменя или предефинира виртуалната функция, в такъв случай се използва версията на базовия клас.
- Достъпът до виртуалните функции трябва да се осъществява използвайки reference/pointer към базовия клас, за да се осъществи Runtime polymorphism.
- Класът може да има виртуален деструктор, но не може да има виртуален конструктор.

```c++
struct A
{
	virtual int f()
	{
		return 1;
	}
	virtual int g()
	{
		return 1;
	}
};

struct B : public A
{
	int f() override
	{
		return 2;
	}
};

struct C : public B
{
	int f() override
	{
		return 3;
	} 
	int g() override
	{
		return 3;
	}
};
```

<img width="466" height="401" alt="image" src="https://github.com/user-attachments/assets/19984ecd-3533-4055-9bf7-d048c08127ea" />



## Полиморфизъм

Едни и същи действия се реализират по различен начин в зависимост от обектите, върху които се прилагат.

- Действията се наричат полиморфни.
- Реализира се чрез виртуални функции.
- Класовете, върху които ще се прилага, трябва да имат общ родител или прародител, т.е. да са наследници на един и същ клас.
- В класа се дефинира виртуален метод, съответстващ на полиморфното действие.
- Всеки клас предефинира или не виртуалния метод.
- Активирането става чрез указател към базов клас, на който може да се присвоят адресите на обекти на който и да е от базовите класове от йерархията

## Compile time polymorphism vs Runtime polymorphism

- Compile time - дадена функция се извиква по време на компилация на програмата(function overload/operator overload).
- Runtime - функциите се извикват в момента на изпълнение на програмата (Dynamic binding/Late binding).


## Важно!
При полиморфна йерархия ще изтриваме обектите чрез указатели от базовия клас. За да се извикват правилните деструкори задължително деструкторът на базовият клас трябва е деклариран като виртуален!

```c++
#include<iostream>

struct Animal
{
	virtual void sayHello() const
	{
		std::cout << "Hello, I am a random animal" << std::endl;
	}

	virtual ~Animal(){} //!!!
};
struct Dog : public Animal
{
	void sayHello() const override
	{
		std::cout << "Hello, I am a dog!" << std::endl;
	}
};

struct Cat : public Animal
{
	void sayHello() const override
	{
		std::cout << "Hello, I am a cat!" << std::endl;
	}
};

struct Mouse : public Animal
{
};

int main()
{
	Animal** animals = new Animal*[3];

	animals[0] = new Dog();
	animals[1] = new Cat();
	animals[2] = new Mouse();


	//from base-class pointer
	animals[0]->sayHello(); // Hello, I am a dog!
	animals[1]->sayHello(); // Hello, I am a cat!
	animals[2]->sayHello(); // Hello, I am a random animal!

	delete animals[0], animals[1], animals[2];
	delete[] animals;
}
```

## Абстрактен клас

- Чисто виртуална функция (pure virtual function) - виртуална функция без тяло.
- Клас е абстрактен, ако в него има поне една чисто виртуална функция.

Тогава класът е предназначен единствено за наследяване и няма да може да създаваме обекти от него. 
Така във всеки наследник ще трябва да се разпише имплементация на функцията.
Ако някой наследник няма собствена имплементация, то и той става абстрактен клас.


```c++
#include<iostream>

struct Animal
{
	virtual void sayHello() const = 0;


	virtual ~Animal(){} //!!!
};
struct Dog : public Animal
{
	void sayHello() const override
	{
		std::cout << "Hello, I am a dog!" << std::endl;
	}
};

struct Cat : public Animal
{
	void sayHello() const override
	{
		std::cout << "Hello, I am a cat!" << std::endl;
	}
};

struct Mouse : public Animal
{
	void sayHello() const override
	{
		std::cout << "Hello, I am a mouse!" << std::endl;
	}
};

struct PrehistoricAnimal : public Animal
{};

int main()
{
	// Animal* pa1 = new Animal(); No! Animal is an abstract class!
	// Animal* pa2 = new PrehistoricAnimal(); No! PrehistoricAnimal is also an abstract class!

	Animal** animals = new Animal*[3];

	animals[0] = new Dog();
	animals[1] = new Cat();
	animals[2] = new Mouse();


	//from base-class pointer
	animals[0]->sayHello(); // Hello, I am a dog!
	animals[1]->sayHello(); // Hello, I am a cat!
	animals[2]->sayHello(); // Hello, I am a mouse!

	delete animals[0]
	delete animals[1]
	delete animals[2];
	delete[] animals;
}

```

## override и final

- override указва, че дадена функция презаписва функция от базовия клас. Ако в базовия клас няма такава функция, то кодът няма да се компилира.
- final указва, че дадена функция не може да се презависва надолу по йерархията или че даден клас не може да се наследява.

## Колекция - Хетерогенен контейнер

Можем да реализираме колекция от различни типове (но с общ базов клас), чрез масив от указатели. Указателите трябва да са от типа на базовия клас.

```c++
struct Fruit
{
	virtual void printColor() const = 0;
	
	virtual ~Fruit(){}
};

struct Apple : public Fruit
{
	void printColor() const override
	{
		std::cout << "Red or green! "<<std::endl;
	}
};

struct Orange : public Fruit
{
	void printColor() const override
	{
		std::cout << "Orange! "<<std::endl;
	}
	
};

struct Lemon : public Fruit
{
	Lemon(size_t sourness) : sourness(sourness){}
	
	size_t sourness;
	
	void printColor() const override
	{
		std::cout << "Yellow! "<<std::endl;
	}
};

class FruitStore
{
private:
	Fruit** fruits;
	size_t capacity;
	size_t count;
public:
        FruitStore();
        FruitStore(const FruitStore&);
        FruitStore& operator=(const FruitStore&);
        ~FruitStore();
	
        void addApple();
        void addOrange();
        void addLemon(size_t sourness);
private:          
        void copyFrom(const FruitStore& other);
        void free();
};

void FruitStore::addApple()
{
	fruits[count++] = new Apple();
}

void FruitStore::addOrange()
{
	fruits[count++] = new Orange();
}

void FruitStore::addLemon(size_t sourness)
{
	fruits[count++] = new Lemon(sourness);
}

//или
/*
class FruitStore
{
private:
	Fruit** fruits;
	size_t capacity;
	size_t count;
          
    void copyFrom(const FruitStore& other);
    void free();
    
public:
	FruitStore();
	FruitStore(const FruitStore&);
	FruitStore& operator=(const FruitStore&);
       ~FruitStore();
	
	void addFruit(Fruit* fr);
};

void FruitStore::addFruit(Fruit* fr)
{
	fruits[count++] = fr;
}
int main()
{
	FruitStore store;
	store.addFruit(new Lemmon(3));
	store.addFruit(new Apple());
}
*/
```

## Триене

Понеже имаме виртуален деструктор в базовия клас, не се интересуваме в колекцията какви са обектите, които трием.

```c++
void FruitStore::free()
{
	for(int i = 0; i < count; i++)
		delete fruits[i];
	
	delete[] fruits;
}
```
## Копиране

Искаме да реализираме копиране на колекцията. Това трябва да стане без да нарушаваме абстракцията - искаме обеките да се копират без да се налага да запитваме за техния тип.
За това дефинираме виртуална функция clone, която ще връща копие на обекта. Тази функция я разписваме във всеки от наследниците.

```c++
struct Fruit
{
    virtual void printColor() const = 0;
    virtual ~Fruit(){}

    virtual Fruit* clone() const = 0; //!
};

struct Apple : public Fruit
{
    void printColor() const override
    {
	std::cout << "Red or green! "<<std::endl;
    }
    Fruit* clone() const override
    {
        return new Apple(*this);
    }
};

struct Orange : public Fruit
{
     void printColor() const override
     {
	std::cout << "Orange! "<<std::endl;
     }
	
     Fruit* clone() const override
     {
	return new Orange(*this);
     }
};

struct Lemon : public Fruit
{
    Lemon(size_t sourness) : sourness(sourness){}
	
    size_t sourness;
    void printColor() const override
    {
	std::cout << "Yellow! "<<std::endl;
    }
	
    Fruit* clone() const override
    {
	return new Lemon(*this);

    //или
    //Fruit* copy = new Lemon(*this);
	//return copy;
    }
};
```
От тук копирането става тривиално:

```c++
void FruitStore::copyFrom(const FruitStore& other)
{
	fruits = new Fruit*[other. capacity];

	for(int i = 0; i < other.count; i++)
		fruits[i] = other.fruits[i]->clone();

	count = other.count;
	capacity = other.capacity;
}
```

## Задачи

## Задача 1

Да се дефинира абстрактен клас Device, който поддържа следните данни:

- Модел – символен низ
- Марка – символен низ
- Цена – цяло число
- Да се дефинират методи за принтиране на информацията на едно устройство, писане и четене във файл.

Нека класът Phone наследи Device като го надгражда със следните характеристики:

- Брой камери
- цяло число
- SecurityLockType – избор между лицево разпознаване и пръстов отпечатък

Нека класът Laptop също наследи Device като за него има следната информация:

- Операционна система – MacOS, Linux, Windows
- Дали е с USB портове или с Thunderbolt
- Брой портове-цяло число

Нека Phone и Laptop имат свои имплементации на методите за принтиране на информацията, писането и четенето от файл.

Да се реализира клас TechnoShop, който представлява магазин за техника. 

Нека той има име и съдържа списък от устройства. 

Да се напишат методи за добавяне и премахване на устройство, премахването да става по подадени модел и марка, записване на информацията на всички устройства във файл и четене на информация за магазин и неговите артикули от файл.

Помислете какво още ще ви е нужно, за да реализирате класа TechnoShop.

## Задача 2

За задачата можете да използвате класа string реализиран на практикума. 
Windows forms е UI framework за лесно създаване на приложения за windows. Той представя лесен начин за създаване на приложения графично и се поддържа от езикци като C#. 

Приложенията представляват множество от форми в които има контроли.

Да се създаде клас, който представя форма.

- Формата има размер (широчина и дължина), както и име.
- Всяка форма поддържа колекция от контроли.
- Всеки контрол има размер и локация във формата. 
- Също така, всеки контрол има функция setDataDialog(); която позволява на потребителя да промени контрола по подходящ начин.
- Всеки контрол може да променя размерите си.

Имаме следните контроли:

- Label - Това е просто етикетче. То има текст в него. setDataDialog() променя текста му.

- CheckBox - Контрол, който има текст и състояние (включен или изключен). setDataDialog() променя дали е включен или изключен по подразбиране. За промяна на текста може да добавите допълнителна функция. 

- Radio Button - Контрол, който има няколко опции, но само една е избрана. setDataDialog() променя избраната опция.

Може да добавите допълнителна логика за промяната на опциите. Броят им, веднъж зададен, не се променя.

Реализирайте хетерогенен контейнер, който съдържа различните контроли, които вашата форма притежава. 

Трябва да имате метод за добавяне на контрола към контейнера. Също така трябва да имате метод за променяне на размера на формата както и на всеки от контролите (може да достъпвате контролите по индекс). 

- Напишете функция за промяна на локацията на контролите, като те не трябва да излизат извън формата.
- Реализирайте метод change(size_t index); който променя контрола на подадения индекс. 
- Промяната става чрез извикване на setDataDialog функцията на съответния контрол.

## Задача 3

Да се реализира йерархия от компютри. Да се реализира:

Абстрактен клас Computer. В себе си той съдържа:

- Мощност на процесора (число тип double).
- Модел на видео картата (масив от символи).
- Мощност на захранването (цяло число).
- Количество RAM памет (цяло число).
- Методи за промяна но компонентите на компютъра Функция, която изписва на стандартния изход какъв тип е компютъра (PC, лаптоп или геймърска конзола).
- Функция, която връща с какви периферни устройства разполага компютъра. Нека перферните устройства са масиви от символи.

Класове PC, Laptop и GamingConsole.

PC: разполага с мишка, клавиатура, микрофон и слушалки.

Laptop: разполага с mouse pad, клавиатура и монитор.

GamingConsole: разполага с джойстик и монитор.
