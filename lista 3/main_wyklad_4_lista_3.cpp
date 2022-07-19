#include <iostream>

struct Link
{
    int value;
    Link* next = nullptr;  // nullptr to adres "nieistniejący", nic nie pokazuje, nie ma danych (za nim)
};

void add(Link** head, int n)
{
    Link* tmp = new Link;
    tmp->value = n;
    tmp->next = *head;
    *head = tmp;
}

void remove_one(Link** phead, int n)
{
    Link* head = *phead;
    if (head == nullptr) return;

    // osobno traktujemy przypadek, gdy poszukiwana wartość jest w pierwszym elemencie listy
    if (head->value == n)
    {
        Link* tmp = head;     // uchwyt do usuwanego elmentu
        *phead = head->next;  // aktualizacja wskaźnika pokazującego początek listy (przeskok o pierwszy element)
        delete tmp;           // usunięcie elementu
        return;
    }

    while (head->next != nullptr && head->next->value != n)
    {
        head = head->next;
    }

    // w tym miejscu albo head->next == nullptr, albo head->next->value == n (ale nie jednocześnie - dlaczego?)
    if (head->next == nullptr)
    {
        return;  // nie znaleźliśmy n
    }

    // w tym miejscu musi być spełniony warunek head->next->value == n, czyli znaleźliśmy n
    Link* tmp = head->next;         // ten element usuniemy
    head->next = head->next->next;  // przestawiamy wskaźnik, by przeskoczyć usuwany element
    delete tmp;                     // usunięcie elementu listy
}

void print(const Link* head)  // implementacja rekurencyjna
{
    if (head == nullptr) return;

    std::cout << head->value << " ";
    print(head->next);
}

void print2(const Link* head)  // implementacja iteracyjna
{
    while (head != nullptr)
    {
        std::cout << head->value << " ";
        head = head->next;
    }
    std::cout << "\n";
}

// zwalniamy pamięć zajmowaną przez elementy listy
void release(Link** phead)
{
    Link* head = *phead;
    while (head != nullptr)
    {
        Link* tmp = head;
        head = head->next;
        delete tmp;
    }
    *phead = nullptr;  // aktualizacja uchwytu (wskaźnika) do pierwszego elementu listy
}

int main()
{
    Link* lista = nullptr;

    add(&lista, 23);
    add(&lista, 24);
    add(&lista, 25);
    remove_one(&lista, 23);

    print(lista);
    std::cout << "\n";
    print2(lista);

    std::cout << "Hello World!" << std::endl;

    release(&lista);
    print(lista);

    return 0;
}
