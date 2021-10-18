#include "cell.h"
#include "states_of_cell.h"

Cell::Cell(char data): content(data){
    if (content == ' ')
        state = empty;
    else if (content == '#')
        state = impassable;
    else if (content == '1' || content == '2' || content =='3')
        state = monster;
    else if (content == '*')
        state = player;
    else if (content == '>')
        state = start;
    else if (content == '<')
        state = finish;
    else if (content == '&')
        state = key;
    else if (content == '+' || content == '@' || content == '/')
        state =  object;
    else if (content == '\n')
        state = unique;
}
char Cell::get_content(){
    return content;
}
void Cell::change_content(char c){
    content = c;
    if (content == ' ')
        state = empty;
    else if (content == '#')
        state = impassable;
    else if (content == '1' || content == '2' || content =='3')
        state = monster;
    else if (content == '*')
        state = player;
    else if (content == '>')
        state = start;
    else if (content == '<')
        state = finish;
    else if (content == '&')
        state = key;
    else if (content == '+' || content == '@' || content == '/')
        state =  object;
    else if (content == '\n')
        state = unique;
}

bool Cell::IsEmpty() {
    return (state == empty);
}
