#include "basefield_builder.h"

void BaseFieldBuilder::Build_Base_Field(Field& field){
    auto it = new IteratorOfField(&field);
    for(it->First(); !it->IsDone(); it->Next()){
        if (!it->Is_Board())
            it->Current()->change_content(' ');
    }
    delete it;

    std::random_device random_device;
    std::mt19937 generator(random_device());

    std::uniform_int_distribution<> distribution(1, field.get_height() - 2);
    int rand_st = distribution(generator);
    int rand_fn = distribution(generator);

    it = new IteratorOfField(&field);
    for(it->First(); !it->IsDone(); it->Next()){
        if(it->Is_St()){
            if(rand_st == 0)
                it->Current()->change_content('>');
            rand_st --;
        } else if(it->Is_Fn()){
            if(rand_fn == 0)
                it->Current()->change_content('<');
            rand_fn --;
        }
    }
    delete it;

    it = new IteratorOfField(&field);
    for(it->First(); !it->IsDone(); it->Next()){
        if(it->Is_Even()){
            std::uniform_int_distribution<> distribution2(0, 2);
            int rand = distribution2(generator);
            if(rand == 1)
                it->Current()->change_content('#');
        }
    }
    delete it;
}
