#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Menu{
public:
    void MainMenu(){
        string Inventory_Name, ID, Text_Description, Weight, mystr,space;
        Inventory_Name="inventory";
        space="\n";
        int choice = 0;
        do
        {
            cout << endl
                 << "------------------------------------\n"
                 << " 1. create a new inventory\n"
                 << " 2. Add box to inventory\n"
                 << " 3. Print the inventory\n"
                 << " 4. Exit\n"
                 << " Enter your choice and press return: \n"
                 << "------------------------------------\n";
            cin >> choice;
            switch (choice)
            {
            case 1:

            
                CreateFile(Inventory_Name);
                cout << "Add successfully!" << endl;

                break;
            case 2:

                std::cout << "input ID number" << std::endl;
                cin >> ID;
                cout << "Add ID successfully!" << endl;
                mystr = "\n";
                getline(cin, mystr);

                cout << "Input Text_Description" << endl;
                getline(std::cin, Text_Description);
                cout << "Add Text Description successfully!" << endl;
                std::cout << "Input weight" << std::endl;
                cin>>Weight;
                 cout << "Add Weight!" << endl;
                WriteFile(Inventory_Name, ID, Text_Description,Weight);
                
                break;
            case 3:
               
                PrintFile(Inventory_Name,space);

                break;
            case 4:

                break;
            default:
                cout << "Not a Valid Choice. \n";
                break;
            }

        } while (choice != 4);
        {
            cout << "byebye\n";

           
        };
    }
    void CreateFile(string a)
    {
        ofstream newFile;
        newFile.open(a + ".txt");
        newFile.close();
    }
    void WriteFile(string a, string ID, string Text,string Weight)
    {
        ofstream newFile;
    // write in file
        newFile.open(a + ".txt",ios::app);
        newFile << ID << endl;
        newFile << Text << endl;
        newFile << Weight +"\n " << endl;
        newFile.close();
       
    }
    void PrintFile(string a, string b)
    {
        string line;
        ifstream myFile;
        
        myFile.open(a + ".txt");
        cout << "           Current inventory details" << endl;
        cout<<"ID Number     Text description of its contents     Weight (kg)"<< endl;
        // Print file content
      

        if (myFile.is_open())
        while (getline(myFile, line))
        {
            if (line==" "){
                cout<<"\n";
            }
            else{
              
                cout << line+"                  ";
                }
     
        }
       else{
        cout<<"Please add box first!"<<endl;
       }

        myFile.close();
    }
};


int main()
{
    Menu m;
    m.MainMenu();
    return 0;
}
