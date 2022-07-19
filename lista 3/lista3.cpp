#include <iostream>

using namespace std;

struct Link
{
    int value;
    Link* next = nullptr;
};

void add(Link** head, int n)
{
    Link* tmp = new Link;
    tmp -> value = n;
    tmp -> next = *head;
    *head = tmp;
}

void print(const Link* head)
{
    while (head != nullptr)
    {
        cout << head -> value << " ";
        head = head -> next;
    }
    cout << "\n";
}

//Zadanie 1.a
size_t size(const Link* head)
{
    size_t count = 0;
    while (head != nullptr)
    {
        count++;
        head = head -> next;
    }

    return count;
}

//Zadanie 1.b
size_t sum(const Link* head)
{
    size_t suma = 0;
    while (head != nullptr)
    {
        suma += head -> value;
        head = head -> next;
    }

    return suma;
}

//Zadanie 2
void release(Link** phead)
{
    if (phead == nullptr) return;

    Link* head = *phead;
    Link* tmp = head;
    head = head -> next;

    delete tmp;
    *phead = nullptr;
}

//Zadanie 3
void reverse(Link* &L)
{
    if (L == nullptr || L -> next == nullptr) return;

    Link* previous_elements = nullptr;
    Link* temp = L -> next;

    while(temp != nullptr)
    {
        L -> next = previous_elements;
        previous_elements = L;
        L = temp;
        temp = temp -> next;
    }

    L -> next = previous_elements;
}

int main()
{
    Link * lista = nullptr;

    add(&lista, 1);
    add(&lista, 2);
    add(&lista, 3);

    cout << "Lista: ";
    print(lista);

    //Test 1.a
    cout << "Liczba elementow na liscie: " << size(lista) << endl;

    //Test 1.b
    cout << "Suma elementow na liscie: " << sum(lista) << endl;

    //Test 2 (należy odkomentować poniższą linię w celu sprawdzenia zadania)
    //release(&lista);
    cout << "Liczba elementow i suma listy, po uzyciu funkcji zwalniajacej pamiec: " << size(lista) << " " << sum(lista) << endl;

    //Test 3
    cout << "Lista przed odwroceniem: ";
    print(lista);
    reverse(lista);
    cout << "Lista po odwroceniu: ";
    print(lista);

    return 0;
}
