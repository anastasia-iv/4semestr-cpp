9.16. Описать функцию, которая удаляет каждый второй элемент заданного контейнера-вектора vector <char>, 
а затем распечатывает его элементы в обратном порядке.

#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;

void f(std :: vector <char> &v)
{
    std : vector <char> :: iterator p = v.begin();
    while ( p != v.end()) {
        p++;
        if (p != v.end()) {
            p = erase(p); //- возвращает итератор на следующий элемент за удаленным
        }
    }
}

Задача 9.17.
Написать функцию, которая удваивает( добавляет еще один такой же ) 
каждый элемент заданного контейнера-списка list<int>.

void g(list <int> &s) {
    list <int> :: iterator p = s.begin();
    while (p != s.end()) {
        p.insert(p, *p);
        p++;
        p++;
    }
}

//вставляет элемент перед p

std :: map <int, int> mp { {12, 1}, {35, 2}, {0, 0}, {1, 33}};
    for (auto p = mp.begin(); p != mp.end(); ++p) 
    {
        std :: cout << p -> first (ключ) << p -> second << std :: endl;
    }
ВЫВОД: 
    {0, 0}, {1, 35}, {12, 1}, {35, 2}

    for (auto x : mp) { //перебираются значения
        cout << x.first << ' ' << x.second;
    }
ВЫВОД: 
    {0, 0}, {1, 35}, {12, 1}, {35, 2}

    mp[1] = 35; - если существует уже ключ, то изменяется значение

    mp.insert(make_pair (2, 35));
    mp.insert(pair <int, int> (2, 35));
    mp.emplace(2, 35)  

    p = mp.find(2 (ключ)) - возвращает итератор на значение, если есть 
                            иначе mp.end

//Лямбда – функции.
Лямбда –функциями называют безымянные локальные функции, 
которые можно создавать внутри какого либо выражения. 

[привязка переменных](параметры функции)-> возвр.тип {тело}

int x=5;
auto lf=[x]() { cout<<x; };  - захватили переменную (означает, что захваченные переменные будут доступны внутри)
//auto lf=[](int a) { cout<<a; }; lf(x);
lf();  // печать 5
x = 94;
lf();  // печать 94

[] – никакие переменные не привязаны
[=] – привязаны все переменные по значению
[&] - привязаны все переменные по ссылке

std :: vector <int> v= { 2, 4, 5, 6, 7, 9, 11, 14 };
auto end = std :: remove_if(v.begin(), v.end(), [](int x){ return x%2==0; }); 
- перемещается все четные в конец контейнера, оставляет нечетные 
- возвращает итератор end на первое четное значение
- {5, 7, 9, 11, 2, 4, 6, 14}

std::for_each(v.begin(), end, [](int x) { std::cout<<x<<” “; });

Если нужно использовать указатель на функцию 
Если лямбда ничего не захватывает, то можно использовать обычные указатели на функции.
Как только лямбда что-либо захватывает, указатель не работает, но 
можно использовать std::function.

#include <functional>
int f1() { return 1; }
int main() {
    std :: function < int() >fptr;
    fptr=f1;
    std::cout<<fptr();
}

 Задание mz03-3.
 complex eval( const std :: vector <std :: string> &args, const complex &z ) 
{   complex_stack st;
    std :: map <string, std :: function<void()>> mp
    { 
         { “z”, [&st, &z]() { st = st << z; } },  // добавляет в стек значение z
         { “;”, [&st]() { st = ~st; } },            // удаляет элемент с верхушки стека
                      . . .
     };
    for (const auto &s : args ) {
       if (s[0]!=’(‘ ) mp[s] ();
       else . . .
  }
return +st;
}

Задача.(ЭКЗАМЕН)
Написать шаблонную функцию для поиска максимального значения в непустых
контейнерах list и vector, содержащих любой числовой тип.

*Шаблонная функция предписывает компилятору генерировать столько разных
версий этой функции сколько было вызовов с различными типами фактических параметров. 

template < class C >
typename C :: value_type Max(const C&c) {
     typename C :: const_iterator p = c.cbegin();  // auto p=c.begin(); - typename - берем value_type из заголовка шаблона
     typename C :: value_type m = *p;            
     while (p != c.end()) {   // нельзя while ( p<c.end() )
             if(*p > m) m = *p;
             ++p;     //  нельзя p += 1;
     }
     return m;
}     
int main() {
     list <int> st = {10, 3, 6, 28, 2, 9};
     cout << Max <list <int> >(st) << endl; // 28
     vector <long> v;
     for( int i=0; i<10; ++i ) v.push_back(i);
     cout << Max(v) << endl;  // 9
     return 0;
}

Задача.
Написать шаблонную функцию, возвращающую сумму пяти последних элементов заданного контейнера
(списка или вектора, константного или не константного). 
Если в списке меньше 5-ти элементов, функция должна возвращать ноль соответствующего типа.

template < class T >
typename T :: value_type  sum(const T&t) {
    typename T :: value_type zero = typename T :: value_type() ;
    auto p = t.end();  
    if (t.size() < 5) return zero;
    for(typename T :: size_type i = 0; i < 5; i++) {
        --p;
        zero += *p;
    }
    return zero;
}