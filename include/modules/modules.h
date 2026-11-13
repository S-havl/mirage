#pragma once

#include <stddef.h>

typedef struct module_descriptor {
    char module_name[64];
    void (*module_function)(void);
} module_descriptor_t;

size_t               get_total_loaded_modules(void);
module_descriptor_t* search_for_module(const char* module_name);
