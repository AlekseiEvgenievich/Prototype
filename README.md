# Prototype
# 🛰️ Prototype — Particle Detector Simulation Framework

## 📌 Overview

**Prototype** is a simulation and analysis framework for studying the response of a multi-layer particle detector system using **Geant4** and **ROOT**.

The project is designed for:

* detector response simulation
* background modeling in space environment
* trigger logic optimization
* sensitivity estimation for gamma-ray sources

This work is part of ongoing research on **novel detection techniques for microsatellite missions**.

---

## 🧱 Project Structure

```
Prototype/
│
├── src/            # C++ implementation files (.cc)
├── include/        # Header files (.hh)
├── macros/         # Geant4 macro files
│
├── README.md
└── .gitignore
```

### 📂 Directory Description

#### `src/`

Contains implementation of:

* detector geometry
* physics processes
* event handling
* data acquisition logic

#### `include/`

Defines core classes:

* `DetectorConstruction`
* `PrimaryGeneratorAction`
* `RunAction`
* `EventAction`
* `SteppingAction`

#### `macros/`

Geant4 macro files used to:

* configure simulations
* define particle sources
* control run parameters

---

## ⚙️ Dependencies

* **C++17**
* **Geant4 (>= 10.x)**
* **ROOT (>= 6.x)**
* **CMake**
* macOS / Linux

---

## 🔧 Installation

### 1. Clone repository

```bash
git clone https://github.com/AlekseiEvgenievich/Prototype.git
cd Prototype
```

### 2. Build project

```bash
mkdir build
cd build
cmake ..
make -j$(nproc)
```

---

## 🚀 Running Simulation

### Batch mode

```bash
./Crystal Eye ../macros/run.mac name_of_particle
```

### Interactive mode

```bash
./Crystal Eye
```

---

## ⚛️ Detector Description

The simulated detector includes:

* multi-layer scintillator system
* anti-coincidence shielding
* top and bottom detector layers

### Key Features

* layered geometry with orthogonal structure
* configurable detector materials (e.g. LYSO)
* coincidence and anti-coincidence logic
* energy deposition tracking


## ⚛️ Physics Simulation

The framework supports simulation of:

* gamma rays
* electrons
* positrons
* protons

### Features

* configurable energy spectra (power-law, mono)
* isotropic or directional sources
* first interaction tracking
* full energy deposition analysis

## 📦 Output

Simulation produces:

### ROOT files

* energy histograms
* event-level data
* response matrices


## 🧠 Future Improvements

* unfolding algorithms implementation
* improved detector geometry
* integration with real DAQ data
* machine learning for event classification
* optimization for space missions

---

## 👤 Author

**Aleksei Smirnov**
PhD student in Experimental High Energy Physics
Gran Sasso Science Institute (Italy)

Research focus:

* detector R&D for space applications
* Geant4 simulations
* data analysis with ROOT

---

## 🤝 Contributing

Contributions are welcome:

* bug reports
* feature requests
* pull requests

---

## 📜 License

Specify your license (e.g. MIT)

---

## ⭐ Acknowledgements

This work is part of detector development efforts for future space-based experiments.

---

## ⚠️ Disclaimer

This repository is a prototype under active development.
Results should be considered preliminary.


