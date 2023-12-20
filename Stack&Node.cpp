#include <iostream>
#include <string>
using namespace std;


class Node 
{
public:
    int key;        // ключ к Node
    Node* next;     // Указатель к следующему эл.Node

    Node(int k) 
    {   
        key = k;
        next = NULL;
    }
};


class Stack 
{
private:
    Node* top;      // Указатель к верхнему элементу Node
    int length;     // длина стэка

public:
    Stack() 
    {
        top = NULL;
        length = 0;
    }

    ~Stack() // деструктор
    {      
        while (top != NULL) 
        {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    bool isEmpty()     // проверяем является ли стэк пустым, путем проверки верхнего узла на наличие
    {    
        return top == NULL;
    }

    bool isFull()     // функция проверяет, является ли стэк полным
    {     
        return false;   
    }

    void push(int k)    // функция добавляет элемент в стэк
    {  
        Node* newNode = new Node(k);
        newNode->next = top;
        top = newNode;
        length++;
    }

    void pop()   // удаляет элемент и выводит на экран
    {        
        if (isEmpty()) 
        {
            cout << "Стэк пустой" << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        int popped = temp->key;
        delete temp;
        length--;
        cout << "Удаленный и выведенный элемент: " << popped << endl;
    }

    void remove()   // удаляяет все элементы стэка
    {     
        while (!isEmpty()) 
        {
            pop();
        }
    }

    void copy(Stack& newStack)   // копирует все элементы в новый стэк
    {    
        Node* temp = top;
        while (temp != NULL) 
        {
            newStack.push(temp->key);
            temp = temp->next;
        }
    }

    int getLength()   // выводит информацию о длине стэка
    {   
        
        return length;
    }

    void print()   // выводит стэк в терминал
        {
        Node* temp = top;
        while (temp != NULL) {
            cout << temp->key << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "RU");
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(10);
    stack.push(12);
    stack.push(38);

    cout << "Длина стэка: " << stack.getLength() << endl;
    cout << "Стэк: ";
    stack.print();

    stack.pop();
    stack.remove();

    if (stack.isEmpty()) {
        cout << "Стэк пустой" << endl;
    }

    return 0;
}
