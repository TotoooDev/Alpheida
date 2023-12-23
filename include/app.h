#ifndef APPLICATION_H
#define APPLICATION_H

typedef struct App App;

App* app_new(const char* name);
void app_delete(App* app);

void app_run(App* app);

#endif

