#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <cstdio>
#include <vector>

//Este struct lo podemos modificar para que almacene la información deseada y luego mostrarla con showInfo
struct Cell {
    int value;
    ALLEGRO_COLOR color;
};

//Según yo esto debería permitir enseñar la info de la matriz, pero puede ser que no
std::vector<std::vector<Cell>> matrix;

//Necesario para Allegro
bool initializeAllegro();
void drawMatrix(ALLEGRO_DISPLAY* display);
void showInfo(ALLEGRO_DISPLAY* display, ALLEGRO_FONT* font, int x, int y);

int SPACE_SIZE = 20; // Tamaño de cada espacio de la matriz
int matrixXSize = 80; // Tamaño inicial de la matriz en X
int matrixYSize = 4; // Tamaño inicial de la matriz en Y

bool mismoColor(ALLEGRO_COLOR color1, ALLEGRO_COLOR color2);

int main() {
    if (!initializeAllegro()) {
        return -1;
    }

    // Inicializamos la matriz valores de 69 y color blanco por defecto
    matrix.resize(matrixXSize, std::vector<Cell>(matrixYSize, { 69, al_map_rgba(0, 0, 0, 0) }));

    if (matrixXSize + matrixYSize >= 222) { // Este condicional maneja cuestiones del tamaño (Puede necesitar mejoras)
        SPACE_SIZE = 3; // Reducir el tamaño del espacio si la suma de las dimensiones es grande
    }
    else if (matrixXSize + matrixYSize >= 127 || matrixYSize - matrixXSize >= 60) {
        SPACE_SIZE = 5; // Tamaño mediano del espacio si la suma está en el rango medio
    }
    else if (matrixXSize + matrixYSize <= 62) {
        SPACE_SIZE = 30; // Aumentar el tamaño del espacio si la suma de las dimensiones es muy pequeña
    }
    else {
        SPACE_SIZE = 15; // Valor predeterminado si no se cumplen las condiciones anteriores
    }


    int windowWidth = matrixXSize * SPACE_SIZE;  // Tamaño predeterminado de la ventana
    int windowHeight = matrixYSize * SPACE_SIZE + 10;  // Añadimos 10 para el texto de abajo

    // Verificación para ajustar el tamaño de la ventana si los números son menores a 10 (Para centrarlas)
    if (matrixXSize < 10 || matrixYSize < 10) {
        windowWidth = std::max(matrixXSize * SPACE_SIZE, 600);  // Tamaño mínimo de la ventana en X
        windowHeight = std::max(matrixYSize * SPACE_SIZE + 10, 400);  // Tamaño mínimo de la ventana en Y
    }

    // Crear la ventana con los tamaños designados
    ALLEGRO_DISPLAY* display = al_create_display(windowWidth, windowHeight);
    if (!display) {
        fprintf(stderr, "Failed to create display.\n");
        return -1;
    }

    al_clear_to_color(al_map_rgb(0, 0, 139)); // Fondo azul oscuro
    drawMatrix(display);
    al_flip_display();

    ALLEGRO_FONT* font = al_create_builtin_font();
    if (!font) {
        fprintf(stderr, "Failed to create font.\n");
        al_destroy_display(display);
        return -1;
    }

    al_clear_to_color(al_map_rgb(67, 93, 115));
    drawMatrix(display);
    al_flip_display();

    ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue(); //Todos estos procedimientos son de allegro
    if (!event_queue) {
        fprintf(stderr, "Failed to create event queue.\n");
        al_destroy_font(font);
        al_destroy_display(display);
        return -1;
    }

    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_mouse_event_source());

    // El bucle principal de eventos para manejar el mouse
    bool shouldExit = false;
    while (!shouldExit) {
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            shouldExit = true;
        }
        else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
            int displayWidth = al_get_display_width(display);
            int displayHeight = al_get_display_height(display);

            // Calcular el inicio en X e Y para centrar la matriz
            int startX = (displayWidth - matrixXSize * SPACE_SIZE) / 2;
            int startY = (displayHeight - matrixYSize * SPACE_SIZE) / 2;

            // Calcula las coordenadas de la matriz basadas en la posición del mouse
            int x = (ev.mouse.x - startX) / SPACE_SIZE;
            int y = (ev.mouse.y - startY) / SPACE_SIZE;

            if (x >= 0 && x < matrixXSize && y >= 0 && y < matrixYSize) {
                // Cambia el color dependiendo del color actual
                if (mismoColor(matrix[x][y].color, al_map_rgb(255, 0, 0))) {
                    matrix[x][y].color = al_map_rgb(255, 255, 255); // Vuelve a blanco
                }
                else {
                    matrix[x][y].color = al_map_rgb(255, 0, 0); // Cambia a rojo
                }
                drawMatrix(display);
                al_flip_display();
            }
        }
        else if (ev.type == ALLEGRO_EVENT_MOUSE_AXES) {
            int displayWidth = al_get_display_width(display);
            int displayHeight = al_get_display_height(display);
            int startX = (displayWidth - matrixXSize * SPACE_SIZE) / 2;
            int startY = (displayHeight - matrixYSize * SPACE_SIZE) / 2;
            int x = (ev.mouse.x - startX) / SPACE_SIZE;
            int y = (ev.mouse.y - startY) / SPACE_SIZE;
            showInfo(display, font, x, y);
        }
    }

    //Necesario por allegro creo xd
    al_destroy_font(font);
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);

    return 0;
}

bool initializeAllegro() {
    if (!al_init()) {
        fprintf(stderr, "Failed to initialize Allegro.\n");
        return false;
    }

    if (!al_init_primitives_addon()) {
        fprintf(stderr, "Failed to initialize Allegro primitives addon.\n");
        return false;
    }

    if (!al_init_font_addon()) {
        fprintf(stderr, "Failed to initialize Allegro font addon.\n");
        return false;
    }

    if (!al_init_ttf_addon()) {
        fprintf(stderr, "Failed to initialize Allegro TTF addon.\n");
        return false;
    }

    if (!al_install_mouse()) {
        fprintf(stderr, "Failed to initialize the mouse.\n");
        return false;
    }

    if (matrixYSize >= 186) {
        fprintf(stderr, "El garage es demasiado grande.\n");
        return false;
    }

    return true;
}

void drawMatrix(ALLEGRO_DISPLAY* display) {
    int displayWidth = al_get_display_width(display);
    int displayHeight = al_get_display_height(display);
    int startX = (displayWidth - matrixXSize * SPACE_SIZE) / 2;
    int startY = (displayHeight - matrixYSize * SPACE_SIZE) / 2;

    for (int i = 0; i < matrixXSize; ++i) {
        for (int j = 0; j < matrixYSize; ++j) {
            al_draw_filled_rectangle(startX + i * SPACE_SIZE, startY + j * SPACE_SIZE, startX + (i + 1) * SPACE_SIZE, startY + (j + 1) * SPACE_SIZE, matrix[i][j].color);
            al_draw_rectangle(startX + i * SPACE_SIZE, startY + j * SPACE_SIZE, startX + (i + 1) * SPACE_SIZE, startY + (j + 1) * SPACE_SIZE, al_map_rgb(0, 0, 0), 1);
        }
    }
}

//Este código de fijo lo vamos a tener que cambiar para que refleje la info de las matrices
void showInfo(ALLEGRO_DISPLAY* display, ALLEGRO_FONT* font, int x, int y) {
    if (x >= 0 && x < matrixXSize && y >= 0 && y < matrixYSize) {
        al_draw_filled_rectangle(0, al_get_display_height(display) - al_get_font_line_height(font), al_get_display_width(display), al_get_display_height(display), al_map_rgba(255, 255, 255, 200));
        al_draw_textf(font, al_map_rgb(0, 0, 0), 10, al_get_display_height(display) - al_get_font_line_height(font), 0, "Mouse sobre espacio (%d, %d) - Valor: %d", x, y, matrix[x][y].value);
        al_flip_display();
    }
}

bool mismoColor(ALLEGRO_COLOR color1, ALLEGRO_COLOR color2) {
    return (color1.r == color2.r && color1.g == color2.g && color1.b == color2.b);
}

//Aviso que el tema de matrices en allegro es medio janky y con matrices muy grandes empieza a mostrar errores