#pragma once

#include <vector>
#include "cell.h"

// Declaración adelantada de la clase Cell
class Cell;

// Declaración de la clase Lattice
class Lattice {
public:
    // Constructor
    Lattice(int size);

    // Destructor
    ~Lattice();

    // Método para obtener una referencia constante a una célula en una posición específica
    const Cell& getCell(const Position& position) const;

    // Método para cargar la configuración inicial del autómata celular
    void loadInitialConfiguration();

private:
    std::vector<Cell*> cells_;
    int size_;
};
