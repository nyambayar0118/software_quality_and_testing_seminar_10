========== 🏥 Hospital System ==========

Use this command to compile:

```bash
g++ main.cpp implementations/*.cpp -Iheaders -o main
```

This is a mock hospital system designed for doing unit and component/interface tests on it. This project includes following files:

## 📁 Project Structure

```text
oldVersion/               # Version before the files were modularized (very messy, probably won't work)

hospital_mock_system/
│
├── headers/ # Header files (.h)
│ ├── human.h
│ ├── doctor.h
│ ├── patient.h
│ ├── hospital.h
│ └── hospitalService.h
│
├── implementations/                # Implementation files (.cpp)
│ ├── human.cpp
│ ├── doctor.cpp
│ ├── patient.cpp
│ ├── hospital.cpp
│ └── hospitalService.cpp
│
├── tests/ # Unit and Component Test Headers
│ ├── UnitTests.h
│ └── ComponentTests.h
│
├── main.cpp                        # Main file containing all the calls and test calls
└── diagram.wsd                     # 🧩 UML class diagram (PlantUML format)
```
