#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;
void updateStock(int medicineID, int quantity);
void addinfo();
void deleteMedicine(const string& medicineName);
void buymed();
void displayMedicines();
void updatenewStock();
void updateStockMenu();

struct meddata   //Declaring a structure
{
    int ID, stock;
    string name;
    float price;
};
meddata phar; //Object of structure

vector<meddata> pharmacy; //Declaring a vector of datatype of structure


void addinfo()
{
    int choice = 0;
    bool id;
    ofstream pharmacyFile; // File stream object for writing
    pharmacyFile.open("pharmacy.txt", ios::app); // Open the file in append mode to add

    if (!pharmacyFile.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }
    else
    {


        do
        {
            id = true;
            cout << "\n Enter name: ";
            cin.ignore();
            getline(cin, phar.name);
            cout << "\n Enter ID: ";
            cin >> phar.ID;
            for (size_t i = 0;i < pharmacy.size();i++)
            {
                if (pharmacy[i].ID == phar.ID || phar.ID==0)
                {
                    if (pharmacy[i].ID == phar.ID) {
                        cout << "This ID is alrady taken" << endl;
                        id = false;
                        break;
                    }
                    else if (phar.ID == 0)
                    {
                        cout << "0 can't be an ID. Please choose another" << endl;
                        id = false;
                        break;
                    }
                   
                }
            }
            if (!id)
            {
                continue;
            }

            cout << "\n Enter price: ";
            cin >> phar.price;
            cout << "\n Enter initial amount of strips: ";
            cin >> phar.stock;
            pharmacy.push_back(phar);
            pharmacyFile << phar.ID << " " << phar.name << " " << phar.price << " " << phar.stock << endl;
            cout << "\n Succesfully added" << endl;
            cout << "Do you want to add more, press 1 to exit press 0:  ";
            cin >> choice;

        } while (choice != 0 && choice == 1);
    }
    pharmacyFile.close(); // Close the file after writing
}

void deleteMedicine(const string& medicineName)
{

    for (auto it = pharmacy.begin(); it != pharmacy.end(); ++it)
    {
        if (it->name == medicineName)
        {
            pharmacy.erase(it);
            cout << "Medicine '" << medicineName << "' deleted successfully." << endl;
            return;
        }
    }
    cout << "Medicine '" << medicineName << "' not found in the database." << endl;
}
void buymed()
{
    meddata med;
    string medicineName;
    int  quantity;
    float totalPrice = 0;

    cout << "\nEnter the Name of the medicine you want to buy: ";
    cin >> medicineName;

    // Search for the medicine

    bool found = false;
    for (const meddata& med : pharmacy)
    {
        if (med.name == medicineName)
        {
            found = true;

            cout << "\nHow much tablets do you want to buy : ";
            cin >> quantity;

            // Check for stock
            if (quantity > 0 && quantity <= med.stock)
            {
                // Calculate the total price
                totalPrice = med.price * quantity;

                // Display the receipt
                cout << "\n--------RECIEPT--------\n";
                cout << "Medicine Name-------- " << med.name << endl;
                cout << "Medicine ID-------- " << med.ID << endl;
                cout << "Tablets--------" << quantity << endl;
                cout << "Price per unit-------- Rs: " << med.price << endl;
                cout << "Total Price-------- Rs: " << totalPrice << endl;
                updateStock(med.ID, quantity);

                cout << "\n----------------THANKYOU FOR YOUR PURCHASE!!!----------------\n" << endl;
            }
            else
            {
                cout << "\nInvalid quantity. Please enter a valid quantity.\n";
            }

            break; // Exit the loop once the medicine is found
        }
    }

    if (!found)
    {
        cout << "\nMedicine with Name " << medicineName << " not found in the database.\n";
    }
}
void prevadd() {
    // Added predefined medicine information to the pharmacy vector
    meddata med1 = { 1, 100, "Panadol", 4 }; // Initializing medicine 1
    pharmacy.push_back(med1);
    meddata med2 = { 2, 100, "Nuberal fort", 6 }; // Initializing medicine 2
    pharmacy.push_back(med2);
    meddata med3 = { 3, 100, "Denzene DS", 5 }; // Initializing medicine 3
    pharmacy.push_back(med3);
    meddata med4 = { 4, 100, "Brufene ", 11 }; // Initializing medicine 4
    pharmacy.push_back(med4);
    meddata med5 = { 5, 100, "Rigix", 7 }; // Initializing medicine 5
    pharmacy.push_back(med5);
    meddata med6 = { 6, 100, "Panadol Extend", 6 }; // Initializing medicine 6
    pharmacy.push_back(med6);
    meddata med7 = { 7, 100, "Caflem", 7 }; // Initializing medicine 7
    pharmacy.push_back(med7);
    meddata med8 = { 8, 100, "Voren", 6 }; // Initializing medicine 8
    pharmacy.push_back(med8);
    meddata med9 = { 9, 100, "Augmenton", 16 }; // Initializing medicine 9
    pharmacy.push_back(med9);
    meddata med10 = { 10, 100, "Cefspan", 5 }; // Initializing medicine 10
    pharmacy.push_back(med10);
    ifstream pharmacyFile("pharmacy.txt"); //Oject for reading
    if (!pharmacyFile.is_open()) {
        std::cout << "Error opening file!" << endl;
    }
    else
    {
        while (pharmacyFile >> phar.ID >> phar.name >> phar.price >> phar.stock) {
            pharmacy.push_back(phar);
        }
    }
    pharmacyFile.close();
}
void displayMedicines()
{
    cout << "--------MEDICINE LIST--------" << endl;;
    for (const meddata& med : pharmacy)
    {
        cout << "Medicine ID: " << med.ID
            << ", Name: " << med.name
            << ", Price: Rs. " << med.price
            << " , Stock: " << med.stock
            << endl;
    }
    ifstream pharmacyFile("pharmacy.txt"); //Oject for reading
    if (!pharmacyFile.is_open()) {
        std::cout << "Error opening file!" << endl;
    }
    else
    {
        while (pharmacyFile >> phar.ID >> phar.name >> phar.price >> phar.stock) {
            pharmacy.push_back(phar);
        }
    }
    pharmacyFile.close();
}

void updateStock(int medicineID, int quantity)
{
    for (meddata& med : pharmacy) {
        if (med.ID == medicineID) {
            med.stock += quantity;
            break;
        }
    }
}

void updatenewStock(int medicineID, int quantity)
{
    for (meddata& med : pharmacy) {
        if (med.ID == medicineID) {
            med.stock += quantity;
            break;
        }
    }
}

void updateStockMenu()
{
    int medicineID, quantity;

    cout << "Enter the ID of the medicine to update stock: ";
    cin >> medicineID;

    cout << "Enter the quantity to add to stock: ";
    cin >> quantity;

    updateStock(medicineID, quantity);

    cout << "Stock for Medicine ID " << medicineID << " is updated." << endl;
}

const string admin_username = "admin", admin_password = "123456";

int main()
{
    int choice1;
    int n;
    string username2, password2;
    prevadd();
    do
    {
        cout << endl;
        cout << "--------WELCOME TO OUR PHARMACY--------" << endl;
        cout << "Enter" << endl;
        cout << "1 if you are a pharmacist" << endl;
        cout << "2 if you are a customer" << endl;
        cout << "3 to Exit Program " << endl;
        cin >> n;

        bool validPassword = false;

        if (n == 2) // If customer
        {

            do {
                cout << endl;
                cout << "Press 1 to Display Medicines List" << endl;
                cout << "Press 2 to Buy Medicines" << endl;
                cout << "Press 3 to exit " << endl;
                cin >> choice1;

                switch (choice1)
                {
                case 1:

                    displayMedicines();
                    break;
                case 2:

                    buymed();
                    break;
                case 3:
                    break;
                default:
                    cout << "Enter a Valid Choice" << endl;
                }
            } while (choice1 != 3);
        }

        else if (n == 1) //If pharmicist
        {
            int c;
            cout << "Please Enter Your Username: ";
            cin >> username2;

            cout << "Please Enter Your Password:";
            cin >> password2;
            if (admin_username == username2 && admin_password == password2)
            {
                validPassword = true;
            }
            if (validPassword)
            {
                cout << "--------ACCESS APPROVED--------" << endl;
                
                do
                {
                    cout << endl;
                    cout << "Press 1 to add medicine" << endl;
                    cout << "Press 2 to delete medicine" << endl;
                    cout << "Press 3 to show all medicines list" << endl;
                    cout << "Press 4 to update stock" << endl;
                    cout << "Press 5 to exit" << endl;
                    cin >> c;
                    switch (c)
                    {
                    case 1:
                        addinfo(); //function call
                        break;
                    case 2:

                    {
                        string medicineName;
                        cout << "Enter the name of the medicine to delete: ";
                        cin.ignore();
                        getline(cin,medicineName);

                        deleteMedicine(medicineName);
                        break;
                    }
                    case 3:

                        displayMedicines();
                        break;

                    case 4:

                        updateStockMenu();
                        break;

                    case 5:
                        break;

                    default: cout << "Enter a valid number" << endl;
                    }
                } while (c != 5);
            }
            else {
                cout << "Wrong Username or Password. Access Denied!!!" << endl;
            }
        }

        else if (n == 3)
        {
            cout << "Exiting Program... Thank you!!! ";
            exit(0);
        }
        else
        {
            cout << "Choose valid number" << endl;
        }
    } while (n != 3);
}
