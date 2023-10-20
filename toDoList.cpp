#include <iostream>
#include <string>
#include <list>
#include <ctime>

using namespace std;

//initializing a class for ToDo Item
class TodoItem
{
    private:
        int id;
        string description;
        bool completed;
    //Constructor?? How does this interact with the class? why?
    public: 
        TodoItem(): id(0), description(""), completed(false){}
        //destructor?? Again, how is this used?
        ~TodoItem() = default;

        bool create(string new_description)
        {
            //randomly gen an int between 1 and 100 
            id = rand() % 100 + 1;
            description = new_description;
            return true;
        }

        //why do we create these methods within this class??
        int getId() {return id;}
        string getDescription() {return description;}
        bool isCompleted() {return completed;}

        void setCompleted(bool val){ completed = val; }
};

int main()
{
    string input_description;
    int input_id;
    char input_option;
    string version = "v0.2.0";
    //list of TodoItem called todoItems, why use a list here instead of array?
    list<TodoItem> todoItems;
    //declare an iterator
    list<TodoItem>::iterator it;
    //why use srand? a brand new seed for the rand num gen
    srand(time(NULL));
    //start with a fresh clear list
    todoItems.clear(); 

    // TodoItem test;
    // test.create("this is a test");
    // todoItems.push_back(test);

    while(1)
    {
        system("cls"); //why use system?? Windows cmd to clear the terminal or console
        cout << "To Do List Maker" << version << endl;
        cout << endl << endl;

        for(it = todoItems.begin(); it != todoItems.end(); it++)
        {
            string completed = it->isCompleted() ? "Done" : "Not Done";

            cout << it->getId() << " | " << it->getDescription() << " | "
                 << completed << endl;
        }

        if (todoItems.empty())
        {
            cout << "Add your first todo!" << endl;
        }

        cout << endl << endl;

        cout << "[a]dd a new Todo" << endl; 
        cout << "[c]complete a Todo" << endl;
        cout << "[q]uit" << endl;

        cout << "choice: ";

        cin >> input_option;
        

        if(input_option == 'q')
        {
            cout << "have a great day!" << endl;
            break;
        }
        else if(input_option == 'a')
        {
            cout << "Add a new description: ";
            cin.clear();
            cin.ignore();
            getline(cin, input_description);

            TodoItem newItem;
            newItem.create(input_description);
            todoItems.push_back(newItem);
        }
        else if(input_option == 'c')
        {
            cout << "Enter ID to mark completed: ";
            cin >> input_id;

            for(it = todoItems.begin(); it != todoItems.end(); it++)
            {
                if(input_id == it->getId())
                {
                    it->setCompleted(true);
                    break;
                }
            }

        }
        

    }

    return 0;
}
