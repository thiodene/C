# Decode JSON


#include "JSON.h"
#include "iostream"

int main() {

    char *json_string = "[[{\"x\":36},{\"y\":0},{\"value\":0.47873455286026}], \
        [{\"x\":68},{\"y\":0},{\"value\":0.00944233685731888}], \
        [{\"x\":35},{\"y\":0},{\"value\":0.00944233685731888}], \
        [{\"x\":206},{\"y\":0},{\"value\":0.00944233685731888}]]";

    JSONValue *data = JSON::Parse(json_string);

    for( size_t i=0; i<data->CountChildren(); ++i ) {
        JSONValue *row = data->Child(i); 
        std::cout << "x = " << row->Child(0)->Child(L"x")->AsNumber() << std::endl;
        std::cout << "y = " << row->Child(1)->Child(L"y")->AsNumber() << std::endl;
        std::cout << "value = " << row->Child(2)->Child(L"value")->AsNumber() << std::endl;
        std::cout << std::endl;
    }

    return 0;
}
