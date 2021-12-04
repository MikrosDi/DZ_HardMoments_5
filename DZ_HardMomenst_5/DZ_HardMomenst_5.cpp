
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
#include <set>
#include <Windows.h> 
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

string trim(string src)
{
    src.erase(find_if_not(src.rbegin(), src.rend(), ::isspace).base(), src.end());
    src.erase(src.begin(), find_if_not(src.begin(), src.end(), ::isspace));
    return src;
}

auto cmp = [](const string& a, const string& b) { return a.length() > b.length(); };

set<string, decltype(cmp)> SplitString(string& str, char delimiter = '.') {
    set<string, decltype(cmp)> result;
    auto start = 0U;
    auto end = str.find(delimiter);
    while (end != string::npos) {
        result.insert(trim(str.substr(start, end - start)));
        start = end + 1;
        end = str.find(delimiter, start);
    }
    if (start != end) {
        result.insert(trim(str.substr(start, end - start)));
    }
    return result;

}
void Task2()
{
    string text;
    cout << "Введите пожалуйста строку: ";
    getline(cin, text);
    cout << text << endl;
    set<string, decltype(cmp)> container = SplitString(text);
    copy(container.begin(), container.end(), ostream_iterator<string>(cout, " \n"));
}




        int main()
        {
            SetConsoleCP(1251);

            SetConsoleOutputCP(1251);

            setlocale(LC_ALL, "rus");
            {
                //Task 1
                cout << "Задание 1\n\n";
                DemonstrationIterators();
            }

            {
                //Task 2
                cout << "\n\nЗадание 2" << endl;
                Task2();

            }

        };
        

