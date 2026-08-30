# 🏧 ATM Banking Simulator System

[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)
[![C++](https://img.shields.io/badge/Language-C%2B%2B-00599C.svg)](https://isocpp.org/)
[![Security](https://img.shields.io/badge/Feature-PIN_Authentication-red.svg)]()
[![File I/O](https://img.shields.io/badge/Storage-Persistent_File_Streams-brightgreen.svg)]()

A robust, console-based **Automated Teller Machine (ATM) Banking Simulation System** written in C++. Designed to replicate modern banking workflows, the application handles user authentication, PIN security, balance inquiry, deposit processing, withdrawal validation with overdraft protection, and persistent file-based transaction logging.

---

## 📌 Overview

| Attribute | Specification |
|---|---|
| **Domain** | Systems Programming, Financial Simulation, Console Application |
| **Language** | C++ (Standard Template Library, fstream) |
| **Data Persistence** | File-based account record storage and transaction journaling |
| **Security Controls** | PIN verification, withdrawal threshold limits, input sanitization |

---

## ✨ Key Features

- **Secure PIN Verification:** Multi-attempt credential validation protecting user accounts against unauthorized access.
- **Account Balance Inquiry:** Real-time balance retrieval reflecting immediate transaction modifications.
- **Cash Deposit & Withdrawal:** Accurate credit/debit operations with automated balance sufficiency checks.
- **PIN Management:** In-session PIN update functionality with confirmation validation.
- **Persistent Data Storage:** Uses C++ `fstream` file handling to ensure balances and credentials survive application termination.

---

## 📂 Project Structure

```
ATM_Simulator_Project/
├── ATM PROJECT CODE.cpp        # Complete C++ source code
├── .gitattributes
├── LICENSE                     # MIT License
└── README.md                   # Documentation
```

---

## 🚀 Setup & Run

### Prerequisites
- Any C++ compiler (`g++`, `clang++`, or Visual Studio).

### Compile and Execute
```bash
# Compile source code
g++ "ATM PROJECT CODE.cpp" -o atm_simulator

# Run executable
./atm_simulator
```

---

## 🛠️ Technologies Used

- **Language:** C++ (Standard Library: `iostream`, `fstream`, `string`, `iomanip`)
- **Key Concepts:** Control Flow, Modular Function Design, File Streams (I/O), Exception Handling & Input Validation

---

## 📄 License

This project is licensed under the **MIT License** — see the [LICENSE](LICENSE) file for details.

---

## 👩‍💻 Author

**Fatima Javaid**  
- **GitHub:** [@Fatima-38](https://github.com/Fatima-38)  
- **Email:** fatimajavaid503@gmail.com  
- **Portfolio:** [fatima-portfolio](https://fatima-38.github.io/fatima-portfolio/)
