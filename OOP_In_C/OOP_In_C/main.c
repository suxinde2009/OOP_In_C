//
//  main.c
//  OOP_In_C
//
//  Created by su xinde on 15/5/5.
//  Copyright (c) 2015年 su xinde. All rights reserved.
//

#include "Object.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, const char * argv[]) {
    
    Object *o1 = object_new(TYPE_OBJECT, NULL);
    TypeInstance *otype = global_types_get_instance(TYPE_OBJECT);
    
    char *to_str = object_to_string (o1);
    printf("o1.to_string() = %s\n", to_str);
    printf("o1.refcount = %llu\n", o1->refcount);
    printf("o1.sizeof() = %zu\n", object_sizeof (o1));
    printf("o1 is type %s\n", otype->name);
    free(to_str);
    
    assert (sizeof(*o1) == object_sizeof(o1));
    
    object_clear_ref (&o1);
    assert (o1 == NULL);
    

    return 0;
}
