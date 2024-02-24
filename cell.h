#pragma once

#include <vector>

// Definiciones de tipos
using Position = int; // Tipo de dato para la posición dentro del retículo
using State = bool;   // Tipo de dato para el estado binario de la célula

// Declaración adelantada de la clase Lattice
class Lattice;

// Declaración de la clase Cell
class Cell {
public:
    // Constructor
    Cell(const Position& position, const State& initialState = false);

    // Métodos
    State getState() const; // Método para obtener el estado de la célula
    void setState(State newState); // Método para establecer el estado de la célula
    const State nextState(const Lattice& lattice) const; // Método para calcular el siguiente estado de la célula
    void updateState(const Lattice& lattice); // Método para actualizar el estado de la célula
    const State transitionFunction(const State& C, const State& L, const State& R) const;
    std::vector<State> getNeighbors(const Lattice& lattice) const;

private:
    Position position_; // Posición dentro del retículo
    State state_;       // Estado actual de la célula
};
