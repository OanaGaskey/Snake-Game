#include <iostream>
// #include <thread>
#include <memory>
#include "controller.h"
#include "game.h"
#include "renderer.h"

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{320};
  constexpr std::size_t kScreenHeight{320};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
  Game game(kGridWidth, kGridHeight);
  game.Run(controller, renderer, kMsPerFrame);
  std::cout << "Game has terminated successfully!\n";
  std::cout << "The winner is: Snake "<<game.GetWinner() << "\n";
  std::cout << "Winner's Score: " << game.GetScore() << "\n";
  std::cout << "Winner's Size: " << game.GetSize() << "\n";
  return 0;
}