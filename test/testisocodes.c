#include <assert.h>

#include "config.h"
#include "isocodes.h"

int main(int argc, char* argv[])
{
    FcitxIsoCodes* isocodes = FcitxXkbReadIsoCodes(ISOCODES_ISO639_XML, ISOCODES_ISO3166_XML);
    
    FcitxIsoCodes639Entry* entry = FcitxIsoCodesGetEntry(isocodes, "eng");
    assert(strcmp(entry->iso_639_2B_code, "eng") == 0);
    assert(strcmp(entry->iso_639_2T_code, "eng") == 0);
    assert(strcmp(entry->iso_639_1_code, "en") == 0);
    assert(strcmp(entry->name, "English") == 0);
    
    FcitxIsoCodesFree(isocodes);
    
    return 0;
}