#include "gui/window.h"

gui::Window *main_window;

int main() {
  main_window = new gui::Window();

  main_window->Init();
  main_window->Loop();

  return 0;
}