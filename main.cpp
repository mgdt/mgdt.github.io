#include <iostream>
#include <string>
using namespace std;

template <class T>
class Elem
{
public:
   T data;
   Elem * next;
   Elem * prev;
};

template <class T>
class List {
private:
    Elem<T> * Head;
    Elem<T> * Tail;
    int count;
public:
    List() {
        Head = NULL;
        Tail = NULL;
        count = 0;
    }

    //Получить размер списка
    int getSize() {
        return count;
    }

    //Добавить в конец
    void pushBack(T n) {
        Elem<T> * temp = new Elem<T>;

        temp->next = 0;
        temp->data = n;
        temp->prev = Tail;

        if (Tail != 0) {
            Tail->next = temp;
        }
        if (count == 0) {
            Head = Tail = temp;
        } else {
            Tail = temp;
        }

        count++;
    }

    //Добавить в начало
    void pushFront(T n) {
        Elem<T> * temp = new Elem<T>;

        temp->prev = 0;
        temp->data = n;
        temp->next = Head;

        if (Head != 0) {
            Head->prev = temp;
        }
        if (count == 0) {
            Head = Tail = temp;
        } else {
            Head = temp;
        }

        count++;
    }

    //Перегрузка оператора []
    T& operator[] (int pos) {
        Elem<T> * temp;

        if (pos < (count / 2)) { //Проверяем, если позиция элемента меньше середины, то идем к элементу с начала
           temp = Head;

            int i = 0;
            while (i < pos && temp != 0) {
                temp = temp->next;
                i++;
            }
        } else { // Иначе идем с конца
           temp = Tail;

            int i = count - 1;
            while (i > pos && temp != 0) {
                temp = temp->prev;
                i--;
            }
        }

        return temp->data;
    }

    //Удаление элемента с i-ой позиции
    void pop(int pos) {
        int i = 0;

        Elem<T> * del = Head;
        while (i < pos) {
            del = del->next;
            i++;
        }
        Elem<T> * delPrev = del->prev;
        Elem<T> * delNext = del->next;

        if (delPrev != 0 && count != 1) {
            delPrev->next = delNext;
        }
        if (delNext != 0 && count != 1) {
            delNext->prev = delPrev;
        }
        if (pos == 0) {
            Head = delNext;
        }
        if (pos == count-1) {
            Tail = delPrev;
        }

        delete del;
        count--;
    }

    //Копирование содержимого списка
    List& operator= (List & lst) {
        Head = Tail = NULL;
        count = 0;
        Elem<T> * temp = lst.Head;

        while (temp != 0) {
            pushBack(temp->data);
            temp = temp->next;
        }
        return * this;
    }

    //Перегрузка оператора += (добавление списка в конец текущего)
    List& operator += (List & lst) {

        Elem<T> * temp = lst.Head;

        while(temp != 0) {
            pushBack(temp->data);
            temp = temp->next;
        }

        return * this;
    }

};

int main()
{

    List<string> lst;
    lst.pushFront("lst1:1");
    lst.pushBack("lst1:2");
    lst.pushBack("lst1:3");
    lst.pushBack("lst1:4");
    lst.pushBack("lst1:5");
    lst.pushBack("lst1:6");

    for (int i = 0; i < lst.getSize(); i++) {
        cout << lst[i] << " ";
    }
    cout << endl;

    List<string> lst2;
    lst2 = lst;
    lst2.pushBack("lst2:1");
    lst2.pushBack("lst2:1");

    for (int i = 0; i < lst2.getSize(); i++) {
        cout << lst2[i] << " ";
    }
    cout << endl;

    List<string> lst3;
    lst3.pushBack("lst3:1");
    lst3.pushBack("lst3:2");
    lst3.pushBack("lst3:3");

    lst3 += lst;

    for (int i = 0; i < lst3.getSize(); i++) {
        cout << lst3[i] << " ";
    }

    return 0;
}
