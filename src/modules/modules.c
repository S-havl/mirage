#include <modules/modules.h>

#include <stddef.h>
#include <string.h>

extern void arp_mitm(void);

static module_descriptor_t registered_modules[] = {
    {.module_name = "net/spoof/arp_mitm", .module_function = arp_mitm}};

size_t get_total_loaded_modules(void)
{
    return sizeof(registered_modules) / sizeof(registered_modules[0]);
}

module_descriptor_t* search_for_module(const char* module_name)
{
    for (size_t i = 0; i < get_total_loaded_modules(); i++) {
        if (strcmp(registered_modules[i].module_name, module_name) == 0) {
            return &registered_modules[i];
        }
    }

    return NULL;
}
