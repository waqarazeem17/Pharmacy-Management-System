# 💊 Pharmacy Management System

This is a **console-based Pharmacy Management System** built using **C++** for the Computer Programming Lab (CSL-113) course at Bahria University. The system is designed to **automate pharmacy operations** such as inventory control, medicine purchases, and prescription record-keeping.

The project demonstrates how fundamental C++ programming concepts can be applied to develop a **real-life utility application** with structured data handling and file management.

---

## 📌 Overview

In the modern healthcare environment, **efficient management of pharmacies** is essential. Many small pharmacies still depend on **manual processes** for tracking medicines, processing sales, and managing customer data. This can result in:

- Inventory errors
- Time-consuming prescription handling
- Incomplete customer records
- Difficulty generating reports

This Pharmacy Management System addresses these problems by offering an automated solution that improves accuracy, speed, and productivity.

---

## 🧠 Objectives

The main goals of this system are:

- Streamline pharmacy operations through automation.
- Reduce human errors in inventory and sales.
- Provide secure access to pharmacy records.
- Create a user-friendly interface using C++.

---

## 🛠️ Technologies Used

- **Language:** C++
- **Compiler:** g++, Dev C++, Visual Studio Code
- **Concepts Applied:**
  - Structures (`struct`)
  - Vectors (`std::vector`)
  - File Handling (`fstream`)
  - User Authentication
  - Menu-driven programming
  - Conditional logic & loops

---

## ⚙️ Core Functionalities

### 👨‍⚕️ Pharmacist Panel
Accessible after login with predefined credentials.

**Features:**
- **Add Medicine:** Input new medicine name, ID, price, and stock.
- **Delete Medicine:** Remove medicine record by name.
- **Update Stock:** Modify quantity of an existing medicine.
- **Display Medicines:** View full list with current stock and prices.
- **Login Protection:** Only accessible using correct username & password.

**Authentication Details:**
``plaintext
Username: admin
Password: 123456

---

## 👥 Customer Panel

**Features:**

- **View Available Medicines:** Customers can view all the available medicines along with their prices and stock levels.
- **Buy Medicines:** Customers can purchase medicines by specifying the medicine name and quantity.
- **Receipt Generation:** After purchase, a receipt is displayed showing the medicine name, quantity, unit price, and total cost.
- **Automatic Stock Update:** The stock is automatically updated when a customer makes a purchase.

---

## 🗃️ Data Management

The system uses a combination of file handling and data structures for persistent and runtime data management.

- **Persistent Data Storage:** The medicine data is saved in a text file named `pharmacy.txt`.
- **In-Memory Data Structure:** A `vector` of `struct meddata` is used to store medicine data during program execution.
- **File Operations:**
  - On program start, `pharmacy.txt` is read to populate the vector.
  - On adding a new medicine, the data is appended to the file.
  - On update or deletion, the vector is updated but not the file (this can be improved in future versions).

**Structure Definition:**

```cpp
struct meddata {
    int ID;
    int stock;
    string name;
    float price;
};

---

## 🔁 Program Flow

The Pharmacy Management System uses a **menu-driven interface** that separates functionalities for **pharmacists** and **customers**.

Here is how the system flows step by step:

### 1. Start Program
- A welcome menu appears asking:
  - `1` → Pharmacist
  - `2` → Customer
  - `3` → Exit

---

### 2. Pharmacist Panel

If the user selects `1` (Pharmacist), they are asked to enter credentials.

**Login Credentials:**
```plaintext
Username: admin
Password: 123456


🚀 How to Run the Program

Follow these steps to run the Pharmacy Management System locally:
🔧 Requirements:

    A C++ compiler like g++, MinGW, or Turbo C++

    IDEs like Code::Blocks, Dev C++, or Visual Studio Code

💻 Steps:

    Clone or Download the project from GitHub:

git clone https://github.com/your-username/pharmacy-management-system.git

Open the project folder in your preferred IDE.

Open the main.cpp file.

Compile the code:

    If using terminal:

    g++ main.cpp -o pharmacy
    ./pharmacy

    Or just click Run in your IDE.

Follow the menu displayed on screen to interact with the system:

    Choose Pharmacist or Customer

    Perform actions like adding medicines, buying, updating stock, etc.
