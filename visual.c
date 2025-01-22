#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

#define WINDOW_POSX 0
#define WINDOWS_POSY 0



int main(int argc, char *argv[]) {
    SDL_bool running = SDL_TRUE;
    SDL_Window *window = SDL_CreateWindow("Tiles", WINDOW_POSX, WINDOWS_POSY, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED );
    
    SDL_Texture *tileSet = IMG_LoadTexture(renderer, "Tile.png");

    SDL_Rect tileRect = {0,0,100,100};
    
    // render loop

    while(running == SDL_TRUE){

        SDL_Event event;
        while (SDL_PollEvent(&event)){
            switch (event.type){
                case SDL_QUIT:
                    running = SDL_FALSE;
                    printf("Exiting Window");
                    break;
            }
        }
        SDL_RenderCopy(renderer, tileSet, NULL, &tileRect);
        SDL_RenderPresent(renderer);
    }
    
    SDL_DestroyTexture(tileSet);

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    return EXIT_SUCCESS;
}