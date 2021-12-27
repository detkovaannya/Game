#include "basefield_builder.h"

void BaseFieldBuilder::Build_Floor(Field& f) {
    auto it = new IteratorOfField(f);
    for (it->First(); !it->IsDone(); (*it)++) {
        if (!it->IsBoard())
            (**it)->SetState(EMP);
    }
    delete it;
}
void BaseFieldBuilder::Build_Block_Cells(Field &f) {
    std::random_device random_device;
    std::mt19937 generator(random_device());

    auto it = new IteratorOfField(f);
    for(it->First(); !it->IsDone(); (*it)++){
        if(it->IsEven()){
            std::uniform_int_distribution<> distribution(0, 2);
            int rand = distribution(generator);
            if(rand == 1)
                (**it)->SetState(IMP);
        }
    }
    delete it;
}
void BaseFieldBuilder::Build_Exit_Entire(Field &f) {
    std::random_device random_device;
    std::mt19937 generator(random_device());

    std::uniform_int_distribution<> distribution(1, f.get_height() - 2);
    int rand_st = distribution(generator);
    int rand_fn = distribution(generator);

    auto it = new IteratorOfField(f);
    for(it->First(); !it->IsDone(); (*it)++){
        if(it->IsAbleSt()){
            if(rand_st == 0)
                (**it)->SetState(START);
            rand_st --;
        } else if(it->IsAbleFn()){
            if(rand_fn == 0)
                (**it)->SetState(FIN);
            rand_fn --;
        }
    }
    delete it;
}