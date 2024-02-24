#include "lattice.h"
#include <stdexcept>

// Constructor del retículo
Lattice::Lattice(int size) : size_(size) {
    // Crear las células del retículo en memoria dinámica y agregar punteros a ellas al vector
    for (int i = 0; i < size_; ++i) {
        cells_.push_back(new Cell(i, false)); // Agrega un nuevo puntero a célula al final del vector
    }
}

// Destructor del retículo
Lattice::~Lattice() {
    // Liberar la memoria de las células
    for (auto cellPtr : cells_) {
        delete cellPtr;
    }
}

// Método para obtener una referencia constante a una célula en una posición específica
const Cell& Lattice::getCell(const Position& position) const {
    if (position >= 0 && position < size_) {
        return *cells_[position];
    }
    throw std::out_of_range("Position is out of range");
}

void Lattice::loadInitialConfiguration() {
    // Colocar el valor de estado "0" en todas las células
    for (auto cellPtr : cells_) {
        cellPtr->setState(false);
    }
    // Asignar el valor de estado "1" a la célula central
    if (size_ % 2 == 0) {
        cells_[size_ / 2]->setState(true);
    } else {
        cells_[size_ / 2]->setState(true);
    }
}
