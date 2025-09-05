# 📚 Student Grading System

## **🔹 Overview**
The **Student Grading System** is a web-based application that allows users to enter **student details**, calculates **grades based on marks**, and **exports the data to a CSV file**. The backend **C++ program** then processes the CSV file and displays student records dynamically.

## **🛠️ Technology Stack**
- **Frontend**: HTML, Tailwind CSS, JavaScript  
- **Data Storage**: LocalStorage (Browser-based)  
- **Export Format**: CSV File  
- **Backend**: C++ (Handles CSV Reading & Processing)  

## **🚀 Features**
- ✅ **Modern UI with Tailwind CSS** - Clean, professional design.  
- ✅ **Dynamic Data Storage (LocalStorage)** - Data persists even after refreshing.  
- ✅ **CSV Export Feature** - Allows students' data to be saved in a file.  
- ✅ **C++ Backend Processing** - Reads CSV, calculates grades, and displays results.  

## **📊 Grading Criteria**
| **Marks (%)** | **Grade** |
|--------------|---------|
| 90 - 100 | A |
| 80 - 89 | B |
| 70 - 79 | C |
| 60 - 69 | D |
| Below 60 | F |

## **🖥️ How It Works?**
### **1️⃣ Frontend (index.html)**
- Users enter student details (Name & Marks).
- Marks are automatically converted into a Grade.
- Data is stored in LocalStorage for persistence.
- Data is displayed dynamically in a table.
- The **CSV Export button** generates a `students.csv` file.

### **2️⃣ CSV File (students.csv)**
- The CSV file is generated when users export the data.
- Example format:
  ```csv
  ID, Name, Marks, Grade
  1, John Doe, 85, B
  2, Jane Smith, 92, A
  ```

### **3️⃣ Backend (C++ Program)**
- The **C++ program** reads the `students.csv` file.
- It extracts student details (ID, Name, Marks).
- The **Grade is calculated** if not present.
- The formatted student records are displayed in the terminal.

## **🔰 Step-by-Step Guide to Run**
### **📌 1. Running the Web Application**
1. Open `index.html` in a browser.  
2. Enter **Student Name & Marks** and click **Add Student**.  
3. View records dynamically appearing in the **table**.  
4. Click **"Export CSV"** to generate `students.csv`.

### **📌 2. Running the C++ Program**
1. **Compile the C++ Code**:  
   ```bash
   g++ student.cpp -o student
   ```
2. **Run the C++ Program**:
   ```bash
   ./student
   ```
3. The program reads `students.csv` and displays records.

## **🎯 Why This Project is Unique?**
- ✅ **Uses Tailwind CSS** instead of traditional Bootstrap for a modern UI.  
- ✅ **Works Without a Database** - Uses LocalStorage for data persistence.  
- ✅ **Seamless Frontend-Backend Connection** - CSV acts as a bridge between HTML & C++.  
- ✅ **Can be Easily Extended** - Possible integration with **APIs & Databases**.  

## **💡 Future Enhancements**
- ✅ **Add a Python API** for backend connectivity.  
- ✅ **Use MySQL/PostgreSQL** for real-time student data storage.  
- ✅ **Generate Graphs & Reports** using JavaScript chart libraries.  

## **🎤 Conclusion**
The **Student Grading System** is an innovative and interactive project designed to simplify **student grade calculation, data storage, and processing**. With a **modern UI, automated calculations, and seamless integration**, it offers a **real-world use case** that can be expanded further..