

#include <glib-object.h>

/*
Note each name you expect to be in the gir must start with the namespace prefix.
For GIMP app, the prefix is 'Gimp'
Here, the prefix is TestCallback.
However, the types such as TestCallbackCallback can use upper case,
but the functions must use a lower case prefix???
*/


/*
GI annotated types for callbacks
A callback is a function pointer that is passed around, a closure.
*/

/**
 * TestCallbackCallback:
 * @array_length:                           the length of the array
 * @drawables: (array length=array_length): the input array
 *
 * The callback is called back from the guest when the host calls callCallback()
 **/
typedef void (* TestCallbackCallback) (gint   array_length,
                                       gint **drawables
                                       );

/*
Functions to register (store as state in the library) a callback.
*/

/*
Register as a single-shot callback, only callback once.
*/
void testcallback_registerCallback  ( TestCallbackCallback aCallback);



/*
Call the callback previously stored.
*/
void testcallback_callCallback ( void );
