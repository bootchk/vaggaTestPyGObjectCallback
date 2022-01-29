
/*
A library called from Python, and calling back to Python
*/

// Include Glib before the header for this file
#include <glib-object.h>

#include "testCallbackGList.h"




/*
Storage for  callbacks.
Library is not shareable since has static variables?
*/
static TestCallbackCallbackGList           theCallback = 0;



// * @aCallback:  (scope forever):       the callback, to be called later, many times

/**
 * testcallback_registerCallbackWGList:
 * @aCallback:  (scope async):       the callback, to be called later, once
 *
 * Registers a callback which the library will call when Python calls callCallback()
 **/
void
testcallback_registerCallbackWGList ( TestCallbackCallbackGList aCallback )
{
  g_printerr("Registering callback.\n");
  theCallback = aCallback;
}



/*
Functions called from Python to ask the library to callback into Python.
*/

/**
 * testcallback_callCallbackWGList:
 *
 * From the guest language (C) call the Python callback previously registered
 **/
void
testcallback_callCallbackWGList( )
{
  if (!theCallback)
    g_printerr("No callback registered.\n");
  else {
    g_printerr("Invoking callback.\n");

    // Create dummy values
    GList* aGList = NULL;
    aGList = g_list_append(aGList, "foo");
    aGList = g_list_append(aGList, "bar");

    // invoke the callback with dummy values
    theCallback(aGList);
  }
}
