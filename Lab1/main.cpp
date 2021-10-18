#include "field.h"
#include "basefield_builder.h"

int main() {
    Field f;
    BaseFieldBuilder b;
    b.Build_Base_Field(f);
    f.print_field();
    return 0;
}
