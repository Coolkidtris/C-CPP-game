#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>

/* Macro Definitions */
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

/*Important to note, X,Y is relative to the top left of the screen*/
#define WINDOW_POSX 0               // Determines window X position relative to the screen
#define WINDOWS_POSY 0              // Determines window Y position relative to the screen

#define maxMapSize 8                // Determines rows and columns

/* Structure Defintions */
typedef struct{                     // Vector with 3 Dimensions
    int x;                          // X Axis
    int y;                          // Y Axis
    int z;                          // Z Axis
}Vector3D;

typedef struct{                     // Vector with 2 Dimensions
    int x;                          // X Axis
    int y;                          // Y Axis
}Vector2D;

typedef struct{
    Vector3D hexCoordinates;        // Cube coordinates use X,Y,Z (Q,R,S) where all of these summed equals 0f
    Vector2D spriteCoordinates;     // Coordinates on the sprite sheet as to where the current sprite is located
    SDL_Rect hexRect;               // SDL Rect which allows for the coordinate data to be used to show the Hex
}Hex;

/* SDL Variables */
SDL_bool running = SDL_TRUE;        // Boolean of whether or not the game is running
SDL_Window *window;                 // Pointer to the window to create
SDL_Renderer *renderer;             // Pointer to the renderer used to render within the window
SDL_Texture *tileSet;               // Pointer to the texture holding the tileset.
SDL_Rect tileRect;                  // Uninitialised Rect.


/* Hex Functions */
Hex initialiseHex(Vector3D hexCoordinates, Vector2D tileCoordinates){   // Function that creates a new Hex tile data structure
    SDL_Rect newRect = {hexCoordinates.x, hexCoordinates.y, 64,64};     // Create a new SDL_Rect with given coordinates 
    Hex newHex = {hexCoordinates, tileCoordinates, newRect};            // Create our new Hex using coordinates and the new Rect
    return newHex;                                                      // Return our newly created Hexagon
}

Hex *setUpHexArray(int maxSize){                                        // Setup an array to store our Hex data structures
    Hex *newHexArray = malloc(maxSize*sizeof(Hex));                     // Allocate space, maxSize times the size of a Hex structure                                 
    if (!newHexArray){ return NULL;}                                    // If allocation fails, then return NULL
    
    Vector3D newHexPos = {0,0,0};
    Vector2D newHexTilemapPos = {0,0};

    return newHexArray;
}

void drawHexArray(Hex hexArrayToDraw[]){

}

/* RECT Functions */
SDL_Rect setUpRect(int x, int y, int w, int h){
    SDL_Rect newRect = {x,y,w,h};
    return newRect;
}

/* Setup Functions */
void setupSDL(){
    window = SDL_CreateWindow("Tiles", WINDOW_POSX, WINDOWS_POSY, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    renderer  = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED );
    tileSet = IMG_LoadTexture(renderer, "Tile.png");
    
    tileRect = setUpRect(0,0,100,100);
    printf("SDL setup\n");
}

/* Evaluation Functions */
void evaluateEvent(SDL_Event event){
    switch (event.type){
        case SDL_QUIT:
            running = SDL_FALSE;
            printf("Exiting Window\n");
            break;
    }
}

void pollSDL(){
    SDL_Event event;
    while (SDL_PollEvent(&event)){
        evaluateEvent(event);
    }
}

/* Main Loop*/
void mainLoop(){
    while(running == SDL_TRUE){
        pollSDL();
        SDL_RenderCopy(renderer, tileSet, NULL, &tileRect);
        SDL_RenderPresent(renderer);
    }
}

/* Cleanup Functions */
void cleanupSDL(){
    SDL_DestroyTexture(tileSet);
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    printf("SDL closed\n");
}

/* Entry Point */
int main(int argc, char *argv[]) {
    setupSDL();
    mainLoop();
    cleanupSDL();

    return 0;
}