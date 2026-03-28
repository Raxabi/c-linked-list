#include <stdio.h>

#include "includes/linked_list.h"
#include "includes/node.h"


// type definition only for testing purposes
// do not apply in other files of the project
typedef struct LinkedList list;

static void newline() {
    puts("");
}

int main() {
    newline();

    union numeric val;
    val.i32 = 50;

    list* ll = linked_list_new(val);

    val.i32 = 60;
    ll_set_first(ll, val);

    val.i32 = 253;
    ll_set_last(ll, val);

    val.u32 = 100;
    ll_set_first(ll, val);

    ll_print(ll);
    ll_drop_last(ll);

    newline();

    ll_print(ll);
    ll_drop(ll);

    return 0;
}