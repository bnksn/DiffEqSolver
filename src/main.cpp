#include <iostream>
#include <memory>

// mine
#include "Solvers/SineSolver.cpp"

const std::unique_ptr<Solver> getSolver() {
	return std::make_unique<SineSolver>(Coeffs{1, 1}, 0.1, 30);
}

int main()
{	
	const auto solver = getSolver();

	const auto result = solver->Solve({.x = 0, .y = 0});

	for (const auto [x, y] : result)
	{
		std::cout << "x: " << x << " y: " << y << '\n';
	}
}