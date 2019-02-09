//
//  Object.h
//  OOP_In_C
//
//  Created by SuXinDe on 2019/2/9.
//  Copyright © 2019 su xinde. All rights reserved.
//

#ifndef Object_h
#define Object_h

#include "Type.h"

typedef struct _ObjectClass ObjectClass;
typedef struct _Object Object;

struct _ObjectClass {
    TypeInstance type_class;
    
    /* virtual methods */
    Object *(*ref)(Object *self);
    void (*unref)(Object *self);
    char *(*to_string)(Object *self);
};

struct _Object {
    const struct _ObjectClass *klass;
    uint64_t refcount;
};

#define TYPE_OBJECT (object_get_type())

void *object_new (Type type, ...);

Object *object_ref (Object *self);

void object_unref (Object *self);

void object_clear_ref (Object **selfptr);

char *object_to_string (Object *self);

static inline size_t object_sizeof (void *self) {
    return (self != NULL && (*(TypeInstance **)self) != NULL) ? (*(TypeInstance **)self)->instance_size : 0;
}

/* finally, declare the type */
DECLARE_TYPE (Object, object);

#endif /* Object_h */
