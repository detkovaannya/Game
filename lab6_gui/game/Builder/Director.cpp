#include "Director.h"

void Director::CreateField(Builder& bildr, Field &f) {
    bildr.Build_Floor(f);
    bildr.Build_Exit_Entire(f);
    bildr.Build_Block_Cells(f);
}