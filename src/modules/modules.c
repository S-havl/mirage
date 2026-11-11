#include <modules/modules.h>

#include <stddef.h>
#include <string.h>

extern void test_module_hello(void);

static module_descriptor_t registered_modules[] = {
    {.module_name = "recon/test/test", .module_function = test_module_hello}};

#define TOTAL_MODULES (sizeof(registered_modules) / sizeof(registered_modules[0]))

module_descriptor_t* search_for_module(const char* module_name)
{
    for (size_t i = 0; i < TOTAL_MODULES; i++) {
        if (strcmp(registered_modules[i].module_name, module_name) == 0) {
            return &registered_modules[i];
        }
    }

    return NULL;
}
