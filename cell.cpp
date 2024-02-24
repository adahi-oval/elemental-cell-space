#include "cell.h"
#include "lattice.h"

// Constructor de la célula
Cell::Cell(const Position& position, const State& initialState) {
  position_ = position;
  state_ = initialState;
}

// Obtener el estado de la célula
State Cell::getState() const {
  return state_;
}

// Establecer el estado de la célula
void Cell::setState(State newState) {
  state_ = newState;
}

std::vector<State> Cell::getNeighbors(const Lattice& lattice) const {
  std::vector<State> neighbors;

  if (position_ > 0) { // Verificar si la posición actual no es la primera
    neighbors.push_back(lattice.getCell(position_ - 1).getState());
  } else {
    neighbors.push_back(State()); // Depende de las condiciones de frontera
  }

  neighbors.push_back(lattice.getCell(position_ + 1).getState());

  return neighbors;
}


// Función de transición, para next State usando la regla 110
const State Cell::transitionFunction(const State& C, const State& L, const State& R) const {
  State result = C + R + C * R + L * C * R;
  return result;
}

// Calcular el siguiente estado de la célula
const State Cell::nextState(const Lattice& lattice) const {
  std::vector<State> vecinos = this->getNeighbors(lattice);

  State C = this->getState();
  State L = vecinos[0];
  State R = vecinos[1];

  return transitionFunction(C, L, R);
}

// Actualizar estado
void Cell::updateState(const Lattice& lattice) {
  this->setState(nextState(lattice));
}
