
#include <iterator>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <map>

using namespace std;

/*Task 1
Создать шаблонную функцию, которая принимает итераторы на начало и конец последовательности слов, 
и выводящую в консоль список уникальных слов (если слово повторяется больше 1 раза, то вывести его надо один раз).
Продемонстрировать работу функции, передав итераторы различных типов.*/

template<typename iter>
void PrintS(const iter& begin, const iter& end) 
{
    unordered_set<typename iterator_traits<iter>::value_type> sorted_words{ begin, end };
    auto print = [&](auto const& item) 
    {
    cout << item << " ";
    };
    for_each(sorted_words.begin(), sorted_words.end(), print);
}

void DemonstrationIterators() {

    cout << "Итератор vector: ";
    vector<string> vocabulary;
    sort(vocabulary.begin(), vocabulary.end());
    vocabulary.push_back("Ехал");
    vocabulary.push_back("Ехал");
    vocabulary.push_back("грека");
    vocabulary.push_back("через");
    vocabulary.push_back("реку");
    vocabulary.push_back("реку");
    PrintS(vocabulary.begin(), vocabulary.end());

    cout << "\nИтератор list: ";
    list<string> vocabulary2{ {"Из","окна","окна","гостинечного","номера","своего","своего",",","я","телевизор","телевизор","выкинул","на","на","авто",} };
    PrintS(vocabulary2.begin(), vocabulary2.end());
};

/*Task 2
Используя ассоциативный контейнер, напишите программу,
которая будет считывать данные введенные пользователем из стандартного потока ввода и разбивать их на предложения.
Далее программа должна вывести пользователю все предложения, отсортировав их по длине.*/

multimap<int, string> StringToMap2()
{
    string one;
    string two;
    multimap<int, string> twos;
    while (cin >> one) {
        if (one.back() != '.' || one.back() != '!' || one.back() != '?')
        {
            two.append(one);
            two.push_back(' ');
        }
        if (*(two.end() - 2) == '.' || *(two.end() - 2) == '!' ||
            *(two.end() - 2) == '?')
        {
            two.pop_back();
            int words = count(two.begin(), two.end(), ' ') + 1;
            twos.insert({ words, two });
            two.clear();
        }
    }
    return twos;
}


void HWTwo()
{
    string str;
    multimap<int, string> two;
    cout << "Введите пожалуйста текст: ";
    two = StringToMap2();
    for_each(two.begin(), two.end(), [](pair<int, string> item)
        {
            cout << item.first << " " << item.second << endl;
        });
}

        int main()
        {

            setlocale(LC_ALL, "rus");
            {
                //Task 1
                cout << "Задание 1\n\n";
                DemonstrationIterators();
            }

            {
                //Task 2
                cout << "\n\nЗадание 2" << endl;
                HWTwo();

            }

        };
        

