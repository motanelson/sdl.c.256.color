#include <SDL2/SDL.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow("SDL2 Rectangle", 
                                          SDL_WINDOWPOS_CENTERED, 
                                          SDL_WINDOWPOS_CENTERED, 
                                          800, 600, 
                                          SDL_WINDOW_SHOWN);
    if (!window) {
        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black background
    SDL_RenderClear(renderer);

    // Set rectangle color
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255); 

    // Define the rectangle
    SDL_Rect rect = {0, 0, 800, 600}; // x, y, width, height

    // Draw the rectangle outline
    SDL_RenderFillRect(renderer, &rect);
    // Set rectangle color
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Red

    // Define the rectangle
    for(int i=0;i<800;i=i+100){
        SDL_Rect r = {i, 100, 90, 100}; // x, y, width, height

       
        // Uncomment the next line to fill the rectangle
        SDL_RenderDrawRect(renderer, &r);
    }
    SDL_RenderPresent(renderer);

    SDL_Delay(5000); // Display for 5 seconds

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}