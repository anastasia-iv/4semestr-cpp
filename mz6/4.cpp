#include <iostream>
#include <vector>
#include <string>
#include <list>
#include<algorithm>
#include<iterator>

/*Написать шаблонную функцию myremove, принимающую две пары итераторов: 
диапазон элементов, содержащих номера удаляемых элементов, диапазон элементов,
 содержащих элементы, подлежащие удалению. Элементы, подлежащие удалению, в диапазоне нумеруются с нуля. 
 Номера элементов отражают позиции элементов на момент начала работы программы. 
 Если номер повторяется более одного раза, все вхождени
я, кроме первого, игнорируются. Если номер элемента недопустим, он игнорируется.*/
template <typename C, typename P> 
P myremove (C a, C b, P c, P d) {
    std :: vector <int> v(a, b);
    std :: sort(v.begin(), v.end());
    auto end = std :: unique(v.begin(), v.end());
    auto begin = v.begin();
    auto i = c;
    int j = 0;
    auto ans = c;
    while (begin != end && *begin < 0) {
        begin++;
    }
    for (;i != d; i++) {
        if (begin != end && *begin == j) {
            begin++;
            //удаляется
        } else {
            std :: iter_swap(ans, i);
            ++ans;
        }
        j++;
    }
    return ans;
}

//ЛУЧШЕ ИСПОЛЬЗОВАТЬ TYPENAME