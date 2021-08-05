#include <SDL2/SDL.h>
#include <unistd.h>
#include <stdbool.h>

const int WINDOW_HEIGHT = 500;
const int WINDOW_WIDTH = 500;

int main(void) {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    fprintf(stderr, "ERR: SDL_Init failed: %s\n", SDL_GetError());
    exit(1);
  }

  SDL_Window* window = SDL_CreateWindow(
    "SDL Hello",
    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
    WINDOW_WIDTH, WINDOW_HEIGHT,
    SDL_WINDOW_SHOWN
  );

  SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  SDL_Event e;
  bool windowIsOpened = true;

  while (windowIsOpened) {
    while (SDL_PollEvent(&e) != 0) {
      if (e.type == SDL_QUIT) {
        windowIsOpened = false;
      }
    }

    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xff);
    SDL_RenderClear(renderer);

    for (int i = 0; i < WINDOW_WIDTH; ++i) {
      for (int j = 0; j < WINDOW_HEIGHT; ++j) {
        SDL_SetRenderDrawColor(renderer, i % 0xff, j % 0xff, (i + j) % 0xff, 0xff);
        SDL_RenderDrawPoint(renderer, i, j);
      }
    }

    SDL_RenderPresent(renderer);

    SDL_Delay(1000 / 60);
  }

  SDL_DestroyRenderer(renderer);
  renderer = NULL;
  SDL_DestroyWindow(window);
  window = NULL;

  SDL_Quit();

  return 0;
}
