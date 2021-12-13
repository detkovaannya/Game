#include "Director.h"

void Director::CreateField(Builder& bldr, Field &f) {
    bldr.Build_Floor(f);
    bldr.Build_Exit_Entire(f);
    bldr.Build_Block_Cells(f);
}