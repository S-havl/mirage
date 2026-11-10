#pragma once

#define LOADED_MODULES 0

typedef struct module_descriptor {
    char module_name[64];
    void (*module_function)(void);
} module_descriptor_t;

module_descriptor_t* search_for_module(const char* module_name);
