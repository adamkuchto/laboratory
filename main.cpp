#include "oblicz.hpp"
#include "menu.hpp"
#include "file.hpp"
#include "mongoose.h"
#include <pthread.h>

using namespace std;

static void fn(struct mg_connection *c, int ev, void *ev_data, void *fn_data)
{
    if (ev == MG_EV_HTTP_MSG)
    {
        struct mg_http_message *hm = (struct mg_http_message *)ev_data;
        if (mg_http_match_uri(hm, "/api/hello"))
        { // On /api/hello requests,
            mg_http_reply(c, 200, "", "{%m:%d}\n",
                          mg_print_esc, 0, "status", 1); // Send dynamic JSON response
        }
        else
        {                                                       // For all other URIs,
            struct mg_http_serve_opts opts = {.root_dir = "."}; // Serve files
            mg_http_serve_dir(c, hm, &opts);                    // From root_dir
        }
    }
}

void *server(void* args)
{
    struct mg_mgr mgr;
    mg_mgr_init(&mgr);                                     // Init manager
    // mg_http_listen(&mgr, "http://0.0.0.0:8000", fn, &mgr); // Setup listener
    mg_http_listen(&mgr, "http://127.0.0.1:8080", fn, &mgr); // Setup listener
    for (;;)
        mg_mgr_poll(&mgr, 1000);
}

void* mainProgram(void* args)
{
    short returnMenu = 0;
    short *ptrShort = &returnMenu;
    float r = 0;
    float *ptrFloat = &r;
    menu(ptrShort);

    if (returnMenu == MENU_SIZE)
    {
        exit(0);
    }
    else if (returnMenu == 4)
    {
        File read;
        read.readFromFile(PATH);
    }
    else if (returnMenu == 5)
    {
        File clear;
        clear.clearFile(PATH);
    }
    else
    {
        getValue(ptrFloat);
        Oblicz test1(r);
        if (returnMenu == 1)
            test1.pole();
        else if (returnMenu == 2)
            test1.obwod();
        else if (returnMenu == 3)
        {
            test1.pole();
            test1.obwod();
        }
        else
            cout << "Nieoczekiwany błąd! " << endl;
    }
    ptrShort = nullptr;
    ptrFloat = nullptr;
}

void threads()
{
    pthread_t mainThread;
    pthread_create(&mainThread, NULL, &server, NULL);
    pthread_create(&mainThread, NULL, &mainProgram, NULL);
    pthread_join(mainThread, NULL);
}

int main()
{
    while (1)
        threads();
    return 0;
}